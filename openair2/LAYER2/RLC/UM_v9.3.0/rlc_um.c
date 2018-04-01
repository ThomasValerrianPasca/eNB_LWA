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

#define RLC_UM_MODULE 1
#define RLC_UM_C 1
//-----------------------------------------------------------------------------
//#include "rtos_header.h"
#include "platform_types.h"
#include "platform_constants.h"
//-----------------------------------------------------------------------------
#if ENABLE_ITTI
# include "intertask_interface.h"
#endif
#include "assertions.h"
#include "msc.h"
#include "rlc_um.h"
#include "list.h"
#include "rlc_primitives.h"
#include "mac_primitives.h"
#include "LAYER2/MAC/extern.h"
#include "UTIL/LOG/log.h"

//our header file

#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<errno.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<sys/ioctl.h>

#include<net/if.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/if_ether.h>
#include<netinet/udp.h>

#include<linux/if_packet.h>
//our header files

//our defination Wifi Mac address
//#define DESTMAC0 0xec
//#define DESTMAC1 0x08
//#define DESTMAC2 0x6b
//#define DESTMAC3 0x0d
//#define DESTMAC4 0x8e
//#define DESTMAC5 0xbe

#define DESTMAC0 0x90
#define DESTMAC1 0x1b
#define DESTMAC2 0x0e
#define DESTMAC3 0xa6
#define DESTMAC4 0x52
#define DESTMAC5 0x01

//our derfinations

#include "rlc_um_very_simple_test.h"
int jk=1;
int sock_raw;
//-----------------------------------------------------------------------------
void rlc_um_stat_req     (rlc_um_entity_t *rlc_pP,
		unsigned int* stat_tx_pdcp_sdu,
		unsigned int* stat_tx_pdcp_bytes,
		unsigned int* stat_tx_pdcp_sdu_discarded,
		unsigned int* stat_tx_pdcp_bytes_discarded,
		unsigned int* stat_tx_data_pdu,
		unsigned int* stat_tx_data_bytes,
		unsigned int* stat_rx_pdcp_sdu,
		unsigned int* stat_rx_pdcp_bytes,
		unsigned int* stat_rx_data_pdus_duplicate,
		unsigned int* stat_rx_data_bytes_duplicate,
		unsigned int* stat_rx_data_pdu,
		unsigned int* stat_rx_data_bytes,
		unsigned int* stat_rx_data_pdu_dropped,
		unsigned int* stat_rx_data_bytes_dropped,
		unsigned int* stat_rx_data_pdu_out_of_window,
		unsigned int* stat_rx_data_bytes_out_of_window,
		unsigned int* stat_timer_reordering_timed_out)
{
	*stat_tx_pdcp_sdu                     = rlc_pP->stat_tx_pdcp_sdu;
	*stat_tx_pdcp_bytes                   = rlc_pP->stat_tx_pdcp_bytes;
	*stat_tx_pdcp_sdu_discarded           = rlc_pP->stat_tx_pdcp_sdu_discarded;
	*stat_tx_pdcp_bytes_discarded         = rlc_pP->stat_tx_pdcp_bytes_discarded;
	*stat_tx_data_pdu                     = rlc_pP->stat_tx_data_pdu;
	*stat_tx_data_bytes                   = rlc_pP->stat_tx_data_bytes;
	*stat_rx_pdcp_sdu                     = rlc_pP->stat_rx_pdcp_sdu;
	*stat_rx_pdcp_bytes                   = rlc_pP->stat_rx_pdcp_bytes;
	*stat_rx_data_pdus_duplicate          = rlc_pP->stat_rx_data_pdus_duplicate;
	*stat_rx_data_bytes_duplicate         = rlc_pP->stat_rx_data_bytes_duplicate;
	*stat_rx_data_pdu                     = rlc_pP->stat_rx_data_pdu;
	*stat_rx_data_bytes                   = rlc_pP->stat_rx_data_bytes;
	*stat_rx_data_pdu_dropped             = rlc_pP->stat_rx_data_pdu_dropped;
	*stat_rx_data_bytes_dropped           = rlc_pP->stat_rx_data_bytes_dropped;
	*stat_rx_data_pdu_out_of_window       = rlc_pP->stat_rx_data_pdu_out_of_window;
	*stat_rx_data_bytes_out_of_window     = rlc_pP->stat_rx_data_bytes_out_of_window;
	*stat_timer_reordering_timed_out      = rlc_pP->stat_timer_reordering_timed_out;
}
//-----------------------------------------------------------------------------
uint32_t
rlc_um_get_buffer_occupancy (rlc_um_entity_t *rlc_pP)
{
	if (rlc_pP->buffer_occupancy > 0) {
		return rlc_pP->buffer_occupancy;
	} else {
		return 0;
	}
}
//-----------------------------------------------------------------------------
void
rlc_um_get_pdus (const protocol_ctxt_t* const ctxt_pP, void *argP)
{
	rlc_um_entity_t *rlc_p = (rlc_um_entity_t *) argP;

	switch (rlc_p->protocol_state) {

	case RLC_NULL_STATE:
		// from 3GPP TS 25.322 V9.2.0 p43
		// In the NULL state the RLC entity does not exist and therefore it is
		// not possible to transfer any data through it.
		// Upon reception of a CRLC-CONFIG-Req from upper layer indicating
		// establishment, the RLC entity:
		//   - is created; and
		//   - enters the DATA_TRANSFER_READY state.
		break;

	case RLC_DATA_TRANSFER_READY_STATE:

		// from 3GPP TS 25.322 V9.2.0 p43-44
		// In the DATA_TRANSFER_READY state, unacknowledged mode data can be
		// exchanged between the entities according to subclause 11.2.
		// Upon reception of a CRLC-CONFIG-Req from upper layer indicating
		// release, the RLC entity:
		// -enters the NULL state; and
		// -is considered as being terminated.
		// Upon reception of a CRLC-CONFIG-Req from upper layer indicating
		// modification, the RLC entity:
		// - stays in the DATA_TRANSFER_READY state;
		// - modifies only the protocol parameters and timers as indicated by
		// upper layers.
		// Upon reception of a CRLC-SUSPEND-Req from upper layers, the RLC
		// entity:
		// - enters the LOCAL_SUSPEND state.

		// SEND DATA TO MAC
		if (rlc_p->tx_sn_length == 10) {
			rlc_um_segment_10 (ctxt_pP, rlc_p);
		}

		if (rlc_p->tx_sn_length == 5) {
			rlc_um_segment_5 (ctxt_pP, rlc_p);
		}

		break;

	case RLC_LOCAL_SUSPEND_STATE:
		// from 3GPP TS 25.322 V9.2.0 p44
		// In the LOCAL_SUSPEND state, the RLC entity is suspended, i.e. it does
		// not send UMD PDUs with "Sequence Number" greater than or equal to a
		// certain specified value (see subclause 9.7.5).
		// Upon reception of a CRLC-CONFIG-Req from upper layer indicating
		// release, the RLC entity:
		// - enters the NULL state; and
		// - is considered as being terminated.
		// Upon reception of a CRLC-RESUME-Req from upper layers, the RLC entity:
		// - enters the DATA_TRANSFER_READY state; and
		// - resumes the data transmission.
		// Upon reception of a CRLC-CONFIG-Req from upper layer indicating
		// modification, the RLC entity:
		// - stays in the LOCAL_SUSPEND state;
		// - modifies only the protocol parameters and timers as indicated by
		//   upper layers.

		// TO DO TAKE CARE OF SN : THE IMPLEMENTATION OF THIS FUNCTIONNALITY IS NOT CRITICAL
		break;

	default:
		LOG_E(RLC, PROTOCOL_RLC_UM_CTXT_FMT" MAC_DATA_REQ UNKNOWN PROTOCOL STATE %02X hex\n",
				PROTOCOL_RLC_UM_CTXT_ARGS(ctxt_pP,rlc_p),
				rlc_p->protocol_state);
	}
}

