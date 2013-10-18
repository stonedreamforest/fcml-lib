/*
 * fcml_modrm_decoder.h
 *
 *  Created on: 19-05-2013
 *      Author: tAs
 */

#ifndef FCML_MODRM_DECODER_H_
#define FCML_MODRM_DECODER_H_

#include "fcml_ceh.h"
#include "fcml_modrm.h"

// Macros.

#define FCML_MODRM_DEC_MOD(x)			( x >> 6 )
#define FCML_MODRM_DEC_REG_OPCODE(x)	( ( x & 0x38 ) >> 3 )
#define FCML_MODRM_DEC_RM(x)			( x & 0x07 )

#define FCML_MODRM_SIB_SS(x)			( x >> 6 )
#define FCML_MODRM_SIB_INDEX(x)			( ( x & 0x38 ) >> 3 )
#define FCML_MODRM_SIB_BASE(x)			( x & 0x07 )

#define FCML_REX_W(x)					FCML_TP_GET_BIT(x, 3)
#define FCML_REX_R(x)					FCML_TP_GET_BIT(x, 2)
#define FCML_REX_X(x)					FCML_TP_GET_BIT(x, 1)
#define FCML_REX_B(x)					FCML_TP_GET_BIT(x, 0)

typedef struct fcml_st_modrm_decoder_context {
	// Sets 32 or 64 bit addressing mode.
	fcml_en_addr_form addr_form;
	// Effective address size using to decode/encode ModR/M. It's very important to set this value properly,
	// because 16 and 32/64 addressing forms
	fcml_data_size effective_address_size;
	// This flag is set only by ModR/M encoder if there is alternative SIB encoding available,
	// but user chooses default ModR/M only encoding.
	fcml_bool is_sib_alternative;
	// This flag is used only by ModR/M encoder, and should be set to TRUE to force
	// using SIB encoding, if there is such alternative.
	fcml_bool choose_sib_encoding;
	// True if displacement should be used to calculate RIP-relative effective address.
	fcml_bool is_rip;
} fcml_st_modrm_decoder_context;

fcml_ceh_error fcml_fn_modrm_decode( fcml_st_modrm_decoder_context *context, fcml_st_modrm_source *modrm_source, fcml_st_modrm *decoded_modrm );
fcml_ceh_error fcml_fn_modrm_decode_rip( fcml_uint64_t rip, fcml_data_size effective_address_size, fcml_st_offset *offset, fcml_st_offset *address );

#endif /* FCML_MODRM_DECODER_H_ */
