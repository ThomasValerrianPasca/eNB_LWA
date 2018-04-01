/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_SCellToAddMod_r10_H_
#define	_SCellToAddMod_r10_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SCellIndex-r10.h"
#include "PhysCellId.h"
#include "ARFCN-ValueEUTRA.h"
#include <constr_SEQUENCE.h>
#include "ARFCN-ValueEUTRA-v9e0.h"
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RadioResourceConfigCommonSCell_r10;
struct RadioResourceConfigDedicatedSCell_r10;
struct AntennaInfoDedicated_v10i0;

/* SCellToAddMod-r10 */
typedef struct SCellToAddMod_r10 {
	SCellIndex_r10_t	 sCellIndex_r10;
	struct SCellToAddMod_r10__cellIdentification_r10 {
		PhysCellId_t	 physCellId_r10;
		ARFCN_ValueEUTRA_t	 dl_CarrierFreq_r10;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *cellIdentification_r10;
	struct RadioResourceConfigCommonSCell_r10	*radioResourceConfigCommonSCell_r10	/* OPTIONAL */;
	struct RadioResourceConfigDedicatedSCell_r10	*radioResourceConfigDedicatedSCell_r10	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	struct SCellToAddMod_r10__ext1 {
		ARFCN_ValueEUTRA_v9e0_t	*dl_CarrierFreq_v1090	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ext1;
	struct SCellToAddMod_r10__ext2 {
		struct AntennaInfoDedicated_v10i0	*antennaInfoDedicatedSCell_v10i0	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ext2;
	struct SCellToAddMod_r10__ext3 {
		long	*srs_SwitchFromServCellIndex_r14	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *ext3;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SCellToAddMod_r10_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SCellToAddMod_r10;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RadioResourceConfigCommonSCell-r10.h"
#include "RadioResourceConfigDedicatedSCell-r10.h"
#include "AntennaInfoDedicated-v10i0.h"

#endif	/* _SCellToAddMod_r10_H_ */
#include <asn_internal.h>
