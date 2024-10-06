idf_component_register(
    SRCS "src/my_hid_host.c"
    INCLUDE_DIRS "include"
    PRIV_REQUIRES usb esp_driver_gpio espressif__usb_host_hid
)