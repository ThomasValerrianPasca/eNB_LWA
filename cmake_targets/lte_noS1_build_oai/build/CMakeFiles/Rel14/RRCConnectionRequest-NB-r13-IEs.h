/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "NBIOT-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_RRCConnectionRequest_NB_r13_IEs_H_
#define	_RRCConnectionRequest_NB_r13_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include "InitialUE-Identity.h"
#include "EstablishmentCause-NB-r13.h"
#include <NativeEnumerated.h>
#include <BIT_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RRCConnectionRequest_NB_r13_IEs__multiToneSupport_r13 {
	RRCConnectionRequest_NB_r13_IEs__multiToneSupport_r13_true	= 0
} e_RRCConnectionRequest_NB_r13_IEs__multiToneSupport_r13;
typedef enum RRCConnectionRequest_NB_r13_IEs__multiCarrierSupport_r13 {
	RRCConnectionRequest_NB_r13_IEs__multiCarrierSupport_r13_true	= 0
} e_RRCConnectionRequest_NB_r13_IEs__multiCarrierSupport_r13;

/* RRCConnectionRequest-NB-r13-IEs */
typedef struct RRCConnectionRequest_NB_r13_IEs {
	InitialUE_Identity_t	 ue_Identity_r13;
	EstablishmentCause_NB_r13_t	 establishmentCause_r13;
	long	*multiToneSupport_r13	/* OPTIONAL */;
	long	*multiCarrierSupport_r13	/* OPTIONAL */;
	BIT_STRING_t	 spare;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RRCConnectionRequest_NB_r13_IEs_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_multiToneSupport_r13_4;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_multiCarrierSupport_r13_6;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_RRCConnectionRequest_NB_r13_IEs;

#ifdef __cplusplus
}
#endif

#endif	/* _RRCConnectionRequest_NB_r13_IEs_H_ */
#include <asn_internal.h>
