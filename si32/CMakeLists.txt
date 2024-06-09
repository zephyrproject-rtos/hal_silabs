zephyr_include_directories(
  si32Hal/sim3u1xx
  si32Hal/SI32_Modules
  )

zephyr_sources_ifdef(CONFIG_SOC_SERIES_SIM3U
  si32Hal/sim3u1xx/SI32_PBCFG_A_Type.c
  si32Hal/SI32_Modules/SI32_SPI_A_Type.c
  )
