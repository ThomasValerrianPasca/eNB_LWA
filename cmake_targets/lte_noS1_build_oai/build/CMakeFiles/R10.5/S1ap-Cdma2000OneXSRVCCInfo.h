/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "/home/oai/Downloads/LWA/openair3/S1AP/MESSAGES/ASN1/R10.5/S1AP-IEs.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_S1ap_Cdma2000OneXSRVCCInfo_H_
#define	_S1ap_Cdma2000OneXSRVCCInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include "S1ap-Cdma2000OneXMEID.h"
#include "S1ap-Cdma2000OneXMSI.h"
#include "S1ap-Cdma2000OneXPilot.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct S1ap_IE_Extensions;

/* S1ap-Cdma2000OneXSRVCCInfo */
typedef struct S1ap_Cdma2000OneXSRVCCInfo {
	S1ap_Cdma2000OneXMEID_t	 cdma2000OneXMEID;
	S1ap_Cdma2000OneXMSI_t	 cdma2000OneXMSI;
	S1ap_Cdma2000OneXPilot_t	 cdma2000OneXPilot;
	struct S1ap_IE_Extensions	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1ap_Cdma2000OneXSRVCCInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_S1ap_Cdma2000OneXSRVCCInfo;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "S1ap-IE-Extensions.h"

#endif	/* _S1ap_Cdma2000OneXSRVCCInfo_H_ */
#include <asn_internal.h>
