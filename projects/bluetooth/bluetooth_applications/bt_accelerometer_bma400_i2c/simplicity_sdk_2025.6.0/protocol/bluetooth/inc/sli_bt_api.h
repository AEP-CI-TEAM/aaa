/***************************************************************************//**
 * @brief SL_BT_API library at application layer provided as source code
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

#ifndef SLI_BT_API_H
#define SLI_BT_API_H
#define VERSION no_link_tables

#include "sl_bt_api.h"
#include "sli_bt_api.h"
#include "sli_bgapi.h"

#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
// Silicon Labs internal functions for Bluetooth host stack initialization

// Forward declaration of the Bluetooth host stack configuration structure
struct sl_bt_configuration;

/**
 * @brief Register the Bluetooth host BGAPI device with specific configuration.
 *
 * This function is used internally by Bluetooth host stack initialization.
 * Do not call this function directly from the application.
 *
 * @param[in] config The Bluetooth host stack configuration to use
 * @param[in] device_info Information about the BGAPI device
 *
 * @return SL_STATUS_OK if successful. Error code otherwise.
 */
sl_status_t sli_bt_register_bgapi_device(const struct sl_bt_configuration *config,
                                         const sli_bgapi_device_info_t *device_info);

/**
 * @brief Initialize the Bluetooth host stack BGAPI device.
 *
 * This function is used internally by Bluetooth host stack initialization.
 * Do not call this function directly from the application.
 *
 * @return SL_STATUS_OK if successful. Error code otherwise.
 */
sl_status_t sli_bt_init_bgapi_device(void);

/**
 * @brief Start the Bluetooth host stack BGAPI device.
 *
 * This function is used internally by Bluetooth host stack initialization.
 * Do not call this function directly from the application.
 *
 * @return SL_STATUS_OK if successful. Error code otherwise.
 */
sl_status_t sli_bt_start_bgapi_device(void);

/**
 * @brief De-initialize the Bluetooth host stack BGAPI device.
 *
 * This function is used internally by Bluetooth host stack de-initialization.
 * Do not call this function directly from the application.
 *
 * @return SL_STATUS_OK if successful. Error code otherwise.
 */
void sli_bt_deinit_bgapi_device(void);

// -----------------------------------------------------------------------------
// Class and command IDs for Bluetooth host stack BGAPI

enum sli_bt_class_id
{
    sli_bt_dfu_class_id = 0x00,
    sli_bt_system_class_id = 0x01,
    sli_bt_resource_class_id = 0x5f,
    sli_bt_gap_class_id = 0x02,
    sli_bt_advertiser_class_id = 0x04,
    sli_bt_legacy_advertiser_class_id = 0x56,
    sli_bt_extended_advertiser_class_id = 0x57,
    sli_bt_periodic_advertiser_class_id = 0x58,
    sli_bt_scanner_class_id = 0x05,
    sli_bt_sync_class_id = 0x42,
    sli_bt_sync_scanner_class_id = 0x50,
    sli_bt_past_receiver_class_id = 0x51,
    sli_bt_advertiser_past_class_id = 0x52,
    sli_bt_sync_past_class_id = 0x5b,
    sli_bt_periodic_sync_class_id = 0x53,
    sli_bt_pawr_sync_class_id = 0x54,
    sli_bt_pawr_advertiser_class_id = 0x55,
    sli_bt_connection_class_id = 0x06,
    sli_bt_gatt_class_id = 0x09,
    sli_bt_gattdb_class_id = 0x46,
    sli_bt_gatt_server_class_id = 0x0a,
    sli_bt_nvm_class_id = 0x0d,
    sli_bt_test_class_id = 0x0e,
    sli_bt_sm_class_id = 0x0f,
    sli_bt_external_bondingdb_class_id = 0x5c,
    sli_bt_resolving_list_class_id = 0x5d,
    sli_bt_accept_list_class_id = 0x5e,
    sli_bt_coex_class_id = 0x20,
    sli_bt_cs_class_id = 0x59,
    sli_bt_cs_test_class_id = 0x5A,
    sli_bt_l2cap_class_id = 0x43,
    sli_bt_cte_transmitter_class_id = 0x44,
    sli_bt_cte_receiver_class_id = 0x45,
    sli_bt_connection_analyzer_class_id = 0x48,
    sli_bt_user_class_id = 0xff,
};

enum sli_bt_command_id
{
    sli_bt_dfu_flash_set_address_command_id = 0x01,
    sli_bt_dfu_flash_upload_command_id = 0x02,
    sli_bt_dfu_flash_upload_finish_command_id = 0x03,
    sli_bt_system_hello_command_id = 0x00,
    sli_bt_system_start_bluetooth_command_id = 0x1c,
    sli_bt_system_stop_bluetooth_command_id = 0x1d,
    sli_bt_system_forcefully_stop_bluetooth_command_id = 0x1e,
    sli_bt_system_get_version_command_id = 0x1b,
    sli_bt_system_reboot_command_id = 0x1f,
    sli_bt_system_halt_command_id = 0x0c,
    sli_bt_system_linklayer_configure_command_id = 0x0e,
    sli_bt_system_set_tx_power_command_id = 0x17,
    sli_bt_system_get_tx_power_setting_command_id = 0x18,
    sli_bt_system_set_identity_address_command_id = 0x13,
    sli_bt_system_get_identity_address_command_id = 0x15,
    sli_bt_system_get_random_data_command_id = 0x0b,
    sli_bt_system_data_buffer_write_command_id = 0x12,
    sli_bt_system_data_buffer_clear_command_id = 0x14,
    sli_bt_system_get_counters_command_id = 0x0f,
    sli_bt_system_set_lazy_soft_timer_command_id = 0x1a,
    sli_bt_system_reset_command_id = 0x01,
    sli_bt_resource_get_status_command_id = 0x00,
    sli_bt_resource_set_report_threshold_command_id = 0x01,
    sli_bt_resource_enable_connection_tx_report_command_id = 0x02,
    sli_bt_resource_get_connection_tx_status_command_id = 0x03,
    sli_bt_resource_disable_connection_tx_report_command_id = 0x04,
    sli_bt_gap_set_privacy_mode_command_id = 0x01,
    sli_bt_gap_set_data_channel_classification_command_id = 0x02,
    sli_bt_gap_set_identity_address_command_id = 0x04,
    sli_bt_gap_get_identity_address_command_id = 0x05,
    sli_bt_advertiser_create_set_command_id = 0x01,
    sli_bt_advertiser_configure_command_id = 0x12,
    sli_bt_advertiser_set_timing_command_id = 0x03,
    sli_bt_advertiser_set_channel_map_command_id = 0x04,
    sli_bt_advertiser_set_tx_power_command_id = 0x0b,
    sli_bt_advertiser_set_report_scan_request_command_id = 0x05,
    sli_bt_advertiser_set_random_address_command_id = 0x10,
    sli_bt_advertiser_clear_random_address_command_id = 0x11,
    sli_bt_advertiser_stop_command_id = 0x0a,
    sli_bt_advertiser_delete_set_command_id = 0x02,
    sli_bt_legacy_advertiser_set_data_command_id = 0x00,
    sli_bt_legacy_advertiser_generate_data_command_id = 0x01,
    sli_bt_legacy_advertiser_start_command_id = 0x02,
    sli_bt_legacy_advertiser_start_directed_command_id = 0x03,
    sli_bt_extended_advertiser_set_phy_command_id = 0x00,
    sli_bt_extended_advertiser_set_data_command_id = 0x01,
    sli_bt_extended_advertiser_set_long_data_command_id = 0x02,
    sli_bt_extended_advertiser_generate_data_command_id = 0x03,
    sli_bt_extended_advertiser_start_command_id = 0x04,
    sli_bt_extended_advertiser_start_directed_command_id = 0x05,
    sli_bt_periodic_advertiser_set_data_command_id = 0x00,
    sli_bt_periodic_advertiser_set_long_data_command_id = 0x01,
    sli_bt_periodic_advertiser_start_command_id = 0x02,
    sli_bt_periodic_advertiser_stop_command_id = 0x03,
    sli_bt_scanner_set_parameters_command_id = 0x06,
    sli_bt_scanner_set_parameters_and_filter_command_id = 0x07,
    sli_bt_scanner_start_command_id = 0x03,
    sli_bt_scanner_stop_command_id = 0x05,
    sli_bt_sync_set_reporting_mode_command_id = 0x03,
    sli_bt_sync_update_sync_parameters_command_id = 0x04,
    sli_bt_sync_close_command_id = 0x01,
    sli_bt_sync_scanner_set_sync_parameters_command_id = 0x00,
    sli_bt_sync_scanner_open_command_id = 0x01,
    sli_bt_past_receiver_set_default_sync_receive_parameters_command_id = 0x00,
    sli_bt_past_receiver_set_sync_receive_parameters_command_id = 0x01,
    sli_bt_past_receiver_set_default_sync_receive_over_sync_parameters_command_id = 0x02,
    sli_bt_past_receiver_set_sync_receive_over_sync_parameters_command_id = 0x03,
    sli_bt_advertiser_past_transfer_command_id = 0x00,
    sli_bt_advertiser_past_transfer_over_pawr_advertiser_command_id = 0x01,
    sli_bt_sync_past_transfer_command_id = 0x00,
    sli_bt_pawr_sync_set_sync_subevents_command_id = 0x02,
    sli_bt_pawr_sync_set_response_data_command_id = 0x03,
    sli_bt_pawr_advertiser_start_command_id = 0x00,
    sli_bt_pawr_advertiser_change_parameters_command_id = 0x04,
    sli_bt_pawr_advertiser_set_subevent_data_command_id = 0x01,
    sli_bt_pawr_advertiser_create_connection_command_id = 0x02,
    sli_bt_pawr_advertiser_stop_command_id = 0x03,
    sli_bt_connection_set_default_parameters_command_id = 0x00,
    sli_bt_connection_set_default_preferred_phy_command_id = 0x01,
    sli_bt_connection_set_default_data_length_command_id = 0x10,
    sli_bt_connection_set_default_acceptable_subrate_command_id = 0x19,
    sli_bt_connection_open_command_id = 0x04,
    sli_bt_connection_open_with_accept_list_command_id = 0x16,
    sli_bt_connection_set_parameters_command_id = 0x06,
    sli_bt_connection_set_preferred_phy_command_id = 0x08,
    sli_bt_connection_disable_slave_latency_command_id = 0x03,
    sli_bt_connection_get_median_rssi_command_id = 0x15,
    sli_bt_connection_read_channel_map_command_id = 0x07,
    sli_bt_connection_set_power_reporting_command_id = 0x09,
    sli_bt_connection_set_remote_power_reporting_command_id = 0x0a,
    sli_bt_connection_get_tx_power_command_id = 0x0b,
    sli_bt_connection_get_remote_tx_power_command_id = 0x0c,
    sli_bt_connection_set_tx_power_command_id = 0x12,
    sli_bt_connection_read_remote_used_features_command_id = 0x0d,
    sli_bt_connection_get_security_status_command_id = 0x0e,
    sli_bt_connection_set_data_length_command_id = 0x11,
    sli_bt_connection_read_statistics_command_id = 0x13,
    sli_bt_connection_get_scheduling_details_command_id = 0x14,
    sli_bt_connection_get_remote_address_command_id = 0x17,
    sli_bt_connection_request_subrate_command_id = 0x1A,
    sli_bt_connection_get_state_command_id = 0x18,
    sli_bt_connection_close_command_id = 0x05,
    sli_bt_connection_forcefully_close_command_id = 0x0f,
    sli_bt_gatt_set_max_mtu_command_id = 0x00,
    sli_bt_gatt_discover_primary_services_command_id = 0x01,
    sli_bt_gatt_discover_primary_services_by_uuid_command_id = 0x02,
    sli_bt_gatt_find_included_services_command_id = 0x10,
    sli_bt_gatt_discover_characteristics_command_id = 0x03,
    sli_bt_gatt_discover_characteristics_by_uuid_command_id = 0x04,
    sli_bt_gatt_discover_descriptors_command_id = 0x06,
    sli_bt_gatt_discover_characteristic_descriptors_command_id = 0x14,
    sli_bt_gatt_set_characteristic_notification_command_id = 0x05,
    sli_bt_gatt_send_characteristic_confirmation_command_id = 0x0d,
    sli_bt_gatt_read_characteristic_value_command_id = 0x07,
    sli_bt_gatt_read_characteristic_value_from_offset_command_id = 0x12,
    sli_bt_gatt_read_multiple_characteristic_values_command_id = 0x17,
    sli_bt_gatt_read_variable_length_characteristic_values_command_id = 0x18,
    sli_bt_gatt_read_characteristic_value_by_uuid_command_id = 0x08,
    sli_bt_gatt_write_characteristic_value_command_id = 0x19,
    sli_bt_gatt_write_characteristic_value_without_response_command_id = 0x1a,
    sli_bt_gatt_prepare_characteristic_value_write_command_id = 0x1b,
    sli_bt_gatt_prepare_characteristic_value_reliable_write_command_id = 0x1c,
    sli_bt_gatt_execute_characteristic_value_write_command_id = 0x0c,
    sli_bt_gatt_read_descriptor_value_command_id = 0x0e,
    sli_bt_gatt_write_descriptor_value_command_id = 0x1d,
    sli_bt_gatt_get_mtu_command_id = 0x15,
    sli_bt_gattdb_new_session_command_id = 0x00,
    sli_bt_gattdb_add_service_command_id = 0x01,
    sli_bt_gattdb_remove_service_command_id = 0x02,
    sli_bt_gattdb_add_included_service_command_id = 0x03,
    sli_bt_gattdb_remove_included_service_command_id = 0x04,
    sli_bt_gattdb_add_uuid16_characteristic_command_id = 0x05,
    sli_bt_gattdb_add_uuid128_characteristic_command_id = 0x06,
    sli_bt_gattdb_remove_characteristic_command_id = 0x07,
    sli_bt_gattdb_add_uuid16_descriptor_command_id = 0x08,
    sli_bt_gattdb_add_uuid128_descriptor_command_id = 0x09,
    sli_bt_gattdb_remove_descriptor_command_id = 0x0a,
    sli_bt_gattdb_start_service_command_id = 0x0b,
    sli_bt_gattdb_stop_service_command_id = 0x0c,
    sli_bt_gattdb_start_characteristic_command_id = 0x0d,
    sli_bt_gattdb_stop_characteristic_command_id = 0x0e,
    sli_bt_gattdb_commit_command_id = 0x0f,
    sli_bt_gattdb_abort_command_id = 0x10,
    sli_bt_gattdb_get_attribute_state_command_id = 0x11,
    sli_bt_gatt_server_set_max_mtu_command_id = 0x0a,
    sli_bt_gatt_server_get_mtu_command_id = 0x0b,
    sli_bt_gatt_server_find_attribute_command_id = 0x06,
    sli_bt_gatt_server_find_primary_service_command_id = 0x09,
    sli_bt_gatt_server_read_attribute_value_command_id = 0x16,
    sli_bt_gatt_server_read_attribute_type_command_id = 0x01,
    sli_bt_gatt_server_read_attribute_properties_command_id = 0x05,
    sli_bt_gatt_server_write_attribute_value_command_id = 0x17,
    sli_bt_gatt_server_send_user_read_response_command_id = 0x18,
    sli_bt_gatt_server_send_user_write_response_command_id = 0x04,
    sli_bt_gatt_server_send_notification_command_id = 0x19,
    sli_bt_gatt_server_send_notification_with_options_command_id = 0x1d,
    sli_bt_gatt_server_send_indication_command_id = 0x1a,
    sli_bt_gatt_server_send_indication_with_options_command_id = 0x1e,
    sli_bt_gatt_server_notify_all_command_id = 0x1b,
    sli_bt_gatt_server_read_client_configuration_command_id = 0x12,
    sli_bt_gatt_server_send_user_prepare_write_response_command_id = 0x1c,
    sli_bt_gatt_server_set_capabilities_command_id = 0x08,
    sli_bt_gatt_server_enable_capabilities_command_id = 0x0c,
    sli_bt_gatt_server_disable_capabilities_command_id = 0x0d,
    sli_bt_gatt_server_get_enabled_capabilities_command_id = 0x0e,
    sli_bt_gatt_server_read_client_supported_features_command_id = 0x15,
    sli_bt_nvm_save_command_id = 0x02,
    sli_bt_nvm_load_command_id = 0x03,
    sli_bt_nvm_erase_command_id = 0x04,
    sli_bt_nvm_erase_all_command_id = 0x01,
    sli_bt_test_dtm_tx_v4_command_id = 0x03,
    sli_bt_test_dtm_tx_cw_command_id = 0x04,
    sli_bt_test_dtm_rx_command_id = 0x01,
    sli_bt_test_dtm_end_command_id = 0x02,
    sli_bt_sm_configure_command_id = 0x01,
    sli_bt_sm_set_minimum_key_size_command_id = 0x14,
    sli_bt_sm_set_debug_mode_command_id = 0x0f,
    sli_bt_sm_store_bonding_configuration_command_id = 0x02,
    sli_bt_sm_set_bondable_mode_command_id = 0x00,
    sli_bt_sm_set_passkey_command_id = 0x10,
    sli_bt_sm_increase_security_command_id = 0x04,
    sli_bt_sm_enter_passkey_command_id = 0x08,
    sli_bt_sm_passkey_confirm_command_id = 0x09,
    sli_bt_sm_bonding_confirm_command_id = 0x0e,
    sli_bt_sm_delete_bonding_command_id = 0x06,
    sli_bt_sm_delete_bondings_command_id = 0x07,
    sli_bt_sm_get_bonding_handles_command_id = 0x15,
    sli_bt_sm_get_bonding_details_command_id = 0x16,
    sli_bt_sm_find_bonding_by_address_command_id = 0x17,
    sli_bt_sm_resolve_rpa_command_id = 0x1d,
    sli_bt_sm_set_bonding_key_command_id = 0x18,
    sli_bt_sm_set_legacy_oob_command_id = 0x19,
    sli_bt_sm_set_oob_command_id = 0x1a,
    sli_bt_sm_set_remote_oob_command_id = 0x1b,
    sli_bt_external_bondingdb_set_data_command_id = 0x00,
    sli_bt_external_bondingdb_set_local_irk_command_id = 0x01,
    sli_bt_resolving_list_add_device_by_bonding_command_id = 0x00,
    sli_bt_resolving_list_add_device_by_address_command_id = 0x01,
    sli_bt_resolving_list_remove_device_by_bonding_command_id = 0x02,
    sli_bt_resolving_list_remove_device_by_address_command_id = 0x03,
    sli_bt_resolving_list_remove_all_devices_command_id = 0x04,
    sli_bt_accept_list_add_device_by_bonding_command_id = 0x00,
    sli_bt_accept_list_add_device_by_address_command_id = 0x01,
    sli_bt_accept_list_remove_device_by_bonding_command_id = 0x02,
    sli_bt_accept_list_remove_device_by_address_command_id = 0x03,
    sli_bt_accept_list_remove_all_devices_command_id = 0x04,
    sli_bt_coex_set_options_command_id = 0x00,
    sli_bt_coex_set_parameters_command_id = 0x02,
    sli_bt_coex_set_directional_priority_pulse_command_id = 0x03,
    sli_bt_coex_get_parameters_command_id = 0x04,
    sli_bt_coex_get_counters_command_id = 0x01,
    sli_bt_cs_security_enable_command_id = 0x00,
    sli_bt_cs_set_default_settings_command_id = 0x01,
    sli_bt_cs_create_config_command_id = 0x02,
    sli_bt_cs_remove_config_command_id = 0x03,
    sli_bt_cs_set_channel_classification_command_id = 0x04,
    sli_bt_cs_set_procedure_parameters_command_id = 0x05,
    sli_bt_cs_procedure_enable_command_id = 0x06,
    sli_bt_cs_set_antenna_configuration_command_id = 0x07,
    sli_bt_cs_read_local_supported_capabilities_command_id = 0x08,
    sli_bt_cs_read_remote_supported_capabilities_command_id = 0x09,
    sli_bt_cs_test_start_command_id = 0x00,
    sli_bt_cs_test_end_command_id = 0x01,
    sli_bt_l2cap_open_le_channel_command_id = 0x01,
    sli_bt_l2cap_send_le_channel_open_response_command_id = 0x02,
    sli_bt_l2cap_channel_send_data_command_id = 0x03,
    sli_bt_l2cap_channel_send_credit_command_id = 0x04,
    sli_bt_l2cap_close_channel_command_id = 0x05,
    sli_bt_cte_transmitter_set_dtm_parameters_command_id = 0x04,
    sli_bt_cte_transmitter_clear_dtm_parameters_command_id = 0x05,
    sli_bt_cte_transmitter_enable_connection_cte_command_id = 0x00,
    sli_bt_cte_transmitter_disable_connection_cte_command_id = 0x01,
    sli_bt_cte_transmitter_enable_connectionless_cte_command_id = 0x02,
    sli_bt_cte_transmitter_disable_connectionless_cte_command_id = 0x03,
    sli_bt_cte_transmitter_enable_silabs_cte_command_id = 0x06,
    sli_bt_cte_transmitter_disable_silabs_cte_command_id = 0x07,
    sli_bt_cte_receiver_set_dtm_parameters_command_id = 0x05,
    sli_bt_cte_receiver_clear_dtm_parameters_command_id = 0x06,
    sli_bt_cte_receiver_set_sync_cte_type_command_id = 0x09,
    sli_bt_cte_receiver_set_default_sync_receive_parameters_command_id = 0x0a,
    sli_bt_cte_receiver_set_sync_receive_parameters_command_id = 0x0b,
    sli_bt_cte_receiver_configure_command_id = 0x00,
    sli_bt_cte_receiver_enable_connection_cte_command_id = 0x01,
    sli_bt_cte_receiver_disable_connection_cte_command_id = 0x02,
    sli_bt_cte_receiver_enable_connectionless_cte_command_id = 0x03,
    sli_bt_cte_receiver_disable_connectionless_cte_command_id = 0x04,
    sli_bt_cte_receiver_enable_silabs_cte_command_id = 0x07,
    sli_bt_cte_receiver_disable_silabs_cte_command_id = 0x08,
    sli_bt_connection_analyzer_start_command_id = 0x00,
    sli_bt_connection_analyzer_stop_command_id = 0x01,
    sli_bt_user_message_to_target_command_id = 0x00,
    sli_bt_user_manage_event_filter_command_id = 0x01,
    sli_bt_user_reset_to_dfu_command_id = 0x02,
    sli_bt_user_cs_service_message_to_target_command_id = 0x03,
};

