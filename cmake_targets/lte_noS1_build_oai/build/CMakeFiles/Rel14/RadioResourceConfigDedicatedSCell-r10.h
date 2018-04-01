/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_RadioResourceConfigDedicatedSCell_r10_H_
#define	_RadioResourceConfigDedicatedSCell_r10_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct PhysicalConfigDedicatedSCell_r10;
struct MAC_MainConfigSCell_r11;
struct NAICS_AssistanceInfo_r12;
struct NeighCellsCRS_Info_r13;

/* RadioResourceConfigDedicatedSCell-r10 */
typedef struct RadioResourceConfigDedicatedSCell_r10 {
	struct PhysicalConfigDedicatedSCell_r10	*physicalConfigDedicatedSCell_r10	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	struct RadioResourceConfigDedicatedSCell_r10__ext1 {
		struct MAC_MainConfigSCell_r11	*mac_MainConfigSCell_r11	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ext1;
	struct RadioResourceConfigDedicatedSCell_r10__ext2 {
		struct NAICS_AssistanceInfo_r12	*naics_Info_r12	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ext2;
	struct RadioResourceConfigDedicatedSCell_r10__ext3 {
		struct NeighCellsCRS_Info_r13	*neighCellsCRS_InfoSCell_r13	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ext3;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RadioResourceConfigDedicatedSCell_r10_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RadioResourceConfigDedicatedSCell_r10;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "PhysicalConfigDedicatedSCell-r10.h"
#include "MAC-MainConfigSCell-r11.h"
#include "NAICS-AssistanceInfo-r12.h"
#include "NeighCellsCRS-Info-r13.h"

#endif	/* _RadioResourceConfigDedicatedSCell_r10_H_ */
#include <asn_internal.h>