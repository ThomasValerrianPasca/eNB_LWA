/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.0  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#include "TLVEncoder.h"
#include "TLVDecoder.h"
#include "GprsTimer.h"

static const long _gprs_timer_unit[] = {2, 60, 360, 60, 60, 60, 60, 0};

int decode_gprs_timer(GprsTimer *gprstimer, uint8_t iei, uint8_t *buffer, uint32_t len)
{
  int decoded = 0;

  if (iei > 0) {
    CHECK_IEI_DECODER(iei, *buffer);
    decoded++;
  }

  gprstimer->unit = (*(buffer + decoded) >> 5) & 0x7;
  gprstimer->timervalue = *(buffer + decoded) & 0x1f;
  decoded++;
#if defined (NAS_DEBUG)
  dump_gprs_timer_xml(gprstimer, iei);
#endif
  return decoded;
}

int encode_gprs_timer(GprsTimer *gprstimer, uint8_t iei, uint8_t *buffer, uint32_t len)
{
  uint32_t encoded = 0;
  /* Checking IEI and pointer */
  CHECK_PDU_POINTER_AND_LENGTH_ENCODER(buffer, GPRS_TIMER_MINIMUM_LENGTH, len);
#if defined (NAS_DEBUG)
  dump_gprs_timer_xml(gprstimer, iei);
#endif

  if (iei > 0) {
    *buffer = iei;
    encoded++;
  }

  *(buffer + encoded) = 0x00 | ((gprstimer->unit & 0x7) << 5) |
                        (gprstimer->timervalue & 0x1f);
  encoded++;
  return encoded;
}

void dump_gprs_timer_xml(GprsTimer *gprstimer, uint8_t iei)
{
  printf("<Gprs Timer>\n");

  if (iei > 0)
    /* Don't display IEI if = 0 */
    printf("    <IEI>0x%X</IEI>\n", iei);

  printf("    <Unit>%u</Unit>\n", gprstimer->unit);
  printf("    <Timer value>%u</Timer value>\n", gprstimer->timervalue);
  printf("</Gprs Timer>\n");
}

long gprs_timer_value(GprsTimer *gprstimer)
{
  return (gprstimer->timervalue * _gprs_timer_unit[gprstimer->unit]);
}

