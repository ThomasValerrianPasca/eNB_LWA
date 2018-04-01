/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_MMEC_H_
#define	_MMEC_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* MMEC */
typedef BIT_STRING_t	 MMEC_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MMEC;
asn_struct_free_f MMEC_free;
asn_struct_print_f MMEC_print;
asn_constr_check_f MMEC_constraint;
ber_type_decoder_f MMEC_decode_ber;
der_type_encoder_f MMEC_encode_der;
xer_type_decoder_f MMEC_decode_xer;
xer_type_encoder_f MMEC_encode_xer;
per_type_decoder_f MMEC_decode_uper;
per_type_encoder_f MMEC_encode_uper;
per_type_decoder_f MMEC_decode_aper;
per_type_encoder_f MMEC_encode_aper;
type_compare_f     MMEC_compare;

#ifdef __cplusplus
}
#endif

#endif	/* _MMEC_H_ */
#include <asn_internal.h>