enum sli_bt_response_id
{
    sli_bt_dfu_flash_set_address_response_id = 0x01,
    sli_bt_dfu_flash_upload_response_id = 0x02,
    sli_bt_dfu_flash_upload_finish_response_id = 0x03,
    sli_bt_system_hello_response_id = 0x00,
    sli_bt_system_start_bluetooth_response_id = 0x1c,
    sli_bt_system_stop_bluetooth_response_id = 0x1d,
    sli_bt_system_forcefully_stop_bluetooth_response_id = 0x1e,
    sli_bt_system_get_version_response_id = 0x1b,
    sli_bt_system_reboot_response_id = 0x1f,
    sli_bt_system_halt_response_id = 0x0c,
    sli_bt_system_linklayer_configure_response_id = 0x0e,
    sli_bt_system_set_tx_power_response_id = 0x17,
    sli_bt_system_get_tx_power_setting_response_id = 0x18,
    sli_bt_system_set_identity_address_response_id = 0x13,
    sli_bt_system_get_identity_address_response_id = 0x15,
    sli_bt_system_get_random_data_response_id = 0x0b,
    sli_bt_system_data_buffer_write_response_id = 0x12,
    sli_bt_system_data_buffer_clear_response_id = 0x14,
    sli_bt_system_get_counters_response_id = 0x0f,
    sli_bt_system_set_lazy_soft_timer_response_id = 0x1a,
    sli_bt_system_reset_response_id = 0x01,
    sli_bt_resource_get_status_response_id = 0x00,
    sli_bt_resource_set_report_threshold_response_id = 0x01,
    sli_bt_resource_enable_connection_tx_report_response_id = 0x02,
    sli_bt_resource_get_connection_tx_status_response_id = 0x03,
    sli_bt_resource_disable_connection_tx_report_response_id = 0x04,
    sli_bt_gap_set_privacy_mode_response_id = 0x01,
    sli_bt_gap_set_data_channel_classification_response_id = 0x02,
    sli_bt_gap_set_identity_address_response_id = 0x04,
    sli_bt_gap_get_identity_address_response_id = 0x05,
    sli_bt_advertiser_create_set_response_id = 0x01,
    sli_bt_advertiser_configure_response_id = 0x12,
    sli_bt_advertiser_set_timing_response_id = 0x03,
    sli_bt_advertiser_set_channel_map_response_id = 0x04,
    sli_bt_advertiser_set_tx_power_response_id = 0x0b,
    sli_bt_advertiser_set_report_scan_request_response_id = 0x05,
    sli_bt_advertiser_set_random_address_response_id = 0x10,
    sli_bt_advertiser_clear_random_address_response_id = 0x11,
    sli_bt_advertiser_stop_response_id = 0x0a,
    sli_bt_advertiser_delete_set_response_id = 0x02,
    sli_bt_legacy_advertiser_set_data_response_id = 0x00,
    sli_bt_legacy_advertiser_generate_data_response_id = 0x01,
    sli_bt_legacy_advertiser_start_response_id = 0x02,
    sli_bt_legacy_advertiser_start_directed_response_id = 0x03,
    sli_bt_extended_advertiser_set_phy_response_id = 0x00,
    sli_bt_extended_advertiser_set_data_response_id = 0x01,
    sli_bt_extended_advertiser_set_long_data_response_id = 0x02,
    sli_bt_extended_advertiser_generate_data_response_id = 0x03,
    sli_bt_extended_advertiser_start_response_id = 0x04,
    sli_bt_extended_advertiser_start_directed_response_id = 0x05,
    sli_bt_periodic_advertiser_set_data_response_id = 0x00,
    sli_bt_periodic_advertiser_set_long_data_response_id = 0x01,
    sli_bt_periodic_advertiser_start_response_id = 0x02,
    sli_bt_periodic_advertiser_stop_response_id = 0x03,
    sli_bt_scanner_set_parameters_response_id = 0x06,
    sli_bt_scanner_set_parameters_and_filter_response_id = 0x07,
    sli_bt_scanner_start_response_id = 0x03,
    sli_bt_scanner_stop_response_id = 0x05,
    sli_bt_sync_set_reporting_mode_response_id = 0x03,
    sli_bt_sync_update_sync_parameters_response_id = 0x04,
    sli_bt_sync_close_response_id = 0x01,
    sli_bt_sync_scanner_set_sync_parameters_response_id = 0x00,
    sli_bt_sync_scanner_open_response_id = 0x01,
    sli_bt_past_receiver_set_default_sync_receive_parameters_response_id = 0x00,
    sli_bt_past_receiver_set_sync_receive_parameters_response_id = 0x01,
    sli_bt_past_receiver_set_default_sync_receive_over_sync_parameters_response_id = 0x02,
    sli_bt_past_receiver_set_sync_receive_over_sync_parameters_response_id = 0x03,
    sli_bt_advertiser_past_transfer_response_id = 0x00,
    sli_bt_advertiser_past_transfer_over_pawr_advertiser_response_id = 0x01,
    sli_bt_sync_past_transfer_response_id = 0x00,
    sli_bt_pawr_sync_set_sync_subevents_response_id = 0x02,
    sli_bt_pawr_sync_set_response_data_response_id = 0x03,
    sli_bt_pawr_advertiser_start_response_id = 0x00,
    sli_bt_pawr_advertiser_change_parameters_response_id = 0x04,
    sli_bt_pawr_advertiser_set_subevent_data_response_id = 0x01,
    sli_bt_pawr_advertiser_create_connection_response_id = 0x02,
    sli_bt_pawr_advertiser_stop_response_id = 0x03,
    sli_bt_connection_set_default_parameters_response_id = 0x00,
    sli_bt_connection_set_default_preferred_phy_response_id = 0x01,
    sli_bt_connection_set_default_data_length_response_id = 0x10,
    sli_bt_connection_set_default_acceptable_subrate_response_id = 0x19,
    sli_bt_connection_open_response_id = 0x04,
    sli_bt_connection_open_with_accept_list_response_id = 0x16,
    sli_bt_connection_set_parameters_response_id = 0x06,
    sli_bt_connection_set_preferred_phy_response_id = 0x08,
    sli_bt_connection_disable_slave_latency_response_id = 0x03,
    sli_bt_connection_get_median_rssi_response_id = 0x15,
    sli_bt_connection_read_channel_map_response_id = 0x07,
    sli_bt_connection_set_power_reporting_response_id = 0x09,
    sli_bt_connection_set_remote_power_reporting_response_id = 0x0a,
    sli_bt_connection_get_tx_power_response_id = 0x0b,
    sli_bt_connection_get_remote_tx_power_response_id = 0x0c,
    sli_bt_connection_set_tx_power_response_id = 0x12,
    sli_bt_connection_read_remote_used_features_response_id = 0x0d,
    sli_bt_connection_get_security_status_response_id = 0x0e,
    sli_bt_connection_set_data_length_response_id = 0x11,
    sli_bt_connection_read_statistics_response_id = 0x13,
    sli_bt_connection_get_scheduling_details_response_id = 0x14,
    sli_bt_connection_get_remote_address_response_id = 0x17,
    sli_bt_connection_request_subrate_response_id = 0x1A,
    sli_bt_connection_get_state_response_id = 0x18,
    sli_bt_connection_close_response_id = 0x05,
    sli_bt_connection_forcefully_close_response_id = 0x0f,
    sli_bt_gatt_set_max_mtu_response_id = 0x00,
    sli_bt_gatt_discover_primary_services_response_id = 0x01,
    sli_bt_gatt_discover_primary_services_by_uuid_response_id = 0x02,
    sli_bt_gatt_find_included_services_response_id = 0x10,
    sli_bt_gatt_discover_characteristics_response_id = 0x03,
    sli_bt_gatt_discover_characteristics_by_uuid_response_id = 0x04,
    sli_bt_gatt_discover_descriptors_response_id = 0x06,
    sli_bt_gatt_discover_characteristic_descriptors_response_id = 0x14,
    sli_bt_gatt_set_characteristic_notification_response_id = 0x05,
    sli_bt_gatt_send_characteristic_confirmation_response_id = 0x0d,
    sli_bt_gatt_read_characteristic_value_response_id = 0x07,
    sli_bt_gatt_read_characteristic_value_from_offset_response_id = 0x12,
    sli_bt_gatt_read_multiple_characteristic_values_response_id = 0x17,
    sli_bt_gatt_read_variable_length_characteristic_values_response_id = 0x18,
    sli_bt_gatt_read_characteristic_value_by_uuid_response_id = 0x08,
    sli_bt_gatt_write_characteristic_value_response_id = 0x19,
    sli_bt_gatt_write_characteristic_value_without_response_response_id = 0x1a,
    sli_bt_gatt_prepare_characteristic_value_write_response_id = 0x1b,
    sli_bt_gatt_prepare_characteristic_value_reliable_write_response_id = 0x1c,
    sli_bt_gatt_execute_characteristic_value_write_response_id = 0x0c,
    sli_bt_gatt_read_descriptor_value_response_id = 0x0e,
    sli_bt_gatt_write_descriptor_value_response_id = 0x1d,
    sli_bt_gatt_get_mtu_response_id = 0x15,
    sli_bt_gattdb_new_session_response_id = 0x00,
    sli_bt_gattdb_add_service_response_id = 0x01,
    sli_bt_gattdb_remove_service_response_id = 0x02,
    sli_bt_gattdb_add_included_service_response_id = 0x03,
    sli_bt_gattdb_remove_included_service_response_id = 0x04,
    sli_bt_gattdb_add_uuid16_characteristic_response_id = 0x05,
    sli_bt_gattdb_add_uuid128_characteristic_response_id = 0x06,
    sli_bt_gattdb_remove_characteristic_response_id = 0x07,
    sli_bt_gattdb_add_uuid16_descriptor_response_id = 0x08,
    sli_bt_gattdb_add_uuid128_descriptor_response_id = 0x09,
    sli_bt_gattdb_remove_descriptor_response_id = 0x0a,
    sli_bt_gattdb_start_service_response_id = 0x0b,
    sli_bt_gattdb_stop_service_response_id = 0x0c,
    sli_bt_gattdb_start_characteristic_response_id = 0x0d,
    sli_bt_gattdb_stop_characteristic_response_id = 0x0e,
    sli_bt_gattdb_commit_response_id = 0x0f,
    sli_bt_gattdb_abort_response_id = 0x10,
    sli_bt_gattdb_get_attribute_state_response_id = 0x11,
    sli_bt_gatt_server_set_max_mtu_response_id = 0x0a,
    sli_bt_gatt_server_get_mtu_response_id = 0x0b,
    sli_bt_gatt_server_find_attribute_response_id = 0x06,
    sli_bt_gatt_server_find_primary_service_response_id = 0x09,
    sli_bt_gatt_server_read_attribute_value_response_id = 0x16,
    sli_bt_gatt_server_read_attribute_type_response_id = 0x01,
    sli_bt_gatt_server_read_attribute_properties_response_id = 0x05,
    sli_bt_gatt_server_write_attribute_value_response_id = 0x17,
    sli_bt_gatt_server_send_user_read_response_response_id = 0x18,
    sli_bt_gatt_server_send_user_write_response_response_id = 0x04,
    sli_bt_gatt_server_send_notification_response_id = 0x19,
    sli_bt_gatt_server_send_notification_with_options_response_id = 0x1d,
    sli_bt_gatt_server_send_indication_response_id = 0x1a,
    sli_bt_gatt_server_send_indication_with_options_response_id = 0x1e,
    sli_bt_gatt_server_notify_all_response_id = 0x1b,
    sli_bt_gatt_server_read_client_configuration_response_id = 0x12,
    sli_bt_gatt_server_send_user_prepare_write_response_response_id = 0x1c,
    sli_bt_gatt_server_set_capabilities_response_id = 0x08,
    sli_bt_gatt_server_enable_capabilities_response_id = 0x0c,
    sli_bt_gatt_server_disable_capabilities_response_id = 0x0d,
    sli_bt_gatt_server_get_enabled_capabilities_response_id = 0x0e,
    sli_bt_gatt_server_read_client_supported_features_response_id = 0x15,
    sli_bt_nvm_save_response_id = 0x02,
    sli_bt_nvm_load_response_id = 0x03,
    sli_bt_nvm_erase_response_id = 0x04,
    sli_bt_nvm_erase_all_response_id = 0x01,
    sli_bt_test_dtm_tx_v4_response_id = 0x03,
    sli_bt_test_dtm_tx_cw_response_id = 0x04,
    sli_bt_test_dtm_rx_response_id = 0x01,
    sli_bt_test_dtm_end_response_id = 0x02,
    sli_bt_sm_configure_response_id = 0x01,
    sli_bt_sm_set_minimum_key_size_response_id = 0x14,
    sli_bt_sm_set_debug_mode_response_id = 0x0f,
    sli_bt_sm_store_bonding_configuration_response_id = 0x02,
    sli_bt_sm_set_bondable_mode_response_id = 0x00,
    sli_bt_sm_set_passkey_response_id = 0x10,
    sli_bt_sm_increase_security_response_id = 0x04,
    sli_bt_sm_enter_passkey_response_id = 0x08,
    sli_bt_sm_passkey_confirm_response_id = 0x09,
    sli_bt_sm_bonding_confirm_response_id = 0x0e,
    sli_bt_sm_delete_bonding_response_id = 0x06,
    sli_bt_sm_delete_bondings_response_id = 0x07,
    sli_bt_sm_get_bonding_handles_response_id = 0x15,
    sli_bt_sm_get_bonding_details_response_id = 0x16,
    sli_bt_sm_find_bonding_by_address_response_id = 0x17,
    sli_bt_sm_resolve_rpa_response_id = 0x1d,
    sli_bt_sm_set_bonding_key_response_id = 0x18,
    sli_bt_sm_set_legacy_oob_response_id = 0x19,
    sli_bt_sm_set_oob_response_id = 0x1a,
    sli_bt_sm_set_remote_oob_response_id = 0x1b,
    sli_bt_external_bondingdb_set_data_response_id = 0x00,
    sli_bt_external_bondingdb_set_local_irk_response_id = 0x01,
    sli_bt_resolving_list_add_device_by_bonding_response_id = 0x00,
    sli_bt_resolving_list_add_device_by_address_response_id = 0x01,
    sli_bt_resolving_list_remove_device_by_bonding_response_id = 0x02,
    sli_bt_resolving_list_remove_device_by_address_response_id = 0x03,
    sli_bt_resolving_list_remove_all_devices_response_id = 0x04,
    sli_bt_accept_list_add_device_by_bonding_response_id = 0x00,
    sli_bt_accept_list_add_device_by_address_response_id = 0x01,
    sli_bt_accept_list_remove_device_by_bonding_response_id = 0x02,
    sli_bt_accept_list_remove_device_by_address_response_id = 0x03,
    sli_bt_accept_list_remove_all_devices_response_id = 0x04,
    sli_bt_coex_set_options_response_id = 0x00,
    sli_bt_coex_set_parameters_response_id = 0x02,
    sli_bt_coex_set_directional_priority_pulse_response_id = 0x03,
    sli_bt_coex_get_parameters_response_id = 0x04,
    sli_bt_coex_get_counters_response_id = 0x01,
    sli_bt_cs_security_enable_response_id = 0x00,
    sli_bt_cs_set_default_settings_response_id = 0x01,
    sli_bt_cs_create_config_response_id = 0x02,
    sli_bt_cs_remove_config_response_id = 0x03,
    sli_bt_cs_set_channel_classification_response_id = 0x04,
    sli_bt_cs_set_procedure_parameters_response_id = 0x05,
    sli_bt_cs_procedure_enable_response_id = 0x06,
    sli_bt_cs_set_antenna_configuration_response_id = 0x07,
    sli_bt_cs_read_local_supported_capabilities_response_id = 0x08,
    sli_bt_cs_read_remote_supported_capabilities_response_id = 0x09,
    sli_bt_cs_test_start_response_id = 0x00,
    sli_bt_cs_test_end_response_id = 0x01,
    sli_bt_l2cap_open_le_channel_response_id = 0x01,
    sli_bt_l2cap_send_le_channel_open_response_response_id = 0x02,
    sli_bt_l2cap_channel_send_data_response_id = 0x03,
    sli_bt_l2cap_channel_send_credit_response_id = 0x04,
    sli_bt_l2cap_close_channel_response_id = 0x05,
    sli_bt_cte_transmitter_set_dtm_parameters_response_id = 0x04,
    sli_bt_cte_transmitter_clear_dtm_parameters_response_id = 0x05,
    sli_bt_cte_transmitter_enable_connection_cte_response_id = 0x00,
    sli_bt_cte_transmitter_disable_connection_cte_response_id = 0x01,
    sli_bt_cte_transmitter_enable_connectionless_cte_response_id = 0x02,
    sli_bt_cte_transmitter_disable_connectionless_cte_response_id = 0x03,
    sli_bt_cte_transmitter_enable_silabs_cte_response_id = 0x06,
    sli_bt_cte_transmitter_disable_silabs_cte_response_id = 0x07,
    sli_bt_cte_receiver_set_dtm_parameters_response_id = 0x05,
    sli_bt_cte_receiver_clear_dtm_parameters_response_id = 0x06,
    sli_bt_cte_receiver_set_sync_cte_type_response_id = 0x09,
    sli_bt_cte_receiver_set_default_sync_receive_parameters_response_id = 0x0a,
    sli_bt_cte_receiver_set_sync_receive_parameters_response_id = 0x0b,
    sli_bt_cte_receiver_configure_response_id = 0x00,
    sli_bt_cte_receiver_enable_connection_cte_response_id = 0x01,
    sli_bt_cte_receiver_disable_connection_cte_response_id = 0x02,
    sli_bt_cte_receiver_enable_connectionless_cte_response_id = 0x03,
    sli_bt_cte_receiver_disable_connectionless_cte_response_id = 0x04,
    sli_bt_cte_receiver_enable_silabs_cte_response_id = 0x07,
    sli_bt_cte_receiver_disable_silabs_cte_response_id = 0x08,
    sli_bt_connection_analyzer_start_response_id = 0x00,
    sli_bt_connection_analyzer_stop_response_id = 0x01,
    sli_bt_user_message_to_target_response_id = 0x00,
    sli_bt_user_manage_event_filter_response_id = 0x01,
    sli_bt_user_reset_to_dfu_response_id = 0x02,
    sli_bt_user_cs_service_message_to_target_response_id = 0x03,
};

enum sli_bt_event_id
{
    sli_bt_dfu_boot_event_id = 0x00,
    sli_bt_dfu_boot_failure_event_id = 0x01,
    sli_bt_system_boot_event_id = 0x00,
    sli_bt_system_stopped_event_id = 0x01,
    sli_bt_system_error_event_id = 0x06,
    sli_bt_system_resource_exhausted_event_id = 0x08,
    sli_bt_system_external_signal_event_id = 0x03,
    sli_bt_system_awake_event_id = 0x04,
    sli_bt_system_soft_timer_event_id = 0x07,
    sli_bt_resource_status_event_id = 0x00,
    sli_bt_advertiser_timeout_event_id = 0x01,
    sli_bt_advertiser_scan_request_event_id = 0x02,
    sli_bt_periodic_advertiser_status_event_id = 0x00,
    sli_bt_scanner_legacy_advertisement_report_event_id = 0x00,
    sli_bt_scanner_extended_advertisement_report_event_id = 0x02,
    sli_bt_sync_closed_event_id = 0x01,
    sli_bt_periodic_sync_opened_event_id = 0x00,
    sli_bt_periodic_sync_transfer_received_event_id = 0x01,
    sli_bt_periodic_sync_report_event_id = 0x02,
    sli_bt_pawr_sync_opened_event_id = 0x00,
    sli_bt_pawr_sync_transfer_received_event_id = 0x01,
    sli_bt_pawr_sync_subevent_report_event_id = 0x02,
    sli_bt_pawr_advertiser_subevent_data_request_event_id = 0x00,
    sli_bt_pawr_advertiser_subevent_tx_failed_event_id = 0x02,
    sli_bt_pawr_advertiser_response_report_event_id = 0x01,
    sli_bt_connection_opened_event_id = 0x00,
    sli_bt_connection_parameters_event_id = 0x02,
    sli_bt_connection_set_parameters_failed_event_id = 0x10,
    sli_bt_connection_phy_status_event_id = 0x04,
    sli_bt_connection_get_remote_tx_power_completed_event_id = 0x05,
    sli_bt_connection_tx_power_event_id = 0x06,
    sli_bt_connection_remote_tx_power_event_id = 0x07,
    sli_bt_connection_remote_used_features_event_id = 0x08,
    sli_bt_connection_data_length_event_id = 0x09,
    sli_bt_connection_statistics_event_id = 0x0a,
    sli_bt_connection_request_subrate_failed_event_id = 0x0D,
    sli_bt_connection_subrate_changed_event_id = 0x0E,
    sli_bt_connection_closed_event_id = 0x01,
    sli_bt_gatt_mtu_exchanged_event_id = 0x00,
    sli_bt_gatt_service_event_id = 0x01,
    sli_bt_gatt_characteristic_event_id = 0x02,
    sli_bt_gatt_descriptor_event_id = 0x03,
    sli_bt_gatt_characteristic_value_event_id = 0x07,
    sli_bt_gatt_descriptor_value_event_id = 0x08,
    sli_bt_gatt_procedure_completed_event_id = 0x06,
    sli_bt_gatt_server_attribute_value_event_id = 0x07,
    sli_bt_gatt_server_user_read_request_event_id = 0x01,
    sli_bt_gatt_server_user_write_request_event_id = 0x08,
    sli_bt_gatt_server_characteristic_status_event_id = 0x03,
    sli_bt_gatt_server_execute_write_completed_event_id = 0x04,
    sli_bt_gatt_server_indication_timeout_event_id = 0x05,
    sli_bt_gatt_server_notification_tx_completed_event_id = 0x06,
    sli_bt_test_dtm_completed_event_id = 0x00,
    sli_bt_sm_passkey_display_event_id = 0x00,
    sli_bt_sm_passkey_request_event_id = 0x01,
    sli_bt_sm_confirm_passkey_event_id = 0x02,
    sli_bt_sm_bonded_event_id = 0x03,
    sli_bt_sm_bonding_failed_event_id = 0x04,
    sli_bt_sm_confirm_bonding_event_id = 0x09,
    sli_bt_external_bondingdb_data_request_event_id = 0x00,
    sli_bt_external_bondingdb_data_event_id = 0x01,
    sli_bt_external_bondingdb_data_ready_event_id = 0x02,
    sli_bt_external_bondingdb_local_irk_request_event_id = 0x03,
    sli_bt_external_bondingdb_local_irk_event_id = 0x04,
    sli_bt_cs_security_enable_complete_event_id = 0x00,
    sli_bt_cs_config_complete_event_id = 0x01,
    sli_bt_cs_procedure_enable_complete_event_id = 0x02,
    sli_bt_cs_result_event_id = 0x03,
    sli_bt_cs_result_continue_event_id = 0x05,
    sli_bt_cs_read_remote_supported_capabilities_complete_event_id = 0x04,
    sli_bt_cs_test_end_completed_event_id = 0x00,
    sli_bt_l2cap_le_channel_open_request_event_id = 0x01,
    sli_bt_l2cap_le_channel_open_response_event_id = 0x02,
    sli_bt_l2cap_channel_data_event_id = 0x03,
    sli_bt_l2cap_channel_credit_event_id = 0x04,
    sli_bt_l2cap_channel_closed_event_id = 0x05,
    sli_bt_l2cap_command_rejected_event_id = 0x06,
    sli_bt_cte_receiver_dtm_iq_report_event_id = 0x02,
    sli_bt_cte_receiver_connection_iq_report_event_id = 0x00,
    sli_bt_cte_receiver_connectionless_iq_report_event_id = 0x01,
    sli_bt_cte_receiver_silabs_iq_report_event_id = 0x03,
    sli_bt_connection_analyzer_report_event_id = 0x00,
    sli_bt_connection_analyzer_completed_event_id = 0x01,
    sli_bt_user_message_to_host_event_id = 0x00,
    sli_bt_user_cs_service_message_to_host_event_id = 0x01,
};

PACKSTRUCT( struct sl_bt_rsp_error_s
{
    uint16_t            result;
});

typedef struct sl_bt_rsp_error_s sl_bt_rsp_error_t;

PACKSTRUCT( struct sl_bt_cmd_dfu_flash_set_address_s
{
    uint32_t address;
});

typedef struct sl_bt_cmd_dfu_flash_set_address_s sl_bt_cmd_dfu_flash_set_address_t;


PACKSTRUCT( struct sl_bt_cmd_dfu_flash_upload_s
{
    uint8array data;
});

typedef struct sl_bt_cmd_dfu_flash_upload_s sl_bt_cmd_dfu_flash_upload_t;


PACKSTRUCT( struct sl_bt_cmd_system_halt_s
{
    uint8_t halt;
});

typedef struct sl_bt_cmd_system_halt_s sl_bt_cmd_system_halt_t;


PACKSTRUCT( struct sl_bt_cmd_system_linklayer_configure_s
{
    uint8_t key;
    uint8array data;
});

typedef struct sl_bt_cmd_system_linklayer_configure_s sl_bt_cmd_system_linklayer_configure_t;


PACKSTRUCT( struct sl_bt_cmd_system_set_tx_power_s
{
    int16_t min_power;
    int16_t max_power;
});

typedef struct sl_bt_cmd_system_set_tx_power_s sl_bt_cmd_system_set_tx_power_t;


PACKSTRUCT( struct sl_bt_cmd_system_set_identity_address_s
{
    bd_addr address;
    uint8_t type;
});

typedef struct sl_bt_cmd_system_set_identity_address_s sl_bt_cmd_system_set_identity_address_t;


PACKSTRUCT( struct sl_bt_cmd_system_get_random_data_s
{
    uint8_t length;
});

typedef struct sl_bt_cmd_system_get_random_data_s sl_bt_cmd_system_get_random_data_t;


PACKSTRUCT( struct sl_bt_cmd_system_data_buffer_write_s
{
    uint8array data;
});

typedef struct sl_bt_cmd_system_data_buffer_write_s sl_bt_cmd_system_data_buffer_write_t;


PACKSTRUCT( struct sl_bt_cmd_system_get_counters_s
{
    uint8_t reset;
});

typedef struct sl_bt_cmd_system_get_counters_s sl_bt_cmd_system_get_counters_t;


PACKSTRUCT( struct sl_bt_cmd_system_set_lazy_soft_timer_s
{
    uint32_t time;
    uint32_t slack;
    uint8_t handle;
    uint8_t single_shot;
});

typedef struct sl_bt_cmd_system_set_lazy_soft_timer_s sl_bt_cmd_system_set_lazy_soft_timer_t;


PACKSTRUCT( struct sl_bt_cmd_system_reset_s
{
    uint8_t dfu;
});

typedef struct sl_bt_cmd_system_reset_s sl_bt_cmd_system_reset_t;


PACKSTRUCT( struct sl_bt_cmd_resource_set_report_threshold_s
{
    uint32_t low;
    uint32_t high;
});

typedef struct sl_bt_cmd_resource_set_report_threshold_s sl_bt_cmd_resource_set_report_threshold_t;


PACKSTRUCT( struct sl_bt_cmd_resource_enable_connection_tx_report_s
{
    uint16_t packet_count;
});

typedef struct sl_bt_cmd_resource_enable_connection_tx_report_s sl_bt_cmd_resource_enable_connection_tx_report_t;


