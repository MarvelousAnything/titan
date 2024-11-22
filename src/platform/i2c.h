/**
 * This file is part of the Titan Flight Computer Project
 * Copyright (c) 2024 UW SARP
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * 
 * @file common/platform/i2c.h
 * @authors Joshua Beard
 * @brief Driver for the I2C
 */

#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "tal/mask.h"

#if defined(__cplusplus)
  extern "C" {
#endif

volatile int32_t* I2C_1_Base = 0x40005400;
// I2C_CR1 offset = 0
int32_t I2C_TIMINGR_OFFSET = 16;


void enable_I2C();

void enable_I2C()
{
    // TODO enable clock
    
    tal_write_mask_u32(0, I2C_1_Base, 0, 1); // clear PE bit
    
    // for now disable digital and analog noise filters, we can chose to have these later
    tal_write_mask_u32(0, I2C_1_Base, 8, 4);
    tal_write_mask_u32(0, I2C_1_Base, 12, 1);

    int32_t timing = 0x00707CBB; // generated by STMCube
    tal_write_mask_u32(timing, I2C_1_Base + I2C_TIMINGR_OFFSET, 0, 32);

    tal_write_mask_u32(1, I2C_1_Base, 0, 1); // set PE bit to 1 enabling I2C
}


#if defined(__cplusplus)
  }
#endif