//-----------------------------------------------------------------------------
void
rlc_um_rx (const protocol_ctxt_t* const ctxt_pP, void *argP, struct mac_data_ind data_indP)
{
	rlc_um_entity_t    *l_rlc_p = (rlc_um_entity_t *) argP;
#if TRACE_RLC_UM_PDU || MESSAGE_CHART_GENERATOR
	char  message_string[10000];
	mem_block_t        *tb_p;
	int16_t               tb_size_in_bytes;
	size_t              message_string_size = 0;
	rlc_um_pdu_info_t   pdu_info;
	int index;
#endif
#if TRACE_RLC_UM_PDU
	int                 octet_index;
#   if ENABLE_ITTI
	MessageDef         *msg_p;
#   endif
#endif

	switch (l_rlc_p->protocol_state) {

	case RLC_NULL_STATE:
		// from 3GPP TS 25.322 V9.2.0 p43
		// In the NULL state the RLC entity does not exist and therefore it is
		// not possible to transfer any data through it.
		// Upon reception of a CRLC-CONFIG-Req from upper layer indicating
		// establishment, the RLC entity:
		//   - is created; and
		//   - enters the DATA_TRANSFER_READY state.
		LOG_N(RLC, PROTOCOL_RLC_UM_CTXT_FMT" ERROR MAC_DATA_IND IN RLC_NULL_STATE\n",
				PROTOCOL_RLC_UM_CTXT_ARGS(ctxt_pP,l_rlc_p));
#if MESSAGE_CHART_GENERATOR

		if (data_indP.data.nb_elements > 0) {
			tb_p = data_indP.data.head;

			while (tb_p != NULL) {
				tb_size_in_bytes   = ((struct mac_tb_ind*) (tb_p->data))->size;
				rlc_um_get_pdu_infos(ctxt_pP,l_rlc_p,(rlc_um_pdu_sn_10_t*) ((struct mac_tb_ind*) (tb_p->data))->data_ptr, tb_size_in_bytes, &pdu_info, l_rlc_p->rx_sn_length);
				message_string_size = 0;
				message_string_size += sprintf(&message_string[message_string_size],
						MSC_AS_TIME_FMT" "PROTOCOL_RLC_UM_MSC_FMT"DATA SN %u size %u FI %u",
						MSC_AS_TIME_ARGS(ctxt_pP),
						PROTOCOL_RLC_UM_MSC_ARGS(ctxt_pP, l_rlc_p),
						pdu_info.sn,
						tb_size_in_bytes,
						pdu_info.fi);

				if (pdu_info.e) {
					message_string_size += sprintf(&message_string[message_string_size], "| HE:");

					for (index=0; index < pdu_info.num_li; index++) {
						message_string_size += sprintf(&message_string[message_string_size], " LI %u", pdu_info.li_list[index]);
					}
				}

				MSC_LOG_RX_DISCARDED_MESSAGE(
						(ctxt_pP->enb_flag == ENB_FLAG_YES) ? MSC_RLC_ENB:MSC_RLC_UE,
								(ctxt_pP->enb_flag == ENB_FLAG_YES) ? MSC_RLC_UE:MSC_RLC_ENB,
										(const char*)pdu_info.payload,
										tb_size_in_bytes,
										message_string);

				tb_p = tb_p->next;
			}
		}

#endif
		list_free (&data_indP.data);
		break;

	case RLC_DATA_TRANSFER_READY_STATE:
		// from 3GPP TS 25.322 V9.2.0 p43-44
		// In the DATA_TRANSFER_READY state, unacknowledged mode data can be
		// exchanged between the entities according to subclause 11.2.
		// Upon reception of a CRLC-CONFIG-Req from upper layer indicating
		// release, the RLC entity:
		// -enters the NULL state; and
		// -is considered as being terminated.
		// Upon reception of a CRLC-CONFIG-Req from upper layer indicating
		// modification, the RLC entity:
		// - stays in the DATA_TRANSFER_READY state;
		// - modifies only the protocol parameters and timers as indicated by
		// upper layers.
		// Upon reception of a CRLC-SUSPEND-Req from upper layers, the RLC
		// entity:
		// - enters the LOCAL_SUSPEND state.
		data_indP.tb_size = data_indP.tb_size >> 3;

#if TRACE_RLC_UM_PDU || MESSAGE_CHART_GENERATOR

		if (data_indP.data.nb_elements > 0) {
			LOG_D(RLC, PROTOCOL_RLC_UM_CTXT_FMT" MAC_DATA_IND %d TBs\n",
					PROTOCOL_RLC_UM_CTXT_ARGS(ctxt_pP,l_rlc_p),
					data_indP.data.nb_elements);

			tb_p = data_indP.data.head;

			while (tb_p != NULL) {
				tb_size_in_bytes   = ((struct mac_tb_ind *) (tb_p->data))->size;
				rlc_um_get_pdu_infos(ctxt_pP,
						l_rlc_p,(rlc_um_pdu_sn_10_t*) ((struct mac_tb_ind*) (tb_p->data))->data_ptr,
						tb_size_in_bytes,
						&pdu_info,
						l_rlc_p->rx_sn_length);

#if MESSAGE_CHART_GENERATOR
message_string_size = 0;
message_string_size += sprintf(&message_string[message_string_size],
		MSC_AS_TIME_FMT" "PROTOCOL_RLC_UM_MSC_FMT"DATA SN %u size %u FI %u",
		MSC_AS_TIME_ARGS(ctxt_pP),
		PROTOCOL_RLC_UM_MSC_ARGS(ctxt_pP, l_rlc_p),
		pdu_info.sn,
		tb_size_in_bytes,
		pdu_info.fi);

if (pdu_info.e) {
	message_string_size += sprintf(&message_string[message_string_size], "| HE:");

	for (index=0; index < pdu_info.num_li; index++) {
		message_string_size += sprintf(&message_string[message_string_size], " LI  %u", pdu_info.li_list[index]);
	}
}

MSC_LOG_RX_MESSAGE(
		(ctxt_pP->enb_flag == ENB_FLAG_YES) ? MSC_RLC_ENB:MSC_RLC_UE,
				(ctxt_pP->enb_flag == ENB_FLAG_YES) ? MSC_RLC_UE:MSC_RLC_ENB,
						(char*)pdu_info.payload,
						tb_size_in_bytes,
						message_string);

#endif
#if TRACE_RLC_UM_PDU
message_string_size = 0;
message_string_size += sprintf(&message_string[message_string_size], "Bearer      : %u\n", l_rlc_p->rb_id);
message_string_size += sprintf(&message_string[message_string_size], "PDU size    : %u\n", tb_size_in_bytes);
message_string_size += sprintf(&message_string[message_string_size], "Header size : %u\n", pdu_info.header_size);
message_string_size += sprintf(&message_string[message_string_size], "Payload size: %u\n", pdu_info.payload_size);
message_string_size += sprintf(&message_string[message_string_size], "PDU type    : RLC UM DATA IND: UMD PDU\n\n");

message_string_size += sprintf(&message_string[message_string_size], "Header      :\n");
message_string_size += sprintf(&message_string[message_string_size], "  FI        : %u\n", pdu_info.fi);
message_string_size += sprintf(&message_string[message_string_size], "  E         : %u\n", pdu_info.e);
message_string_size += sprintf(&message_string[message_string_size], "  SN        : %u\n", pdu_info.sn);

if (pdu_info.e) {
	message_string_size += sprintf(&message_string[message_string_size], "\nHeader extension  : \n");

	for (index=0; index < pdu_info.num_li; index++) {
		message_string_size += sprintf(&message_string[message_string_size], "  LI        : %u\n", pdu_info.li_list[index]);
	}
}

message_string_size += sprintf(&message_string[message_string_size], "\nPayload  : \n");
message_string_size += sprintf(&message_string[message_string_size], "------+-------------------------------------------------|\n");
message_string_size += sprintf(&message_string[message_string_size], "      |  0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f |\n");
message_string_size += sprintf(&message_string[message_string_size], "------+-------------------------------------------------|\n");

for (octet_index = 0; octet_index < pdu_info.payload_size; octet_index++) {
	if ((octet_index % 16) == 0) {
		if (octet_index != 0) {
			message_string_size += sprintf(&message_string[message_string_size], " |\n");
		}

		message_string_size += sprintf(&message_string[message_string_size], " %04d |", octet_index);
	}

	/*
	 * Print every single octet in hexadecimal form
	 */
	message_string_size += sprintf(&message_string[message_string_size], " %02x", pdu_info.payload[octet_index]);
	/*
	 * Align newline and pipes according to the octets in groups of 2
	 */
}

/*
 * Append enough spaces and put final pipe
 */
for (index = octet_index; index < 16; ++index) {
	message_string_size += sprintf(&message_string[message_string_size], "   ");
}

message_string_size += sprintf(&message_string[message_string_size], " |\n");

#   if ENABLE_ITTI
msg_p = itti_alloc_new_message_sized (ctxt_pP->enb_flag ? TASK_RLC_ENB:TASK_RLC_UE , RLC_UM_DATA_PDU_IND, message_string_size + sizeof (IttiMsgText));
msg_p->ittiMsg.rlc_um_data_pdu_ind.size = message_string_size;
memcpy(&msg_p->ittiMsg.rlc_um_data_pdu_ind.text, message_string, message_string_size);

itti_send_msg_to_task(TASK_UNKNOWN, ctxt_pP->instance, msg_p);

# else
LOG_T(RLC, "%s", message_string);
# endif // ENABLE_ITTI
#endif // TRACE_RLC_UM_PDU

tb_p = tb_p->next;
			}
		}

#endif
		rlc_um_receive (ctxt_pP, l_rlc_p, data_indP);
		break;

	case RLC_LOCAL_SUSPEND_STATE:
		// from 3GPP TS 25.322 V9.2.0 p44
		// In the LOCAL_SUSPEND state, the RLC entity is suspended, i.e. it does
		// not send UMD PDUs with "Sequence Number" greater than or equal to a
		// certain specified value (see subclause 9.7.5).
		// Upon reception of a CRLC-CONFIG-Req from upper layer indicating
		// release, the RLC entity:
		// - enters the NULL state; and
		// - is considered as being terminated.
		// Upon reception of a CRLC-RESUME-Req from upper layers, the RLC entity:
		// - enters the DATA_TRANSFER_READY state; and
		// - resumes the data transmission.
		// Upon reception of a CRLC-CONFIG-Req from upper layer indicating
		// modification, the RLC entity:
		// - stays in the LOCAL_SUSPEND state;
		// - modifies only the protocol parameters and timers as indicated by
		//   upper layers.
		LOG_N(RLC, PROTOCOL_RLC_UM_CTXT_FMT" RLC_LOCAL_SUSPEND_STATE\n",
				PROTOCOL_RLC_UM_CTXT_ARGS(ctxt_pP,l_rlc_p));
		/*if (data_indP.data.nb_elements > 0) {
        LOG_D(RLC, "[FRAME %05d][%s][RLC_UM][MOD %02u/%02u][RB %02d] MAC_DATA_IND %d TBs\n", l_rlc_p->module_id, l_rlc_p->rb_id, ctxt_pP->frame, data_indP.data.nb_elements);
        rlc_p[l_rlc_p->module_id].m_mscgen_trace_length = sprintf(rlc_p[l_rlc_p->module_id].m_mscgen_trace, "[MSC_MSG][FRAME %05d][MAC_%s][MOD %02d][][--- MAC_DATA_IND/ %d TB(s) ",
            ctxt_pP->frame,
            (ctxt_pP->enb_flag) ? "eNB":"UE",
            l_rlc_p->module_id,
            data_indP.data.nb_elements);

        tb = data_indP.data.head;
        while (tb != NULL) {
            rlc_p[l_rlc_p->module_id].m_mscgen_trace_length += sprintf(&rlc_p[l_rlc_p->module_id].m_mscgen_trace[rlc_p[l_rlc_p->module_id].m_mscgen_trace_length], " SN %d %c%c%c %d Bytes ",
                                                                (((struct mac_tb_ind *) (tb->data))->data_ptr[1]) +  (((uint16_t)((((struct mac_tb_ind *) (tb->data))->data_ptr[0]) & 0x03)) << 8),
                                                                (((struct mac_tb_ind *) (tb->data))->data_ptr[0] & 0x10) ?  '}':'{',
                                                                (((struct mac_tb_ind *) (tb->data))->data_ptr[0] & 0x08) ?  '{':'}',
                                                                (((struct mac_tb_ind *) (tb->data))->data_ptr[0] & 0x04) ?  'E':'_',
                                                                ((struct mac_tb_ind *) (tb->data))->size);
            tb = tb->next;
        }
        rlc_p[l_rlc_p->module_id].m_mscgen_trace_length += sprintf(&rlc_p[l_rlc_p->module_id].m_mscgen_trace[rlc_p[l_rlc_p->module_id].m_mscgen_trace_length], " DROPPED RLC LOCAL SUSPEND STATE ---X][RLC_UM][MOD %02d][RB %02d]\n",
            l_rlc_p->module_id,
            l_rlc_p->rb_id);

        rlc_p[l_rlc_p->module_id].m_mscgen_trace[rlc_p[l_rlc_p->module_id].m_mscgen_trace_length] = 0;
        LOG_D(RLC, "%s", rlc_p[l_rlc_p->module_id].m_mscgen_trace);
    }*/
		list_free (&data_indP.data);
		break;

	default:
		LOG_E(RLC, PROTOCOL_RLC_UM_CTXT_FMT" TX UNKNOWN PROTOCOL STATE %02X hex\n",
				PROTOCOL_RLC_UM_CTXT_ARGS(ctxt_pP,l_rlc_p),
				l_rlc_p->protocol_state);
	}
}