PACKSTRUCT( struct sl_bt_cmd_resource_get_connection_tx_status_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_resource_get_connection_tx_status_s sl_bt_cmd_resource_get_connection_tx_status_t;


PACKSTRUCT( struct sl_bt_cmd_gap_set_privacy_mode_s
{
    uint8_t privacy;
    uint8_t interval;
});

typedef struct sl_bt_cmd_gap_set_privacy_mode_s sl_bt_cmd_gap_set_privacy_mode_t;


PACKSTRUCT( struct sl_bt_cmd_gap_set_data_channel_classification_s
{
    uint8array channel_map;
});

typedef struct sl_bt_cmd_gap_set_data_channel_classification_s sl_bt_cmd_gap_set_data_channel_classification_t;


PACKSTRUCT( struct sl_bt_cmd_gap_set_identity_address_s
{
    bd_addr address;
    uint8_t addr_type;
});

typedef struct sl_bt_cmd_gap_set_identity_address_s sl_bt_cmd_gap_set_identity_address_t;


PACKSTRUCT( struct sl_bt_cmd_advertiser_configure_s
{
    uint8_t advertising_set;
    uint32_t flags;
});

typedef struct sl_bt_cmd_advertiser_configure_s sl_bt_cmd_advertiser_configure_t;


PACKSTRUCT( struct sl_bt_cmd_advertiser_set_timing_s
{
    uint8_t advertising_set;
    uint32_t interval_min;
    uint32_t interval_max;
    uint16_t duration;
    uint8_t maxevents;
});

typedef struct sl_bt_cmd_advertiser_set_timing_s sl_bt_cmd_advertiser_set_timing_t;


PACKSTRUCT( struct sl_bt_cmd_advertiser_set_channel_map_s
{
    uint8_t advertising_set;
    uint8_t channel_map;
});

typedef struct sl_bt_cmd_advertiser_set_channel_map_s sl_bt_cmd_advertiser_set_channel_map_t;


PACKSTRUCT( struct sl_bt_cmd_advertiser_set_tx_power_s
{
    uint8_t advertising_set;
    int16_t power;
});

typedef struct sl_bt_cmd_advertiser_set_tx_power_s sl_bt_cmd_advertiser_set_tx_power_t;


PACKSTRUCT( struct sl_bt_cmd_advertiser_set_report_scan_request_s
{
    uint8_t advertising_set;
    uint8_t report_scan_req;
});

typedef struct sl_bt_cmd_advertiser_set_report_scan_request_s sl_bt_cmd_advertiser_set_report_scan_request_t;


PACKSTRUCT( struct sl_bt_cmd_advertiser_set_random_address_s
{
    uint8_t advertising_set;
    uint8_t addr_type;
    bd_addr address;
});

typedef struct sl_bt_cmd_advertiser_set_random_address_s sl_bt_cmd_advertiser_set_random_address_t;


PACKSTRUCT( struct sl_bt_cmd_advertiser_clear_random_address_s
{
    uint8_t advertising_set;
});

typedef struct sl_bt_cmd_advertiser_clear_random_address_s sl_bt_cmd_advertiser_clear_random_address_t;


PACKSTRUCT( struct sl_bt_cmd_advertiser_stop_s
{
    uint8_t advertising_set;
});

typedef struct sl_bt_cmd_advertiser_stop_s sl_bt_cmd_advertiser_stop_t;


PACKSTRUCT( struct sl_bt_cmd_advertiser_delete_set_s
{
    uint8_t advertising_set;
});

typedef struct sl_bt_cmd_advertiser_delete_set_s sl_bt_cmd_advertiser_delete_set_t;


PACKSTRUCT( struct sl_bt_cmd_legacy_advertiser_set_data_s
{
    uint8_t advertising_set;
    uint8_t type;
    uint8array data;
});

typedef struct sl_bt_cmd_legacy_advertiser_set_data_s sl_bt_cmd_legacy_advertiser_set_data_t;


PACKSTRUCT( struct sl_bt_cmd_legacy_advertiser_generate_data_s
{
    uint8_t advertising_set;
    uint8_t discover;
});

typedef struct sl_bt_cmd_legacy_advertiser_generate_data_s sl_bt_cmd_legacy_advertiser_generate_data_t;


PACKSTRUCT( struct sl_bt_cmd_legacy_advertiser_start_s
{
    uint8_t advertising_set;
    uint8_t connect;
});

typedef struct sl_bt_cmd_legacy_advertiser_start_s sl_bt_cmd_legacy_advertiser_start_t;


PACKSTRUCT( struct sl_bt_cmd_legacy_advertiser_start_directed_s
{
    uint8_t advertising_set;
    uint8_t connect;
    bd_addr peer_addr;
    uint8_t peer_addr_type;
});

typedef struct sl_bt_cmd_legacy_advertiser_start_directed_s sl_bt_cmd_legacy_advertiser_start_directed_t;


PACKSTRUCT( struct sl_bt_cmd_extended_advertiser_set_phy_s
{
    uint8_t advertising_set;
    uint8_t primary_phy;
    uint8_t secondary_phy;
});

typedef struct sl_bt_cmd_extended_advertiser_set_phy_s sl_bt_cmd_extended_advertiser_set_phy_t;


PACKSTRUCT( struct sl_bt_cmd_extended_advertiser_set_data_s
{
    uint8_t advertising_set;
    uint8array data;
});

typedef struct sl_bt_cmd_extended_advertiser_set_data_s sl_bt_cmd_extended_advertiser_set_data_t;


PACKSTRUCT( struct sl_bt_cmd_extended_advertiser_set_long_data_s
{
    uint8_t advertising_set;
});

typedef struct sl_bt_cmd_extended_advertiser_set_long_data_s sl_bt_cmd_extended_advertiser_set_long_data_t;


PACKSTRUCT( struct sl_bt_cmd_extended_advertiser_generate_data_s
{
    uint8_t advertising_set;
    uint8_t discover;
});

typedef struct sl_bt_cmd_extended_advertiser_generate_data_s sl_bt_cmd_extended_advertiser_generate_data_t;


PACKSTRUCT( struct sl_bt_cmd_extended_advertiser_start_s
{
    uint8_t advertising_set;
    uint8_t connect;
    uint32_t flags;
});

typedef struct sl_bt_cmd_extended_advertiser_start_s sl_bt_cmd_extended_advertiser_start_t;


PACKSTRUCT( struct sl_bt_cmd_extended_advertiser_start_directed_s
{
    uint8_t advertising_set;
    uint8_t connect;
    uint32_t flags;
    bd_addr peer_addr;
    uint8_t peer_addr_type;
});

typedef struct sl_bt_cmd_extended_advertiser_start_directed_s sl_bt_cmd_extended_advertiser_start_directed_t;


PACKSTRUCT( struct sl_bt_cmd_periodic_advertiser_set_data_s
{
    uint8_t advertising_set;
    uint8array data;
});

typedef struct sl_bt_cmd_periodic_advertiser_set_data_s sl_bt_cmd_periodic_advertiser_set_data_t;


PACKSTRUCT( struct sl_bt_cmd_periodic_advertiser_set_long_data_s
{
    uint8_t advertising_set;
});

typedef struct sl_bt_cmd_periodic_advertiser_set_long_data_s sl_bt_cmd_periodic_advertiser_set_long_data_t;


PACKSTRUCT( struct sl_bt_cmd_periodic_advertiser_start_s
{
    uint8_t advertising_set;
    uint16_t interval_min;
    uint16_t interval_max;
    uint32_t flags;
});

typedef struct sl_bt_cmd_periodic_advertiser_start_s sl_bt_cmd_periodic_advertiser_start_t;


PACKSTRUCT( struct sl_bt_cmd_periodic_advertiser_stop_s
{
    uint8_t advertising_set;
});

typedef struct sl_bt_cmd_periodic_advertiser_stop_s sl_bt_cmd_periodic_advertiser_stop_t;


PACKSTRUCT( struct sl_bt_cmd_scanner_set_parameters_s
{
    uint8_t mode;
    uint16_t interval;
    uint16_t window;
});

typedef struct sl_bt_cmd_scanner_set_parameters_s sl_bt_cmd_scanner_set_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_scanner_set_parameters_and_filter_s
{
    uint8_t mode;
    uint16_t interval;
    uint16_t window;
    uint32_t flags;
    uint8_t filter_policy;
});

typedef struct sl_bt_cmd_scanner_set_parameters_and_filter_s sl_bt_cmd_scanner_set_parameters_and_filter_t;


PACKSTRUCT( struct sl_bt_cmd_scanner_start_s
{
    uint8_t scanning_phy;
    uint8_t discover_mode;
});

typedef struct sl_bt_cmd_scanner_start_s sl_bt_cmd_scanner_start_t;


PACKSTRUCT( struct sl_bt_cmd_sync_set_reporting_mode_s
{
    uint16_t sync;
    uint8_t reporting_mode;
});

typedef struct sl_bt_cmd_sync_set_reporting_mode_s sl_bt_cmd_sync_set_reporting_mode_t;


PACKSTRUCT( struct sl_bt_cmd_sync_update_sync_parameters_s
{
    uint16_t sync;
    uint16_t skip;
    uint16_t timeout;
});

typedef struct sl_bt_cmd_sync_update_sync_parameters_s sl_bt_cmd_sync_update_sync_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_sync_close_s
{
    uint16_t sync;
});

typedef struct sl_bt_cmd_sync_close_s sl_bt_cmd_sync_close_t;


PACKSTRUCT( struct sl_bt_cmd_sync_scanner_set_sync_parameters_s
{
    uint16_t skip;
    uint16_t timeout;
    uint8_t reporting_mode;
});

typedef struct sl_bt_cmd_sync_scanner_set_sync_parameters_s sl_bt_cmd_sync_scanner_set_sync_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_sync_scanner_open_s
{
    bd_addr address;
    uint8_t address_type;
    uint8_t adv_sid;
});

typedef struct sl_bt_cmd_sync_scanner_open_s sl_bt_cmd_sync_scanner_open_t;


PACKSTRUCT( struct sl_bt_cmd_past_receiver_set_default_sync_receive_parameters_s
{
    uint8_t mode;
    uint16_t skip;
    uint16_t timeout;
    uint8_t reporting_mode;
});

typedef struct sl_bt_cmd_past_receiver_set_default_sync_receive_parameters_s sl_bt_cmd_past_receiver_set_default_sync_receive_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_past_receiver_set_sync_receive_parameters_s
{
    uint8_t connection;
    uint8_t mode;
    uint16_t skip;
    uint16_t timeout;
    uint8_t reporting_mode;
});

typedef struct sl_bt_cmd_past_receiver_set_sync_receive_parameters_s sl_bt_cmd_past_receiver_set_sync_receive_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_past_receiver_set_default_sync_receive_over_sync_parameters_s
{
    uint8_t mode;
    uint16_t skip;
    uint16_t timeout;
    uint8_t reporting_mode;
});

typedef struct sl_bt_cmd_past_receiver_set_default_sync_receive_over_sync_parameters_s sl_bt_cmd_past_receiver_set_default_sync_receive_over_sync_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_past_receiver_set_sync_receive_over_sync_parameters_s
{
    uint16_t sync;
    uint8_t mode;
    uint16_t skip;
    uint16_t timeout;
    uint8_t reporting_mode;
});

typedef struct sl_bt_cmd_past_receiver_set_sync_receive_over_sync_parameters_s sl_bt_cmd_past_receiver_set_sync_receive_over_sync_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_advertiser_past_transfer_s
{
    uint8_t connection;
    uint16_t service_data;
    uint8_t advertising_set;
});

typedef struct sl_bt_cmd_advertiser_past_transfer_s sl_bt_cmd_advertiser_past_transfer_t;


PACKSTRUCT( struct sl_bt_cmd_advertiser_past_transfer_over_pawr_advertiser_s
{
    uint8_t transferring_advertising_set;
    uint16_t service_data;
    uint8_t advertising_set;
    uint8_t repeat_count;
    uint8array subevents;
});

typedef struct sl_bt_cmd_advertiser_past_transfer_over_pawr_advertiser_s sl_bt_cmd_advertiser_past_transfer_over_pawr_advertiser_t;


PACKSTRUCT( struct sl_bt_cmd_sync_past_transfer_s
{
    uint8_t connection;
    uint16_t service_data;
    uint16_t sync;
});

typedef struct sl_bt_cmd_sync_past_transfer_s sl_bt_cmd_sync_past_transfer_t;


PACKSTRUCT( struct sl_bt_cmd_pawr_sync_set_sync_subevents_s
{
    uint16_t sync;
    uint8array subevents;
});

typedef struct sl_bt_cmd_pawr_sync_set_sync_subevents_s sl_bt_cmd_pawr_sync_set_sync_subevents_t;


PACKSTRUCT( struct sl_bt_cmd_pawr_sync_set_response_data_s
{
    uint16_t sync;
    uint16_t request_event;
    uint8_t request_subevent;
    uint8_t response_subevent;
    uint8_t response_slot;
    uint8array response_data;
});

typedef struct sl_bt_cmd_pawr_sync_set_response_data_s sl_bt_cmd_pawr_sync_set_response_data_t;


PACKSTRUCT( struct sl_bt_cmd_pawr_advertiser_start_s
{
    uint8_t advertising_set;
    uint16_t interval_min;
    uint16_t interval_max;
    uint32_t flags;
    uint8_t num_subevents;
    uint8_t subevent_interval;
    uint8_t response_slot_delay;
    uint8_t response_slot_spacing;
    uint8_t response_slots;
});

typedef struct sl_bt_cmd_pawr_advertiser_start_s sl_bt_cmd_pawr_advertiser_start_t;


PACKSTRUCT( struct sl_bt_cmd_pawr_advertiser_change_parameters_s
{
    uint8_t advertising_set;
    uint16_t interval_min;
    uint16_t interval_max;
    uint32_t flags;
    uint8_t num_subevents;
    uint8_t subevent_interval;
    uint8_t response_slot_delay;
    uint8_t response_slot_spacing;
    uint8_t response_slots;
    uint8_t phy;
    uint8_t repeat_count;
});

typedef struct sl_bt_cmd_pawr_advertiser_change_parameters_s sl_bt_cmd_pawr_advertiser_change_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_pawr_advertiser_set_subevent_data_s
{
    uint8_t advertising_set;
    uint8_t subevent;
    uint8_t response_slot_start;
    uint8_t response_slot_count;
    uint8array adv_data;
});

typedef struct sl_bt_cmd_pawr_advertiser_set_subevent_data_s sl_bt_cmd_pawr_advertiser_set_subevent_data_t;


PACKSTRUCT( struct sl_bt_cmd_pawr_advertiser_create_connection_s
{
    uint8_t advertising_set;
    uint8_t subevent;
    bd_addr address;
    uint8_t address_type;
});

typedef struct sl_bt_cmd_pawr_advertiser_create_connection_s sl_bt_cmd_pawr_advertiser_create_connection_t;


PACKSTRUCT( struct sl_bt_cmd_pawr_advertiser_stop_s
{
    uint8_t advertising_set;
});

typedef struct sl_bt_cmd_pawr_advertiser_stop_s sl_bt_cmd_pawr_advertiser_stop_t;


PACKSTRUCT( struct sl_bt_cmd_connection_set_default_parameters_s
{
    uint16_t min_interval;
    uint16_t max_interval;
    uint16_t latency;
    uint16_t timeout;
    uint16_t min_ce_length;
    uint16_t max_ce_length;
});

typedef struct sl_bt_cmd_connection_set_default_parameters_s sl_bt_cmd_connection_set_default_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_connection_set_default_preferred_phy_s
{
    uint8_t preferred_phy;
    uint8_t accepted_phy;
});

typedef struct sl_bt_cmd_connection_set_default_preferred_phy_s sl_bt_cmd_connection_set_default_preferred_phy_t;


PACKSTRUCT( struct sl_bt_cmd_connection_set_default_data_length_s
{
    uint16_t tx_data_len;
});

typedef struct sl_bt_cmd_connection_set_default_data_length_s sl_bt_cmd_connection_set_default_data_length_t;


PACKSTRUCT( struct sl_bt_cmd_connection_set_default_acceptable_subrate_s
{
    uint16_t min_subrate;
    uint16_t max_subrate;
    uint16_t max_latency;
    uint16_t continuation_number;
    uint16_t max_timeout;
});

typedef struct sl_bt_cmd_connection_set_default_acceptable_subrate_s sl_bt_cmd_connection_set_default_acceptable_subrate_t;


PACKSTRUCT( struct sl_bt_cmd_connection_open_s
{
    bd_addr address;
    uint8_t address_type;
    uint8_t initiating_phy;
});

typedef struct sl_bt_cmd_connection_open_s sl_bt_cmd_connection_open_t;


PACKSTRUCT( struct sl_bt_cmd_connection_open_with_accept_list_s
{
    uint8_t initiating_phy;
});

typedef struct sl_bt_cmd_connection_open_with_accept_list_s sl_bt_cmd_connection_open_with_accept_list_t;


PACKSTRUCT( struct sl_bt_cmd_connection_set_parameters_s
{
    uint8_t connection;
    uint16_t min_interval;
    uint16_t max_interval;
    uint16_t latency;
    uint16_t timeout;
    uint16_t min_ce_length;
    uint16_t max_ce_length;
});

typedef struct sl_bt_cmd_connection_set_parameters_s sl_bt_cmd_connection_set_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_connection_set_preferred_phy_s
{
    uint8_t connection;
    uint8_t preferred_phy;
    uint8_t accepted_phy;
});

typedef struct sl_bt_cmd_connection_set_preferred_phy_s sl_bt_cmd_connection_set_preferred_phy_t;


PACKSTRUCT( struct sl_bt_cmd_connection_disable_slave_latency_s
{
    uint8_t connection;
    uint8_t disable;
});

typedef struct sl_bt_cmd_connection_disable_slave_latency_s sl_bt_cmd_connection_disable_slave_latency_t;


PACKSTRUCT( struct sl_bt_cmd_connection_get_median_rssi_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_connection_get_median_rssi_s sl_bt_cmd_connection_get_median_rssi_t;


PACKSTRUCT( struct sl_bt_cmd_connection_read_channel_map_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_connection_read_channel_map_s sl_bt_cmd_connection_read_channel_map_t;


PACKSTRUCT( struct sl_bt_cmd_connection_set_power_reporting_s
{
    uint8_t connection;
    uint8_t mode;
});

typedef struct sl_bt_cmd_connection_set_power_reporting_s sl_bt_cmd_connection_set_power_reporting_t;


PACKSTRUCT( struct sl_bt_cmd_connection_set_remote_power_reporting_s
{
    uint8_t connection;
    uint8_t mode;
});

typedef struct sl_bt_cmd_connection_set_remote_power_reporting_s sl_bt_cmd_connection_set_remote_power_reporting_t;


PACKSTRUCT( struct sl_bt_cmd_connection_get_tx_power_s
{
    uint8_t connection;
    uint8_t phy;
});

typedef struct sl_bt_cmd_connection_get_tx_power_s sl_bt_cmd_connection_get_tx_power_t;


PACKSTRUCT( struct sl_bt_cmd_connection_get_remote_tx_power_s
{
    uint8_t connection;
    uint8_t phy;
});

typedef struct sl_bt_cmd_connection_get_remote_tx_power_s sl_bt_cmd_connection_get_remote_tx_power_t;


PACKSTRUCT( struct sl_bt_cmd_connection_set_tx_power_s
{
    uint8_t connection;
    int16_t tx_power;
});

typedef struct sl_bt_cmd_connection_set_tx_power_s sl_bt_cmd_connection_set_tx_power_t;


PACKSTRUCT( struct sl_bt_cmd_connection_read_remote_used_features_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_connection_read_remote_used_features_s sl_bt_cmd_connection_read_remote_used_features_t;


PACKSTRUCT( struct sl_bt_cmd_connection_get_security_status_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_connection_get_security_status_s sl_bt_cmd_connection_get_security_status_t;


PACKSTRUCT( struct sl_bt_cmd_connection_set_data_length_s
{
    uint8_t connection;
    uint16_t tx_data_len;
    uint16_t tx_time_us;
});

typedef struct sl_bt_cmd_connection_set_data_length_s sl_bt_cmd_connection_set_data_length_t;


PACKSTRUCT( struct sl_bt_cmd_connection_read_statistics_s
{
    uint8_t connection;
    uint8_t reset;
});

typedef struct sl_bt_cmd_connection_read_statistics_s sl_bt_cmd_connection_read_statistics_t;


PACKSTRUCT( struct sl_bt_cmd_connection_get_scheduling_details_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_connection_get_scheduling_details_s sl_bt_cmd_connection_get_scheduling_details_t;


PACKSTRUCT( struct sl_bt_cmd_connection_get_remote_address_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_connection_get_remote_address_s sl_bt_cmd_connection_get_remote_address_t;


PACKSTRUCT( struct sl_bt_cmd_connection_request_subrate_s
{
    uint8_t connection;
    uint16_t min_subrate;
    uint16_t max_subrate;
    uint16_t max_latency;
    uint16_t continuation_number;
    uint16_t timeout;
});

typedef struct sl_bt_cmd_connection_request_subrate_s sl_bt_cmd_connection_request_subrate_t;


PACKSTRUCT( struct sl_bt_cmd_connection_get_state_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_connection_get_state_s sl_bt_cmd_connection_get_state_t;


PACKSTRUCT( struct sl_bt_cmd_connection_close_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_connection_close_s sl_bt_cmd_connection_close_t;


PACKSTRUCT( struct sl_bt_cmd_connection_forcefully_close_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_connection_forcefully_close_s sl_bt_cmd_connection_forcefully_close_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_set_max_mtu_s
{
    uint16_t max_mtu;
});

typedef struct sl_bt_cmd_gatt_set_max_mtu_s sl_bt_cmd_gatt_set_max_mtu_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_discover_primary_services_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_gatt_discover_primary_services_s sl_bt_cmd_gatt_discover_primary_services_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_discover_primary_services_by_uuid_s
{
    uint8_t connection;
    uint8array uuid;
});

typedef struct sl_bt_cmd_gatt_discover_primary_services_by_uuid_s sl_bt_cmd_gatt_discover_primary_services_by_uuid_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_find_included_services_s
{
    uint8_t connection;
    uint32_t service;
});

typedef struct sl_bt_cmd_gatt_find_included_services_s sl_bt_cmd_gatt_find_included_services_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_discover_characteristics_s
{
    uint8_t connection;
    uint32_t service;
});

typedef struct sl_bt_cmd_gatt_discover_characteristics_s sl_bt_cmd_gatt_discover_characteristics_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_discover_characteristics_by_uuid_s
{
    uint8_t connection;
    uint32_t service;
    uint8array uuid;
});

typedef struct sl_bt_cmd_gatt_discover_characteristics_by_uuid_s sl_bt_cmd_gatt_discover_characteristics_by_uuid_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_discover_descriptors_s
{
    uint8_t connection;
    uint16_t characteristic;
});

typedef struct sl_bt_cmd_gatt_discover_descriptors_s sl_bt_cmd_gatt_discover_descriptors_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_discover_characteristic_descriptors_s
{
    uint8_t connection;
    uint16_t start;
    uint16_t end;
});

typedef struct sl_bt_cmd_gatt_discover_characteristic_descriptors_s sl_bt_cmd_gatt_discover_characteristic_descriptors_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_set_characteristic_notification_s
{
    uint8_t connection;
    uint16_t characteristic;
    uint8_t flags;
});

typedef struct sl_bt_cmd_gatt_set_characteristic_notification_s sl_bt_cmd_gatt_set_characteristic_notification_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_send_characteristic_confirmation_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_gatt_send_characteristic_confirmation_s sl_bt_cmd_gatt_send_characteristic_confirmation_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_read_characteristic_value_s
{
    uint8_t connection;
    uint16_t characteristic;
});

typedef struct sl_bt_cmd_gatt_read_characteristic_value_s sl_bt_cmd_gatt_read_characteristic_value_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_read_characteristic_value_from_offset_s
{
    uint8_t connection;
    uint16_t characteristic;
    uint16_t offset;
    uint16_t maxlen;
});

typedef struct sl_bt_cmd_gatt_read_characteristic_value_from_offset_s sl_bt_cmd_gatt_read_characteristic_value_from_offset_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_read_multiple_characteristic_values_s
{
    uint8_t connection;
    byte_array characteristic_list;
});

typedef struct sl_bt_cmd_gatt_read_multiple_characteristic_values_s sl_bt_cmd_gatt_read_multiple_characteristic_values_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_read_variable_length_characteristic_values_s
{
    uint8_t connection;
    byte_array characteristic_list;
});

typedef struct sl_bt_cmd_gatt_read_variable_length_characteristic_values_s sl_bt_cmd_gatt_read_variable_length_characteristic_values_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_read_characteristic_value_by_uuid_s
{
    uint8_t connection;
    uint32_t service;
    uint8array uuid;
});

typedef struct sl_bt_cmd_gatt_read_characteristic_value_by_uuid_s sl_bt_cmd_gatt_read_characteristic_value_by_uuid_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_write_characteristic_value_s
{
    uint8_t connection;
    uint16_t characteristic;
    byte_array value;
});

typedef struct sl_bt_cmd_gatt_write_characteristic_value_s sl_bt_cmd_gatt_write_characteristic_value_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_write_characteristic_value_without_response_s
{
    uint8_t connection;
    uint16_t characteristic;
    byte_array value;
});

typedef struct sl_bt_cmd_gatt_write_characteristic_value_without_response_s sl_bt_cmd_gatt_write_characteristic_value_without_response_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_prepare_characteristic_value_write_s
{
    uint8_t connection;
    uint16_t characteristic;
    uint16_t offset;
    byte_array value;
});

typedef struct sl_bt_cmd_gatt_prepare_characteristic_value_write_s sl_bt_cmd_gatt_prepare_characteristic_value_write_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_prepare_characteristic_value_reliable_write_s
{
    uint8_t connection;
    uint16_t characteristic;
    uint16_t offset;
    byte_array value;
});

typedef struct sl_bt_cmd_gatt_prepare_characteristic_value_reliable_write_s sl_bt_cmd_gatt_prepare_characteristic_value_reliable_write_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_execute_characteristic_value_write_s
{
    uint8_t connection;
    uint8_t flags;
});

typedef struct sl_bt_cmd_gatt_execute_characteristic_value_write_s sl_bt_cmd_gatt_execute_characteristic_value_write_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_read_descriptor_value_s
{
    uint8_t connection;
    uint16_t descriptor;
});

typedef struct sl_bt_cmd_gatt_read_descriptor_value_s sl_bt_cmd_gatt_read_descriptor_value_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_write_descriptor_value_s
{
    uint8_t connection;
    uint16_t descriptor;
    byte_array value;
});

typedef struct sl_bt_cmd_gatt_write_descriptor_value_s sl_bt_cmd_gatt_write_descriptor_value_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_get_mtu_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_gatt_get_mtu_s sl_bt_cmd_gatt_get_mtu_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_add_service_s
{
    uint16_t session;
    uint8_t type;
    uint8_t property;
    uint8array uuid;
});

typedef struct sl_bt_cmd_gattdb_add_service_s sl_bt_cmd_gattdb_add_service_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_remove_service_s
{
    uint16_t session;
    uint16_t service;
});

typedef struct sl_bt_cmd_gattdb_remove_service_s sl_bt_cmd_gattdb_remove_service_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_add_included_service_s
{
    uint16_t session;
    uint16_t service;
    uint16_t included_service;
});

typedef struct sl_bt_cmd_gattdb_add_included_service_s sl_bt_cmd_gattdb_add_included_service_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_remove_included_service_s
{
    uint16_t session;
    uint16_t attribute;
});

typedef struct sl_bt_cmd_gattdb_remove_included_service_s sl_bt_cmd_gattdb_remove_included_service_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_add_uuid16_characteristic_s
{
    uint16_t session;
    uint16_t service;
    uint16_t property;
    uint16_t security;
    uint8_t flag;
    sl_bt_uuid_16_t uuid;
    uint8_t value_type;
    uint16_t maxlen;
    byte_array value;
});

typedef struct sl_bt_cmd_gattdb_add_uuid16_characteristic_s sl_bt_cmd_gattdb_add_uuid16_characteristic_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_add_uuid128_characteristic_s
{
    uint16_t session;
    uint16_t service;
    uint16_t property;
    uint16_t security;
    uint8_t flag;
    uuid_128 uuid;
    uint8_t value_type;
    uint16_t maxlen;
    byte_array value;
});

typedef struct sl_bt_cmd_gattdb_add_uuid128_characteristic_s sl_bt_cmd_gattdb_add_uuid128_characteristic_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_remove_characteristic_s
{
    uint16_t session;
    uint16_t characteristic;
});

typedef struct sl_bt_cmd_gattdb_remove_characteristic_s sl_bt_cmd_gattdb_remove_characteristic_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_add_uuid16_descriptor_s
{
    uint16_t session;
    uint16_t characteristic;
    uint16_t property;
    uint16_t security;
    sl_bt_uuid_16_t uuid;
    uint8_t value_type;
    uint16_t maxlen;
    byte_array value;
});

typedef struct sl_bt_cmd_gattdb_add_uuid16_descriptor_s sl_bt_cmd_gattdb_add_uuid16_descriptor_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_add_uuid128_descriptor_s
{
    uint16_t session;
    uint16_t characteristic;
    uint16_t property;
    uint16_t security;
    uuid_128 uuid;
    uint8_t value_type;
    uint16_t maxlen;
    byte_array value;
});

typedef struct sl_bt_cmd_gattdb_add_uuid128_descriptor_s sl_bt_cmd_gattdb_add_uuid128_descriptor_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_remove_descriptor_s
{
    uint16_t session;
    uint16_t descriptor;
});

typedef struct sl_bt_cmd_gattdb_remove_descriptor_s sl_bt_cmd_gattdb_remove_descriptor_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_start_service_s
{
    uint16_t session;
    uint16_t service;
});

typedef struct sl_bt_cmd_gattdb_start_service_s sl_bt_cmd_gattdb_start_service_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_stop_service_s
{
    uint16_t session;
    uint16_t service;
});

typedef struct sl_bt_cmd_gattdb_stop_service_s sl_bt_cmd_gattdb_stop_service_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_start_characteristic_s
{
    uint16_t session;
    uint16_t characteristic;
});

typedef struct sl_bt_cmd_gattdb_start_characteristic_s sl_bt_cmd_gattdb_start_characteristic_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_stop_characteristic_s
{
    uint16_t session;
    uint16_t characteristic;
});

typedef struct sl_bt_cmd_gattdb_stop_characteristic_s sl_bt_cmd_gattdb_stop_characteristic_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_commit_s
{
    uint16_t session;
});

typedef struct sl_bt_cmd_gattdb_commit_s sl_bt_cmd_gattdb_commit_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_abort_s
{
    uint16_t session;
});

typedef struct sl_bt_cmd_gattdb_abort_s sl_bt_cmd_gattdb_abort_t;


