zephyr_include_directories(
  si32Hal/sim3u1xx
  si32Hal/SI32_Modules
  )

if(CONFIG_SOC_SERIES_SIM3U)
  zephyr_sources(si32Hal/sim3u1xx/SI32_PBCFG_A_Type.c)
  zephyr_sources_ifdef(CONFIG_DMA si32Hal/sim3u1xx/SI32_DMAXBAR_A_Type.c)
  zephyr_sources_ifdef(CONFIG_DMA si32Hal/SI32_Modules/SI32_DMADESC_A_Type.c)
  zephyr_sources_ifdef(CONFIG_SPI si32Hal/SI32_Modules/SI32_SPI_A_Type.c)
endif()
