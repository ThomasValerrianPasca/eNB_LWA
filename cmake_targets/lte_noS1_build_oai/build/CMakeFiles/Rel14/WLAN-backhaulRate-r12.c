/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "fixed_grammar.asn"
 * 	`asn1c -gen-PER`
 */

#include "WLAN-backhaulRate-r12.h"

int
WLAN_backhaulRate_r12_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static void
WLAN_backhaulRate_r12_1_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_NativeEnumerated.free_struct;
	td->print_struct   = asn_DEF_NativeEnumerated.print_struct;
	td->ber_decoder    = asn_DEF_NativeEnumerated.ber_decoder;
	td->der_encoder    = asn_DEF_NativeEnumerated.der_encoder;
	td->xer_decoder    = asn_DEF_NativeEnumerated.xer_decoder;
	td->xer_encoder    = asn_DEF_NativeEnumerated.xer_encoder;
	td->uper_decoder   = asn_DEF_NativeEnumerated.uper_decoder;
	td->uper_encoder   = asn_DEF_NativeEnumerated.uper_encoder;
	td->aper_decoder   = asn_DEF_NativeEnumerated.aper_decoder;
	td->aper_encoder   = asn_DEF_NativeEnumerated.aper_encoder;
	td->compare        = asn_DEF_NativeEnumerated.compare;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_NativeEnumerated.per_constraints;
	td->elements       = asn_DEF_NativeEnumerated.elements;
	td->elements_count = asn_DEF_NativeEnumerated.elements_count;
     /* td->specifics      = asn_DEF_NativeEnumerated.specifics;	// Defined explicitly */
}

void
WLAN_backhaulRate_r12_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	WLAN_backhaulRate_r12_1_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

int
WLAN_backhaulRate_r12_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	WLAN_backhaulRate_r12_1_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

asn_dec_rval_t
WLAN_backhaulRate_r12_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	WLAN_backhaulRate_r12_1_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

asn_enc_rval_t
WLAN_backhaulRate_r12_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	WLAN_backhaulRate_r12_1_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

asn_dec_rval_t
WLAN_backhaulRate_r12_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	WLAN_backhaulRate_r12_1_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

asn_enc_rval_t
WLAN_backhaulRate_r12_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	WLAN_backhaulRate_r12_1_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

asn_dec_rval_t
WLAN_backhaulRate_r12_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	WLAN_backhaulRate_r12_1_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

asn_enc_rval_t
WLAN_backhaulRate_r12_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	WLAN_backhaulRate_r12_1_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

asn_enc_rval_t
WLAN_backhaulRate_r12_encode_aper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	WLAN_backhaulRate_r12_1_inherit_TYPE_descriptor(td);
	return td->aper_encoder(td, constraints, structure, per_out);
}

asn_comp_rval_t * 
WLAN_backhaulRate_r12_compare(asn_TYPE_descriptor_t *td1,
		const void *structure1,
		asn_TYPE_descriptor_t *td2,
		const void *structure2) {
	asn_comp_rval_t * res  = NULL;
	WLAN_backhaulRate_r12_1_inherit_TYPE_descriptor(td1);
	WLAN_backhaulRate_r12_1_inherit_TYPE_descriptor(td2);
	res = td1->compare(td1, structure1, td2, structure2);
	return res;
}