PACKSTRUCT( struct sl_bt_cmd_gattdb_get_attribute_state_s
{
    uint16_t attribute;
});

typedef struct sl_bt_cmd_gattdb_get_attribute_state_s sl_bt_cmd_gattdb_get_attribute_state_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_set_max_mtu_s
{
    uint16_t max_mtu;
});

typedef struct sl_bt_cmd_gatt_server_set_max_mtu_s sl_bt_cmd_gatt_server_set_max_mtu_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_get_mtu_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_gatt_server_get_mtu_s sl_bt_cmd_gatt_server_get_mtu_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_find_attribute_s
{
    uint16_t start;
    uint8array type;
});

typedef struct sl_bt_cmd_gatt_server_find_attribute_s sl_bt_cmd_gatt_server_find_attribute_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_find_primary_service_s
{
    uint16_t start;
    uint8array uuid;
});

typedef struct sl_bt_cmd_gatt_server_find_primary_service_s sl_bt_cmd_gatt_server_find_primary_service_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_read_attribute_value_s
{
    uint16_t attribute;
    uint16_t offset;
});

typedef struct sl_bt_cmd_gatt_server_read_attribute_value_s sl_bt_cmd_gatt_server_read_attribute_value_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_read_attribute_type_s
{
    uint16_t attribute;
});

typedef struct sl_bt_cmd_gatt_server_read_attribute_type_s sl_bt_cmd_gatt_server_read_attribute_type_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_read_attribute_properties_s
{
    uint16_t attribute;
});

typedef struct sl_bt_cmd_gatt_server_read_attribute_properties_s sl_bt_cmd_gatt_server_read_attribute_properties_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_write_attribute_value_s
{
    uint16_t attribute;
    uint16_t offset;
    byte_array value;
});

typedef struct sl_bt_cmd_gatt_server_write_attribute_value_s sl_bt_cmd_gatt_server_write_attribute_value_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_send_user_read_response_s
{
    uint8_t connection;
    uint16_t characteristic;
    uint8_t att_errorcode;
    byte_array value;
});

typedef struct sl_bt_cmd_gatt_server_send_user_read_response_s sl_bt_cmd_gatt_server_send_user_read_response_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_send_user_write_response_s
{
    uint8_t connection;
    uint16_t characteristic;
    uint8_t att_errorcode;
});

typedef struct sl_bt_cmd_gatt_server_send_user_write_response_s sl_bt_cmd_gatt_server_send_user_write_response_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_send_notification_s
{
    uint8_t connection;
    uint16_t characteristic;
    byte_array value;
});

typedef struct sl_bt_cmd_gatt_server_send_notification_s sl_bt_cmd_gatt_server_send_notification_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_send_notification_with_options_s
{
    uint8_t connection;
    uint16_t characteristic;
    uint32_t options;
    byte_array value;
});

typedef struct sl_bt_cmd_gatt_server_send_notification_with_options_s sl_bt_cmd_gatt_server_send_notification_with_options_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_send_indication_s
{
    uint8_t connection;
    uint16_t characteristic;
    byte_array value;
});

typedef struct sl_bt_cmd_gatt_server_send_indication_s sl_bt_cmd_gatt_server_send_indication_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_send_indication_with_options_s
{
    uint8_t connection;
    uint16_t characteristic;
    uint32_t options;
    byte_array value;
});

typedef struct sl_bt_cmd_gatt_server_send_indication_with_options_s sl_bt_cmd_gatt_server_send_indication_with_options_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_notify_all_s
{
    uint16_t characteristic;
    byte_array value;
});

typedef struct sl_bt_cmd_gatt_server_notify_all_s sl_bt_cmd_gatt_server_notify_all_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_read_client_configuration_s
{
    uint8_t connection;
    uint16_t characteristic;
});

typedef struct sl_bt_cmd_gatt_server_read_client_configuration_s sl_bt_cmd_gatt_server_read_client_configuration_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_send_user_prepare_write_response_s
{
    uint8_t connection;
    uint16_t characteristic;
    uint8_t att_errorcode;
    uint16_t offset;
    byte_array value;
});

typedef struct sl_bt_cmd_gatt_server_send_user_prepare_write_response_s sl_bt_cmd_gatt_server_send_user_prepare_write_response_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_set_capabilities_s
{
    uint32_t caps;
    uint32_t reserved;
});

typedef struct sl_bt_cmd_gatt_server_set_capabilities_s sl_bt_cmd_gatt_server_set_capabilities_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_enable_capabilities_s
{
    uint32_t caps;
});

typedef struct sl_bt_cmd_gatt_server_enable_capabilities_s sl_bt_cmd_gatt_server_enable_capabilities_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_disable_capabilities_s
{
    uint32_t caps;
});

typedef struct sl_bt_cmd_gatt_server_disable_capabilities_s sl_bt_cmd_gatt_server_disable_capabilities_t;


PACKSTRUCT( struct sl_bt_cmd_gatt_server_read_client_supported_features_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_gatt_server_read_client_supported_features_s sl_bt_cmd_gatt_server_read_client_supported_features_t;


PACKSTRUCT( struct sl_bt_cmd_nvm_save_s
{
    uint16_t key;
    uint8array value;
});

typedef struct sl_bt_cmd_nvm_save_s sl_bt_cmd_nvm_save_t;


PACKSTRUCT( struct sl_bt_cmd_nvm_load_s
{
    uint16_t key;
});

typedef struct sl_bt_cmd_nvm_load_s sl_bt_cmd_nvm_load_t;


PACKSTRUCT( struct sl_bt_cmd_nvm_erase_s
{
    uint16_t key;
});

typedef struct sl_bt_cmd_nvm_erase_s sl_bt_cmd_nvm_erase_t;


PACKSTRUCT( struct sl_bt_cmd_test_dtm_tx_v4_s
{
    uint8_t packet_type;
    uint8_t length;
    uint8_t channel;
    uint8_t phy;
    int8_t power_level;
});

typedef struct sl_bt_cmd_test_dtm_tx_v4_s sl_bt_cmd_test_dtm_tx_v4_t;


PACKSTRUCT( struct sl_bt_cmd_test_dtm_tx_cw_s
{
    uint8_t packet_type;
    uint8_t channel;
    uint8_t phy;
    int16_t power_level;
});

typedef struct sl_bt_cmd_test_dtm_tx_cw_s sl_bt_cmd_test_dtm_tx_cw_t;


PACKSTRUCT( struct sl_bt_cmd_test_dtm_rx_s
{
    uint8_t channel;
    uint8_t phy;
});

typedef struct sl_bt_cmd_test_dtm_rx_s sl_bt_cmd_test_dtm_rx_t;


PACKSTRUCT( struct sl_bt_cmd_sm_configure_s
{
    uint8_t flags;
    uint8_t io_capabilities;
});

typedef struct sl_bt_cmd_sm_configure_s sl_bt_cmd_sm_configure_t;


PACKSTRUCT( struct sl_bt_cmd_sm_set_minimum_key_size_s
{
    uint8_t minimum_key_size;
});

typedef struct sl_bt_cmd_sm_set_minimum_key_size_s sl_bt_cmd_sm_set_minimum_key_size_t;


PACKSTRUCT( struct sl_bt_cmd_sm_store_bonding_configuration_s
{
    uint8_t max_bonding_count;
    uint8_t policy_flags;
});

typedef struct sl_bt_cmd_sm_store_bonding_configuration_s sl_bt_cmd_sm_store_bonding_configuration_t;


PACKSTRUCT( struct sl_bt_cmd_sm_set_bondable_mode_s
{
    uint8_t bondable;
});

typedef struct sl_bt_cmd_sm_set_bondable_mode_s sl_bt_cmd_sm_set_bondable_mode_t;


PACKSTRUCT( struct sl_bt_cmd_sm_set_passkey_s
{
    int32_t passkey;
});

typedef struct sl_bt_cmd_sm_set_passkey_s sl_bt_cmd_sm_set_passkey_t;


PACKSTRUCT( struct sl_bt_cmd_sm_increase_security_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_sm_increase_security_s sl_bt_cmd_sm_increase_security_t;


PACKSTRUCT( struct sl_bt_cmd_sm_enter_passkey_s
{
    uint8_t connection;
    int32_t passkey;
});

typedef struct sl_bt_cmd_sm_enter_passkey_s sl_bt_cmd_sm_enter_passkey_t;


PACKSTRUCT( struct sl_bt_cmd_sm_passkey_confirm_s
{
    uint8_t connection;
    uint8_t confirm;
});

typedef struct sl_bt_cmd_sm_passkey_confirm_s sl_bt_cmd_sm_passkey_confirm_t;


PACKSTRUCT( struct sl_bt_cmd_sm_bonding_confirm_s
{
    uint8_t connection;
    uint8_t confirm;
});

typedef struct sl_bt_cmd_sm_bonding_confirm_s sl_bt_cmd_sm_bonding_confirm_t;


PACKSTRUCT( struct sl_bt_cmd_sm_delete_bonding_s
{
    uint8_t bonding;
});

typedef struct sl_bt_cmd_sm_delete_bonding_s sl_bt_cmd_sm_delete_bonding_t;


PACKSTRUCT( struct sl_bt_cmd_sm_get_bonding_handles_s
{
    uint32_t reserved;
});

typedef struct sl_bt_cmd_sm_get_bonding_handles_s sl_bt_cmd_sm_get_bonding_handles_t;


PACKSTRUCT( struct sl_bt_cmd_sm_get_bonding_details_s
{
    uint32_t bonding;
});

typedef struct sl_bt_cmd_sm_get_bonding_details_s sl_bt_cmd_sm_get_bonding_details_t;


PACKSTRUCT( struct sl_bt_cmd_sm_find_bonding_by_address_s
{
    bd_addr address;
});

typedef struct sl_bt_cmd_sm_find_bonding_by_address_s sl_bt_cmd_sm_find_bonding_by_address_t;


PACKSTRUCT( struct sl_bt_cmd_sm_resolve_rpa_s
{
    bd_addr rpa;
});

typedef struct sl_bt_cmd_sm_resolve_rpa_s sl_bt_cmd_sm_resolve_rpa_t;


PACKSTRUCT( struct sl_bt_cmd_sm_set_bonding_key_s
{
    uint32_t bonding;
    uint8_t key_type;
    aes_key_128 key;
});

typedef struct sl_bt_cmd_sm_set_bonding_key_s sl_bt_cmd_sm_set_bonding_key_t;


PACKSTRUCT( struct sl_bt_cmd_sm_set_legacy_oob_s
{
    uint8_t enable;
    aes_key_128 oob_data;
});

typedef struct sl_bt_cmd_sm_set_legacy_oob_s sl_bt_cmd_sm_set_legacy_oob_t;


PACKSTRUCT( struct sl_bt_cmd_sm_set_oob_s
{
    uint8_t enable;
});

typedef struct sl_bt_cmd_sm_set_oob_s sl_bt_cmd_sm_set_oob_t;


PACKSTRUCT( struct sl_bt_cmd_sm_set_remote_oob_s
{
    uint8_t enable;
    aes_key_128 random;
    aes_key_128 confirm;
});

typedef struct sl_bt_cmd_sm_set_remote_oob_s sl_bt_cmd_sm_set_remote_oob_t;


PACKSTRUCT( struct sl_bt_cmd_external_bondingdb_set_data_s
{
    uint8_t connection;
    uint8_t type;
    uint8array data;
});

typedef struct sl_bt_cmd_external_bondingdb_set_data_s sl_bt_cmd_external_bondingdb_set_data_t;


PACKSTRUCT( struct sl_bt_cmd_external_bondingdb_set_local_irk_s
{
    uint8array irk;
});

typedef struct sl_bt_cmd_external_bondingdb_set_local_irk_s sl_bt_cmd_external_bondingdb_set_local_irk_t;


PACKSTRUCT( struct sl_bt_cmd_resolving_list_add_device_by_bonding_s
{
    uint32_t bonding;
    uint8_t privacy_mode;
});

typedef struct sl_bt_cmd_resolving_list_add_device_by_bonding_s sl_bt_cmd_resolving_list_add_device_by_bonding_t;


PACKSTRUCT( struct sl_bt_cmd_resolving_list_add_device_by_address_s
{
    bd_addr address;
    uint8_t address_type;
    aes_key_128 key;
    uint8_t privacy_mode;
});

typedef struct sl_bt_cmd_resolving_list_add_device_by_address_s sl_bt_cmd_resolving_list_add_device_by_address_t;


PACKSTRUCT( struct sl_bt_cmd_resolving_list_remove_device_by_bonding_s
{
    uint32_t bonding;
});

typedef struct sl_bt_cmd_resolving_list_remove_device_by_bonding_s sl_bt_cmd_resolving_list_remove_device_by_bonding_t;


PACKSTRUCT( struct sl_bt_cmd_resolving_list_remove_device_by_address_s
{
    bd_addr address;
    uint8_t address_type;
});

typedef struct sl_bt_cmd_resolving_list_remove_device_by_address_s sl_bt_cmd_resolving_list_remove_device_by_address_t;


PACKSTRUCT( struct sl_bt_cmd_accept_list_add_device_by_bonding_s
{
    uint32_t bonding;
});

typedef struct sl_bt_cmd_accept_list_add_device_by_bonding_s sl_bt_cmd_accept_list_add_device_by_bonding_t;


PACKSTRUCT( struct sl_bt_cmd_accept_list_add_device_by_address_s
{
    bd_addr address;
    uint8_t address_type;
});

typedef struct sl_bt_cmd_accept_list_add_device_by_address_s sl_bt_cmd_accept_list_add_device_by_address_t;


PACKSTRUCT( struct sl_bt_cmd_accept_list_remove_device_by_bonding_s
{
    uint32_t bonding;
});

typedef struct sl_bt_cmd_accept_list_remove_device_by_bonding_s sl_bt_cmd_accept_list_remove_device_by_bonding_t;


PACKSTRUCT( struct sl_bt_cmd_accept_list_remove_device_by_address_s
{
    bd_addr address;
    uint8_t address_type;
});

typedef struct sl_bt_cmd_accept_list_remove_device_by_address_s sl_bt_cmd_accept_list_remove_device_by_address_t;


PACKSTRUCT( struct sl_bt_cmd_coex_set_options_s
{
    uint32_t mask;
    uint32_t options;
});

typedef struct sl_bt_cmd_coex_set_options_s sl_bt_cmd_coex_set_options_t;


PACKSTRUCT( struct sl_bt_cmd_coex_set_parameters_s
{
    uint8_t priority;
    uint8_t request;
    uint8_t pwm_period;
    uint8_t pwm_dutycycle;
});

typedef struct sl_bt_cmd_coex_set_parameters_s sl_bt_cmd_coex_set_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_coex_set_directional_priority_pulse_s
{
    uint8_t pulse;
});

typedef struct sl_bt_cmd_coex_set_directional_priority_pulse_s sl_bt_cmd_coex_set_directional_priority_pulse_t;


PACKSTRUCT( struct sl_bt_cmd_coex_get_counters_s
{
    uint8_t reset;
});

typedef struct sl_bt_cmd_coex_get_counters_s sl_bt_cmd_coex_get_counters_t;


PACKSTRUCT( struct sl_bt_cmd_cs_security_enable_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_cs_security_enable_s sl_bt_cmd_cs_security_enable_t;


PACKSTRUCT( struct sl_bt_cmd_cs_set_default_settings_s
{
    uint8_t connection;
    uint8_t initiator_status;
    uint8_t reflector_status;
    uint8_t antenna_identifier;
    int8_t max_tx_power;
});

typedef struct sl_bt_cmd_cs_set_default_settings_s sl_bt_cmd_cs_set_default_settings_t;


PACKSTRUCT( struct sl_bt_cmd_cs_create_config_s
{
    uint8_t connection;
    uint8_t config_id;
    uint8_t create_context;
    uint8_t main_mode_type;
    uint8_t sub_mode_type;
    uint8_t min_main_mode_steps;
    uint8_t max_main_mode_steps;
    uint8_t main_mode_repetition;
    uint8_t mode_calibration_steps;
    uint8_t role;
    uint8_t rtt_type;
    uint8_t cs_sync_phy;
    sl_bt_cs_channel_map_t channel_map;
    uint8_t channel_map_repetition;
    uint8_t channel_selection_type;
    uint8_t ch3c_shape;
    uint8_t ch3c_jump;
    uint8_t reserved;
});

typedef struct sl_bt_cmd_cs_create_config_s sl_bt_cmd_cs_create_config_t;


PACKSTRUCT( struct sl_bt_cmd_cs_remove_config_s
{
    uint8_t connection;
    uint8_t config_id;
});

typedef struct sl_bt_cmd_cs_remove_config_s sl_bt_cmd_cs_remove_config_t;


PACKSTRUCT( struct sl_bt_cmd_cs_set_channel_classification_s
{
    sl_bt_cs_channel_map_t channel_map;
});

typedef struct sl_bt_cmd_cs_set_channel_classification_s sl_bt_cmd_cs_set_channel_classification_t;


PACKSTRUCT( struct sl_bt_cmd_cs_set_procedure_parameters_s
{
    uint8_t connection;
    uint8_t config_id;
    uint16_t max_procedure_len;
    uint16_t min_procedure_interval;
    uint16_t max_procedure_interval;
    uint16_t max_procedure_count;
    uint32_t min_subevent_len;
    uint32_t max_subevent_len;
    uint8_t tone_antenna_config_selection;
    uint8_t phy;
    int8_t tx_pwr_delta;
    uint8_t preferred_peer_antenna;
    uint8_t snr_control_initiator;
    uint8_t snr_control_reflector;
});

typedef struct sl_bt_cmd_cs_set_procedure_parameters_s sl_bt_cmd_cs_set_procedure_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_cs_procedure_enable_s
{
    uint8_t connection;
    uint8_t enable;
    uint8_t config_id;
});

typedef struct sl_bt_cmd_cs_procedure_enable_s sl_bt_cmd_cs_procedure_enable_t;


PACKSTRUCT( struct sl_bt_cmd_cs_set_antenna_configuration_s
{
    uint8array antenna_element_offset;
});

typedef struct sl_bt_cmd_cs_set_antenna_configuration_s sl_bt_cmd_cs_set_antenna_configuration_t;


PACKSTRUCT( struct sl_bt_cmd_cs_read_remote_supported_capabilities_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_cs_read_remote_supported_capabilities_s sl_bt_cmd_cs_read_remote_supported_capabilities_t;


PACKSTRUCT( struct sl_bt_cmd_cs_test_start_s
{
    uint8_t main_mode_type;
    uint8_t sub_mode_type;
    uint8_t main_mode_repetition;
    uint8_t mode_calibration_steps;
    uint8_t role;
    uint8_t rtt_type;
    uint8_t cs_sync_phy;
    uint8_t antenna_selection;
    sl_bt_cs_subevent_length_t subevent_len;
    uint16_t subevent_interval;
    uint8_t max_num_subevents;
    int8_t tx_power;
    uint8_t t_ip1_time;
    uint8_t t_ip2_time;
    uint8_t t_fcs_time;
    uint8_t t_pm_time;
    uint8_t t_sw_time;
    uint8_t tone_antenna_config;
    uint8_t reserved;
    uint8_t snr_control_initiator;
    uint8_t snr_control_reflector;
    uint16_t drbg_nonce;
    uint8_t channel_map_repetition;
    uint16_t override_config;
    uint8array override_parameters;
});

typedef struct sl_bt_cmd_cs_test_start_s sl_bt_cmd_cs_test_start_t;


PACKSTRUCT( struct sl_bt_cmd_l2cap_open_le_channel_s
{
    uint8_t connection;
    uint16_t spsm;
    uint16_t max_sdu;
    uint16_t max_pdu;
    uint16_t credit;
});

typedef struct sl_bt_cmd_l2cap_open_le_channel_s sl_bt_cmd_l2cap_open_le_channel_t;


PACKSTRUCT( struct sl_bt_cmd_l2cap_send_le_channel_open_response_s
{
    uint8_t connection;
    uint16_t cid;
    uint16_t max_sdu;
    uint16_t max_pdu;
    uint16_t credit;
    uint16_t errorcode;
});

typedef struct sl_bt_cmd_l2cap_send_le_channel_open_response_s sl_bt_cmd_l2cap_send_le_channel_open_response_t;


PACKSTRUCT( struct sl_bt_cmd_l2cap_channel_send_data_s
{
    uint8_t connection;
    uint16_t cid;
    uint8array data;
});

typedef struct sl_bt_cmd_l2cap_channel_send_data_s sl_bt_cmd_l2cap_channel_send_data_t;


PACKSTRUCT( struct sl_bt_cmd_l2cap_channel_send_credit_s
{
    uint8_t connection;
    uint16_t cid;
    uint16_t credit;
});

typedef struct sl_bt_cmd_l2cap_channel_send_credit_s sl_bt_cmd_l2cap_channel_send_credit_t;


PACKSTRUCT( struct sl_bt_cmd_l2cap_close_channel_s
{
    uint8_t connection;
    uint16_t cid;
});

typedef struct sl_bt_cmd_l2cap_close_channel_s sl_bt_cmd_l2cap_close_channel_t;


PACKSTRUCT( struct sl_bt_cmd_cte_transmitter_set_dtm_parameters_s
{
    uint8_t cte_length;
    uint8_t cte_type;
    uint8array switching_pattern;
});

typedef struct sl_bt_cmd_cte_transmitter_set_dtm_parameters_s sl_bt_cmd_cte_transmitter_set_dtm_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_cte_transmitter_enable_connection_cte_s
{
    uint8_t connection;
    uint8_t cte_types;
    uint8array switching_pattern;
});

typedef struct sl_bt_cmd_cte_transmitter_enable_connection_cte_s sl_bt_cmd_cte_transmitter_enable_connection_cte_t;


PACKSTRUCT( struct sl_bt_cmd_cte_transmitter_disable_connection_cte_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_cte_transmitter_disable_connection_cte_s sl_bt_cmd_cte_transmitter_disable_connection_cte_t;


PACKSTRUCT( struct sl_bt_cmd_cte_transmitter_enable_connectionless_cte_s
{
    uint8_t handle;
    uint8_t cte_length;
    uint8_t cte_type;
    uint8_t cte_count;
    uint8array switching_pattern;
});

typedef struct sl_bt_cmd_cte_transmitter_enable_connectionless_cte_s sl_bt_cmd_cte_transmitter_enable_connectionless_cte_t;


PACKSTRUCT( struct sl_bt_cmd_cte_transmitter_disable_connectionless_cte_s
{
    uint8_t handle;
});

typedef struct sl_bt_cmd_cte_transmitter_disable_connectionless_cte_s sl_bt_cmd_cte_transmitter_disable_connectionless_cte_t;


PACKSTRUCT( struct sl_bt_cmd_cte_transmitter_enable_silabs_cte_s
{
    uint8_t handle;
    uint8_t cte_length;
    uint8_t cte_type;
    uint8_t cte_count;
    uint8array switching_pattern;
});

typedef struct sl_bt_cmd_cte_transmitter_enable_silabs_cte_s sl_bt_cmd_cte_transmitter_enable_silabs_cte_t;


PACKSTRUCT( struct sl_bt_cmd_cte_transmitter_disable_silabs_cte_s
{
    uint8_t handle;
});

typedef struct sl_bt_cmd_cte_transmitter_disable_silabs_cte_s sl_bt_cmd_cte_transmitter_disable_silabs_cte_t;


PACKSTRUCT( struct sl_bt_cmd_cte_receiver_set_dtm_parameters_s
{
    uint8_t cte_length;
    uint8_t cte_type;
    uint8_t slot_durations;
    uint8array switching_pattern;
});

typedef struct sl_bt_cmd_cte_receiver_set_dtm_parameters_s sl_bt_cmd_cte_receiver_set_dtm_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_cte_receiver_set_sync_cte_type_s
{
    uint8_t sync_cte_type;
});

typedef struct sl_bt_cmd_cte_receiver_set_sync_cte_type_s sl_bt_cmd_cte_receiver_set_sync_cte_type_t;


PACKSTRUCT( struct sl_bt_cmd_cte_receiver_set_default_sync_receive_parameters_s
{
    uint8_t mode;
    uint16_t skip;
    uint16_t timeout;
    uint8_t sync_cte_type;
    uint8_t reporting_mode;
});

typedef struct sl_bt_cmd_cte_receiver_set_default_sync_receive_parameters_s sl_bt_cmd_cte_receiver_set_default_sync_receive_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_cte_receiver_set_sync_receive_parameters_s
{
    uint8_t connection;
    uint8_t mode;
    uint16_t skip;
    uint16_t timeout;
    uint8_t sync_cte_type;
    uint8_t reporting_mode;
});

typedef struct sl_bt_cmd_cte_receiver_set_sync_receive_parameters_s sl_bt_cmd_cte_receiver_set_sync_receive_parameters_t;


PACKSTRUCT( struct sl_bt_cmd_cte_receiver_configure_s
{
    uint8_t flags;
});

typedef struct sl_bt_cmd_cte_receiver_configure_s sl_bt_cmd_cte_receiver_configure_t;


PACKSTRUCT( struct sl_bt_cmd_cte_receiver_enable_connection_cte_s
{
    uint8_t connection;
    uint16_t interval;
    uint8_t cte_length;
    uint8_t cte_type;
    uint8_t slot_durations;
    uint8array switching_pattern;
});

typedef struct sl_bt_cmd_cte_receiver_enable_connection_cte_s sl_bt_cmd_cte_receiver_enable_connection_cte_t;


PACKSTRUCT( struct sl_bt_cmd_cte_receiver_disable_connection_cte_s
{
    uint8_t connection;
});

typedef struct sl_bt_cmd_cte_receiver_disable_connection_cte_s sl_bt_cmd_cte_receiver_disable_connection_cte_t;


PACKSTRUCT( struct sl_bt_cmd_cte_receiver_enable_connectionless_cte_s
{
    uint16_t sync;
    uint8_t slot_durations;
    uint8_t cte_count;
    uint8array switching_pattern;
});

typedef struct sl_bt_cmd_cte_receiver_enable_connectionless_cte_s sl_bt_cmd_cte_receiver_enable_connectionless_cte_t;


PACKSTRUCT( struct sl_bt_cmd_cte_receiver_disable_connectionless_cte_s
{
    uint16_t sync;
});

typedef struct sl_bt_cmd_cte_receiver_disable_connectionless_cte_s sl_bt_cmd_cte_receiver_disable_connectionless_cte_t;


PACKSTRUCT( struct sl_bt_cmd_cte_receiver_enable_silabs_cte_s
{
    uint8_t slot_durations;
    uint8_t cte_count;
    uint8array switching_pattern;
});

typedef struct sl_bt_cmd_cte_receiver_enable_silabs_cte_s sl_bt_cmd_cte_receiver_enable_silabs_cte_t;