//-----------------------------------------------------------------------------
struct mac_status_resp
rlc_um_mac_status_indication (const protocol_ctxt_t* const ctxt_pP, void *rlc_pP, uint16_t tbs_sizeP, struct mac_status_ind tx_statusP,const eNB_flag_t enb_flagP)
{
	struct mac_status_resp status_resp;
	uint16_t  sdu_size = 0;
	uint16_t  sdu_remaining_size = 0;
	int32_t diff_time=0;
	rlc_um_entity_t   *rlc_p = NULL;
	mem_block_t       *mb_p = NULL;

	status_resp.buffer_occupancy_in_pdus         = 0;
	status_resp.buffer_occupancy_in_bytes        = 0;
	status_resp.head_sdu_remaining_size_to_send  = 0;
	status_resp.head_sdu_creation_time           = 0;
	status_resp.head_sdu_is_segmented            = 0;

	if (rlc_pP) {

		rlc_p = (rlc_um_entity_t *) rlc_pP;
		status_resp.rlc_info.rlc_protocol_state      = rlc_p->protocol_state;
		rlc_um_check_timer_dar_time_out(ctxt_pP, rlc_p);

		rlc_p->nb_bytes_requested_by_mac = tbs_sizeP;

		status_resp.buffer_occupancy_in_bytes = rlc_um_get_buffer_occupancy (rlc_p);

		if ((status_resp.buffer_occupancy_in_bytes > 0) && ((mb_p = list_get_head(&rlc_p->input_sdus)) != NULL)) {

			if (enb_flagP == ENB_FLAG_YES) {
				/* For eNB: add minimum RLC UM header size for the scheduler */
				/* For UE : RLC header part is not taken into account for BSR reporting (cf 36.321) */
				status_resp.buffer_occupancy_in_bytes += rlc_p->tx_header_min_length_in_bytes;
			}
			status_resp.buffer_occupancy_in_pdus = rlc_p->input_sdus.nb_elements;

			diff_time =   ctxt_pP->frame - ((struct rlc_um_tx_sdu_management *)mb_p->data)->sdu_creation_time;
			status_resp.head_sdu_creation_time = (diff_time > 0 ) ? (uint32_t) diff_time :  (uint32_t)(0xffffffff - diff_time + ctxt_pP->frame) ;
			//msg("rlc_p status for ctxt_pP->frame %d diff time %d resp %d\n", ctxt_pP->frame, diff_time,status_resp.head_sdu_creation_time) ;

			sdu_size            = ((struct rlc_um_tx_sdu_management *) mb_p->data)->sdu_size;
			sdu_remaining_size  = ((struct rlc_um_tx_sdu_management *) mb_p->data)->sdu_remaining_size;

			status_resp.head_sdu_remaining_size_to_send = sdu_remaining_size;

			if (sdu_size == sdu_remaining_size)  {
				status_resp.head_sdu_is_segmented = 0;
			} else {
				status_resp.head_sdu_is_segmented = 1;
			}

		} else {
		}

		//msg("[FRAME %05d][%s][RLC_UM][MOD %02u/%02u][RB %02d] MAC_STATUS_INDICATION BO = %d\n", ((rlc_um_entity_t *) rlc_pP)->module_id, ((rlc_um_entity_t *) rlc_pP)->rb_id, status_resp.buffer_occupancy_in_bytes);

		status_resp.rlc_info.rlc_protocol_state = ((rlc_um_entity_t *) rlc_pP)->protocol_state;
#if TRACE_RLC_UM_TX_STATUS

		if ((((rlc_um_entity_t *) rlc_pP)->rb_id > 0) && (status_resp.buffer_occupancy_in_bytes > 0)) {
			LOG_D(RLC, PROTOCOL_RLC_UM_CTXT_FMT" MAC_STATUS_INDICATION (DATA) %d bytes requested -> %d bytes available\n",
					PROTOCOL_RLC_UM_CTXT_ARGS(ctxt_pP,rlc_pP),
					tbs_sizeP,
					status_resp.buffer_occupancy_in_bytes);

			if ((tx_statusP.tx_status == MAC_TX_STATUS_SUCCESSFUL) && (tx_statusP.no_pdu)) {
				LOG_D(RLC, PROTOCOL_RLC_UM_CTXT_FMT" MAC_STATUS_INDICATION  TX STATUS   SUCCESSFUL %d PDUs\n",
						PROTOCOL_RLC_UM_CTXT_ARGS(ctxt_pP,rlc_pP),
						tx_statusP.no_pdu);
			}

			if ((tx_statusP.tx_status == MAC_TX_STATUS_UNSUCCESSFUL) && (tx_statusP.no_pdu)) {
				LOG_D(RLC, PROTOCOL_RLC_UM_CTXT_FMT" MAC_STATUS_INDICATION  TX STATUS UNSUCCESSFUL %d PDUs\n",
						PROTOCOL_RLC_UM_CTXT_ARGS(ctxt_pP,rlc_pP),
						tx_statusP.no_pdu);
			}
		}

#endif
	} else {
		LOG_E(RLC, "[RLC] rlc_um_mac_status_indication RLC NULL!!!\n");
	}

	return status_resp;
}

