/*
 * Copyright (C) 2015-2017 Erin Tomson <erin@rgba.net>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BOOTLOADER_H_
#define BOOTLOADER_H_

#include <stdint.h>
#include "otp.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void runBootloader();
void ClockInit();
void ClockDeinit();
OTP_v5 GetOTPData();

#ifdef __cplusplus
}
#endif

#endif /* BOOTLOADER_H_ */
