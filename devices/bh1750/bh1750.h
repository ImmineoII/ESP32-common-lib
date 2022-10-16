
/**
 * @file     bh1750.c
 * @author   Eric Boccati - Nicholas Polledri
 * @version  1.1
 * @date     24-08-2022
 * 
 * @brief    ESP-IDF driver for BH1750
 */

#include <stdint.h>
#include <esp_err.h>


// I2C Operation Codes
#define BH1750_OPCODE_HIGH 0x0 
#define BH1750_OPCODE_MEDIUM 0x1
#define BH1750_OPCODE_LOW 0x3
#define BH1750_OPCODE_CONT 0x10
#define BH1750_OPCODE_OT 0x20
#define BH1750_OPCODE_POWER_DOWN 0x00
#define BH1750_OPCODE_POWER_ON 0x01
#define BH1750_OPCODE_MT_HI 0x40
#define BH1750_OPCODE_MT_LO 0x60


typedef struct
{
    uint8_t address;
    i2c_port_t i2c_master_port;
} bh1750_t;


typedef enum
{
    BH1750_MODE_ONE_TIME = 0,
    BH1750_MODE_CONTINIOUS
} bh1750_mode_t;

typedef enum
{
    BH1750_RES_LOW = 0, // Resolution 4 lx, measurement time 16 ms
    BH1750_RES_MEDIUM,    // Resolution 1 lx, measurement time 120 ms
    BH1750_RES_HIGH    // Resolution 0.5 lx, measurement time 120 ms
} bh1750_resolution_t;


esp_err_t bh1750_setup(bh1750_t device, bh1750_mode_t mode, bh1750_resolution_t resolution);
esp_err_t bh1750_read(bh1750_t device, uint16_t *level);
esp_err_t bh1750_power_down(bh1750_t device);
esp_err_t bh1750_power_on(bh1750_t device);
esp_err_t bh1750_set_measurement_time(bh1750_t device, uint8_t time);