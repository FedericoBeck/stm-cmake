#include "ina219.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_def.h"
#include "stm32f1xx_hal_i2c.h"
#include <stdint.h>

addr_t ina219 = {
    .addres = 0x44,
    .config = 0x00,
    .shuntvolt = 0x01,
    .busvolt = 0x02,
    .power = 0x03,
    .current = 0x04,
    .calibr = 0x05,
    .reset = 0x8000,
};

ina219_init(i2c_dir *INA219, I2C_HandleTypeDef *i2c, uint8_t addr) {
  INA219->ina219_i2c = i2c;
  INA219->Addr = addr;

  uint8_t i2c_test = HAL_I2C_IsDeviceReady(i2c, (addr << 1), 3, 2);

  if (i2c_test == HAL_OK) {
    ina219_reset(INA219);

    return 1;

  }

  else {
  }
}
ina219_reset(i2c_dir *INA219) {
  w_reg(INA219, ina219.config, ina219.reset);
  HAL_Delay(1);
}

w_reg(i2c_dir *INA219, uint8_t Reg, uint16_t Val) {
  uint8_t addr[2];
  addr[0] = (Val >> 8) & 0xff; // Byte mas significativoI
  addr[1] = (Val >> 0) & 0xff; // Byte menos significativo
  HAL_I2C_Mem_Write(INA219->ina219_i2c, (ina219.addres << 1), Reg, 1,
                    (uint8_t *)addr, 1, TIMEOUT);
}