PACKSTRUCT( struct sl_bt_cmd_connection_analyzer_start_s
{
    uint32_t access_address;
    uint32_t crc_init;
    uint16_t interval;
    uint16_t supervision_timeout;
    uint8_t central_clock_accuracy;
    uint8_t central_phy;
    uint8_t peripheral_phy;
    uint8_t channel_selection_algorithm;
    uint8_t hop;
    sl_bt_connection_channel_map_t channel_map;
    uint8_t channel;
    uint16_t event_counter;
    int32_t start_time_us;
    uint32_t flags;
});

typedef struct sl_bt_cmd_connection_analyzer_start_s sl_bt_cmd_connection_analyzer_start_t;


PACKSTRUCT( struct sl_bt_cmd_connection_analyzer_stop_s
{
    uint8_t analyzer;
});

typedef struct sl_bt_cmd_connection_analyzer_stop_s sl_bt_cmd_connection_analyzer_stop_t;


PACKSTRUCT( struct sl_bt_cmd_user_message_to_target_s
{
    uint8array data;
});

typedef struct sl_bt_cmd_user_message_to_target_s sl_bt_cmd_user_message_to_target_t;


PACKSTRUCT( struct sl_bt_cmd_user_manage_event_filter_s
{
    uint8array data;
});

typedef struct sl_bt_cmd_user_manage_event_filter_s sl_bt_cmd_user_manage_event_filter_t;


PACKSTRUCT( struct sl_bt_cmd_user_cs_service_message_to_target_s
{
    uint8array data;
});

typedef struct sl_bt_cmd_user_cs_service_message_to_target_s sl_bt_cmd_user_cs_service_message_to_target_t;




