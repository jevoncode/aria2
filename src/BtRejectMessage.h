/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#ifndef _D_BT_REJECT_MESSAGE_H_
#define _D_BT_REJECT_MESSAGE_H_

#include "SimpleBtMessage.h"

class BtRejectMessage;

typedef SharedHandle<BtRejectMessage> BtRejectMessageHandle;

class BtRejectMessage : public SimpleBtMessage {
private:
  int32_t index;
  int32_t begin;
  int32_t length;
  unsigned char* msg;
  static int32_t MESSAGE_LENGTH;
public:
  BtRejectMessage(int32_t index = 0, int32_t begin = 0, int32_t length = 0)
    :index(index),
     begin(begin),
     length(length),
     msg(0) {}

  virtual ~BtRejectMessage() {
    delete [] msg;
  }

  static const int8_t ID = 16;

  int32_t getIndex() const { return index; }
  void setIndex(int32_t index) { this->index = index; }

  int32_t getBegin() const { return begin; }
  void setBegin(int32_t begin) { this->begin = begin; }

  int32_t getLength() const { return length; }
  void setLength(int32_t length) { this->length = length; }

  static BtRejectMessageHandle create(const unsigned char* data, int32_t dataLength);

  virtual int8_t getId() { return ID; }

  virtual void doReceivedAction();

  virtual const unsigned char* getMessage();

  virtual int32_t getMessageLength();

  virtual string toString() const;
};

#endif // _D_BT_REJECT_MESSAGE_H_