//-----------------------------------------------------------------------------
void
rlc_um_set_nb_bytes_requested_by_mac (
		void *				rlc_pP,
		const tb_size_t		tb_sizeP
)
{
	((rlc_um_entity_t *) rlc_pP)->nb_bytes_requested_by_mac = tb_sizeP;
}

//-----------------------------------------------------------------------------
struct mac_data_req
rlc_um_mac_data_request (const protocol_ctxt_t* const ctxt_pP, void *rlc_pP,const eNB_flag_t  enb_flagP)
{
	struct mac_data_req data_req;
	int16_t               tb_size_in_bytes;
	mem_block_t        *tb_p;
#if TRACE_RLC_UM_PDU || MESSAGE_CHART_GENERATOR
	char  message_string[10000];
	size_t              message_string_size = 0;
#   if ENABLE_ITTI
	MessageDef         *msg_p;
#   endif
	rlc_um_pdu_info_t   pdu_info;
	int                 octet_index, index;
#endif
	rlc_um_entity_t *l_rlc_p = (rlc_um_entity_t *) rlc_pP;

	rlc_um_get_pdus(ctxt_pP, l_rlc_p);

	list_init (&data_req.data, NULL);
	list_add_list (&l_rlc_p->pdus_to_mac_layer, &data_req.data);


	if (enb_flagP) {
		// redundant in UE MAC Tx processing and not used in eNB scheduler ...
		data_req.buffer_occupancy_in_bytes = rlc_um_get_buffer_occupancy (l_rlc_p);

		if (data_req.buffer_occupancy_in_bytes > 0) {
			data_req.buffer_occupancy_in_bytes += l_rlc_p->tx_header_min_length_in_bytes;
		}
	}

	data_req.rlc_info.rlc_protocol_state = l_rlc_p->protocol_state;

	if (data_req.data.nb_elements > 0) {
		tb_p = data_req.data.head;

		while (tb_p != NULL) {
			tb_size_in_bytes   = ((struct mac_tb_req *) (tb_p->data))->tb_size;

			LOG_D(RLC, PROTOCOL_RLC_UM_CTXT_FMT" MAC_DATA_REQUEST  TB SIZE %u\n",
					PROTOCOL_RLC_UM_CTXT_ARGS(ctxt_pP,l_rlc_p),
					((struct mac_tb_req *) (tb_p->data))->tb_size);
			l_rlc_p->stat_tx_data_pdu   += 1;
			l_rlc_p->stat_tx_data_bytes += tb_size_in_bytes;

			AssertFatal( tb_size_in_bytes > 0 , "RLC UM PDU LENGTH %d", tb_size_in_bytes);
#if TRACE_RLC_UM_PDU || MESSAGE_CHART_GENERATOR
			rlc_um_get_pdu_infos(ctxt_pP, l_rlc_p,(rlc_um_pdu_sn_10_t*) ((struct mac_tb_req*) (tb_p->data))->data_ptr, tb_size_in_bytes, &pdu_info, l_rlc_p->rx_sn_length);
#endif
#if MESSAGE_CHART_GENERATOR
			message_string_size = 0;
			message_string_size += sprintf(&message_string[message_string_size],
					MSC_AS_TIME_FMT" "PROTOCOL_RLC_UM_MSC_FMT" DATA SN %u size %u FI %u",
					MSC_AS_TIME_ARGS(ctxt_pP),
					PROTOCOL_RLC_UM_MSC_ARGS(ctxt_pP, l_rlc_p),
					pdu_info.sn,
					tb_size_in_bytes,
					pdu_info.fi);

			if (pdu_info.e) {
				message_string_size += sprintf(&message_string[message_string_size], "|HE:");

				for (index=0; index < pdu_info.num_li; index++) {
					message_string_size += sprintf(&message_string[message_string_size], " LI %u", pdu_info.li_list[index]);
				}
			}

			MSC_LOG_TX_MESSAGE(
					(ctxt_pP->enb_flag == ENB_FLAG_YES) ? MSC_RLC_ENB:MSC_RLC_UE,
							(ctxt_pP->enb_flag == ENB_FLAG_YES) ? MSC_RLC_UE:MSC_RLC_ENB,
									(const char*)pdu_info.payload,
									pdu_info.payload_size,
									message_string);

#endif
#if TRACE_RLC_UM_PDU
			message_string_size = 0;
			message_string_size += sprintf(&message_string[message_string_size], "Bearer      : %u\n", l_rlc_p->rb_id);
			message_string_size += sprintf(&message_string[message_string_size], "PDU size    : %u\n", tb_size_in_bytes);
			message_string_size += sprintf(&message_string[message_string_size], "Header size : %u\n", pdu_info.header_size);
			message_string_size += sprintf(&message_string[message_string_size], "Payload size: %u\n", pdu_info.payload_size);
			message_string_size += sprintf(&message_string[message_string_size], "PDU type    : RLC UM DATA IND: UMD PDU\n\n");

			message_string_size += sprintf(&message_string[message_string_size], "Header      :\n");
			message_string_size += sprintf(&message_string[message_string_size], "  FI        : %u\n", pdu_info.fi);
			message_string_size += sprintf(&message_string[message_string_size], "  E         : %u\n", pdu_info.e);
			message_string_size += sprintf(&message_string[message_string_size], "  SN        : %u\n", pdu_info.sn);

			if (pdu_info.e) {
				message_string_size += sprintf(&message_string[message_string_size], "\nHeader extension  : \n");

				for (index=0; index < pdu_info.num_li; index++) {
					message_string_size += sprintf(&message_string[message_string_size], "  LI        : %u\n", pdu_info.li_list[index]);
				}
			}

			message_string_size += sprintf(&message_string[message_string_size], "\nPayload  : \n");
			message_string_size += sprintf(&message_string[message_string_size], "------+-------------------------------------------------|\n");
			message_string_size += sprintf(&message_string[message_string_size], "      |  0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f |\n");
			message_string_size += sprintf(&message_string[message_string_size], "------+-------------------------------------------------|\n");

			for (octet_index = 0; octet_index < pdu_info.payload_size; octet_index++) {
				if ((octet_index % 16) == 0) {
					if (octet_index != 0) {
						message_string_size += sprintf(&message_string[message_string_size], " |\n");
					}

					message_string_size += sprintf(&message_string[message_string_size], " %04d |", octet_index);
				}

				/*
				 * Print every single octet in hexadecimal form
				 */
				message_string_size += sprintf(&message_string[message_string_size], " %02x", pdu_info.payload[octet_index]);
				/*
				 * Align newline and pipes according to the octets in groups of 2
				 */
			}

			/*
			 * Append enough spaces and put final pipe
			 */
			for (index = octet_index; index < 16; ++index) {
				message_string_size += sprintf(&message_string[message_string_size], "   ");
			}

			message_string_size += sprintf(&message_string[message_string_size], " |\n");

#   if ENABLE_ITTI
			msg_p = itti_alloc_new_message_sized (ctxt_pP->enb_flag > 0 ? TASK_RLC_ENB:TASK_RLC_UE , RLC_UM_DATA_PDU_REQ, message_string_size + sizeof (IttiMsgText));
			msg_p->ittiMsg.rlc_um_data_pdu_req.size = message_string_size;
			memcpy(&msg_p->ittiMsg.rlc_um_data_pdu_req.text, message_string, message_string_size);

			itti_send_msg_to_task(TASK_UNKNOWN, ctxt_pP->instance, msg_p);

# else
			LOG_T(RLC, "%s", message_string);
# endif
#endif
			tb_p = tb_p->next;
		}
	}

	return data_req;
}