PACKSTRUCT( struct sl_bt_rsp_dfu_flash_set_address_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_dfu_flash_set_address_s sl_bt_rsp_dfu_flash_set_address_t;


PACKSTRUCT( struct sl_bt_rsp_dfu_flash_upload_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_dfu_flash_upload_s sl_bt_rsp_dfu_flash_upload_t;


PACKSTRUCT( struct sl_bt_rsp_dfu_flash_upload_finish_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_dfu_flash_upload_finish_s sl_bt_rsp_dfu_flash_upload_finish_t;


PACKSTRUCT( struct sl_bt_rsp_system_hello_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_system_hello_s sl_bt_rsp_system_hello_t;


PACKSTRUCT( struct sl_bt_rsp_system_start_bluetooth_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_system_start_bluetooth_s sl_bt_rsp_system_start_bluetooth_t;


PACKSTRUCT( struct sl_bt_rsp_system_stop_bluetooth_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_system_stop_bluetooth_s sl_bt_rsp_system_stop_bluetooth_t;


PACKSTRUCT( struct sl_bt_rsp_system_forcefully_stop_bluetooth_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_system_forcefully_stop_bluetooth_s sl_bt_rsp_system_forcefully_stop_bluetooth_t;


PACKSTRUCT( struct sl_bt_rsp_system_get_version_s
{
    uint16_t result;
    uint16_t major;
    uint16_t minor;
    uint16_t patch;
    uint16_t build;
    uint32_t bootloader;
    uint32_t hash;
});

typedef struct sl_bt_rsp_system_get_version_s sl_bt_rsp_system_get_version_t;


PACKSTRUCT( struct sl_bt_rsp_system_halt_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_system_halt_s sl_bt_rsp_system_halt_t;


PACKSTRUCT( struct sl_bt_rsp_system_linklayer_configure_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_system_linklayer_configure_s sl_bt_rsp_system_linklayer_configure_t;


PACKSTRUCT( struct sl_bt_rsp_system_set_tx_power_s
{
    uint16_t result;
    int16_t set_min;
    int16_t set_max;
});

typedef struct sl_bt_rsp_system_set_tx_power_s sl_bt_rsp_system_set_tx_power_t;


PACKSTRUCT( struct sl_bt_rsp_system_get_tx_power_setting_s
{
    uint16_t result;
    int16_t support_min;
    int16_t support_max;
    int16_t set_min;
    int16_t set_max;
    int16_t rf_path_gain;
});

typedef struct sl_bt_rsp_system_get_tx_power_setting_s sl_bt_rsp_system_get_tx_power_setting_t;


PACKSTRUCT( struct sl_bt_rsp_system_set_identity_address_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_system_set_identity_address_s sl_bt_rsp_system_set_identity_address_t;


PACKSTRUCT( struct sl_bt_rsp_system_get_identity_address_s
{
    uint16_t result;
    bd_addr address;
    uint8_t type;
});

typedef struct sl_bt_rsp_system_get_identity_address_s sl_bt_rsp_system_get_identity_address_t;


PACKSTRUCT( struct sl_bt_rsp_system_get_random_data_s
{
    uint16_t result;
    uint8array data;
});

typedef struct sl_bt_rsp_system_get_random_data_s sl_bt_rsp_system_get_random_data_t;


PACKSTRUCT( struct sl_bt_rsp_system_data_buffer_write_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_system_data_buffer_write_s sl_bt_rsp_system_data_buffer_write_t;


PACKSTRUCT( struct sl_bt_rsp_system_data_buffer_clear_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_system_data_buffer_clear_s sl_bt_rsp_system_data_buffer_clear_t;


PACKSTRUCT( struct sl_bt_rsp_system_get_counters_s
{
    uint16_t result;
    uint16_t tx_packets;
    uint16_t rx_packets;
    uint16_t crc_errors;
    uint16_t failures;
});

typedef struct sl_bt_rsp_system_get_counters_s sl_bt_rsp_system_get_counters_t;


PACKSTRUCT( struct sl_bt_rsp_system_set_lazy_soft_timer_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_system_set_lazy_soft_timer_s sl_bt_rsp_system_set_lazy_soft_timer_t;


PACKSTRUCT( struct sl_bt_rsp_resource_get_status_s
{
    uint16_t result;
    uint32_t total_bytes;
    uint32_t free_bytes;
});

typedef struct sl_bt_rsp_resource_get_status_s sl_bt_rsp_resource_get_status_t;


PACKSTRUCT( struct sl_bt_rsp_resource_set_report_threshold_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_resource_set_report_threshold_s sl_bt_rsp_resource_set_report_threshold_t;


PACKSTRUCT( struct sl_bt_rsp_resource_enable_connection_tx_report_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_resource_enable_connection_tx_report_s sl_bt_rsp_resource_enable_connection_tx_report_t;


PACKSTRUCT( struct sl_bt_rsp_resource_get_connection_tx_status_s
{
    uint16_t result;
    uint16_t flags;
    uint16_t packet_count;
    uint32_t data_len;
});

typedef struct sl_bt_rsp_resource_get_connection_tx_status_s sl_bt_rsp_resource_get_connection_tx_status_t;


PACKSTRUCT( struct sl_bt_rsp_resource_disable_connection_tx_report_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_resource_disable_connection_tx_report_s sl_bt_rsp_resource_disable_connection_tx_report_t;


PACKSTRUCT( struct sl_bt_rsp_gap_set_privacy_mode_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gap_set_privacy_mode_s sl_bt_rsp_gap_set_privacy_mode_t;


PACKSTRUCT( struct sl_bt_rsp_gap_set_data_channel_classification_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gap_set_data_channel_classification_s sl_bt_rsp_gap_set_data_channel_classification_t;


PACKSTRUCT( struct sl_bt_rsp_gap_set_identity_address_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gap_set_identity_address_s sl_bt_rsp_gap_set_identity_address_t;


PACKSTRUCT( struct sl_bt_rsp_gap_get_identity_address_s
{
    uint16_t result;
    bd_addr address;
    uint8_t type;
});

typedef struct sl_bt_rsp_gap_get_identity_address_s sl_bt_rsp_gap_get_identity_address_t;


PACKSTRUCT( struct sl_bt_rsp_advertiser_create_set_s
{
    uint16_t result;
    uint8_t handle;
});

typedef struct sl_bt_rsp_advertiser_create_set_s sl_bt_rsp_advertiser_create_set_t;


PACKSTRUCT( struct sl_bt_rsp_advertiser_configure_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_advertiser_configure_s sl_bt_rsp_advertiser_configure_t;


PACKSTRUCT( struct sl_bt_rsp_advertiser_set_timing_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_advertiser_set_timing_s sl_bt_rsp_advertiser_set_timing_t;


PACKSTRUCT( struct sl_bt_rsp_advertiser_set_channel_map_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_advertiser_set_channel_map_s sl_bt_rsp_advertiser_set_channel_map_t;


PACKSTRUCT( struct sl_bt_rsp_advertiser_set_tx_power_s
{
    uint16_t result;
    int16_t set_power;
});

typedef struct sl_bt_rsp_advertiser_set_tx_power_s sl_bt_rsp_advertiser_set_tx_power_t;


PACKSTRUCT( struct sl_bt_rsp_advertiser_set_report_scan_request_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_advertiser_set_report_scan_request_s sl_bt_rsp_advertiser_set_report_scan_request_t;


PACKSTRUCT( struct sl_bt_rsp_advertiser_set_random_address_s
{
    uint16_t result;
    bd_addr address_out;
});

typedef struct sl_bt_rsp_advertiser_set_random_address_s sl_bt_rsp_advertiser_set_random_address_t;


PACKSTRUCT( struct sl_bt_rsp_advertiser_clear_random_address_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_advertiser_clear_random_address_s sl_bt_rsp_advertiser_clear_random_address_t;


PACKSTRUCT( struct sl_bt_rsp_advertiser_stop_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_advertiser_stop_s sl_bt_rsp_advertiser_stop_t;


PACKSTRUCT( struct sl_bt_rsp_advertiser_delete_set_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_advertiser_delete_set_s sl_bt_rsp_advertiser_delete_set_t;


PACKSTRUCT( struct sl_bt_rsp_legacy_advertiser_set_data_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_legacy_advertiser_set_data_s sl_bt_rsp_legacy_advertiser_set_data_t;


PACKSTRUCT( struct sl_bt_rsp_legacy_advertiser_generate_data_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_legacy_advertiser_generate_data_s sl_bt_rsp_legacy_advertiser_generate_data_t;


PACKSTRUCT( struct sl_bt_rsp_legacy_advertiser_start_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_legacy_advertiser_start_s sl_bt_rsp_legacy_advertiser_start_t;


PACKSTRUCT( struct sl_bt_rsp_legacy_advertiser_start_directed_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_legacy_advertiser_start_directed_s sl_bt_rsp_legacy_advertiser_start_directed_t;


PACKSTRUCT( struct sl_bt_rsp_extended_advertiser_set_phy_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_extended_advertiser_set_phy_s sl_bt_rsp_extended_advertiser_set_phy_t;


PACKSTRUCT( struct sl_bt_rsp_extended_advertiser_set_data_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_extended_advertiser_set_data_s sl_bt_rsp_extended_advertiser_set_data_t;


PACKSTRUCT( struct sl_bt_rsp_extended_advertiser_set_long_data_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_extended_advertiser_set_long_data_s sl_bt_rsp_extended_advertiser_set_long_data_t;


PACKSTRUCT( struct sl_bt_rsp_extended_advertiser_generate_data_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_extended_advertiser_generate_data_s sl_bt_rsp_extended_advertiser_generate_data_t;


PACKSTRUCT( struct sl_bt_rsp_extended_advertiser_start_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_extended_advertiser_start_s sl_bt_rsp_extended_advertiser_start_t;


PACKSTRUCT( struct sl_bt_rsp_extended_advertiser_start_directed_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_extended_advertiser_start_directed_s sl_bt_rsp_extended_advertiser_start_directed_t;


PACKSTRUCT( struct sl_bt_rsp_periodic_advertiser_set_data_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_periodic_advertiser_set_data_s sl_bt_rsp_periodic_advertiser_set_data_t;


PACKSTRUCT( struct sl_bt_rsp_periodic_advertiser_set_long_data_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_periodic_advertiser_set_long_data_s sl_bt_rsp_periodic_advertiser_set_long_data_t;


PACKSTRUCT( struct sl_bt_rsp_periodic_advertiser_start_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_periodic_advertiser_start_s sl_bt_rsp_periodic_advertiser_start_t;


PACKSTRUCT( struct sl_bt_rsp_periodic_advertiser_stop_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_periodic_advertiser_stop_s sl_bt_rsp_periodic_advertiser_stop_t;


PACKSTRUCT( struct sl_bt_rsp_scanner_set_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_scanner_set_parameters_s sl_bt_rsp_scanner_set_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_scanner_set_parameters_and_filter_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_scanner_set_parameters_and_filter_s sl_bt_rsp_scanner_set_parameters_and_filter_t;


PACKSTRUCT( struct sl_bt_rsp_scanner_start_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_scanner_start_s sl_bt_rsp_scanner_start_t;


PACKSTRUCT( struct sl_bt_rsp_scanner_stop_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_scanner_stop_s sl_bt_rsp_scanner_stop_t;


PACKSTRUCT( struct sl_bt_rsp_sync_set_reporting_mode_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sync_set_reporting_mode_s sl_bt_rsp_sync_set_reporting_mode_t;


PACKSTRUCT( struct sl_bt_rsp_sync_update_sync_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sync_update_sync_parameters_s sl_bt_rsp_sync_update_sync_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_sync_close_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sync_close_s sl_bt_rsp_sync_close_t;


PACKSTRUCT( struct sl_bt_rsp_sync_scanner_set_sync_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sync_scanner_set_sync_parameters_s sl_bt_rsp_sync_scanner_set_sync_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_sync_scanner_open_s
{
    uint16_t result;
    uint16_t sync;
});

typedef struct sl_bt_rsp_sync_scanner_open_s sl_bt_rsp_sync_scanner_open_t;


PACKSTRUCT( struct sl_bt_rsp_past_receiver_set_default_sync_receive_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_past_receiver_set_default_sync_receive_parameters_s sl_bt_rsp_past_receiver_set_default_sync_receive_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_past_receiver_set_sync_receive_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_past_receiver_set_sync_receive_parameters_s sl_bt_rsp_past_receiver_set_sync_receive_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_past_receiver_set_default_sync_receive_over_sync_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_past_receiver_set_default_sync_receive_over_sync_parameters_s sl_bt_rsp_past_receiver_set_default_sync_receive_over_sync_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_past_receiver_set_sync_receive_over_sync_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_past_receiver_set_sync_receive_over_sync_parameters_s sl_bt_rsp_past_receiver_set_sync_receive_over_sync_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_advertiser_past_transfer_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_advertiser_past_transfer_s sl_bt_rsp_advertiser_past_transfer_t;


PACKSTRUCT( struct sl_bt_rsp_advertiser_past_transfer_over_pawr_advertiser_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_advertiser_past_transfer_over_pawr_advertiser_s sl_bt_rsp_advertiser_past_transfer_over_pawr_advertiser_t;


PACKSTRUCT( struct sl_bt_rsp_sync_past_transfer_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sync_past_transfer_s sl_bt_rsp_sync_past_transfer_t;


PACKSTRUCT( struct sl_bt_rsp_pawr_sync_set_sync_subevents_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_pawr_sync_set_sync_subevents_s sl_bt_rsp_pawr_sync_set_sync_subevents_t;


PACKSTRUCT( struct sl_bt_rsp_pawr_sync_set_response_data_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_pawr_sync_set_response_data_s sl_bt_rsp_pawr_sync_set_response_data_t;


PACKSTRUCT( struct sl_bt_rsp_pawr_advertiser_start_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_pawr_advertiser_start_s sl_bt_rsp_pawr_advertiser_start_t;


PACKSTRUCT( struct sl_bt_rsp_pawr_advertiser_change_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_pawr_advertiser_change_parameters_s sl_bt_rsp_pawr_advertiser_change_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_pawr_advertiser_set_subevent_data_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_pawr_advertiser_set_subevent_data_s sl_bt_rsp_pawr_advertiser_set_subevent_data_t;


PACKSTRUCT( struct sl_bt_rsp_pawr_advertiser_create_connection_s
{
    uint16_t result;
    uint8_t connection;
});

typedef struct sl_bt_rsp_pawr_advertiser_create_connection_s sl_bt_rsp_pawr_advertiser_create_connection_t;


PACKSTRUCT( struct sl_bt_rsp_pawr_advertiser_stop_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_pawr_advertiser_stop_s sl_bt_rsp_pawr_advertiser_stop_t;


PACKSTRUCT( struct sl_bt_rsp_connection_set_default_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_set_default_parameters_s sl_bt_rsp_connection_set_default_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_connection_set_default_preferred_phy_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_set_default_preferred_phy_s sl_bt_rsp_connection_set_default_preferred_phy_t;


PACKSTRUCT( struct sl_bt_rsp_connection_set_default_data_length_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_set_default_data_length_s sl_bt_rsp_connection_set_default_data_length_t;


PACKSTRUCT( struct sl_bt_rsp_connection_set_default_acceptable_subrate_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_set_default_acceptable_subrate_s sl_bt_rsp_connection_set_default_acceptable_subrate_t;


PACKSTRUCT( struct sl_bt_rsp_connection_open_s
{
    uint16_t result;
    uint8_t connection;
});

typedef struct sl_bt_rsp_connection_open_s sl_bt_rsp_connection_open_t;


PACKSTRUCT( struct sl_bt_rsp_connection_open_with_accept_list_s
{
    uint16_t result;
    uint8_t connection;
});

typedef struct sl_bt_rsp_connection_open_with_accept_list_s sl_bt_rsp_connection_open_with_accept_list_t;


PACKSTRUCT( struct sl_bt_rsp_connection_set_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_set_parameters_s sl_bt_rsp_connection_set_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_connection_set_preferred_phy_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_set_preferred_phy_s sl_bt_rsp_connection_set_preferred_phy_t;


PACKSTRUCT( struct sl_bt_rsp_connection_disable_slave_latency_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_disable_slave_latency_s sl_bt_rsp_connection_disable_slave_latency_t;


PACKSTRUCT( struct sl_bt_rsp_connection_get_median_rssi_s
{
    uint16_t result;
    int8_t rssi;
});

typedef struct sl_bt_rsp_connection_get_median_rssi_s sl_bt_rsp_connection_get_median_rssi_t;


PACKSTRUCT( struct sl_bt_rsp_connection_read_channel_map_s
{
    uint16_t result;
    uint8array channel_map;
});

typedef struct sl_bt_rsp_connection_read_channel_map_s sl_bt_rsp_connection_read_channel_map_t;


PACKSTRUCT( struct sl_bt_rsp_connection_set_power_reporting_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_set_power_reporting_s sl_bt_rsp_connection_set_power_reporting_t;


PACKSTRUCT( struct sl_bt_rsp_connection_set_remote_power_reporting_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_set_remote_power_reporting_s sl_bt_rsp_connection_set_remote_power_reporting_t;


PACKSTRUCT( struct sl_bt_rsp_connection_get_tx_power_s
{
    uint16_t result;
    int8_t current_level;
    int8_t max_level;
});

typedef struct sl_bt_rsp_connection_get_tx_power_s sl_bt_rsp_connection_get_tx_power_t;


PACKSTRUCT( struct sl_bt_rsp_connection_get_remote_tx_power_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_get_remote_tx_power_s sl_bt_rsp_connection_get_remote_tx_power_t;


PACKSTRUCT( struct sl_bt_rsp_connection_set_tx_power_s
{
    uint16_t result;
    int16_t tx_power_out;
});

typedef struct sl_bt_rsp_connection_set_tx_power_s sl_bt_rsp_connection_set_tx_power_t;


PACKSTRUCT( struct sl_bt_rsp_connection_read_remote_used_features_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_read_remote_used_features_s sl_bt_rsp_connection_read_remote_used_features_t;


PACKSTRUCT( struct sl_bt_rsp_connection_get_security_status_s
{
    uint16_t result;
    uint8_t security_mode;
    uint8_t key_size;
    uint8_t bonding_handle;
});

typedef struct sl_bt_rsp_connection_get_security_status_s sl_bt_rsp_connection_get_security_status_t;


PACKSTRUCT( struct sl_bt_rsp_connection_set_data_length_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_set_data_length_s sl_bt_rsp_connection_set_data_length_t;


PACKSTRUCT( struct sl_bt_rsp_connection_read_statistics_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_read_statistics_s sl_bt_rsp_connection_read_statistics_t;


PACKSTRUCT( struct sl_bt_rsp_connection_get_scheduling_details_s
{
    uint16_t result;
    uint32_t access_address;
    uint8_t role;
    uint32_t crc_init;
    uint16_t interval;
    uint16_t supervision_timeout;
    uint8_t central_clock_accuracy;
    uint8_t central_phy;
    uint8_t peripheral_phy;
    uint8_t channel_selection_algorithm;
    uint8_t hop;
    sl_bt_connection_channel_map_t channel_map;
    uint8_t channel;
    uint16_t event_counter;
    uint32_t start_time_us;
});

typedef struct sl_bt_rsp_connection_get_scheduling_details_s sl_bt_rsp_connection_get_scheduling_details_t;


PACKSTRUCT( struct sl_bt_rsp_connection_get_remote_address_s
{
    uint16_t result;
    bd_addr address;
    uint8_t address_type;
});

typedef struct sl_bt_rsp_connection_get_remote_address_s sl_bt_rsp_connection_get_remote_address_t;


PACKSTRUCT( struct sl_bt_rsp_connection_request_subrate_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_request_subrate_s sl_bt_rsp_connection_request_subrate_t;


PACKSTRUCT( struct sl_bt_rsp_connection_get_state_s
{
    uint16_t result;
    uint8_t state;
});

typedef struct sl_bt_rsp_connection_get_state_s sl_bt_rsp_connection_get_state_t;


PACKSTRUCT( struct sl_bt_rsp_connection_close_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_close_s sl_bt_rsp_connection_close_t;


PACKSTRUCT( struct sl_bt_rsp_connection_forcefully_close_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_forcefully_close_s sl_bt_rsp_connection_forcefully_close_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_set_max_mtu_s
{
    uint16_t result;
    uint16_t max_mtu_out;
});

typedef struct sl_bt_rsp_gatt_set_max_mtu_s sl_bt_rsp_gatt_set_max_mtu_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_discover_primary_services_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_discover_primary_services_s sl_bt_rsp_gatt_discover_primary_services_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_discover_primary_services_by_uuid_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_discover_primary_services_by_uuid_s sl_bt_rsp_gatt_discover_primary_services_by_uuid_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_find_included_services_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_find_included_services_s sl_bt_rsp_gatt_find_included_services_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_discover_characteristics_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_discover_characteristics_s sl_bt_rsp_gatt_discover_characteristics_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_discover_characteristics_by_uuid_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_discover_characteristics_by_uuid_s sl_bt_rsp_gatt_discover_characteristics_by_uuid_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_discover_descriptors_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_discover_descriptors_s sl_bt_rsp_gatt_discover_descriptors_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_discover_characteristic_descriptors_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_discover_characteristic_descriptors_s sl_bt_rsp_gatt_discover_characteristic_descriptors_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_set_characteristic_notification_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_set_characteristic_notification_s sl_bt_rsp_gatt_set_characteristic_notification_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_send_characteristic_confirmation_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_send_characteristic_confirmation_s sl_bt_rsp_gatt_send_characteristic_confirmation_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_read_characteristic_value_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_read_characteristic_value_s sl_bt_rsp_gatt_read_characteristic_value_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_read_characteristic_value_from_offset_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_read_characteristic_value_from_offset_s sl_bt_rsp_gatt_read_characteristic_value_from_offset_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_read_multiple_characteristic_values_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_read_multiple_characteristic_values_s sl_bt_rsp_gatt_read_multiple_characteristic_values_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_read_variable_length_characteristic_values_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_read_variable_length_characteristic_values_s sl_bt_rsp_gatt_read_variable_length_characteristic_values_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_read_characteristic_value_by_uuid_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_read_characteristic_value_by_uuid_s sl_bt_rsp_gatt_read_characteristic_value_by_uuid_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_write_characteristic_value_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_write_characteristic_value_s sl_bt_rsp_gatt_write_characteristic_value_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_write_characteristic_value_without_response_s
{
    uint16_t result;
    uint16_t sent_len;
});

typedef struct sl_bt_rsp_gatt_write_characteristic_value_without_response_s sl_bt_rsp_gatt_write_characteristic_value_without_response_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_prepare_characteristic_value_write_s
{
    uint16_t result;
    uint16_t sent_len;
});

typedef struct sl_bt_rsp_gatt_prepare_characteristic_value_write_s sl_bt_rsp_gatt_prepare_characteristic_value_write_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_prepare_characteristic_value_reliable_write_s
{
    uint16_t result;
    uint16_t sent_len;
});

typedef struct sl_bt_rsp_gatt_prepare_characteristic_value_reliable_write_s sl_bt_rsp_gatt_prepare_characteristic_value_reliable_write_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_execute_characteristic_value_write_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_execute_characteristic_value_write_s sl_bt_rsp_gatt_execute_characteristic_value_write_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_read_descriptor_value_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_read_descriptor_value_s sl_bt_rsp_gatt_read_descriptor_value_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_write_descriptor_value_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_write_descriptor_value_s sl_bt_rsp_gatt_write_descriptor_value_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_get_mtu_s
{
    uint16_t result;
    uint16_t mtu;
});

typedef struct sl_bt_rsp_gatt_get_mtu_s sl_bt_rsp_gatt_get_mtu_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_new_session_s
{
    uint16_t result;
    uint16_t session;
});

typedef struct sl_bt_rsp_gattdb_new_session_s sl_bt_rsp_gattdb_new_session_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_add_service_s
{
    uint16_t result;
    uint16_t service;
});

typedef struct sl_bt_rsp_gattdb_add_service_s sl_bt_rsp_gattdb_add_service_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_remove_service_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gattdb_remove_service_s sl_bt_rsp_gattdb_remove_service_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_add_included_service_s
{
    uint16_t result;
    uint16_t attribute;
});

typedef struct sl_bt_rsp_gattdb_add_included_service_s sl_bt_rsp_gattdb_add_included_service_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_remove_included_service_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gattdb_remove_included_service_s sl_bt_rsp_gattdb_remove_included_service_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_add_uuid16_characteristic_s
{
    uint16_t result;
    uint16_t characteristic;
});

typedef struct sl_bt_rsp_gattdb_add_uuid16_characteristic_s sl_bt_rsp_gattdb_add_uuid16_characteristic_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_add_uuid128_characteristic_s
{
    uint16_t result;
    uint16_t characteristic;
});

typedef struct sl_bt_rsp_gattdb_add_uuid128_characteristic_s sl_bt_rsp_gattdb_add_uuid128_characteristic_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_remove_characteristic_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gattdb_remove_characteristic_s sl_bt_rsp_gattdb_remove_characteristic_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_add_uuid16_descriptor_s
{
    uint16_t result;
    uint16_t descriptor;
});

typedef struct sl_bt_rsp_gattdb_add_uuid16_descriptor_s sl_bt_rsp_gattdb_add_uuid16_descriptor_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_add_uuid128_descriptor_s
{
    uint16_t result;
    uint16_t descriptor;
});

typedef struct sl_bt_rsp_gattdb_add_uuid128_descriptor_s sl_bt_rsp_gattdb_add_uuid128_descriptor_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_remove_descriptor_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gattdb_remove_descriptor_s sl_bt_rsp_gattdb_remove_descriptor_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_start_service_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gattdb_start_service_s sl_bt_rsp_gattdb_start_service_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_stop_service_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gattdb_stop_service_s sl_bt_rsp_gattdb_stop_service_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_start_characteristic_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gattdb_start_characteristic_s sl_bt_rsp_gattdb_start_characteristic_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_stop_characteristic_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gattdb_stop_characteristic_s sl_bt_rsp_gattdb_stop_characteristic_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_commit_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gattdb_commit_s sl_bt_rsp_gattdb_commit_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_abort_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gattdb_abort_s sl_bt_rsp_gattdb_abort_t;


PACKSTRUCT( struct sl_bt_rsp_gattdb_get_attribute_state_s
{
    uint16_t result;
    uint8_t state;
});

typedef struct sl_bt_rsp_gattdb_get_attribute_state_s sl_bt_rsp_gattdb_get_attribute_state_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_set_max_mtu_s
{
    uint16_t result;
    uint16_t max_mtu_out;
});

typedef struct sl_bt_rsp_gatt_server_set_max_mtu_s sl_bt_rsp_gatt_server_set_max_mtu_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_get_mtu_s
{
    uint16_t result;
    uint16_t mtu;
});

typedef struct sl_bt_rsp_gatt_server_get_mtu_s sl_bt_rsp_gatt_server_get_mtu_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_find_attribute_s
{
    uint16_t result;
    uint16_t attribute;
});

typedef struct sl_bt_rsp_gatt_server_find_attribute_s sl_bt_rsp_gatt_server_find_attribute_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_find_primary_service_s
{
    uint16_t result;
    uint16_t start_out;
    uint16_t end_out;
});

typedef struct sl_bt_rsp_gatt_server_find_primary_service_s sl_bt_rsp_gatt_server_find_primary_service_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_read_attribute_value_s
{
    uint16_t result;
    byte_array value;
});

typedef struct sl_bt_rsp_gatt_server_read_attribute_value_s sl_bt_rsp_gatt_server_read_attribute_value_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_read_attribute_type_s
{
    uint16_t result;
    uint8array type;
});

typedef struct sl_bt_rsp_gatt_server_read_attribute_type_s sl_bt_rsp_gatt_server_read_attribute_type_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_read_attribute_properties_s
{
    uint16_t result;
    uint8_t category;
    uint16_t security;
    uint16_t properties;
    uint8_t value_type;
    uint16_t len;
    uint16_t max_writable_len;
});

typedef struct sl_bt_rsp_gatt_server_read_attribute_properties_s sl_bt_rsp_gatt_server_read_attribute_properties_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_write_attribute_value_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_server_write_attribute_value_s sl_bt_rsp_gatt_server_write_attribute_value_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_send_user_read_response_s
{
    uint16_t result;
    uint16_t sent_len;
});

typedef struct sl_bt_rsp_gatt_server_send_user_read_response_s sl_bt_rsp_gatt_server_send_user_read_response_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_send_user_write_response_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_server_send_user_write_response_s sl_bt_rsp_gatt_server_send_user_write_response_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_send_notification_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_server_send_notification_s sl_bt_rsp_gatt_server_send_notification_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_send_notification_with_options_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_server_send_notification_with_options_s sl_bt_rsp_gatt_server_send_notification_with_options_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_send_indication_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_server_send_indication_s sl_bt_rsp_gatt_server_send_indication_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_send_indication_with_options_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_server_send_indication_with_options_s sl_bt_rsp_gatt_server_send_indication_with_options_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_notify_all_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_server_notify_all_s sl_bt_rsp_gatt_server_notify_all_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_read_client_configuration_s
{
    uint16_t result;
    uint16_t client_config_flags;
});

typedef struct sl_bt_rsp_gatt_server_read_client_configuration_s sl_bt_rsp_gatt_server_read_client_configuration_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_send_user_prepare_write_response_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_server_send_user_prepare_write_response_s sl_bt_rsp_gatt_server_send_user_prepare_write_response_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_set_capabilities_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_server_set_capabilities_s sl_bt_rsp_gatt_server_set_capabilities_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_enable_capabilities_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_server_enable_capabilities_s sl_bt_rsp_gatt_server_enable_capabilities_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_disable_capabilities_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_gatt_server_disable_capabilities_s sl_bt_rsp_gatt_server_disable_capabilities_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_get_enabled_capabilities_s
{
    uint16_t result;
    uint32_t caps;
});

typedef struct sl_bt_rsp_gatt_server_get_enabled_capabilities_s sl_bt_rsp_gatt_server_get_enabled_capabilities_t;


PACKSTRUCT( struct sl_bt_rsp_gatt_server_read_client_supported_features_s
{
    uint16_t result;
    uint8_t client_features;
});

typedef struct sl_bt_rsp_gatt_server_read_client_supported_features_s sl_bt_rsp_gatt_server_read_client_supported_features_t;


PACKSTRUCT( struct sl_bt_rsp_nvm_save_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_nvm_save_s sl_bt_rsp_nvm_save_t;


PACKSTRUCT( struct sl_bt_rsp_nvm_load_s
{
    uint16_t result;
    uint8array value;
});

typedef struct sl_bt_rsp_nvm_load_s sl_bt_rsp_nvm_load_t;


PACKSTRUCT( struct sl_bt_rsp_nvm_erase_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_nvm_erase_s sl_bt_rsp_nvm_erase_t;


PACKSTRUCT( struct sl_bt_rsp_nvm_erase_all_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_nvm_erase_all_s sl_bt_rsp_nvm_erase_all_t;


PACKSTRUCT( struct sl_bt_rsp_test_dtm_tx_v4_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_test_dtm_tx_v4_s sl_bt_rsp_test_dtm_tx_v4_t;


PACKSTRUCT( struct sl_bt_rsp_test_dtm_tx_cw_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_test_dtm_tx_cw_s sl_bt_rsp_test_dtm_tx_cw_t;


PACKSTRUCT( struct sl_bt_rsp_test_dtm_rx_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_test_dtm_rx_s sl_bt_rsp_test_dtm_rx_t;


PACKSTRUCT( struct sl_bt_rsp_test_dtm_end_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_test_dtm_end_s sl_bt_rsp_test_dtm_end_t;


PACKSTRUCT( struct sl_bt_rsp_sm_configure_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_configure_s sl_bt_rsp_sm_configure_t;


PACKSTRUCT( struct sl_bt_rsp_sm_set_minimum_key_size_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_set_minimum_key_size_s sl_bt_rsp_sm_set_minimum_key_size_t;


PACKSTRUCT( struct sl_bt_rsp_sm_set_debug_mode_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_set_debug_mode_s sl_bt_rsp_sm_set_debug_mode_t;


PACKSTRUCT( struct sl_bt_rsp_sm_store_bonding_configuration_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_store_bonding_configuration_s sl_bt_rsp_sm_store_bonding_configuration_t;


PACKSTRUCT( struct sl_bt_rsp_sm_set_bondable_mode_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_set_bondable_mode_s sl_bt_rsp_sm_set_bondable_mode_t;


PACKSTRUCT( struct sl_bt_rsp_sm_set_passkey_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_set_passkey_s sl_bt_rsp_sm_set_passkey_t;


PACKSTRUCT( struct sl_bt_rsp_sm_increase_security_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_increase_security_s sl_bt_rsp_sm_increase_security_t;


PACKSTRUCT( struct sl_bt_rsp_sm_enter_passkey_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_enter_passkey_s sl_bt_rsp_sm_enter_passkey_t;


PACKSTRUCT( struct sl_bt_rsp_sm_passkey_confirm_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_passkey_confirm_s sl_bt_rsp_sm_passkey_confirm_t;


PACKSTRUCT( struct sl_bt_rsp_sm_bonding_confirm_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_bonding_confirm_s sl_bt_rsp_sm_bonding_confirm_t;


PACKSTRUCT( struct sl_bt_rsp_sm_delete_bonding_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_delete_bonding_s sl_bt_rsp_sm_delete_bonding_t;


PACKSTRUCT( struct sl_bt_rsp_sm_delete_bondings_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_delete_bondings_s sl_bt_rsp_sm_delete_bondings_t;


PACKSTRUCT( struct sl_bt_rsp_sm_get_bonding_handles_s
{
    uint16_t result;
    uint32_t num_bondings;
    uint8array bondings;
});

typedef struct sl_bt_rsp_sm_get_bonding_handles_s sl_bt_rsp_sm_get_bonding_handles_t;


PACKSTRUCT( struct sl_bt_rsp_sm_get_bonding_details_s
{
    uint16_t result;
    bd_addr address;
    uint8_t address_type;
    uint8_t security_mode;
    uint8_t key_size;
});

typedef struct sl_bt_rsp_sm_get_bonding_details_s sl_bt_rsp_sm_get_bonding_details_t;


PACKSTRUCT( struct sl_bt_rsp_sm_find_bonding_by_address_s
{
    uint16_t result;
    uint32_t bonding;
    uint8_t security_mode;
    uint8_t key_size;
});

typedef struct sl_bt_rsp_sm_find_bonding_by_address_s sl_bt_rsp_sm_find_bonding_by_address_t;


PACKSTRUCT( struct sl_bt_rsp_sm_resolve_rpa_s
{
    uint16_t result;
    bd_addr address;
    uint8_t address_type;
    uint32_t bonding;
});

typedef struct sl_bt_rsp_sm_resolve_rpa_s sl_bt_rsp_sm_resolve_rpa_t;


PACKSTRUCT( struct sl_bt_rsp_sm_set_bonding_key_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_set_bonding_key_s sl_bt_rsp_sm_set_bonding_key_t;


PACKSTRUCT( struct sl_bt_rsp_sm_set_legacy_oob_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_set_legacy_oob_s sl_bt_rsp_sm_set_legacy_oob_t;


PACKSTRUCT( struct sl_bt_rsp_sm_set_oob_s
{
    uint16_t result;
    aes_key_128 random;
    aes_key_128 confirm;
});

typedef struct sl_bt_rsp_sm_set_oob_s sl_bt_rsp_sm_set_oob_t;


PACKSTRUCT( struct sl_bt_rsp_sm_set_remote_oob_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_sm_set_remote_oob_s sl_bt_rsp_sm_set_remote_oob_t;


PACKSTRUCT( struct sl_bt_rsp_external_bondingdb_set_data_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_external_bondingdb_set_data_s sl_bt_rsp_external_bondingdb_set_data_t;


PACKSTRUCT( struct sl_bt_rsp_external_bondingdb_set_local_irk_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_external_bondingdb_set_local_irk_s sl_bt_rsp_external_bondingdb_set_local_irk_t;


PACKSTRUCT( struct sl_bt_rsp_resolving_list_add_device_by_bonding_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_resolving_list_add_device_by_bonding_s sl_bt_rsp_resolving_list_add_device_by_bonding_t;


PACKSTRUCT( struct sl_bt_rsp_resolving_list_add_device_by_address_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_resolving_list_add_device_by_address_s sl_bt_rsp_resolving_list_add_device_by_address_t;


PACKSTRUCT( struct sl_bt_rsp_resolving_list_remove_device_by_bonding_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_resolving_list_remove_device_by_bonding_s sl_bt_rsp_resolving_list_remove_device_by_bonding_t;


PACKSTRUCT( struct sl_bt_rsp_resolving_list_remove_device_by_address_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_resolving_list_remove_device_by_address_s sl_bt_rsp_resolving_list_remove_device_by_address_t;


PACKSTRUCT( struct sl_bt_rsp_resolving_list_remove_all_devices_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_resolving_list_remove_all_devices_s sl_bt_rsp_resolving_list_remove_all_devices_t;


PACKSTRUCT( struct sl_bt_rsp_accept_list_add_device_by_bonding_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_accept_list_add_device_by_bonding_s sl_bt_rsp_accept_list_add_device_by_bonding_t;


PACKSTRUCT( struct sl_bt_rsp_accept_list_add_device_by_address_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_accept_list_add_device_by_address_s sl_bt_rsp_accept_list_add_device_by_address_t;


PACKSTRUCT( struct sl_bt_rsp_accept_list_remove_device_by_bonding_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_accept_list_remove_device_by_bonding_s sl_bt_rsp_accept_list_remove_device_by_bonding_t;


PACKSTRUCT( struct sl_bt_rsp_accept_list_remove_device_by_address_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_accept_list_remove_device_by_address_s sl_bt_rsp_accept_list_remove_device_by_address_t;


PACKSTRUCT( struct sl_bt_rsp_accept_list_remove_all_devices_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_accept_list_remove_all_devices_s sl_bt_rsp_accept_list_remove_all_devices_t;


PACKSTRUCT( struct sl_bt_rsp_coex_set_options_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_coex_set_options_s sl_bt_rsp_coex_set_options_t;


PACKSTRUCT( struct sl_bt_rsp_coex_set_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_coex_set_parameters_s sl_bt_rsp_coex_set_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_coex_set_directional_priority_pulse_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_coex_set_directional_priority_pulse_s sl_bt_rsp_coex_set_directional_priority_pulse_t;


PACKSTRUCT( struct sl_bt_rsp_coex_get_parameters_s
{
    uint16_t result;
    uint8_t priority;
    uint8_t request;
    uint8_t pwm_period;
    uint8_t pwm_dutycycle;
});

typedef struct sl_bt_rsp_coex_get_parameters_s sl_bt_rsp_coex_get_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_coex_get_counters_s
{
    uint16_t result;
    uint8array counters;
});

typedef struct sl_bt_rsp_coex_get_counters_s sl_bt_rsp_coex_get_counters_t;


PACKSTRUCT( struct sl_bt_rsp_cs_security_enable_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cs_security_enable_s sl_bt_rsp_cs_security_enable_t;


PACKSTRUCT( struct sl_bt_rsp_cs_set_default_settings_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cs_set_default_settings_s sl_bt_rsp_cs_set_default_settings_t;


PACKSTRUCT( struct sl_bt_rsp_cs_create_config_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cs_create_config_s sl_bt_rsp_cs_create_config_t;


PACKSTRUCT( struct sl_bt_rsp_cs_remove_config_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cs_remove_config_s sl_bt_rsp_cs_remove_config_t;


PACKSTRUCT( struct sl_bt_rsp_cs_set_channel_classification_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cs_set_channel_classification_s sl_bt_rsp_cs_set_channel_classification_t;


PACKSTRUCT( struct sl_bt_rsp_cs_set_procedure_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cs_set_procedure_parameters_s sl_bt_rsp_cs_set_procedure_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_cs_procedure_enable_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cs_procedure_enable_s sl_bt_rsp_cs_procedure_enable_t;


PACKSTRUCT( struct sl_bt_rsp_cs_set_antenna_configuration_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cs_set_antenna_configuration_s sl_bt_rsp_cs_set_antenna_configuration_t;


PACKSTRUCT( struct sl_bt_rsp_cs_read_local_supported_capabilities_s
{
    uint16_t result;
    uint8_t num_config;
    uint16_t max_consecutive_procedures;
    uint8_t num_antennas;
    uint8_t max_antenna_paths;
    uint8_t roles;
    uint8_t modes;
    uint8_t rtt_capability;
    uint8_t rtt_aa_only;
    uint8_t rtt_sounding;
    uint8_t rtt_random_payload;
    uint8_t cs_sync_phys;
    uint16_t subfeatures;
    uint16_t t_ip1_times;
    uint16_t t_ip2_times;
    uint16_t t_fcs_times;
    uint16_t t_pm_times;
    uint8_t t_sw_times;
    uint8_t tx_snr_capability;
});

typedef struct sl_bt_rsp_cs_read_local_supported_capabilities_s sl_bt_rsp_cs_read_local_supported_capabilities_t;


PACKSTRUCT( struct sl_bt_rsp_cs_read_remote_supported_capabilities_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cs_read_remote_supported_capabilities_s sl_bt_rsp_cs_read_remote_supported_capabilities_t;


PACKSTRUCT( struct sl_bt_rsp_cs_test_start_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cs_test_start_s sl_bt_rsp_cs_test_start_t;


PACKSTRUCT( struct sl_bt_rsp_cs_test_end_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cs_test_end_s sl_bt_rsp_cs_test_end_t;


PACKSTRUCT( struct sl_bt_rsp_l2cap_open_le_channel_s
{
    uint16_t result;
    uint16_t cid;
});

typedef struct sl_bt_rsp_l2cap_open_le_channel_s sl_bt_rsp_l2cap_open_le_channel_t;


PACKSTRUCT( struct sl_bt_rsp_l2cap_send_le_channel_open_response_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_l2cap_send_le_channel_open_response_s sl_bt_rsp_l2cap_send_le_channel_open_response_t;


PACKSTRUCT( struct sl_bt_rsp_l2cap_channel_send_data_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_l2cap_channel_send_data_s sl_bt_rsp_l2cap_channel_send_data_t;


PACKSTRUCT( struct sl_bt_rsp_l2cap_channel_send_credit_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_l2cap_channel_send_credit_s sl_bt_rsp_l2cap_channel_send_credit_t;


PACKSTRUCT( struct sl_bt_rsp_l2cap_close_channel_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_l2cap_close_channel_s sl_bt_rsp_l2cap_close_channel_t;


PACKSTRUCT( struct sl_bt_rsp_cte_transmitter_set_dtm_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_transmitter_set_dtm_parameters_s sl_bt_rsp_cte_transmitter_set_dtm_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_cte_transmitter_clear_dtm_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_transmitter_clear_dtm_parameters_s sl_bt_rsp_cte_transmitter_clear_dtm_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_cte_transmitter_enable_connection_cte_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_transmitter_enable_connection_cte_s sl_bt_rsp_cte_transmitter_enable_connection_cte_t;


PACKSTRUCT( struct sl_bt_rsp_cte_transmitter_disable_connection_cte_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_transmitter_disable_connection_cte_s sl_bt_rsp_cte_transmitter_disable_connection_cte_t;


PACKSTRUCT( struct sl_bt_rsp_cte_transmitter_enable_connectionless_cte_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_transmitter_enable_connectionless_cte_s sl_bt_rsp_cte_transmitter_enable_connectionless_cte_t;


PACKSTRUCT( struct sl_bt_rsp_cte_transmitter_disable_connectionless_cte_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_transmitter_disable_connectionless_cte_s sl_bt_rsp_cte_transmitter_disable_connectionless_cte_t;


PACKSTRUCT( struct sl_bt_rsp_cte_transmitter_enable_silabs_cte_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_transmitter_enable_silabs_cte_s sl_bt_rsp_cte_transmitter_enable_silabs_cte_t;


PACKSTRUCT( struct sl_bt_rsp_cte_transmitter_disable_silabs_cte_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_transmitter_disable_silabs_cte_s sl_bt_rsp_cte_transmitter_disable_silabs_cte_t;


PACKSTRUCT( struct sl_bt_rsp_cte_receiver_set_dtm_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_receiver_set_dtm_parameters_s sl_bt_rsp_cte_receiver_set_dtm_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_cte_receiver_clear_dtm_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_receiver_clear_dtm_parameters_s sl_bt_rsp_cte_receiver_clear_dtm_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_cte_receiver_set_sync_cte_type_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_receiver_set_sync_cte_type_s sl_bt_rsp_cte_receiver_set_sync_cte_type_t;


PACKSTRUCT( struct sl_bt_rsp_cte_receiver_set_default_sync_receive_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_receiver_set_default_sync_receive_parameters_s sl_bt_rsp_cte_receiver_set_default_sync_receive_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_cte_receiver_set_sync_receive_parameters_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_receiver_set_sync_receive_parameters_s sl_bt_rsp_cte_receiver_set_sync_receive_parameters_t;


PACKSTRUCT( struct sl_bt_rsp_cte_receiver_configure_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_receiver_configure_s sl_bt_rsp_cte_receiver_configure_t;


PACKSTRUCT( struct sl_bt_rsp_cte_receiver_enable_connection_cte_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_receiver_enable_connection_cte_s sl_bt_rsp_cte_receiver_enable_connection_cte_t;


PACKSTRUCT( struct sl_bt_rsp_cte_receiver_disable_connection_cte_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_receiver_disable_connection_cte_s sl_bt_rsp_cte_receiver_disable_connection_cte_t;


PACKSTRUCT( struct sl_bt_rsp_cte_receiver_enable_connectionless_cte_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_receiver_enable_connectionless_cte_s sl_bt_rsp_cte_receiver_enable_connectionless_cte_t;


PACKSTRUCT( struct sl_bt_rsp_cte_receiver_disable_connectionless_cte_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_receiver_disable_connectionless_cte_s sl_bt_rsp_cte_receiver_disable_connectionless_cte_t;


PACKSTRUCT( struct sl_bt_rsp_cte_receiver_enable_silabs_cte_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_receiver_enable_silabs_cte_s sl_bt_rsp_cte_receiver_enable_silabs_cte_t;


PACKSTRUCT( struct sl_bt_rsp_cte_receiver_disable_silabs_cte_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_cte_receiver_disable_silabs_cte_s sl_bt_rsp_cte_receiver_disable_silabs_cte_t;


PACKSTRUCT( struct sl_bt_rsp_connection_analyzer_start_s
{
    uint16_t result;
    uint8_t analyzer;
});

typedef struct sl_bt_rsp_connection_analyzer_start_s sl_bt_rsp_connection_analyzer_start_t;


PACKSTRUCT( struct sl_bt_rsp_connection_analyzer_stop_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_connection_analyzer_stop_s sl_bt_rsp_connection_analyzer_stop_t;


PACKSTRUCT( struct sl_bt_rsp_user_message_to_target_s
{
    uint16_t result;
    uint8array response;
});

typedef struct sl_bt_rsp_user_message_to_target_s sl_bt_rsp_user_message_to_target_t;


PACKSTRUCT( struct sl_bt_rsp_user_manage_event_filter_s
{
    uint16_t result;
});

typedef struct sl_bt_rsp_user_manage_event_filter_s sl_bt_rsp_user_manage_event_filter_t;


PACKSTRUCT( struct sl_bt_rsp_user_cs_service_message_to_target_s
{
    uint16_t result;
    uint8array response;
});

typedef struct sl_bt_rsp_user_cs_service_message_to_target_s sl_bt_rsp_user_cs_service_message_to_target_t;



PACKSTRUCT( struct sl_bt_packet {
  uint32_t   header;
  union {
    uint8_t handle;
    sl_bt_rsp_error_t rsp_error;
    sl_bt_cmd_dfu_flash_set_address_t                            cmd_dfu_flash_set_address;
    sl_bt_cmd_dfu_flash_upload_t                                 cmd_dfu_flash_upload;
    sl_bt_cmd_system_halt_t                                      cmd_system_halt;
    sl_bt_cmd_system_linklayer_configure_t                       cmd_system_linklayer_configure;
    sl_bt_cmd_system_set_tx_power_t                              cmd_system_set_tx_power;
    sl_bt_cmd_system_set_identity_address_t                      cmd_system_set_identity_address;
    sl_bt_cmd_system_get_random_data_t                           cmd_system_get_random_data;
    sl_bt_cmd_system_data_buffer_write_t                         cmd_system_data_buffer_write;
    sl_bt_cmd_system_get_counters_t                              cmd_system_get_counters;
    sl_bt_cmd_system_set_lazy_soft_timer_t                       cmd_system_set_lazy_soft_timer;
    sl_bt_cmd_system_reset_t                                     cmd_system_reset;
    sl_bt_cmd_resource_set_report_threshold_t                    cmd_resource_set_report_threshold;
    sl_bt_cmd_resource_enable_connection_tx_report_t             cmd_resource_enable_connection_tx_report;
    sl_bt_cmd_resource_get_connection_tx_status_t                cmd_resource_get_connection_tx_status;
    sl_bt_cmd_gap_set_privacy_mode_t                             cmd_gap_set_privacy_mode;
    sl_bt_cmd_gap_set_data_channel_classification_t              cmd_gap_set_data_channel_classification;
    sl_bt_cmd_gap_set_identity_address_t                         cmd_gap_set_identity_address;
    sl_bt_cmd_advertiser_configure_t                             cmd_advertiser_configure;
    sl_bt_cmd_advertiser_set_timing_t                            cmd_advertiser_set_timing;
    sl_bt_cmd_advertiser_set_channel_map_t                       cmd_advertiser_set_channel_map;
    sl_bt_cmd_advertiser_set_tx_power_t                          cmd_advertiser_set_tx_power;
    sl_bt_cmd_advertiser_set_report_scan_request_t               cmd_advertiser_set_report_scan_request;
    sl_bt_cmd_advertiser_set_random_address_t                    cmd_advertiser_set_random_address;
    sl_bt_cmd_advertiser_clear_random_address_t                  cmd_advertiser_clear_random_address;
    sl_bt_cmd_advertiser_stop_t                                  cmd_advertiser_stop;
    sl_bt_cmd_advertiser_delete_set_t                            cmd_advertiser_delete_set;
    sl_bt_cmd_legacy_advertiser_set_data_t                       cmd_legacy_advertiser_set_data;
    sl_bt_cmd_legacy_advertiser_generate_data_t                  cmd_legacy_advertiser_generate_data;
    sl_bt_cmd_legacy_advertiser_start_t                          cmd_legacy_advertiser_start;
    sl_bt_cmd_legacy_advertiser_start_directed_t                 cmd_legacy_advertiser_start_directed;
    sl_bt_cmd_extended_advertiser_set_phy_t                      cmd_extended_advertiser_set_phy;
    sl_bt_cmd_extended_advertiser_set_data_t                     cmd_extended_advertiser_set_data;
    sl_bt_cmd_extended_advertiser_set_long_data_t                cmd_extended_advertiser_set_long_data;
    sl_bt_cmd_extended_advertiser_generate_data_t                cmd_extended_advertiser_generate_data;
    sl_bt_cmd_extended_advertiser_start_t                        cmd_extended_advertiser_start;
    sl_bt_cmd_extended_advertiser_start_directed_t               cmd_extended_advertiser_start_directed;
    sl_bt_cmd_periodic_advertiser_set_data_t                     cmd_periodic_advertiser_set_data;
    sl_bt_cmd_periodic_advertiser_set_long_data_t                cmd_periodic_advertiser_set_long_data;
    sl_bt_cmd_periodic_advertiser_start_t                        cmd_periodic_advertiser_start;
    sl_bt_cmd_periodic_advertiser_stop_t                         cmd_periodic_advertiser_stop;
    sl_bt_cmd_scanner_set_parameters_t                           cmd_scanner_set_parameters;
    sl_bt_cmd_scanner_set_parameters_and_filter_t                cmd_scanner_set_parameters_and_filter;
    sl_bt_cmd_scanner_start_t                                    cmd_scanner_start;
    sl_bt_cmd_sync_set_reporting_mode_t                          cmd_sync_set_reporting_mode;
    sl_bt_cmd_sync_update_sync_parameters_t                      cmd_sync_update_sync_parameters;
    sl_bt_cmd_sync_close_t                                       cmd_sync_close;
    sl_bt_cmd_sync_scanner_set_sync_parameters_t                 cmd_sync_scanner_set_sync_parameters;
    sl_bt_cmd_sync_scanner_open_t                                cmd_sync_scanner_open;
    sl_bt_cmd_past_receiver_set_default_sync_receive_parameters_t cmd_past_receiver_set_default_sync_receive_parameters;
    sl_bt_cmd_past_receiver_set_sync_receive_parameters_t        cmd_past_receiver_set_sync_receive_parameters;
    sl_bt_cmd_past_receiver_set_default_sync_receive_over_sync_parameters_t cmd_past_receiver_set_default_sync_receive_over_sync_parameters;
    sl_bt_cmd_past_receiver_set_sync_receive_over_sync_parameters_t cmd_past_receiver_set_sync_receive_over_sync_parameters;
    sl_bt_cmd_advertiser_past_transfer_t                         cmd_advertiser_past_transfer;
    sl_bt_cmd_advertiser_past_transfer_over_pawr_advertiser_t    cmd_advertiser_past_transfer_over_pawr_advertiser;
    sl_bt_cmd_sync_past_transfer_t                               cmd_sync_past_transfer;
    sl_bt_cmd_pawr_sync_set_sync_subevents_t                     cmd_pawr_sync_set_sync_subevents;
    sl_bt_cmd_pawr_sync_set_response_data_t                      cmd_pawr_sync_set_response_data;
    sl_bt_cmd_pawr_advertiser_start_t                            cmd_pawr_advertiser_start;
    sl_bt_cmd_pawr_advertiser_change_parameters_t                cmd_pawr_advertiser_change_parameters;
    sl_bt_cmd_pawr_advertiser_set_subevent_data_t                cmd_pawr_advertiser_set_subevent_data;
    sl_bt_cmd_pawr_advertiser_create_connection_t                cmd_pawr_advertiser_create_connection;
    sl_bt_cmd_pawr_advertiser_stop_t                             cmd_pawr_advertiser_stop;
    sl_bt_cmd_connection_set_default_parameters_t                cmd_connection_set_default_parameters;
    sl_bt_cmd_connection_set_default_preferred_phy_t             cmd_connection_set_default_preferred_phy;
    sl_bt_cmd_connection_set_default_data_length_t               cmd_connection_set_default_data_length;
    sl_bt_cmd_connection_set_default_acceptable_subrate_t        cmd_connection_set_default_acceptable_subrate;
    sl_bt_cmd_connection_open_t                                  cmd_connection_open;
    sl_bt_cmd_connection_open_with_accept_list_t                 cmd_connection_open_with_accept_list;
    sl_bt_cmd_connection_set_parameters_t                        cmd_connection_set_parameters;
    sl_bt_cmd_connection_set_preferred_phy_t                     cmd_connection_set_preferred_phy;
    sl_bt_cmd_connection_disable_slave_latency_t                 cmd_connection_disable_slave_latency;
    sl_bt_cmd_connection_get_median_rssi_t                       cmd_connection_get_median_rssi;
    sl_bt_cmd_connection_read_channel_map_t                      cmd_connection_read_channel_map;
    sl_bt_cmd_connection_set_power_reporting_t                   cmd_connection_set_power_reporting;
    sl_bt_cmd_connection_set_remote_power_reporting_t            cmd_connection_set_remote_power_reporting;
    sl_bt_cmd_connection_get_tx_power_t                          cmd_connection_get_tx_power;
    sl_bt_cmd_connection_get_remote_tx_power_t                   cmd_connection_get_remote_tx_power;
    sl_bt_cmd_connection_set_tx_power_t                          cmd_connection_set_tx_power;
    sl_bt_cmd_connection_read_remote_used_features_t             cmd_connection_read_remote_used_features;
    sl_bt_cmd_connection_get_security_status_t                   cmd_connection_get_security_status;
    sl_bt_cmd_connection_set_data_length_t                       cmd_connection_set_data_length;
    sl_bt_cmd_connection_read_statistics_t                       cmd_connection_read_statistics;
    sl_bt_cmd_connection_get_scheduling_details_t                cmd_connection_get_scheduling_details;
    sl_bt_cmd_connection_get_remote_address_t                    cmd_connection_get_remote_address;
    sl_bt_cmd_connection_request_subrate_t                       cmd_connection_request_subrate;
    sl_bt_cmd_connection_get_state_t                             cmd_connection_get_state;
    sl_bt_cmd_connection_close_t                                 cmd_connection_close;
    sl_bt_cmd_connection_forcefully_close_t                      cmd_connection_forcefully_close;
    sl_bt_cmd_gatt_set_max_mtu_t                                 cmd_gatt_set_max_mtu;
    sl_bt_cmd_gatt_discover_primary_services_t                   cmd_gatt_discover_primary_services;
    sl_bt_cmd_gatt_discover_primary_services_by_uuid_t           cmd_gatt_discover_primary_services_by_uuid;
    sl_bt_cmd_gatt_find_included_services_t                      cmd_gatt_find_included_services;
    sl_bt_cmd_gatt_discover_characteristics_t                    cmd_gatt_discover_characteristics;
    sl_bt_cmd_gatt_discover_characteristics_by_uuid_t            cmd_gatt_discover_characteristics_by_uuid;
    sl_bt_cmd_gatt_discover_descriptors_t                        cmd_gatt_discover_descriptors;
    sl_bt_cmd_gatt_discover_characteristic_descriptors_t         cmd_gatt_discover_characteristic_descriptors;
    sl_bt_cmd_gatt_set_characteristic_notification_t             cmd_gatt_set_characteristic_notification;
    sl_bt_cmd_gatt_send_characteristic_confirmation_t            cmd_gatt_send_characteristic_confirmation;
    sl_bt_cmd_gatt_read_characteristic_value_t                   cmd_gatt_read_characteristic_value;
    sl_bt_cmd_gatt_read_characteristic_value_from_offset_t       cmd_gatt_read_characteristic_value_from_offset;
    sl_bt_cmd_gatt_read_multiple_characteristic_values_t         cmd_gatt_read_multiple_characteristic_values;
    sl_bt_cmd_gatt_read_variable_length_characteristic_values_t  cmd_gatt_read_variable_length_characteristic_values;
    sl_bt_cmd_gatt_read_characteristic_value_by_uuid_t           cmd_gatt_read_characteristic_value_by_uuid;
    sl_bt_cmd_gatt_write_characteristic_value_t                  cmd_gatt_write_characteristic_value;
    sl_bt_cmd_gatt_write_characteristic_value_without_response_t cmd_gatt_write_characteristic_value_without_response;
    sl_bt_cmd_gatt_prepare_characteristic_value_write_t          cmd_gatt_prepare_characteristic_value_write;
    sl_bt_cmd_gatt_prepare_characteristic_value_reliable_write_t cmd_gatt_prepare_characteristic_value_reliable_write;
    sl_bt_cmd_gatt_execute_characteristic_value_write_t          cmd_gatt_execute_characteristic_value_write;
    sl_bt_cmd_gatt_read_descriptor_value_t                       cmd_gatt_read_descriptor_value;
    sl_bt_cmd_gatt_write_descriptor_value_t                      cmd_gatt_write_descriptor_value;
    sl_bt_cmd_gatt_get_mtu_t                                     cmd_gatt_get_mtu;
    sl_bt_cmd_gattdb_add_service_t                               cmd_gattdb_add_service;
    sl_bt_cmd_gattdb_remove_service_t                            cmd_gattdb_remove_service;
    sl_bt_cmd_gattdb_add_included_service_t                      cmd_gattdb_add_included_service;
    sl_bt_cmd_gattdb_remove_included_service_t                   cmd_gattdb_remove_included_service;
    sl_bt_cmd_gattdb_add_uuid16_characteristic_t                 cmd_gattdb_add_uuid16_characteristic;
    sl_bt_cmd_gattdb_add_uuid128_characteristic_t                cmd_gattdb_add_uuid128_characteristic;
    sl_bt_cmd_gattdb_remove_characteristic_t                     cmd_gattdb_remove_characteristic;
    sl_bt_cmd_gattdb_add_uuid16_descriptor_t                     cmd_gattdb_add_uuid16_descriptor;
    sl_bt_cmd_gattdb_add_uuid128_descriptor_t                    cmd_gattdb_add_uuid128_descriptor;
    sl_bt_cmd_gattdb_remove_descriptor_t                         cmd_gattdb_remove_descriptor;
    sl_bt_cmd_gattdb_start_service_t                             cmd_gattdb_start_service;
    sl_bt_cmd_gattdb_stop_service_t                              cmd_gattdb_stop_service;
    sl_bt_cmd_gattdb_start_characteristic_t                      cmd_gattdb_start_characteristic;
    sl_bt_cmd_gattdb_stop_characteristic_t                       cmd_gattdb_stop_characteristic;
    sl_bt_cmd_gattdb_commit_t                                    cmd_gattdb_commit;
    sl_bt_cmd_gattdb_abort_t                                     cmd_gattdb_abort;
    sl_bt_cmd_gattdb_get_attribute_state_t                       cmd_gattdb_get_attribute_state;
    sl_bt_cmd_gatt_server_set_max_mtu_t                          cmd_gatt_server_set_max_mtu;
    sl_bt_cmd_gatt_server_get_mtu_t                              cmd_gatt_server_get_mtu;
    sl_bt_cmd_gatt_server_find_attribute_t                       cmd_gatt_server_find_attribute;
    sl_bt_cmd_gatt_server_find_primary_service_t                 cmd_gatt_server_find_primary_service;
    sl_bt_cmd_gatt_server_read_attribute_value_t                 cmd_gatt_server_read_attribute_value;
    sl_bt_cmd_gatt_server_read_attribute_type_t                  cmd_gatt_server_read_attribute_type;
    sl_bt_cmd_gatt_server_read_attribute_properties_t            cmd_gatt_server_read_attribute_properties;
    sl_bt_cmd_gatt_server_write_attribute_value_t                cmd_gatt_server_write_attribute_value;
    sl_bt_cmd_gatt_server_send_user_read_response_t              cmd_gatt_server_send_user_read_response;
    sl_bt_cmd_gatt_server_send_user_write_response_t             cmd_gatt_server_send_user_write_response;
    sl_bt_cmd_gatt_server_send_notification_t                    cmd_gatt_server_send_notification;
    sl_bt_cmd_gatt_server_send_notification_with_options_t       cmd_gatt_server_send_notification_with_options;
    sl_bt_cmd_gatt_server_send_indication_t                      cmd_gatt_server_send_indication;
    sl_bt_cmd_gatt_server_send_indication_with_options_t         cmd_gatt_server_send_indication_with_options;
    sl_bt_cmd_gatt_server_notify_all_t                           cmd_gatt_server_notify_all;
    sl_bt_cmd_gatt_server_read_client_configuration_t            cmd_gatt_server_read_client_configuration;
    sl_bt_cmd_gatt_server_send_user_prepare_write_response_t     cmd_gatt_server_send_user_prepare_write_response;
    sl_bt_cmd_gatt_server_set_capabilities_t                     cmd_gatt_server_set_capabilities;
    sl_bt_cmd_gatt_server_enable_capabilities_t                  cmd_gatt_server_enable_capabilities;
    sl_bt_cmd_gatt_server_disable_capabilities_t                 cmd_gatt_server_disable_capabilities;
    sl_bt_cmd_gatt_server_read_client_supported_features_t       cmd_gatt_server_read_client_supported_features;
    sl_bt_cmd_nvm_save_t                                         cmd_nvm_save;
    sl_bt_cmd_nvm_load_t                                         cmd_nvm_load;
    sl_bt_cmd_nvm_erase_t                                        cmd_nvm_erase;
    sl_bt_cmd_test_dtm_tx_v4_t                                   cmd_test_dtm_tx_v4;
    sl_bt_cmd_test_dtm_tx_cw_t                                   cmd_test_dtm_tx_cw;
    sl_bt_cmd_test_dtm_rx_t                                      cmd_test_dtm_rx;
    sl_bt_cmd_sm_configure_t                                     cmd_sm_configure;
    sl_bt_cmd_sm_set_minimum_key_size_t                          cmd_sm_set_minimum_key_size;
    sl_bt_cmd_sm_store_bonding_configuration_t                   cmd_sm_store_bonding_configuration;
    sl_bt_cmd_sm_set_bondable_mode_t                             cmd_sm_set_bondable_mode;
    sl_bt_cmd_sm_set_passkey_t                                   cmd_sm_set_passkey;
    sl_bt_cmd_sm_increase_security_t                             cmd_sm_increase_security;
    sl_bt_cmd_sm_enter_passkey_t                                 cmd_sm_enter_passkey;
    sl_bt_cmd_sm_passkey_confirm_t                               cmd_sm_passkey_confirm;
    sl_bt_cmd_sm_bonding_confirm_t                               cmd_sm_bonding_confirm;
    sl_bt_cmd_sm_delete_bonding_t                                cmd_sm_delete_bonding;
    sl_bt_cmd_sm_get_bonding_handles_t                           cmd_sm_get_bonding_handles;
    sl_bt_cmd_sm_get_bonding_details_t                           cmd_sm_get_bonding_details;
    sl_bt_cmd_sm_find_bonding_by_address_t                       cmd_sm_find_bonding_by_address;
    sl_bt_cmd_sm_resolve_rpa_t                                   cmd_sm_resolve_rpa;
    sl_bt_cmd_sm_set_bonding_key_t                               cmd_sm_set_bonding_key;
    sl_bt_cmd_sm_set_legacy_oob_t                                cmd_sm_set_legacy_oob;
    sl_bt_cmd_sm_set_oob_t                                       cmd_sm_set_oob;
    sl_bt_cmd_sm_set_remote_oob_t                                cmd_sm_set_remote_oob;
    sl_bt_cmd_external_bondingdb_set_data_t                      cmd_external_bondingdb_set_data;
    sl_bt_cmd_external_bondingdb_set_local_irk_t                 cmd_external_bondingdb_set_local_irk;
    sl_bt_cmd_resolving_list_add_device_by_bonding_t             cmd_resolving_list_add_device_by_bonding;
    sl_bt_cmd_resolving_list_add_device_by_address_t             cmd_resolving_list_add_device_by_address;
    sl_bt_cmd_resolving_list_remove_device_by_bonding_t          cmd_resolving_list_remove_device_by_bonding;
    sl_bt_cmd_resolving_list_remove_device_by_address_t          cmd_resolving_list_remove_device_by_address;
    sl_bt_cmd_accept_list_add_device_by_bonding_t                cmd_accept_list_add_device_by_bonding;
    sl_bt_cmd_accept_list_add_device_by_address_t                cmd_accept_list_add_device_by_address;
    sl_bt_cmd_accept_list_remove_device_by_bonding_t             cmd_accept_list_remove_device_by_bonding;
    sl_bt_cmd_accept_list_remove_device_by_address_t             cmd_accept_list_remove_device_by_address;
    sl_bt_cmd_coex_set_options_t                                 cmd_coex_set_options;
    sl_bt_cmd_coex_set_parameters_t                              cmd_coex_set_parameters;
    sl_bt_cmd_coex_set_directional_priority_pulse_t              cmd_coex_set_directional_priority_pulse;
    sl_bt_cmd_coex_get_counters_t                                cmd_coex_get_counters;
    sl_bt_cmd_cs_security_enable_t                               cmd_cs_security_enable;
    sl_bt_cmd_cs_set_default_settings_t                          cmd_cs_set_default_settings;
    sl_bt_cmd_cs_create_config_t                                 cmd_cs_create_config;
    sl_bt_cmd_cs_remove_config_t                                 cmd_cs_remove_config;
    sl_bt_cmd_cs_set_channel_classification_t                    cmd_cs_set_channel_classification;
    sl_bt_cmd_cs_set_procedure_parameters_t                      cmd_cs_set_procedure_parameters;
    sl_bt_cmd_cs_procedure_enable_t                              cmd_cs_procedure_enable;
    sl_bt_cmd_cs_set_antenna_configuration_t                     cmd_cs_set_antenna_configuration;
    sl_bt_cmd_cs_read_remote_supported_capabilities_t            cmd_cs_read_remote_supported_capabilities;
    sl_bt_cmd_cs_test_start_t                                    cmd_cs_test_start;
    sl_bt_cmd_l2cap_open_le_channel_t                            cmd_l2cap_open_le_channel;
    sl_bt_cmd_l2cap_send_le_channel_open_response_t              cmd_l2cap_send_le_channel_open_response;
    sl_bt_cmd_l2cap_channel_send_data_t                          cmd_l2cap_channel_send_data;
    sl_bt_cmd_l2cap_channel_send_credit_t                        cmd_l2cap_channel_send_credit;
    sl_bt_cmd_l2cap_close_channel_t                              cmd_l2cap_close_channel;
    sl_bt_cmd_cte_transmitter_set_dtm_parameters_t               cmd_cte_transmitter_set_dtm_parameters;
    sl_bt_cmd_cte_transmitter_enable_connection_cte_t            cmd_cte_transmitter_enable_connection_cte;
    sl_bt_cmd_cte_transmitter_disable_connection_cte_t           cmd_cte_transmitter_disable_connection_cte;
    sl_bt_cmd_cte_transmitter_enable_connectionless_cte_t        cmd_cte_transmitter_enable_connectionless_cte;
    sl_bt_cmd_cte_transmitter_disable_connectionless_cte_t       cmd_cte_transmitter_disable_connectionless_cte;
    sl_bt_cmd_cte_transmitter_enable_silabs_cte_t                cmd_cte_transmitter_enable_silabs_cte;
    sl_bt_cmd_cte_transmitter_disable_silabs_cte_t               cmd_cte_transmitter_disable_silabs_cte;
    sl_bt_cmd_cte_receiver_set_dtm_parameters_t                  cmd_cte_receiver_set_dtm_parameters;
    sl_bt_cmd_cte_receiver_set_sync_cte_type_t                   cmd_cte_receiver_set_sync_cte_type;
    sl_bt_cmd_cte_receiver_set_default_sync_receive_parameters_t cmd_cte_receiver_set_default_sync_receive_parameters;
    sl_bt_cmd_cte_receiver_set_sync_receive_parameters_t         cmd_cte_receiver_set_sync_receive_parameters;
    sl_bt_cmd_cte_receiver_configure_t                           cmd_cte_receiver_configure;
    sl_bt_cmd_cte_receiver_enable_connection_cte_t               cmd_cte_receiver_enable_connection_cte;
    sl_bt_cmd_cte_receiver_disable_connection_cte_t              cmd_cte_receiver_disable_connection_cte;
    sl_bt_cmd_cte_receiver_enable_connectionless_cte_t           cmd_cte_receiver_enable_connectionless_cte;
    sl_bt_cmd_cte_receiver_disable_connectionless_cte_t          cmd_cte_receiver_disable_connectionless_cte;
    sl_bt_cmd_cte_receiver_enable_silabs_cte_t                   cmd_cte_receiver_enable_silabs_cte;
    sl_bt_cmd_connection_analyzer_start_t                        cmd_connection_analyzer_start;
    sl_bt_cmd_connection_analyzer_stop_t                         cmd_connection_analyzer_stop;
    sl_bt_cmd_user_message_to_target_t                           cmd_user_message_to_target;
    sl_bt_cmd_user_manage_event_filter_t                         cmd_user_manage_event_filter;
    sl_bt_cmd_user_cs_service_message_to_target_t                cmd_user_cs_service_message_to_target;
    sl_bt_rsp_dfu_flash_set_address_t                            rsp_dfu_flash_set_address;
    sl_bt_rsp_dfu_flash_upload_t                                 rsp_dfu_flash_upload;
    sl_bt_rsp_dfu_flash_upload_finish_t                          rsp_dfu_flash_upload_finish;
    sl_bt_rsp_system_hello_t                                     rsp_system_hello;
    sl_bt_rsp_system_start_bluetooth_t                           rsp_system_start_bluetooth;
    sl_bt_rsp_system_stop_bluetooth_t                            rsp_system_stop_bluetooth;
    sl_bt_rsp_system_forcefully_stop_bluetooth_t                 rsp_system_forcefully_stop_bluetooth;
    sl_bt_rsp_system_get_version_t                               rsp_system_get_version;
    sl_bt_rsp_system_halt_t                                      rsp_system_halt;
    sl_bt_rsp_system_linklayer_configure_t                       rsp_system_linklayer_configure;
    sl_bt_rsp_system_set_tx_power_t                              rsp_system_set_tx_power;
    sl_bt_rsp_system_get_tx_power_setting_t                      rsp_system_get_tx_power_setting;
    sl_bt_rsp_system_set_identity_address_t                      rsp_system_set_identity_address;
    sl_bt_rsp_system_get_identity_address_t                      rsp_system_get_identity_address;
    sl_bt_rsp_system_get_random_data_t                           rsp_system_get_random_data;
    sl_bt_rsp_system_data_buffer_write_t                         rsp_system_data_buffer_write;
    sl_bt_rsp_system_data_buffer_clear_t                         rsp_system_data_buffer_clear;
    sl_bt_rsp_system_get_counters_t                              rsp_system_get_counters;
    sl_bt_rsp_system_set_lazy_soft_timer_t                       rsp_system_set_lazy_soft_timer;
    sl_bt_rsp_resource_get_status_t                              rsp_resource_get_status;
    sl_bt_rsp_resource_set_report_threshold_t                    rsp_resource_set_report_threshold;
    sl_bt_rsp_resource_enable_connection_tx_report_t             rsp_resource_enable_connection_tx_report;
    sl_bt_rsp_resource_get_connection_tx_status_t                rsp_resource_get_connection_tx_status;
    sl_bt_rsp_resource_disable_connection_tx_report_t            rsp_resource_disable_connection_tx_report;
    sl_bt_rsp_gap_set_privacy_mode_t                             rsp_gap_set_privacy_mode;
    sl_bt_rsp_gap_set_data_channel_classification_t              rsp_gap_set_data_channel_classification;
    sl_bt_rsp_gap_set_identity_address_t                         rsp_gap_set_identity_address;
    sl_bt_rsp_gap_get_identity_address_t                         rsp_gap_get_identity_address;
    sl_bt_rsp_advertiser_create_set_t                            rsp_advertiser_create_set;
    sl_bt_rsp_advertiser_configure_t                             rsp_advertiser_configure;
    sl_bt_rsp_advertiser_set_timing_t                            rsp_advertiser_set_timing;
    sl_bt_rsp_advertiser_set_channel_map_t                       rsp_advertiser_set_channel_map;
    sl_bt_rsp_advertiser_set_tx_power_t                          rsp_advertiser_set_tx_power;
    sl_bt_rsp_advertiser_set_report_scan_request_t               rsp_advertiser_set_report_scan_request;
    sl_bt_rsp_advertiser_set_random_address_t                    rsp_advertiser_set_random_address;
    sl_bt_rsp_advertiser_clear_random_address_t                  rsp_advertiser_clear_random_address;
    sl_bt_rsp_advertiser_stop_t                                  rsp_advertiser_stop;
    sl_bt_rsp_advertiser_delete_set_t                            rsp_advertiser_delete_set;
    sl_bt_rsp_legacy_advertiser_set_data_t                       rsp_legacy_advertiser_set_data;
    sl_bt_rsp_legacy_advertiser_generate_data_t                  rsp_legacy_advertiser_generate_data;
    sl_bt_rsp_legacy_advertiser_start_t                          rsp_legacy_advertiser_start;
    sl_bt_rsp_legacy_advertiser_start_directed_t                 rsp_legacy_advertiser_start_directed;
    sl_bt_rsp_extended_advertiser_set_phy_t                      rsp_extended_advertiser_set_phy;
    sl_bt_rsp_extended_advertiser_set_data_t                     rsp_extended_advertiser_set_data;
    sl_bt_rsp_extended_advertiser_set_long_data_t                rsp_extended_advertiser_set_long_data;
    sl_bt_rsp_extended_advertiser_generate_data_t                rsp_extended_advertiser_generate_data;
    sl_bt_rsp_extended_advertiser_start_t                        rsp_extended_advertiser_start;
    sl_bt_rsp_extended_advertiser_start_directed_t               rsp_extended_advertiser_start_directed;
    sl_bt_rsp_periodic_advertiser_set_data_t                     rsp_periodic_advertiser_set_data;
    sl_bt_rsp_periodic_advertiser_set_long_data_t                rsp_periodic_advertiser_set_long_data;
    sl_bt_rsp_periodic_advertiser_start_t                        rsp_periodic_advertiser_start;
    sl_bt_rsp_periodic_advertiser_stop_t                         rsp_periodic_advertiser_stop;
    sl_bt_rsp_scanner_set_parameters_t                           rsp_scanner_set_parameters;
    sl_bt_rsp_scanner_set_parameters_and_filter_t                rsp_scanner_set_parameters_and_filter;
    sl_bt_rsp_scanner_start_t                                    rsp_scanner_start;
    sl_bt_rsp_scanner_stop_t                                     rsp_scanner_stop;
    sl_bt_rsp_sync_set_reporting_mode_t                          rsp_sync_set_reporting_mode;
    sl_bt_rsp_sync_update_sync_parameters_t                      rsp_sync_update_sync_parameters;
    sl_bt_rsp_sync_close_t                                       rsp_sync_close;
    sl_bt_rsp_sync_scanner_set_sync_parameters_t                 rsp_sync_scanner_set_sync_parameters;
    sl_bt_rsp_sync_scanner_open_t                                rsp_sync_scanner_open;
    sl_bt_rsp_past_receiver_set_default_sync_receive_parameters_t rsp_past_receiver_set_default_sync_receive_parameters;
    sl_bt_rsp_past_receiver_set_sync_receive_parameters_t        rsp_past_receiver_set_sync_receive_parameters;
    sl_bt_rsp_past_receiver_set_default_sync_receive_over_sync_parameters_t rsp_past_receiver_set_default_sync_receive_over_sync_parameters;
    sl_bt_rsp_past_receiver_set_sync_receive_over_sync_parameters_t rsp_past_receiver_set_sync_receive_over_sync_parameters;
    sl_bt_rsp_advertiser_past_transfer_t                         rsp_advertiser_past_transfer;
    sl_bt_rsp_advertiser_past_transfer_over_pawr_advertiser_t    rsp_advertiser_past_transfer_over_pawr_advertiser;
    sl_bt_rsp_sync_past_transfer_t                               rsp_sync_past_transfer;
    sl_bt_rsp_pawr_sync_set_sync_subevents_t                     rsp_pawr_sync_set_sync_subevents;
    sl_bt_rsp_pawr_sync_set_response_data_t                      rsp_pawr_sync_set_response_data;
    sl_bt_rsp_pawr_advertiser_start_t                            rsp_pawr_advertiser_start;
    sl_bt_rsp_pawr_advertiser_change_parameters_t                rsp_pawr_advertiser_change_parameters;
    sl_bt_rsp_pawr_advertiser_set_subevent_data_t                rsp_pawr_advertiser_set_subevent_data;
    sl_bt_rsp_pawr_advertiser_create_connection_t                rsp_pawr_advertiser_create_connection;
    sl_bt_rsp_pawr_advertiser_stop_t                             rsp_pawr_advertiser_stop;
    sl_bt_rsp_connection_set_default_parameters_t                rsp_connection_set_default_parameters;
    sl_bt_rsp_connection_set_default_preferred_phy_t             rsp_connection_set_default_preferred_phy;
    sl_bt_rsp_connection_set_default_data_length_t               rsp_connection_set_default_data_length;
    sl_bt_rsp_connection_set_default_acceptable_subrate_t        rsp_connection_set_default_acceptable_subrate;
    sl_bt_rsp_connection_open_t                                  rsp_connection_open;
    sl_bt_rsp_connection_open_with_accept_list_t                 rsp_connection_open_with_accept_list;
    sl_bt_rsp_connection_set_parameters_t                        rsp_connection_set_parameters;
    sl_bt_rsp_connection_set_preferred_phy_t                     rsp_connection_set_preferred_phy;
    sl_bt_rsp_connection_disable_slave_latency_t                 rsp_connection_disable_slave_latency;
    sl_bt_rsp_connection_get_median_rssi_t                       rsp_connection_get_median_rssi;
    sl_bt_rsp_connection_read_channel_map_t                      rsp_connection_read_channel_map;
    sl_bt_rsp_connection_set_power_reporting_t                   rsp_connection_set_power_reporting;
    sl_bt_rsp_connection_set_remote_power_reporting_t            rsp_connection_set_remote_power_reporting;
    sl_bt_rsp_connection_get_tx_power_t                          rsp_connection_get_tx_power;
    sl_bt_rsp_connection_get_remote_tx_power_t                   rsp_connection_get_remote_tx_power;
    sl_bt_rsp_connection_set_tx_power_t                          rsp_connection_set_tx_power;
    sl_bt_rsp_connection_read_remote_used_features_t             rsp_connection_read_remote_used_features;
    sl_bt_rsp_connection_get_security_status_t                   rsp_connection_get_security_status;
    sl_bt_rsp_connection_set_data_length_t                       rsp_connection_set_data_length;
    sl_bt_rsp_connection_read_statistics_t                       rsp_connection_read_statistics;
    sl_bt_rsp_connection_get_scheduling_details_t                rsp_connection_get_scheduling_details;
    sl_bt_rsp_connection_get_remote_address_t                    rsp_connection_get_remote_address;
    sl_bt_rsp_connection_request_subrate_t                       rsp_connection_request_subrate;
    sl_bt_rsp_connection_get_state_t                             rsp_connection_get_state;
    sl_bt_rsp_connection_close_t                                 rsp_connection_close;
    sl_bt_rsp_connection_forcefully_close_t                      rsp_connection_forcefully_close;
    sl_bt_rsp_gatt_set_max_mtu_t                                 rsp_gatt_set_max_mtu;
    sl_bt_rsp_gatt_discover_primary_services_t                   rsp_gatt_discover_primary_services;
    sl_bt_rsp_gatt_discover_primary_services_by_uuid_t           rsp_gatt_discover_primary_services_by_uuid;
    sl_bt_rsp_gatt_find_included_services_t                      rsp_gatt_find_included_services;
    sl_bt_rsp_gatt_discover_characteristics_t                    rsp_gatt_discover_characteristics;
    sl_bt_rsp_gatt_discover_characteristics_by_uuid_t            rsp_gatt_discover_characteristics_by_uuid;
    sl_bt_rsp_gatt_discover_descriptors_t                        rsp_gatt_discover_descriptors;
    sl_bt_rsp_gatt_discover_characteristic_descriptors_t         rsp_gatt_discover_characteristic_descriptors;
    sl_bt_rsp_gatt_set_characteristic_notification_t             rsp_gatt_set_characteristic_notification;
    sl_bt_rsp_gatt_send_characteristic_confirmation_t            rsp_gatt_send_characteristic_confirmation;
    sl_bt_rsp_gatt_read_characteristic_value_t                   rsp_gatt_read_characteristic_value;
    sl_bt_rsp_gatt_read_characteristic_value_from_offset_t       rsp_gatt_read_characteristic_value_from_offset;
    sl_bt_rsp_gatt_read_multiple_characteristic_values_t         rsp_gatt_read_multiple_characteristic_values;
    sl_bt_rsp_gatt_read_variable_length_characteristic_values_t  rsp_gatt_read_variable_length_characteristic_values;
    sl_bt_rsp_gatt_read_characteristic_value_by_uuid_t           rsp_gatt_read_characteristic_value_by_uuid;
    sl_bt_rsp_gatt_write_characteristic_value_t                  rsp_gatt_write_characteristic_value;
    sl_bt_rsp_gatt_write_characteristic_value_without_response_t rsp_gatt_write_characteristic_value_without_response;
    sl_bt_rsp_gatt_prepare_characteristic_value_write_t          rsp_gatt_prepare_characteristic_value_write;
    sl_bt_rsp_gatt_prepare_characteristic_value_reliable_write_t rsp_gatt_prepare_characteristic_value_reliable_write;
    sl_bt_rsp_gatt_execute_characteristic_value_write_t          rsp_gatt_execute_characteristic_value_write;
    sl_bt_rsp_gatt_read_descriptor_value_t                       rsp_gatt_read_descriptor_value;
    sl_bt_rsp_gatt_write_descriptor_value_t                      rsp_gatt_write_descriptor_value;
    sl_bt_rsp_gatt_get_mtu_t                                     rsp_gatt_get_mtu;
    sl_bt_rsp_gattdb_new_session_t                               rsp_gattdb_new_session;
    sl_bt_rsp_gattdb_add_service_t                               rsp_gattdb_add_service;
    sl_bt_rsp_gattdb_remove_service_t                            rsp_gattdb_remove_service;
    sl_bt_rsp_gattdb_add_included_service_t                      rsp_gattdb_add_included_service;
    sl_bt_rsp_gattdb_remove_included_service_t                   rsp_gattdb_remove_included_service;
    sl_bt_rsp_gattdb_add_uuid16_characteristic_t                 rsp_gattdb_add_uuid16_characteristic;
    sl_bt_rsp_gattdb_add_uuid128_characteristic_t                rsp_gattdb_add_uuid128_characteristic;
    sl_bt_rsp_gattdb_remove_characteristic_t                     rsp_gattdb_remove_characteristic;
    sl_bt_rsp_gattdb_add_uuid16_descriptor_t                     rsp_gattdb_add_uuid16_descriptor;
    sl_bt_rsp_gattdb_add_uuid128_descriptor_t                    rsp_gattdb_add_uuid128_descriptor;
    sl_bt_rsp_gattdb_remove_descriptor_t                         rsp_gattdb_remove_descriptor;
    sl_bt_rsp_gattdb_start_service_t                             rsp_gattdb_start_service;
    sl_bt_rsp_gattdb_stop_service_t                              rsp_gattdb_stop_service;
    sl_bt_rsp_gattdb_start_characteristic_t                      rsp_gattdb_start_characteristic;
    sl_bt_rsp_gattdb_stop_characteristic_t                       rsp_gattdb_stop_characteristic;
    sl_bt_rsp_gattdb_commit_t                                    rsp_gattdb_commit;
    sl_bt_rsp_gattdb_abort_t                                     rsp_gattdb_abort;
    sl_bt_rsp_gattdb_get_attribute_state_t                       rsp_gattdb_get_attribute_state;
    sl_bt_rsp_gatt_server_set_max_mtu_t                          rsp_gatt_server_set_max_mtu;
    sl_bt_rsp_gatt_server_get_mtu_t                              rsp_gatt_server_get_mtu;
    sl_bt_rsp_gatt_server_find_attribute_t                       rsp_gatt_server_find_attribute;
    sl_bt_rsp_gatt_server_find_primary_service_t                 rsp_gatt_server_find_primary_service;
    sl_bt_rsp_gatt_server_read_attribute_value_t                 rsp_gatt_server_read_attribute_value;
    sl_bt_rsp_gatt_server_read_attribute_type_t                  rsp_gatt_server_read_attribute_type;
    sl_bt_rsp_gatt_server_read_attribute_properties_t            rsp_gatt_server_read_attribute_properties;
    sl_bt_rsp_gatt_server_write_attribute_value_t                rsp_gatt_server_write_attribute_value;
    sl_bt_rsp_gatt_server_send_user_read_response_t              rsp_gatt_server_send_user_read_response;
    sl_bt_rsp_gatt_server_send_user_write_response_t             rsp_gatt_server_send_user_write_response;
    sl_bt_rsp_gatt_server_send_notification_t                    rsp_gatt_server_send_notification;
    sl_bt_rsp_gatt_server_send_notification_with_options_t       rsp_gatt_server_send_notification_with_options;
    sl_bt_rsp_gatt_server_send_indication_t                      rsp_gatt_server_send_indication;
    sl_bt_rsp_gatt_server_send_indication_with_options_t         rsp_gatt_server_send_indication_with_options;
    sl_bt_rsp_gatt_server_notify_all_t                           rsp_gatt_server_notify_all;
    sl_bt_rsp_gatt_server_read_client_configuration_t            rsp_gatt_server_read_client_configuration;
    sl_bt_rsp_gatt_server_send_user_prepare_write_response_t     rsp_gatt_server_send_user_prepare_write_response;
    sl_bt_rsp_gatt_server_set_capabilities_t                     rsp_gatt_server_set_capabilities;
    sl_bt_rsp_gatt_server_enable_capabilities_t                  rsp_gatt_server_enable_capabilities;
    sl_bt_rsp_gatt_server_disable_capabilities_t                 rsp_gatt_server_disable_capabilities;
    sl_bt_rsp_gatt_server_get_enabled_capabilities_t             rsp_gatt_server_get_enabled_capabilities;
    sl_bt_rsp_gatt_server_read_client_supported_features_t       rsp_gatt_server_read_client_supported_features;
    sl_bt_rsp_nvm_save_t                                         rsp_nvm_save;
    sl_bt_rsp_nvm_load_t                                         rsp_nvm_load;
    sl_bt_rsp_nvm_erase_t                                        rsp_nvm_erase;
    sl_bt_rsp_nvm_erase_all_t                                    rsp_nvm_erase_all;
    sl_bt_rsp_test_dtm_tx_v4_t                                   rsp_test_dtm_tx_v4;
    sl_bt_rsp_test_dtm_tx_cw_t                                   rsp_test_dtm_tx_cw;
    sl_bt_rsp_test_dtm_rx_t                                      rsp_test_dtm_rx;
    sl_bt_rsp_test_dtm_end_t                                     rsp_test_dtm_end;
    sl_bt_rsp_sm_configure_t                                     rsp_sm_configure;
    sl_bt_rsp_sm_set_minimum_key_size_t                          rsp_sm_set_minimum_key_size;
    sl_bt_rsp_sm_set_debug_mode_t                                rsp_sm_set_debug_mode;
    sl_bt_rsp_sm_store_bonding_configuration_t                   rsp_sm_store_bonding_configuration;
    sl_bt_rsp_sm_set_bondable_mode_t                             rsp_sm_set_bondable_mode;
    sl_bt_rsp_sm_set_passkey_t                                   rsp_sm_set_passkey;
    sl_bt_rsp_sm_increase_security_t                             rsp_sm_increase_security;
    sl_bt_rsp_sm_enter_passkey_t                                 rsp_sm_enter_passkey;
    sl_bt_rsp_sm_passkey_confirm_t                               rsp_sm_passkey_confirm;
    sl_bt_rsp_sm_bonding_confirm_t                               rsp_sm_bonding_confirm;
    sl_bt_rsp_sm_delete_bonding_t                                rsp_sm_delete_bonding;
    sl_bt_rsp_sm_delete_bondings_t                               rsp_sm_delete_bondings;
    sl_bt_rsp_sm_get_bonding_handles_t                           rsp_sm_get_bonding_handles;
    sl_bt_rsp_sm_get_bonding_details_t                           rsp_sm_get_bonding_details;
    sl_bt_rsp_sm_find_bonding_by_address_t                       rsp_sm_find_bonding_by_address;
    sl_bt_rsp_sm_resolve_rpa_t                                   rsp_sm_resolve_rpa;
    sl_bt_rsp_sm_set_bonding_key_t                               rsp_sm_set_bonding_key;
    sl_bt_rsp_sm_set_legacy_oob_t                                rsp_sm_set_legacy_oob;
    sl_bt_rsp_sm_set_oob_t                                       rsp_sm_set_oob;
    sl_bt_rsp_sm_set_remote_oob_t                                rsp_sm_set_remote_oob;
    sl_bt_rsp_external_bondingdb_set_data_t                      rsp_external_bondingdb_set_data;
    sl_bt_rsp_external_bondingdb_set_local_irk_t                 rsp_external_bondingdb_set_local_irk;
    sl_bt_rsp_resolving_list_add_device_by_bonding_t             rsp_resolving_list_add_device_by_bonding;
    sl_bt_rsp_resolving_list_add_device_by_address_t             rsp_resolving_list_add_device_by_address;
    sl_bt_rsp_resolving_list_remove_device_by_bonding_t          rsp_resolving_list_remove_device_by_bonding;
    sl_bt_rsp_resolving_list_remove_device_by_address_t          rsp_resolving_list_remove_device_by_address;
    sl_bt_rsp_resolving_list_remove_all_devices_t                rsp_resolving_list_remove_all_devices;
    sl_bt_rsp_accept_list_add_device_by_bonding_t                rsp_accept_list_add_device_by_bonding;
    sl_bt_rsp_accept_list_add_device_by_address_t                rsp_accept_list_add_device_by_address;
    sl_bt_rsp_accept_list_remove_device_by_bonding_t             rsp_accept_list_remove_device_by_bonding;
    sl_bt_rsp_accept_list_remove_device_by_address_t             rsp_accept_list_remove_device_by_address;
    sl_bt_rsp_accept_list_remove_all_devices_t                   rsp_accept_list_remove_all_devices;
    sl_bt_rsp_coex_set_options_t                                 rsp_coex_set_options;
    sl_bt_rsp_coex_set_parameters_t                              rsp_coex_set_parameters;
    sl_bt_rsp_coex_set_directional_priority_pulse_t              rsp_coex_set_directional_priority_pulse;
    sl_bt_rsp_coex_get_parameters_t                              rsp_coex_get_parameters;
    sl_bt_rsp_coex_get_counters_t                                rsp_coex_get_counters;
    sl_bt_rsp_cs_security_enable_t                               rsp_cs_security_enable;
    sl_bt_rsp_cs_set_default_settings_t                          rsp_cs_set_default_settings;
    sl_bt_rsp_cs_create_config_t                                 rsp_cs_create_config;
    sl_bt_rsp_cs_remove_config_t                                 rsp_cs_remove_config;
    sl_bt_rsp_cs_set_channel_classification_t                    rsp_cs_set_channel_classification;
    sl_bt_rsp_cs_set_procedure_parameters_t                      rsp_cs_set_procedure_parameters;
    sl_bt_rsp_cs_procedure_enable_t                              rsp_cs_procedure_enable;
    sl_bt_rsp_cs_set_antenna_configuration_t                     rsp_cs_set_antenna_configuration;
    sl_bt_rsp_cs_read_local_supported_capabilities_t             rsp_cs_read_local_supported_capabilities;
    sl_bt_rsp_cs_read_remote_supported_capabilities_t            rsp_cs_read_remote_supported_capabilities;
    sl_bt_rsp_cs_test_start_t                                    rsp_cs_test_start;
    sl_bt_rsp_cs_test_end_t                                      rsp_cs_test_end;
    sl_bt_rsp_l2cap_open_le_channel_t                            rsp_l2cap_open_le_channel;
    sl_bt_rsp_l2cap_send_le_channel_open_response_t              rsp_l2cap_send_le_channel_open_response;
    sl_bt_rsp_l2cap_channel_send_data_t                          rsp_l2cap_channel_send_data;
    sl_bt_rsp_l2cap_channel_send_credit_t                        rsp_l2cap_channel_send_credit;
    sl_bt_rsp_l2cap_close_channel_t                              rsp_l2cap_close_channel;
    sl_bt_rsp_cte_transmitter_set_dtm_parameters_t               rsp_cte_transmitter_set_dtm_parameters;
    sl_bt_rsp_cte_transmitter_clear_dtm_parameters_t             rsp_cte_transmitter_clear_dtm_parameters;
    sl_bt_rsp_cte_transmitter_enable_connection_cte_t            rsp_cte_transmitter_enable_connection_cte;
    sl_bt_rsp_cte_transmitter_disable_connection_cte_t           rsp_cte_transmitter_disable_connection_cte;
    sl_bt_rsp_cte_transmitter_enable_connectionless_cte_t        rsp_cte_transmitter_enable_connectionless_cte;
    sl_bt_rsp_cte_transmitter_disable_connectionless_cte_t       rsp_cte_transmitter_disable_connectionless_cte;
    sl_bt_rsp_cte_transmitter_enable_silabs_cte_t                rsp_cte_transmitter_enable_silabs_cte;
    sl_bt_rsp_cte_transmitter_disable_silabs_cte_t               rsp_cte_transmitter_disable_silabs_cte;
    sl_bt_rsp_cte_receiver_set_dtm_parameters_t                  rsp_cte_receiver_set_dtm_parameters;
    sl_bt_rsp_cte_receiver_clear_dtm_parameters_t                rsp_cte_receiver_clear_dtm_parameters;
    sl_bt_rsp_cte_receiver_set_sync_cte_type_t                   rsp_cte_receiver_set_sync_cte_type;
    sl_bt_rsp_cte_receiver_set_default_sync_receive_parameters_t rsp_cte_receiver_set_default_sync_receive_parameters;
    sl_bt_rsp_cte_receiver_set_sync_receive_parameters_t         rsp_cte_receiver_set_sync_receive_parameters;
    sl_bt_rsp_cte_receiver_configure_t                           rsp_cte_receiver_configure;
    sl_bt_rsp_cte_receiver_enable_connection_cte_t               rsp_cte_receiver_enable_connection_cte;
    sl_bt_rsp_cte_receiver_disable_connection_cte_t              rsp_cte_receiver_disable_connection_cte;
    sl_bt_rsp_cte_receiver_enable_connectionless_cte_t           rsp_cte_receiver_enable_connectionless_cte;
    sl_bt_rsp_cte_receiver_disable_connectionless_cte_t          rsp_cte_receiver_disable_connectionless_cte;
    sl_bt_rsp_cte_receiver_enable_silabs_cte_t                   rsp_cte_receiver_enable_silabs_cte;
    sl_bt_rsp_cte_receiver_disable_silabs_cte_t                  rsp_cte_receiver_disable_silabs_cte;
    sl_bt_rsp_connection_analyzer_start_t                        rsp_connection_analyzer_start;
    sl_bt_rsp_connection_analyzer_stop_t                         rsp_connection_analyzer_stop;
    sl_bt_rsp_user_message_to_target_t                           rsp_user_message_to_target;
    sl_bt_rsp_user_manage_event_filter_t                         rsp_user_manage_event_filter;
    sl_bt_rsp_user_cs_service_message_to_target_t                rsp_user_cs_service_message_to_target;
    sl_bt_evt_dfu_boot_t                                         evt_dfu_boot;
    sl_bt_evt_dfu_boot_failure_t                                 evt_dfu_boot_failure;
    sl_bt_evt_system_boot_t                                      evt_system_boot;
    sl_bt_evt_system_error_t                                     evt_system_error;
    sl_bt_evt_system_resource_exhausted_t                        evt_system_resource_exhausted;
    sl_bt_evt_system_external_signal_t                           evt_system_external_signal;
    sl_bt_evt_system_soft_timer_t                                evt_system_soft_timer;
    sl_bt_evt_resource_status_t                                  evt_resource_status;
    sl_bt_evt_advertiser_timeout_t                               evt_advertiser_timeout;
    sl_bt_evt_advertiser_scan_request_t                          evt_advertiser_scan_request;
    sl_bt_evt_periodic_advertiser_status_t                       evt_periodic_advertiser_status;
    sl_bt_evt_scanner_legacy_advertisement_report_t              evt_scanner_legacy_advertisement_report;
    sl_bt_evt_scanner_extended_advertisement_report_t            evt_scanner_extended_advertisement_report;
    sl_bt_evt_sync_closed_t                                      evt_sync_closed;
    sl_bt_evt_periodic_sync_opened_t                             evt_periodic_sync_opened;
    sl_bt_evt_periodic_sync_transfer_received_t                  evt_periodic_sync_transfer_received;
    sl_bt_evt_periodic_sync_report_t                             evt_periodic_sync_report;
    sl_bt_evt_pawr_sync_opened_t                                 evt_pawr_sync_opened;
    sl_bt_evt_pawr_sync_transfer_received_t                      evt_pawr_sync_transfer_received;
    sl_bt_evt_pawr_sync_subevent_report_t                        evt_pawr_sync_subevent_report;
    sl_bt_evt_pawr_advertiser_subevent_data_request_t            evt_pawr_advertiser_subevent_data_request;
    sl_bt_evt_pawr_advertiser_subevent_tx_failed_t               evt_pawr_advertiser_subevent_tx_failed;
    sl_bt_evt_pawr_advertiser_response_report_t                  evt_pawr_advertiser_response_report;
    sl_bt_evt_connection_opened_t                                evt_connection_opened;
    sl_bt_evt_connection_parameters_t                            evt_connection_parameters;
    sl_bt_evt_connection_set_parameters_failed_t                 evt_connection_set_parameters_failed;
    sl_bt_evt_connection_phy_status_t                            evt_connection_phy_status;
    sl_bt_evt_connection_get_remote_tx_power_completed_t         evt_connection_get_remote_tx_power_completed;
    sl_bt_evt_connection_tx_power_t                              evt_connection_tx_power;
    sl_bt_evt_connection_remote_tx_power_t                       evt_connection_remote_tx_power;
    sl_bt_evt_connection_remote_used_features_t                  evt_connection_remote_used_features;
    sl_bt_evt_connection_data_length_t                           evt_connection_data_length;
    sl_bt_evt_connection_statistics_t                            evt_connection_statistics;
    sl_bt_evt_connection_request_subrate_failed_t                evt_connection_request_subrate_failed;
    sl_bt_evt_connection_subrate_changed_t                       evt_connection_subrate_changed;
    sl_bt_evt_connection_closed_t                                evt_connection_closed;
    sl_bt_evt_gatt_mtu_exchanged_t                               evt_gatt_mtu_exchanged;
    sl_bt_evt_gatt_service_t                                     evt_gatt_service;
    sl_bt_evt_gatt_characteristic_t                              evt_gatt_characteristic;
    sl_bt_evt_gatt_descriptor_t                                  evt_gatt_descriptor;
    sl_bt_evt_gatt_characteristic_value_t                        evt_gatt_characteristic_value;
    sl_bt_evt_gatt_descriptor_value_t                            evt_gatt_descriptor_value;
    sl_bt_evt_gatt_procedure_completed_t                         evt_gatt_procedure_completed;
    sl_bt_evt_gatt_server_attribute_value_t                      evt_gatt_server_attribute_value;
    sl_bt_evt_gatt_server_user_read_request_t                    evt_gatt_server_user_read_request;
    sl_bt_evt_gatt_server_user_write_request_t                   evt_gatt_server_user_write_request;
    sl_bt_evt_gatt_server_characteristic_status_t                evt_gatt_server_characteristic_status;
    sl_bt_evt_gatt_server_execute_write_completed_t              evt_gatt_server_execute_write_completed;
    sl_bt_evt_gatt_server_indication_timeout_t                   evt_gatt_server_indication_timeout;
    sl_bt_evt_gatt_server_notification_tx_completed_t            evt_gatt_server_notification_tx_completed;
    sl_bt_evt_test_dtm_completed_t                               evt_test_dtm_completed;
    sl_bt_evt_sm_passkey_display_t                               evt_sm_passkey_display;
    sl_bt_evt_sm_passkey_request_t                               evt_sm_passkey_request;
    sl_bt_evt_sm_confirm_passkey_t                               evt_sm_confirm_passkey;
    sl_bt_evt_sm_bonded_t                                        evt_sm_bonded;
    sl_bt_evt_sm_bonding_failed_t                                evt_sm_bonding_failed;
    sl_bt_evt_sm_confirm_bonding_t                               evt_sm_confirm_bonding;
    sl_bt_evt_external_bondingdb_data_request_t                  evt_external_bondingdb_data_request;
    sl_bt_evt_external_bondingdb_data_t                          evt_external_bondingdb_data;
    sl_bt_evt_external_bondingdb_data_ready_t                    evt_external_bondingdb_data_ready;
    sl_bt_evt_external_bondingdb_local_irk_t                     evt_external_bondingdb_local_irk;
    sl_bt_evt_cs_security_enable_complete_t                      evt_cs_security_enable_complete;
    sl_bt_evt_cs_config_complete_t                               evt_cs_config_complete;
    sl_bt_evt_cs_procedure_enable_complete_t                     evt_cs_procedure_enable_complete;
    sl_bt_evt_cs_result_t                                        evt_cs_result;
    sl_bt_evt_cs_result_continue_t                               evt_cs_result_continue;
    sl_bt_evt_cs_read_remote_supported_capabilities_complete_t   evt_cs_read_remote_supported_capabilities_complete;
    sl_bt_evt_cs_test_end_completed_t                            evt_cs_test_end_completed;
    sl_bt_evt_l2cap_le_channel_open_request_t                    evt_l2cap_le_channel_open_request;
    sl_bt_evt_l2cap_le_channel_open_response_t                   evt_l2cap_le_channel_open_response;
    sl_bt_evt_l2cap_channel_data_t                               evt_l2cap_channel_data;
    sl_bt_evt_l2cap_channel_credit_t                             evt_l2cap_channel_credit;
    sl_bt_evt_l2cap_channel_closed_t                             evt_l2cap_channel_closed;
    sl_bt_evt_l2cap_command_rejected_t                           evt_l2cap_command_rejected;
    sl_bt_evt_cte_receiver_dtm_iq_report_t                       evt_cte_receiver_dtm_iq_report;
    sl_bt_evt_cte_receiver_connection_iq_report_t                evt_cte_receiver_connection_iq_report;
    sl_bt_evt_cte_receiver_connectionless_iq_report_t            evt_cte_receiver_connectionless_iq_report;
    sl_bt_evt_cte_receiver_silabs_iq_report_t                    evt_cte_receiver_silabs_iq_report;
    sl_bt_evt_connection_analyzer_report_t                       evt_connection_analyzer_report;
    sl_bt_evt_connection_analyzer_completed_t                    evt_connection_analyzer_completed;
    sl_bt_evt_user_message_to_host_t                             evt_user_message_to_host;
    sl_bt_evt_user_cs_service_message_to_host_t                  evt_user_cs_service_message_to_host;
    uint8_t payload[SL_BGAPI_MAX_PAYLOAD_SIZE];
  } data;
});

#ifdef __cplusplus
}
#endif

#endif