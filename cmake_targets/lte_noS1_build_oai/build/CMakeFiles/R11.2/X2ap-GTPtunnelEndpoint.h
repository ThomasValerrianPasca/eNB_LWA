/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "X2AP-IEs"
 * 	found in "/home/oai/Downloads/LWA/openair2/X2AP/MESSAGES/ASN1/R11.2/X2AP-IEs.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_X2ap_GTPtunnelEndpoint_H_
#define	_X2ap_GTPtunnelEndpoint_H_


#include <asn_application.h>

/* Including external dependencies */
#include "X2ap-TransportLayerAddress.h"
#include "X2ap-GTP-TEI.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct X2ap_IE_Extensions;

/* X2ap-GTPtunnelEndpoint */
typedef struct X2ap_GTPtunnelEndpoint {
	X2ap_TransportLayerAddress_t	 transportLayerAddress;
	X2ap_GTP_TEI_t	 gTP_TEID;
	struct X2ap_IE_Extensions	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} X2ap_GTPtunnelEndpoint_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_X2ap_GTPtunnelEndpoint;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "X2ap-IE-Extensions.h"

#endif	/* _X2ap_GTPtunnelEndpoint_H_ */
#include <asn_internal.h>
