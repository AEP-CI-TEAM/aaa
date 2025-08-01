# Define minimal required version of CMake.
cmake_minimum_required(VERSION "3.25")

# Project definition
project(
	bt_soc_blinky
	VERSION 1.0
	LANGUAGES C CXX ASM
)

# Include the definition of the slc_bt_soc_blinky target,
# which contains the content of the SLC project
include(bt_soc_blinky.cmake)

add_executable(bt_soc_blinky
    # Add additional sources here
)

target_include_directories(bt_soc_blinky PUBLIC
    # Add additional include paths here
)

target_compile_definitions(bt_soc_blinky PUBLIC
    # Add additional macros here
)

target_compile_options(bt_soc_blinky PUBLIC
    # Set additional compiler flags here
)

target_link_options(bt_soc_blinky PUBLIC
    # Set additional linker flags here
)

# Link with the content defined in the SLC project
target_link_libraries(bt_soc_blinky PRIVATE
    slc_bt_soc_blinky
)

# Include managed project content if available
include(bt_soc_blinky_project.cmake OPTIONAL RESULT_VARIABLE managed_project)
if(managed_project)
    message(STATUS "Using managed project content from ${managed_project}")
endif()

# Force the gcc linker command
set_target_properties(bt_soc_blinky PROPERTIES LINKER_LANGUAGE C)

# Create .bin, .hex and .s37 artifacts after building the project
add_custom_command(TARGET bt_soc_blinky
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} ${OBJCOPY_SREC_CMD} "$<TARGET_FILE:bt_soc_blinky>" "$<TARGET_FILE_DIR:bt_soc_blinky>/$<TARGET_FILE_BASE_NAME:bt_soc_blinky>.s37"
    COMMAND ${CMAKE_OBJCOPY} ${OBJCOPY_IHEX_CMD} "$<TARGET_FILE:bt_soc_blinky>" "$<TARGET_FILE_DIR:bt_soc_blinky>/$<TARGET_FILE_BASE_NAME:bt_soc_blinky>.hex"
    COMMAND ${CMAKE_OBJCOPY} ${OBJCOPY_BIN_CMD}  "$<TARGET_FILE:bt_soc_blinky>" "$<TARGET_FILE_DIR:bt_soc_blinky>/$<TARGET_FILE_BASE_NAME:bt_soc_blinky>.bin" 
)

# Run post-build pipeline to perform additional post-processing
if(post_build_command)
add_custom_command(TARGET bt_soc_blinky
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/..
    COMMAND ${post_build_command}
)
endif()