#include "main.h"
#include "stm32f1xx_hal_i2c.h"
#include <stdint.h>

#define TIMEOUT 1000

typedef struct {
  I2C_HandleTypeDef *ina219_i2c;
  uint8_t Addr;
} i2c_dir;

typedef struct {
  uint8_t addres;
  uint8_t config;
  uint8_t shuntvolt;
  uint8_t busvolt;
  uint8_t power;
  uint8_t current;
  uint8_t calibr;
  uint8_t reset;
} addr_t;

uint8_t ina219_init(i2c_dir *INA219, I2C_HandleTypeDef *i2c, uint8_t addr);
uint8_t ina219_reset(i2c_dir *INA219);
uint16_t w_reg(i2c_dir *INA219, uint8_t Reg, uint16_t Val);
uint16_t r_reg(i2c_dir *INA219, uint8_t Reg);
