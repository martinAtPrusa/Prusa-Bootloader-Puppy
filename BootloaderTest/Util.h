/*
Copyright 2017 3devo (www.3devo.eu)

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <SoftWire.h>
#include <ArduinoUnit.h>
#include <util/crc16.h>
#include "Constants.h"

#pragma once
// These are macros, so the caller's line number info and expressions
// are preserved
#define assertAck(result, ...) assertEqual(result, SoftWire::ack, ## __VA_ARGS__)
#define assertOk(status, ...) assertEqual(status, Status::COMMAND_OK, ## __VA_ARGS__)

/**
 * Helper class to calculate crcs for transfers. To use it, create an
 * instance, call update() for each byte and/or buffer of bytes to
 * calculate the CRC over, and then call get() to get the result.
 * update() is chainable, so you can do e.g.:
 *
 *   uint8_t crc = Crc().update(first_byte).update(rest_of_bytes, len).get();
 */
class Crc {
  public:
    Crc& update(uint8_t b) {
      this->crc = _crc8_ccitt_update(this->crc, b);
      return *this;
    }

    Crc& update(uint8_t *buf, uint8_t len) {
      for (uint8_t i = 0; i < len; ++i)
        this->update(buf[i]);
      return *this;
    }
    uint8_t get() {
      return this->crc;
    }

  private:
    uint8_t crc = 0xff;
};