void wifi_init_rlc(){
	sock_raw=socket(AF_PACKET,SOCK_RAW,IPPROTO_RAW);

}

//-----------------------------------------------------------------------------
void
rlc_um_mac_data_indication (const protocol_ctxt_t* const ctxt_pP, void *rlc_pP, struct mac_data_ind data_indP)
{
	rlc_um_rx (ctxt_pP, rlc_pP, data_indP);
	rlc_um_check_timer_dar_time_out(ctxt_pP, rlc_pP);
}
//our functions
//our functions

struct ifreq ifreq_c,ifreq_i,ifreq_ip; /// for each ioctl keep diffrent ifreq structure otherwise error may come in sending(sendto )

unsigned char *sendbuff;
uint16_t total_len=0,send_len;

void get_wlan_index()
{
	memset(&ifreq_i,0,sizeof(ifreq_i));
	strncpy(ifreq_i.ifr_name,"eth1",IFNAMSIZ-1);

	if((ioctl(sock_raw,SIOCGIFINDEX,&ifreq_i))<0)
		printf("error in index ioctl reading");

//	printf("index=%d\n",ifreq_i.ifr_ifindex);

}
void get_mac()
{

	memset(&ifreq_c,0,sizeof(ifreq_c));
	strncpy(ifreq_c.ifr_name,"eth1",IFNAMSIZ-1);

	if((ioctl(sock_raw,SIOCGIFHWADDR,&ifreq_c))<0)
		printf("error in SIOCGIFHWADDR ioctl reading");

	//printf("Mac= %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n",(unsigned char)(ifreq_c.ifr_hwaddr.sa_data[0]),(unsigned char)(ifreq_c.ifr_hwaddr.sa_data[1]),(unsigned char)(ifreq_c.ifr_hwaddr.sa_data[2]),(unsigned char)(ifreq_c.ifr_hwaddr.sa_data[3]),(unsigned char)(ifreq_c.ifr_hwaddr.sa_data[4]),(unsigned char)(ifreq_c.ifr_hwaddr.sa_data[5]));


	//printf("Ethernet packaging start ... \n");

	struct ether_header *eth = (struct ether_header *)(sendbuff);
	eth->ether_shost[0] = (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[0]);
	eth->ether_shost[1] = (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[1]);
	eth->ether_shost[2] = (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[2]);
	eth->ether_shost[3] = (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[3]);
	eth->ether_shost[4] = (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[4]);
	eth->ether_shost[5] = (unsigned char)(ifreq_c.ifr_hwaddr.sa_data[5]);

	eth->ether_dhost[0]    =  DESTMAC0;
	eth->ether_dhost[1]    =  DESTMAC1;
	eth->ether_dhost[2]    =  DESTMAC2;
	eth->ether_dhost[3]    =  DESTMAC3;
	eth->ether_dhost[4]    =  DESTMAC4;
	eth->ether_dhost[5]    =  DESTMAC5;

	eth->ether_type = htons(ETH_P_IP);   //0x800
	//printf("Mac= %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n",(eth->ether_dhost[0]),(eth->ether_dhost[1]),(eth->ether_dhost[2]),(eth->ether_dhost[3]),(eth->ether_dhost[4]),(eth->ether_dhost[5]));

//	printf("Ethernet packaging done.\n");
//	printf("Total Length\n");
	total_len+=sizeof(struct ether_header);
}

