/*
 *   Copyright (C) 2015,2016,2017 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if !defined(P25RX_H)
#define  P25RX_H

#include "P25Defines.h"

enum P25RX_STATE {
  P25RXS_NONE,
  P25RXS_DATA
};

class CP25RX {
public:
  CP25RX();

  void databit(bool bit);

  void reset();

private:
  bool        m_prev;
  P25RX_STATE m_state;
  uint64_t    m_bitBuffer;
  uint8_t     m_outBuffer[P25_LDU_FRAME_LENGTH_BYTES + 3U];
  uint8_t*    m_buffer;
  uint16_t    m_bufferPtr;
  uint16_t    m_lostCount;

  void processNone(bool bit);
  void processData(bool bit);

};

#endif

