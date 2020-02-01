#include <lcom/lcf.h>

#include <stdint.h>

int(util_get_LSB)(uint16_t val, uint8_t *lsb) {
  *lsb =(uint8_t)(val & 0xFF);
  return 0;
}

int(util_get_MSB)(uint16_t val, uint8_t *msb) {
  *msb = (uint8_t)((val & 0xFF00)>>8);
  return 0;
}

int (util_sys_inb)(int port, uint8_t *value) {

  //converting uint8_t RB command to a uint32_t
  uint32_t rb_command_32b = (uint32_t)*value;

  //getting the status with sys function - using a uint32_t
  if(sys_inb(port, &rb_command_32b) == OK){
    //now the rb_command_32b is the status; We need to truncate it to a uint8_t 
    *value = (uint8_t) rb_command_32b;
    return 0;
  }
  else
    return 1;
}