void get_data(unsigned char *new_sdu_p,uint16_t sdu_sizeP )
//      void get_data()
{
//	printf("Before Total Lenght = %d\n", total_len);
	//    	printf("*****Before Size of sendbuff******%d\n", strlen(sendbuff));
	//    	sendbuff = new_sdu_p;
	//    	total_len=total_len+ sdu_sizeP;
	//    	printf("Before Total Lenght = %d", total_len);
	//    	sendbuff[total_len++]	=	0xAA;
	//    		sendbuff[total_len++]	=	0xBB;
	//    		sendbuff[total_len++]	=	0xCC;
	//    		sendbuff[total_len++]	=	0xDD;
	//    		sendbuff[total_len++]	=	0xEE;
	int j=0;
	//printf("header size before adding packet = %d\n",total_len);
	for(uint16_t i=total_len; i<total_len+sdu_sizeP; i++ )
	{
		sendbuff[i]=*(new_sdu_p+j+24); j++;
		//sendbuff[i]=*(new_sdu_p+j); j++;
//		printf("char = %c \t %2.X \t %c\t %2.X \n",*(new_sdu_p+j), *(new_sdu_p+j), new_sdu_p+j, new_sdu_p+j );
	}
//	printf("*****Size of sendbuff******%d\n", strlen(sendbuff));

	total_len=total_len+sdu_sizeP;
//	printf("After Total Lenght = %d\n Size of SDU=%d " , total_len,sdu_sizeP);
}

