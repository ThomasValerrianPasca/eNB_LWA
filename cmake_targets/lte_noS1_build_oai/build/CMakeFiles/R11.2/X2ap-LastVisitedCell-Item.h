/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "X2AP-IEs"
 * 	found in "/home/oai/Downloads/LWA/openair2/X2AP/MESSAGES/ASN1/R11.2/X2AP-IEs.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_X2ap_LastVisitedCell_Item_H_
#define	_X2ap_LastVisitedCell_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "X2ap-LastVisitedEUTRANCellInformation.h"
#include "X2ap-LastVisitedUTRANCellInformation.h"
#include "X2ap-LastVisitedGERANCellInformation.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum X2ap_LastVisitedCell_Item_PR {
	X2ap_LastVisitedCell_Item_PR_NOTHING,	/* No components present */
	X2ap_LastVisitedCell_Item_PR_e_UTRAN_Cell,
	X2ap_LastVisitedCell_Item_PR_uTRAN_Cell,
	X2ap_LastVisitedCell_Item_PR_gERAN_Cell,
	/* Extensions may appear below */
	
} X2ap_LastVisitedCell_Item_PR;

/* X2ap-LastVisitedCell-Item */
typedef struct X2ap_LastVisitedCell_Item {
	X2ap_LastVisitedCell_Item_PR present;
	union X2ap_LastVisitedCell_Item_u {
		X2ap_LastVisitedEUTRANCellInformation_t	 e_UTRAN_Cell;
		X2ap_LastVisitedUTRANCellInformation_t	 uTRAN_Cell;
		X2ap_LastVisitedGERANCellInformation_t	 gERAN_Cell;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} X2ap_LastVisitedCell_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_X2ap_LastVisitedCell_Item;

#ifdef __cplusplus
}
#endif

#endif	/* _X2ap_LastVisitedCell_Item_H_ */
#include <asn_internal.h>
