idf_component_register( NAME "wifi_sta"
                        SRCS "wifi_sta.c"
                        INCLUDE_DIRS "."
                        REQUIRES "nvs_flash esp_wifi")
