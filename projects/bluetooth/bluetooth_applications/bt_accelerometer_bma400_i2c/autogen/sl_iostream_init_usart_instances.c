#if defined(SL_COMPONENT_CATALOG_PRESENT)
#include "sl_component_catalog.h"
#endif
#if defined(SL_CATALOG_POWER_MANAGER_PRESENT)
#include "sl_power_manager.h"
#endif
#include "em_device.h"
#include "sl_iostream.h"
#include "sl_iostream_uart.h"
#include "sl_iostream_usart.h"

#include "sl_cos.h"


// Include instance config 
 #include "sl_iostream_usart_vcom_config.h"

// MACROs for generating name and IRQ handler function  
#define SL_IOSTREAM_USART_CONCAT_PASTER(first, second, third)        first ##  second ## third
 



#define SL_IOSTREAM_USART_TX_IRQ_NUMBER(periph_nbr)     SL_IOSTREAM_USART_CONCAT_PASTER(USART, periph_nbr, _TX_IRQn)        
#define SL_IOSTREAM_USART_RX_IRQ_NUMBER(periph_nbr)     SL_IOSTREAM_USART_CONCAT_PASTER(USART, periph_nbr, _RX_IRQn)        
#define SL_IOSTREAM_USART_TX_IRQ_HANDLER(periph_nbr)    SL_IOSTREAM_USART_CONCAT_PASTER(USART, periph_nbr, _TX_IRQHandler)  
#define SL_IOSTREAM_USART_RX_IRQ_HANDLER(periph_nbr)    SL_IOSTREAM_USART_CONCAT_PASTER(USART, periph_nbr, _RX_IRQHandler)  

#define SL_IOSTREAM_USART_RX_DMA_SIGNAL(periph_nbr)     SL_IOSTREAM_USART_CONCAT_PASTER(dmadrvPeripheralSignal_USART, periph_nbr, _RXDATAV)  
#define SL_IOSTREAM_USART_TX_DMA_SIGNAL(periph_nbr)     SL_IOSTREAM_USART_CONCAT_PASTER(dmadrvPeripheralSignal_USART, periph_nbr, _TXBL)  

#define SL_IOSTREAM_USART_CLOCK_REF(periph_nbr)         SL_IOSTREAM_USART_CONCAT_PASTER(cmuClock_, USART, periph_nbr)       
// EM Events
#if defined(SL_CATALOG_POWER_MANAGER_PRESENT) 
#if defined(_SILICON_LABS_32B_SERIES_2)
#define SLEEP_EM_EVENT_MASK      ( SL_POWER_MANAGER_EVENT_TRANSITION_ENTERING_EM2  \
                                  | SL_POWER_MANAGER_EVENT_TRANSITION_LEAVING_EM2  \
                                  | SL_POWER_MANAGER_EVENT_TRANSITION_ENTERING_EM0 \
                                  | SL_POWER_MANAGER_EVENT_TRANSITION_LEAVING_EM0)
#else 
#define SLEEP_EM_EVENT_MASK      (SL_POWER_MANAGER_EVENT_TRANSITION_ENTERING_EM0   \
                                  | SL_POWER_MANAGER_EVENT_TRANSITION_LEAVING_EM0)
#endif // _SILICON_LABS_32B_SERIES_2
static void events_handler(sl_power_manager_em_t from,
                           sl_power_manager_em_t to);
static sl_power_manager_em_transition_event_info_t events_info =
{
  .event_mask = SLEEP_EM_EVENT_MASK,
  .on_event = events_handler,
};
static sl_power_manager_em_transition_event_handle_t events_handle;
#endif // SL_CATALOG_POWER_MANAGER_PRESENT


sl_status_t sl_iostream_usart_init_vcom(void);


// Instance(s) handle and context variable 

static sl_iostream_uart_t sl_iostream_vcom;
sl_iostream_t *sl_iostream_vcom_handle = &sl_iostream_vcom.stream;
sl_iostream_uart_t *sl_iostream_uart_vcom_handle = &sl_iostream_vcom;
static sl_iostream_usart_context_t  context_vcom;
static uint8_t  rx_buffer_vcom[SL_IOSTREAM_USART_VCOM_RX_BUFFER_SIZE];
static sli_iostream_uart_periph_t uart_periph_vcom = {
  .rx_irq_number = SL_IOSTREAM_USART_RX_IRQ_NUMBER(SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO),
#if defined(SL_CATALOG_POWER_MANAGER_PRESENT)
  .tx_irq_number = SL_IOSTREAM_USART_TX_IRQ_NUMBER(SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO),
#endif
};
sl_iostream_instance_info_t sl_iostream_instance_vcom_info = {
  .handle = &sl_iostream_vcom.stream,
  .name = "vcom",
  .type = SL_IOSTREAM_TYPE_UART,
  .periph_id = SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO,
  .init = sl_iostream_usart_init_vcom,
};



