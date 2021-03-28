if(${CONFIG_SOC_SERIES} MATCHES "efr32[fbm]g([0-9]+)[pbv]")
	set(RAIL_LIB_STATIC_NAME "librail_efr32xg${CMAKE_MATCH_1}")
else()
	message(FATAL_ERROR "Unable to guess SiLabs Wireless Gecko static library name from ${CONFIG_SOC_SERIES}")
endif()

message(STATUS "RAIL: ${RAIL_LIB_STATIC_NAME}")

set(RAIL_LIB_STATIC_PATH autogen/librail_release/${RAIL_LIB_STATIC_NAME}_gcc_release.a)
zephyr_library_import(rail_lib_static ${CMAKE_CURRENT_SOURCE_DIR}/${RAIL_LIB_STATIC_PATH})

zephyr_interface_library_named(RAIL_LIB)

target_include_directories(RAIL_LIB INTERFACE
	common/
	chip/efr32/efr32xg1x/
)

target_include_directories_ifdef(CONFIG_SOC_GECKO_RAIL_LIB_IEEE802154 RAIL_LIB INTERFACE
	protocol/ieee802154/
)