void get_udp(unsigned char* new_sdu_p,uint16_t sdu_sizeP )
//    void get_udp()
{
	struct udphdr *uh = (struct udphdr *)(sendbuff + sizeof(struct iphdr) + sizeof(struct ether_header));

	uh->source	= htons(23451);
	uh->dest	= htons(23452);
	uh->check	= 0;
	//	uh->check = udp_checksum((void *) (datagram + sizeof(struct iphdr)),ntohs(uh->len), iph->saddr, iph->daddr);

	total_len+= sizeof(struct udphdr);
	get_data(new_sdu_p,sdu_sizeP );
	//    	get_data();
	uh->len		= htons((total_len - sizeof(struct iphdr) - sizeof(struct ether_header)));
	//printf("length of uh %lu",total_len - sizeof(struct iphdr) - sizeof(struct ether_header));

}

unsigned short checksum(unsigned short* buff, int _16bitword)
{
	unsigned long sum;
	for(sum=0;_16bitword>0;_16bitword--)
		sum+=htons(*(buff)++);
	do
	{
		sum = ((sum >> 16) + (sum & 0xFFFF));
	}
	while(sum & 0xFFFF0000);

	return (~sum);

}

void get_ip(unsigned char* new_sdu_p,uint16_t sdu_sizeP )
//    void get_ip()
{

	//printf("Hello Himank get ip\n");
	memset(&ifreq_ip,0,sizeof(ifreq_ip));
	strncpy(ifreq_ip.ifr_name,"eth1",IFNAMSIZ-1);

	if(ioctl(sock_raw,SIOCGIFADDR,&ifreq_ip)<0)
	{
		printf("error in SIOCGIFADDR \n");
	}

	//printf("%s\n",inet_ntoa((((struct sockaddr_in*)&(ifreq_ip.ifr_addr))->sin_addr)));
//	printf("Hello Himank get ip2\n");
	/****** OR
    	int i;
    	for(i=0;i<14;i++)
    	printf("%d\n",(unsigned char)ifreq_ip.ifr_addr.sa_data[i]); ******/

	struct iphdr *iph = (struct iphdr*)(sendbuff + sizeof(struct ether_header));
	iph->ihl	= 5;
	iph->version	= 4;
	iph->tos	= 16;
	iph->id		= htons(10201);
	iph->ttl	= 64;
	iph->protocol	= 17;
	//iph->saddr	= inet_addr(inet_ntoa((((struct sockaddr_in *)&(ifreq_ip.ifr_addr))->sin_addr)));
	iph->saddr	= inet_addr("192.168.130.119");

	iph->daddr	= inet_addr("192.168.130.22"); // put destination IP address


	total_len += sizeof(struct iphdr);
	get_udp(new_sdu_p,sdu_sizeP );
	//    	get_udp();
//	printf("Tota length %d\n",total_len);
	iph->tot_len	= htons(total_len - sizeof(struct ether_header));
	iph->check	= htons(checksum((unsigned short*)(sendbuff + sizeof(struct ether_header)), (sizeof(struct iphdr)/2)));

}
void send_wifi(unsigned char *new_sdu_p,uint16_t sdu_sizeP )
///void send_wifi()
{

	//sock_raw=socket(AF_PACKET,SOCK_RAW,IPPROTO_RAW);
	if(sock_raw == -1)
		printf("error in socket");

//	printf("sdu size ######%d\n", sdu_sizeP);
//	printf("sending...\n");
	int t=0;

	struct sockaddr_ll sadr_ll;

	total_len=0;
	t++;
	sendbuff=(unsigned char*)malloc(sdu_sizeP+42); // increase in case of large data.Here data is --> AA  BB  CC  DD  EE
	memset(sendbuff,0,(uint32_t)sdu_sizeP+42);


//	printf("\n Sending through Wi-Fi");
	get_wlan_index();
	get_mac();
//	printf("1Packet has been sent\n");
	sadr_ll.sll_ifindex = ifreq_i.ifr_ifindex;
	sadr_ll.sll_halen   = ETH_ALEN;
	sadr_ll.sll_addr[0]  = DESTMAC0;
	sadr_ll.sll_addr[1]  = DESTMAC1;
	sadr_ll.sll_addr[2]  = DESTMAC2;
	sadr_ll.sll_addr[3]  = DESTMAC3;
	sadr_ll.sll_addr[4]  = DESTMAC4;
	sadr_ll.sll_addr[5]  = DESTMAC5;
//	printf("2Packet has been sent\n");
	get_ip(new_sdu_p,sdu_sizeP );
	//    	        	get_ip();
	//printf("SendBuff Data $$$$$$$\t%.2X\n", *sendbuff);
	send_len = sendto(sock_raw,sendbuff,total_len,0,(const struct sockaddr*)&sadr_ll,sizeof(struct sockaddr_ll));


	if(send_len<0)
	{
//		printf("error in sending....sendlen=%d....errno=%d\n",send_len,errno);
		return ;

	}

}
//our functions
//our functions