sl_status_t sl_iostream_usart_init_vcom(void)
{
  sl_status_t status;
  USART_InitAsync_TypeDef init_vcom = USART_INITASYNC_DEFAULT;
  init_vcom.baudrate = SL_IOSTREAM_USART_VCOM_BAUDRATE;
  init_vcom.parity = SL_IOSTREAM_USART_VCOM_PARITY;
  init_vcom.stopbits = SL_IOSTREAM_USART_VCOM_STOP_BITS;
#if (_SILICON_LABS_32B_SERIES > 0)
  init_vcom.hwFlowControl = SL_IOSTREAM_USART_VCOM_FLOW_CONTROL_TYPE != uartFlowControlSoftware ? SL_IOSTREAM_USART_VCOM_FLOW_CONTROL_TYPE : usartHwFlowControlNone;
#endif
  sl_iostream_usart_config_t config_vcom = { 
    .usart = SL_IOSTREAM_USART_VCOM_PERIPHERAL,
    .clock = SL_IOSTREAM_USART_CLOCK_REF(SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO),
    .tx_port = SL_IOSTREAM_USART_VCOM_TX_PORT,
    .tx_pin = SL_IOSTREAM_USART_VCOM_TX_PIN,
    .rx_port = SL_IOSTREAM_USART_VCOM_RX_PORT,
    .rx_pin = SL_IOSTREAM_USART_VCOM_RX_PIN,
#if (_SILICON_LABS_32B_SERIES > 0)
#if defined(SL_IOSTREAM_USART_VCOM_CTS_PORT)
    .cts_port = SL_IOSTREAM_USART_VCOM_CTS_PORT,
    .cts_pin = SL_IOSTREAM_USART_VCOM_CTS_PIN,
#endif
#if defined(SL_IOSTREAM_USART_VCOM_RTS_PORT)
    .rts_port = SL_IOSTREAM_USART_VCOM_RTS_PORT,
    .rts_pin = SL_IOSTREAM_USART_VCOM_RTS_PIN,
#endif
#endif
#if defined(GPIO_USART_ROUTEEN_TXPEN)
    .usart_index = SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO,
#elif defined(USART_ROUTEPEN_RXPEN)
    .usart_tx_location = SL_IOSTREAM_USART_VCOM_TX_LOC,
    .usart_rx_location = SL_IOSTREAM_USART_VCOM_RX_LOC,
#if defined(SL_IOSTREAM_USART_VCOM_CTS_PORT)
    .usart_cts_location = SL_IOSTREAM_USART_VCOM_CTS_LOC,
#endif
#if defined(SL_IOSTREAM_USART_VCOM_RTS_PORT)
    .usart_rts_location = SL_IOSTREAM_USART_VCOM_RTS_LOC,
#endif
#else
    .usart_location = SL_IOSTREAM_USART_VCOM_ROUTE_LOC,
#endif
  };

  sl_iostream_dma_config_t rx_dma_config_vcom = {.src = (uint8_t *)&SL_IOSTREAM_USART_VCOM_PERIPHERAL->RXDATA,
                                                        .xfer_cfg = IOSTREAM_LDMA_TFER_CFG_PERIPH(SL_IOSTREAM_USART_RX_DMA_SIGNAL(SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO))};

  sl_iostream_dma_config_t tx_dma_config_vcom = {.dst = (uint8_t *)&SL_IOSTREAM_USART_VCOM_PERIPHERAL->TXDATA,
                                                        .xfer_cfg = IOSTREAM_LDMA_TFER_CFG_PERIPH(SL_IOSTREAM_USART_TX_DMA_SIGNAL(SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO))};

  sl_iostream_uart_config_t uart_config_vcom = {
    .rx_dma_cfg = rx_dma_config_vcom,
    .tx_dma_cfg = tx_dma_config_vcom,
    .rx_buffer = rx_buffer_vcom,
    .rx_buffer_length = SL_IOSTREAM_USART_VCOM_RX_BUFFER_SIZE,
    .lf_to_crlf = SL_IOSTREAM_USART_VCOM_CONVERT_BY_DEFAULT_LF_TO_CRLF,
    .enable_high_frequency = true,
    .rx_when_sleeping = SL_IOSTREAM_USART_VCOM_RESTRICT_ENERGY_MODE_TO_ALLOW_RECEPTION,
    .uart_periph = &uart_periph_vcom
  };
  uart_config_vcom.sw_flow_control = SL_IOSTREAM_USART_VCOM_FLOW_CONTROL_TYPE == uartFlowControlSoftware;


#if defined(SL_IOSTREAM_USART_VCOM_ASYNC_TX)
  uart_config_vcom.async_tx_enabled = SL_IOSTREAM_USART_VCOM_ASYNC_TX;
#else
  uart_config_vcom.async_tx_enabled = false;
#endif

  // Instantiate usart instance 
  status = sl_iostream_usart_init(&sl_iostream_vcom,
                                  &uart_config_vcom,
                                  &init_vcom,
                                  &config_vcom,
                                  &context_vcom);
  EFM_ASSERT(status == SL_STATUS_OK);

  
  // Send VCOM config to WSTK
  uint8_t flow_control = COS_CONFIG_FLOWCONTROL_NONE;
  // Series 0 boards don't have HWFC.
  #if !defined(_SILICON_LABS_32B_SERIES_0)
  if (!uart_config_vcom.sw_flow_control) {
    switch (SL_IOSTREAM_USART_VCOM_FLOW_CONTROL_TYPE) 
    {
      case uartFlowControlNone:
        flow_control = COS_CONFIG_FLOWCONTROL_NONE;
        break;
      case usartHwFlowControlCts:
        flow_control = COS_CONFIG_FLOWCONTROL_CTS;
        break;
      case usartHwFlowControlRts:
        flow_control = COS_CONFIG_FLOWCONTROL_RTS;
        break;
      case usartHwFlowControlCtsAndRts:
        flow_control = COS_CONFIG_FLOWCONTROL_CTS_RTS;
        break;
      default:
        // Invalid flow control type  
        EFM_ASSERT(0);
        break;
    }
  }
  #endif // _SILICON_LABS_32B_SERIES_0
  sl_cos_config_vcom((uint32_t) SL_IOSTREAM_USART_VCOM_BAUDRATE, flow_control);
  

  return status;
}