asn_dec_rval_t
WLAN_backhaulRate_r12_decode_aper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	WLAN_backhaulRate_r12_1_inherit_TYPE_descriptor(td);
	return td->aper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_per_constraints_t asn_PER_type_WLAN_backhaulRate_r12_constr_1 GCC_NOTUSED = {
	{ APC_CONSTRAINED,	 5,  5,  0,  31 }	/* (0..31) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_WLAN_backhaulRate_r12_value2enum_1[] = {
	{ 0,	2,	"r0" },
	{ 1,	2,	"r4" },
	{ 2,	2,	"r8" },
	{ 3,	3,	"r16" },
	{ 4,	3,	"r32" },
	{ 5,	3,	"r64" },
	{ 6,	4,	"r128" },
	{ 7,	4,	"r256" },
	{ 8,	4,	"r512" },
	{ 9,	5,	"r1024" },
	{ 10,	5,	"r2048" },
	{ 11,	5,	"r4096" },
	{ 12,	5,	"r8192" },
	{ 13,	6,	"r16384" },
	{ 14,	6,	"r32768" },
	{ 15,	6,	"r65536" },
	{ 16,	7,	"r131072" },
	{ 17,	7,	"r262144" },
	{ 18,	7,	"r524288" },
	{ 19,	8,	"r1048576" },
	{ 20,	8,	"r2097152" },
	{ 21,	8,	"r4194304" },
	{ 22,	8,	"r8388608" },
	{ 23,	9,	"r16777216" },
	{ 24,	9,	"r33554432" },
	{ 25,	9,	"r67108864" },
	{ 26,	10,	"r134217728" },
	{ 27,	10,	"r268435456" },
	{ 28,	10,	"r536870912" },
	{ 29,	11,	"r1073741824" },
	{ 30,	11,	"r2147483648" },
	{ 31,	11,	"r4294967296" }
};
static unsigned int asn_MAP_WLAN_backhaulRate_r12_enum2value_1[] = {
	0,	/* r0(0) */
	9,	/* r1024(9) */
	19,	/* r1048576(19) */
	29,	/* r1073741824(29) */
	6,	/* r128(6) */
	16,	/* r131072(16) */
	26,	/* r134217728(26) */
	3,	/* r16(3) */
	13,	/* r16384(13) */
	23,	/* r16777216(23) */
	10,	/* r2048(10) */
	20,	/* r2097152(20) */
	30,	/* r2147483648(30) */
	7,	/* r256(7) */
	17,	/* r262144(17) */
	27,	/* r268435456(27) */
	4,	/* r32(4) */
	14,	/* r32768(14) */
	24,	/* r33554432(24) */
	1,	/* r4(1) */
	11,	/* r4096(11) */
	21,	/* r4194304(21) */
	31,	/* r4294967296(31) */
	8,	/* r512(8) */
	18,	/* r524288(18) */
	28,	/* r536870912(28) */
	5,	/* r64(5) */
	15,	/* r65536(15) */
	25,	/* r67108864(25) */
	2,	/* r8(2) */
	12,	/* r8192(12) */
	22	/* r8388608(22) */
};
static asn_INTEGER_specifics_t asn_SPC_WLAN_backhaulRate_r12_specs_1 = {
	asn_MAP_WLAN_backhaulRate_r12_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_WLAN_backhaulRate_r12_enum2value_1,	/* N => "tag"; sorted by N */
	32,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_WLAN_backhaulRate_r12_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_WLAN_backhaulRate_r12 = {
	"WLAN-backhaulRate-r12",
	"WLAN-backhaulRate-r12",
	WLAN_backhaulRate_r12_free,
	WLAN_backhaulRate_r12_print,
	WLAN_backhaulRate_r12_constraint,
	WLAN_backhaulRate_r12_decode_ber,
	WLAN_backhaulRate_r12_encode_der,
	WLAN_backhaulRate_r12_decode_xer,
	WLAN_backhaulRate_r12_encode_xer,
	WLAN_backhaulRate_r12_decode_uper,
	WLAN_backhaulRate_r12_encode_uper,
	WLAN_backhaulRate_r12_decode_aper,
	WLAN_backhaulRate_r12_encode_aper,
	WLAN_backhaulRate_r12_compare,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_WLAN_backhaulRate_r12_tags_1,
	sizeof(asn_DEF_WLAN_backhaulRate_r12_tags_1)
		/sizeof(asn_DEF_WLAN_backhaulRate_r12_tags_1[0]), /* 1 */
	asn_DEF_WLAN_backhaulRate_r12_tags_1,	/* Same as above */
	sizeof(asn_DEF_WLAN_backhaulRate_r12_tags_1)
		/sizeof(asn_DEF_WLAN_backhaulRate_r12_tags_1[0]), /* 1 */
	&asn_PER_type_WLAN_backhaulRate_r12_constr_1,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_WLAN_backhaulRate_r12_specs_1	/* Additional specs */
};