//-----------------------------------------------------------------------------
void
rlc_um_data_req (const protocol_ctxt_t* const ctxt_pP, void *rlc_pP, mem_block_t *sdu_pP)
{
	rlc_um_entity_t *rlc_p = (rlc_um_entity_t *) rlc_pP;

#if ! USER_MODE
	unsigned long int rlc_um_time_us;
	int min, sec, usec;
#endif
#if TRACE_RLC_UM_PDU
#if ENABLE_ITTI
	MessageDef          *msg_p;
#   endif
	uint16_t             data_offset;
	uint16_t             data_size;
	size_t               message_string_size = 0;
	int                  octet_index, index;
	char                 message_string[7000];
#endif

	LOG_D(RLC, PROTOCOL_RLC_UM_CTXT_FMT" RLC_UM_DATA_REQ size %d Bytes, BO %d , NB SDU %d\n",
			PROTOCOL_RLC_UM_CTXT_ARGS(ctxt_pP,rlc_p),
			((struct rlc_um_data_req *) (sdu_pP->data))->data_size,
			rlc_p->buffer_occupancy,
			rlc_p->input_sdus.nb_elements);

	/*rlc_util_print_hex_octets(
      RLC,
      (uint8_t*)&sdu_pP->data[sizeof (struct rlc_um_data_req_alloc)],
      ((struct rlc_um_data_req *) (sdu_pP->data))->data_size);*/

	// IMPORTANT : do not change order of affectations
	((struct rlc_um_tx_sdu_management *) (sdu_pP->data))->sdu_size = ((struct rlc_um_data_req *) (sdu_pP->data))->data_size;
	//rlc_p->nb_sdu += 1;
	((struct rlc_um_tx_sdu_management *) (sdu_pP->data))->first_byte = (uint8_t*)&sdu_pP->data[sizeof (struct rlc_um_data_req_alloc)];
	((struct rlc_um_tx_sdu_management *) (sdu_pP->data))->sdu_remaining_size = ((struct rlc_um_tx_sdu_management *)
			(sdu_pP->data))->sdu_size;
	((struct rlc_um_tx_sdu_management *) (sdu_pP->data))->sdu_segmented_size = 0;
	((struct rlc_um_tx_sdu_management *) (sdu_pP->data))->sdu_creation_time = ctxt_pP->frame;
	//rlc_p->next_sdu_index = (rlc_p->next_sdu_index + 1) % rlc_p->size_input_sdus_buffer;

	rlc_p->stat_tx_pdcp_sdu   += 1;
	rlc_p->stat_tx_pdcp_bytes += ((struct rlc_um_tx_sdu_management *) (sdu_pP->data))->sdu_size;

	MSC_LOG_RX_MESSAGE(
			(ctxt_pP->enb_flag == ENB_FLAG_YES) ? MSC_RLC_ENB:MSC_RLC_UE,
					(ctxt_pP->enb_flag == ENB_FLAG_YES) ? MSC_PDCP_ENB:MSC_PDCP_UE,
							NULL,
							0,
							MSC_AS_TIME_FMT" "PROTOCOL_RLC_UM_MSC_FMT" DATA-REQ size %u",
							MSC_AS_TIME_ARGS(ctxt_pP),
							PROTOCOL_RLC_UM_MSC_ARGS(ctxt_pP, rlc_p),
							((struct rlc_um_tx_sdu_management*) (sdu_pP->data))->sdu_size);


#   if TRACE_RLC_UM_PDU
	data_offset = sizeof (struct rlc_um_data_req_alloc);
	data_size   = ((struct rlc_um_tx_sdu_management *)(sdu_pP->data))->sdu_size;
	message_string_size += sprintf(&message_string[message_string_size], "Bearer      : %u\n", rlc_p->rb_id);
	message_string_size += sprintf(&message_string[message_string_size], "SDU size    : %u\n", data_size);

	message_string_size += sprintf(&message_string[message_string_size], "\nPayload  : \n");
	message_string_size += sprintf(&message_string[message_string_size], "------+-------------------------------------------------|\n");
	message_string_size += sprintf(&message_string[message_string_size], "      |  0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f |\n");
	message_string_size += sprintf(&message_string[message_string_size], "------+-------------------------------------------------|\n");

	for (octet_index = 0; octet_index < data_size; octet_index++) {
		if ((octet_index % 16) == 0) {
			if (octet_index != 0) {
				message_string_size += sprintf(&message_string[message_string_size], " |\n");
			}

			message_string_size += sprintf(&message_string[message_string_size], " %04d |", octet_index);
		}

		/*
		 * Print every single octet in hexadecimal form
		 */
		message_string_size += sprintf(&message_string[message_string_size], " %02x", ((uint8_t*)(&sdu_pP->data[data_offset]))[octet_index]);
		/*
		 * Align newline and pipes according to the octets in groups of 2
		 */
	}

	/*
	 * Append enough spaces and put final pipe
	 */
	for (index = octet_index; index < 16; ++index) {
		message_string_size += sprintf(&message_string[message_string_size], "   ");
	}
	printf("1");
	message_string_size += sprintf(&message_string[message_string_size], " |\n");

#   if ENABLE_ITTI
	printf("2");
	msg_p = itti_alloc_new_message_sized (ctxt_pP->enb_flag > 0 ? TASK_RLC_ENB:TASK_RLC_UE , RLC_UM_SDU_REQ, message_string_size + sizeof (IttiMsgText));
	msg_p->ittiMsg.rlc_um_sdu_req.size = message_string_size;
	memcpy(&msg_p->ittiMsg.rlc_um_sdu_req.text, message_string, message_string_size);

	itti_send_msg_to_task(TASK_UNKNOWN, ctxt_pP->instance, msg_p);

#else
	printf("3");
	LOG_T(RLC, "%s", message_string);
#endif
#   endif
	printf("4");
	RLC_UM_MUTEX_LOCK(&rlc_p->lock_input_sdus, ctxt_pP, rlc_p);
	//int a= jk % 2;
	jk++;
	if(jk%2<1 && jk>100){
		//        	rlc_um_data_req(ctxt_pP, &rlc_union_p->rlc.um, new_sdu_p);
		// Go through Wi-Fi
		//printf("Packet THrough Wifi......\n");
		unsigned char *temp;
		temp = sdu_pP->data;

//		printf("@@@@@@@%zu", sizeof(temp));
//
//		printf("sdu size ######%d", ((struct rlc_um_tx_sdu_management *) (sdu_pP->data))->sdu_size);
//		//int val=0;
//		printf("Data !!!!!!!!!!!!!!!");
		//  	for (val=0; val<sdu_sizeP;val++)
		//  	       	printf("%.2X\n",*(new_sdu_p->data+val));

		send_wifi(temp,((struct rlc_um_tx_sdu_management *) (sdu_pP->data))->sdu_size);

		//send_wifi();
//		printf("Himank Sent \n");
		//  	return RLC_OP_STATUS_OK;
	}
	else{
		rlc_p->buffer_occupancy += ((struct rlc_um_tx_sdu_management *) (sdu_pP->data))->sdu_size;
		list_add_tail_eurecom(sdu_pP, &rlc_p->input_sdus);

	}
	//list_add_tail_eurecom(sdu_pP, &rlc_p->input_sdus);
	RLC_UM_MUTEX_UNLOCK(&rlc_p->lock_input_sdus);
#if DEBUG_RLC_CONGESTION
#if MESSAGE_CHART_GENERATOR
	printf("5");
	if (rlc_p->buffer_occupancy > 4096) {
		MSC_LOG_EVENT((ctxt_pP->enb_flag == ENB_FLAG_YES) ? MSC_RLC_ENB:MSC_RLC_UE,\
				"0 "PROTOCOL_RLC_AM_MSC_FMT" BO %u bytes",\
				PROTOCOL_RLC_AM_MSC_ARGS(ctxt_pP,rlc_pP), rlc_p->buffer_occupancy);
	}
#else
	printf("6");
	LOG_W(RLC, PROTOCOL_RLC_UM_CTXT_FMT" BO %d , NB SDU %d\n",
			PROTOCOL_RLC_UM_CTXT_ARGS(ctxt_pP,rlc_p),
			rlc_p->buffer_occupancy,
			rlc_p->input_sdus.nb_elements);
#endif
#endif
}
