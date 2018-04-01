/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_SupportedBandCombination_v1270_H_
#define	_SupportedBandCombination_v1270_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct BandCombinationParameters_v1270;

/* SupportedBandCombination-v1270 */
typedef struct SupportedBandCombination_v1270 {
	A_SEQUENCE_OF(struct BandCombinationParameters_v1270) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SupportedBandCombination_v1270_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SupportedBandCombination_v1270;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "BandCombinationParameters-v1270.h"

#endif	/* _SupportedBandCombination_v1270_H_ */
#include <asn_internal.h>
