idf_component_register(
    SRCS "src/spi_send.c"
    INCLUDE_DIRS "include"
    PRIV_REQUIRES esp_driver_spi esp_driver_gpio esp_timer my_hid_host
)