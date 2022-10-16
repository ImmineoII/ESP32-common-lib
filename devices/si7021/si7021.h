/**
 * @file     si7021.h
 * @author   Eric Boccati - Nicholas Polledri
 * @version  1.1
 * @date     07-09-2022
 * 
 * @brief    ESP-IDF driver for Si7021
 */

#include <stdint.h>
#include <esp_err.h>

typedef enum
{
    SI7021_RES_HIGH2 = 0, // Temp resolution 14 bit, RH 12 bit
    SI7021_RES_HIGH,      // Temp resolution 12 bit, RH 8 bit
    SI7021_RES_HIGH1,     // Temp resolution 13 bit, RH 10 bit
    SI7021_RES_LOW        // Temp resolution 11 bit, RH 11 bit

} si7021_resolution_t;

typedef enum
{
    SI7021_CELSIUS = 0,
    SI7021_FAHRENHEIT
} s7021_temp_measure_unit_t;

typedef struct
{
    uint8_t address;
    i2c_port_t i2c_master_port;
    s7021_temp_measure_unit_t temperature_measure_unit;
} si7021_t;


#define SI7021_RESOLUTION SI7021_RES_HIGH2 // Temperature and humidity sensor resolution

#define SI7021_COMMAND_READ_RH 0xF5 // I2C Operation Codes
#define SI7021_COMMAND_READ_TEMP 0xF3
#define SI7021_COMMAND_READ_TEMP_AFTER_RH 0xE0
#define SI7021_REG_WRITE 0xE6
#define SI7021_REG_READ 0xE7
#define SI7021_RESET 0xFE

esp_err_t si7021_setup(si7021_t device, si7021_resolution_t resolution);
esp_err_t si7021_write_register(si7021_t device, uint8_t settings);
esp_err_t si7021_read_register(si7021_t device, uint8_t *output);
esp_err_t si7021_measure(si7021_t device, float *temperature, float *humidity);
esp_err_t si7021_read_temperature(si7021_t device, float *temperature);
esp_err_t si7021_read_temperature_after_humidity(si7021_t device, float *temperature);
esp_err_t si7021_read_humidity(si7021_t device, float *humidity);