void sl_iostream_usart_init_instances(void)
{
  sl_status_t status;
#if defined(SL_CATALOG_POWER_MANAGER_PRESENT)
  // Enable power manager notifications
  sl_power_manager_subscribe_em_transition_event(&events_handle, &events_info);
#endif

  // Instantiate usart instance(s) 
  
  status = sl_iostream_usart_init_vcom();
  EFM_ASSERT(status == SL_STATUS_OK);
  
}

 
// VCOM IRQ Handler
void SL_IOSTREAM_USART_TX_IRQ_HANDLER(SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO)(void)
{
  sl_iostream_usart_irq_handler(&sl_iostream_vcom);
}

void SL_IOSTREAM_USART_RX_IRQ_HANDLER(SL_IOSTREAM_USART_VCOM_PERIPHERAL_NO)(void)
{
  sl_iostream_usart_irq_handler(&sl_iostream_vcom);
}



#if defined(SL_CATALOG_POWER_MANAGER_PRESENT) 
#if !defined(SL_CATALOG_KERNEL_PRESENT)
 
sl_power_manager_on_isr_exit_t sl_iostream_usart_vcom_sleep_on_isr_exit(void)
{
  return sl_iostream_uart_sleep_on_isr_exit(&sl_iostream_vcom);
}

#endif // SL_CATALOG_KERNEL_PRESENT
static void events_handler(sl_power_manager_em_t from,
                           sl_power_manager_em_t to)
{
  (void) from;
  #if defined(_SILICON_LABS_32B_SERIES_2)
  uint32_t out;
  if (((from == SL_POWER_MANAGER_EM2) 
      || (from == SL_POWER_MANAGER_EM3)) 
      && ((to == SL_POWER_MANAGER_EM1) 
      || (to == SL_POWER_MANAGER_EM0))) {
      
	// Wake the USART Tx pin back up
	out = GPIO_PinOutGet(SL_IOSTREAM_USART_VCOM_TX_PORT, SL_IOSTREAM_USART_VCOM_TX_PIN);
	GPIO_PinModeSet(SL_IOSTREAM_USART_VCOM_TX_PORT, SL_IOSTREAM_USART_VCOM_TX_PIN, gpioModePushPull, out);
    
	} else if (((to == SL_POWER_MANAGER_EM2) 
			   || (to == SL_POWER_MANAGER_EM3)) 
			   && ((from == SL_POWER_MANAGER_EM1) 
			   || (from == SL_POWER_MANAGER_EM0))) {
	    
	  // Sleep the USART Tx pin on series 2 devices to save energy
      out = GPIO_PinOutGet(SL_IOSTREAM_USART_VCOM_TX_PORT, SL_IOSTREAM_USART_VCOM_TX_PIN);
      GPIO_PinModeSet(SL_IOSTREAM_USART_VCOM_TX_PORT, SL_IOSTREAM_USART_VCOM_TX_PIN, gpioModeDisabled, out);
    
  }
  #endif // _SILICON_LABS_32B_SERIES_2
  if (to == SL_POWER_MANAGER_EM0) {
     
    if (sl_iostream_uart_vcom_handle->stream.context != NULL) {
      sl_iostream_uart_wakeup(sl_iostream_uart_vcom_handle);
    }
    
  } else if (to < SL_POWER_MANAGER_EM2){
    // Only prepare for sleep to EM1 or less, since USART doesn't run in EM2
     
    if (sl_iostream_uart_vcom_handle->stream.context != NULL) {
      sl_iostream_uart_prepare_for_sleep(sl_iostream_uart_vcom_handle);
    }
    
  }
}
#endif // SL_CATALOG_POWER_MANAGER_PRESENT