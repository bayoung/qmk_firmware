#ifndef ERGODOX_EZ_H
#define ERGODOX_EZ_H

#include "quantum.h"
#include <stdint.h>
#include <stdbool.h>
#include "i2c_master.h"
#include <util/delay.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00

// I2C aliases and register addresses (see "mcp23018.md")
#define I2C_ADDR        0b0100000
#define I2C_ADDR_WRITE  ( (I2C_ADDR<<1) | I2C_WRITE )
#define I2C_ADDR_READ   ( (I2C_ADDR<<1) | I2C_READ  )
#define IODIRA          0x00            // i/o direction register
#define IODIRB          0x01
#define GPPUA           0x0C            // GPIO pull-up resistor register
#define GPPUB           0x0D
#define GPIOA           0x12            // general purpose i/o port register (write modifies OLAT)
#define GPIOB           0x13
#define OLATA           0x14            // output latch register
#define OLATB           0x15

extern i2c_status_t mcp23018_status;
#define ERGODOX_EZ_I2C_TIMEOUT 100

void init_ergodox(void);
uint8_t init_mcp23018(void);

#define LAYOUT( \
    k50, \
    k40, k41, k42, k43, k44, k45, k46,          k47, k48, k49, k410, k411, k412, k413, \
    k30, k31, k32, k33, k34, k35,               k37, k38, k39, k310, k311, k312, k313, k314, \
              k22, k23, k24, k25, k26,          k27, k28, k29, k210, k211, k212, k213, \
         k11, k12, k13, k14, k15, k16,               k18, k19, k110, k111, k112, k113, k114, \
    k00, k01, k02, k03,      k05,                         k09,             k012, k013, k014) \
    { \
        { KC_NO, k47, k37, k27, KC_NO, KC_NO, KC_NO, KC_NO }, \
        { KC_NO, k48, k38, k28, k18, KC_NO, KC_NO, KC_NO }, \
        { KC_NO, k49, k39, k29, k19, k09, KC_NO, KC_NO }, \
        { KC_NO, k410, k310, k210, k110, KC_NO, KC_NO, KC_NO }, \
        { KC_NO, k411, k311, k211, k111, KC_NO, KC_NO, KC_NO }, \
        { KC_NO, k412, k312, k212, k112, k012, KC_NO, KC_NO }, \
        { KC_NO, k413, k313, k213, k113, k013, KC_NO, KC_NO }, \
        { KC_NO, KC_NO, k314, KC_NO, k114, k014, KC_NO, KC_NO }, \
        \
        { k50, k40, k30, KC_NO, KC_NO, k00, KC_NO, KC_NO }, \
        { KC_NO, k41, k31, KC_NO, k11, k01, KC_NO, KC_NO }, \
        { KC_NO, k42, k32, k22, k12, k02, KC_NO, KC_NO }, \
        { KC_NO, k43, k33, k23, k13, k03, KC_NO, KC_NO }, \
        { KC_NO, k44, k34, k24, k14, KC_NO, KC_NO, KC_NO }, \
        { KC_NO, k45, k35, k25, k15, k05, KC_NO, KC_NO }, \
        { KC_NO, k46, KC_NO, k26, k16, KC_NO, KC_NO, KC_NO }, \
        { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
    }
/*
TODO remove extra "columns"
        { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
        { k47,   k48,   k49,   k410,  k411,  k412,  k413,  KC_NO }, \
        { k37,   k38,   k39,   k310,  k311,  k312,  k313,  k314 }, \
        { k27,   k28,   k29,   k210,  k211,  k212,  k213,  KC_NO }, \
        { KC_NO, k18,   k19,   k110,  k111,  k112,  k113,  k114 }, \
        { KC_NO, KC_NO, k09,   KC_NO, KC_NO, k012,  k013,  k014 }, \
        { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \



        { k50, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
        { k40, k41,   k42,   k43,   k44,   k45,   k46, KC_NO }, \
        { k30, k31, k32, k33, k34, k35, KC_NO, KC_NO }, \
        { KC_NO, KC_NO, k22, k23, k24, k25, k26, KC_NO }, \
        { KC_NO, k11, k12, k13, k14, k15, k16, KC_NO }, \
        { k00, k01, k02, k03, KC_NO, k05, KC_NO, KC_NO }, \
        { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
        { k47,   k48,   k49,   k410,  k411,  k412,  k413,  KC_NO }, \
        { k37,   k38,   k39,   k310,  k311,  k312,  k313,  k314 }, \
        { k27,   k28,   k29,   k210,  k211,  k212,  k213,  KC_NO }, \
        { KC_NO, k18,   k19,   k110,  k111,  k112,  k113,  k114 }, \
        { KC_NO, KC_NO, k09,   KC_NO, KC_NO, k012,  k013,  k014 } \
*/
#endif
