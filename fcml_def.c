/*
 * ira_def.c
 *
 *  Created on: 19-11-2010
 *      Author: Slawomir Wojtasiak
 */

#include "fcml_def.h"

// Instruction descriptions.

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_AAA[] = {
	{ NULL, 0x0000, 0x00440000, { 0x37, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_AAD[] = {
	{ NULL, 0x0000, 0x00580000, { 0xD5, 0x0A, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0000, 0x00440000, { 0xD5, 0x00, 0x00 }, { FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_AAM[] = {
	{ NULL, 0x0001, 0x00580000, { 0xD4, 0x0A, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x00440000, { 0xD4, 0x00, 0x00 }, { FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_AAS[] = {
	{ NULL, 0x0001, 0x00440000, { 0x3F, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ADC[] = {
	// 14 ib ADC AL, imm8 C Valid Valid Add with carry imm8 to AL.
	{ NULL, 0x0000, 0x00C40000, { 0x14, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 15 iw ADC AX, imm16 C Valid Valid Add with carry imm16 to AX.
	// 15 id ADC EAX, imm32 C Valid Valid Add with carry imm32 to EAX.
	{ NULL, 0x0010, 0x00C40000, { 0x15, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 15 id ADC RAX, imm32 C Valid N.E. Add with carry imm32 sign extended to 64-bits to RAX.
	{ NULL, 0x0008, 0x04840000, { 0x15, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 80 /2 ib ADC r/m8, imm8 B Valid Valid Add with carry imm8 to r/m8.
	// REX + 80 /2 ib ADC r/m8*, imm8 B Valid N.E. Add with carry imm8 to r/m8.
	{ NULL, 0x0000, 0x00C59000, { 0x80, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 81 /2 iw ADC r/m16, imm16 B Valid Valid Add with carry imm16 to r/m16.
	// 81 /2 id ADC r/m32, imm32 B Valid Valid Add with CF imm32 to r/m32.
	{ NULL, 0x0010, 0x03C59000, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 81 /2 id ADC r/m64, imm32 B Valid N.E. Add with CF imm32 sign extended to 64-bits to r/m64.
	{ NULL, 0x0008, 0x04859000, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 83 /2 ib ADC r/m16, imm8 B Valid Valid Add with CF sign-extended imm8 to r/m16.
	// 83 /2 ib ADC r/m32, imm8 B Valid Valid Add with CF sign-extended imm8 into r/m32.
	{ NULL, 0x0010, 0x00C59000, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 83 /2 ib ADC r/m64, imm8 B Valid N.E. Add with CF sign-extended imm8 into r/m64.
	{ NULL, 0x0008, 0x04859000, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 10 /r ADC r/m8, r8 A Valid Valid Add with carry byte register to r/m8.
	// REX + 10 /r ADC r/m8*, r8* A Valid N.E. Add with carry byte register to r/m64.
	{ NULL, 0x0000, 0x00C48000, { 0x10, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_MODRM_R_8, FCML_NA, FCML_NA, FCML_NA } },
	// 11 /r ADC r/m16, r16 A Valid Valid Add with carry r16 to r/m16.
	// 11 /r ADC r/m32, r32 A Valid Valid Add with CF r32 to r/m32.
	// REX.W + 11 /r ADC r/m64, r64 A Valid N.E. Add with CF r64 to r/m64.
	{ NULL, 0x0000, 0x00C48000, { 0x11, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
	// 12 /r ADC r8, r/m8 A Valid Valid Add with carry r/m8 to byte register.
	// REX + 12 /r ADC r8*, r/m8* A Valid N.E. Add with carry r/m64 to byte register.
	{ NULL, 0x0000, 0x00C48000, { 0x12, 0x00, 0x00 }, { FCML_OP_MODRM_R_8_W, FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA } },
	// 13 /r ADC r16, r/m16 A Valid Valid Add with carry r/m16 to r16.
	// 13 /r ADC r32, r/m32 A Valid Valid Add with CF r/m32 to r32.
	// REX.W + 13 /r ADC r64, r/m64 A Valid N.E. Add with CF r/m64 to r64.
	{ NULL, 0x0000, 0x00C48000, { 0x13, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ADD[] = {
	// 04 ib ADD AL, imm8 C Valid Valid Add imm8 to AL..
	{ NULL, 0x0000, 0x00C40000, { 0x04, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 05 iw ADD AX, imm16 C Valid Valid Add imm16 to AX.
	// 05 id ADD EAX, imm32 C Valid Valid Add imm32 to EAX.
	{ NULL, 0x0010, 0x03C40000, { 0x05, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 05 id ADD RAX, imm32 C Valid N.E. Add imm32 sign-extended to 64-bits to RAX.
	{ NULL, 0x0008, 0x04840000, { 0x05, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 80 /0 ib ADD r/m8, imm8 B Valid Valid Add imm8 to r/m8.
	// REX + 80 /0 ib ADD r/m8*, imm8 B Valid N.E. Add sign-extended imm8 to r/m64.
	{ NULL, 0x0000, 0x00C58000, { 0x80, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 81 /0 iw ADD r/m16, imm16 B Valid Valid Add imm16 to r/m16.
	// 81 /0 id ADD r/m32, imm32 B Valid Valid Add imm32 to r/m32.
	{ NULL, 0x0010, 0x03C58000, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 81 /0 id ADD r/m64, imm32 B Valid N.E. Add imm32 sign-extended to 64-bits to r/m64.
	{ NULL, 0x0008, 0x04858000, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 83 /0 ib ADD r/m16, imm8 B Valid Valid Add sign-extended imm8 to r/m16.
	// 83 /0 ib ADD r/m32, imm8 B Valid Valid Add sign-extended imm8 to r/m32.
	{ NULL, 0x0010, 0x03C58000, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 83 /0 ib ADD r/m64, imm8 B Valid N.E. Add sign-extended imm8 to r/m64.
	{ NULL, 0x0008, 0x04858000, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 00 /r ADD r/m8, r8 A Valid Valid Add r8 to r/m8.
	// REX + 00 /r ADD r/m8*, r8* A Valid N.E. Add r8 to r/m8.
	{ NULL, 0x0000, 0x00C48000, { 0x00, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_MODRM_R_8, FCML_NA, FCML_NA, FCML_NA } },
	// 01 /r ADD r/m16, r16 A Valid Valid Add r16 to r/m16.
	// 01 /r ADD r/m32, r32 A Valid Valid Add r32 to r/m32.
	// REX.W + 01 /r ADD r/m64, r64 A Valid N.E. Add r64 to r/m64.
	{ NULL, 0x0000, 0x00C48000, { 0x01, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
	// 02 /r ADD r8, r/m8 A Valid Valid Add r/m8 to r8.
	// REX + 02 /r ADD r8*, r/m8* A Valid N.E. Add r/m8 to r8.
	{ NULL, 0x0000, 0x00C48000, { 0x02, 0x00, 0x00 }, { FCML_OP_MODRM_R_8_W, FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA } },
	// 03 /r ADD r16, r/m16 A Valid Valid Add r/m16 to r16.
	// 03 /r ADD r32, r/m32 A Valid Valid Add r/m32 to r32.
	// REX.W + 03 /r ADD r64, r/m64 A Valid N.E. Add r/m64 to r64.
	{ NULL, 0x0000, 0x00C48000, { 0x03, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ADDPD[] = {
	// 66 0F 58 /r ADDPD xmm1, xmm2/m128 A Valid Valid Add packed double-precision floating-point values from xmm2/m128 to xmm1.
	{ NULL, 0x1000, 0x00D88000, { 0x0F, 0x58, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 58 /r VADDPD xmm1, xmm2, xmm3/m128 V/V AVX Add packed double-precision floating-point values from xmm3/mem to xmm2 and stores result in xmm1.
	// VEX.NDS.256.66.0F.WIG 58 /r VADDPD ymm1, ymm2, ymm3/m256 Add packed double-precision floating-point values from ymm3/mem to ymm2 and stores result in ymm1.
	{ "vaddpd", 0x1080, 0x00D88000, { 0x0F, 0x58, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ADDPS[] = {
	// 0F 58 /r ADDPS xmm1, xmm2/m128 A Valid Valid Add packed single-precision floating-point values from xmm2/m128 to xmm1.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x58, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F 58 /r VADDPS xmm1,xmm2, xmm3/m128
	// VEX.NDS.256.0F 58 /r VADDPS ymm1, ymm2, ymm3/m256
	{ "vaddps", 0x0080, 0x00D88000, { 0x0F, 0x58, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ADDSD[] = {
	// F2 0F 58 /r ADDSD xmm1, xmm2/m64 A Valid Valid Add the low doubleprecision floating-point value from xmm2/m64 to xmm1.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0x58, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F 58 /r VADDSD xmm1,xmm2,xmm3/m64
	{ "vaddsd", 0x20C0, 0x00D88000, { 0x0F, 0x58, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ADDSS[] = {
	// F3 0F 58 /r ADDSS xmm1, xmm2/m32 A Valid Valid Add the low single-precision floating-point value from xmm2/m32 to xmm1.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x58, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F3.0F 58 /r VADDSS xmm1,xmm2, xmm3/m32
	{ "vaddss", 0x40C0, 0x00D88000, { 0x0F, 0x58, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_32, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ADDSUBPD[] = {
	//66 0F D0 /r ADDSUBPD xmm1, xmm2/m128 A Valid Valid Add/subtract doubleprecision floating-point values from xmm2/m128 to xmm1.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xD0, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F D0 /r VADDSUBPD xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F D0 /r VADDSUBPD ymm1,ymm2,ymm3/m256
	{ "vaddsubpd", 0x1080, 0x00D88000, { 0x0F, 0xD0, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ADDSUBPS[] = {
	// F2 0F D0 /r ADDSUBPS xmm1, xmm2/m128 A Valid Valid Add/subtract singleprecision floating-point values from xmm2/m128 to xmm1.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0xD0, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F D0 /r VADDSUBPS xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.F2.0F D0 /r VADDSUBPS ymm1, ymm2,ymm3/m256
	{ "vaddsubps", 0x2080, 0x00D88000, { 0x0F, 0xD0, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_AESDEC[] = {
	// 66 0F 38 DE /r AESDEC xmm1,xmm2/m128
	{ NULL, 0x1000, 0x00EC8000, { 0x0F, 0x38, 0xDE }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG DE /r VAESDEC xmm1,xmm2,xmm3/m128
	{ "vaesdec", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0xDE }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_AESDECLAST[] = {
	// 66 0F 38 DF /r AESDECLAST xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0xDF }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG DF /r VAESDECLAST xmm1,xmm2,xmm3/m128
	{ "vaesdeclast", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0xDF }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_AESENC[] = {
	// 66 0F 38 DC /r AESENC xmm1, xmm2/m128 A Valid Valid Perform one round of an AES encryption flow, operating on a 128-bit data (state) from xmm1 with a 128-bit round key from xmm2/m128.
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0xDC }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG DC /r VAESENC xmm1, xmm2, xmm3/m128
	{ "vaesenc", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0xDC }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_AESENCLAST[] = {
	//66 0F 38 DD /r AESENCLAST xmm1, xmm2/m128 A Valid Valid Perform the last round of an AES encryption flow, operating on a 128-bit data (state) from xmm1 with a 128-bit round key from xmm2/m128.
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0xDD }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG DD /r VAESENCLAST xmm1,xmm2,xmm3/m128
	{ "vaesenclast", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0xDD }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_AESIMC[] = {
	// 66 0F 38 DB /r AESIMC xmm1, xmm2/m128 A Valid Valid Perform the InvMixColumn transformation on a 128-bit round key from xmm2/m128 and store the result in xmm1.
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0xDB }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG DB /r VAESIMC xmm1, xmm2/m128
	{ "vaesimc", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0xDB }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_AESKEYGENASSIST[] = {
	// 66 0F 3A DF /r ib AESKEYGENASSIST xmm1, xmm2/m128, imm8 A Valid Valid Assist in AES round key generation using an 8 bits Round Constant (RCON) specified in the immediate byte, operating on 128 bits of data specified in xmm2/m128 and stores the result in xmm1.
	{ NULL, 0x1000, 0x00EC8000, { 0x0F, 0x3A, 0xDF }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A.WIG DF /r ib VAESKEYGENASSIST xmm1,xmm2/m128,imm8
	{ "vaeskeygenassist", 0x11C0, 0x00EC8000, { 0x0F, 0x3A, 0xDF }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_AND[] = {
	// 24 ib AND AL, imm8 C Valid Valid AL AND imm8.
	{ NULL, 0x0000, 0x00C40000, { 0x24, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 25 iw AND AX, imm16 C Valid Valid AX AND imm16.
	// 25 id AND EAX, imm32 C Valid Valid EAX AND imm32.
	{ NULL, 0x0010, 0x03C40000, { 0x25, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 25 id AND RAX, imm32 C Valid N.E. RAX AND imm32 signextended to 64-bits.
	{ NULL, 0x0008, 0x04840000, { 0x25, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 80 /4 ib AND r/m8, imm8 MR Valid Valid r/m8 AND imm8.
	// REX + 80 /4 ib AND r/m8*, imm8 MR Valid N.E. r/m8 AND imm8.
	{ NULL, 0x0000, 0x00C5A000, { 0x80, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 81 /4 iw AND r/m16, imm16 B Valid Valid r/m16 AND imm16.
	// 81 /4 id AND r/m32, imm32 B Valid Valid r/m32 AND imm32.
	{ NULL, 0x0010, 0x03C5A000, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 81 /4 id AND r/m64, imm32 B Valid N.E. r/m64 AND imm32 sign extended to 64-bits.
	{ NULL, 0x0008, 0x0485A000, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 83 /4 ib AND r/m16, imm8 B Valid Valid r/m16 AND imm8 (signextended).
	// 83 /4 ib AND r/m32, imm8 B Valid Valid r/m32 AND imm8 (signextended).
	{ NULL, 0x0010, 0x03C5A000, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 83 /4 ib AND r/m64, imm8 B Valid N.E. r/m64 AND imm8 (signextended).
	{ NULL, 0x0008, 0x0485A000, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 20 /r AND r/m8, r8 A Valid Valid r/m8 AND r8.
	// REX + 20 /r AND r/m8*, r8* A Valid N.E. r/m64 AND r8 (signextended).
	{ NULL, 0x0000, 0x00C48000, { 0x20, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_MODRM_R_8, FCML_NA, FCML_NA, FCML_NA } },
	// 21 /r AND r/m16, r16 A Valid Valid r/m16 AND r16.
	// 21 /r AND r/m32, r32 A Valid Valid r/m32 AND r32.
	// REX.W + 21 /r AND r/m64, r64 A Valid N.E. r/m64 AND r32.
	{ NULL, 0x0000, 0x00C48000, { 0x21, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
	// 22 /r AND r8, r/m8 A Valid Valid r8 AND r/m8.
	// REX + 22 /r AND r8*, r/m8* A Valid N.E. r/m64 AND r8 (signextended).
	{ NULL, 0x0000, 0x00C48000, { 0x22, 0x00, 0x00 }, { FCML_OP_MODRM_R_8_W, FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA } },
	// 23 /r AND r16, r/m16 A Valid Valid r16 AND r/m16.
	// 23 /r AND r32, r/m32 A Valid Valid r32 AND r/m32.
	// REX.W + 23 /r AND r64, r/m64 A Valid N.E. r64 AND r/m64.
	{ NULL, 0x0000, 0x00C48000, { 0x23, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ANDPD[] = {
	// 66 0F 54 /r ANDPD xmm1, xmm2/m128 A Valid Valid Bitwise logical AND of xmm2/m128 and xmm1.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x54, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F 54 /r VANDPD xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F 54 /r VANDPD ymm1,ymm2,ymm3/m256
	{ "vandpd", 0x1080, 0x00D88000, { 0x0F, 0x54, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ANDPS[] = {
	// 0F 54 /r ANDPS xmm1, xmm2/m128 A Valid Valid Bitwise logical AND of xmm2/m128 and xmm1.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x54, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F 54 /r VANDPS xmm1,xmm2, xmm3/m128
	// VEX.NDS.256.0F 54 /r VANDPS ymm1, ymm2, ymm3/m256
	{ "vandps", 0x0080, 0x00D88000, { 0x0F, 0x54, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ANDNPD[] = {
	// 66 0F 55 /r ANDNPD xmm1, xmm2/m128 A Valid Valid Bitwise logical AND NOT of xmm2/m128 and xmm1.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x55, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F 55 /r VANDNPD xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F 55 /r VANDNPD ymm1,ymm2,ymm3/m256
	{ "vandnpd", 0x1080, 0x00D88000, { 0x0F, 0x55, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ANDNPS[] = {
	// 0F 55 /r ANDNPS xmm1, xmm2/m128 A Valid Valid Bitwise logical AND NOT of xmm2/m128 and xmm1.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x55, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F 55 /r VANDNPS xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.0F 55 /r VANDNPS ymm1,ymm2,ymm3/m256
	{ "vandnps", 0x0080, 0x00D88000, { 0x0F, 0x55, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ARPL[] = {
	// 63 /r ARPL r/m16, r16 A N. E. Valid Adjust RPL of r/m16 to not less than RPL of r16.
	{ NULL, 0x0001, 0x00448000, { 0x63, 0x00, 0x00 }, { FCML_OP_MODRM_RM_16, FCML_OP_MODRM_R_16, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLENDPD[] = {
	// 66 0F 3A 0D /r ib BLENDPD xmm1, xmm2/m128, imm8 A Valid Valid Select packed DP-FP values from xmm1 and xmm2/m128 from mask specified in imm8 and store the values into xmm1.
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x0D }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F3A 0D /r ib VBLENDPD xmm1,xmm2,xmm3/m128,imm8
	// VEX.NDS.256.66.0F3A 0D /r ib VBLENDPD ymm1,ymm2,ymm3/m256,imm8
	{ "vblendpd", 0x1080, 0x00EC8000, { 0x0F, 0x3A, 0x0D }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLENDPS[] = {
	// 66 0F 3A 0C /r ib BLENDPS xmm1, xmm2/m128, imm8 A Valid Valid Select packed single precision floating-point values from xmm1 and xmm2/m128 from mask specified in imm8 and store the values into xmm1.
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x0C }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F3A 0C /r ib VBLENDPS xmm1,xmm2,xmm3/m128,imm8
	// VEX.NDS.256.66.0F3A 0C /r ib VBLENDPS ymm1,ymm2,ymm3/m256,imm8
	{ "vblendps", 0x1080, 0x00EC8000, { 0x0F, 0x3A, 0x0C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLENDVPD[] = {
	// 66 0F 38 15 /r BLENDVPD xmm1, xmm2/m128 , <XMM0> A Valid Valid Select packed DP FP values from xmm1 and xmm2 from mask specified in XMM0 and store the values in xmm1.
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x15 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_EXPLICIT_REG( FCML_REG_SIMD, FCML_REG_XMM0, FCML_EOS_OWORD ), FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F3A 4B /r /is4 VBLENDVPD xmm1, xmm2, xmm3/m128, xmm4
	// VEX.NDS.256.66.0F3A 4B /r /is4 VBLENDVPD ymm1, ymm2, ymm3/m256, ymm4
	{ "vblendvpd", 0x1080, 0x00EC8000, { 0x0F, 0x3A, 0x4B }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLENDVPS[] = {
	// 66 0F 38 14 /r BLENDVPS xmm1, xmm2/m128, <XMM0> A Valid Valid Select packed single precision floating-point values from xmm1 and xmm2/m128 from mask specified in XMM0 and store the values into xmm1.
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x14 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_EXPLICIT_REG( FCML_REG_SIMD, FCML_REG_XMM0, FCML_EOS_OWORD ), FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F3A 4A /r /is4 VBLENDVPS xmm1, xmm2, xmm3/m128, xmm4
	// VEX.NDS.256.66.0F3A 4A /r /is4 VBLENDVPS ymm1, ymm2, ymm3/m256, ymm4
	{ "vblendvps", 0x1080, 0x00EC8000, { 0x0F, 0x3A, 0x4A }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VBROADCASTSS[] = {
	// VEX.128.66.0F38 18 /r VBROADCASTSS xmm1, m32
	// VEX.256.66.0F38 18 /r VBROADCASTSS ymm1, m32
	{ NULL, 0x1000, 0x80EC8000, { 0x0F, 0x38, 0x18 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38 19 /r VBROADCASTSD ymm1, m64
	{ "vbroadcastsd", 0x11A0, 0x80EC8000, { 0x0F, 0x38, 0x19 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.W0 1A /r VBROADCASTF128 ymm1,m128
	{ "vbroadcastf128", 0x11B0, 0x80EC8000, { 0x0F, 0x38, 0x1A }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_M_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.W0 5A /r VBROADCASTI128 ymm1,m128
	{ "vbroadcasti128", 0x11B0, 0x80EC8000, { 0x0F, 0x38, 0x5A }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_M_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.W0 18 /r VBROADCASTSS xmm1,xmm2
	// VEX.256.66.0F38.W0 18 /r VBROADCASTSS ymm1,xmm2
	{ "vbroadcastss", 0x1180, 0x00EE8000, { 0x0F, 0x38, 0x18 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.W0 19 /r VBROADCASTSD ymm1,xmm2
	{ "vbroadcastsd", 0x11A0, 0x00EE8000, { 0x0F, 0x38, 0x19 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPBROADCAST[] = {
	// VEX.128.66.0F38.W0 78 /r VPBROADCASTB xmm1,xmm2/m8
	// VEX.256.66.0F38.W0 78 /r VPBROADCASTB ymm1,xmm2/m8
	{ "vpbroadcastb", 0x1190, 0x00EC8000, { 0x0F, 0x38, 0x78 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L_8, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.W0 79 /r VPBROADCASTW xmm1,xmm2/m16
	// VEX.256.66.0F38.W0 79 /r VPBROADCASTW ymm1,xmm2/m16
	{ "vpbroadcastw", 0x1190, 0x00EC8000, { 0x0F, 0x38, 0x79 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L_16, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.W0 58 /r VPBROADCASTD xmm1,xmm2/m32
	// VEX.256.66.0F38.W0 58 /r VPBROADCASTD ymm1,xmm2/m32
	{ "vpbroadcastd", 0x1190, 0x00EC8000, { 0x0F, 0x38, 0x58 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.W0 59 /r VPBROADCASTQ xmm1,xmm2/m64
	// VEX.256.66.0F38.W0 59 /r VPBROADCASTQ ymm1,xmm2/m64
	{ "vpbroadcastq", 0x1190, 0x00EC8000, { 0x0F, 0x38, 0x59 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BOUND[] = {
	// 62 /r BOUND r16, m16&16 A Invalid Valid Check if r16 (array index) is within bounds specified by m16&16.
	// 62 /r BOUND r32, m32&32 A Invalid Valid Check if r32 (array index) is within bounds specified by m16&16.
	{ NULL, 0x0001, 0x00448000, { 0x62 }, { FCML_OP_MODRM_R, FCML_OP_MODRM_MM_OSA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BSF[] = {
	// 0F BC /r BSF r16, r/m16 A Valid Valid Bit scan forward on r/m16.
	// 0F BC /r BSF r32, r/m32 A Valid Valid Bit scan forward on r/m32.
	// REX.W + 0F BC BSF r64, r/m64 A Valid N.E. Bit scan forward on r/m64.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0xBC, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BSR[] = {
	// 0F BD /r BSR r16, r/m16 A Valid Valid Bit scan reverse on r/m16.
	// 0F BD /r BSR r32, r/m32 A Valid Valid Bit scan reverse on r/m32.
	// REX.W + 0F BD BSR r64, r/m64 A Valid N.E. Bit scan reverse on r/m64.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0xBC, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BSWAP[] = {
	// 0F C8+rd BSWAP r32 A Valid* Valid Reverses the byte order of a 32-bit register.
	{ NULL, 0x0000, 0x00D80001, { 0x0F, 0xC8, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_DWORD ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 0F C8+rd BSWAP r64 A Valid N.E. Reverses the byte order of a 64-bit register.
	{ NULL, 0x0008, 0x00980001, { 0x0F, 0xC8, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_QWORD ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BT[] = {
	// 0F A3 BT r/m16, r16 A Valid Valid Store selected bit in CF flag.
	// 0F A3 BT r/m32, r32 A Valid Valid Store selected bit in CF flag.
	// REX.W + 0F A3 BT r/m64, r64 A Valid N.E. Store selected bit in CF flag.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0xA3, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
	// 0F BA /4 ib BT r/m16, imm8 B Valid Valid Store selected bit in CF flag.
	// 0F BA /4 ib BT r/m32, imm8 B Valid Valid Store selected bit in CF flag.
	// REX.W + 0F BA /4 ib BT r/m64, imm8 B Valid N.E. Store selected bit in CF flag.
	{ NULL, 0x0000, 0x00D9A000, { 0x0F, 0xBA, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BTC[] = {
	// 0F BB BTC r/m16, r16 A Valid Valid Store selected bit in CF flag and complement.
	// 0F BB BTC r/m32, r32 A Valid Valid Store selected bit in CF flag and complement.
	// REX.W + 0F BB BTC r/m64, r64 A Valid N.E. Store selected bit in CF flag and complement.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0xBB, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
	// 0F BA /7 ib BTC r/m16, imm8 B Valid Valid Store selected bit in CF flag and complement.
	// 0F BA /7 ib BTC r/m32, imm8 B Valid Valid Store selected bit in CF flag and complement.
	// REX.W + 0F BA /7 ib BTC r/m64, imm8 B Valid N.E. Store selected bit in CF flag and complement.
	{ NULL, 0x0000, 0x00D9B800, { 0x0F, 0xBA, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BTR[] = {
	// 0F B3 BTR r/m16, r16 A Valid Valid Store selected bit in CF flag and clear.
	// 0F B3 BTR r/m32, r32 A Valid Valid Store selected bit in CF flag and clear.
	// REX.W + 0F B3 BTR r/m64, r64 A Valid N.E. Store selected bit in CF flag and clear.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0xB3, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
	// 0F BA /6 ib BTR r/m16, imm8 B Valid Valid Store selected bit in CF flag and clear.
	// 0F BA /6 ib BTR r/m32, imm8 B Valid Valid Store selected bit in CF flag and clear.
	// REX.W + 0F BA /6 ib BTR r/m64, imm8 B Valid N.E. Store selected bit in CF flag and clear.
	{ NULL, 0x0000, 0x00D9B000, { 0x0F, 0xBA, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BTS[] = {
	// 0F AB BTS r/m16, r16 A Valid Valid Store selected bit in CF flag and set.
	// 0F AB BTS r/m32, r32 A Valid Valid Store selected bit in CF flag and set.
	// REX.W + 0F AB BTS r/m64, r64 A Valid N.E. Store selected bit in CF flag and set.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xAB, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
	// 0F BA /5 ib BTS r/m16, imm8 B Valid Valid Store selected bit in CF flag and set.
	// 0F BA /5 ib BTS r/m32, imm8 B Valid Valid Store selected bit in CF flag and set.
	// REX.W + 0F BA /5 ib BTS r/m64, imm8 B Valid N.E. Store selected bit in CF flag and set.
	{ NULL, 0x0001, 0x00D9A800, { 0x0F, 0xBA, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CALL[] = {
	// E8 cw CALL rel16 B N.S. Valid Call near, relative, displacement relative to next instruction.
	// E8 cd CALL rel32 B Valid Valid Call near, relative, displacement relative to next instruction.
	// 32-bit displacement sign extended to 64-bits in 64-bit mode.
	{ NULL, 0x0000, 0x40C40000, { 0xE8, 0x00, 0x00 }, { FCML_OP_IMMEDIATE_DIS_RELATIVE_EOSA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// FF /2 CALL r/m16 B N.E. Valid Call near, absolute indirect, address given in r/m16.
	// FF /2 CALL r/m32 B N.E. Valid Call near, absolute indirect, address given in r/m32.
	// FF /2 CALL r/m64 B Valid N.E. Call near, absolute indirect, address given in r/m64.
	{ NULL, 0x0000, 0x40C59000, { 0xFF, 0x00, 0x00 }, { FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 9A cd CALL ptr16:16 A Invalid Valid Call far, absolute, address given in operand.
	// 9A cp CALL ptr16:32 A Invalid Valid Call far, absolute, address given in operand.
	{ NULL, 0x0000, 0x00440000, { 0x9A, 0x00, 0x00 }, { FCML_OP_FAR_POINTER, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// FF /3 CALL m16:16 B Valid Valid Call far, absolute indirect address given in m16:16.
	// FF /3 CALL m16:32 B Valid Valid In 64-bit mode.
	// REX.W + FF /3 CALL m16:64 B Valid N.E. In 64-bit mode.
	{ NULL, 0x0000, 0x00C59800, { 0xFF, 0x00, 0x00 }, { FCML_OP_FAR_POINTER_INDIRECT, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CBW[] = {
	// 98 CBW A Valid Valid AX  sign-extend of AL.
	{ "cbw", 0x0000, 0x01C40000, { 0x98, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 98 CWDE A Valid Valid EAX  sign-extend of AX.
	{ "cwde", 0x0000, 0x02C40000, { 0x98, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 98 CDQE A Valid N.E. RAX  sign-extend of EAX.
	{ "cdqe", 0x0000, 0x04C40000, { 0x98, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CLC[] = {
	// F8 CLC A Valid Valid Clear CF flag.
	{ NULL, 0x0000, 0x00C40000, { 0xF8, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CLD[] = {
	// F8 CLC A Valid Valid Clear CF flag.
	{ NULL, 0x0000, 0x00C40000, { 0xFC, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CLFLUSH[] = {
	// 0F AE /7 CLFLUSH m8 A Valid Valid Flushes cache line containing m8.
	{ NULL, 0x0000, 0x00D9B800, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_8_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CLI[] = {
	// FA CLI A Valid Valid Clear interrupt flag interrupts disabled when interrupt flag cleared.
	{ NULL, 0x0001, 0x00C40000, { 0xFA, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CLGI[] = {
	// CLGI 0F 01 DD Clears the global interrupt flag (GIF).
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xDD }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CLTS[] = {
	// 0F 06 CLTS A Valid Valid Clears TS flag in CR0.
	{ NULL, 0x0001, 0x00D80000, { 0x0F, 0x06, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CMC[] = {
	// F5 CMC A Valid Valid Complement CF flag. Op/En
	{ NULL, 0x0001, 0x00C40000, { 0xF5, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CMOV[] = {
	// 0F 4X /r CMOVA r16, r/m16 A Valid Valid Move if above (CF=0 and ZF=0).
	// 0F 4X /r CMOVA r32, r/m32 A Valid Valid Move if above (CF=0 and ZF=0).
	// REX.W + 0F 4X /r CMOVA r64, r/m64 A Valid N.E. Move if above (CF=0 and ZF=0).
	{ NULL, 0x0001, 0x00D88040, { 0x0F, 0x40, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_JCXZ[] = {
	// E3 cb JCXZ rel8 A N.E. Valid Jump short if CX register is 0.
	{ "jcxz", 0x0001, 0x08440000, { 0xE3, 0x00, 0x00 }, { FCML_OP_IMMEDIATE_DIS_RELATIVE_R_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// E3 cb JECXZ rel8 A Valid Valid Jump short if ECX register is 0.
	{ "jecxz", 0x0001, 0x50C40000, { 0xE3, 0x00, 0x00 }, { FCML_OP_IMMEDIATE_DIS_RELATIVE_R_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// E3 cb JRCXZ rel8 A Valid N.E. Jump short if RCX register is 0.
	{ "jrcxz", 0x0001, 0x60840000, { 0xE3, 0x00, 0x00 }, { FCML_OP_IMMEDIATE_DIS_RELATIVE_R_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_Jcc[] = {
	// JA rel8 A Valid Valid Jump short if ...
	{ NULL, 0x0001, 0x40C40040, { 0x70, 0x00, 0x00 }, { FCML_OP_IMMEDIATE_DIS_RELATIVE_R_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// JA rel32 A Valid Valid Jump near if ...
	// JAE rel16 A N.S. Valid Jump near if ...
	{ NULL, 0x0001, 0x40D80040, { 0x0F, 0x80, 0x00 }, { FCML_OP_IMMEDIATE_DIS_RELATIVE_EOSA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_JMP[] = {
	// EB cb JMP rel8 A Valid Valid Jump short, RIP = RIP + 8-bit displacement sign extended to 64-bits
	{ NULL, 0x0001, 0x40C40000, { 0xEB, 0x00, 0x00 }, { FCML_OP_IMMEDIATE_DIS_RELATIVE_R_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// E9 cw JMP rel16 A N.S. Valid Jump near, relative, displacement relative to next instruction. Not supported in 64-bit mode.
	// E9 cd JMP rel32 A Valid Valid Jump near, relative, RIP = RIP + 32-bit displacement sign extended to 64-bits
	{ NULL, 0x0001, 0x40C40000, { 0xE9, 0x00, 0x00 }, { FCML_OP_IMMEDIATE_DIS_RELATIVE_EOSA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// FF /4 JMP r/m16 B N.S. Valid Jump near, absolute indirect, address = zero-extended r/m16. Not supported in 64- bit mode.
	// FF /4 JMP r/m32 B N.S. Valid Jump near, absolute indirect, address given in r/m32. Not supported in 64-bit mode.
	// FF /4 JMP r/m64 B Valid N.E. Jump near, absolute indirect, RIP = 64-Bit offset from register or memory
	{ NULL, 0x0001, 0x40C5A000, { 0xFF, 0x00, 0x00 }, { FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// EA cd JMP ptr16:16 A Inv. Valid Jump far, absolute, address given in operand
	// EA cp JMP ptr16:32 A Inv. Valid Jump far, absolute, address given in operand
	{ NULL, 0x0001, 0x00440000, { 0xEA, 0x00, 0x00 }, { FCML_OP_FAR_POINTER, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// FF /5 JMP m16:16 A Valid Valid Jump far, absolute indirect, address given in m16:16
	// FF /5 JMP m16:32 A Valid Valid Jump far, absolute indirect, address given in m16:32.
	// REX.W + FF /5 JMP m16:64 A Valid N.E. Jump far, absolute indirect, address given in m16:64.
	{ NULL, 0x0001, 0x00C5A800, { 0xFF, 0x00, 0x00 }, { FCML_OP_FAR_POINTER_INDIRECT, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CMP[] = {
	// 3C ib CMP AL, imm8 D Valid Valid Compare imm8 with AL.
	{ NULL, 0x0000, 0x00C40000, { 0x3C, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 3D iw CMP AX, imm16 D Valid Valid Compare imm16 with AX.
	// 3D id CMP EAX, imm32 D Valid Valid Compare imm32 with EAX.
	{ NULL, 0x0010, 0x03C40000, { 0x3D, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 3D id CMP RAX, imm32 D Valid N.E. Compare imm32 sign extended to 64-bits with RAX.
	{ NULL, 0x0008, 0x04840000, { 0x3D, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 80 /7 ib CMP r/m8, imm8 C Valid Valid Compare imm8 with r/m8.
	// REX + 80 /7 ib CMP r/m8*, imm8 C Valid N.E. Compare imm8 with r/m8.
	{ NULL, 0x0000, 0x00C5B800, { 0x80, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 81 /7 iw CMP r/m16, imm16 C Valid Valid Compare imm16 with r/m16.
	// 81 /7 id CMP r/m32, imm32 C Valid Valid Compare imm32 with r/m32.
	{ NULL, 0x0010, 0x03C5B800, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 81 /7 id CMP r/m64, imm32 C Valid N.E. Compare imm32 sign extended to 64-bits with r/m64.
	{ NULL, 0x0008, 0x0485B800, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 83 /7 ib CMP r/m16, imm8 C Valid Valid Compare imm8 with r/m16.
	// 83 /7 ib CMP r/m32, imm8 C Valid Valid Compare imm8 with r/m32.
	{ NULL, 0x0010, 0x03C5B800, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 83 /7 ib CMP r/m64, imm8 C Valid N.E. Compare imm8 with r/m64.
	{ NULL, 0x0008, 0x0485B800, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 38 /r CMP r/m8, r8 B Valid Valid Compare r8 with r/m8.
	// REX + 38 /r CMP r/m8*, r8* B Valid N.E. Compare r8 with r/m8.
	{ NULL, 0x0000, 0x00C48000, { 0x38, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_MODRM_R_8, FCML_NA, FCML_NA, FCML_NA } },
	// 39 /r CMP r/m16, r16 B Valid Valid Compare r16 with r/m16.
	// 39 /r CMP r/m32, r32 B Valid Valid Compare r32 with r/m32.
	// REX.W + 39 /r CMP r/m64,r64 B Valid N.E. Compare r64 with r/m64.
	{ NULL, 0x0000, 0x00C48000, { 0x39, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
	// 3A /r CMP r8, r/m8 A Valid Valid Compare r/m8 with r8.
	// REX + 3A /r CMP r8*, r/m8* A Valid N.E. Compare r/m8 with r8.
	{ NULL, 0x0000, 0x00C48000, { 0x3A, 0x00, 0x00 }, { FCML_OP_MODRM_R_8_W, FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA } },
	// 3B /r CMP r16, r/m16 A Valid Valid Compare r/m16 with r16.
	// 3B /r CMP r32, r/m32 A Valid Valid Compare r/m32 with r32.
	// REX.W + 3B /r CMP r64, r/m64 A Valid N.E. Compare r/m64 with r64.
	{ NULL, 0x0000, 0x00C48000, { 0x3B, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CMPPD[] = {
	// 66 0F C2 /r ib CMPPD xmm1, xmm2/m128, imm8 A Valid Valid Compare packed doubleprecision floating-point values in xmm2/m128 and xmm1 using imm8 as comparison predicate.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xC2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F C2 /r ib VCMPPD xmm1, xmm2, xmm3/m128, imm8
	// VEX.NDS.256.66.0F C2 /r ib VCMPPD ymm1, ymm2, ymm3/m256, imm8
	{ "vcmppd", 0x1080, 0x00D88000, { 0x0F, 0xC2, 0x0C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CMPPS[] = {
	// 0F C2 /r ib CMPPS xmm1, xmm2/m128, imm8 A Valid Valid Compare packed singleprecision floating-point values in xmm2/mem and xmm1 using imm8 as comparison predicate.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xC2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F C2 /r ib VCMPPS xmm1, xmm2, xmm3/m128, imm8
	// VEX.NDS.256.0F C2 /r ib VCMPPS ymm1, ymm2, ymm3/m256, imm8
	{ "vcmpps", 0x0080, 0x00D88000, { 0x0F, 0xC2, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CMPS[] = {
	// A6 CMPS m8, m8 A Valid Valid For legacy mode, compare byte at address DS:(E)SI with byte at address ES:(E)DI; For 64-bit mode compare byte at address (R|E)SI to byte at address (R|E)DI. The status flags are set accordingly.
	{ "cmps;cmpsb[ts]", 0x0001, 0x00C40000, { 0xA6, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_SI, FCML_EOS_BYTE, FCML_SEG_ENCODE_REGISTER( FCML_REG_DS, FCML_SEG_ALLOW_OVERRIDE ) ),
			FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_BYTE, FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ),
			FCML_NA, FCML_NA, FCML_NA } },
	// A7 CMPS m16, m16 A Valid Valid For legacy mode, compare word at address DS:(E)SI with word at address ES:(E)DI; For 64-bit mode compare word at address (R|E)SI with word at address (R|E)DI. The status flags are set accordingly.
	// A7 CMPS m32, m32 A Valid Valid For legacy mode, compare dword at address DS:(E)SI at dword at address ES:(E)DI; For 64-bit mode compare dword at address (R|E)SI at dword at address (R|E)DI. The status flags are set accordingly.
	// REX.W + A7 CMPS m64, m64 A Valid N.E. Compares quadword at address (R|E)SI with quadword at address (R|E)DI and sets the status flags accordingly.
	{ "cmps;cmpsw[ts,ow,a*];cmpsd[ts,od,a*];cmpsq[ts,oq,a*]", 0x0001, 0x00C40000, { 0xA7, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_SI, FCML_EOS_EOSA, FCML_SEG_ENCODE_REGISTER( FCML_REG_DS, FCML_SEG_ALLOW_OVERRIDE ) ),
			FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_EOSA, FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ),
			FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CMPSD[] = {
	// F2 0F C2 /r ib CMPSD xmm1, xmm2/m64, imm8 A Valid Valid Compare low double precision floating-point value in xmm2/m64 and xmm1 using imm8 as comparison predicate.
    // Compiler should treat reserved Imm8 values as illegal syntax, it's why appropriate mask is defined.
	{ "cmpsd", 0x2000, 0x00D88000, { 0x0F, 0xC2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_OP_PSEUDO_OP( 0x07 ), FCML_NA, FCML_NA } },
	{ "cmpeqsd[p00];cmpltsd[p01];cmplesd[p02];cmpunordsd[p03];cmpneqsd[p04];cmpnltsd[p05];cmpnlesd[p06];cmpordsd[p07]", 0x2000, 0x00D88000, { 0x0F, 0xC2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_PSEUDO_OP( 0x07 ), FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F C2 /r ib VCMPSD xmm1, xmm2, xmm3/m64, imm8
	{ "vcmpsd", 0x20C0, 0x00D88000, { 0x0F, 0xC2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_64, FCML_OP_PSEUDO_OP( 0x0F ), FCML_NA } },
	{ "vcmpeqsd[p00];vcmpltsd[p01];vcmplesd[p02];vcmpunordsd[p03];vcmpneqsd[p04];vcmpnltsd[p05];vcmpnlesd[p06];vcmpordsd[p07];vcmpeq_uqsd[p08];vcmpngesd[p09];vcmpngtsd[p0a];vcmpfalsesd[p0b];vcmpneq_oqsd[p0c];vcmpgesd[p0d];vcmpgtsd[p0e];vcmptruesd[p0f];vcmpeq_ossd[p10];vcmplt_oqsd[p11];vcmple_oqsd[p12];vcmpunord_ssd[p13];vcmpneq_ussd[p14];vcmpnlt_uqsd[p15];vcmpnle_uqsd[p16];vcmpord_ssd[p17];vcmpeq_ussd[p18];vcmpnge_uqsd[p19];vcmpngt_uqsd[p1a];vcmpfalse_ossd[p1b];vcmpneq_ossd[p1c];vcmpge_oqsd[p1d];vcmpgt_oqsd[p1e];vcmptrue_ussd[p1f]", 0x20C0, 0x00D88000, { 0x0F, 0xC2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_PSEUDO_OP( 0x1F ), FCML_NA } }
};

// TODO Jak bedzie czas doimplementowac Pseudo-Op patrz: dokumentacja VAX.
struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CMPSS[] = {
	// F3 0F C2 /r ib CMPSS xmm1, xmm2/m32, imm8 A Valid Valid Compare low singleprecision floating-point value in xmm2/m32 and xmm1 using imm8 as comparison predicate.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0xC2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F3.0F C2 /r ib VCMPSS xmm1, xmm2, xmm3/m32, imm8
	{ "vcmpss", 0x40C0, 0x00D88000, { 0x0F, 0xC2, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_32, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CMPXCHG[] = {
	// 0F B0/r CMPXCHG r/m8, r8 A Valid Valid* Compare AL with r/m8. If equal, ZF is set and r8 is loaded into r/m8. Else, clear ZF and load r/m8 into AL.
	// REX + 0F B0/r CMPXCHG r/m8**,r8 A Valid N.E. Compare AL with r/m8. If equal, ZF is set and r8 is loaded into r/m8. Else, clear ZF and load r/m8 into AL.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xB0, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_MODRM_R_8, FCML_NA, FCML_NA, FCML_NA } },
	// 0F B1/r CMPXCHG r/m16, r16 A Valid Valid* Compare AX with r/m16. If equal, ZF is set and r16 is loaded into r/m16. Else, clear ZF and load r/m16 into AX.
	// 0F B1/r CMPXCHG r/m32, r32 A Valid Valid* Compare EAX with r/m32. If equal, ZF is set and r32 is loaded into r/m32. Else, clear ZF and load r/m32 into EAX.
	// REX.W + 0F B1/r CMPXCHG r/m64, r64 A Valid N.E. Compare RAX with r/m64. If equal, ZF is set and r64 is loaded into r/m64. Else, clear ZF and load r/m64 into RAX.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xB1, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CMPXCHGxB[] = {
	// 0F C7 /1 m64 CMPXCHG8B m64 A Valid Valid* Compare EDX:EAX with m64. If equal, set ZF and load ECX:EBX into m64. Else, clear ZF and load m64 into EDX:EAX.
	// REX.W + 0F C7 /1 m128 CMPXCHG16B m128 A Valid N.E. Compare RDX:RAX with m128. If equal, set ZF and load RCX:RBX into m128. Else, clear ZF and load m128 into RDX:RAX.
	{ "cmpxchg8b", 0x0001, 0x03D98800, { 0x0F, 0xC7, 0x00 }, { FCML_OP_MODRM_MM_OSA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ "cmpxchg16b", 0x0001, 0x04D98800, { 0x0F, 0xC7, 0x00 }, { FCML_OP_MODRM_MM_OSA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_COMISD[] = {
	// 66 0F 2F /r COMISD xmm1, xmm2/m64 A Valid Valid Compare low doubleprecision floating-point values in xmm1 and xmm2/mem64 and set the EFLAGS flags accordingly.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x2F, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F 2F /r VCOMISD xmm1, xmm2/m64
	{ "vcomisd", 0x11C1, 0x00D88000, { 0x0F, 0x2F, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_COMISS[] = {
	// 0F 2F /r COMISS xmm1, xmm2/m32 A Valid Valid Compare low singleprecision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x2F, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.0F 2F /r VCOMISS xmm1, xmm2/m32
	{ "vcomiss", 0x01C1, 0x00D88000, { 0x0F, 0x2F, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CPUID[] = {
	// 0F A2 CPUID A Valid Valid Returns processor identification and feature information to the EAX, EBX, ECX, and EDX registers, as determined by input entered in EAX (in some cases, ECX as well).
	{ NULL, 0x0001, 0x00D80000, { 0x0F, 0xA2, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CRC32[] = {
	// F2 0F 38 F0 /r CRC32 r32, r/m8 A Valid Valid Accumulate CRC32 on r/m8.
	// F2 REX 0F 38 F0 /r CRC32 r32, r/m8* A Valid N.E. Accumulate CRC32 on r/m8.
	{ NULL, 0x2001, 0x03EC8000, { 0x0F, 0x38, 0xF0 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA } },
	// F2 REX.W 0F 38 F0 /r CRC32 r64, r/m8 A Valid N.E. Accumulate CRC32 on r/m8.
	{ NULL, 0x2009, 0x04AC8000, { 0x0F, 0x38, 0xF0 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA } },
	// F2 0F 38 F1 /r CRC32 r32, r/m16 A Valid Valid Accumulate CRC32 on r/m16.
	// F2 0F 38 F1 /r CRC32 r32, r/m32 A Valid Valid Accumulate CRC32 on r/m32.
	{ NULL, 0x2001, 0x03EC8000, { 0x0F, 0x38, 0xF1 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } },
	// F2 REX.W 0F 38 F1 /r CRC32 r64, r/m64 A Valid N.E. Accumulate CRC32 on r/m64.
	{ NULL, 0x2009, 0x04AC8000, { 0x0F, 0x38, 0xF1 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } },
};

// MMWORD
struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTDQ2PD[] = {
	// F3 0F E6 CVTDQ2PD xmm1, xmm2/m64 A Valid Valid Convert two packed signed doubleword integers from xmm2/m128 to two packed double-precision floatingpoint values in xmm1.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0xE6, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F E6 /r VCVTDQ2PD xmm1, xmm2/m64
	{ "vcvtdq2pd", 0x41C1, 0x00D88000, { 0x0F, 0xE6, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.F3.0F E6 /r VCVTDQ2PD ymm1, xmm2/m128
	{ "vcvtdq2pd", 0x41A1, 0x00D88000, { 0x0F, 0xE6, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L_128, FCML_NA, FCML_NA, FCML_NA } }
};

// XMMWORD
struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTDQ2PS[] = {
	// 0F 5B /r CVTDQ2PS xmm1, xmm2/m128 A Valid Valid Convert four packed signed doubleword integers from xmm2/m128 to four packed single-precision floatingpoint
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x5B, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.0F 5B /r VCVTDQ2PS xmm1, xmm2/m128
	// VEX.256.0F 5B /r VCVTDQ2PS ymm1, ymm2/m256
	{ "vcvtdq2ps", 0x0181, 0x00D88000, { 0x0F, 0x5B, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

// XMMWORD
struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTPD2DQ[] = {
	// F2 0F E6 CVTPD2DQ xmm1, xmm2/m128 A Valid Valid Convert two packed doubleprecision floating-point values from xmm2/m128 to two packed signed doubleword integers in xmm1.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0xE6, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F2.0F E6 /r VCVTPD2DQ xmm1, xmm2/m128
	// VEX.256.F2.0F E6 /r VCVTPD2DQ xmm1, ymm2/m256
	{ "vcvtpd2dq", 0x2181, 0x00D88000, { 0x0F, 0xE6, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTPD2PI[] = {
	// 66 0F 2D /r CVTPD2PI mm, xmm/m128 A Valid Valid Convert two packed doubleprecision floating-point values from xmm/m128 to two packed signed doubleword integers in mm.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x2D, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTPD2PS[] = {
	// 66 0F 5A /r CVTPD2PS xmm1,xmm2/m128 A Valid Valid Convert two packed doubleprecision floating-point values in xmm2/m128 to two packed single-precision floating-point values in xmm1.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x5A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F 5A /r VCVTPD2PS xmm1, xmm2/m128
	// VEX.256.66.0F 5A /r VCVTPD2PS xmm1, ymm2/m256
	{ "vcvtpd2ps", 0x1181, 0x00D88000, { 0x0F, 0x5A, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

// XMMWORD
struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTPI2PD[] = {
	// 66 0F 2A /r CVTPI2PD xmm, mm/m64* A Valid Valid Convert two packed signed doubleword integers from mm/mem64 to two packed double-precision floatingpoint values in xmm.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x2A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

// XMMWORD
struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTPI2PS[] = {
	// 0F 2A /r CVTPI2PS xmm, mm/m64 A Valid Valid Convert two signed doubleword integers from mm/m64 to two singleprecision floating-point values in xmm.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x2A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTPS2DQ[] = {
	// 66 0F 5B /r CVTPS2DQ xmm1, xmm2/m128 A Valid Valid Convert four packed singleprecision floating-point values from xmm2/m128 to four packed signed doubleword integers in xmm1.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x5B, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F 5B /r VCVTPS2DQ xmm1, xmm2/m128
	// VEX.256.66.0F 5B /r VCVTPS2DQ ymm1, ymm2/m256
	{ "vcvtps2dq", 0x1180, 0x00D88000, { 0x0F, 0x5B, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTPS2PD[] = {
	// 0F 5A /r CVTPS2PD xmm1, xmm2/m64 A Valid Valid Convert two packed singleprecision floating-point values in xmm2/m64 to two packed double-precision floating-point values in xmm1.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x5A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.0F 5A /r VCVTPS2PD xmm1, xmm2/m64
	// VEX.256.0F 5A /r VCVTPS2PD ymm1, xmm2/m128
	{ "vcvtps2pd", 0x0180, 0x00D88000, { 0x0F, 0x5A, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTPS2PI[] = {
	// 0F 2D /r CVTPS2PI mm, xmm/m64 A Valid Valid Convert two packed singleprecision floating-point values from xmm/m64 to two packed signed doubleword integers in mm.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x2D, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTSD2SI[] = {
	// F2 0F 2D /r CVTSD2SI r32, xmm/m64 A Valid Valid Convert one doubleprecision floating-point value from xmm/m64 to one signed doubleword integer r32.
	{ NULL, 0x2001, 0x03D88000, { 0x0F, 0x2D, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// F2 REX.W 0F 2D /r CVTSD2SI r64, xmm/m64 A Valid N.E. Convert one doubleprecision floating-point value from xmm/m64 to one signed quadword integer sign-extended into r64.
	{ NULL, 0x2009, 0x04988000, { 0x0F, 0x2D, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F2.0F.W0 2D /r VCVTSD2SI r32, xmm1/m64
	{ "vcvtsd2si", 0x21D0, 0x03D88000, { 0x0F, 0x2D, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F2.0F.W1 2D /r VCVTSD2SI r64, xmm1/m64
	{ "vcvtsd2si", 0x21C8, 0x04988000, { 0x0F, 0x2D, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTSD2SS[] = {
	// F2 0F 5A /r CVTSD2SS xmm1, xmm2/m64 A Valid Valid Convert one doubleprecision floating-point value in xmm2/m64 to one single-precision floatingpoint value in xmm1.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0x5A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F 5A /r VCVTSD2SS xmm1,xmm2,xmm3/m64
	{ "vcvtsd2ss", 0x20C0, 0x00D88000, { 0x0F, 0x5A, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTSI2SD[] = {
	// F2 0F 2A /r CVTSI2SD xmm, r/m32 A Valid Valid Convert one signed doubleword integer from r/m32 to one doubleprecision floating-point value in xmm.
	{ NULL, 0x2001, 0x03D88000, { 0x0F, 0x2A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// F2 REX.W 0F 2A /r CVTSI2SD xmm, r/m64 A Valid N.E. Convert one signed quadword integer from r/m64 to one doubleprecision floating-point value in xmm.
	{ NULL, 0x2009, 0x04988000, { 0x0F, 0x2A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F.W0 2A /r VCVTSI2SD xmm1, xmm2, r/m32
	{ "vcvtsi2sd", 0x20D0, 0x03D88000, { 0x0F, 0x2A, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F.W1 2A /r VCVTSI2SD xmm1, xmm2, r/m64
	{ "vcvtsi2sd", 0x20C8, 0x04988000, { 0x0F, 0x2A, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTSI2SS[] = {
	// F3 0F 2A /r CVTSI2SS xmm, r/m32 A Valid Valid Convert one signed doubleword integer from r/m32 to one singleprecision floating-point value in xmm.
	{ NULL, 0x4001, 0x03D88000, { 0x0F, 0x2A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// F3 REX.W 0F 2A /r CVTSI2SS xmm, r/m64 A Valid N.E. Convert one signed quadword integer from r/m64 to one singleprecision floating-point value in xmm.
	{ NULL, 0x4009, 0x04988000, { 0x0F, 0x2A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F3.0F.W0 2A /r VCVTSI2SS xmm1, xmm2, r/m32
	{ "vcvtsi2ss", 0x40D0, 0x03D88000, { 0x0F, 0x2A, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F3.0F.W1 2A /r VCVTSI2SS xmm1, xmm2, r/m64
	{ "vcvtsi2ss", 0x40C8, 0x04988000, { 0x0F, 0x2A, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTSS2SD[] = {
	// F3 0F 5A /r CVTSS2SD xmm1, xmm2/m32 A Valid Valid Convert one single-precision floating-point value in xmm2/m32 to one doubleprecision floating-point value in xmm1.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x5A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F3.0F 5A /r VCVTSS2SD xmm1, xmm2, xmm3/m32
	{ "vcvtss2sd", 0x40C0, 0x00D88000, { 0x0F, 0x5A, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTSS2SI[] = {
	// F3 0F 2D /r CVTSS2SI r32, xmm/m32 A Valid Valid Convert one single-precision floating-point value from xmm/m32 to one signed doubleword integer in r32.
	{ NULL, 0x4001, 0x03D88000, { 0x0F, 0x2D, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// F3 REX.W 0F 2D /r CVTSS2SI r64, xmm/m32 A Valid N.E. Convert one single-precision floating-point value from xmm/m32 to one signed quadword integer in r64.
	{ NULL, 0x4009, 0x04988000, { 0x0F, 0x2D, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F.W0 2D /r VCVTSS2SI r32, xmm1/m32
	{ "vcvtss2si", 0x41D0, 0x03D88000, { 0x0F, 0x2D, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_SIMD_L_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F.W1 2D /r VCVTSS2SI r64, xmm1/m32
	{ "vcvtss2si", 0x41C8, 0x04988000, { 0x0F, 0x2D, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_SIMD_L_32, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTTPD2DQ[] = {
	// 66 0F E6 CVTTPD2DQ xmm1, xmm2/m128 A Valid Valid Convert two packed doubleprecision floating-point values from xmm2/m128 to two packed signed doubleword integers in xmm1 using truncation.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xE6, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F E6 /r VCVTTPD2DQ xmm1, xmm2/m128
	// VEX.256.66.0F E6 /r VCVTTPD2DQ xmm1, ymm2/m256
	{ "vcvttpd2dq", 0x1180, 0x00D88000, { 0x0F, 0xE6, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTTPD2PI[] = {
	// 66 0F 2C /r CVTTPD2PI mm, xmm/m128 A Valid Valid Convert two packer doubleprecision floating-point values from xmm/m128 to two packed signed doubleword integers in mm using truncation.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x2C, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTTPS2DQ[] = {
	// F3 0F 5B /r CVTTPS2DQ xmm1, xmm2/m128 A Valid Valid Convert four singleprecision floating-point values from xmm2/m128 to four signed doubleword integers in xmm1 using truncation.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x5B, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F 5B /r VCVTTPS2DQ xmm1, xmm2/m128
	// VEX.256.F3.0F 5B /r VCVTTPS2DQ ymm1, ymm2/m256
	{ "vcvttps2dq", 0x4180, 0x00D88000, { 0x0F, 0x5B, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTTPS2PI[] = {
	// 0F 2C /r CVTTPS2PI mm, xmm/m64 A Valid Valid Convert two singleprecision floating-point values from xmm/m64 to two signed doubleword signed integers in mm using truncation.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x2C, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTTSD2SI[] = {
	// F2 0F 2C /r CVTTSD2SI r32, xmm/m64 A Valid Valid Convert one doubleprecision floating-point value from xmm/m64 to one signed doubleword integer in r32 using truncation.
	{ NULL, 0x2001, 0x03D88000, { 0x0F, 0x2C, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// F2 REX.W 0F 2C /r CVTTSD2SI r64, xmm/m64 A Valid N.E. Convert one double precision floating-point value from xmm/m64 to one signedquad wordinteger in r64 using truncation.
	{ NULL, 0x2009, 0x04988000, { 0x0F, 0x2C, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F2.0F.W0 2C /r VCVTTSD2SI r32, xmm1/m64
	{ "vcvttsd2si", 0x21D0, 0x03D88000, { 0x0F, 0x2C, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F2.0F.W1 2C /r VCVTTSD2SI r64, xmm1/m64
	{ "vcvttsd2si", 0x21C8, 0x04988000, { 0x0F, 0x2C, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA, FCML_NA } }
};

// MMWORD
struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CVTTSS2SI[] = {
	// F3 0F 2C /r CVTTSS2SI r32, xmm/m32 A Valid Valid Convert one single-precision floating-point value from xmm/m32 to one signed doubleword integer in r32 using truncation.
	{ NULL, 0x4001, 0x03D88000, { 0x0F, 0x2C, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// F3 REX.W 0F 2C /r CVTTSS2SI r64, xmm/m32 A Valid N.E. Convert one single-precision floating-point value from xmm/m32 to one signed quadword integer in
	{ NULL, 0x4009, 0x04988000, { 0x0F, 0x2C, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F.W0 2C /r VCVTTSS2SI r32, xmm1/m32
	{ "vcvttss2si", 0x41C0, 0x03D88000, { 0x0F, 0x2C, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_SIMD_L_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F.W1 2C /r VCVTTSS2SI r64, xmm1/m32
	{ "vcvttss2si", 0x41D0, 0x04988000, { 0x0F, 0x2C, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_SIMD_L_32, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CWD_CDQ_CQO[] = {
	// 99 CWD A Valid Valid DX:AX <- sign-extend of AX.
	{ "cwd", 0x0001, 0x01C40000, { 0x99, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 99 CDQ A Valid Valid EDX:EAX <- sign-extend of EAX.
	{ "cdq", 0x0001, 0x02C40000, { 0x99, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 99 CQO A Valid N.E. RDX:RAX <- sign-extend of RAX.
	{ "cqo", 0x0001, 0x04840000, { 0x99, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_DAA[] = {
	// 27 DAA A Invalid Valid Decimal adjust AL after addition.
	{ NULL, 0x0001, 0x00440000, { 0x27, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_DAS[] = {
	// 2F DAS A Invalid Valid Decimal adjust AL after subtraction.
	{ NULL, 0x0001, 0x00440000, { 0x2F, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_DEC[] = {
	// FE /1 DEC r/m8 A Valid Valid Decrement r/m8 by 1.
	// REX + FE /1 DEC r/m8* A Valid N.E. Decrement r/m8 by 1.
	{ NULL, 0x0001, 0x00C58800, { 0xFE, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// FF /1 DEC r/m16 A Valid Valid Decrement r/m16 by 1.
	// FF /1 DEC r/m32 A Valid Valid Decrement r/m32 by 1.
	// REX.W + FF /1 DEC r/m64 A Valid N.E. Decrement r/m64 by 1.
	{ NULL, 0x0001, 0x00C58800, { 0xFF, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 48+rw DEC r16 B N.E. Valid Decrement r16 by 1.
	// 48+rd DEC r32 B N.E. Valid Decrement r32 by 1.
	{ NULL, 0x0001, 0x00440001, { 0x48, 0x00, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_EOSA ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_DIV[] = {
	// F6 /6 DIV r/m8 A Valid Valid Unsigned divide AX by r/m8,with result stored in AL Quotient, AH Remainder.
	// REX + F6 /6 DIV r/m8* A Valid N.E. Unsigned divide AX by r/m8, with result stored in AL Quotient, AH Remainder.
	{ NULL, 0x0001, 0x00C5B000, { 0xF6, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AX, FCML_EOS_WORD ), FCML_OP_MODRM_RM_8_W, FCML_NA, FCML_NA, FCML_NA } },
	// F7 /6 DIV r/m16 A Valid Valid Unsigned divide DX:AX by r/m16, with result stored in AX Quotient, DX Remainder.
	// F7 /6 DIV r/m32 A Valid Valid Unsigned divide EDX:EAX by r/m32, with result stored in EAX Quotient, EDX Remainder.
	// REX.W + F7 /6 DIV r/m64 A Valid N.E. Unsigned divide RDX:RAX by r/m64, with result stored in RAX Quotient, RDX Remainder.
	{ NULL, 0x0001, 0x00C5B000, { 0xF7, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ), FCML_OP_MODRM_RM_W, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_DIVPD[] = {
	// 66 0F 5E /r DIVPD xmm1, xmm2/m128 A Valid Valid Divide packed doubleprecision floating-point values in xmm1 by packed double-precision floatingpoint values xmm2/m128.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x5E, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F 5E /r VDIVPD xmm1, xmm2, xmm3/m128
	// VEX.NDS.256.66.0F 5E /r VDIVPD ymm1, ymm2, ymm3/m256
	{ "vdivpd", 0x1080, 0x00D88000, { 0x0F, 0x5E, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_DIVPS[] = {
	// 0F 5E /r DIVPS xmm1, xmm2/m128 A Valid Valid Divide packed singleprecision floating-point values in xmm1 by packed single-precision floatingpoint values xmm2/m128.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x5E, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F 5E /r VDIVPS xmm1, xmm2, xmm3/m128
	// VEX.NDS.256.0F 5E /r VDIVPS ymm1, ymm2, ymm3/m256
	{ "vdivps", 0x0080, 0x00D88000, { 0x0F, 0x5E, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_DIVSD[] = {
	// F2 0F 5E /r DIVSD xmm1, xmm2/m64 A Valid Valid Divide low double-precision floating-point value n xmm1 by low double-precision floating-point value in xmm2/mem64.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0x5E, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F 5E /r VDIVSD xmm1, xmm2, xmm3/m64
	{ "vdivsd", 0x20C0, 0x00D88000, { 0x0F, 0x5E, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_DIVSS[] = {
	// F3 0F 5E /r DIVSS xmm1, xmm2/m32 A Valid Valid Divide low single-precision floating-point value in xmm1 by low singleprecision floating-point value in xmm2/m32.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x5E, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F3.0F 5E /r VDIVSS xmm1, xmm2, xmm3/m32
	{ "vdivss", 0x40C0, 0x00D88000, { 0x0F, 0x5E, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_32, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_DPPD[] = {
	// 66 0F 3A 41 /r ib DPPD xmm1, xmm2/m128, imm8 A Valid Valid Selectively multiply packed DP floating-point values from xmm1 with packed DP floating-point values from xmm2, add and selectively store the packed DP floating-point values to xmm1.
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x41 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F3A 41 /r ib VDPPD xmm1,xmm2,xmm3/m128,imm8
	{ "vdppd", 0x10C0, 0x00EC8000, { 0x0F, 0x3A, 0x41 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_128, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_DPPS[] = {
	// 66 0F 3A 40 /r ib DPPS xmm1, xmm2/m128, imm8 A Valid Valid Selectively multiply packed SP floating-point values from xmm1 with packed SP floating-point values from xmm2, add and selectively store the packed SP floating-point values or zero values to xmm1.
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x40 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F3A 40 /r ib VDPPS xmm1,xmm2,xmm3/m128,imm8
	// VEX.NDS.256.66.0F3A 40 /r ib VDPPS ymm1,ymm2,ymm3/m256,imm8
	{ "vdpps", 0x1080, 0x00EC8000, { 0x0F, 0x3A, 0x40 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VEXTRACTF128[] = {
	// VEX.256.66.0F3A 19 /r ib VEXTRACTF128 xmm1/m128,ymm2,imm8
	{ "vextractf128", 0x11A0, 0x00EC8000, { 0x0F, 0x3A, 0x19 }, { FCML_OP_MODRM_RM_XMM_128_W, FCML_OP_MODRM_R_SIMD_L, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_EMMS[] = {
	// 0F 77 EMMS A Valid Valid Set the x87 FPU tag word to empty.
	{ NULL, 0x0001, 0x00D80000, { 0x0F, 0x77, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ENTER[] = {
	// C8 iw 00 ENTER imm16, 0 A Valid Valid Create a stack frame for a procedure.
	// C8 iw 01 ENTER imm16, 1 A Valid Valid Create a nested stack frame for a procedure.
	// C8 iw ib ENTER imm16, imm8 A Valid Valid Create a nested stack frame for a procedure.
	{ NULL, 0x0001, 0x00C40000, { 0xC8, 0x00, 0x00 }, { FCML_OP_IW | FCML_OA_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_EXTRACTPS[] = {
	// 66 0F 3A 17 /r ib EXTRACTPS reg/m32, xmm2, imm8 A Valid Valid Extract a single-precision floating-point value from xmm2 at the source offset specified by imm8 and store the result to reg or m32. The upper 32 bits of r64 is zeroed if reg is r64.,
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x17 }, { FCML_OP_MODRM_RM_32_W, FCML_OP_MODRM_R_XMM, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A 17 /r ib VEXTRACTPS r/m32, xmm1, imm8
	{ "vextractps", 0x11C0, 0x00EC8000, { 0x0F, 0x3A, 0x17 }, { FCML_OP_MODRM_RM_32_W, FCML_OP_MODRM_R_XMM, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_EXTRQ[] = {
	// EXTRQ xmm1,imm8,imm8 66 0F 78 /0 ib ib
	{ NULL, 0x1000, 0x00DB8000, { 0x0F, 0x78, 0x00 }, { FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_OP_IB, FCML_NA, FCML_NA } },
	// EXTRQ xmm1,xmm2 66 0F 79 /r
	{ NULL, 0x1000, 0x00DA8000, { 0x0F, 0x79, 0x00 }, { FCML_OP_MODRM_R_XMM, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_F2XM1[] = {
	// D9 F0 F2XM1 Valid Valid Replace ST(0) with (2ST(0) � 1).
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xF0, 0x17 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FABS[] = {
	// D9 E1 FABS Valid Valid Replace ST with its absolute value.
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xE1, 0x17 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FADD[] = {
	// D8 /0 FADD m32fp Valid Valid Add m32fp to ST(0) and store result in ST(0).
	{ NULL, 0x0001, 0x00C58000, { 0xD8, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DC /0 FADD m64fp Valid Valid Add m64fp to ST(0) and store result in ST(0).
	{ NULL, 0x0001, 0x00C58000, { 0xDC, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D8 C0+i FADD ST(0), ST(i) Valid Valid Add ST(0) to ST(i) and store result in ST(0).
	{ NULL, 0x0001, 0x00D80001, { 0xD8, 0xC0, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DC C0+i FADD ST(i), ST(0) Valid Valid Add ST(i) to ST(0) and store result in ST(i).
	{ NULL, 0x0001, 0x00D80001, { 0xDC, 0xC0, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DE C0+i FADDP ST(i), ST(0) Valid Valid Add ST(0) to ST(i), store result in ST(i), and pop the register stack.
	{ "faddp", 0x0001, 0x00D80001, { 0xDE, 0xC0, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DA /0 FIADD m32int Valid Valid Add m32int to ST(0) and store result in ST(0).
	{ "fiadd", 0x0001, 0x00C58000, { 0xDA, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DE /0 FIADD m16int Valid Valid Add m16int to ST(0) and store result in ST(0).
	{ "fiadd", 0x0001, 0x00C58000, { 0xDE, 0x00, 0x00 }, { FCML_OP_MODRM_M_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FBLD[] = {
	// DF /4 FBLD m80 dec Valid Valid Convert BCD value to floating-point and push onto the FPU stack.
	{ NULL, 0x0001, 0x00C5A000, { 0xDF, 0x00, 0x00 }, { FCML_OP_MODRM_M_80, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FBSTP[] = {
	// DF /6 FBSTP m80bcd Valid Valid Store ST(0) in m80bcd and pop ST(0).
	{ NULL, 0x0001, 0x00C5B000, { 0xDF, 0x00, 0x00 }, { FCML_OP_MODRM_M_80, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FCHS[] = {
	// D9 E0 FCHS Valid Valid Complements sign of ST(0).
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xE0, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FCLEX[] = {
	// 9B DB E2 FCLEX Valid Valid Clear floating-point exception flags after checking for pending unmasked floatingpoint exceptions.
	{ NULL, 0x0001, 0x00EC0000, { 0x9B, 0xDB, 0xE2 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DB E2 * Valid Valid Clear floating-point exception flags without checking for pending unmasked floating-point exceptions.
	{ "fnclex", 0x0001, 0x00D80000, { 0xDB, 0xE2, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FCMOV[] = {
	// DA C0+i FCMOVB ST(0), ST(i) Valid Valid Move if below (CF=1).
	{ "fcmovb", 0x0001, 0x00D80001, { 0xDA, 0xC0, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DA C8+i FCMOVE ST(0), ST(i) Valid Valid Move if equal (ZF=1).
	{ "fcmove", 0x0001, 0x00D80001, { 0xDA, 0xC8, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DA D0+i FCMOVBE ST(0), ST(i) Valid Valid Move if below or equal (CF=1 or ZF=1).
	{ "fcmovbe", 0x0001, 0x00D80001, { 0xDA, 0xD0, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DA D8+i FCMOVU ST(0), ST(i) Valid Valid Move if unordered (PF=1).
	{ "fcmovu", 0x0001, 0x00D80001, { 0xDA, 0xD8, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DB C0+i FCMOVNB ST(0), ST(i) Valid Valid Move if not below (CF=0).
	{ "fcmovnb", 0x0001, 0x00D80001, { 0xDB, 0xC0, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DB C8+i FCMOVNE ST(0), ST(i) Valid Valid Move if not equal (ZF=0).
	{ "fcmovne", 0x0001, 0x00D80001, { 0xDB, 0xC8, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DB D0+i FCMOVNBE ST(0), ST(i) Valid Valid Move if not below or equal (CF=0 and ZF=0).
	{ "fcmovnbe", 0x0001, 0x00D80001, { 0xDB, 0xD0, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DB D8+i FCMOVNU ST(0), ST(i) Valid Valid Move if not unordered (PF=0).
	{ "fcmovnu", 0x0001, 0x00D80001, { 0xDB, 0xD8, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FCOM[] = {
	// D8 /2 FCOM m32fp
	{ "fcom", 0x0000, 0x00C59000, { 0xD8, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D8 /3 FCOMP m32fp
	{ "fcomp", 0x0000, 0x00C59800, { 0xD8, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DC /2 FCOM m64fp
	{ "fcom", 0x0000, 0x00C59000, { 0xDC, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DC /3 FCOMP m64fp
	{ "fcomp", 0x0000, 0x00C59800, { 0xDC, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D8 D0+i FCOM ST(i)
	{ "fcom", 0x0000, 0x00D80001, { 0xD8, 0xD0, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D8 D8+i FCOMP ST(i)
	{ "fcomp", 0x0000, 0x00D80001, { 0xD8, 0xD8, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DE D9 FCOMPP
	{ "fcompp", 0x0000, 0x00D80000, { 0xDE, 0xD9, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }

	// TODO: D8 D1 FCOM (assembler.)
	// TODO: D8 D9 FCOMP (assembler.)
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FCOMI[] = {
	// DB F0+i FCOMI ST, ST(i) Valid Valid Compare ST(0) with ST(i) and set status flags accordingly.
	{ "fcomi", 0x0001, 0x00D80001, { 0xDB, 0xF0, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DF F0+i FCOMIP ST, ST(i) Valid Valid Compare ST(0) with ST(i), set status flags accordingly, and pop register stack.
	{ "fcomip", 0x0001, 0x00D80001, { 0xDF, 0xF0, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DB E8+i FUCOMI ST, ST(i) Valid Valid Compare ST(0) with ST(i), check for ordered values, and set status flags accordingly.
	{ "fucomi", 0x0001, 0x00D80001, { 0xDB, 0xE8, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DF E8+i FUCOMIP ST, ST(i) Valid Valid Compare ST(0) with ST(i), check for ordered values, set status flags accordingly, and pop register stack.
	{ "fucomip", 0x0001, 0x00D80001, { 0xDF, 0xE8, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FCOS[] = {
	// D9 FF FCOS Valid Valid Replace ST(0) with its cosine.
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xFF, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FDECSTP[] = {
	// D9 F6 FDECSTP Valid Valid Decrement
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xF6, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FDIV[] = {
	// D8 /6 FDIV m32fp Valid Valid Divide ST(0) by m32fp and store result in ST(0).
	{ NULL, 0x0001, 0x00C5B000, { 0xD8, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DC /6 FDIV m64fp Valid Valid Divide ST(0) by m64fp and store result in ST(0).
	{ NULL, 0x0001, 0x00C5B000, { 0xDC, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D8 F0+i FDIV ST(0), ST(i) Valid Valid Divide ST(0) by ST(i) and store result in ST(0).
	{ NULL, 0x0001, 0x00D80001, { 0xD8, 0xF0, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DC F8+i FDIV ST(i), ST(0) Valid Valid Divide ST(i) by ST(0) and store result in ST(i).
	{ NULL, 0x0001, 0x00D80001, { 0xDC, 0xF8, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DE F8+i FDIVP ST(i), ST(0) Valid Valid Divide ST(i) by ST(0), store result in ST(i), and pop the register stack.
	{ "fdivp", 0x0001, 0x00D80001, { 0xDE, 0xF8, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DA /6 FIDIV m32int Valid Valid Divide ST(0) by m32int and store result in ST(0).
	{ "fidiv", 0x0001, 0x00C5B000, { 0xDA, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DE /6 FIDIV m16int Valid Valid Divide ST(0) by m64int and store result in ST(0).
	{ "fidiv", 0x0001, 0x00C5B000, { 0xDE, 0x00, 0x00 }, { FCML_OP_MODRM_M_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FDIVR[] = {
	// D8 /7 FDIVR m32fp Valid Valid Divide m32fp by ST(0) and store result in ST(0).
	{ NULL, 0x0001, 0x00C5B800, { 0xD8, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DC /7 FDIVR m64fp Valid Valid Divide m64fp by ST(0) and store result in ST(0).
	{ NULL, 0x0001, 0x00C5B800, { 0xDC, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D8 F8+i FDIVR ST(0), ST(i) Valid Valid Divide ST(i) by ST(0) and store result in ST(0).
	{ NULL, 0x0001, 0x00D80001, { 0xD8, 0xF8, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DC F0+i FDIVR ST(i), ST(0) Valid Valid Divide ST(0) by ST(i) and store result in ST(i).
	{ NULL, 0x0001, 0x00D80001, { 0xDC, 0xF0, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DE F0+i FDIVRP ST(i), ST(0) Valid Valid Divide ST(0) by ST(i), store result in ST(i), and pop the register stack.
	{ "fdivrp", 0x0001, 0x00D80001, { 0xDE, 0xF0, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DA /7 FIDIVR m32int Valid Valid Divide m32int by ST(0) and store result in ST(0).
	{ "fidivr", 0x0001, 0x00C5B800, { 0xDA, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DE /7 FIDIVR m16int Valid Valid Divide m16int by ST(0) and store result in ST(0).
	{ "fidivr", 0x0001, 0x00C5B800, { 0xDE, 0x00, 0x00 }, { FCML_OP_MODRM_M_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FFREE[] = {
	// DD C0+i FFREE ST(i) Valid Valid Sets tag for ST(i) to empty.
	{ NULL, 0x0001, 0x00D80001, { 0xDD, 0xC0, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FICOM[] = {
	// DE /2 FICOM m16int Valid Valid Compare ST(0) with m16int.
	{ NULL, 0x0001, 0x00C59000, { 0xDE, 0x00, 0x00 }, { FCML_OP_MODRM_M_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DA /2 FICOM m32int Valid Valid Compare ST(0) with m32int.
	{ NULL, 0x0001, 0x00C59000, { 0xDA, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DE /3 FICOMP m16int Valid Valid Compare ST(0) with m16int and pop stack register.
	{ "ficomp", 0x0001, 0x00C59800, { 0xDE, 0x00, 0x00 }, { FCML_OP_MODRM_M_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DA /3 FICOMP m32int Valid Valid Compare ST(0) with m32int and pop stack register.
	{ "ficomp", 0x0001, 0x00C59800, { 0xDA, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FILD[] = {
	// DF /0 FILD m16int Valid Valid Push m16int onto the FPU register stack.
	{ NULL, 0x0001, 0x00C58000, { 0xDF, 0x00, 0x00 }, { FCML_OP_MODRM_M_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DB /0 FILD m32int Valid Valid Push m32int onto the FPU register stack.
	{ NULL, 0x0001, 0x00C58000, { 0xDB, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DF /5 FILD m64int Valid Valid Push m64int onto the FPU register stack.
	{ NULL, 0x0001, 0x00C5A800, { 0xDF, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FINCSTP[] = {
	// D9 F7 FINCSTP Valid Valid Increment the TOP field in the FPU status register.
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xF7, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FINIT[] = {
	// 9B DB E3 FINIT Valid Valid Initialize FPU after checking for pending unmasked floating-point exceptions.
	{ NULL, 0x0001, 0x00EC0000, { 0x9B, 0xDB, 0xE3 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DB E3 FNINIT* Valid Valid Initialize FPU without checking for pending unmasked floating-point exceptions.
	{ "fninit", 0x0001, 0x00D80000, { 0xDB, 0xE3, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FIST[] = {
	// DF /2 FIST m16int Valid Valid Store ST(0) in m16int.
	{ NULL, 0x0001, 0x00C59000, { 0xDF, 0x00, 0x00 }, { FCML_OP_MODRM_M_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DB /2 FIST m32int Valid Valid Store ST(0) in m32int.
	{ NULL, 0x0001, 0x00C59000, { 0xDB, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DF /3 FISTP m16int Valid Valid Store ST(0) in m16int and pop register stack.
	{ "fistp", 0x0001, 0x00C59800, { 0xDF, 0x00, 0x00 }, { FCML_OP_MODRM_M_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DB /3 FISTP m32int Valid Valid Store ST(0) in m32int and pop register stack.
	{ "fistp", 0x0001, 0x00C59800, { 0xDB, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DF /7 FISTP m64int Valid Valid Store ST(0) in m64int and pop register stack.
	{ "fistp", 0x0001, 0x00C5B800, { 0xDF, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FISTTP[] = {
	// DF /1 FISTTP m16int Valid Valid Store ST(0) in m16int with truncation.
	{ NULL, 0x0001, 0x00C58800, { 0xDF, 0x00, 0x00 }, { FCML_OP_MODRM_M_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DB /1 FISTTP m32int Valid Valid Store ST(0) in m32int with truncation.
	{ NULL, 0x0001, 0x00C58800, { 0xDB, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DD /1 FISTTP m64int Valid Valid Store ST(0) in m64int with truncation.
	{ NULL, 0x0001, 0x00C58800, { 0xDD, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FLD[] = {
	// D9 /0 FLD m32fp Valid Valid Push m32fp onto the FPU register stack.
	{ NULL, 0x0001, 0x00C58000, { 0xD9, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DD /0 FLD m64fp Valid Valid Push m64fp onto the FPU register stack.
	{ NULL, 0x0001, 0x00C58000, { 0xDD, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DB /5 FLD m80fp Valid Valid Push m80fp onto the FPU register stack.
	{ NULL, 0x0001, 0x00C5A800, { 0xDB, 0x00, 0x00 }, { FCML_OP_MODRM_M_80, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D9 C0+i FLD ST(i) Valid Valid Push ST(i) onto the FPU register stack.
	{ NULL, 0x0001, 0x00D80001, { 0xD9, 0xC0, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FLDx[] = {
	// D9 E8 FLD1 Valid Valid Push +1.0 onto the FPU register stack.
	{ "fld1", 0x0001, 0x00D80000, { 0xD9, 0xE8, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D9 E9 FLDL2T Valid Valid Push log210 onto the FPU register stack.
	{ "fldl2t", 0x0001, 0x00D80000, { 0xD9, 0xE9, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D9 EA FLDL2E Valid Valid Push log2e onto the FPU register stack.
	{ "fldl2e", 0x0001, 0x00D80000, { 0xD9, 0xEA, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D9 EB FLDPI Valid Valid Push onto the FPU register stack.
	{ "fldpi", 0x0001, 0x00D80000, { 0xD9, 0xEB, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D9 EC FLDLG2 Valid Valid Push log102 onto the FPU register stack.
	{ "fldlg2", 0x0001, 0x00D80000, { 0xD9, 0xEC, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D9 ED FLDLN2 Valid Valid Push loge2 onto the FPU register stack.
	{ "fldln2", 0x0001, 0x00D80000, { 0xD9, 0xED, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D9 EE FLDZ Valid Valid Push +0.0 onto the FPU register stack.
	{ "fldz", 0x0001, 0x00D80000, { 0xD9, 0xEE, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FLDCW[] = {
	// D9 /5 FLDCW m2byte Valid Valid Load FPU control word from m2byte.
	{ NULL, 0x0001, 0x00C5A800, { 0xD9, 0x00, 0x00 }, { FCML_OP_MODRM_M_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FLDENV[] = {
	// D9 /4 FLDENV m14/28byte Valid Valid Load FPU environment from m14byte or m28byte.
	{ NULL, 0x0001, 0x00C5A000, { 0xD9, 0x00, 0x00 }, { FCML_OP_MODRM_M_14_28, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FMUL[] = {
	// D8 /1 FMUL m32fp Valid Valid Multiply ST(0) by m32fp and store result in ST(0).
	{ NULL, 0x0001, 0x00C58800, { 0xD8, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DC /1 FMUL m64fp Valid Valid Multiply ST(0) by m64fp and store result in ST(0).
	{ NULL, 0x0001, 0x00C58800, { 0xDC, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D8 C8+i FMUL ST(0), ST(i) Valid Valid Multiply ST(0) by ST(i) and store result in ST(0).
	{ NULL, 0x0001, 0x00D80001, { 0xD8, 0xC8, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DC C8+i FMUL ST(i), ST(0) Valid Valid Multiply ST(i) by ST(0) and store result in ST(i).
	{ NULL, 0x0001, 0x00D80001, { 0xDC, 0xC8, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DE C8+i FMULP ST(i), ST(0) Valid Valid Multiply ST(i) by ST(0), store result in ST(i), and pop the register stack.
	{ "fmulp", 0x0001, 0x00D80001, { 0xDE, 0xC8, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DA /1 FIMUL m32int Valid Valid Multiply ST(0) by m32int and store result in ST(0).
	{ "fimul", 0x0001, 0x00C58800, { 0xDA, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DE /1 FIMUL m16int Valid Valid Multiply ST(0) by m16int and store result in ST(0).
	{ "fimul", 0x0001, 0x00C58800, { 0xDE, 0x00, 0x00 }, { FCML_OP_MODRM_M_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FNOP[] = {
	// D9 D0 FNOP Valid Valid No operation is performed.
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xD0, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FPATAN[] = {
	// D9 F3 FPATAN Valid Valid Replace ST(1) with arctan(ST(1) ST(0)) and pop the register stack.
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xF3, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FPREM[] = {
	// D9 F8 FPREM Valid Valid Replace ST(0) with the remainder obtained from dividing ST(0) by ST(1).
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xF8, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FPREM1[] = {
	// D9 F5 FPREM1 Valid Valid Replace ST(0) with the IEEE remainder obtained from dividing ST(0) by ST(1).
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xF5, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FPTAN[] = {
	// D9 F2 FPTAN Valid Valid Replace ST(0) with its tangent and push 1 onto the FPU stack.
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xF2, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FRNDINT[] = {
	// D9 FC FRNDINT Valid Valid Round ST(0) to an integer.
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xFC, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FRSTOR[] = {
	// DD /4 FRSTOR m94/108byte Valid Valid Load FPU state from m94byte or m108byte.
	{ NULL, 0x0001, 0x00C5A000, { 0xDD, 0x00, 0x00 }, { FCML_OP_MODRM_M_94_108, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FSAVE[] = {
	// 9B DD /6 FSAVE m94/108byte Valid Valid Store FPU state to m94byte or m108byte after checking for pending unmasked floatingpoint exceptions. Then reinitialize the FPU.
	{ NULL, 0x0001, 0x00D9B000, { 0x9B, 0xDD, 0x00 }, { FCML_OP_MODRM_M_94_108, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DD /6 FNSAVE* m94/108byte Valid Valid Store FPU environment to m94byte or m108byte without checking for pending unmasked floating-point exceptions.
	{ "fnsave", 0x0001, 0x00C5B000, { 0xDD, 0x00, 0x00 }, { FCML_OP_MODRM_M_94_108, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FSCALE[] = {
	// D9 FD FSCALE Valid Valid Scale ST(0) by ST(1).
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xFD, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FSIN[] = {
	// D9 FE FSIN Valid Valid Replace ST(0) with its sine.
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xFE, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FSINCOS[] = {
	// D9 FB FSINCOS Valid Valid Compute the sine and cosine of ST(0); replace ST(0) with the sine, and push the cosine onto the register stack.
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xFB, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FSQRT[] = {
	// D9 FA FSQRT Valid Valid Computes square root of ST(0) and stores the result in ST(0).
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xFA, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FST[] = {
	// D9 /2 FST m32fp Valid Valid Copy ST(0) to m32fp.
	{ NULL, 0x0001, 0x00C59000, { 0xD9, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DD /2 FST m64fp Valid Valid Copy ST(0) to m64fp.
	{ NULL, 0x0001, 0x00C59000, { 0xDD, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DD D0+i FST ST(i) Valid Valid Copy ST(0) to ST(i).
	{ NULL, 0x0001, 0x00D80001, { 0xDD, 0xD0, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D9 /3 FSTP m32fp Valid Valid Copy ST(0) to m32fp and pop register stack.
	{ "fstp", 0x0001, 0x00C59800, { 0xD9, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DD /3 FSTP m64fp Valid Valid Copy ST(0) to m64fp and pop register stack.
	{ "fstp", 0x0001, 0x00C59800, { 0xDD, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DB /7 FSTP m80fp Valid Valid Copy ST(0) to m80fp and pop register stack.
	{ "fstp", 0x0001, 0x00C5B800, { 0xDB, 0x00, 0x00 }, { FCML_OP_MODRM_M_80, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DD D8+i FSTP ST(i) Valid Valid Copy ST(0) to ST(i) and pop register stack.
	{ "fstp", 0x0001, 0x00D80001, { 0xDD, 0xD8, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FSTCW[] = {
	// 9B D9 /7 FSTCW m2byte Valid Valid Store FPU control word to m2byte after checking for pending unmasked floating-point exceptions.
	{ NULL, 0x0001, 0x00D9B800, { 0x9B, 0xD9, 0x00 }, { FCML_OP_MODRM_M_16_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D9 /7 FNSTCW* m2byte Valid Valid Store FPU control word to m2byte without checking for pending unmasked floating-point exceptions.
	{ "fnstcw", 0x0001, 0x00C5B800, { 0xD9, 0x00, 0x00 }, { FCML_OP_MODRM_M_16_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FSTENV[] = {
	// 9B D9 /6 FSTENV m14/28byte Valid Valid Store FPU environment to m14byte or m28byte after checking for pending unmasked floating-point exceptions. Then mask all floatingpoint exceptions.
	{ NULL, 0x0001, 0x00D9B000, { 0x9B, 0xD9, 0x00 }, { FCML_OP_MODRM_M_14_28_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D9 /6 FNSTENV* m14/28byte Valid Valid Store FPU environment to m14byte or m28byte without checking for pending unmasked floating-point exceptions. Then mask all floatingpoint exceptions.
	{ "fnstenv", 0x0001, 0x00C5B000, { 0xD9, 0x00, 0x00 }, { FCML_OP_MODRM_M_14_28_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FSTSW[] = {
	// 9B DD /7 FSTSW m2byte Valid Valid Store FPU status word at m2byte after checking for pending unmasked floatingpoint exceptions.
	{ NULL, 0x0001, 0x00D9B800, { 0x9B, 0xDD, 0x00 }, { FCML_OP_MODRM_M_16_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 9B DF E0 FSTSW AX Valid Valid Store FPU status word in AX register after checking for pending unmasked floatingpoint exceptions.
	{ NULL, 0x0001, 0x00EC0000, { 0x9B, 0xDF, 0xE0 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AX, FCML_EOS_WORD ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DD /7 FNSTSW* m2byte Valid Valid Store FPU status word at m2byte without checking for pending unmasked floatingpoint exceptions.
	{ "fnstsw", 0x0001, 0x00C5B800, { 0xDD, 0x00, 0x00 }, { FCML_OP_MODRM_M_16_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DF E0 FNSTSW* AX Valid Valid Store FPU status word in AX register without checking for pending unmasked floatingpoint exceptions.
	{ "fnstsw", 0x0001, 0x00D80000, { 0xDF, 0xE0, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AX, FCML_EOS_WORD ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FSUB[] = {
	// D8 /4 FSUB m32fp Valid Valid Subtract m32fp from ST(0) and store result in ST(0).
	{ NULL, 0x0001, 0x00C5A000, { 0xD8, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DC /4 FSUB m64fp Valid Valid Subtract m64fp from ST(0) and store result in ST(0).
	{ NULL, 0x0001, 0x00C5A000, { 0xDC, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D8 E0+i FSUB ST(0), ST(i) Valid Valid Subtract ST(i) from ST(0) and store result in ST(0).
	{ NULL, 0x0001, 0x00D80001, { 0xD8, 0xE0, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DC E8+i FSUB ST(i), ST(0) Valid Valid Subtract ST(0) from ST(i) and store result in ST(i).
	{ NULL, 0x0001, 0x00D80001, { 0xDC, 0xE8, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DE E8+i FSUBP ST(i), ST(0) Valid Valid Subtract ST(0) from ST(i), store result in ST(i), and pop register stack.
	{ "fsubp", 0x0001, 0x00D80001, { 0xDE, 0xE8, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DA /4 FISUB m32int Valid Valid Subtract m32int from ST(0) and store result in ST(0).
	{ "fisub", 0x0001, 0x00C5A000, { 0xDA, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DE /4 FISUB m16int Valid Valid Subtract m16int from ST(0) and store result in ST(0).
	{ "fisub", 0x0001, 0x00C5A000, { 0xDE, 0x00, 0x00 }, { FCML_OP_MODRM_M_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FSUBR[] = {
	// D8 /5 FSUBR m32fp Valid Valid Subtract ST(0) from m32fp and store result in ST(0).
	{ NULL, 0x0001, 0x00C5A800, { 0xD8, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DC /5 FSUBR m64fp Valid Valid Subtract ST(0) from m64fp and store result in ST(0).
	{ NULL, 0x0001, 0x00C5A800, { 0xDC, 0x00, 0x00 }, { FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D8 E8+i FSUBR ST(0), ST(i) Valid Valid Subtract ST(0) from ST(i) and store result in ST(0).
	{ NULL, 0x0001, 0x00D80001, { 0xD8, 0xE8, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DC E0+i FSUBR ST(i), ST(0) Valid Valid Subtract ST(i) from ST(0) and store result in ST(i).
	{ NULL, 0x0001, 0x00D80001, { 0xDC, 0xE0, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DE E0+i FSUBRP ST(i), ST(0) Valid Valid Subtract ST(i) from ST(0), store result in ST(i), and pop register stack.
	{ "fsubrp", 0x0001, 0x00D80001, { 0xDE, 0xE0, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_OP_EXPLICIT_REG( FCML_REG_FPU, FCML_REG_ST0, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA } },
	// DA /5 FISUBR m32int Valid Valid Subtract ST(0) from m32int and store result in ST(0).
	{ "fisubr", 0x0001, 0x00C5A800, { 0xDA, 0x00, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DE /5 FISUBR m16int Valid Valid Subtract ST(0) from m16int and store result in ST(0).
	{ "fisubr", 0x0001, 0x00C5A800, { 0xDE, 0x00, 0x00 }, { FCML_OP_MODRM_M_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FTST[] = {
	// D9 E4 FTST Valid Valid Compare ST(0) with 0.0.
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xE4, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FUCOM[] = {
	// DD E0+i FUCOM ST(i) Valid Valid Compare ST(0) with ST(i).
	{ NULL, 0x0001, 0x00D80001, { 0xDD, 0xE0, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DD E8+i FUCOMP ST(i) Valid Valid Compare ST(0) with ST(i) and pop register stack.
	{ "fucomp", 0x0001, 0x00D80001, { 0xDD, 0xE8, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// DA E9 FUCOMPP Valid Valid Compare ST(0) with ST(1) and pop register stack twice.
	{ "fucompp", 0x0001, 0x00D80000, { 0xDA, 0xE9, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FXAM[] = {
	// D9 E5 FXAM Valid Valid Classify value or number in ST(0).
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xE5, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FXCH[] = {
	// D9 C8+i FXCH ST(i) Valid Valid Exchange the contents of ST(0) and ST(i).
	{ NULL, 0x0001, 0x00D80001, { 0xD9, 0xC8, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_FPU, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FXRSTOR[] = {
	// 0F AE /1 FXRSTOR m512byte A Valid Valid Restore the x87 FPU, MMX, XMM, and MXCSR register state from m512byte.
	{ NULL, 0x0001, 0x03D98800, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_512B, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W+ 0F AE /1 FXRSTOR64 m512byte A Valid N.E. Restore the x87 FPU, MMX, XMM, and MXCSR register state from m512byte.
	{ "fxrstor64", 0x0008, 0x04998800, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_512B, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FXSAVE[] = {
	// 0F AE /0 FXSAVE m512byte A Valid Valid Save the x87 FPU, MMX, XMM, and MXCSR register state to m512byte.
	{ NULL, 0x0001, 0x03D98000, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_512B, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W+ 0F AE /0 FXSAVE64 m512byte A Valid N.E. Save the x87 FPU, MMX, XMM, and MXCSR register state to m512byte.
	{ "fxsave64", 0x0008, 0x04998000, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_512B, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FXTRACT[] = {
	// D9 F4 FXTRACT Valid Valid Separate value in ST(0) into exponent and significand, store exponent in ST(0), and push the significand onto the register stack.
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xF4, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FYL2X[] = {
	// D9 F1 FYL2X Valid Valid Replace ST(1) with (ST(1) log2ST(0)) and pop the register stack.
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xF1, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FYL2XP1[] = {
	// D9 F9 FYL2XP1 Valid Valid Replace ST(1) with ST(1) log2(ST(0) + 1.0) and pop the register stack.
	{ NULL, 0x0001, 0x00D80000, { 0xD9, 0xF9, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_HADDPD[] = {
	// 66 0F 7C /r HADDPD xmm1, xmm2/m128 A Valid Valid Horizontal add packed double-precision floatingpoint values from xmm2/m128 to xmm1.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x7C, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F 7C /r VHADDPD xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F 7C /r VHADDPD ymm1,ymm2,ymm3/m256
	{ "vhaddpd", 0x1080, 0x00D88000, { 0x0F, 0x7C, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_HADDPS[] = {
	// F2 0F 7C /r HADDPS xmm1, xmm2/m128 A Valid Valid Horizontal add packed single-precision floatingpoint values from xmm2/m128 to xmm1.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0x7C, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F 7C /r VHADDPS xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.F2.0F 7C /r VHADDPS ymm1,ymm2,ymm3/m256
	{ "vhaddps", 0x2080, 0x00D88000, { 0x0F, 0x7C, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_HLT[] = {
	// F4 HLT A Valid Valid Halt
	{ NULL, 0x0001, 0x00C40000, { 0xF4, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_HSUBPD[] = {
	// 66 0F 7D /r HSUBPD xmm1, xmm2/m128A Valid Valid Horizontal subtract packed double-precision floating pointvalues from xmm2/m128 to xmm1.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x7D, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F 7D /r VHSUBPD xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F 7D /r VHSUBPD ymm1,ymm2,ymm3/m256
	{ "vhsubpd", 0x1080, 0x00D88000, { 0x0F, 0x7D, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_HSUBPS[] = {
	// F2 0F 7D /r HSUBPS xmm1, xmm2/m128 A Valid Valid Horizontal subtract packedsingle-precision floatingpoint values from xmm2/m128 to xmm1.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0x7D, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F 7D /r VHSUBPS xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.F2.0F 7D /r VHSUBPS ymm1,ymm2,ymm3/m256
	{ "vhsubps", 0x2080, 0x00D88000, { 0x0F, 0x7D, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_IDIV[] = {
	// F6 /7 IDIV r/m8 A Valid Valid Signed divide AX by r/m8,with result stored in: AL Quotient, AH Remainder.
	// REX + F6 /7 IDIV r/m8* A Valid N.E. Signed divide AX by r/m8, with result stored in AL Quotient, AH Remainder.
	{ NULL, 0x0001, 0x00C5B800, { 0xF6, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AX, FCML_EOS_WORD ), FCML_OP_MODRM_RM_8_W, FCML_NA, FCML_NA, FCML_NA } },
	// F7 /7 IDIV r/m16 A Valid Valid Signed divide DX:AX by r/m16, with result stored in AX Quotient, DX Remainder.
	// F7 /7 IDIV r/m32 A Valid Valid Signed divide EDX:EAX by r/m32, with result stored in EAX Quotient, EDX Remainder.
	// REX.W + F7 /7 IDIV r/m64 A Valid N.E. Signed divide RDX:RAX by r/m64, with result stored in RAX Quotient, RDX Remainder.
	{ NULL, 0x0001, 0x00C5B800, { 0xF7, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ), FCML_OP_MODRM_RM_W, FCML_NA, FCML_NA, FCML_NA } }
};

// ***********************************
// TODO: RWX(W) is not used from here!
// ***********************************

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_IMUL[] = {
	// F6 /5 IMUL r/m8* A Valid Valid AX AL r/m byte.
	{ NULL, 0x0001, 0x00C5A800, { 0xF6, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// F7 /5 IMUL r/m16 A Valid Valid DX:AX AX r/m word.
	// F7 /5 IMUL r/m32 A Valid Valid EDX:EAX EAX r/m32.
	// REX.W + F7 /5 IMUL r/m64 A Valid N.E. RDX:RAX RAX r/m64.
	{ NULL, 0x0001, 0x00C5A800, { 0xF7, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 0F AF /r IMUL r16, r/m16 B Valid Valid word register word register r/m16.
	// 0F AF /r IMUL r32, r/m32 B Valid Valid doubleword register doubleword register r/m32.
	// REX.W + 0F AF /r IMUL r64, r/m64 B Valid N.E. Quadword register Quadword register r/m64.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xAF, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM,  FCML_NA, FCML_NA, FCML_NA } },
	// 6B /r ib IMUL r16, r/m16, imm8 C Valid Valid word register r/m16 sign-extended immediate byte.
	// 6B /r ib IMUL r32, r/m32, imm8 C Valid Valid doubleword register r/m32 sign-extended immediate byte.
	// REX.W + 6B /r ib IMUL r64, r/m64, imm8 C Valid N.E. Quadword register r/m64 sign-extended immediate byte.
	{ NULL, 0x0001, 0x00C48000, { 0x6B, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA } },
	// 69 /r iw IMUL r16, r/m16, imm16 C Valid Valid word register r/m16 immediate word.
	// 69 /r id IMUL r32, r/m32, imm32 C Valid Valid doubleword register r/m32 immediate doubleword.
	{ NULL, 0x0001, 0x03C48000, { 0x69, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA } },
	// REX.W + 69 /r id IMUL r64, r/m64, imm32 C Valid N.E. Quadword register r/m64 immediate doubleword.
	{ NULL, 0x0001, 0x04848000, { 0x69, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_IN[] = {
	// E4 ib IN AL, imm8 A Valid Valid Input byte from imm8 I/O port address into AL.
	{ NULL, 0x0001, 0x07C40000, { 0xE4, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// E5 ib IN AX, imm8 A Valid Valid Input word from imm8 I/O port address into AX.
	{ NULL, 0x0001, 0x01C40000, { 0xE5, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_WORD), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// E5 ib IN EAX, imm8 A Valid Valid Input dword from imm8 I/O port address into EAX.
	{ NULL, 0x0001, 0x06C40000, { 0xE5, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_DWORD), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// EC IN AL,DX B Valid Valid Input byte from I/O port in DX into AL.
	{ NULL, 0x0001, 0x07C40000, { 0xEC, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_DX, FCML_EOS_WORD ), FCML_NA, FCML_NA, FCML_NA } },
	// ED IN AX,DX B Valid Valid Input word from I/O port in DX into AX.
	{ NULL, 0x0001, 0x01C40000, { 0xED, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_WORD ), FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_DX, FCML_EOS_WORD ), FCML_NA, FCML_NA, FCML_NA } },
	// ED IN EAX,DX B Valid Valid Input doubleword from I/O port in DX into EAX.
	{ NULL, 0x0001, 0x06C40000, { 0xED, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_DWORD ), FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_DX, FCML_EOS_WORD ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_INC[] = {
	// FE /0 INC r/m8 A Valid Valid Increment r/m byte by 1.
	// REX + FE /0 INC r/m8* A Valid N.E. Increment r/m byte by 1.
	{ NULL, 0x0001, 0x00C58000, { 0xFE, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// FF /0 INC r/m16 A Valid Valid Increment r/m word by 1.
	// FF /0 INC r/m32 A Valid Valid Increment r/m doubleword by 1.
	// REX.W + FF /0 INC r/m64 A Valid N.E. Increment r/m quadword by 1.
	{ NULL, 0x0001, 0x00C58000, { 0xFF, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 40+ rw** INC r16 B N.E. Valid Increment word register by 1.
	// 40+ rd INC r32 B N.E. Valid Increment doubleword register by 1.
	{ NULL, 0x0001, 0x00440001, { 0x40, 0x00, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_EOSA ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_INS[] = {
	// 6C INS m8, DX A Valid Valid Input byte from I/O port specified in DX into memory location specified in ES:(E)DI or RDI.*
	{ NULL, 0x0001, 0x07C40000, { 0x6C, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_BYTE, FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ),
			FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_DX, FCML_EOS_WORD ), FCML_NA, FCML_NA, FCML_NA } },
	// 6D INS m16, DX A Valid Valid Input word from I/O port specified in DX into memory location specified in ES:(E)DI or RDI.1
	{ NULL, 0x0001, 0x01C40000, { 0x6D, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_WORD, FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ),
			FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_DX, FCML_EOS_WORD ), FCML_NA, FCML_NA, FCML_NA } },
	// 6D INS m32, DX A Valid Valid Input doubleword from I/O port specified in DX into memory location specified in ES:(E)DI or RDI.1
	{ NULL, 0x0001, 0x06C40000, { 0x6D, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_DWORD, FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ),
			FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_DX, FCML_EOS_WORD ), FCML_NA, FCML_NA, FCML_NA } }
	// TODO: W przypadku assemblera trzeba to bedzie obsluzyc.
	// 6C INSB A Valid Valid Input byte from I/O port specified in DX into memory location specified with ES:(E)DI or RDI.1
	// 6D INSW A Valid Valid Input word from I/O portspecified in DX into memory location specified in ES:(E)DI or RDI.1
	// 6D INSD A Valid Valid Input doubleword from I/O port specified in DX into memory location specified in ES:(E)DI or RDI.1
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_INSERTPS[] = {
	// 66 0F 3A 21 /r ib INSERTPS xmm1, xmm2/m32, imm8 A Valid Valid Insert a single precision floating-point value selected by imm8 from xmm2/m32 into xmm1 at the specified destination element specified by imm8 and zero out destination elements in xmm1 as indicated in imm8.
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x021 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F3A 21 /r ib VINSERTPS xmm1,xmm2,xmm3/m32,imm8
	{ "vinsertps", 0x10C0, 0x00EC8000, { 0x0F, 0x3A, 0x21 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_INSERTQ[] = {
	// INSERTQ xmm1, xmm2, imm8, imm8 F2 0F 78 /r ib ib
	{ NULL, 0x2000, 0x00DA8000, { 0x0F, 0x78, 0x00 }, { FCML_OP_MODRM_R_XMM, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_OP_IB, FCML_NA } },
	// INSERTQ xmm1, xmm2 F2 0F 79 /r
	{ NULL, 0x2000, 0x00DA8000, { 0x0F, 0x79, 0x00 }, { FCML_OP_MODRM_R_XMM, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VINSERTF128[] = {
	// VEX.NDS.256.66.0F3A 18 /r ib VINSERTF128 ymm1,ymm2,xmm3/m128,imm8
	{ "vinsertf128", 0x10A0, 0x00EC8000, { 0x0F, 0x3A, 0x18 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_INT[] = {
	// CC INT 3 A Valid Valid Interrupt 3�trap to debugger.
	{ NULL, 0x0001, 0x00C40000, { 0xCC, 0x00, 0x00 }, { FCML_OP_EXPLICIT_IB( 3 ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// CD ib INT imm8 B Valid Valid Interrupt vector number specified by immediate byte.
	{ NULL, 0x0001, 0x00C40000, { 0xCD, 0x00, 0x00 }, { FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// CE INTO A Invalid Valid Interrupt 4�if overflow flag is 1.
	{ "into", 0x0001, 0x00C40000, { 0xCE, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_INVD[] = {
	// 0F 08 INVD A Valid Valid Flush internal caches; initiate flushing of external caches.
	{ NULL, 0x0001, 0x00D80000, { 0x0F, 0x08, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_INVLPG[] = {
	// 0F 01/7 INVLPG m A Valid Valid Invalidate TLB Entry for page that contains m.
	{ NULL, 0x0001, 0x00D9B800, { 0x0F, 0x01, 0x00 }, { FCML_OP_MODRM_M_UNDEF, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_INVLPGA[] = {
	// INVLPGA rAX, ECX 0F 01 DF
	{ NULL, 0x0001, 0x00EC0000, { 0x0F, 0x01, 0xDF }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_EAX, FCML_EOS_EASA ), FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_ECX, FCML_EOS_DWORD ), FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_INVPCID[] = {
	// 66 0F 38 82 /r INVPCID r32, m128 RM NE/V INVPCID Invalidates entries in the TLBs and paging-structure caches based on invalidation type in r32 and descriptor in m128.
	{ NULL, 0x1001, 0x806C8000, { 0x0F, 0x38, 0x82 }, { FCML_OP_MODRM_R_32, FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_OWORD, FCML_RMF_M ), FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 82 /r INVPCID r64, m128 RM V/NE INVPCID Invalidates entries in the TLBs and paging-structure caches based on invalidation type in r64 and descriptor in m128.
	{ NULL, 0x1001, 0x80AC8000, { 0x0F, 0x38, 0x82 }, { FCML_OP_MODRM_R_64, FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_OWORD, FCML_RMF_M ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_IRET[] = {
	// CF IRET A Valid Valid Interrupt return (16-bit operand size).
	{ NULL, 0x0001, 0x01C40000, { 0xCF, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// CF IRETD A Valid Valid Interrupt return (32-bit operand size).
	{ "iretd", 0x0001, 0x02C40000, { 0xCF, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + CF IRETQ A Valid N.E. Interrupt return (64-bit operand size).
	{ "iretq", 0x0001, 0x04C40000, { 0xCF, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LAHF[] = {
	// 9F LAHF A Invalid* Valid Load: AH EFLAGS(SF:ZF:0:AF:0:PF:1:CF).
	{ NULL, 0x0001, 0x00C40000, { 0x9F, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LAR[] = {
	// 0F 02 /r LAR r16, r16/m16 A Valid Valid r16 r16/m16 masked by FF00H.
	// 0F 02 /r LAR r32, r32/m16 A Valid Valid r32 r32/m16 masked by 00FxFF00H
	{ NULL, 0x0001, 0x03D80000, { 0x0F, 0x02, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_RM( FCML_REG_GPR, FCML_EOS_EOSA, FCML_EOS_WORD, FCML_RMF_RM ), FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 0F 02 /r LAR r64, r32/m16 A Valid N.E. r64 r32/m16 masked by 00FxFF00H
	{ NULL, 0x0001, 0x04980000, { 0x0F, 0x02, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_RM( FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_WORD, FCML_RMF_RM ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LDDQU[] = {
	// F2 0F F0 /r LDDQU xmm1, mem A Valid Valid Load unaligned data from mem and return double quadword in xmm1.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0xF0, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_M_UNDEF, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F2.0F F0 /r VLDDQU xmm1, m128
	// VEX.256.F2.0F F0 /r VLDDQU ymm1, m256
	{ "vlddqu", 0x2180, 0x80D88000, { 0x0F, 0xF0, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_L, FCML_RMF_M ), FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VLDMXCSR[] = {
	// VEX.128.0F AE /2 VLDMXCSR m32
	{ NULL, 0x01C0, 0x80D99000, { 0x0F, 0xAE, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_DWORD, FCML_RMF_M ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LDMXCSR[] = {
	// 0F AE /2 LDMXCSR m32 A Valid Valid Load MXCSR register from m32.
	{ NULL, 0x0001, 0x00D99000, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

// TODO: Nie ma aktualnie mozliwosci sprawdzenia po disassemblacji, czy to byl far indirect czy nie, poniewaz jest to
// disassemblowane poprostu jako RM z okrelslona wielkoscia operandu.
struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LDS[] = {
	// C5 /r LDS r16,m16:16 A Invalid Valid Load DS:r16 with far pointer from memory.
	// C5 /r LDS r32,m16:32 A Invalid Valid Load DS:r32 with far pointer from memory.
	{ NULL, 0x0001, 0x00448000, { 0xC5, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_FAR_POINTER_INDIRECT, FCML_NA, FCML_NA, FCML_NA } },
	// 0F B2 /r LSS r16,m16:16 A Valid Valid Load SS:r16 with far pointer from memory.
	// 0F B2 /r LSS r32,m16:32 A Valid Valid Load SS:r32 with far pointer from memory.
	// REX + 0F B2 /r LSS r64,m16:64 A Valid N.E. Load SS:r64 with far pointer from memory.
	{ "lss", 0x0001, 0x00D88000, { 0x0F, 0xB2, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_FAR_POINTER_INDIRECT, FCML_NA, FCML_NA, FCML_NA } },
	// C4 /r LES r16,m16:16 A Invalid Valid Load ES:r16 with far pointer from memory.
	// C4 /r LES r32,m16:32 A Invalid Valid Load ES:r32 with far pointer from memory.
	{ "les", 0x0001, 0x00448000, { 0xC4, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_FAR_POINTER_INDIRECT, FCML_NA, FCML_NA, FCML_NA } },
	// 0F B4 /r LFS r16,m16:16 A Valid Valid Load FS:r16 with far pointer from memory.
	// 0F B4 /r LFS r32,m16:32 A Valid Valid Load FS:r32 with far pointer from memory.
	// REX + 0F B4 /r LFS r64,m16:64 A Valid N.E. Load FS:r64 with far pointer from memory.
	{ "lfs", 0x0001, 0x00D88000, { 0x0F, 0xB4, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_FAR_POINTER_INDIRECT, FCML_NA, FCML_NA, FCML_NA } },
	// 0F B5 /r LGS r16,m16:16 A Valid Valid Load GS:r16 with far pointer from memory.
	// 0F B5 /r LGS r32,m16:32 A Valid Valid Load GS:r32 with far pointer from memory.
	// REX + 0F B5 /r LGS r64,m16:64 A Valid N.E. Load GS:r64 with far pointer from memory.
	{ "lgs", 0x0001, 0x00D88000, { 0x0F, 0xB5, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_FAR_POINTER_INDIRECT, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LEA[] = {
	// 8D /r LEA r16,m A Valid Valid Store effective address for m in register r16.
	// 8D /r LEA r32,m A Valid Valid Store effective address for m in register r32.
	// REX.W + 8D /r LEA r64,m A Valid N.E. Store effective address for m in register r64.
	{ NULL, 0x0001, 0x00C48000, { 0x8D, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_M_UNDEF, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LEAVE[] = {
	// C9 LEAVE A Valid Valid Set SP to BP, then pop BP.
	// C9 LEAVE A N.E. Valid Set ESP to EBP, then pop EBP.
	// C9 LEAVE A Valid N.E. Set RSP
	{ NULL, 0x0001, 0x00C40000, { 0xC9, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LFENCE[] = {
	// 0F AE /5 LFENCE A Valid Valid Serializes load operations.
	{ NULL, 0x0001, 0x00EC0000, { 0x0F, 0xAE, 0xE8 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LLWPCB[] = {
	// LLWPCB reg32 8F RXB.09 0.1111.0.00 12 /0
	{ NULL, 0x0450, 0x00DB8000, { 0x09, 0x12, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// LLWPCB reg64 8F RXB.09 1.1111.0.00 12 /0
	{ NULL, 0x0448, 0x00DB8000, { 0x09, 0x12, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LGDT[] = {
	// 0F 01 /2 LGDT m16&32 A N.E. Valid Load m into GDTR.
	{ NULL, 0x0001, 0x03D99000, { 0x0F, 0x01, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, (FCML_EOS_WORD + FCML_EOS_DWORD), FCML_RMF_M ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 01 /2 LGDT m16&64 A Valid N.E. Load m into GDTR.
	{ NULL, 0x0001, 0x04999000, { 0x0F, 0x01, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, (FCML_EOS_WORD + FCML_EOS_QWORD), FCML_RMF_M ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 01 /3 LIDT m16&32 A N.E. Valid Load m into IDTR.
	{ "lidt", 0x0001, 0x04999800, { 0x0F, 0x01, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, (FCML_EOS_WORD + FCML_EOS_DWORD), FCML_RMF_M ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 01 /3 LIDT m16&64 A Valid N.E. Load m into IDTR.
	{ "lidt", 0x0001, 0x04980000, { 0x0F, 0x01, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, (FCML_EOS_WORD + FCML_EOS_QWORD), FCML_RMF_M ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LLDT[] = {
	// 0F 00 /2 LLDT r/m16 A Valid Valid Load segment selector r/m16 into LDTR.
	{ NULL, 0x0001, 0x00D99000, { 0x0F, 0x00, 0x00 }, { FCML_OP_MODRM_RM_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LMSW[] = {
	// 0F 01 /6 LMSW r/m16 A Valid Valid Loads r/m16 in machine status word of CR0.
	{ NULL, 0x0001, 0x00D9B000, { 0x0F, 0x01, 0x00 }, { FCML_OP_MODRM_RM_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LODS[] = {
	// AC LODS m8 A Valid Valid For legacy mode, Load byte at address DS:(E)SI into AL. For 64-bit mode load byte at address (R)SI into AL.
	{ NULL, 0x0001, 0x00C48000, { 0xAC, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_SI, FCML_EOS_BYTE, FCML_SEG_ENCODE_REGISTER( FCML_REG_DS, FCML_SEG_ALLOW_OVERRIDE ) ),
			FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// AD LODS m16 A Valid Valid For legacy mode, Load word at address DS:(E)SI into AX. For 64-bit mode load word at address (R)SI into AX.
	// AD  LODS m32 A Valid Valid For legacy mode, Load dword at address DS:(E)SI into EAX. For 64-bit mode load dword at address (R)SI into EAX.
	// REX.W + AD LODS m64 A Valid N.E. Load qword at address (R)SI into RAX.
	{ NULL, 0x0001, 0x00C48000, { 0xAD, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_SI, FCML_EOS_EOSA,FCML_SEG_ENCODE_REGISTER( FCML_REG_DS, FCML_SEG_ALLOW_OVERRIDE ) ),
			FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
	// TODO: Probably nedded by assembler.
	// AC LODSB A Valid Valid For legacy mode, Load byte at address DS:(E)SI into AL. For 64-bit mode load byte at address (R)SI into AL.
	// AD LODSW A Valid Valid For legacy mode, Load word at address DS:(E)SI into AX. For 64-bit mode load word at address (R)SI into AX.
	// AD LODSD A Valid Valid For legacy mode, Load dword at address DS:(E)SI into EAX. For 64-bit mode load dword at address (R)SI into EAX.
	// REX.W + AD LODSQ A Valid N.E. Load qword at address (R)SI into RAX.
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LOOP[] = {
	// E2 cb LOOP rel8 A Valid Valid Decrement count; jump short if count 0.
	{ NULL, 0x0001, 0x00C40000, { 0xE2, 0x00, 0x00 }, { FCML_OP_IMMEDIATE_DIS_RELATIVE_R_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// E1 cb LOOPE rel8 A Valid Valid Decrement count; jump short if count 0 and ZF = 1.
	{ "loope", 0x0001, 0x00C40000, { 0xE1, 0x00, 0x00 }, { FCML_OP_IMMEDIATE_DIS_RELATIVE_R_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// E0 cb LOOPNE rel8 A Valid Valid Decrement count; jump short if count 0 and ZF = 0.
	{ "loopne", 0x0001, 0x00C40000, { 0xE0, 0x00, 0x00 }, { FCML_OP_IMMEDIATE_DIS_RELATIVE_R_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
	// TODO: Alternatywne dla assemblera.
	// LOOP rel8off E2 cb Decrement rCX, then jump short if rCX is not 0.
	// LOOPE rel8off E1 cb Decrement rCX, then jump short if rCX is not 0 and ZF is 1.
	// LOOPNE rel8off E0 cb Decrement rCX, then Jump short if rCX is not 0 and ZF is 0.
	// LOOPNZ rel8off E0 cb Decrement rCX, then Jump short if rCX is not 0 and ZF is 0.
	// LOOPZ rel8off E1 cb Decrement rCX, then Jump short if rCX is not 0 and ZF is 1.
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LWPINS[] = {
	// LWPINS reg32.vvvv, reg/mem32, imm32 8F RXB.0A 0.src1.0.00 12 /0 /imm32
	{ NULL, 0x0450, 0x00D98000, { 0x0A, 0x12, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_OP_ID, FCML_NA, FCML_NA } },
	// LWPINS reg64.vvvv, reg/mem32, imm32 8F RXB.0A 1.src1.0.00 12 /0 /imm32
	{ NULL, 0x0448, 0x00D98000, { 0x0A, 0x12, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_OP_ID, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LWPVAL[] = {
	// LWPVAL reg32.vvvv, reg/mem32, imm32 8F RXB.0A 0.src1.0.00 12 /1 /imm32
	{ NULL, 0x0450, 0x00D98800, { 0x0A, 0x12, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_OP_ID, FCML_NA, FCML_NA } },
	// LWPVAL reg64.vvvv, reg/mem32, imm32 8F RXB.0A 1.src1.0.00 12 /1 /imm32
	{ NULL, 0x0448, 0x00D98800, { 0x0A, 0x12, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_OP_ID, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LSL[] = {
	// 0F 03 /r LSL r16, r16/m16 A Valid Valid Load: r16 segment limit, selector r16/m16.
	// 0F 03 /r LSL r32, r32/m16* A Valid Valid Load: r32 segment limit, selector r32/m16.
	{ NULL, 0x0001, 0x03D80000, { 0x0F, 0x03, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_RM( FCML_REG_GPR, FCML_EOS_EOSA, FCML_EOS_WORD, FCML_RMF_RM ), FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 0F 03 /r LSL r64, r32/m16* A Valid Valid Load: r64 segment limit, selector r32/m16
	{ NULL, 0x0001, 0x04980000, { 0x0F, 0x03, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_RM( FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_WORD, FCML_RMF_RM ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LTR[] = {
	// 0F 00 /3 LTR r/m16 A Valid Valid Load r/m16 into task register.
	{ NULL, 0x0001, 0x00D99800, { 0x0F, 0x00, 0x00 }, { FCML_OP_MODRM_RM_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MASKMOVDQU[] = {
	// 66 0F F7 /r MASKMOVDQU xmm1, xmm2 A Valid Valid Selectively write bytes from xmm1 to memory location using the byte mask in xmm2. The default memory location is specified by DS:EDI/RDI.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xF7, 0x00 }, { FCML_OP_R( FCML_REG_SIMD, FCML_EOS_OWORD ), FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F F7 /r VMASKMOVDQU xmm1,xmm2
	{ "vmaskmovdqu", 0x11C0, 0x00D88000, { 0x0F, 0xF7, 0x00 }, { FCML_OP_R( FCML_REG_SIMD, FCML_EOS_OWORD ), FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VMASKMOVP[] = {
	// VEX.NDS.128.66.0F38 2C /r VMASKMOVPS xmm1,xmm2,m128
	// VEX.NDS.256.66.0F38 2C /r VMASKMOVPS ymm1,ymm2,m256
	{ "vmaskmovps", 0x1080, 0x00EC8000, { 0x0F, 0x38, 0x2C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_M_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38 2D /r VMASKMOVPD xmm1,xmm2,m128
	// VEX.NDS.256.66.0F38 2D /r VMASKMOVPD ymm1,ymm2,m256
	{ "vmaskmovpd", 0x1080, 0x00EC8000, { 0x0F, 0x38, 0x2D }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_M_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38 2E /r VMASKMOVPS m128,xmm1,xmm2
	// VEX.NDS.256.66.0F38 2E /r VMASKMOVPS m256,ymm1,ymm2
	{ "vmaskmovps", 0x1080, 0x00EC8000, { 0x0F, 0x38, 0x2E }, { FCML_OP_MODRM_M_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_R_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38 2F /r VMASKMOVPD m128,xmm1,xmm2
	// VEX.NDS.256.66.0F38 2F /r VMASKMOVPD m256,ymm1,ymm2
	{ "vmaskmovpd", 0x1080, 0x00EC8000, { 0x0F, 0x38, 0x2F }, { FCML_OP_MODRM_M_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_R_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPMASKMOVD[] = {
	// VEX.NDS.128.66.0F38.W0 8C /r VPMASKMOVD xmm1,xmm2,m128
	// VEX.NDS.256.66.0F38.W0 8C /r VPMASKMOVD ymm1,ymm2,m256
	{ "vpmaskmovd", 0x1090, 0x80EC8000, { 0x0F, 0x38, 0x8C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_M_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.W1 8C /r VPMASKMOVQ xmm1,xmm2,m128
	// VEX.NDS.256.66.0F38.W1 8C /r VPMASKMOVQ ymm1,ymm2,m256
	{ "vpmaskmovq", 0x1088, 0x80EC8000, { 0x0F, 0x38, 0x8C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_M_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.W0 8E /r VPMASKMOVD m128,xmm1,xmm2
	// VEX.NDS.256.66.0F38.W0 8E /r VPMASKMOVD m256,ymm1,ymm2
	{ "vpmaskmovd", 0x1090, 0x80EC8000, { 0x0F, 0x38, 0x8E }, { FCML_OP_MODRM_M_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_R_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.W1 8E /r VPMASKMOVQ m128,xmm1,xmm2
	// VEX.NDS.256.66.0F38.W1 8E /r VPMASKMOVQ m256,ymm1,ymm2
	{ "vpmaskmovq", 0x1088, 0x80EC8000, { 0x0F, 0x38, 0x8E }, { FCML_OP_MODRM_M_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_R_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MASKMOVQ[] = {
	// 0F F7 /r MASKMOVQ mm1, mm2 A Valid Valid Selectively write bytes from mm1 to memory location using the byte mask in mm2. The default memory location is specified by DS:EDI/RDI.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xF7, 0x00 }, { FCML_OP_R( FCML_REG_SIMD, FCML_EOS_QWORD ), FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MAXPD[] = {
	// 66 0F 5F /r MAXPD xmm1, xmm2/m128 A Valid Valid Return the maximum double-precision floatingpoint values between xmm2/m128 and xmm1.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x5F, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F 5F /r VMAXPD xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F 5F /r VMAXPD ymm1,ymm2,ymm3/m256
	{ "vmaxpd", 0x1080, 0x00D88000, { 0x0F, 0x5F, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MAXPS[] = {
	// 0F 5F /r MAXPS xmm1, xmm2/m128 A Valid Valid Return the maximum singleprecision floating-point values between xmm2/m128 and xmm1.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x5F, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F 5F /r VMAXPS xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.0F 5F /r VMAXPS ymm1,ymm2,ymm3/m256
	{ "vmaxps", 0x0080, 0x00D88000, { 0x0F, 0x5F, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

// TODO: Zastanowic sie na dwiloscia operandu podawanego dla trubow FCML_OP_MODRM_R_, czy ma ona sens? Najprwdopodobniejnie ma to zadnego znaczenia przynajmniej z punktu widzenia assemblera, no moze tylko dla GPR tu ma.

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MAXSD[] = {
	// F2 0F 5F /r MAXSD xmm1, xmm2/m64 A Valid Valid Return the maximum scalardouble-precision floatingpoint value between xmm2/mem64 and xmm1.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0x5F, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F 5F /r VMAXSD xmm1,xmm2,xmm3/m64
	{ "vmaxsd", 0x20C0, 0x00D88000, { 0x0F, 0x5F, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MAXSS[] = {
	// F3 0F 5F /r MAXSS xmm1, xmm2/m32 A Valid Valid Return the maximum scalarsingle-precision floatingpoint value between xmm2/mem32 and xmm1.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x5F, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F3.0F 5F /r VMAXSS xmm1, xmm2, xmm3/m32
	{ "vmaxss", 0x40C0, 0x00D88000, { 0x0F, 0x5F, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MFENCE[] = {
	// MFENCE 0F AE /6  A Valid Valid Serializes load and store operations.
	{ NULL, 0x0001, 0x00EC0000, { 0x0F, 0xAE, 0xF0 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MINPD[] = {
	// 66 0F 5D /r MINPD xmm1, xmm2/m128 A Valid Valid Return the minimum doubleprecision floating-point values between xmm2/m128 and xmm1.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x5D, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F 5D /r VMINPD xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F 5D /r VMINPD ymm1,ymm2,ymm3/m256
	{ "vminpd", 0x1080, 0x00D88000, { 0x0F, 0x5D, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MINPS[] = {
	// 0F 5D /r MINPS xmm1, xmm2/m128 A Valid Valid Return the minimum singleprecision floating-point values between xmm2/m128 and xmm1.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x5D, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F 5D /r VMINPS xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.0F 5D /r VMINPS ymm1,ymm2,ymm3/m256
	{ "vminps", 0x0080, 0x00D88000, { 0x0F, 0x5D, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MINSD[] = {
	// F2 0F 5D /r MINSD xmm1, xmm2/m64 A Valid Valid Return the minimum scalar double-precision floatingpoint value between xmm2/mem64 and xmm1.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0x5D, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F 5D /r VMINSD xmm1, xmm2, xmm3/m64
	{ "vminsd", 0x20C0, 0x00D88000, { 0x0F, 0x5D, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MINSS[] = {
	// F3 0F 5D /r MINSS xmm1, xmm2/m32 A Valid Valid Return the minimum scalar single-precision floatingpoint value between xmm2/mem32 and xmm1.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x5D, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F3.0F 5D /r VMINSS xmm1,xmm2,xmm3/m32
	{ "vminss", 0x40C0, 0x00D88000, { 0x0F, 0x5D, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } }
};

// TODO: Zastanowic sie nad operandami virtualnymi, czyli takimi ktore wystepuja w instrukcji ale tak naprawde nie sa zapiane w pecyfikacji jako operancdy patrz instrukcja ponizej:

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MONITOR[] = {
	// 0F 01 C8 MONITOR A Valid Valid Sets up a linear address range to be monitored by hardware and activates the monitor. The address range should be a write-back memory caching type. The address is DS:EAX
	{ NULL, 0x0001, 0x006C0000, { 0x0F, 0x01, 0xC8 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_EAX, FCML_EOS_DWORD ),
		FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_ECX, FCML_EOS_DWORD ),
		FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_EDX, FCML_EOS_DWORD ), FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x00AC0000, { 0x0F, 0x01, 0xC8 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_RAX, FCML_EOS_QWORD ),
		FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_RCX, FCML_EOS_QWORD ),
		FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_RDX, FCML_EOS_QWORD ), FCML_NA, FCML_NA } }
	// TODO: Przy assemblacji pameitac zeby pozwolic na assemblacje samej mnemoniki!, byc moze idea virtualnych opcod rozwiaze problem
};



struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOV[] = {
	// 88 /r MOV r/m8,r8 A Valid Valid Move r8 to r/m8.
	// REX + 88 /r MOV r/m8***,r8*** A Valid N.E. Move r8 to r/m8.
	{ NULL, 0x0001, 0x00C48000, { 0x88, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_MODRM_R_8, FCML_NA, FCML_NA, FCML_NA } },
	// 89 /r MOV r/m16,r16 A Valid Valid Move r16 to r/m16.
	// 89 /r MOV r/m32,r32 A Valid Valid Move r32 to r/m32.
	// REX.W + 89 /r MOV r/m64,r64 A Valid N.E. Move r64 to r/m64.
	{ NULL, 0x0001, 0x00C48000, { 0x89, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
	// 8A /r MOV r8,r/m8 B Valid Valid Move r/m8 to r8.
	// REX + 8A /r MOV r8***,r/m8*** B Valid N.E. Move r/m8 to r8.
	{ NULL, 0x0001, 0x00C48000, { 0x8A, 0x00, 0x00 }, { FCML_OP_MODRM_R_8_W, FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA } },
	// 8B /r MOV r16,r/m16 B Valid Valid Move r/m16 to r16.
	// 8B /r MOV r32,r/m32 B Valid Valid Move r/m32 to r32.
	// REX.W + 8B /r MOV r64,r/m64 B Valid N.E. Move r/m64 to r64.
	{ NULL, 0x0001, 0x00C48000, { 0x8B, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } },
	// 8C /r MOV r/m16,Sreg** A Valid Valid Move segment register to r/m16.
	{ NULL, 0x0001, 0x03C48000, { 0x8C, 0x00, 0x00 }, { FCML_OP_MODRM_RM_16_W, FCML_OP_R( FCML_REG_SEG, FCML_EOS_WORD ), FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 8C /r MOV r/m64,Sreg** A Valid Valid Move zero extended 16-bit segment register to r/m64.

	// TODO: Assembler hint: The processor will execute this instruction correctly, but it will usually require an extra clock. With most assemblers, using the instruction form MOV DS, EAX will avoid this unneeded 66H prefix.

	{ NULL, 0x0001, 0x04848000, { 0x8C, 0x00, 0x00 }, { FCML_OP_MODRM_RM_64_W, FCML_OP_R( FCML_REG_SEG, FCML_EOS_WORD ), FCML_NA, FCML_NA, FCML_NA } },
	// 8E /r MOV Sreg,r/m16** RM Valid Valid Move r/m16 to segment register.
	{ NULL, 0x0001, 0x03C48000, { 0x8E, 0x00, 0x00 }, { FCML_OP_R( FCML_REG_SEG, FCML_EOS_WORD ), FCML_OP_MODRM_RM_16_W, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 8E /r MOV Sreg,r/m64** RM Valid Valid Move lower 16 bits of r/m64 to segment register.
	{ NULL, 0x0001, 0x04848000, { 0x8E, 0x00, 0x00 }, { FCML_OP_R( FCML_REG_SEG, FCML_EOS_WORD ), FCML_OP_MODRM_RM_64_W, FCML_NA, FCML_NA, FCML_NA } },
	// A0 MOV AL,moffs8* C Valid Valid Move byte at (seg:offset) to AL.
	// REX.W + A0 MOV AL,moffs8* C Valid N.E. Move byte at (offset) to AL.
	{ NULL, 0x0001, 0x00C40000, { 0xA0, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_OP_SEGMENT_RELATIVE_OFFSET( FCML_EOS_BYTE, FCML_SEG_ENCODE_REGISTER( FCML_REG_DS, FCML_SEG_ALLOW_OVERRIDE ) ), FCML_NA, FCML_NA, FCML_NA } },
	// A1 MOV AX,moffs16* C Valid Valid Move word at (seg:offset) to AX.
	// A1 MOV EAX,moffs32* C Valid Valid Move doubleword at (seg:offset) to EAX.
	// REX.W + A1 MOV RAX,moffs64* C Valid N.E. Move quadword at (offset) to RAX.
	{ NULL, 0x0001, 0x00C40000, { 0xA1, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ), FCML_OP_SEGMENT_RELATIVE_OFFSET( FCML_EOS_EOSA, FCML_SEG_ENCODE_REGISTER( FCML_REG_DS, FCML_SEG_ALLOW_OVERRIDE ) ), FCML_NA, FCML_NA, FCML_NA } },
	// A2 MOV moffs8,AL D Valid Valid Move AL to (seg:offset).
	// REX.W + A2 MOV moffs8***,AL D Valid N.E. Move AL to (offset).
	{ NULL, 0x0001, 0x00C40000, { 0xA2, 0x00, 0x00 }, { FCML_OP_SEGMENT_RELATIVE_OFFSET( FCML_EOS_BYTE, FCML_SEG_ENCODE_REGISTER( FCML_REG_DS, FCML_SEG_ALLOW_OVERRIDE ) ), FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// A3 MOV moffs16*,AX D Valid Valid Move AX to (seg:offset).
	// A3 MOV moffs32*,EAX D Valid Valid Move EAX to (seg:offset).
	// REX.W + A3 MOV moffs64*,RAX D Valid N.E. Move RAX to (offset).
	{ NULL, 0x0001, 0x00C40000, { 0xA3, 0x00, 0x00 }, { FCML_OP_SEGMENT_RELATIVE_OFFSET( FCML_EOS_EOSA, FCML_SEG_ENCODE_REGISTER( FCML_REG_DS, FCML_SEG_ALLOW_OVERRIDE ) ), FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ), FCML_NA, FCML_NA, FCML_NA } },
	// B0+ rb MOV r8, imm8 E Valid Valid Move imm8 to r8.
	// REX + B0+ rb MOV r8***, imm8 E Valid N.E. Move imm8 to r8.
	{ NULL, 0x0001, 0x00C40001, { 0xB0, 0x00, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_BYTE ) | FCML_OA_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// B8+ rw MOV r16, imm16 E Valid Valid Move imm16 to r16.
	// B8+ rd MOV r32, imm32 E Valid Valid Move imm32 to r32.
	// REX.W + B8+ rd MOV r64, imm64 E Valid N.E. Move imm64 to r64.
	{ NULL, 0x0001, 0x00C40001, { 0xB8, 0x00, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// C6 /0 MOV r/m8, imm8 F Valid Valid Move imm8 to r/m8.
	// REX + C6 /0 MOV r/m8***, imm8 F Valid N.E. Move imm8 to r/m8.
	{ NULL, 0x0001, 0x00C58000, { 0xC6, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// C7 /0 MOV r/m16, imm16 F Valid Valid Move imm16 to r/m16.
	// C7 /0 MOV r/m32, imm32 F Valid Valid Move imm32 to r/m32.
	{ NULL, 0x0001, 0x03C58000, { 0xC7, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + C7 /0 MOV r/m64, imm32 F Valid N.E. Move imm32 sign extended to 64-bits to r/m64.
	{ NULL, 0x0001, 0x04858000, { 0xC7, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOV_CR[] = {
	// 0F 20/r MOV r32, CR0�CR7 A N.E. Valid Move control register to r32
	{ NULL, 0x0001, 0x00588000, { 0x0F, 0x20, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ) | FCML_OA_W, FCML_OP_R( FCML_REG_CR, FCML_EOS_DWORD ), FCML_NA, FCML_NA, FCML_NA } },
	// 0F 20/r MOV r64, CR0�CR7 A Valid N.E. Move extended control register to r64.
	// REX.R + 0F 20 /0 MOV r64, CR8 A Valid N.E. Move extended CR8 to r64.1
	{ NULL, 0x0001, 0x00988000, { 0x0F, 0x20, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ) | FCML_OA_W, FCML_OP_R( FCML_REG_CR, FCML_EOS_QWORD ), FCML_NA, FCML_NA, FCML_NA } },
	// 0F 22 /r MOV CR0�CR7, r32 A N.E. Valid Move r32 to control register
	{ NULL, 0x0001, 0x00588000, { 0x0F, 0x22, 0x00 }, { FCML_OP_R( FCML_REG_CR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_RM( FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	// 0F 22 /r MOV CR0�CR7, r64 A Valid N.E. Move r64 to extended control register.
	// REX.R + 0F 22 /0 MOV CR8, r64 A Valid N.E. Move r64 to extended CR8.1
	{ NULL, 0x0001, 0x00988000, { 0x0F, 0x22, 0x00 }, { FCML_OP_R( FCML_REG_CR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_RM( FCML_REG_GPR, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOV_DR[] = {
	// 0F 21/r MOV r32, DR0�DR7 A N.E. Valid Move debug register to r32
	{ NULL, 0x0001, 0x00588000, { 0x0F, 0x21, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ) | FCML_OA_W, FCML_OP_R( FCML_REG_DR, FCML_EOS_DWORD ), FCML_NA, FCML_NA, FCML_NA } },
	// 0F 21/r MOV r64, DR0�DR7 A Valid N.E. Move extended debug register to r64.
	{ NULL, 0x0001, 0x00988000, { 0x0F, 0x21, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ) | FCML_OA_W, FCML_OP_R( FCML_REG_DR, FCML_EOS_QWORD ), FCML_NA, FCML_NA, FCML_NA } },
	// 0F 23 /r MOV DR0�DR7, r32 A N.E. Valid Move r32 to debug register
	{ NULL, 0x0001, 0x00588000, { 0x0F, 0x23, 0x00 }, { FCML_OP_R( FCML_REG_DR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_RM( FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	// 0F 23 /r MOV DR0�DR7, r64 A Valid N.E. Move r64 to extended debug register.
	{ NULL, 0x0001, 0x00988000, { 0x0F, 0x23, 0x00 }, { FCML_OP_R( FCML_REG_DR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_RM( FCML_REG_GPR, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVAPD[] = {
	// 66 0F 28 /r MOVAPD xmm1, xmm2/m128 A Valid Valid Move packed doubleprecision floating-point values from xmm2/m128 to xmm1.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x28, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 29 /r MOVAPD xmm2/m128, xmm1 B Valid Valid Move packed doubleprecision floating-point values from xmm1 to xmm2/m128.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x29, 0x00 }, { FCML_OP_MODRM_RM_XMM_128_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F 28 /r VMOVAPD xmm1,xmm2/m128
	// VEX.256.66.0F 28 /r VMOVAPD ymm1,ymm2/m256
	{ "vmovapd", 0x1180, 0x00D88000, { 0x0F, 0x28, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F 29 /r VMOVAPD xmm2/m128,xmm1
	// VEX.256.66.0F 29 /r VMOVAPD ymm2/m256,ymm1
	{ "vmovapd", 0x1180, 0x00D88000, { 0x0F, 0x29, 0x00 }, { FCML_OP_MODRM_RM_SIMD_L_W, FCML_OP_MODRM_R_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVAPS[] = {
	// 0F 28 /r MOVAPS xmm1, xmm2/m128 A Valid Valid Move packed singleprecision floating-point values from xmm2/m128 to xmm1.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x28, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 29 /r MOVAPS xmm2/m128, xmm1 B Valid Valid Move packed singleprecision floating-point values from xmm1 to xmm2/m128.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x29, 0x00 }, { FCML_OP_MODRM_RM_XMM_128_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.0F 28 /r VMOVAPS xmm1,xmm2/m128
	// VEX.256.0F 28 /r VMOVAPS ymm1,ymm2/m256
	{ "vmovaps", 0x0180, 0x00D88000, { 0x0F, 0x28, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.0F 29 /r VMOVAPS xmm2/m128,xmm1
	// VEX.256.0F 29 /r VMOVAPS ymm2/m256,ymm1
	{ "vmovaps", 0x0180, 0x00D88000, { 0x0F, 0x29, 0x00 }, { FCML_OP_MODRM_RM_SIMD_L_W, FCML_OP_MODRM_R_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVBE[] = {
	// 0F 38 F0 /r MOVBE r16, m16 A Valid Valid Reverse byte order in m16 and move to r16
	// 0F 38 F0 /r MOVBE r32, m32 A Valid Valid Reverse byte order in m32 and move to r32
	// REX.W + 0F 38 F0 /r MOVBE r64, m64 A Valid N.E. Reverse byte order in m64 and move to r64.
	{ NULL, 0x0001, 0x00EC8000, { 0x0F, 0x38, 0xF0 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 38 F1 /r MOVBE m16, r16 B Valid Valid Reverse byte order in r16 and move to m16
	// 0F 38 F1 /r MOVBE m32, r32 B Valid Valid Reverse byte order in r32 and move to m32
	// REX.W + 0F 38 F1 /r MOVBE m64, r64 B Valid N.E. Reverse byte order in
	{ NULL, 0x0001, 0x00EC8000, { 0x0F, 0x38, 0xF1 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVD[] = {
	// 0F 6E /r MOVD mm,r/m32 A Valid Valid Move doubleword from r/m32 to mm.
	{ NULL, 0x0001, 0x03D88000, { 0x0F, 0x6E, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 0F 6E /r MOVQ mm, r/m64 A Valid N.E. Move quadword from r/m64 to mm.
	{ "movq", 0x0001, 0x04988000, { 0x0F, 0x6E, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 7E /r MOVD r/m32, mm B Valid Valid Move doubleword from mm to r/m32.
	{ NULL, 0x0001, 0x03D88000, { 0x0F, 0x7E, 0x00 }, { FCML_OP_MODRM_RM_32_W, FCML_OP_MODRM_R_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 0F 7E /r MOVQ r/m64, mm B Valid N.E. Move quadword from mm to r/m64.
	{ "movq", 0x0001, 0x04988000, { 0x0F, 0x7E, 0x00 }, { FCML_OP_MODRM_RM_64_W, FCML_OP_MODRM_R_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 6E /r MOVD xmm, r/m32 A Valid Valid Move doubleword from r/m32 to xmm.
	{ NULL, 0x1001, 0x03D88000, { 0x0F, 0x6E, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// 66 REX.W 0F 6E /r MOVQ xmm, r/m64 A Valid N.E. Move quadword from r/m64 to xmm.
	{ "movq", 0x1001, 0x04988000, { 0x0F, 0x6E, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 7E /r MOVD r/m32, xmm B Valid Valid Move doubleword from xmm register to r/m32.
	{ NULL, 0x1001, 0x03D88000, { 0x0F, 0x7E, 0x00 }, { FCML_OP_MODRM_RM_32_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// 66 REX.W 0F 7E /r MOVQ r/m64, xmm B Valid N.E. Move quadword from xmm register to r/m64.
	{ "movq", 0x1001, 0x04988000, { 0x0F, 0x7E, 0x00 }, { FCML_OP_MODRM_RM_64_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F.W0 6E /r VMOVD xmm1,r32/m32
	{ "vmovd", 0x11D0, 0x03588000, { 0x0F, 0x6E, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F.W1 6E /r VMOVQ xmm1,r64/m64
	{ "vmovq", 0x11C8, 0x04988000, { 0x0F, 0x6E, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F.W0 7E /r VMOVD r32/m32,xmm1
	{ "vmovd", 0x11D0, 0x03588000, { 0x0F, 0x7E, 0x00 }, { FCML_OP_MODRM_RM_32_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F.W1 7E /r VMOVQ r64/m64,xmm1
	{ "vmovq", 0x11C8, 0x04988000, { 0x0F, 0x7E, 0x00 }, { FCML_OP_MODRM_RM_64_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVDDUP[] = {
	//F2 0F 12 /r MOVDDUP xmm1, xmm2/m64 A Valid Valid Move one double-precision floating-point value from the lower 64-bit operand in xmm2/m64 to xmm1 and duplicate.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0x12, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F2.0F 12 /r VMOVDDUP xmm1,xmm2/m64
	{ "vmovddup", 0x21C0, 0x00D88000, { 0x0F, 0x12, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.F2.0F 12 /r VMOVDDUP ymm1,ymm2/m256
	{ "vmovddup", 0x21A0, 0x00D88000, { 0x0F, 0x12, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVDQA[] = {
	// 66 0F 6F /r MOVDQA xmm1, xmm2/m128 A Valid Valid Move aligned double quadword from xmm2/m128 to xmm1.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x6F, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 7F /r MOVDQA xmm2/m128, xmm1 B Valid Valid Move aligned double quadword from xmm1 to xmm2/m128.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x7F, 0x00 }, { FCML_OP_MODRM_RM_XMM_128_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F 6F /r VMOVDQA xmm1,xmm2/m128
	// VEX.256.66.0F 6F /r VMOVDQA ymm1,ymm2/m256
	{ "vmovdqa", 0x1180, 0x00D88000, { 0x0F, 0x6F, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F 7F /r VMOVDQA xmm2/m128,xmm1
	// VEX.256.66.0F 7F /r VMOVDQA ymm2/m256,ymm1
	{ "vmovdqa", 0x1180, 0x00D88000, { 0x0F, 0x7F, 0x00 }, { FCML_OP_MODRM_RM_SIMD_L_W, FCML_OP_MODRM_R_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVDQU[] = {
	// F3 0F 6F /r MOVDQU xmm1, xmm2/m128 A Valid Valid Move unaligned double quadword from xmm2/m128 to xmm1.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x6F, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// F3 0F 7F /r MOVDQU xmm2/m128, xmm1 B Valid Valid Move unaligned double quadword from xmm1 to xmm2/m128.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x7F, 0x00 }, { FCML_OP_MODRM_RM_XMM_128_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F 6F /r VMOVDQU xmm1,xmm2/m128
	// VEX.256.F3.0F 6F /r VMOVDQU ymm1,ymm2/m256
	{ "vmovdqu", 0x4180, 0x00D88000, { 0x0F, 0x6F, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F 7F /r VMOVDQU xmm2/m128,xmm1
	// VEX.256.F3.0F 7F /r VMOVDQU ymm2/m256,ymm1
	{ "vmovdqu", 0x4180, 0x00D88000, { 0x0F, 0x7F, 0x00 }, { FCML_OP_MODRM_RM_SIMD_L_W, FCML_OP_MODRM_R_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVDQ2Q[] = {
	// F2 0F D6 MOVDQ2Q mm, xmm A Valid Valid Move low quadword from xmm to mmx register.
	{ NULL, 0x2001, 0x00DA8000, { 0x0F, 0xD6, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVHLPS[] = {
	// 0F 12 /r MOVHLPS xmm1, xmm2 A Valid Valid Move two packed singleprecision floating-point values from high quadword of xmm2 to low quadword of xmm1.
	{ NULL, 0x0001, 0x00DA8000, { 0x0F, 0x12, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F 12 /r VMOVHLPS xmm1, xmm2, xmm3
	{ "vmovhlps", 0x00C0, 0x00DA8000, { 0x0F, 0x12, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_L, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVHPD[] = {
	// 66 0F 16 /r MOVHPD xmm, m64 A Valid Valid Move double-precision floating-point value from m64 to high quadword of xmm.
	{ NULL, 0x1001, 0x80D88000, { 0x0F, 0x16, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_QWORD, FCML_RMF_M ), FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 17 /r MOVHPD m64, xmm B Valid Valid Move double-precision floating-point value from high quadword of xmm to m64.
	{ NULL, 0x1001, 0x80D88000, { 0x0F, 0x17, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_QWORD, FCML_RMF_M ) | FCML_OA_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F 16 /r VMOVHPD xmm2,xmm1,m64
	{ "vmovhpd", 0x10C0, 0x80D88000, { 0x0F, 0x16, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA } },
	// VEX128.66.0F 17/r VMOVHPD m64, xmm1
	{ "vmovhpd", 0x11C0, 0x80D88000, { 0x0F, 0x17, 0x00 }, { FCML_OP_MODRM_RM_SIMD_L_64_W, FCML_OP_MODRM_R_SIMD_L_W, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVHPS[] = {
	// 0F 16 /r MOVHPS xmm, m64 A Valid Valid Move two packed singleprecision floating-point values from m64 to high quadword of xmm.
	{ NULL, 0x0001, 0x80D88000, { 0x0F, 0x16, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_QWORD, FCML_RMF_M ), FCML_NA, FCML_NA, FCML_NA } },
	// 0F 17 /r MOVHPS m64, xmm B Valid Valid Move two packed singleprecision floating-point values from high quadword of xmm to m64.
	{ NULL, 0x0001, 0x80D88000, { 0x0F, 0x17, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_QWORD, FCML_RMF_M ) | FCML_OA_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F 16 /r VMOVHPS xmm2,xmm1,m64
	{ "vmovhps", 0x00C0, 0x80D88000, { 0x0F, 0x16, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA } },
	// VEX.128.0F 17 /r VMOVHPS m64,xmm1
	{ "vmovhps", 0x01C0, 0x80D88000, { 0x0F, 0x17, 0x00 }, { FCML_OP_MODRM_RM_SIMD_L_64_W, FCML_OP_MODRM_R_SIMD_L_W, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVLHPS[] = {
	// 0F 16 /r MOVLHPS xmm1, xmm2 A Valid Valid Move two packed singleprecision floating-point values from low quadword of xmm2 to high quadword of xmm1.
	{ NULL, 0x0001, 0x00DA8000, { 0x0F, 0x16, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F 16 /r VMOVLHPS xmm1,xmm2,xmm3
	{ "vmovlhps", 0x00C0, 0x00DA8000, { 0x0F, 0x16, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVLPD[] = {
	// 66 0F 12 /r MOVLPD xmm, m64 A Valid Valid Move double-precision floating-point value from m64 to low quadword of xmm register.
	{ NULL, 0x1001, 0x80D88000, { 0x0F, 0x12, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_QWORD, FCML_RMF_M ), FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 13 /r MOVLPD m64, xmm B Valid Valid Move double-precision floating-point nvalue from low quadword of xmm register to m64.
	{ NULL, 0x1001, 0x80D88000, { 0x0F, 0x13, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_QWORD, FCML_RMF_M ) | FCML_OA_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F 12 /r VMOVLPD xmm2,xmm1,m64
	{ "vmovlpd", 0x10C0, 0x80D88000, { 0x0F, 0x12, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA } },
	// VEX.128.66.0F 13 /r VMOVLPD m64,xmm1
	{ "vmovlpd", 0x11C0, 0x80D88000, { 0x0F, 0x13, 0x00 }, { FCML_OP_MODRM_RM_SIMD_L_64_W, FCML_OP_MODRM_R_SIMD_L_W, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVLPS[] = {
	// 0F 12 /r MOVLPS xmm, m64 A Valid Valid Move two packed singleprecision floating-point values from m64 to low quadword of xmm.
	{ NULL, 0x0001, 0x80D88000, { 0x0F, 0x12, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_QWORD, FCML_RMF_M ), FCML_NA, FCML_NA, FCML_NA } },
	// 0F 13 /r MOVLPS m64, xmm B Valid Valid Move two packed singleprecision floating-point values from low quadword of xmm to m64.
	{ NULL, 0x0001, 0x80D88000, { 0x0F, 0x13, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_QWORD, FCML_RMF_M ) | FCML_OA_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F 12 /r VMOVLPS xmm2,xmm1,m64
	{ "vmovlps", 0x00C0, 0x80D88000, { 0x0F, 0x12, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_M_64, FCML_NA, FCML_NA } },
	// VEX.128.0F 13 /r VMOVLPS m64, xmm1
	{ "vmovlps", 0x01C0, 0x80D88000, { 0x0F, 0x13, 0x00 }, { FCML_OP_MODRM_M_64_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVMSKPD[] = {
	// 66 0F 50 /r MOVMSKPD reg, xmm A Valid Valid Extract 2-bit sign mask from xmm and store in reg. The upper bits of r32 or r64 are filled with zeros.
	{ NULL, 0x1001, 0x005A8000, { 0x0F, 0x50, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x1001, 0x009A8000, { 0x0F, 0x50, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F 50 /r VMOVMSKPD reg,xmm2
	// VEX.256.66.0F 50 /r VMOVMSKPD reg,ymm2
	{ "vmovmskpd", 0x1180, 0x005A8000, { 0x0F, 0x50, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_L, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	{ "vmovmskpd", 0x1180, 0x009A8000, { 0x0F, 0x50, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_L, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVMSKPS[] = {
	// 0F 50 /r MOVMSKPS reg, xmm A Valid Valid Extract 4-bit sign mask from xmm and store in reg. The upper bits of r32 or r64 are filled with zeros.
	{ NULL, 0x0001, 0x005A8000, { 0x0F, 0x50, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x009A8000, { 0x0F, 0x50, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.0F 50 /r VMOVMSKPS reg,xmm2
	// VEX.256.0F 50 /r VMOVMSKPS reg,ymm2
	{ "vmovmskps", 0x0180, 0x005A8000, { 0x0F, 0x50, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_L, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	{ "vmovmskps", 0x0180, 0x009A8000, { 0x0F, 0x50, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_L, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVNTDQA[] = {
	// 66 0F 38 2A /r MOVNTDQA xmm1, m128 A Valid Valid Move double quadword from m128 to xmm using non-temporal hint if WC memory type.
	{ NULL, 0x1001, 0x80EC8000, { 0x0F, 0x38, 0x2A }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_OWORD, FCML_RMF_M ), FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38 2A /r VMOVNTDQA xmm1,m128
	{ "vmovntdqa", 0x11C0, 0x80EC8000, { 0x0F, 0x38, 0x2A }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_M_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.WIG 2A /r VMOVNTDQA ymm1,m256
	{ "vmovntdqa", 0x11A0, 0x80EC8000, { 0x0F, 0x38, 0x2A }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_M_256, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVNTDQ[] = {
	// 66 0F E7 /r MOVNTDQ m128, xmm A Valid Valid Move double quadword from xmm to m128 using non-temporal hint.
	{ NULL, 0x1001, 0x80D88000, { 0x0F, 0xE7, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_OWORD, FCML_RMF_M ) | FCML_OA_W, FCML_OP_MODRM_R_XMM , FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F E7 /r VMOVNTDQ m128,xmm1
	{ "vmovntdq", 0x11C0, 0x80D88000, { 0x0F, 0xE7, 0x00 }, { FCML_OP_MODRM_M_128_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVNTI[] = {
	// 0F C3 /r MOVNTI m32, r32 A Valid Valid Move doubleword from r32 to m32 using non-temporal hint.
	{ NULL, 0x0001, 0x83D88000, { 0x0F, 0xC3, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_DWORD, FCML_RMF_M ) | FCML_OA_W, FCML_OP_MODRM_R_32 , FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 0F C3 /rMOVNTI m64, r64 A Valid N.E. Move quadword from r64 to m64 using non-temporal hint.
	{ NULL, 0x0001, 0x84988000, { 0x0F, 0xC3, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_QWORD, FCML_RMF_M ) | FCML_OA_W, FCML_OP_MODRM_R_64 , FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVNTPD[] = {
	// 66 0F 2B /r MOVNTPD m128, xmm A Valid Valid Move packed doubleprecision floating-point values from xmm to m128 using non-temporal hint.
	{ NULL, 0x1001, 0x80D88000, { 0x0F, 0x2B, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_OWORD, FCML_RMF_M ) | FCML_OA_W, FCML_OP_MODRM_R_XMM , FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F 2B /r VMOVNTPD m128,xmm1
	{ "vmovntpd", 0x11C0, 0x80D88000, { 0x0F, 0x2B, 0x00 }, { FCML_OP_MODRM_M_128_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVNTPS[] = {
	// 0F 2B /r MOVNTPS m128, xmm A Valid Valid Move packed singleprecision floating-point values from xmm to m128 using non-temporal hint.
	{ NULL, 0x0001, 0x80D88000, { 0x0F, 0x2B, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_OWORD, FCML_RMF_M ) | FCML_OA_W, FCML_OP_MODRM_R_XMM , FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.0F 2B /r VMOVNTPS m128, xmm1
	{ "vmovntps", 0x01C0, 0x80D88000, { 0x0F, 0x2B, 0x00 }, { FCML_OP_MODRM_M_128_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVNTSD[] = {
	// MOVNTSD mem64, xmm F2 0F 2B /r
	{ NULL, 0x2000, 0x80D88000, { 0x0F, 0x2B, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_QWORD, FCML_RMF_M ) | FCML_OA_W, FCML_OP_MODRM_R_XMM , FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVNTSS[] = {
	// MOVNTSS mem32, xmm F3 0F 2B /r
	{ NULL, 0x4000, 0x80D88000, { 0x0F, 0x2B, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_DWORD, FCML_RMF_M ) | FCML_OA_W, FCML_OP_MODRM_R_XMM , FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVNTQ[] = {
	// 0F E7 /r MOVNTQ m64, mm A Valid Valid Move quadword from mm to m64 using non-temporal hint.
	{ NULL, 0x0001, 0x80D88000, { 0x0F, 0xE7, 0x00 }, { FCML_OP_RM( FCML_REG_UNDEFINED, FCML_EOS_UNDEFINED, FCML_EOS_QWORD, FCML_RMF_M ) | FCML_OA_W, FCML_OP_MODRM_R_MMX , FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVQ[] = {
	// 0F 6F /r MOVQ mm, mm/m64 A Valid Valid Move quadword from mm/m64 to mm.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x6F, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 7F /r MOVQ mm/m64, mm B Valid Valid Move quadword from mm to mm/m64.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x7F, 0x00 }, { FCML_OP_MODRM_RM_MMX_W, FCML_OP_MODRM_R_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// F3 0F 7E MOVQ xmm1, xmm2/m64 A Valid Valid Move quadword from xmm2/mem64 to xmm1.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x7E, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F D6 MOVQ xmm2/m64, xmm1 B Valid Valid Move quadword from xmm1 to xmm2/mem64.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xD6, 0x00 }, { FCML_OP_MODRM_RM_XMM_64_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F 7E /r VMOVQ xmm1,xmm2
	// VEX.128.F3.0F 7E /r VMOVQ xmm1,m64
	{ "vmovq", 0x41C0, 0x00D88000, { 0x0F, 0x7E, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F D6 /r VMOVQ xmm1/m64,xmm2
	{ "vmovq", 0x41C0, 0x00D88000, { 0x0F, 0xD6, 0x00 }, { FCML_OP_MODRM_RM_XMM_64_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } }

};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVQ2DQ[] = {
	// F3 0F D6 MOVQ2DQ xmm, mm A Valid Valid Move quadword from mmx to low quadword of xmm.
	{ NULL, 0x4001, 0x00DA8000, { 0x0F, 0xD6, 0x00 }, { FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ) | FCML_OA_W, FCML_OP_MODRM_R_MMX, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVS[] = {
	// A4 MOVS m8, m8 A Valid Valid For legacy mode, Move byte from address DS:(E)SI to ES:(E)DI. For 64-bit mode move byte from address (R|E)SI to (R|E)DI.
	{ NULL, 0x0001, 0x00C40000, { 0xA4, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_SI, FCML_EOS_BYTE, FCML_SEG_ENCODE_REGISTER( FCML_REG_DS, FCML_SEG_ALLOW_OVERRIDE ) ),
			FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_BYTE, FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ),
			FCML_NA, FCML_NA, FCML_NA } },
	// A5 MOVS m16, m16 A Valid Valid For legacy mode, move word from address DS:(E)SI to ES:(E)DI. For 64-bit mode move word at address (R|E)SI to (R|E)DI.
	// A5 MOVS m32, m32 A Valid Valid For legacy mode, move dword from address DS:(E)SI to ES:(E)DI. For 64-bit mode move dword from address (R|E)SI to (R|E)DI.
	// REX.W + A5 MOVS m64, m64 A Valid N.E. Move qword from address (R|E)SI to (R|E)DI.
	{ NULL, 0x0001, 0x00C40000, { 0xA5, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_SI, FCML_EOS_EOSA,FCML_SEG_ENCODE_REGISTER( FCML_REG_DS, FCML_SEG_ALLOW_OVERRIDE ) ),
			FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_EOSA,FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ),
			FCML_NA, FCML_NA, FCML_NA } }
	// A4 MOVSB A Valid Valid For legacy mode, Move byte from address DS:(E)SI to ES:(E)DI. For 64-bit mode move byte from address (R|E)SI to (R|E)DI.
	// A5 MOVSW A Valid Valid For legacy mode, move word from address DS:(E)SI to ES:(E)DI. For 64-bit mode move word at address (R|E)SI to (R|E)DI.
	// A5 MOVSD A Valid Valid For legacy mode, move dword from address DS:(E)SI to ES:(E)DI. For 64-bit mode move dword from address (R|E)SI to (R|E)DI. REX.W + A5 MOVSQ A Valid N.E. Move qword from address
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVSD[] = {
	// F2 0F 10 /r MOVSD xmm1, xmm2/m64 A Valid Valid Move scalar doubleprecision floating-point value from xmm2/m64 to xmm1 register.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0x10, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// F2 0F 11 /r MOVSD xmm2/m64, xmm1 B Valid Valid Move scalar doubleprecision floating-point value from xmm1 register to xmm2/m64.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0x11, 0x00 }, { FCML_OP_MODRM_RM_XMM_64_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F 10 /r VMOVSD xmm1,xmm2,xmm3
	{ "vmovsd", 0x20C0, 0x00DA8000, { 0x0F, 0x10, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F 11 /r VMOVSD xmm1,xmm2,xmm3
	{ "vmovsd", 0x20C0, 0x00DA8000, { 0x0F, 0x11, 0x00 }, { FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ) | FCML_OA_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA } },
	// VEX.128.F2.0F 10 /r VMOVSD xmm1,m64
	{ "vmovsd", 0x21C0, 0x80D88000, { 0x0F, 0x10, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_M_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F2.0F 11 /r VMOVSD m64,xmm1
	{ "vmovsd", 0x21C0, 0x80D88000, { 0x0F, 0x11, 0x00 }, { FCML_OP_MODRM_M_64_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVSHDUP[] = {
	// F3 0F 16 /r MOVSHDUP xmm1, xmm2/m128 A Valid Valid Move two single-precisionfloating-point values from the higher 32-bit operand of each qword in xmm2/m128 to xmm1 and duplicate each 32-bit operand to the lower 32-bits of each qword.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x16, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F 16 /r VMOVSHDUP xmm1,xmm2/m128
	// VEX.256.F3.0F 16 /r VMOVSHDUP ymm1,ymm2/m256
	{ "vmovshdup", 0x4180, 0x00D88000, { 0x0F, 0x16, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVSLDUP[] = {
	// F3 0F 12 /r MOVSLDUP xmm1, xmm2/m128 A Valid Valid Move two single-precision floating-point values from the lower 32-bit operand ofeach qword in xmm2/m128 to xmm1 and duplicate each 32-bit operand to the higher 32-bits of each qword.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x12, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F 12 /r VMOVSLDUP xmm1,xmm2/m128
	// VEX.256.F3.0F 12 /r VMOVSLDUP ymm1,ymm2/m256
	{ "vmovsldup", 0x4180, 0x00D88000, { 0x0F, 0x12, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVSS[] = {
	// F3 0F 10 /r MOVSS xmm1, xmm2/m32 A Valid Valid Move scalar single-precision floating-point value from xmm2/m32 to xmm1 register.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x10, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// F3 0F 11 /r MOVSS xmm2/m32, xmm B Valid Valid Move scalar single-precision floating-point value from xmm1 register to
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x11, 0x00 }, { FCML_OP_MODRM_RM_XMM_32_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F3.0F 10 /r VMOVSS xmm1,xmm2,xmm3
	{ "vmovss", 0x40C0, 0x00DA8000, { 0x0F, 0x10, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA } },
	// VEX.NDS.128.F3.0F 11 /r VMOVSS xmm1,xmm2,xmm3
	{ "vmovss", 0x40C0, 0x00DA8000, { 0x0F, 0x11, 0x00 }, { FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ) | FCML_OA_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F 10 /r VMOVSS xmm1,m32
	{ "vmovss", 0x41C0, 0x80D88000, { 0x0F, 0x10, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F 11 /r VMOVSS m32,xmm1
	{ "vmovss", 0x41C0, 0x80D88000, { 0x0F, 0x11, 0x00 }, { FCML_OP_MODRM_M_32_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVSX[] = {
	// 0F BE /r MOVSX r16, r/m8 A Valid Valid Move byte to word with sign-extension.
	// 0F BE /r MOVSX r32, r/m8 A Valid Valid Move byte to doubleword with sign-extension.
	// REX + 0F BE /r MOVSX r64, r/m8* A Valid N.E. Move byte to quadword with sign-extension.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xBE, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA } },
	// 0F BF /r MOVSX r32, r/m16 A Valid Valid Move word to doubleword, with sign-extension.
	{ NULL, 0x0001, 0x03D88000, { 0x0F, 0xBF, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_16, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 0F BF /r MOVSX r64, r/m16 A Valid N.E. Move word to quadword with sign-extension.
	{ NULL, 0x0001, 0x04988000, { 0x0F, 0xBF, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_16, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W** + 63 /r MOVSXD r64, r/m32 A Valid N.E. Move doubleword to quadword with signextension.
	{ "movsxd", 0x0001, 0x04848000, { 0x63, 0x00, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVUPD[] = {
	// 66 0F 10 /r MOVUPD xmm1, xmm2/m128 A Valid Valid Move packed doubleprecision floating-point values from xmm2/m128 to xmm1.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x10, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 11 /r MOVUPD xmm2/m128, xmm B Valid Valid Move packed doubleprecision floating-point values from xmm1 to xmm2/m128.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x11, 0x00 }, { FCML_OP_MODRM_RM_XMM_128_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F 10 /r VMOVUPD xmm1,xmm2/m128
	// VEX.256.66.0F 10 /r VMOVUPD ymm1,ymm2/m256
	{ "vmovupd", 0x1180, 0x00D88000, { 0x0F, 0x10, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F 11 /r VMOVUPD xmm2/m128,xmm1
	// VEX.256.66.0F 11 /r VMOVUPD ymm2/m256,ymm1
	{ "vmovupd", 0x1180, 0x00D88000, { 0x0F, 0x11, 0x00 }, { FCML_OP_MODRM_RM_SIMD_L_W, FCML_OP_MODRM_R_SIMD_L, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVUPS[] = {
	// 0F 10 /r MOVUPS xmm1, xmm2/m128 A Valid Valid Move packed singleprecision floating-point values from xmm2/m128 to xmm1.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x10, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 11 /r MOVUPS xmm2/m128, xmm1 B Valid Valid Move packed singleprecision floating-point values from xmm1 to xmm2/m128.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x11, 0x00 }, { FCML_OP_MODRM_RM_XMM_128_W, FCML_OP_MODRM_R_XMM, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.0F 10 /r VMOVUPS xmm1,xmm2/m128
	// VEX.256.0F 10 /r VMOVUPS ymm1,ymm2/m256
	{ "vmovups", 0x0180, 0x00D88000, { 0x0F, 0x10, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.0F 11 /r VMOVUPS xmm2/m128,xmm1
	// VEX.256.0F 11 /r VMOVUPS ymm2/m256,ymm1
	{ "vmovups", 0x0180, 0x00D88000, { 0x0F, 0x11, 0x00 }, { FCML_OP_MODRM_RM_SIMD_L_W, FCML_OP_MODRM_R_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MOVZX[] = {
	// 0F B6 /r MOVZX r16, r/m8 A Valid Valid Move byte to word with zero-extension.
	// 0F B6 /r MOVZX r32, r/m8 A Valid Valid Move byte to doubleword, zero-extension.
	// REX.W + 0F B6 /r MOVZX r64, r/m8* A Valid N.E. Move byte to quadword, zero-extension.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xB6, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA } },
	// 0F B7 /r MOVZX r32, r/m16 A Valid Valid Move word to doubleword, zero-extension.
	{ NULL, 0x0001, 0x03D88000, { 0x0F, 0xB7, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_16, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 0F B7 /r MOVZX r64, r/m16 A Valid N.E. Move word to quadword, zero-extension.
	{ NULL, 0x0001, 0x04988000, { 0x0F, 0xB7, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_16, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MPSADBW[] = {
	// 66 0F 3A 42 /r ib MPSADBW xmm1, xmm2/m128, imm8 A Valid Valid Sums absolute 8-bit integer difference of adjacent groups of 4 byte integers in xmm1 and xmm2/m128 and writes the results in xmm1. Starting offsets within xmm1 and xmm2/m128 are determined by imm8.
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x42 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F3A 42 /r ib VMPSADBW xmm1,xmm2,xmm3/m128,imm8
	{ "vmpsadbw", 0x10C0, 0x00EC8000, { 0x0F, 0x3A, 0x42 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA } },
	// AVX2
	// VEX.NDS.256.66.0F3A.WIG 42 /r ib VMPSADBW ymm1,ymm2,ymm3/m256,imm8
	{ "vmpsadbw", 0x10A0, 0x00EC8000, { 0x0F, 0x3A, 0x42 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MUL[] = {
	// F6 /4 MUL r/m8 A Valid Valid Unsigned multiply (AX AL r/m8).
	// REX + F6 /4 MUL r/m8* A Valid N.E. Unsigned multiply (AX AL r/m8).
	{ NULL, 0x0001, 0x00C5A000, { 0xF6, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// F7 /4 MUL r/m16 A Valid Valid Unsigned multiply (DX:AX AX r/m16).
	// F7 /4 MUL r/m32 A Valid Valid Unsigned multiply (EDX:EAX EAX r/m32).
	// REX.W + F7 /4 MUL r/m64 A Valid N.E. Unsigned multiply (RDX:RAX RAX r/m64.
	{ NULL, 0x0001, 0x00C5A000, { 0xF7, 0x00, 0x00 }, { FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MULPD[] = {
	// 66 0F 59 /r MULPD xmm1, xmm2/m128 A Valid Valid Multiply packed doubleprecision floating-point values in xmm2/m128 by xmm1.
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x59, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F 59 /r VMULPD xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F 59 /r VMULPD ymm1,ymm2,ymm3/m256
	{ "vmulpd", 0x1080, 0x00D88000, { 0x0F, 0x59, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MULPS[] = {
	// 0F 59 /r MULPS xmm1, xmm2/m128 A Valid Valid Multiply packed singleprecision floating-point values in xmm2/mem by xmm1.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x59, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F 59 /r VMULPS xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.0F 59 /r VMULPS ymm1,ymm2,ymm3/m256
	{ "vmulps", 0x0080, 0x00D88000, { 0x0F, 0x59, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MULSD[] = {
	// F2 0F 59 /r MULSD xmm1, xmm2/m64 A Valid Valid Multiply the low doubleprecision floating-point value in xmm2/mem64 by low double-precision floating-point value in xmm1.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0x59, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F2.0F 59 /r VMULSD xmm1,xmm2,xmm3/m64
	{ "vmulsd", 0x20C0, 0x00D88000, { 0x0F, 0x59, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MULSS[] = {
	// F3 0F 59 /r MULSS xmm1, xmm2/m32 A Valid Valid Multiply the low singleprecision floating-point value in xmm2/mem by the low single-precision floating-point value in xmm1.
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x59, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.F3.0F 59 /r VMULSS xmm1,xmm2,xmm3/m32
	{ "vmulss", 0x40C0, 0x00D88000, { 0x0F, 0x59, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_32, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MWAIT[] = {
	// 0F 01 C9 MWAIT A Valid Valid A hint that allow the processor to stop instruction execution and enter an implementationdependent optimized state until occurrence of a class of events.
	{ NULL, 0x0001, 0x00EC8000, { 0x0F, 0x01, 0xC9 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_NEG[] = {
	// F6 /3 NEG r/m8 M Valid Valid Two's complement negate r/m8.
	// REX + F6 /3 NEG r/m8* M Valid N.E. Two's complement negate r/m8.
	{ NULL, 0x0001, 0x00C59800, { 0xF6, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// F7 /3 NEG r/m16 M Valid Valid Two's complement negate r/m16.
	// F7 /3 NEG r/m32 M Valid Valid Two's complement negate r/m32.
	// REX.W + F7 /3 NEG r/m64 M Valid N.E. Two's complement negate r/m64.
	{ NULL, 0x0001, 0x00C59800, { 0xF7, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_NOP[] = {
	// 90 NOP NP Valid Valid One byte no-operation instruction.
	{ NULL, 0x0001, 0x00C40000, { 0x90, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 1F /0 NOP r/m16 M Valid Valid Multi-byte no-operation instruction.
	// 0F 1F /0 NOP r/m32 M Valid Valid Multi-byte no-operation instruction.
	{ NULL, 0x0001, 0x00D98000, { 0x0F, 0x1F, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_NOT[] = {
	// F6 /2 NOT r/m8 M Valid Valid Reverse each bit of r/m8.
	// REX + F6 /2 NOT r/m8* M Valid N.E. Reverse each bit of r/m8.
	{ NULL, 0x0001, 0x00C59000, { 0xF6, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// F7 /2 NOT r/m16 M Valid Valid Reverse each bit of r/m16.
	// F7 /2 NOT r/m32 M Valid Valid Reverse each bit of r/m32.
	// REX.W + F7 /2 NOT r/m64 M Valid N.E. Reverse each bit of r/m64.
	{ NULL, 0x0001, 0x00C59000, { 0xF7, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_OR[] = {
	// 0C ib OR AL, imm8 I Valid Valid AL OR imm8.
	{ NULL, 0x0001, 0x00C40000, { 0x0C, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 0D iw OR AX, imm16 I Valid Valid AX OR imm16.
	// 0D id OR EAX, imm32 I Valid Valid EAX OR imm32.
	{ NULL, 0x0001, 0x03C40000, { 0x0D, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 0D id OR RAX, imm32 I Valid N.E. RAX OR imm32 (sign-extended).
	{ NULL, 0x0001, 0x04840000, { 0x0D, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 80 /1 ib OR r/m8, imm8 MI Valid Valid r/m8 OR imm8.
	// REX + 80 /1 ib OR r/m8*, imm8 MI Valid N.E. r/m8 OR imm8.
	{ NULL, 0x0001, 0x00C58800, { 0x80, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 81 /1 iw OR r/m16, imm16 MI Valid Valid r/m16 OR imm16.
	// 81 /1 id OR r/m32, imm32 MI Valid Valid r/m32 OR imm32.
	{ NULL, 0x0001, 0x03C58800, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 81 /1 id OR r/m64, imm32 MI Valid N.E. r/m64 OR imm32 (sign-extended).
	{ NULL, 0x0001, 0x04858800, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 83 /1 ib OR r/m16, imm8 MI Valid Valid r/m16 OR imm8 (sign-extended).
	// 83 /1 ib OR r/m32, imm8 MI Valid Valid r/m32 OR imm8 (sign-extended).
	{ NULL, 0x0001, 0x03C58800, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 83 /1 ib OR r/m64, imm8 MI Valid N.E. r/m64 OR imm8 (sign-extended).
	{ NULL, 0x0001, 0x04858800, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 08 /r OR r/m8, r8 MR Valid Valid r/m8 OR r8.
	// REX + 08 /r OR r/m8*, r8* MR Valid N.E. r/m8 OR r8.
	{ NULL, 0x0001, 0x00C48000, { 0x08, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_MODRM_R_8, FCML_NA, FCML_NA, FCML_NA } },
	// 09 /r OR r/m16, r16 MR Valid Valid r/m16 OR r16.
	// 09 /r OR r/m32, r32 MR Valid Valid r/m32 OR r32.
	// REX.W + 09 /r OR r/m64, r64 MR Valid N.E. r/m64 OR r64.
	{ NULL, 0x0001, 0x00C48000, { 0x09, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
	// 0A /r OR r8, r/m8 RM Valid Valid r8 OR r/m8.
	// REX + 0A /r OR r8*, r/m8* RM Valid N.E. r8 OR r/m8.
	{ NULL, 0x0001, 0x00C48000, { 0x0A, 0x00, 0x00 }, { FCML_OP_MODRM_R_8_W, FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA } },
	// 0B /r OR r16, r/m16 RM Valid Valid r16 OR r/m16.
	// 0B /r OR r32, r/m32 RM Valid Valid r32 OR r/m32.
	// REX.W + 0B /r OR r64, r/m64 RM Valid N.E. r64 OR r/m64.
	{ NULL, 0x0001, 0x00C48000, { 0x0B, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ORPD[] = {
	// 66 0F 56 /r ORPD xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0x56, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F 56 /r VORPD xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F 56 /r VORPD ymm1,ymm2,ymm3/m256
	{ "vorpd", 0x1080, 0x00D88000, { 0x0F, 0x56, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ORPS[] = {
	// 0F 56 /r ORPS xmm1, xmm2/m128
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x56, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F 56 /r VORPS xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.0F 56 /r VORPS ymm1,ymm2,ymm3/m256
	{ "vorps", 0x0080, 0x00D88000, { 0x0F, 0x56, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_OUT[] = {
	// E6 ib OUT imm8, AL I Valid Valid Output byte in AL to I/O port address imm8.
	{ NULL, 0x0001, 0x07C40000, { 0xE6, 0x00, 0x00 }, { FCML_OP_IB, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// E7 ib OUT imm8, AX I Valid Valid Output word in AX to I/O port address imm8.
	{ NULL, 0x0001, 0x01C40000, { 0xE7, 0x00, 0x00 }, { FCML_OP_IB, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_WORD), FCML_NA, FCML_NA, FCML_NA } },
	// E7 ib OUT imm8, EAX I Valid Valid Output doubleword in EAX to I/O port address imm8.
	{ NULL, 0x0001, 0x06C40000, { 0xE7, 0x00, 0x00 }, { FCML_OP_IB, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_DWORD), FCML_NA, FCML_NA, FCML_NA } },
	// EE OUT DX, AL NP Valid Valid Output byte in AL to I/O port address in DX.
	{ NULL, 0x0001, 0x07C40000, { 0xEE, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_DX, FCML_EOS_WORD ), FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// EF OUT DX, AX NP Valid Valid Output word in AX to I/O port address in DX.
	{ NULL, 0x0001, 0x01C40000, { 0xEF, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_DX, FCML_EOS_WORD ), FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_WORD ), FCML_NA, FCML_NA, FCML_NA } },
	// EF OUT DX, EAX NP Valid Valid Output doubleword in EAX to I/O port address in DX.
	{ NULL, 0x0001, 0x06C40000, { 0xEF, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_DX, FCML_EOS_WORD ), FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_DWORD ), FCML_NA, FCML_NA, FCML_NA } }
};


struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_OUTS[] = {
	// 6E OUTS DX, m8 NP Valid Valid Output byte from memory location specified in DS:(E)SI or RSI to I/O port specified in DX.
	{ NULL, 0x0001, 0x07C40000, { 0x6E, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_DX, FCML_EOS_WORD ),
			FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_BYTE, FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ), FCML_NA, FCML_NA, FCML_NA } },
	// 6F OUTS DX, m16 NP Valid Valid Output word from memory location specified in DS:(E)SI or RSI to I/O port specified in DX.
	{ NULL, 0x0001, 0x01C40000, { 0x6F, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_DX, FCML_EOS_WORD ),
			FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_WORD, FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ), FCML_NA, FCML_NA, FCML_NA } },
	// 6F OUTS DX, m32 NP Valid Valid Output doubleword from memory location specified in DS:(E)SI or RSI to I/O port specified in DX.
	{ NULL, 0x0001, 0x06C40000, { 0x6F, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_DX, FCML_EOS_WORD ),
			FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_DWORD, FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ), FCML_NA, FCML_NA, FCML_NA } }
	// TODO: W przypadku assemblera trzeba to bedzie obsluzyc.
	// 6E OUTSB NP Valid Valid Output byte from memory location specified in DS:(E)SI or RSI to I/O port specified in DX.
	// 6F OUTSW NP Valid Valid Output word from memory location specified in DS:(E)SI or RSI to I/O port specified in DX.
	// 6F OUTSD NP Valid Valid Output doubleword from memory location specified in DS:(E)SI or RSI to I/O port specified in DX.
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PABS[] = {
	// 0F 38 1C /r1 PABSB mm1,mm2/m64
	{ "pabsb", 0x0001, 0x00EC8000, { 0x0F, 0x38, 0x1C }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 38 1D /r1 PABSW mm1,mm2/m64
	{ "pabsw", 0x0001, 0x00EC8000, { 0x0F, 0x38, 0x1D }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 38 1E /r1 PABSD mm1,mm2/m64
	{ "pabsd", 0x0001, 0x00EC8000, { 0x0F, 0x38, 0x1E }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 1C /r PABSB xmm1,xmm2/m128
	{ "pabsb", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x1C }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 1D /r PABSW xmm1,xmm2/m128
	{ "pabsw", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x1D }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 1E /r PABSD xmm1,xmm2/m128
	{ "pabsd", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x1E }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38 1C /r VPABSB xmm1,xmm2/m128
	{ "vpabsb", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x1C }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38 1D /r VPABSW xmm1,xmm2/m128
	{ "vpabsw", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x1D }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38 1E /r VPABSD xmm1,xmm2/m128
	{ "vpabsd", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x1E }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.WIG 1C /r VPABSB ymm1, ymm2/m256
	{ "vpabsb", 0x11A0, 0x00EC8000, { 0x0F, 0x38, 0x1C }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.WIG 1D /r VPABSW ymm1, ymm2/m256
	{ "vpabsw", 0x11A0, 0x00EC8000, { 0x0F, 0x38, 0x1D }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.WIG 1E /r VPABSD ymm1, ymm2/m256
	{ "vpabsd", 0x11A0, 0x00EC8000, { 0x0F, 0x38, 0x1E }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA, FCML_NA } }
};



struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PACKSS[] = {
	// 0F 63 /r1 PACKSSWB mm1,mm2/m64
	{ "packsswb", 0x0001, 0x00D88000, { 0x0F, 0x63, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 6B /r1 PACKSSDW mm1,mm2/m64
	{ "packssdw", 0x0001, 0x00D88000, { 0x0F, 0x6B, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 63 /r PACKSSWB xmm1,xmm2/m128
	{ "packsswb", 0x1001, 0x00D88000, { 0x0F, 0x63, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 6B /r PACKSSDW xmm1,xmm2/m128
	{ "packssdw", 0x1001, 0x00D88000, { 0x0F, 0x6B, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 63 /r VPACKSSWB xmm1,xmm2,xmm3/m128
	{ "vpacksswb", 0x10C0, 0x00D88000, { 0x0F, 0x63, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 6B /r VPACKSSDW xmm1,xmm2,xmm3/m128
	{ "vpackssdw", 0x10C0, 0x00D88000, { 0x0F, 0x6B, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 63 /r VPACKSSWB ymm1,ymm2,ymm3/m256
	{ "vpacksswb", 0x10A0, 0x00D88000, { 0x0F, 0x63, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 6B /r VPACKSSDW ymm1,ymm2,ymm3/m256
	{ "vpackssdw", 0x10A0, 0x00D88000, { 0x0F, 0x6B, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }

};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PACKUSD[] = {
	// 66 0F 38 2B /r PACKUSDW xmm1,xmm2/m128
	{ "packusdw", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x2B }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 2B /r VPACKUSDW xmm1,xmm2,xmm3/m128
	{ "vpackusdw", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x2B }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 2B /r VPACKUSDW ymm1,ymm2,ymm3/m256
	{ "vpackusdw", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x2B }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PACKUSW[] = {
	// 0F 67 /r1 PACKUSWB mm,mm/m64
	{ "packuswb", 0x0001, 0x00D88000, { 0x0F, 0x67, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 67 /r PACKUSWB xmm1,xmm2/m128
	{ "packuswb", 0x1001, 0x00D88000, { 0x0F, 0x67, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 67 /r VPACKUSWB xmm1,xmm2,xmm3/m128
	{ "vpackuswb", 0x10C0, 0x00D88000, { 0x0F, 0x67, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 67 /r VPACKUSWB ymm1,ymm2,ymm3/m256
	{ "vpackuswb", 0x10A0, 0x00D88000, { 0x0F, 0x67, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PADD[] = {
	// 0F FC /r1 PADDB mm,mm/m64
	{ "paddb", 0x0001, 0x00D88000, { 0x0F, 0xFC, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F FD /r1 PADDW mm,mm/m64
	{ "paddw", 0x0001, 0x00D88000, { 0x0F, 0xFD, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F FE /r1 PADDD mm,mm/m64
	{ "paddd", 0x0001, 0x00D88000, { 0x0F, 0xFE, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F FC /r PADDB xmm1,xmm2/m128
	{ "paddb", 0x1001, 0x00D88000, { 0x0F, 0xFC, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F FD /r PADDW xmm1,xmm2/m128
	{ "paddw", 0x1001, 0x00D88000, { 0x0F, 0xFD, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F FE /r PADDD xmm1,xmm2/m128
	{ "paddd", 0x1001, 0x00D88000, { 0x0F, 0xFE, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG FC /r VPADDB xmm1,xmm2,xmm3/m128
	{ "vpaddb", 0x10C0, 0x00D88000, { 0x0F, 0xFC, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG FD /r VPADDW xmm1,xmm2,xmm3/m128
	{ "vpaddw", 0x10C0, 0x00D88000, { 0x0F, 0xFD, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG FE /r VPADDD xmm1,xmm2,xmm3/m128
	{ "vpaddd", 0x10C0, 0x00D88000, { 0x0F, 0xFE, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG FC /r VPADDB ymm1,ymm2,ymm3/m256
	{ "vpaddb", 0x10A0, 0x00D88000, { 0x0F, 0xFC, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG FD /r VPADDW ymm1,ymm2,ymm3/m256
	{ "vpaddw", 0x10A0, 0x00D88000, { 0x0F, 0xFD, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG FE /r VPADDD ymm1,ymm2,ymm3/m256
	{ "vpaddd", 0x10A0, 0x00D88000, { 0x0F, 0xFE, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG D4 /r VPADDQ ymm1,ymm2,ymm3/m256
	{ "vpaddq", 0x10A0, 0x00D88000, { 0x0F, 0xD4, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PADDS[] = {
	// 0F EC /r1 PADDSB mm,mm/m64
	{ "paddsb", 0x0001, 0x00D88000, { 0x0F, 0xEC, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F ED /r1 PADDSW mm,mm/m64
	{ "paddsw", 0x0001, 0x00D88000, { 0x0F, 0xED, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F EC /r PADDSB xmm1,xmm2/m128
	{ "paddsb", 0x1001, 0x00D88000, { 0x0F, 0xEC, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F ED /r PADDSW xmm1,xmm2/m128
	{ "paddsw", 0x1001, 0x00D88000, { 0x0F, 0xED, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG EC /r VPADDSB xmm1,xmm2,xmm3/m128
	{ "vpaddsb", 0x10C0, 0x00D88000, { 0x0F, 0xEC, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG ED /r VPADDSW xmm1,xmm2,xmm3/m128
	{ "vpaddsw", 0x10C0, 0x00D88000, { 0x0F, 0xED, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG EC /r VPADDSB ymm1,ymm2,ymm3/m256
	{ "vpaddsb", 0x10A0, 0x00D88000, { 0x0F, 0xEC, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG ED /r VPADDSW ymm1,ymm2,ymm3/m256
	{ "vpaddsw", 0x10A0, 0x00D88000, { 0x0F, 0xED, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PADDUS[] = {
	// 0F DC /r1 PADDUSB mm,mm/m64
	{ "paddusb", 0x0001, 0x00D88000, { 0x0F, 0xDC, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F DD /r1 PADDUSW mm,mm/m64
	{ "paddusw", 0x0001, 0x00D88000, { 0x0F, 0xDD, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F DC /r PADDUSB xmm1,xmm2/m128
	{ "paddusb", 0x1001, 0x00D88000, { 0x0F, 0xDC, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F DD /r PADDUSW xmm1,xmm2/m128
	{ "paddusw", 0x1001, 0x00D88000, { 0x0F, 0xDD, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.660F.WIG DC /r VPADDUSB xmm1,xmm2,xmm3/m128
	{ "vpaddusb", 0x10C0, 0x00D88000, { 0x0F, 0xDC, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG DD /r VPADDUSW xmm1,xmm2,xmm3/m128
	{ "vpaddusw", 0x10C0, 0x00D88000, { 0x0F, 0xDD, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG DC /r VPADDUSB ymm1,ymm2,ymm3/m256
	{ "vpaddusb", 0x10A0, 0x00D88000, { 0x0F, 0xDC, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG DD /r VPADDUSW ymm1,ymm2,ymm3/m256
	{ "vpaddusw", 0x10A0, 0x00D88000, { 0x0F, 0xDD, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PADDQ[] = {
	// 0F D4 /r1 PADDQ mm1,mm2/m64
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0xD4, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F D4 /r PADDQ xmm1,xmm2/m128
	{ NULL, 0x1000, 0x00D88000, { 0x0F, 0xD4, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG D4 /r VPADDQ xmm1,xmm2,xmm3/m128
	{ "vpaddq", 0x10C0, 0x00D88000, { 0x0F, 0xD4, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PALIGNR[] = {
	// 0F 3A 0F PALIGNR mm1,mm2/m64,imm8
	{ NULL, 0x0001, 0x00EC8000, { 0x0F, 0x3A, 0x00F }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_OP_IB, FCML_NA, FCML_NA } },
	// 66 0F 3A 0F PALIGNR xmm1,xmm2/m128,imm8
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x00F }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F3A.WIG 0F /r ib VPALIGNR xmm1,xmm2,xmm3/m128,imm8
	{ "vpalignr", 0x10C0, 0x00EC8000, { 0x0F, 0x3A, 0x0F }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA } },
	// VEX.NDS.256.66.0F3A.WIG 0F /r ib VPALIGNR ymm1,ymm2,ymm3/m256,imm8
	{ "vpalignr", 0x10A0, 0x00EC8000, { 0x0F, 0x3A, 0x0F }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PAND[] = {
		// 0F DB /r PAND mm,mm/m64
		{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xDB, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
		// 66 0F DB /r PAND xmm1,xmm2/m128
		{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xDB, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
		// VEX.NDS.128.66.0F.WIG DB /r VPAND xmm1,xmm2,xmm3/m128
		{ "vpand", 0x10C0, 0x00D88000, { 0x0F, 0xDB, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
		// VEX.NDS.256.66.0F.WIG DB /r VPAND ymm1,ymm2,ymm3/m256
		{ "vpand", 0x10A0, 0x00D88000, { 0x0F, 0xDB, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PANDN[] = {
		// 0F DF /r PANDN mm,mm/m64
		{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xDF, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
		// 66 0F DF /r PANDN xmm1,xmm2/m128
		{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xDF, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
		// VEX.NDS.128.66.0F.WIG DF /r VPANDN xmm1,xmm2,xmm3/m128
		{ "vpandn", 0x10C0, 0x00D88000, { 0x0F, 0xDF, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
		// VEX.NDS.256.66.0F.WIG DF /r VPANDN ymm1,ymm2,ymm3/m256
		{ "vpandn", 0x10A0, 0x00D88000, { 0x0F, 0xDF, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PAUSE[] = {
	// F3 90 PAUSE
	{ NULL, 0x4001, 0x00C40000, { 0x90, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PAVG[] = {
	// 0F E0 /r1 PAVGB mm1,mm2/m64
	{ "pavgb", 0x0001, 0x00D88000, { 0x0F, 0xE0, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F E3 /r1 PAVGW mm1,mm2/m64
	{ "pavgw", 0x0001, 0x00D88000, { 0x0F, 0xE3, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F E0, /r PAVGB xmm1,xmm2/m128
	{ "pavgb", 0x1001, 0x00D88000, { 0x0F, 0xE0, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F E3 /r PAVGW xmm1,xmm2/m128
	{ "pavgw", 0x1001, 0x00D88000, { 0x0F, 0xE3, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG E0 /r VPAVGB xmm1,xmm2,xmm3/m128
	{ "vpavgb", 0x10C0, 0x00D88000, { 0x0F, 0xE0, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG E3 /r VPAVGW xmm1,xmm2,xmm3/m128
	{ "vpavgw", 0x10C0, 0x00D88000, { 0x0F, 0xE3, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG E0 /r VPAVGB ymm1,ymm2,ymm3/m256
	{ "vpavgb", 0x10A0, 0x00D88000, { 0x0F, 0xE0, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG E3 /r VPAVGW ymm1,ymm2,ymm3/m256
	{ "vpavgw", 0x10A0, 0x00D88000, { 0x0F, 0xE3, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PBLENDVB[] = {
	// 66 0F 38 10 /r PBLENDVB xmm1,xmm2/m128,<XMM0>
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x10 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_EXPLICIT_REG( FCML_REG_SIMD, FCML_REG_XMM0, FCML_EOS_OWORD ), FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F3A 4C /r /is4 VPBLENDVB xmm1,xmm2,xmm3/m128,xmm4
	{ "vpblendvb", 0x10C0, 0x00EC8000, { 0x0F, 0x3A, 0x4C }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VEX.NDS.256.66.0F3A.W0 4C /r /is4 VPBLENDVB ymm1,ymm2,ymm3/m256,ymm4
	{ "vpblendvb", 0x10A0, 0x00EC8000, { 0x0F, 0x3A, 0x4C }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PBLENDW[] = {
	// 66 0F 3A 0E /r ib PBLENDW xmm1,xmm2/m128,imm8
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x0E }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F3A 0E /r ib VPBLENDW xmm1,xmm2,xmm3/m128,imm8
	{ "vpblendw", 0x10C0, 0x00EC8000, { 0x0F, 0x3A, 0x0E }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA } },
	// VEX.NDS.256.66.0F3A.WIG 0E /r ib VPBLENDW ymm1,ymm2,ymm3/m256,imm8
	{ "vpblendw", 0x10A0, 0x00EC8000, { 0x0F, 0x3A, 0x0E }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPBLENDD[] = {
	// VEX.NDS.128.66.0F3A.W0 02 /r ib VPBLENDD xmm1,xmm2,xmm3/m128,imm8
	// VEX.NDS.256.66.0F3A.W0 02 /r ib VPBLENDD ymm1,ymm2,ymm3/m256,imm8
	{ NULL, 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x02 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PCLMULQDQ[] = {
	// 66 0F 3A 44 /r ib PCLMULQDQ xmm1,xmm2/m128,imm8
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x44 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F3A 44 /r ib VPCLMULQDQ xmm1,xmm2,xmm3/m128,imm8
	{ "vpclmulqdq", 0x10C0, 0x00EC8000, { 0x0F, 0x3A, 0x44 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PCMPEQ[] = {
	// 0F 74 /r1 PCMPEQB mm,mm/m64
	{ "pcmpeqb", 0x0001, 0x00D88000, { 0x0F, 0x74, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 75 /r1 PCMPEQW mm,mm/m64
	{ "pcmpeqw", 0x0001, 0x00D88000, { 0x0F, 0x75, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 76 /r1 PCMPEQD mm,mm/m64
	{ "pcmpeqd", 0x0001, 0x00D88000, { 0x0F, 0x76, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 74 /r PCMPEQB xmm1,xmm2/m128
	{ "pcmpeqb", 0x1001, 0x00D88000, { 0x0F, 0x74, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 75 /r PCMPEQW xmm1,xmm2/m128
	{ "pcmpeqw", 0x1001, 0x00D88000, { 0x0F, 0x75, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 76 /r PCMPEQD xmm1,xmm2/m128
	{ "pcmpeqd", 0x1001, 0x00D88000, { 0x0F, 0x76, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 74 /r VPCMPEQB xmm1,xmm2,xmm3/m128
	{ "vpcmpeqb", 0x10C0, 0x00D88000, { 0x0F, 0x74, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 75 /r VPCMPEQW xmm1,xmm2,xmm3/m128
	{ "vpcmpeqw", 0x10C0, 0x00D88000, { 0x0F, 0x75, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 76 /r VPCMPEQD xmm1,xmm2,xmm3/m128
	{ "vpcmpeqd", 0x10C0, 0x00D88000, { 0x0F, 0x76, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 74 /r VPCMPEQB ymm1,ymm2,ymm3/m256
	{ "vpcmpeqb", 0x10A0, 0x00D88000, { 0x0F, 0x74, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 75 /r VPCMPEQW ymm1,ymm2,ymm3/m256
	{ "vpcmpeqw", 0x10A0, 0x00D88000, { 0x0F, 0x75, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 76 /r VPCMPEQD ymm1,ymm2,ymm3/m256
	{ "vpcmpeqd", 0x10A0, 0x00D88000, { 0x0F, 0x76, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PCMPEQQ[] = {
	// 66 0F 38 29 /r PCMPEQQ xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x29 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 29 /r VPCMPEQQ xmm1,xmm2,xmm3/m128
	{ "vpcmpeqq", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x29 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 29 /r VPCMPEQQ ymm1,ymm2,ymm3/m256
	{ "vpcmpeqq", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x29 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PCMPESTRI[] = {
	// 66 0F 3A 61 /r imm8 PCMPESTRI xmm1,xmm2/m128,imm8
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x61 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A.WIG 61 /r ib VPCMPESTRI xmm1,xmm2/m128,imm8
	{ "vpcmpestri", 0x11C0, 0x00EC8000, { 0x0F, 0x3A, 0x61 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PCMPESTRM[] = {
	// 66 0F 3A 60 /r imm8 PCMPESTRM xmm1,xmm2/m128,imm8
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x60 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A.WIG 60 /r ib VPCMPESTRM xmm1,xmm2/m128,imm8
	{ "vpcmpestrm", 0x11C0, 0x00EC8000, { 0x0F, 0x3A, 0x60 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PCMPGT[] = {
	// 0F 64 /r1 PCMPGTB mm,mm/m64
	// 0F 65 /r1 PCMPGTW mm,mm/m64
	// 0F 66 /r1 PCMPGTD mm,mm/m64
	{ "pcmpgtb", 0x0001, 0x00D88000, { 0x0F, 0x64, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	{ "pcmpgtw", 0x0001, 0x00D88000, { 0x0F, 0x65, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	{ "pcmpgtd", 0x0001, 0x00D88000, { 0x0F, 0x66, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 64 /r PCMPGTB xmm1,xmm2/m128
	// 66 0F 65 /r PCMPGTW xmm1,xmm2/m128
	// 66 0F 66 /r PCMPGTD xmm1,xmm2/m128
	{ "pcmpgtb", 0x1001, 0x00D88000, { 0x0F, 0x64, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	{ "pcmpgtw", 0x1001, 0x00D88000, { 0x0F, 0x65, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	{ "pcmpgtd", 0x1001, 0x00D88000, { 0x0F, 0x66, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 64 /r VPCMPGTB xmm1,xmm2,xmm3/m128
	// VEX.NDS.128.66.0F.WIG 65 /r VPCMPGTW xmm1,xmm2,xmm3/m128
	// VEX.NDS.128.66.0F.WIG 66 /r VPCMPGTD xmm1,xmm2,xmm3/m128
	{ "vpcmpgtb", 0x10C0, 0x00D88000, { 0x0F, 0x64, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	{ "vpcmpgtw", 0x10C0, 0x00D88000, { 0x0F, 0x65, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	{ "vpcmpgtd", 0x10C0, 0x00D88000, { 0x0F, 0x66, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 64 /r VPCMPGTB ymm1,ymm2,ymm3/m256
	// VEX.NDS.256.66.0F.WIG 65 /r VPCMPGTW ymm1,ymm2,ymm3/m256
	// VEX.NDS.256.66.0F.WIG 66 /r VPCMPGTD ymm1,ymm2,ymm3/m256
	{ "vpcmpgtb", 0x10A0, 0x00D88000, { 0x0F, 0x64, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	{ "vpcmpgtw", 0x10A0, 0x00D88000, { 0x0F, 0x65, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	{ "vpcmpgtd", 0x10A0, 0x00D88000, { 0x0F, 0x66, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PCMPGTQ[] = {
	// 66 0F 38 37 /r PCMPGTQ xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x37 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 37 /r VPCMPGTQ xmm1,xmm2,xmm3/m128
	{ "vpcmpgtq", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x37 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 37 /r VPCMPGTQ ymm1,ymm2,ymm3/m256
	{ "vpcmpgtq", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x37 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PCMPISTRI[] = {
	// 66 0F 3A 63 /r imm8 PCMPISTRI xmm1,xmm2/m128,imm8
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x63 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A.WIG 63 /r ib VPCMPISTRI xmm1,xmm2/m128,imm8
	{ "vpcmpistri", 0x11C0, 0x00EC8000, { 0x0F, 0x3A, 0x63 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PCMPISTRM[] = {
	// 66 0F 3A 62 /r imm8 PCMPISTRM xmm1,xmm2/m128,imm8
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x62 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A.WIG 62 /r ib VPCMPISTRM xmm1,xmm2/m128,imm8
	{ "vpcmpistrm", 0x11C0, 0x00EC8000, { 0x0F, 0x3A, 0x62 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PEXTR[] = {
	// 66 0F 3A 14 /r ib PEXTRB reg/m8,xmm2,imm8
	{ "pextrb", 0x1001, 0x40EC8000, { 0x0F, 0x3A, 0x14 }, { FCML_OP_RM(FCML_REG_GPR, FCML_EOS_EOSA, FCML_EOS_BYTE, FCML_RMF_RM ), FCML_OP_MODRM_R_XMM, FCML_OP_IB, FCML_NA, FCML_NA } },
	// 66 0F 3A 16 /r ib PEXTRD r/m32, xmm2, imm8
	{ "pextrd", 0x1001, 0x40EC8000, { 0x0F, 0x3A, 0x16 }, { FCML_OP_RM(FCML_REG_GPR, FCML_EOS_EOSA, FCML_EOS_DWORD, FCML_RMF_RM ), FCML_OP_MODRM_R_XMM, FCML_OP_IB, FCML_NA, FCML_NA } },
	// 66 REX.W 0F 3A 16 /r ib PEXTRQ r/m64, xmm2, imm8
	{ "pextrq", 0x1009, 0x04AC8000, { 0x0F, 0x3A, 0x16 }, { FCML_OP_RM(FCML_REG_GPR, FCML_EOS_QWORD, FCML_EOS_QWORD, FCML_RMF_RM ), FCML_OP_MODRM_R_XMM, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A.W0 14 /r ib VPEXTRB reg/m8, xmm2, imm8
	{ "vpextrb", 0x13C0, 0x40EC8000, { 0x0F, 0x3A, 0x14 }, { FCML_OP_RM(FCML_REG_GPR, FCML_EOS_EOSA, FCML_EOS_BYTE, FCML_RMF_RM ), FCML_OP_MODRM_R_XMM, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A.W0 16 /r ib VPEXTRD r32/m32, xmm2, imm8
	{ "vpextrd", 0x13D0, 0x40EC8000, { 0x0F, 0x3A, 0x16 }, { FCML_OP_RM(FCML_REG_GPR, FCML_EOS_EOSA, FCML_EOS_DWORD, FCML_RMF_RM ), FCML_OP_MODRM_R_XMM, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A.W1 16 /r ib VPEXTRQ r64/m64, xmm2, imm8
	{ "vpextrq", 0x11C8, 0x04AC8000, { 0x0F, 0x3A, 0x16 }, { FCML_OP_RM(FCML_REG_GPR, FCML_EOS_QWORD, FCML_EOS_QWORD, FCML_RMF_RM ), FCML_OP_MODRM_R_XMM, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PEXTRW[] = {
	// 0F C5 /r ib PEXTRW reg,mm,imm8
	{ NULL, 0x0001, 0x40DA8000, { 0x0F, 0xC5, 0x00 }, { FCML_OP_R(FCML_REG_GPR, FCML_EOS_EOSA), FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// 66 0F C5 /r ib PEXTRW reg,xmm,imm8
	{ NULL, 0x1001, 0x40DA8000, { 0x0F, 0xC5, 0x00 }, { FCML_OP_R(FCML_REG_GPR, FCML_EOS_EOSA), FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// 66 0F 3A 15 /r ib PEXTRW reg/m16,xmm,imm8
	{ NULL, 0x1001, 0x40EC8000, { 0x0F, 0x3A, 0x15 }, { FCML_OP_RM(FCML_REG_GPR, FCML_EOS_EOSA, FCML_EOS_WORD, FCML_RMF_RM ), FCML_OP_R(FCML_REG_SIMD, FCML_EOS_OWORD), FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F.W0 C5 /r ib VPEXTRW reg,xmm1,imm8
	{ "vpextrw", 0x13C1, 0x40DA8000, { 0x0F, 0xC5, 0x00 }, { FCML_OP_R(FCML_REG_GPR, FCML_EOS_EOSA), FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A.W0 15 /r ib VPEXTRW reg/m16,xmm2,imm8
	{ "vpextrw", 0x13C1, 0x40EC8000, { 0x0F, 0x3A, 0x15 }, { FCML_OP_RM(FCML_REG_GPR, FCML_EOS_EOSA, FCML_EOS_WORD, FCML_RMF_RM ), FCML_OP_R(FCML_REG_SIMD, FCML_EOS_OWORD), FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PHADD[] = {
	// 0F 38 01 /r PHADDW mm1,mm2/m64
	{ "phaddw", 0x0001, 0x00EC8000, { 0x0F, 0x38, 0x01 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 38 02 /r PHADDD mm1,mm2/m64
	{ "phaddd", 0x0001, 0x00EC8000, { 0x0F, 0x38, 0x02 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 01 /r PHADDW xmm1,xmm2/m128
	{ "phaddw", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x01 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 02 /r PHADDD xmm1,xmm2/m128
	{ "phaddd", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x02 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 01 /r VPHADDW xmm1,xmm2,xmm3/m128
	{ "vphaddw", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x01 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 02 /r VPHADDD xmm1,xmm2,xmm3/m128
	{ "vphaddd", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x02 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 01 /r VPHADDW ymm1,ymm2,ymm3/m256
	{ "vphaddw", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x01 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 02 /r VPHADDD ymm1,ymm2,ymm3/m256
	{ "vphaddd", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x02 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PHADDSW[] = {
	// 0F 38 03 /r PHADDSW mm1,mm2/m64
	{ NULL, 0x0001, 0x00EC8000, { 0x0F, 0x38, 0x03 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 03 /r PHADDSW xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x03 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 03 /r VPHADDSW xmm1,xmm2,xmm3/m128
	{ "vphaddsw", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x03 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 03 /r VPHADDSW ymm1,ymm2,ymm3/m256
	{ "vphaddsw", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x03 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PHMINPOSUW[] = {
	// 66 0F 38 41 /r PHMINPOSUW xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x41 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 41 /r VPHMINPOSUW xmm1,xmm2/m128
	{ "vphminposuw", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x41 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PHSUB[] = {
	// 0F 38 05 /r1 PHSUBW mm1,mm2/m64
	{ "phsubw", 0x0001, 0x00EC8000, { 0x0F, 0x38, 0x05 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 38 06 /r PHSUBD mm1,mm2/m64
	{ "phsubd", 0x0001, 0x00EC8000, { 0x0F, 0x38, 0x06 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 05 /r PHSUBW xmm1,xmm2/m128
	{ "phsubw", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x05 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 06 /r PHSUBD xmm1,xmm2/m128
	{ "phsubd", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x06 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 05 /r VPHSUBW xmm1,xmm2,xmm3/m128
	{ "vphsubw", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x05 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 06 /r VPHSUBD xmm1,xmm2,xmm3/m128
	{ "vphsubd", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x06 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 05 /r VPHSUBW ymm1,ymm2,ymm3/m256
	{ "vphsubw", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x05 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 06 /r VPHSUBD ymm1,ymm2,ymm3/m256
	{ "vphsubd", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x06 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PHSUBSW[] = {
	// 0F 38 07 /r PHSUBSW mm1,mm2/m64
	{ NULL, 0x0001, 0x00EC8000, { 0x0F, 0x38, 0x07 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 07 /r PHSUBSW xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x07 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 07 /r VPHSUBSW xmm1,xmm2,xmm3/m128
	{ "vphsubsw", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x07 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 07 /r VPHSUBSW ymm1,ymm2,ymm3/m256
	{ "vphsubsw", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x07 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PINSR[] = {
	// 66 0F 3A 20 /r ib PINSRB xmm1,r32/m8,imm8
	{ "pinsrb", 0x1001, 0x00EC8000, { 0x0F, 0x3A, 0x20 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_RM(FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_BYTE, FCML_RMF_RM ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// 66 0F 3A 22 /r ib PINSRD xmm1,r/m32,imm8
	{ "pinsrd", 0x1001, 0x03EC8000, { 0x0F, 0x3A, 0x22 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_32, FCML_OP_IB, FCML_NA, FCML_NA } },
	// 66 REX.W 0F 3A 22 /r ib PINSRQ xmm1,r/m64,imm8
	{ "pinsrq", 0x1009, 0x04AC8000, { 0x0F, 0x3A, 0x22 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_64, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F3A.W0 20 /r ib VPINSRB xmm1,xmm2,r32/m8,imm8
	{ "vpinsrb", 0x10C0, 0x00EC8000, { 0x0F, 0x3A, 0x20 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_RM(FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_BYTE, FCML_RMF_RM ), FCML_OP_IB, FCML_NA } },
	// VEX.NDS.128.66.0F3A.W0 22 /r ib VPINSRD xmm1,xmm2,r32/m32,imm8
	{ "vpinsrd", 0x10D0, 0x00EC8000, { 0x0F, 0x3A, 0x22 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_32, FCML_OP_IB, FCML_NA } },
	// VEX.NDS.128.66.0F3A.W1 22 /r ib VPINSRQ xmm1,xmm2,r64/m64,imm8
	{ "vpinsrq", 0x10C8, 0x00EC8000, { 0x0F, 0x3A, 0x22 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_64, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PINSRW[] = {
	// 0F C4 /r ib PINSRW mm,r32/m16,imm8
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xC4, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_RM(FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_WORD, FCML_RMF_RM ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// 66 0F C4 /r ib PINSRW xmm,r32/m16,imm8
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xC4, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_RM(FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_WORD, FCML_RMF_RM ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.W0 C4 /r ib VPINSRW xmm1,xmm2,r32/m16,imm8
	{ "vpinsrw", 0x10C0, 0x00D88000, { 0x0F, 0xC4, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_RM(FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_WORD, FCML_RMF_RM ), FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMADDUBSW[] = {
	// 0F 38 04 /r PMADDUBSW mm1,mm2/m64
	{ NULL, 0x0001, 0x00EC8000, { 0x0F, 0x38, 0x04 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 04 /r PMADDUBSW xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x04 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 04 /r VPMADDUBSW xmm1,xmm2,xmm3/m128
	{ "vpmaddubsw", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x04 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 04 /r VPMADDUBSW ymm1,ymm2,ymm3/m256
	{ "vpmaddubsw", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x04 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMADDWD[] = {
	// 0F F5 /r PMADDWD mm,mm/m64
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xF5, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F F5 /r PMADDWD xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xF5, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG F5 /r VPMADDWD xmm1,xmm2,xmm3/m128
	{ "vpmaddwd", 0x10C0, 0x00D88000, { 0x0F, 0xF5, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG F5 /r VPMADDWD ymm1,ymm2,ymm3/m256
	{ "vpmaddwd", 0x10A0, 0x00D88000, { 0x0F, 0xF5, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }

};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMAXSB[] = {
	// 66 0F 38 3C /r PMAXSB xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x3C }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 3C /r VPMAXSB xmm1,xmm2,xmm3/m128
	{ "vpmaxsb", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x3C }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 3C /r VPMAXSB ymm1,ymm2,ymm3/m256
	{ "vpmaxsb", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x3C }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMAXSD[] = {
	// 66 0F 38 3D /r PMAXSD xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x3D }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 3D /r VPMAXSD xmm1,xmm2,xmm3/m128
	{ "vpmaxsd", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x3D }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 3D /r VPMAXSD ymm1,ymm2,ymm3/m256
	{ "vpmaxsd", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x3D }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMAXSW[] = {
	// 0F EE /r PMAXSW mm1,mm2/m64
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xEE, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F EE /r PMAXSW xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xEE, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG EE /r VPMAXSW xmm1,xmm2,xmm3/m128
	{ "vpmaxsw", 0x10C0, 0x00D88000, { 0x0F, 0xEE, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG EE /r VPMAXSW ymm1,ymm2,ymm3/m256
	{ "vpmaxsw", 0x10A0, 0x00D88000, { 0x0F, 0xEE, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMAXUB[] = {
	// 0F DE /r PMAXUB mm1,mm2/m64
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xDE, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F DE /r PMAXUB xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xDE, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG DE /r VPMAXUB xmm1,xmm2,xmm3/m128
	{ "vpmaxub", 0x10C0, 0x00D88000, { 0x0F, 0xDE, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG DE /r VPMAXUB ymm1,ymm2,ymm3/m256
	{ "vpmaxub", 0x10A0, 0x00D88000, { 0x0F, 0xDE, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMAXUD[] = {
	// 66 0F 38 3F /r PMAXUD xmm1, xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x3F }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 3F /r VPMAXUD xmm1,xmm2,xmm3/m128
	{ "vpmaxud", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x3F }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 3F /r VPMAXUD ymm1,ymm2,ymm3/m256
	{ "vpmaxud", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x3F }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMAXUW[] = {
	// 66 0F 38 3E /r PMAXUW xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x3E }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 3E/r VPMAXUW xmm1,xmm2,xmm3/m128
	{ "vpmaxuw", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x3E }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 3E /r VPMAXUW ymm1,ymm2,ymm3/m256
	{ "vpmaxuw", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x3E }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMINSB[] = {
	// 66 0F 38 38 /r PMINSB xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x38 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 38 /r VPMINSB xmm1,xmm2,xmm3/m128
	{ "vpminsb", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x38 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 38 /r VPMINSB ymm1,ymm2,ymm3/m256
	{ "vpminsb", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x38 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMINSD[] = {
	// 66 0F 38 39 /r PMINSD xmm1, xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x39 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 39 /r VPMINSD xmm1, xmm2, xmm3/m128
	{ "vpminsd", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x39 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 39 /r VPMINSD ymm1,ymm2,ymm3/m256
	{ "vpminsd", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x39 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMINSW[] = {
	// 0F EA /r PMINSW mm1,mm2/m64
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xEA, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F EA /r PMINSW xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xEA, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG EA /r VPMINSW xmm1,xmm2,xmm3/m128
	{ "vpminsw", 0x10C0, 0x00D88000, { 0x0F, 0xEA, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG EA /r VPMINSW ymm1,ymm2,ymm3/m256
	{ "vpminsw", 0x10A0, 0x00D88000, { 0x0F, 0xEA, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMINUB[] = {
	// 0F DA /r PMINUB mm1,mm2/m64
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xDA, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F DA /r PMINUB xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xDA, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG DA /r VPMINUB xmm1,xmm2,xmm3/m128
	{ "vpminub", 0x10C0, 0x00D88000, { 0x0F, 0xDA, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG DA /r VPMINUB ymm1,ymm2,ymm3/m256
	{ "vpminub", 0x10A0, 0x00D88000, { 0x0F, 0xDA, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMINUW[] = {
	// 66 0F 38 3A /r PMINUW xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x3A }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 3A /r VPMINUW xmm1,xmm2,xmm3/m128
	{ "vpminuw", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x3A }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 3A /r VPMINUW ymm1,ymm2,ymm3/m256
	{ "vpminuw", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x3A }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMINUD[] = {
	// 66 0F 38 3B /r PMINUD xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x3B }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 3B /r VPMINUD xmm1,xmm2,xmm3/m128
	{ "vpminud", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x3B }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 3B /r VPMINUD ymm1,ymm2,ymm3/m256
	{ "vpminud", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x3B }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMOVMSKB[] = {
	// 0F D7 /r1 PMOVMSKB reg, mm
	{ NULL, 0x0001, 0x40DA8000, { 0x0F, 0xD7, 0x00 }, { FCML_OP_R(FCML_REG_GPR, FCML_EOS_EOSA), FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F D7 /r PMOVMSKB reg, xmm
	{ NULL, 0x1001, 0x40DA8000, { 0x0F, 0xD7, 0x00 }, { FCML_OP_R(FCML_REG_GPR, FCML_EOS_EOSA), FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F.WIG D7 /r VPMOVMSKB reg,xmm1
	{ "vpmovmskb", 0x13C0, 0x40DA8000, { 0x0F, 0xD7, 0x22 }, { FCML_OP_MODRM_R_W, FCML_OP_VEX_VVVV_REG( FCML_REG_SIMD, FCML_EOS_OWORD ), FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F.WIG D7 /r VPMOVMSKB reg,ymm1
	{ "vpmovmskb", 0x13A0, 0x40DA8000, { 0x0F, 0xD7, 0x22 }, { FCML_OP_MODRM_R_W, FCML_OP_VEX_VVVV_REG( FCML_REG_SIMD, FCML_EOS_YWORD ), FCML_NA, FCML_NA, FCML_NA } }

};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMOVSX[] = {
	// 66 0f 38 20 /r PMOVSXBW xmm1,xmm2/m64
	{ "pmovsxbw", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x20 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0f 38 21 /r PMOVSXBD xmm1,xmm2/m32
	{ "pmovsxbd", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x21 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0f 38 22 /r PMOVSXBQ xmm1,xmm2/m16
	{ "pmovsxbq", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x22 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_16, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0f 38 23 /r PMOVSXWD xmm1,xmm2/m64
	{ "pmovsxwd", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x23 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0f 38 24 /r PMOVSXWQ xmm1,xmm2/m32
	{ "pmovsxwq", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x24 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0f 38 25 /r PMOVSXDQ xmm1,xmm2/m64
	{ "pmovsxdq", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x25 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 20 /r VPMOVSXBW xmm1,xmm2/m64
	{ "vpmovsxbw", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x20 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 21 /r VPMOVSXBD xmm1,xmm2/m32
	{ "vpmovsxbd", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x21 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 22 /r VPMOVSXBQ xmm1,xmm2/m16
	{ "vpmovsxbq", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x22 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_16, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 23 /r VPMOVSXWD xmm1,xmm2/m64
	{ "vpmovsxwd", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x23 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 24 /r VPMOVSXWQ xmm1,xmm2/m32
	{ "vpmovsxwq", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x24 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 25 /r VPMOVSXDQ xmm1,xmm2/m64
	{ "vpmovsxdq", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x25 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.WIG 20 /r VPMOVSXBW ymm1,xmm2/m128
	{ "vpmovsxbw", 0x11A0, 0x00EC8000, { 0x0F, 0x38, 0x20 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.WIG 21 /r VPMOVSXBD ymm1,xmm2/m64
	{ "vpmovsxbd", 0x11A0, 0x00EC8000, { 0x0F, 0x38, 0x21 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.WIG 22 /r VPMOVSXBQ ymm1,xmm2/m32
	{ "vpmovsxbq", 0x11A0, 0x00EC8000, { 0x0F, 0x38, 0x22 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMOVZX[] = {
	// 66 0f 38 30 /r PMOVZXBW xmm1,xmm2/m64
	{ "pmovzxbw", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x30 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0f 38 31 /r PMOVZXBD xmm1,xmm2/m32
	{ "pmovzxbd", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x31 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0f 38 32 /r PMOVZXBQ xmm1,xmm2/m16
	{ "pmovzxbq", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x32 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_16, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0f 38 33 /r PMOVZXWD xmm1,xmm2/m64
	{ "pmovzxwd", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x33 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0f 38 34 /r PMOVZXWQ xmm1,xmm2/m32
	{ "pmovzxwq", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x34 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0f 38 35 /r PMOVZXDQ xmm1,xmm2/m64
	{ "pmovzxdq", 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x35 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 30 /r VPMOVZXBW xmm1,xmm2/m64
	{ "vpmovzxbw", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x30 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 31 /r VPMOVZXBD xmm1,xmm2/m32
	{ "vpmovzxbd", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x31 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 32 /r VPMOVZXBQ xmm1,xmm2/m16
	{ "vpmovzxbq", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x32 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_16, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 33 /r VPMOVZXWD xmm1,xmm2/m64
	{ "vpmovzxwd", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x33 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 34 /r VPMOVZXWQ xmm1,xmm2/m32
	{ "vpmovzxwq", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x34 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 35 /r VPMOVZXDQ xmm1,xmm2/m64
	{ "vpmovzxdq", 0x11C0, 0x00EC8000, { 0x0F, 0x38, 0x35 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.WIG 30 /r VPMOVZXBW ymm1,xmm2/m128
	{ "vpmovzxbw", 0x11A0, 0x00EC8000, { 0x0F, 0x38, 0x30 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.WIG 31 /r VPMOVZXBD ymm1,xmm2/m64
	{ "vpmovzxbd", 0x11A0, 0x00EC8000, { 0x0F, 0x38, 0x31 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.WIG 32 /r VPMOVZXBQ ymm1,xmm2/m32
	{ "vpmovzxbq", 0x11A0, 0x00EC8000, { 0x0F, 0x38, 0x32 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.WIG 33 /r VPMOVZXWD ymm1,xmm2/m128
	{ "vpmovzxwd", 0x11A0, 0x00EC8000, { 0x0F, 0x38, 0x33 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMULDQ[] = {
	// 66 0F 38 28 /r PMULDQ xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x28 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 28 /r VPMULDQ xmm1,xmm2,xmm3/m128
	{ "vpmuldq", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x28 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 28 /r VPMULDQ ymm1,ymm2,ymm3/m256
	{ "vpmuldq", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x28 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMULHRSW[] = {
	// 0F 38 0B /r PMULHRSW mm1,mm2/m64
	{ NULL, 0x0001, 0x00EC8000, { 0x0F, 0x38, 0x0B }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 0B /r PMULHRSW xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x0B }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 0B /r VPMULHRSW xmm1,xmm2,xmm3/m128
	{ "vpmulhrsw", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x0B }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 0B /r VPMULHRSW ymm1,ymm2,ymm3/m256
	{ "vpmulhrsw", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x0B }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }

};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMULHUW[] = {
	// 0F E4 /r PMULHUW mm1,mm2/m64
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xE4, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F E4 /r PMULHUW xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xE4, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG E4 /r VPMULHUW xmm1,xmm2,xmm3/m128
	{ "vpmulhuw", 0x10C0, 0x00D88000, { 0x0F, 0xE4, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG E4 /r VPMULHUW ymm1,ymm2,ymm3/m256
	{ "vpmulhuw", 0x10A0, 0x00D88000, { 0x0F, 0xE4, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMULHW[] = {
	// 0F E5 /r PMULHW mm,mm/m64
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xE5, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F E5 /r PMULHW xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xE5, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG E5 /r VPMULHW xmm1,xmm2,xmm3/m128
	{ "vpmulhw", 0x10C0, 0x00D88000, { 0x0F, 0xE5, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG E5 /r VPMULHW ymm1,ymm2,ymm3/m256
	{ "vpmulhw", 0x10A0, 0x00D88000, { 0x0F, 0xE5, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMULUDQ[] = {
	// 0F F4 /r1 PMULUDQ mm1,mm2/m64
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xF4, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F F4 /r PMULUDQ xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xF4, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG F4 /r VPMULUDQ xmm1,xmm2,xmm3/m128
	{ "vpmuludq", 0x10C0, 0x00D88000, { 0x0F, 0xF4, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG F4 /r VPMULUDQ ymm1,ymm2,ymm3/m256
	{ "vpmuludq", 0x10A0, 0x00D88000, { 0x0F, 0xF4, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMULLW[] = {
	// 0F D5 /r PMULLW mm,mm/m64
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xD5, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F D5 /r PMULLW xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xD5, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG D5 /r VPMULLW xmm1,xmm2,xmm3/m128
	{ "vpmullw", 0x10C0, 0x00D88000, { 0x0F, 0xD5, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG D5 /r VPMULLW ymm1,ymm2,ymm3/m256
	{ "vpmullw", 0x10A0, 0x00D88000, { 0x0F, 0xD5, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMULLD[] = {
	// 66 0F 38 40 /r PMULLD xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00EC8000, { 0x0F, 0x38, 0x40 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 40 /r VPMULLD xmm1,xmm2,xmm3/m128
	{ "vpmulld", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x40 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 40 /r VPMULLD ymm1,ymm2,ymm3/m256
	{ "vpmulld", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x40 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_POP[] = {
	// 8F /0 POP r/m16 M Valid Valid Pop top of stack into m16; increment stack pointer.
	// 8F /0 POP r/m32 M N.E. Valid Pop top of stack into m32; increment stack pointer.
	// 8F /0 POP r/m64 M Valid N.E. Pop top of stack into m64; increment stack pointer. Cannot encode 32-bit operand size.
	{ NULL, 0x0001, 0x00458000, { 0x8F, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x01858000, { 0x8F, 0x00, 0x00 }, { FCML_OP_MODRM_RM_16_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x06858000, { 0x8F, 0x00, 0x00 }, { FCML_OP_MODRM_RM_64_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 58+ rw POP r16 O Valid Valid Pop top of stack into r16; increment stack pointer.
	// 58+ rd POP r32 O N.E. Valid Pop top of stack into r32; increment stack pointer.
	// 58+ rd POP r64 O Valid N.E. Pop top of stack into r64; increment stack pointer. Cannot encode 32-bit operand size.
	{ NULL, 0x0001, 0x00440000, { 0x58, 0x00, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_EOSA), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x01840000, { 0x58, 0x00, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_WORD ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x06840000, { 0x58, 0x00, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_QWORD ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 1F POP DS NP Invalid Valid Pop top of stack into DS; increment stack pointer.
	// 07 POP ES NP Invalid Valid Pop top of stack into ES; increment stack pointer.
	// 17 POP SS NP Invalid Valid Pop top of stack into SS; increment stack pointer.
	{ NULL, 0x0001, 0x00440000, { 0x1F, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_SEG, FCML_REG_DS, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x00440000, { 0x07, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_SEG, FCML_REG_ES, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x00440000, { 0x17, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_SEG, FCML_REG_SS, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 0F A1 POP FS NP Valid Valid Pop top of stack into FS; increment stack pointer by 16 bits.
	// 0F A1 POP FS NP N.E. Valid Pop top of stack into FS; increment stack pointer by 32 bits.
	// 0F A1 POP FS NP Valid N.E. Pop top of stack into FS; increment stack pointer by 64 bits.
	{ NULL, 0x0001, 0x00D80000, { 0x0F, 0xA1, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_SEG, FCML_REG_FS, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 0F A9 POP GS NP Valid Valid Pop top of stack into GS; increment stack pointer by 16 bits.
	// 0F A9 POP GS NP N.E. Valid Pop top of stack into GS; increment stack pointer by 32 bits.
	// 0F A9 POP GS NP Valid N.E. Pop top of stack into GS; increment stack pointer by 64 bits.
	{ NULL, 0x0001, 0x00D80000, { 0x0F, 0xA9, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_SEG, FCML_REG_GS, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_POPA[] = {
	// 61 POPA NP Invalid Valid Pop DI, SI, BP, BX, DX, CX, and AX.
	{ NULL, 0x0001, 0x01440000, { 0x61, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 61 POPAD NP Invalid Valid Pop EDI, ESI, EBP, EBX, EDX, ECX, and EAX.
	{ "popad", 0x0001, 0x02440000, { 0x61, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_POPCNT[] = {
	// F3 0F B8 /r POPCNT r16, r/m16 RM Valid Valid POPCNT on r/m16
	// F3 0F B8 /r POPCNT r32, r/m32 RM Valid Valid POPCNT on r/m32
	// F3 REX.W 0F B8 /r POPCNT r64, r/m64 RM Valid N.E. POPCNT on r/m64
	{ NULL, 0x4000, 0x00D88000, { 0x0F, 0xB8, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM_W, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_POPF[] = {
	// 9D POPF NP Valid Valid Pop top of stack into lower 16 bits of EFLAGS.
	{ NULL, 0x0000, 0x01C40000, { 0x9D, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 9D POPFD NP N.E. Valid Pop top of stack into EFLAGS.
	{ "popfd", 0x0000, 0x02440000, { 0x9D, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 9D POPFQ NP Valid N.E. Pop top of stack and zero-extend into RFLAGS.
	{ "popfq", 0x0000, 0x04840000, { 0x9D, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_POR[] = {
	// 0F EB /r1 POR mm,mm/m64
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xEB, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F EB /r POR xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xEB, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG EB /r VPOR xmm1,xmm2,xmm3/m128
	{ "vpor", 0x10C0, 0x00D88000, { 0x0F, 0xEB, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG EB /r VPOR ymm1,ymm2,ymm3/m256
	{ "vpor", 0x10A0, 0x00D88000, { 0x0F, 0xEB, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PREFETCHT[] = {
	// 0F 18 /1 PREFETCHT0 m8 M Valid Valid Move data from m8 closer to the processor using T0 hint.
	{ "prefetcht0", 0x0001, 0x80D98800, { 0x0F, 0x18, 0x00 }, { FCML_OP_MODRM_M_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 18 /2 PREFETCHT1 m8 M Valid Valid Move data from m8 closer to the processor using T1 hint.
	{ "prefetcht1", 0x0001, 0x80D99000, { 0x0F, 0x18, 0x00 }, { FCML_OP_MODRM_M_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 18 /3 PREFETCHT2 m8 M Valid Valid Move data from m8 closer to the processor using T2 hint.
	{ "prefetcht2", 0x0001, 0x80D99800, { 0x0F, 0x18, 0x00 }, { FCML_OP_MODRM_M_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 18 /0 PREFETCHNTA m8 M Valid Valid Move data from m8 closer to the processor using NTA hint.
	{ "prefetchnta", 0x0001, 0x80D98000, { 0x0F, 0x18, 0x00 }, { FCML_OP_MODRM_M_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSADBW[] = {
	// 0F F6 /r PSADBW mm1,mm2/m64
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xF6, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F F6 /r PSADBW xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xF6, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG F6 /r VPSADBW xmm1,xmm2,xmm3/m128
	{ "vpsadbw", 0x10C0, 0x00D88000, { 0x0F, 0xF6, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG F6 /r VPSADBW ymm1,ymm2,ymm3/m256
	{ "vpsadbw", 0x10A0, 0x00D88000, { 0x0F, 0xF6, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSHUFB[] = {
	// 0F 38 00 /r PSHUFB mm1,mm2/m64
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x38, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 00 /r PSHUFB xmm1,xmm2/m128
	{ NULL, 0x1000, 0x00EC8000, { 0x0F, 0x38, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 00 /r VPSHUFB xmm1,xmm2,xmm3/m128
	{ "vpshufb", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 00 /r VPSHUFB ymm1,ymm2,ymm3/m256
	{ "vpshufb", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }

};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSHUFD[] = {
	// 66 0F 70 /r ib PSHUFD xmm1,xmm2/m128,imm8
	{ NULL, 0x1000, 0x00D88000, { 0x0F, 0x70, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F.WIG 70 /r ib VPSHUFD xmm1,xmm2/m128,imm8
	{ "vpshufd", 0x10C0, 0x00D88000, { 0x0F, 0x70, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.256.66.0F.WIG 70 /r ib VPSHUFD ymm1,ymm2/m256,imm8
	{ "vpshufd", 0x10A0, 0x00D88000, { 0x0F, 0x70, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_YMM_256, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSHUFHW[] = {
	// F3 0F 70 /r ib PSHUFHW xmm1,xmm2/m128,imm8
	{ NULL, 0x4000, 0x00D88000, { 0x0F, 0x70, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.F3.0F.WIG 70 /r ib VPSHUFHW xmm1,xmm2/m128,imm8
	{ "vpshufhw", 0x40C0, 0x00D88000, { 0x0F, 0x70, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.256.F3.0F.WIG 70 /r ib VPSHUFHW ymm1,ymm2/m256,imm8
	{ "vpshufhw", 0x40A0, 0x00D88000, { 0x0F, 0x70, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_YMM_256, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSHUFLW[] = {
	// F2 0F 70 /r ib PSHUFLW xmm1,xmm2/m128,imm8
	{ NULL, 0x2000, 0x00D88000, { 0x0F, 0x70, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.F2.0F.WIG 70 /r ib VPSHUFLW xmm1,xmm2/m128,imm8
	{ "vpshuflw", 0x20C0, 0x00D88000, { 0x0F, 0x70, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.256.F2.0F.WIG 70 /r ib VPSHUFLW ymm1,ymm2/m256,imm8
	{ "vpshuflw", 0x20A0, 0x00D88000, { 0x0F, 0x70, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_YMM_256, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSHUFW[] = {
	// 0F 70 /r ib PSHUFW mm1,mm2/m64,imm8
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0x70, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_OP_IB, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSIGN[] = {
	// 0F 38 08 /r PSIGNB mm1,mm2/m64
	{ "psignb", 0x0000, 0x00EC8000, { 0x0F, 0x38, 0x08 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 38 09 /r PSIGNW mm1,mm2/m64
	{ "psignw", 0x0000, 0x00EC8000, { 0x0F, 0x38, 0x09 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 38 0A /r PSIGND mm1,mm2/m64
	{ "psignd", 0x0000, 0x00EC8000, { 0x0F, 0x38, 0x0A }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 08 /r PSIGNB xmm1,xmm2/m128
	{ "psignb", 0x1000, 0x00EC8000, { 0x0F, 0x38, 0x08 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 09 /r PSIGNW xmm1,xmm2/m128
	{ "psignw", 0x1000, 0x00EC8000, { 0x0F, 0x38, 0x09 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 38 0A /r PSIGND xmm1,xmm2/m128
	{ "psignd", 0x1000, 0x00EC8000, { 0x0F, 0x38, 0x0A }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 08 /r VPSIGNB xmm1,xmm2,xmm3/m128
	{ "vpsignb", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x08 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 09 /r VPSIGNW xmm1,xmm2,xmm3/m128
	{ "vpsignw", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x09 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.WIG 0A /r VPSIGND xmm1,xmm2,xmm3/m128
	{ "vpsignd", 0x10C0, 0x00EC8000, { 0x0F, 0x38, 0x0A }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 08 /r VPSIGNB ymm1,ymm2,ymm3/m256
	{ "vpsignb", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x08 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 09 /r VPSIGNW ymm1,ymm2,ymm3/m256
	{ "vpsignw", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x09 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F38.WIG 0A /r VPSIGND ymm1,ymm2,ymm3/m256
	{ "vpsignd", 0x10A0, 0x00EC8000, { 0x0F, 0x38, 0x0A }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSLLDQ[] = {
	// 66 0F 73 /7 ib PSLLDQ xmm1,imm8
	{ NULL, 0x1000, 0x00DBB800, { 0x0F, 0x73, 0x00 }, { FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDD.128.66.0F.WIG 73 /7 ib VPSLLDQ xmm1,xmm2,imm8
	{ "vpslldq", 0x10C0, 0x00DBB800, { 0x0F, 0x73, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDD.256.66.0F.WIG 73 /7 ib VPSLLDQ ymm1,ymm2,imm8
	{ "vpslldq", 0x10A0, 0x00DBB800, { 0x0F, 0x73, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_YWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSLL[] = {
	// 0F F1 /r1 PSLLW mm,mm/m64
	{ "psllw", 0x0000, 0x00D88000, { 0x0F, 0xF1, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F F2 /r1 PSLLD mm,mm/m64
	{ "pslld", 0x0000, 0x00D88000, { 0x0F, 0xF2, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F F3 /r1 PSLLQ mm,mm/m64
	{ "psllq", 0x0000, 0x00D88000, { 0x0F, 0xF3, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F F1 /r PSLLW xmm1,xmm2/m128
	{ "psllw", 0x1000, 0x00D88000, { 0x0F, 0xF1, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F F2 /r PSLLD xmm1,xmm2/m128
	{ "pslld", 0x1000, 0x00D88000, { 0x0F, 0xF2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F F3 /r PSLLQ xmm1,xmm2/m128
	{ "psllq", 0x1000, 0x00D88000, { 0x0F, 0xF3, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 71 /6 ib PSLLW mm,imm8
	{ "psllw", 0x0000, 0x00DBB000, { 0x0F, 0x71, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 72 /6 ib1 PSLLD mm,imm8
	{ "pslld", 0x0000, 0x00DBB000, { 0x0F, 0x72, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 73 /6 ib1 PSLLQ mm,imm8
	{ "psllq", 0x0000, 0x00DBB000, { 0x0F, 0x73, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 71 /6 ib PSLLW xmm1,imm8
	{ "psllw", 0x1000, 0x00DBB000, { 0x0F, 0x71, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 72 /6 ib PSLLD xmm1,imm8
	{ "pslld", 0x1000, 0x00DBB000, { 0x0F, 0x72, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 73 /6 ib PSLLQ xmm1,imm8
	{ "psllq", 0x1000, 0x00DBB000, { 0x0F, 0x73, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG F1 /r VPSLLW xmm1,xmm2,xmm3/m128
	{ "vpsllw", 0x10C0, 0x00D88000, { 0x0F, 0xF1, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG F2 /r VPSLLD xmm1,xmm2,xmm3/m128
	{ "vpslld", 0x10C0, 0x00D88000, { 0x0F, 0xF2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG F3 /r VPSLLQ xmm1,xmm2,xmm3/m128
	{ "vpsllq", 0x10C0, 0x00D88000, { 0x0F, 0xF3, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG F2 /r VPSLLD ymm1,ymm2,xmm3/m128
	{ "vpslld", 0x10A0, 0x00D88000, { 0x0F, 0xF2, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDD.128.66.0F.WIG 71 /6 ib VPSLLW xmm1,xmm2,imm8
	{ "vpsllw", 0x10C0, 0x00DBB000, { 0x0F, 0x71, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDD.128.66.0F.WIG 72 /6 ib VPSLLD xmm1,xmm2,imm8
	{ "vpslld", 0x10C0, 0x00DBB000, { 0x0F, 0x72, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDD.128.66.0F.WIG 73 /6 ib VPSLLQ xmm1,xmm2,imm8
	{ "vpsllq", 0x10C0, 0x00DBB000, { 0x0F, 0x73, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDD.256.66.0F.WIG 71 /6 ib VPSLLW ymm1,ymm2,imm8
	{ "vpsllw", 0x10A0, 0x00DBB000, { 0x0F, 0x71, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_YWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSRA[] = {
	// 0F E1 /r1 PSRAW mm,mm/m64
	// 0F E2 /r1 PSRAD mm,mm/m64
	{ "psraw", 0x0000, 0x00D88000, { 0x0F, 0xE1, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	{ "psrad", 0x0000, 0x00D88000, { 0x0F, 0xE2, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F E1 /r PSRAW xmm1,xmm2/m128
	// 66 0F E2 /r PSRAD xmm1,xmm2/m128
	{ "psraw", 0x1000, 0x00D88000, { 0x0F, 0xE1, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	{ "psrad", 0x1000, 0x00D88000, { 0x0F, 0xE2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG E1 /r VPSRAW xmm1,xmm2,xmm3/m128
	// VEX.NDS.128.66.0F.WIG E2 /r VPSRAD xmm1,xmm2,xmm3/m128
	{ "vpsraw", 0x10C0, 0x00D88000, { 0x0F, 0xE1, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	{ "vpsrad", 0x10C0, 0x00D88000, { 0x0F, 0xE2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG E1 /r VPSRAW ymm1, ymm2, xmm3/m128
	// VEX.NDS.256.66.0F.WIG E2 /r VPSRAD ymm1, ymm2, xmm3/m128
	{ "vpsraw", 0x10A0, 0x00D88000, { 0x0F, 0xE1, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	{ "vpsrad", 0x10A0, 0x00D88000, { 0x0F, 0xE2, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// 0F 71 /4 ib1 PSRAW mm,imm8
	// 0F 72 /4 ib1 PSRAD mm,imm8
	{ "psraw", 0x0000, 0x00DBA000, { 0x0F, 0x71, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	{ "psrad", 0x0000, 0x00DBA000, { 0x0F, 0x72, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 71 /4 ib PSRAW xmm1,imm8
	// 66 0F 72 /4 ib PSRAD xmm1,imm8
	{ "psraw", 0x1000, 0x00DBA000, { 0x0F, 0x71, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	{ "psrad", 0x1000, 0x00DBA000, { 0x0F, 0x72, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDD.128.66.0F.WIG 71 /4 ib VPSRAW xmm1,xmm2,imm8
	// VEX.NDD.128.66.0F.WIG 72 /4 ib VPSRAD xmm1,xmm2,imm8
	{ "vpsraw", 0x10C0, 0x00DBA000, { 0x0F, 0x71, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	{ "vpsrad", 0x10C0, 0x00DBA000, { 0x0F, 0x72, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDD.256.66.0F.WIG 71 /4 ib VPSRAW ymm1,ymm2,imm8
	// VEX.NDD.256.66.0F.WIG 72 /4 ib VPSRAD ymm1,ymm2,imm8
	{ "vpsraw", 0x10A0, 0x00DBA000, { 0x0F, 0x71, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_YWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	{ "vpsrad", 0x10A0, 0x00DBA000, { 0x0F, 0x72, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_YWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSRLDQ[] = {
	// 66 0F 73 /3 ib PSRLDQ xmm1,imm8
	{ NULL, 0x1000, 0x00DB9800, { 0x0F, 0x73, 0x00 }, { FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDD.128.66.0F.WIG 73 /3 ib VPSRLDQ xmm1,xmm2,imm8
	{ "vpsrldq", 0x10C0, 0x00DB9800, { 0x0F, 0x73, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDD.256.66.0F.WIG 73 /3 ib VPSRLDQ ymm1,ymm2,imm8
	{ "vpsrldq", 0x10A0, 0x00DB9800, { 0x0F, 0x73, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_YWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSRL[] = {
	// 0F D1 /r PSRLW mm,mm/m64
	{ "psrlw", 0x0000, 0x00D88000, { 0x0F, 0xD1, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F D2 /r PSRLD mm,mm/m64
	{ "psrld", 0x0000, 0x00D88000, { 0x0F, 0xD2, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F D3 /r PSRLQ mm,mm/m64
	{ "psrlq", 0x0000, 0x00D88000, { 0x0F, 0xD3, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F D1 /r PSRLW xmm1,xmm2/m128
	{ "psrlw", 0x1000, 0x00D88000, { 0x0F, 0xD1, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F D2 /r PSRLD xmm1,xmm2/m128
	{ "psrld", 0x1000, 0x00D88000, { 0x0F, 0xD2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F D3 /r PSRLQ xmm1,xmm2/m128
	{ "psrlq", 0x1000, 0x00D88000, { 0x0F, 0xD3, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 71 /2 ib PSRLW mm,imm8
	{ "psrlw", 0x0000, 0x00DB9000, { 0x0F, 0x71, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 72 /2 ib PSRLD mm,imm8
	{ "psrld", 0x0000, 0x00DB9000, { 0x0F, 0x72, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 73 /2 ib PSRLQ mm,imm8
	{ "psrlq", 0x0000, 0x00DB9000, { 0x0F, 0x73, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 71 /2 ib PSRLW xmm1,imm8
	{ "psrlw", 0x1000, 0x00DB9000, { 0x0F, 0x71, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 72 /2 ib PSRLD xmm1,imm8
	{ "psrld", 0x1000, 0x00DB9000, { 0x0F, 0x72, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 73 /2 ib PSRLQ xmm1,imm8
	{ "psrlq", 0x1000, 0x00DB9000, { 0x0F, 0x73, 0x00 }, { FCML_OP_RM(FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG D1 /r VPSRLW xmm1,xmm2,xmm3/m128
	{ "vpsrlw", 0x10C0, 0x00D88000, { 0x0F, 0xD1, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG D2 /r VPSRLD xmm1,xmm2,xmm3/m128
	{ "vpsrld", 0x10C0, 0x00D88000, { 0x0F, 0xD2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG D3 /r VPSRLQ xmm1,xmm2,xmm3/m128
	{ "vpsrlq", 0x10C0, 0x00D88000, { 0x0F, 0xD3, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG D1 /r VPSRLW ymm1,ymm2,xmm3/m128
	{ "vpsrlw", 0x10A0, 0x00D88000, { 0x0F, 0xD1, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG D2 /r VPSRLD ymm1,ymm2,xmm3/m128
	{ "vpsrld", 0x10A0, 0x00D88000, { 0x0F, 0xD2, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDD.128.66.0F.WIG 71 /2 ib VPSRLW xmm1,xmm2,imm8
	{ "vpsrlw", 0x10C0, 0x00DB9000, { 0x0F, 0x71, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDD.128.66.0F.WIG 72 /2 ib VPSRLD xmm1,xmm2,imm8
	{ "vpsrld", 0x10C0, 0x00DB9000, { 0x0F, 0x72, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDD.128.66.0F.WIG 73 /2 ib VPSRLQ xmm1,xmm2,imm8
	{ "vpsrlq", 0x10C0, 0x00DB9000, { 0x0F, 0x73, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_OWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDD.256.66.0F.WIG 71 /2 ib VPSRLW ymm1,ymm2,imm8
	{ "vpsrlw", 0x10A0, 0x00DB9000, { 0x0F, 0x71, 0x00 }, { FCML_OP_VEX_VVVV_SIMD_REG | FCML_OA_W, FCML_OP_RM( FCML_REG_SIMD, FCML_EOS_YWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSUB[] = {
	// 0F F8 /r PSUBB mm,mm/m64
	{ "psubb", 0x0000, 0x00D88000, { 0x0F, 0xF8, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F F9 /r PSUBW mm,mm/m64
	{ "psubw", 0x0000, 0x00D88000, { 0x0F, 0xF9, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F FA /r PSUBD mm,mm/m64
	{ "psubd", 0x0000, 0x00D88000, { 0x0F, 0xFA, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F F8 /r PSUBB xmm1,xmm2/m128
	{ "psubb", 0x1001, 0x00D88000, { 0x0F, 0xF8, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F F9 /r PSUBW xmm1,xmm2/m128
	{ "psubw", 0x1001, 0x00D88000, { 0x0F, 0xF9, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F FA /r PSUBD xmm1,xmm2/m128
	{ "psubd", 0x1001, 0x00D88000, { 0x0F, 0xFA, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG F8 /r VPSUBB xmm1,xmm2,xmm3/m128
	{ "vpsubb", 0x10C0, 0x00D88000, { 0x0F, 0xF8, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG F9 /r VPSUBW xmm1,xmm2,xmm3/m128
	{ "vpsubw", 0x10C0, 0x00D88000, { 0x0F, 0xF9, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG FA /r VPSUBD xmm1,xmm2,xmm3/m128
	{ "vpsubd", 0x10C0, 0x00D88000, { 0x0F, 0xFA, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG F8 /r VPSUBB ymm1,ymm2,ymm3/m256
	{ "vpsubb", 0x10A0, 0x00D88000, { 0x0F, 0xF8, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG F9 /r VPSUBW ymm1,ymm2,ymm3/m256
	{ "vpsubw", 0x10A0, 0x00D88000, { 0x0F, 0xF9, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG FA /r VPSUBD ymm1,ymm2,ymm3/m256
	{ "vpsubd", 0x10A0, 0x00D88000, { 0x0F, 0xFA, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG FB /r VPSUBQ ymm1,ymm2,ymm3/m256
	{ "vpsubq", 0x10A0, 0x00D88000, { 0x0F, 0xFB, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSUBQ[] = {
	// 0F FB /r PSUBQ mm1,mm2/m64
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0xFB, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F FB /r PSUBQ xmm1,xmm2/m128
	{ NULL, 0x1000, 0x00D88000, { 0x0F, 0xFB, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG FB/r VPSUBQ xmm1,xmm2,xmm3/m128
	{ "vpsubq", 0x10C0, 0x00D88000, { 0x0F, 0xFB, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_128, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSUBS[] = {
	// 0F E8 /r PSUBSB mm,mm/m64
	{ "psubsb", 0x0000, 0x00D88000, { 0x0F, 0xE8, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F E9 /r PSUBSW mm,mm/m64
	{ "psubsw", 0x0000, 0x00D88000, { 0x0F, 0xE9, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F E8 /r PSUBSB xmm1,xmm2/m128
	{ "psubsb", 0x1000, 0x00D88000, { 0x0F, 0xE8, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F E9 /r PSUBSW xmm1,xmm2/m128
	{ "psubsw", 0x1000, 0x00D88000, { 0x0F, 0xE9, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG E8 /r VPSUBSB xmm1,xmm2,xmm3/m128
	{ "vpsubsb", 0x10C0, 0x00D88000, { 0x0F, 0xE8, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG E9 /r VPSUBSW xmm1,xmm2,xmm3/m128
	{ "vpsubsw", 0x10C0, 0x00D88000, { 0x0F, 0xE9, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG E8 /r VPSUBSB ymm1,ymm2,ymm3/m256
	{ "vpsubsb", 0x10A0, 0x00D88000, { 0x0F, 0xE8, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG E9 /r VPSUBSW ymm1,ymm2,ymm3/m256
	{ "vpsubsw", 0x10A0, 0x00D88000, { 0x0F, 0xE9, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSUBUS[] = {
	// 0F D8 /r PSUBUSB mm,mm/m64
	{ "psubusb", 0x0000, 0x00D88000, { 0x0F, 0xD8, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F D9 /r1 PSUBUSW mm,mm/m64
	{ "psubusw", 0x0000, 0x00D88000, { 0x0F, 0xD9, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F D8 /r PSUBUSB xmm1,xmm2/m128
	{ "psubusb", 0x1000, 0x00D88000, { 0x0F, 0xD8, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F D9 /r PSUBUSW xmm1,xmm2/m128
	{ "psubusw", 0x1000, 0x00D88000, { 0x0F, 0xD9, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG D8 /r VPSUBUSB xmm1,xmm2,xmm3/m128
	{ "vpsubusb", 0x10C0, 0x00D88000, { 0x0F, 0xD8, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG D9 /r VPSUBUSW xmm1,xmm2,xmm3/m128
	{ "vpsubusw", 0x10C0, 0x00D88000, { 0x0F, 0xD9, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG D8 /r VPSUBUSB ymm1,ymm2,ymm3/m256
	{ "vpsubusb", 0x10A0, 0x00D88000, { 0x0F, 0xD8, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG D9 /r VPSUBUSW ymm1,ymm2,ymm3/m256
	{ "vpsubusw", 0x10A0, 0x00D88000, { 0x0F, 0xD9, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PTEST[] = {
	// 66 0F 38 17 /r PTEST xmm1,xmm2/m128
	{ "ptest", 0x1000, 0x00EC8000, { 0x0F, 0x38, 0x17 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.WIG 17 /r VPTEST xmm1,xmm2/m128
	// VEX.256.66.0F38.WIG 17 /r VPTEST ymm1,ymm2/m256
	{ "vptest", 0x1180, 0x00EC8000, { 0x0F, 0x38, 0x17 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PUNPCKL[] = {
	// 0F 60 /r PUNPCKLBW mm,mm/m32
	{ "punpcklbw", 0x0000, 0x00D88000, { 0x0F, 0x60, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX_32, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 61 /r PUNPCKLWD mm,mm/m32
	{ "punpcklwd", 0x0000, 0x00D88000, { 0x0F, 0x61, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX_32, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 62 /r PUNPCKLDQ mm,mm/m32
	{ "punpckldq", 0x0000, 0x00D88000, { 0x0F, 0x62, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX_32, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 60 /r PUNPCKLBW xmm1,xmm2/m128
	{ "punpcklbw", 0x1000, 0x00D88000, { 0x0F, 0x60, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 61 /r PUNPCKLWD xmm1,xmm2/m128
	{ "punpcklwd", 0x1000, 0x00D88000, { 0x0F, 0x61, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 62 /r PUNPCKLDQ xmm1,xmm2/m128
	{ "punpckldq", 0x1000, 0x00D88000, { 0x0F, 0x62, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 6C /r PUNPCKLQDQ xmm1,xmm2/m128
	{ "punpcklqdq", 0x1000, 0x00D88000, { 0x0F, 0x6C, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 60 /r VPUNPCKLBW xmm1,xmm2,xmm3/m128
	{ "vpunpcklbw", 0x10C0, 0x00D88000, { 0x0F, 0x60, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 61 /r VPUNPCKLWD xmm1,xmm2,xmm3/m128
	{ "vpunpcklwd", 0x10C0, 0x00D88000, { 0x0F, 0x61, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 62 /r VPUNPCKLDQ xmm1,xmm2,xmm3/m128
	{ "vpunpckldq", 0x10C0, 0x00D88000, { 0x0F, 0x62, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 6C /r VPUNPCKLQDQ xmm1,xmm2,xmm3/m128
	{ "vpunpcklqdq", 0x10C0, 0x00D88000, { 0x0F, 0x6C, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 60 /r VPUNPCKLBW ymm1,ymm2,ymm3/m256
	{ "vpunpcklbw", 0x10A0, 0x00D88000, { 0x0F, 0x60, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 61 /r VPUNPCKLWD ymm1,ymm2,ymm3/m256
	{ "vpunpcklwd", 0x10A0, 0x00D88000, { 0x0F, 0x61, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 62 /r VPUNPCKLDQ ymm1,ymm2,ymm3/m256
	{ "vpunpckldq", 0x10A0, 0x00D88000, { 0x0F, 0x62, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 6C /r VPUNPCKLQDQ ymm1,ymm2,ymm3/m256
	{ "vpunpcklqdq", 0x10A0, 0x00D88000, { 0x0F, 0x6C, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PUNPCKH[] = {
	// 0F 68 /r PUNPCKHBW mm,mm/m64
	{ "punpckhbw", 0x0000, 0x00D88000, { 0x0F, 0x68, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 69 /r PUNPCKHWD mm,mm/m64
	{ "punpckhwd", 0x0000, 0x00D88000, { 0x0F, 0x69, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 0F 6A /r PUNPCKHDQ mm,mm/m64
	{ "punpckhdq", 0x0000, 0x00D88000, { 0x0F, 0x6A, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 68 /r PUNPCKHBW xmm1,xmm2/m128
	{ "punpckhbw", 0x1000, 0x00D88000, { 0x0F, 0x68, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 69 /r PUNPCKHWD xmm1,xmm2/m128
	{ "punpckhwd", 0x1000, 0x00D88000, { 0x0F, 0x69, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 6A /r PUNPCKHDQ xmm1,xmm2/m128
	{ "punpckhdq", 0x1000, 0x00D88000, { 0x0F, 0x6A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F 6D /r PUNPCKHQDQ xmm1,xmm2/m128
	{ "punpckhqdq", 0x1000, 0x00D88000, { 0x0F, 0x6D, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 68 /r VPUNPCKHBW xmm1,xmm2,xmm3/m128
	{ "vpunpckhbw", 0x10C0, 0x00D88000, { 0x0F, 0x68, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 69 /r VPUNPCKHWD xmm1,xmm2,xmm3/m128
	{ "vpunpckhwd", 0x10C0, 0x00D88000, { 0x0F, 0x69, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 6A /r VPUNPCKHDQ xmm1,xmm2,xmm3/m128
	{ "vpunpckhdq", 0x10C0, 0x00D88000, { 0x0F, 0x6A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 6D /r VPUNPCKHQDQ xmm1,xmm2,xmm3/m128
	{ "vpunpckhqdq", 0x10C0, 0x00D88000, { 0x0F, 0x6D, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 68 /r VPUNPCKHBW ymm1,ymm2,ymm3/m256
	{ "vpunpckhbw", 0x10A0, 0x00D88000, { 0x0F, 0x68, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 69 /r VPUNPCKHWD ymm1,ymm2,ymm3/m256
	{ "vpunpckhwd", 0x10A0, 0x00D88000, { 0x0F, 0x69, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 6A /r VPUNPCKHDQ ymm1,ymm2,ymm3/m256
	{ "vpunpckhdq", 0x10A0, 0x00D88000, { 0x0F, 0x6A, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG 6D /r VPUNPCKHQDQ ymm1,ymm2,ymm3/m256
	{ "vpunpckhqdq", 0x10A0, 0x00D88000, { 0x0F, 0x6D, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PUSH[] = {
	// FF /6 PUSH r/m16 M Valid Valid Push r/m16.
	// FF /6 PUSH r/m32 M N.E. Valid Push r/m32.
	// FF /6 PUSH r/m64 M Valid N.E. Push r/m64.
	{ NULL, 0x0001, 0x0045B000, { 0xFF, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x0185B000, { 0xFF, 0x00, 0x00 }, { FCML_OP_MODRM_RM_16_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x0685B000, { 0xfF, 0x00, 0x00 }, { FCML_OP_MODRM_RM_64_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 50+rw PUSH r16 O Valid Valid Push r16.
	// 50+rd PUSH r32 O N.E. Valid Push r32.
	// 50+rd PUSH r64 O Valid N.E. Push r64.
	{ NULL, 0x0001, 0x00440000, { 0x50, 0x00, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_EOSA), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x01840000, { 0x50, 0x00, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_WORD ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x06840000, { 0x50, 0x00, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_QWORD ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 6A PUSH imm8 I Valid Valid Push imm8.
	{ NULL, 0x0001, 0x00C40000, { 0x6A, 0x00, 0x00 }, { FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 68 PUSH imm16 I Valid Valid Push imm16.
	{ NULL, 0x0001, 0x01C40000, { 0x68, 0x00, 0x00 }, { FCML_OP_IW_EX_EOSA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 68 PUSH imm32 I Valid Valid Push imm32.
	{ NULL, 0x0001, 0x06C40000, { 0x68, 0x00, 0x00 }, { FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 1E PUSH DS NP Invalid Valid Push DS.
	// 06 PUSH ES NP Invalid Valid Push ES.
	// 16 PUSH SS NP Invalid Valid Push SS.
	// 0E PUSH CS NP Invalid Valid Push CS.
	{ NULL, 0x0001, 0x00440000, { 0x1E, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_SEG, FCML_REG_DS, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x00440000, { 0x06, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_SEG, FCML_REG_ES, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x00440000, { 0x16, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_SEG, FCML_REG_SS, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0001, 0x00440000, { 0x0E, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_SEG, FCML_REG_CS, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 0F A0 PUSH FS NP Valid Valid Push FS.
	{ NULL, 0x0001, 0x00D80000, { 0x0F, 0xA0, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_SEG, FCML_REG_FS, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 0F A8 PUSH GS NP Valid Valid Push GS.
	{ NULL, 0x0001, 0x00D80000, { 0x0F, 0xA8, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_SEG, FCML_REG_GS, FCML_EOS_UNDEFINED ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PUSHA[] = {
	// 60 PUSHA NP Invalid Valid Push AX, CX, DX, BX, original SP, BP, SI, and DI.
	{ NULL, 0x0001, 0x01440000, { 0x60, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 60 PUSHAD NP Invalid Valid Push EAX, ECX, EDX, EBX, original ESP, EBP, ESI, and EDI.
	{ "pushad", 0x0001, 0x02440000, { 0x60, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PUSHF[] = {
	// 9C PUSHF NP Valid Valid Push lower 16 bits of EFLAGS.
	{ NULL, 0x0000, 0x01C40000, { 0x9C, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 9C PUSHFD NP N.E. Valid Push EFLAGS.
	{ "pushfd", 0x0000, 0x02440000, { 0x9C, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// 9C PUSHFQ NP Valid N.E. Push RFLAGS.
	{ "pushfq", 0x0000, 0x04840000, { 0x9C, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PXOR[] = {
	// 0F EF /r PXOR mm,mm/m64
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xEF, 0x00 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } },
	// 66 0F EF /r PXOR xmm1,xmm2/m128
	{ NULL, 0x1001, 0x00D88000, { 0x0F, 0xEF, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG EF /r VPXOR xmm1,xmm2,xmm3/m128
	{ "vpxor", 0x10C0, 0x00D88000, { 0x0F, 0xEF, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VEX.NDS.256.66.0F.WIG EF /r VPXOR ymm1,ymm2,ymm3/m256
	{ "vpxor", 0x10A0, 0x00D88000, { 0x0F, 0xEF, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RCL[] = {
	// D0 /2 RCL r/m8, 1
	// REX + D0 /2 RCL r/m8, 1
	{ NULL, 0x0000, 0x00C59000, { 0xD0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D2 /2 RCL r/m8, CL
	// REX + D2 /2 RCL r/m8, CL
	{ NULL, 0x0000, 0x00C59000, { 0xD2, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C0 /2 ib RCL r/m8, imm8
	// REX + C0 /2 ib RCL r/m8, imm8
	{ NULL, 0x0000, 0x00C59000, { 0xC0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// D1 /2 RCL r/m16, 1
	// D1 /2 RCL r/m32, 1
	// REX.W + D1 /2 RCL r/m64, 1
	{ NULL, 0x0000, 0x00C59000, { 0xD1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D3 /2 RCL r/m16, CL
	// D3 /2 RCL r/m32, CL
	// REX.W + D3 /2 RCL r/m64, CL
	{ NULL, 0x0000, 0x00C59000, { 0xD3, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C1 /2 ib RCL r/m16, imm8
	// C1 /2 ib RCL r/m32, imm8
	// REX.W + C1 /2 ib RCL r/m64, imm8
	{ NULL, 0x0000, 0x00C59000, { 0xC1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RCR[] = {
	// D0 /3 RCR r/m8, 1
	// REX + D0 /3 RCR r/m8, 1
	{ NULL, 0x0000, 0x00C59800, { 0xD0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D2 /3 RCR r/m8, CL
	// REX + D2 /3 RCR r/m8, CL
	{ NULL, 0x0000, 0x00C59800, { 0xD2, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C0 /3 ib RCR r/m8, imm8
	// REX + C0 /3 ib RCR r/m8, imm8
	{ NULL, 0x0000, 0x00C59800, { 0xC0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// D1 /3 RCR r/m16, 1
	// D1 /3 RCR r/m32, 1
	// REX.W + D1 /3 RCR r/m64, 1
	{ NULL, 0x0000, 0x00C59800, { 0xD1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D3 /3 RCR r/m16, CL
	// D3 /3 RCR r/m32, CL
	// REX.W + D3 /3 RCR r/m64, CL
	{ NULL, 0x0000, 0x00C59800, { 0xD3, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C1 /3 ib RCR r/m16, imm8
	// C1 /3 ib RCR r/m32, imm8
	// REX.W + C1 /3 ib RCR r/m64, imm8
	{ NULL, 0x0000, 0x00C59800, { 0xC1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ROL[] = {
	// D0 /0 ROL r/m8, 1
	// REX + D0 /0 ROL r/m8, 1
	{ NULL, 0x0000, 0x00C58000, { 0xD0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D2 /0 ROL r/m8, CL
	// REX + D2 /0 ROL r/m8, CL
	{ NULL, 0x0000, 0x00C58000, { 0xD2, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C0 /0 ib ROL r/m8, imm8
	// REX + C0 /0 ib ROL r/m8, imm8
	{ NULL, 0x0000, 0x00C58000, { 0xC0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// D1 /0 ROL r/m16, 1
	// D1 /0 ROL r/m32, 1
	// REX.W + D1 /0 ROL r/m64, 1
	{ NULL, 0x0000, 0x00C58000, { 0xD1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D3 /0 ROL r/m16, CL
	// D3 /0 ROL r/m32, CL
	// REX.W + D3 /0 ROL r/m64, CL
	{ NULL, 0x0000, 0x00C58000, { 0xD3, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C1 /0 ib ROL r/m16, imm8
	// C1 /0 ib ROL r/m32, imm8
	// C1 /0 ib ROL r/m64, imm8
	{ NULL, 0x0000, 0x00C58000, { 0xC1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ROR[] = {
	// D0 /1 ROR r/m8, 1
	// REX + D0 /1 ROR r/m8, 1
	{ NULL, 0x0000, 0x00C58800, { 0xD0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D2 /1 ROR r/m8, CL
	// REX + D2 /1 ROR r/m8, CL
	{ NULL, 0x0000, 0x00C58800, { 0xD2, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C0 /1 ib ROR r/m8, imm8
	// REX + C0 /1 ib ROR r/m8, imm8
	{ NULL, 0x0000, 0x00C58800, { 0xC0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// D1 /1 ROR r/m16, 1
	// D1 /1 ROR r/m32, 1
	// REX.W + D1 /1 ROR r/m64, 1
	{ NULL, 0x0000, 0x00C58800, { 0xD1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D3 /1 ROR r/m16, CL
	// D3 /1 ROR r/m32, CL
	// REX.W + D3 /1 ROR r/m64, CL
	{ NULL, 0x0000, 0x00C58800, { 0xD3, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C1 /1 ib ROR r/m16, imm8
	// C1 /1 ib ROR r/m32, imm8
	// REX.W + C1 /1 ib ROR r/m64, imm8
	{ NULL, 0x0000, 0x00C58800, { 0xC1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } }
};

// XMMWORD
struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RCPPS[] = {
	// 0F 53 /r RCPPS xmm1,xmm2/m128
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0x53, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.0F.WIG 53 /r VRCPPS xmm1,xmm2/m128
	// VEX.256.0F.WIG 53 /r VRCPPS ymm1,ymm2/m256
	{ "vrcpps", 0x0181, 0x00D88000, { 0x0F, 0x53, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RCPSS[] = {
	// F3 0F 53 /r RCPSS xmm1,xmm2/m32
	{ NULL, 0x4000, 0x00D88000, { 0x0F, 0x53, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.LIG.F3.0F.WIG 53 /r VRCPSS xmm1,xmm2,xmm3/m32
	{ "vrcpss", 0x40C0, 0x00D88000, { 0x0F, 0x53, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_32, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RDFSBASE[] = {
	// F3 0F AE /0 RDFSBASE r32
	// REX.W + F3 0F AE /0 RDFSBASE r64
	{ NULL, 0x4000, 0x039B8000, { 0x0F, 0xAE, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ) | FCML_OA_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x4000, 0x049B8000, { 0x0F, 0xAE, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ) | FCML_OA_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// F3 0F AE /1 RDGSBASE r32
	// REX.W + F3 0F AE /1 RDGSBASE r64
	{ "rdgsbase", 0x4000, 0x039B8800, { 0x0F, 0xAE, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ) | FCML_OA_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ "rdgsbase", 0x4000, 0x049B8800, { 0x0F, 0xAE, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ) | FCML_OA_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RDRAND[] = {
	// 0F C7 /6 RDRAND r16
	// 0F C7 /6 RDRAND r32
	// REX.W + 0F C7 /6 RDRAND r64
	{ NULL, 0x0000, 0x00DBB000, { 0x0F, 0xC7, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_EOSA, FCML_EOS_UNDEFINED, FCML_RMF_R ) | FCML_OA_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RDTSCP[] = {
	// 0F 01 F9 RDTSCP
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xF9 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RDTSC[] = {
	// 0F 31 RDTSC
	{ NULL, 0x0000, 0x00D80000, { 0x0F, 0x31, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RDPMC[] = {
	// 0F 33 RDPMC
	{ NULL, 0x0000, 0x00D80000, { 0x0F, 0x33, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RDMSR[] = {
	// 0F 32 RDMSR
	{ NULL, 0x0000, 0x00D80000, { 0x0F, 0x32, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RET[] = {
	// C3 RET
	// CB RET
	{ NULL, 0x0000, 0x00C40000, { 0xC3, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ "retf", 0x0000, 0x00C40000, { 0xCB, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// C2 iw RET imm16
	// CA iw RET imm16
	{ NULL, 0x0000, 0x00C40000, { 0xC2, 0x00, 0x00 }, { FCML_OP_IW, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	{ "retf", 0x0000, 0x00C40000, { 0xCA, 0x00, 0x00 }, { FCML_OP_IW, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ROUNDPD[] = {
	// 66 0F 3A 09 /r ib ROUNDPD xmm1,xmm2/m128,imm8
	{ NULL, 0x1000, 0x00EC8000, { 0x0F, 0x3A, 0x09 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A.WIG 09 /r ib VROUNDPD xmm1,xmm2/m128,imm8
	// VEX.256.66.0F3A.WIG 09 /r ib VROUNDPD ymm1,ymm2/m256,imm8
	{ "vroundpd", 0x1180, 0x00EC8000, { 0x0F, 0x3A, 0x09 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ROUNDPS[] = {
	// 66 0F 3A 08 /r ib ROUNDPS xmm1,xmm2/m128,imm8
	{ NULL, 0x1000, 0x00EC8000, { 0x0F, 0x3A, 0x08 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A.WIG 08 /r ib VROUNDPS xmm1,xmm2/m128,imm8
	// VEX.256.66.0F3A.WIG 08 /r ib VROUNDPS ymm1,ymm2/m256,imm8
	{ "vroundps", 0x1180, 0x00EC8000, { 0x0F, 0x3A, 0x08 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ROUNDSD[] = {
	// 66 0F 3A 0B /r ib ROUNDSD xmm1,xmm2/m64,imm8
	{ NULL, 0x1000, 0x00EC8000, { 0x0F, 0x3A, 0x0B }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.LIG.66.0F3A.WIG 0B /r ib VROUNDSD xmm1,xmm2,xmm3/m64,imm8
	{ "vroundsd", 0x10C0, 0x00EC8000, { 0x0F, 0x3A, 0x0B }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_64, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ROUNDSS[] = {
	// 66 0F 3A 0A /r ib ROUNDSS xmm1,xmm2/m32,imm8
	{ NULL, 0x1000, 0x00EC8000, { 0x0F, 0x3A, 0x0A }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.LIG.66.0F3A.WIG 0A ib VROUNDSS xmm1,xmm2,xmm3/m32,imm8
	{ "vroundss", 0x10C0, 0x00EC8000, { 0x0F, 0x3A, 0x0A }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_32, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RSM[] = {
	// 0F AA RSM NP Invalid Valid Resume operation of interrupted program.
	{ NULL, 0x0000, 0x00580000, { 0x0F, 0xAA, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RSQRTPS[] = {
	// 0F 52 /r RSQRTPS xmm1,xmm2/m128
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0x52, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.0F.WIG 52 /r VRSQRTPS xmm1,xmm2/m128
	// VEX.256.0F.WIG 52 /r VRSQRTPS ymm1,ymm2/m256
	{ "vrsqrtps", 0x0180, 0x00D88000, { 0x0F, 0x52, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RSQRTSS[] = {
	// F3 0F 52 /r RSQRTSS xmm1,xmm2/m32
	{ NULL, 0x4000, 0x00D88000, { 0x0F, 0x52, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.LIG.F3.0F.WIG 52 /r VRSQRTSS xmm1,xmm2,xmm3/m32
	{ "vrsqrtss", 0x40C0, 0x00D88000, { 0x0F, 0x52, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SAHF[] = {
	// 9E SAHF
	// TODO: Narazie dostepne w 64 bit, ale generalnie dostepne w 64 bit tylko jezeli CPUID jest odpowiednio ustawiony.
	// Jzeli bedziemy dodawali mozliwosc parametryzacji wynikow debugera poprzez dostarczanie CPUID, to trzeba to bedzie obsluzyc.
	{ NULL, 0x0000, 0x00C40000, { 0x9E, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

// TODO: Zaimplementowac na cele assemblera dopiero. Jako ze tak samo sie koduje jak SHL.
// D0 /4 SAL r/m8, 1 M1 Valid Valid Multiply r/m8 by 2, once.
// REX + D0 /4 SAL r/m8**, 1 M1 Valid N.E. Multiply r/m8 by 2, once.
// D2 /4 SAL r/m8, CL MC Valid Valid Multiply r/m8 by 2, CL times.
// REX + D2 /4 SAL r/m8**, CL MC Valid N.E. Multiply r/m8 by 2, CL times.
// C0 /4 ib SAL r/m8, imm8 MI Valid Valid Multiply r/m8 by 2, imm8 times.
// REX + C0 /4 ib SAL r/m8**, imm8 MI Valid N.E. Multiply r/m8 by 2, imm8 times.
// D1 /4 SAL r/m16, 1 M1 Valid Valid Multiply r/m16 by 2, once.
// D1 /4 SAL r/m32, 1 M1 Valid Valid Multiply r/m32 by 2, once.
// REX.W + D1 /4 SAL r/m64, 1 M1 Valid N.E. Multiply r/m64 by 2, once.
// D3 /4 SAL r/m16, CL MC Valid Valid Multiply r/m16 by 2, CL times.
// D3 /4 SAL r/m32, CL MC Valid Valid Multiply r/m32 by 2, CL times.
// REX.W + D3 /4 SAL r/m64, CL MC Valid N.E. Multiply r/m64 by 2, CL times.
// C1 /4 ib SAL r/m16, imm8 MI Valid Valid Multiply r/m16 by 2, imm8 times.
// C1 /4 ib SAL r/m32, imm8 MI Valid Valid Multiply r/m32 by 2, imm8 times.
// REX.W + C1 /4 ib SAL r/m64, imm8 MI Valid N.E. Multiply r/m64 by 2, imm8 times.

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SAR[] = {
	// D0 /7 SAR r/m8, 1
	// REX + D0 /7 SAR r/m8
	{ NULL, 0x0000, 0x00C5B800, { 0xD0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D2 /7 SAR r/m8, CL MC Valid Valid Signed divide* r/m8 by 2, CL times.
	// REX + D2 /7 SAR r/m8**, CL MC Valid N.E. Signed divide* r/m8 by 2, CL times.
	{ NULL, 0x0000, 0x00C5B800, { 0xD2, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C0 /7 ib SAR r/m8, imm8 MI Valid Valid Signed divide* r/m8 by 2, imm8 time.
	// REX + C0 /7 ib SAR r/m8**, imm8 MI Valid N.E. Signed divide* r/m8 by 2, imm8 times.
	{ NULL, 0x0000, 0x00C5B800, { 0xC0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// D1 /7 SAR r/m16,1 M1 Valid Valid Signed divide* r/m16 by 2, once.
	// D1 /7 SAR r/m32, 1 M1 Valid Valid Signed divide* r/m32 by 2, once.
	// REX.W + D1 /7 SAR r/m64, 1 M1 Valid N.E. Signed divide* r/m64 by 2, once.
	{ NULL, 0x0000, 0x00C5B800, { 0xD1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D3 /7 SAR r/m16, CL MC Valid Valid Signed divide* r/m16 by 2, CL times.
	// D3 /7 SAR r/m32, CL MC Valid Valid Signed divide* r/m32 by 2, CL times.
	// REX.W + D3 /7 SAR r/m64, CL MC Valid N.E. Signed divide* r/m64 by 2, CL times.
	{ NULL, 0x0000, 0x00C5B800, { 0xD3, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C1 /7 ib SAR r/m16, imm8 MI Valid Valid Signed divide* r/m16 by 2, imm8 times.
	// C1 /7 ib SAR r/m32, imm8 MI Valid Valid Signed divide* r/m32 by 2, imm8 times.
	// REX.W + C1 /7 ib SAR r/m64, imm8 MI Valid N.E. Signed divide* r/m64 by 2, imm8 times
	{ NULL, 0x0000, 0x00C5B800, { 0xC1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SHL[] = {
	// D0 /4 SHL r/m8,1
	// REX + D0 /4 SHL r/m8,1
	{ NULL, 0x0000, 0x00C5A000, { 0xD0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D2 /4 SHL r/m8,CL
	// REX + D2 /4 SHL r/m8,CL
	{ NULL, 0x0000, 0x00C5A000, { 0xD2, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C0 /4 ib SHL r/m8,imm8
	// REX + C0 /4 ib SHL r/m8,imm8
	{ NULL, 0x0000, 0x00C5A000, { 0xC0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// D1 /4 SHL r/m16,1
	// D1 /4 SHL r/m32,1
	// REX.W + D1 /4 SHL r/m64,1
	{ NULL, 0x0000, 0x00C5A000, { 0xD1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D3 /4 SHL r/m16,CL
	// D3 /4 SHL r/m32,CL
	// REX.W + D3 /4 SHL r/m64,CL
	{ NULL, 0x0000, 0x00C5A000, { 0xD3, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C1 /4 ib SHL r/m16,imm8
	// C1 /4 ib SHL r/m32,imm8
	// REX.W + C1 /4 ib SHL r/m64,imm8
	{ NULL, 0x0000, 0x00C5A000, { 0xC1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SHR[] = {
	// D0 /5 SHR r/m8,1
	// REX + D0 /5 SHR r/m8,1
	{ NULL, 0x0000, 0x00C5A800, { 0xD0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D2 /5 SHR r/m8,CL
	// REX + D2 /5 SHR r/m8,CL
	{ NULL, 0x0000, 0x00C5A800, { 0xD2, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C0 /5 ib SHR r/m8,imm8
	// REX + C0 /5 ib SHR r/m8,imm8
	{ NULL, 0x0000, 0x00C5A800, { 0xC0, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// D1 /5 SHR r/m16,1
	// D1 /5 SHR r/m32,1
	// REX.W + D1 /5 SHR r/m64,1
	{ NULL, 0x0000, 0x00C5A800, { 0xD1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_IB(1), FCML_NA, FCML_NA, FCML_NA } },
	// D3 /5 SHR r/m16,CL
	// D3 /5 SHR r/m32,CL
	// REX.W + D3 /5 SHR r/m64,CL
	{ NULL, 0x0000, 0x00C5A800, { 0xD3, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA, FCML_NA } },
	// C1 /5 ib SHR r/m16,imm8
	// C1 /5 ib SHR r/m32,imm8
	// REX.W + C1 /5 ib SHR r/m64,imm8
	{ NULL, 0x0000, 0x00C5A800, { 0xC1, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SBB[] = {
	// 1C ib SBB AL,imm8
	{ NULL, 0x0001, 0x00C40000, { 0x1C, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 1D iw SBB AX,imm16
	// 1D id SBB EAX,imm32
	{ NULL, 0x0001, 0x00C40000, { 0x1D, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 1D id SBB RAX,imm32
	{ NULL, 0x0009, 0x00840000, { 0x1D, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 80 /3 ib SBB r/m8,imm8
	// REX + 80 /3 ib SBB r/m8,imm8
	{ NULL, 0x0001, 0x00C59800, { 0x80, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 81 /3 iw SBB r/m16,imm16
	// 81 /3 id SBB r/m32,imm32
	{ NULL, 0x0001, 0x00C59800, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 81 /3 id SBB r/m64,imm32
	{ NULL, 0x0009, 0x00859800, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 83 /3 ib SBB r/m16,imm8
	// 83 /3 ib SBB r/m32,imm8
	{ NULL, 0x0001, 0x00C59800, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 83 /3 ib SBB r/m64,imm8
	{ NULL, 0x0009, 0x00859800, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 18 /r SBB r/m8,r8
	// REX + 18 /r SBB r/m8,r8
	{ NULL, 0x0001, 0x00C48000, { 0x18, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_MODRM_R_8, FCML_NA, FCML_NA, FCML_NA } },
	// 19 /r SBB r/m16,r16
	// 19 /r SBB r/m32,r32
	// REX.W + 19 /r SBB r/m64,r64
	{ NULL, 0x0001, 0x00C48000, { 0x19, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
	// 1A /r SBB r8,r/m8
	// REX + 1A /r SBB r8,r/m8
	{ NULL, 0x0001, 0x00C48000, { 0x1A, 0x00, 0x00 }, { FCML_OP_MODRM_R_8_W, FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA } },
	// 1B /r SBB r16,r/m16
	// 1B /r SBB r32,r/m32
	// REX.W + 1B /r SBB r64,r/m64
	{ NULL, 0x0001, 0x00C48000, { 0x1B, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SCAS[] = {
	// AE SCAS m8 NP Valid Valid Compare AL with byte at ES:(E)DI or RDI, then set status flags.*
	{ NULL, 0x0001, 0x00C40000, { 0xAE, 0x00, 0x00 },
				{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_BYTE, FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ),
				FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// AF SCAS m16 NP Valid Valid Compare AX with word at ES:(E)DI or RDI, then set status flags.*
	// AF SCAS m32 NP Valid Valid Compare EAX with doubleword at ES(E)DI or RDI then set status flags.*
	// REX.W + AF SCAS m64 NP Valid N.E. Compare RAX with quadword at RDI or EDI then set status flags.
	{ NULL, 0x0001, 0x00C40000, { 0xAF, 0x00, 0x00 },
				{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_EOSA,FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ),
				FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
	// TODO: Assembler.
	// AE SCASB NP Valid Valid Compare AL with byte at ES:(E)DI or RDI then set status flags.*
	// AF SCASW NP Valid Valid Compare AX with word at ES:(E)DI or RDI then set status flags.*
	// AF SCASD NP Valid Valid Compare EAX with doubleword at ES:(E)DI or RDI then set status flags.*
	// REX.W + AF SCASQ NP Valid N.E. Compare RAX with quadword at RDI or EDI then set status flags.
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SETcc[] = {
	// 0F 97 SETA r/m8 M Valid Valid Set byte if above (CF=0 and ZF=0).
	// REX + 0F 97 SETA r/m8*
	{ NULL, 0x0001, 0x00D80040, { 0x0F, 0x97, 0x00 }, { FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SFENCE[] = {
	{ NULL, 0x0001, 0x00EC0000, { 0x0F, 0xAE, 0xF8 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SGDT[] = {
	// 0F 01 /0 SGDT m
	{ NULL, 0x0000, 0x00D98000, { 0x0F, 0x01, 0x00 }, { FCML_OP_MODRM_M_UNDEF, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SHLD[] = {
	// 0F A4 SHLD r/m16,r16,imm8 MRI Valid Valid Shift r/m16 to left imm8 places while shifting bits from r16 in from the right.
	// 0F A4 SHLD r/m32,r32,imm8 MRI Valid Valid Shift r/m32 to left imm8 places while shifting bits from r32 in from the right.
	// REX.W + 0F A4 SHLD r/m64,r64, imm8 MRI Valid N.E. Shift r/m64 to left imm8 places while shifting bits from r64 in from the right.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0xA4, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R,FCML_OP_IB, FCML_NA, FCML_NA } },
	// 0F A5 SHLD r/m16,r16,CL MRC Valid Valid Shift r/m16 to left CL places while shifting bits from r16 in from the right.
	// 0F A5 SHLD r/m32,r32,CL MRC Valid Valid Shift r/m32 to left CL places while shifting bits from r32 in from the right.
	// REX.W + 0F A5 SHLD r/m64,r64,CL MRC Valid N.E. Shift r/m64 to left CL places while shifting bits from r64 in from the right.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0xA5, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R,FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SHRD[] = {
	// 0F AC SHRD r/m16, r16, imm8 MRI Valid Valid Shift r/m16 to right imm8 places while shifting bits from r16 in from the left.
	// 0F AC SHRD r/m32, r32, imm8 MRI Valid Valid Shift r/m32 to right imm8 places while shifting bits from r32 in from the left.
	// REX.W + 0F AC SHRD r/m64, r64, imm8 MRI Valid N.E. Shift r/m64 to right imm8 places while shifting bits from r64 in from the left.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0xAC, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R,FCML_OP_IB, FCML_NA, FCML_NA } },
	// 0F AD SHRD r/m16, r16, CL MRC Valid Valid Shift r/m16 to right CL places while shifting bits from r16 in from the left.
	// 0F AD SHRD r/m32, r32, CL MRC Valid Valid Shift r/m32 to right CL places while shifting bits from r32 in from the left.
	// REX.W + 0F AD SHRD r/m64, r64, CL MRC Valid N.E. Shift r/m64 to right CL places while shifting bits from r64 in from the left.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0xAD, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R,FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_CL, FCML_EOS_BYTE ), FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SKINIT[] = {
	// SKINIT EAX 0F 01 DE Secure initialization and jump, with attestation.
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xDE }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_EAX, FCML_EOS_DWORD ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SLWPCB[] = {
	// SLWPCB reg32 8F RXB.09 0.1111.0.00 12 /1
	{ NULL, 0x0450, 0x00DB8800, { 0x09, 0x12, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// SLWPCB reg64 8F RXB.09 1.1111.0.00 12 /1
	{ NULL, 0x0448, 0x00DB8800, { 0x09, 0x12, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SHUFPD[] = {
	// 66 0F C6 /r ib SHUFPD xmm1, xmm2/m128, imm8 RMI V/V SSE2 Shuffle packed double-precision floatingpoint values selected by imm8 from xmm1 and xmm2/m128 to xmm1.
	{ NULL, 0x1000, 0x00D88000, { 0x0F, 0xC6, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG C6 /r ib VSHUFPD xmm1, xmm2, xmm3/m128, imm8 RVMI V/V AVX Shuffle Packed double-precision floatingpoint values selected by imm8 from xmm2 and xmm3/mem.
	// VEX.NDS.256.66.0F.WIG C6 /r ib VSHUFPD ymm1, ymm2, ymm3/m256, imm8 RVMI V/V AVX Shuffle Packed double-precision floatingpoint values selected by imm8 from ymm2 and ymm3/mem.
	{ "vshufpd", 0x1080, 0x00D88000, { 0x0F, 0xC6, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SHUFPS[] = {
	// 0F C6 /r ib SHUFPS xmm1, xmm2/m128, imm8 RMI V/V SSE Shuffle packed single-precision floating-point values selected by imm8 from xmm1 and xmm1/m128 to xmm1.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0xC6, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F.WIG C6 /r ib VSHUFPS xmm1, xmm2, xmm3/m128, imm8 RVMI V/V AVX Shuffle Packed single-precision floating-point values selected by imm8 from xmm2 and xmm3/mem.
	// VEX.NDS.256.0F.WIG C6 /r ib VSHUFPS ymm1, ymm2, ymm3/m256, imm8 RVMI V/V AVX Shuffle Packed single-precision floating-point values selected by imm8 from ymm2 and ymm3/mem.
	{ "vshufps", 0x0080, 0x00D88000, { 0x0F, 0xC6, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SIDT[] = {
	// 0F 01 /1 SIDT m M Valid Valid Store IDTR to m.
	{ NULL, 0x0000, 0x80D98800, { 0x0F, 0x01, 0x00 }, { FCML_OP_MODRM_M_UNDEF, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SLDT[] = {
	// 0F 00 /0 SLDT r/m16 M Valid Valid Stores segment selector from LDTR in r/m16.
	{ NULL, 0x0010, 0x03D98000, { 0x0F, 0x00, 0x00 }, { FCML_OP_MODRM_RM_16_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 0F 00 /0 SLDT r64/m16 M Valid Valid Stores segment selector from LDTR in r64/m16.
	{ NULL, 0x0008, 0x04998000, { 0x0F, 0x00, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_QWORD, FCML_EOS_WORD, FCML_RMF_RM ) | FCML_OA_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SMSW[] = {
	// 0F 01 /4 SMSW r/m16 M Valid Valid Store machine status word to r/m16.
	// 0F 01 /4 SMSW r32/m16 M Valid Valid Store machine status word in low-order 16 bits of r32/m16; high-order 16 bits of r32 are undefined.
	// REX.W + 0F 01 /4 SMSW r64/m16 M Valid Valid Store machine status word in low-order 16 bits of r64/m16; high-order 16 bits of r32 are undefined.
	{ NULL, 0x0000, 0x00D9A000, { 0x0F, 0x01, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_EOSA, FCML_EOS_WORD, FCML_RMF_RM ) | FCML_OA_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SQRTPD[] = {
	// 66 0F 51 /r SQRTPD xmm1,xmm2/m128
	{ NULL, 0x1000, 0x00D88000, { 0x0F, 0x51, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F.WIG 51 /r VSQRTPD xmm1,xmm2/m128
	// VEX.256.66.0F.WIG 51 /r VSQRTPD ymm1,ymm2/m256
	{ "vsqrtpd", 0x1180, 0x00D88000, { 0x0F, 0x51, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SQRTPS[] = {
	// 0F 51 /r SQRTPS xmm1,xmm2/m128 RM V/V SSE Computes square roots of the packed singleprecision floating-point values in xmm2/m128 and stores the results in xmm1.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0x51, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.0F.WIG 51 /r VSQRTPS xmm1,xmm2/m128 RM V/V AVX Computes Square Roots of the packed singleprecision floating-point values in xmm2/m128 and stores the result in xmm1.
	// VEX.256.0F.WIG 51 /r VSQRTPS ymm1,ymm2/m256 RM V/V AVX Computes Square Roots of the packed singleprecision floating-point values in ymm2/m256 and stores the result in ymm1.
	{ "vsqrtps", 0x0180, 0x00D88000, { 0x0F, 0x51, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SQRTSD[] = {
	// F2 0F 51 /r SQRTSD xmm1,xmm2/m64 RM V/V SSE2 Computes square root of the low doubleprecision floating-point value in xmm2/m64 and stores the results in xmm1.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0x51, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.LIG.F2.0F.WIG 51 /r VSQRTSD xmm1,xmm2,xmm3/m64 RVM V/V AVX Computes square root of the low doubleprecision floating point value in xmm3/m64 and stores the results in xmm2. Also, upper double precision floating-point value (bits[127:64]) from xmm2 is copied to xmm1[127:64].
	{ "vsqrtsd", 0x20C0, 0x00D88000, { 0x0F, 0x51, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SQRTSS[] = {
	// F3 0F 51 /r SQRTSS xmm1, xmm2/m32 RM V/V SSE Computes square root of the low singleprecision floating-point value in xmm2/m32 and stores the results in xmm1.
	{ NULL, 0x4000, 0x00D88000, { 0x0F, 0x51, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.LIG.F3.0F.WIG 51 VSQRTSS xmm1, xmm2, xmm3/m32 RVM V/V AVX Computes square root of the low singleprecision floating-point value in xmm3/m32 and stores the results in xmm1. Also, upper single precision floating-point values (bits[127:32]) from xmm2 are copied to xmm1[127:32].
	{ "vsqrtss", 0x40C0, 0x00D88000, { 0x0F, 0x51, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_32, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_STC[] = {
	// F9 STC NP Valid Valid Set CF flag.
	{ NULL, 0x0000, 0x00C40000, { 0xF9, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_STD[] = {
	// FD STD NP Valid Valid Set DF flag.
	{ NULL, 0x0000, 0x00C40000, { 0xFD, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_STGI[] = {
	// STGI 0F 01 DC Sets the global interrupt flag (GIF).
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xDC }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_STI[] = {
	// FB STI NP Valid Valid Set interrupt flag; external, maskable interrupts enabled at the end of the next instruction.
	{ NULL, 0x0000, 0x00C40000, { 0xFB, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_STMXCSR[] = {
	// 0F AE /3 STMXCSR m32 M V/V SSE Store contents of MXCSR register to m32.
	{ NULL, 0x0000, 0x80D99800, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.LZ.0F.WIG AE /3 VSTMXCSR m32 M V/V AVX Store contents of MXCSR register to m32.
	{ "vstmxcsr", 0x01C0, 0x80D99800, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_32, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_STOS[] = {
	// AA STOS m8 NA Valid Valid For legacy mode, store AL at address ES:(E)DI; For 64-bit mode store AL at address RDI or EDI.
	{ NULL, 0x0001, 0x00C40000, { 0xAA, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_SI, FCML_EOS_BYTE, FCML_SEG_ENCODE_REGISTER( FCML_REG_DS, FCML_SEG_ALLOW_OVERRIDE ) ),
			FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_BYTE, FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ),
			FCML_NA, FCML_NA, FCML_NA } },
	// AB STOS m16 NA Valid Valid For legacy mode, store AX at address ES:(E)DI; For 64-bit mode store AX at address RDI or EDI.
	// AB STOS m32 NA Valid Valid For legacy mode, store EAX at address ES:(E)DI; For 64-bit mode store EAX at address RDI or EDI.
	// REX.W + AB STOS m64 NA Valid N.E. Store RAX at address RDI or EDI.
	{ NULL, 0x0001, 0x00C40000, { 0xAB, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_SI, FCML_EOS_EOSA,FCML_SEG_ENCODE_REGISTER( FCML_REG_DS, FCML_SEG_ALLOW_OVERRIDE ) ),
			FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_DI, FCML_EOS_EOSA,FCML_SEG_ENCODE_REGISTER( FCML_REG_ES, FCML_SEG_DENY_OVERRIDE ) ),
			FCML_NA, FCML_NA, FCML_NA } }
	// AA STOSB NA Valid Valid For legacy mode, store AL at address ES:(E)DI; For 64-bit mode store AL at address RDI or EDI.
	// AB STOSW NA Valid Valid For legacy mode, store AX at address ES:(E)DI; For 64-bit mode store AX at address RDI or EDI.
	// AB STOSD NA Valid Valid For legacy mode, store EAX at address ES:(E)DI; For 64-bit mode store EAX at address RDI or EDI.
	// REX.W + AB STOSQ NA Valid N.E. Store RAX at address RDI or EDI.
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_STR[] = {
	// 0F 00 /1 STR r/m16 M Valid Valid Stores segment selector from TR in r/m16.
	{ NULL, 0x0000, 0x00D98800, { 0x0F, 0x00, 0x00 }, { FCML_OP_MODRM_RM_16_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SUB[] = {
	// 2C ib SUB AL, imm8 I Valid Valid Subtract imm8 from AL.
	{ NULL, 0x0001, 0x00C40000, { 0x2C, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 2D iw SUB AX, imm16 I Valid Valid Subtract imm16 from AX.
	// 2D id SUB EAX, imm32 I Valid Valid Subtract imm32 from EAX.
	{ NULL, 0x0001, 0x00C40000, { 0x2D, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 2D id SUB RAX, imm32 I Valid N.E. Subtract imm32 sign-extended to 64-bits from RAX.
	{ NULL, 0x0009, 0x00840000, { 0x2D, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 80 /5 ib SUB r/m8, imm8 MI Valid Valid Subtract imm8 from r/m8.
	// REX + 80 /5 ib SUB r/m8*, imm8 MI Valid N.E. Subtract imm8 from r/m8.
	{ NULL, 0x0001, 0x00C5A800, { 0x80, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 81 /5 iw SUB r/m16, imm16 MI Valid Valid Subtract imm16 from r/m16.
	// 81 /5 id SUB r/m32, imm32 MI Valid Valid Subtract imm32 from r/m32.
	{ NULL, 0x0001, 0x00C5A800, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 81 /5 id SUB r/m64, imm32 MI Valid N.E. Subtract imm32 sign-extended to 64-bits from r/m64.
	{ NULL, 0x0009, 0x0085A800, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 83 /5 ib SUB r/m16, imm8 MI Valid Valid Subtract sign-extended imm8 from r/m16.
	// 83 /5 ib SUB r/m32, imm8 MI Valid Valid Subtract sign-extended imm8 from r/m32.
	{ NULL, 0x0001, 0x00C5A800, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 83 /5 ib SUB r/m64, imm8 MI Valid N.E. Subtract sign-extended imm8 from r/m64.
	{ NULL, 0x0009, 0x0085A800, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 28 /r SUB r/m8, r8 MR Valid Valid Subtract r8 from r/m8.
	// REX + 28 /r SUB r/m8*, r8* MR Valid N.E. Subtract r8 from r/m8.
	{ NULL, 0x0001, 0x00C48000, { 0x28, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_MODRM_R_8, FCML_NA, FCML_NA, FCML_NA } },
	// 29 /r SUB r/m16, r16 MR Valid Valid Subtract r16 from r/m16.
	// 29 /r SUB r/m32, r32 MR Valid Valid Subtract r32 from r/m32.
	// REX.W + 29 /r SUB r/m64, r32 MR Valid N.E. Subtract r64 from r/m64.
	{ NULL, 0x0001, 0x00C48000, { 0x29, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
	// 2A /r SUB r8, r/m8 RM Valid Valid Subtract r/m8 from r8.
	// REX + 2A /r SUB r8*, r/m8* RM Valid N.E. Subtract r/m8 from r8.
	{ NULL, 0x0001, 0x00C48000, { 0x2A, 0x00, 0x00 }, { FCML_OP_MODRM_R_8_W, FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA } },
	// 2B /r SUB r16, r/m16 RM Valid Valid Subtract r/m16 from r16.
	// 2B /r SUB r32, r/m32 RM Valid Valid Subtract r/m32 from r32.
	// REX.W + 2B /r SUB r64, r/m64 RM Valid N.E. Subtract r/m64 from r64.
	{ NULL, 0x0001, 0x00C48000, { 0x2B, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_T1MSKC[] = {
	// T1MSKC reg32, reg/mem32 8F RXB.09 0.dest.0.00 01 /7
	{ NULL, 0x0450, 0x00D9B800, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// T1MSKC reg64, reg/mem64 8F RXB.09 1.dest.0.00 01 /7
	{ NULL, 0x0448, 0x00D9B800, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SUBPD[] = {
	// 66 0F 5C /r SUBPD xmm1,xmm2/m128 RM V/V SSE2 Subtract packed double-precision floatingpoint values in xmm2/m128 from xmm1.
	{ NULL, 0x1000, 0x00D88000, { 0x0F, 0x5C, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 5C /r VSUBPD xmm1,xmm2,xmm3/m128 RVM V/V AVX Subtract packed double-precision floatingpoint values in xmm3/mem from xmm2 and stores result in xmm1.
	// VEX.NDS.256.66.0F.WIG 5C /r VSUBPD ymm1,ymm2,ymm3/m256 RVM V/V AVX Subtract packed double-precision floatingpoint values in ymm3/mem from ymm2 and stores result in ymm1.	_TEST32_VEX( "c4e149c6140120 vshufpd xmm2,xmm6,oword ptr [ecx+eax],20h", 0xC4, 0xE1, 0x49, 0xC6, 0x14, 0x01, 0x20 );
	{ "vsubpd", 0x1080, 0x00D88000, { 0x0F, 0x5C, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SUBPS[] = {
	// 0F 5C /r SUBPS xmm1,xmm2/m128 RM V/V SSE Subtract packed single-precision floating-point values in xmm2/mem from xmm1.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0x5C, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F.WIG 5C /r VSUBPS xmm1,xmm2,xmm3/m128 RVM V/V AVX Subtract packed single-precision floating-point values in xmm3/mem from xmm2 and stores result in xmm1.
	// VEX.NDS.256.0F.WIG 5C /r VSUBPS ymm1,ymm2,ymm3/m256 RVM V/V AVX Subtract packed single-precision floating-point values in ymm3/mem from ymm2 and stores result in ymm1.
	{ "vsubps", 0x0080, 0x00D88000, { 0x0F, 0x5C, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SUBSD[] = {
	// F2 0F 5C /r SUBSD xmm1,xmm2/m64 RM V/V SSE2 Subtracts the low double-precision floatingpoint values in xmm2/mem64 from xmm1.
	{ NULL, 0x2001, 0x00D88000, { 0x0F, 0x5C, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.LIG.F2.0F.WIG 5C /r VSUBSD xmm1,xmm2,xmm3/m64 RVM V/V AVX Subtract the low double-precision floatingpoint value in xmm3/mem from xmm2 and store the result in xmm1.
	{ "vsubsd", 0x20C0, 0x00D88000, { 0x0F, 0x5C, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_64, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SUBSS[] = {
	// F3 0F 5C /r SUBSS xmm1,xmm2/m32
	{ NULL, 0x4001, 0x00D88000, { 0x0F, 0x5C, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.LIG.F3.0F.WIG 5C /r VSUBSS xmm1,xmm2,xmm3/m32
	{ "vsubss", 0x40C0, 0x00D88000, { 0x0F, 0x5C, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L_32, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SWAPGS[] = {
	// 0F 01 F8 SWAPGS NP Valid Invalid Exchanges the current GS base register value with the value contained in MSR address C0000102H.
	{ NULL, 0x0000, 0x00AC0000, { 0x0F, 0x01, 0xF8 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SYSCALL[] = {
	// 0F 05 SYSCALL NP Valid Invalid Fast call to privilege level 0 system procedures.
	{ NULL, 0x0000, 0x00980000, { 0x0F, 0x05, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SYSENTER[] = {
	// 0F 34 SYSENTER NP Valid Valid Fast call to privilege level 0 system procedures.
	{ NULL, 0x0000, 0x00D80000, { 0x0F, 0x34, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SYSEXIT[] = {
	// 0F 35 SYSEXIT NP Valid Valid Fast return to privilege level 3 user code.
	// REX.W + 0F 35 SYSEXIT NP Valid Valid Fast return to 64-bit mode privilege level 3 user code.
	// TODO: Rozdzielic przy assemblerze, patrz opis. Zastoowac mnemonke sysexit64
	{ NULL, 0x0000, 0x00D80000, { 0x0F, 0x35, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SYSRET[] = {
	// 0F 07 SYSRET NP Valid Invalid Return to compatibility mode from fast system call
	// REX.W + 0F 07 SYSRET NP Valid Invalid Return to 64-bit mode from fast system call
	// TODO: Rozdzielic przy assemblerze, patrz opis. Zastoowac mnemonke sysret64
	{ NULL, 0x0000, 0x00980000, { 0x0F, 0x07, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_TEST[] = {
	// A8 ib TEST AL, imm8 I Valid Valid AND imm8 with AL; set SF, ZF, PF according to result.
	{ NULL, 0x0001, 0x00C40000, { 0xA8, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// A9 iw TEST AX, imm16 I Valid Valid AND imm16 with AX; set SF, ZF, PF according to result.
	// A9 id TEST EAX, imm32 I Valid Valid AND imm32 with EAX; set SF, ZF, PF according to result.
	{ NULL, 0x0001, 0x00C40000, { 0xA9, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + A9 id TEST RAX, imm32 I Valid N.E. AND imm32 sign-extended to 64-bits with RAX; set SF, ZF, PF according to result.
	{ NULL, 0x0009, 0x00840000, { 0xA9, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// F6 /0 ib TEST r/m8, imm8 MI Valid Valid AND imm8 with r/m8; set SF, ZF, PF according to result.
	// REX + F6 /0 ib TEST r/m8*, imm8 MI Valid N.E. AND imm8 with r/m8; set SF, ZF, PF according to result.
	{ NULL, 0x0001, 0x00C58000, { 0xF6, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// F7 /0 iw TEST r/m16, imm16 MI Valid Valid AND imm16 with r/m16; set SF, ZF, PF according to result.
	// F7 /0 id TEST r/m32, imm32 MI Valid Valid AND imm32 with r/m32; set SF, ZF, PF according to result.
	{ NULL, 0x0001, 0x00C58000, { 0xF7, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + F7 /0 id TEST r/m64, imm32 MI Valid N.E. AND imm32 sign-extended to 64-bits with r/m64; set SF, ZF, PF according to result.
	{ NULL, 0x0009, 0x00858000, { 0xF7, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 84 /r TEST r/m8, r8 MR Valid Valid AND r8 with r/m8; set SF, ZF, PF according to result.
	// REX + 84 /r TEST r/m8*, r8* MR Valid N.E. AND r8 with r/m8; set SF, ZF, PF according to result.
	{ NULL, 0x0001, 0x00C48000, { 0x84, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_MODRM_R_8, FCML_NA, FCML_NA, FCML_NA } },
	// 85 /r TEST r/m16, r16 MR Valid Valid AND r16 with r/m16; set SF, ZF, PF according to result.
	// 85 /r TEST r/m32, r32 MR Valid Valid AND r32 with r/m32; set SF, ZF, PF according to result.
	// REX.W + 85 /r TEST r/m64, r64 MR Valid N.E. AND r64 with r/m64; set SF, ZF, PF according to result.
	{ NULL, 0x0001, 0x00C48000, { 0x85, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_UCOMISD[] = {
	// 66 0F 2E /r UCOMISD xmm1,xmm2/m64 RM V/V SSE2 Compares (unordered) the low doubleprecision floating-point values in xmm1 and xmm2/m64 and set the EFLAGS accordingly.
	{ NULL, 0x1000, 0x00D88000, { 0x0F, 0x2E, 0x00 }, { FCML_OP_MODRM_R_XMM, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.LIG.66.0F.WIG 2E /r VUCOMISD xmm1,xmm2/m64 RM V/V AVX Compare low double precision floating-point values in xmm1 and xmm2/mem64 and set the EFLAGS flags accordingly.
	{ "vucomisd", 0x11C0, 0x00D88000, { 0x0F, 0x2E, 0x00 }, { FCML_OP_MODRM_R_XMM, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_UCOMISS[] = {
	// 0F 2E /r UCOMISS xmm1,xmm2/m32 RM V/V SSE Compare lower single-precision floating-point value in xmm1 register with lower singleprecision floating-point value in xmm2/mem and set the status flags accordingly.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0x2E, 0x00 }, { FCML_OP_MODRM_R_XMM, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.LIG.0F.WIG 2E /r VUCOMISS xmm1,xmm2/m32 RM V/V AVX Compare low single precision floating-point values in xmm1 and xmm2/mem32 and set the EFLAGS flags accordingly.
	{ "vucomiss", 0x01C0, 0x00D88000, { 0x0F, 0x2E, 0x00 }, { FCML_OP_MODRM_R_XMM, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_UD2[] = {
	// 0F 0B UD2 NP Valid Valid Raise invalid opcode exception.
	{ NULL, 0x0000, 0x00D80000, { 0x0F, 0x0B, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_UNPCKHPD[] = {
	// 66 0F 15 /r UNPCKHPD xmm1,xmm2/m128 RM V/V SSE2 Unpacks and Interleaves double-precision floating-point values from high quadwords of xmm1 and xmm2/m128.
	{ NULL, 0x1000, 0x00D88000, { 0x0F, 0x15, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 15 /r VUNPCKHPD xmm1,xmm2,xmm3/m128 RVM V/V AVX Unpacks and Interleaves double precision floating-point values from high quadwords of xmm2 and xmm3/m128.
	// VEX.NDS.256.66.0F.WIG 15 /r VUNPCKHPD ymm1,ymm2,ymm3/m256 RVM V/V AVX Unpacks and Interleaves double precision floating-point values from high quadwords of ymm2 and ymm3/m256.
	{ "vunpckhpd", 0x1080, 0x00D88000, { 0x0F, 0x15, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_UNPCKHPS[] = {
	// 0F 15 /r UNPCKHPS xmm1, xmm2/m128 RM V/V SSE Unpacks and Interleaves single-precision floating-point values from high quadwords of xmm1 and xmm2/mem into xmm1.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0x15, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F.WIG 15 /r VUNPCKHPS xmm1,xmm2, xmm3/m128 RVM V/V AVX Unpacks and Interleaves single-precision floating-point values from high quadwords of xmm2 and xmm3/m128.
	// VEX.NDS.256.0F.WIG 15 /r VUNPCKHPS ymm1,ymm2,ymm3/m256 RVM V/V AVX Unpacks and Interleaves single-precision floating-point values from high quadwords of ymm2 and ymm3/m256.
	{ "vunpckhps", 0x0080, 0x00D88000, { 0x0F, 0x15, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_UNPCKLPD[] = {
	// 66 0F 14 /r UNPCKLPD xmm1, xmm2/m128 RM V/V SSE2 Unpacks and Interleaves double-precision floating-point values from low quadwords of xmm1 and xmm2/m128.
	{ NULL, 0x1000, 0x00D88000, { 0x0F, 0x14, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 14 /r VUNPCKLPD xmm1,xmm2, xmm3/m128 RVM V/V AVX Unpacks and Interleaves double precision floating-point values low high quadwords of xmm2 and xmm3/m128.
	// VEX.NDS.256.66.0F.WIG 14 /r VUNPCKLPD ymm1,ymm2, ymm3/m256 RVM V/V AVX Unpacks and Interleaves double precision floating-point values low high quadwords of ymm2 and ymm3/m256.
	{ "vunpcklpd", 0x1080, 0x00D88000, { 0x0F, 0x14, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_UNPCKLPS[] = {
	// 0F 14 /r UNPCKLPS xmm1, xmm2/m128 RM V/V SSE Unpacks and Interleaves single-precision floating-point values from low quadwords of xmm1 and xmm2/mem into xmm1.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0x14, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F.WIG 14 /r VUNPCKLPS xmm1,xmm2, xmm3/m128 RVM V/V AVX Unpacks and Interleaves single-precision floating-point values from low quadwords of xmm2 and xmm3/m128.
	// VEX.NDS.256.0F.WIG 14 /r VUNPCKLPS ymm1,ymm2,ymm3/m256 RVM V/V AVX Unpacks and Interleaves single-precision floating-point values from low quadwords of ymm2 and ymm3/m256.
	{ "vunpcklps", 0x0080, 0x00D88000, { 0x0F, 0x14, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VCVTPH2PS[] = {
	// VEX.128.66.0F38.W0 13 /r VCVTPH2PS xmm1,xmm2/m64 RM V/V F16C Convert four packed half precision (16-bit) floating-point values in xmm2/m64 to packed single-precision floating-point value in xmm1.
	{ NULL, 0x11D0, 0x00EC8000, { 0x0F, 0x38, 0x13 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.256.66.0F38.W0 13 /r VCVTPH2PS ymm1,xmm2/m128 RM V/V F16C Convert eight packed half precision (16-bit) floating-point values in xmm2/m128 to packed single-precision floating-point value in ymm1.
	{ NULL, 0x11B0, 0x00EC8000, { 0x0F, 0x38, 0x13 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VCVTPS2PH[] = {
	// VEX.128.66.0F3A.W0.1D /r VCVTPS2PH xmm1/m64,xmm2,imm8 ib MR V/V F16C Convert four packed single-precision floating-point value in xmm2 to packed halfprecision (16-bit) floating-point value in xmm1/mem. Imm8 provides rounding controls.
	{ NULL, 0x11D0, 0x00EC8000, { 0x0F, 0x3A, 0x1D }, { FCML_OP_MODRM_RM_XMM_64_W, FCML_OP_MODRM_R_XMM, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.256.66.0F3A.W0 1D /r VCVTPS2PH xmm1/m128,ymm2,imm8 ib MR V/V F16C Convert eight packed single-precision floating-point value in ymm2 to packed half-precision (16-bit) floating-point value in xmm1/mem. Imm8 provides rounding controls.
	{ NULL, 0x11B0, 0x00EC8000, { 0x0F, 0x3A, 0x1D }, { FCML_OP_MODRM_RM_XMM_128_W, FCML_OP_MODRM_R_XMM, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VERR[] = {
	// 0F 00 /4 VERR r/m16 M Valid Valid Set ZF=1 if segment specified with r/m16 can be read.
	{ NULL, 0x0000, 0x00D9A000, { 0x0F, 0x00, 0x00 }, { FCML_OP_MODRM_RM_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VERW[] = {
	// 0F 00 /5 VERW r/m16 M Valid Valid Set ZF=1 if segment specified with r/m16 can be written.
	{ NULL, 0x0000, 0x00D9A800, { 0x0F, 0x00, 0x00 }, { FCML_OP_MODRM_RM_16, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VMLOAD[] = {
	// VMLOAD rAX 0F 01 DA Load additional state from VMCB.
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xDA }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_EAX, FCML_EOS_EASA ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VMMCALL[] = {
	// VMMCALL 0F 01 D9 Explicit communication with the VMM.
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xD9 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VMRUN[] = {
	// VMRUN rAX 0F 01 D8 Performs a world-switch to guest.
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xD8 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_EAX, FCML_EOS_EASA ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VMSAVE[] = {
	// VMSAVE rAX 0F 01 DB Save additional guest state to VMCB.
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xDB }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_EAX, FCML_EOS_EASA ), FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPERMILPD[] = {
	// VEX.NDS.128.66.0F38.W0 0D /r VPERMILPD xmm1,xmm2,xmm3/m128 RVM V/V AVX Permute double-precision floating-point values in xmm2 using controls from xmm3/mem and store result in xmm1.
	// VEX.NDS.256.66.0F38.W0 0D /r VPERMILPD ymm1,ymm2,ymm3/m256 RVM V/V AVX Permute double-precision floating-point values in ymm2 using controls from ymm3/mem and store result in ymm1.
	{ NULL, 0x1090, 0x00EC8000, { 0x0F, 0x38, 0x0D }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A.W0 05 /r ib VPERMILPD xmm1,xmm2/m128,imm8 RMI V/V AVX Permute double-precision floating-point values in xmm2/mem using controls from imm8.
	// VEX.256.66.0F3A.W0 05 /r ib VPERMILPD ymm1,ymm2/m256,imm8 RMI V/V AVX Permute double-precision floating-point values in ymm2/mem using controls from imm8.
	{ NULL, 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x05 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPERMILPS[] = {
	// VEX.NDS.128.66.0F38.W0 0C /r VPERMILPS xmm1,xmm2,xmm3/m128 RVM V/V AVX Permute single-precision floating-point values in xmm2 using controls from xmm3/mem and store result in xmm1.
	// VEX.NDS.256.66.0F38.W0 0C /r VPERMILPS ymm1,ymm2,ymm3/m256 RVM V/V AVX Permute single-precision floating-point values in ymm2 using controls from ymm3/mem and store result in ymm1.
	{ NULL, 0x1090, 0x00EC8000, { 0x0F, 0x38, 0x0C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.128.66.0F3A.W0 04 /r ib VPERMILPS xmm1,xmm2/m128,imm8 RMI V/V AVX Permute single-precision floating-point values in xmm2/mem using controls from imm8 and store result in xmm1.
	// VEX.256.66.0F3A.W0 04 /r ib VPERMILPS ymm1,ymm2/m256,imm8 RMI V/V AVX Permute single-precision floating-point values in ymm2/mem using controls from imm8 and store result in ymm1.
	{ NULL, 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x04 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPSLLVD[] = {
	// VEX.NDS.128.66.0F38.W0 47 /r VPSLLVD xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F38.W0 47 /r VPSLLVD ymm1,ymm2,ymm3/m256
	{ NULL, 0x1090, 0x00EC8000, { 0x0F, 0x38, 0x47 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.W1 47 /r VPSLLVQ xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F38.W1 47 /r VPSLLVQ ymm1,ymm2,ymm3/m256
	{ "vpsllvq", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0x47 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPSRLVD[] = {
	// VEX.NDS.128.66.0F38.W0 45 /r VPSRLVD xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F38.W0 45 /r VPSRLVD ymm1,ymm2,ymm3/m256
	{ NULL, 0x1090, 0x00EC8000, { 0x0F, 0x38, 0x45 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F38.W1 45 /r VPSRLVQ xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F38.W1 45 /r VPSRLVQ ymm1,ymm2,ymm3/m256
	{ "vpsrlvq", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0x45 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPSRAVD[] = {
	// VEX.NDS.128.66.0F38.W0 46 /r VPSRAVD xmm1,xmm2,xmm3/m128
	// VEX.NDS.256.66.0F38.W0 46 /r VPSRAVD ymm1,ymm2,ymm3/m256
	{ NULL, 0x1090, 0x00EC8000, { 0x0F, 0x38, 0x46 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPERMD[] = {
	// VEX.NDS.256.66.0F38.W0 36 /r VPERMD ymm1,ymm2,ymm3/m256
	{ NULL, 0x10B0, 0x00EC8000, { 0x0F, 0x38, 0x36 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPERMPD[] = {
	// VEX.256.66.0F3A.W1 01 /r ib VPERMPD ymm1,ymm2/m256,imm8
	{ NULL, 0x11A8, 0x00EC8000, { 0x0F, 0x3A, 0x01 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_YMM_256, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPERMQ[] = {
	// VEX.256.66.0F3A.W1 00 /r ib VPERMQ ymm1,ymm2/m256,imm8
	{ NULL, 0x11A8, 0x00EC8000, { 0x0F, 0x3A, 0x00 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_MODRM_RM_YMM_256, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPERMPS[] = {
	// VEX.NDS.256.66.0F38.W0 16 /r VPERMPS ymm1,ymm2,ymm3/m256
	{ NULL, 0x10B0, 0x00EC8000, { 0x0F, 0x38, 0x16 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPERM2F128[] = {
	// VEX.NDS.256.66.0F3A.W0 06 /r ib VPERM2F128 ymm1,ymm2,ymm3/m256,imm8 RVMI V/V AVX Permute 128-bit floating-point fields in ymm2 and ymm3/mem using controls from imm8 and store result in ymm1.
	{ NULL, 0x10B0, 0x00EC8000, { 0x0F, 0x3A, 0x06 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPERM2I128[] = {
	// VEX.NDS.256.66.0F3A.W0 46 /r ib VPERM2I128 ymm1,ymm2,ymm3/m256,imm8
	{ NULL, 0x10B0, 0x00EC8000, { 0x0F, 0x3A, 0x46 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VEXTRACTI128[] = {
	// VEX.256.66.0F3A.W0 39 /r ib VEXTRACTI128 xmm1/m128,ymm2,imm8
	{ NULL, 0x11B0, 0x00EC8000, { 0x0F, 0x3A, 0x39 }, { FCML_OP_MODRM_RM_XMM_128_W, FCML_OP_MODRM_R_YMM, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VINSERTI128[] = {
	// VEX.NDS.256.66.0F3A.W0 38 /r ib VINSERTI128 ymm1,ymm2,xmm3/m128,imm8
	{ NULL, 0x10B0, 0x00EC8000, { 0x0F, 0x3A, 0x38 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_YMM_256, FCML_OP_IB, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VTESTPS[] = {
	// VEX.128.66.0F38.W0 0E /r VTESTPS xmm1,xmm2/m128 RM V/V AVX Set ZF and CF depending on sign bit AND and ANDN of packed single-precision floatingpoint sources.
	// VEX.256.66.0F38.W0 0E /r VTESTPS ymm1,ymm2/m256 RM V/V AVX Set ZF and CF depending on sign bit AND and ANDN of packed single-precision floatingpoint sources.
	{ NULL, 0x1190, 0x00EC8000, { 0x0F, 0x38, 0x0E }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.128.66.0F38.W0 0F /r VTESTPD xmm1,xmm2/m128 RM V/V AVX Set ZF and CF depending on sign bit AND and ANDN of packed double-precision floatingpoint sources.
	// VEX.256.66.0F38.W0 0F /r VTESTPD ymm1,ymm2/m256 RM V/V AVX Set ZF and CF depending on sign bit AND and ANDN of packed double-precision floatingpoint sources.
	{ "vtestpd", 0x1190, 0x00EC8000, { 0x0F, 0x38, 0x0F }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VGATHERDPD[] = {
	// VEX.DDS.128.66.0F38.W1 92 /r VGATHERDPD xmm1, vm32x, xmm2
	// VEX.DDS.256.66.0F38.W1 92 /r VGATHERDPD ymm1, vm32x, ymm2
	{ NULL, 0x1088, 0x00EC8000, { 0x0F, 0x38, 0x92 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VSIB(FCML_VSIB_XMM,FCML_VSIB_IS_32), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 93 /r VGATHERQPD xmm1, vm64x, xmm2
	{ "vgatherqpd", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0x93 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VSIB(FCML_VSIB_XMM,FCML_VSIB_IS_64), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } },
	// VEX.DDS.256.66.0F38.W1 93 /r VGATHERQPD ymm1, vm64y, ymm2
	{ "vgatherqpd", 0x10A8, 0x00EC8000, { 0x0F, 0x38, 0x93 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VSIB(FCML_VSIB_YMM,FCML_VSIB_IS_64), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VGATHERDPS[] = {
	// VEX.DDS.128.66.0F38.W0 92 /r VGATHERDPS xmm1,vm32x,xmm2
	{ NULL, 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0x92 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VSIB(FCML_VSIB_XMM,FCML_VSIB_IS_32), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } },
	// VEX.DDS.256.66.0F38.W0 92 /r VGATHERDPS ymm1,vm32y,ymm2
	{ NULL, 0x10B0, 0x00EC8000, { 0x0F, 0x38, 0x92 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VSIB(FCML_VSIB_YMM,FCML_VSIB_IS_32), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 93 /r VGATHERQPS xmm1,vm64x,xmm2
	{ "vgatherqps", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0x93 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VSIB(FCML_VSIB_XMM,FCML_VSIB_IS_64), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } },
	// VEX.DDS.256.66.0F38.W0 93 /r VGATHERQPS xmm1,vm64y,xmm2
	{ "vgatherqps", 0x10B0, 0x00EC8000, { 0x0F, 0x38, 0x93 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VSIB(FCML_VSIB_YMM,FCML_VSIB_IS_64), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPGATHERDD[] = {
	// VEX.DDS.128.66.0F38.W0 90 /r VPGATHERDD xmm1,vm32x,xmm2
	{ NULL, 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0x90 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VSIB(FCML_VSIB_XMM,FCML_VSIB_IS_32), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } },
	// VEX.DDS.256.66.0F38.W0 90 /r VPGATHERDD ymm1,vm32y,ymm2
	{ NULL, 0x10B0, 0x00EC8000, { 0x0F, 0x38, 0x90 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VSIB(FCML_VSIB_YMM,FCML_VSIB_IS_32), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 91 /r VPGATHERQD xmm1,vm64x,xmm2
	{ "vpgatherqd", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0x91 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VSIB(FCML_VSIB_XMM,FCML_VSIB_IS_64), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } },
	// VEX.DDS.256.66.0F38.W0 91 /r VPGATHERQD xmm1,vm64y,xmm2
	{ "vpgatherqd", 0x10B0, 0x00EC8000, { 0x0F, 0x38, 0x91 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VSIB(FCML_VSIB_YMM,FCML_VSIB_IS_64), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPGATHERDQ[] = {
	// VEX.DDS.128.66.0F38.W1 90 /r VPGATHERDQ xmm1,vm32x,xmm2
	// VEX.DDS.256.66.0F38.W1 90 /r VPGATHERDQ ymm1,vm32x,ymm2
	{ NULL, 0x1088, 0x00EC8000, { 0x0F, 0x38, 0x90 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VSIB(FCML_VSIB_XMM,FCML_VSIB_IS_32), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 91 /r VPGATHERQQ xmm1,vm64x,xmm2
	{ "vpgatherqq", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0x91 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VSIB(FCML_VSIB_XMM,FCML_VSIB_IS_64), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } },
	// VEX.DDS.256.66.0F38.W1 91 /r VPGATHERQQ ymm1,vm64y,ymm2
	{ "vpgatherqq", 0x10A8, 0x00EC8000, { 0x0F, 0x38, 0x91 }, { FCML_OP_MODRM_R_YMM_W, FCML_OP_VSIB(FCML_VSIB_YMM,FCML_VSIB_IS_64), FCML_OP_VEX_VVVV_SIMD_REG, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VZEROALL[] = {
	// VEX.256.0F.WIG 77 VZEROALL NP V/V AVX Zero all YMM registers.
	{ NULL, 0x01A0, 0x00D80000, { 0x0F, 0x77, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VZEROUPPER[] = {
	// VEX.128.0F.WIG 77 VZEROUPPER NP V/V AVX Zero upper 128 bits of all YMM registers.
	{ NULL, 0x01C0, 0x00D80000, { 0x0F, 0x77, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_WAIT[] = {
	// 9B WAIT NP Valid Valid Check pending unmasked floating-point exceptions.
	// 9B FWAIT NP Valid Valid Check pending unmasked floating-point exceptions.
	{ NULL, 0x0000, 0x00C40000, { 0x9B, 0x00, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_WBINVD[] = {
	// 0F 09 WBINVD NP Valid Valid Write back and flush Internal caches; initiate writing-back and flushing of external caches.
	{ NULL, 0x0000, 0x00D80000, { 0x0F, 0x09, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_WRFSBASE[] = {
	// F3 0F AE /2 WRFSBASE r32 M V/I FSGSBASE Load the FS base address with the 32-bit value in the source register.
	{ NULL, 0x4010, 0x03DB9000, { 0x0F, 0xAE, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA , FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + F3 0F AE /2 WRFSBASE r64 M V/I FSGSBASE Load the FS base address with the 64-bit value in the source register.
	{ NULL, 0x4008, 0x049B9000, { 0x0F, 0xAE, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA , FCML_NA, FCML_NA, FCML_NA } },
	// F3 0F AE /3 WRGSBASE r32 M V/I FSGSBASE Load the GS base address with the 32-bit value in the source register.
	{ "wrgsbase", 0x4010, 0x03DB9800, { 0x0F, 0xAE, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_DWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA , FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + F3 0F AE /3 WRGSBASE r64 M V/I FSGSBASE Load the GS base address with the 64-bit value in the source register.
	{ "wrgsbase", 0x4008, 0x049B9800, { 0x0F, 0xAE, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_QWORD, FCML_EOS_UNDEFINED, FCML_RMF_R ), FCML_NA , FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_WRMSR[] = {
	// 0F 30 WRMSR NP Valid Valid Write the value in EDX:EAX to MSR specified by ECX.
	{ NULL, 0x0000, 0x00D80000, { 0x0F, 0x30, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XADD[] = {
	// 0F C0 /r XADD r/m8,r8 MR Valid Valid Exchange r8 and r/m8; load sum into r/m8.
	// REX + 0F C0 /r XADD r/m8*,r8* MR Valid N.E. Exchange r8 and r/m8; load sum into r/m8.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xC0, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_MODRM_R_8, FCML_NA, FCML_NA, FCML_NA } },
	// 0F C1 /r XADD r/m16,r16 MR Valid Valid Exchange r16 and r/m16; load sum into r/m16.
	// 0F C1 /r XADD r/m32,r32 MR Valid Valid Exchange r32 and r/m32; load sum into r/m32.
	// REX.W + 0F C1 /r XADD r/m64,r64 MR Valid N.E. Exchange r64 and r/m64; load sum into r/m64.
	{ NULL, 0x0001, 0x00D88000, { 0x0F, 0xC1, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XCHG[] = {
	// 90+rw XCHG AX, r16 O Valid Valid Exchange r16 with AX.
	// 90+rw XCHG r16, AX O Valid Valid Exchange AX with r16.
	// 90+rd XCHG EAX, r32 O Valid Valid Exchange r32 with EAX.
	// 90+rd XCHG r32, EAX O Valid Valid Exchange EAX with r32.
	// REX.W + 90+rd XCHG RAX, r64 O Valid N.E. Exchange r64 with RAX.
	// REX.W + 90+rd XCHG r64, RAX O Valid N.E. Exchange RAX with r64.
	{ NULL, 0x0000, 0x00C40001, { 0x90, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_EAX, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_EOSA) | FCML_OA_W, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0000, 0x00C40001, { 0x90, 0x00, 0x00 }, { FCML_OP_OPCODE_REG( FCML_REG_GPR, FCML_EOS_EOSA) | FCML_OA_W, FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_EAX, FCML_EOS_EOSA ) | FCML_OA_W, FCML_NA, FCML_NA, FCML_NA } },
	// 86 /r XCHG r/m8, r8 MR Valid Valid Exchange r8 (byte register) with byte from r/m8.
	// REX + 86 /r XCHG r/m8*, r8* MR Valid N.E. Exchange r8 (byte register) with byte from r/m8.
	// 86 /r XCHG r8, r/m8 RM Valid Valid Exchange byte from r/m8 with r8 (byte register).
	// REX + 86 /r XCHG r8*, r/m8* RM Valid N.E. Exchange byte from r/m8 with r8 (byte register).
	{ NULL, 0x0000, 0x00C48000, { 0x86, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_MODRM_R_8_W, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0000, 0x00C48000, { 0x86, 0x00, 0x00 }, { FCML_OP_MODRM_R_8_W, FCML_OP_MODRM_RM_8_W, FCML_NA, FCML_NA, FCML_NA } },
	// 87 /r XCHG r/m16, r16 MR Valid Valid Exchange r16 with word from r/m16.
	// 87 /r XCHG r16, r/m16 RM Valid Valid Exchange word from r/m16 with r16.
	// 87 /r XCHG r/m32, r32 MR Valid Valid Exchange r32 with doubleword from r/m32.
	// 87 /r XCHG r32, r/m32 RM Valid Valid Exchange doubleword from r/m32 with r32.
	// REX.W + 87 /r XCHG r/m64, r64 MR Valid N.E. Exchange r64 with quadword from r/m64.
	// REX.W + 87 /r XCHG r64, r/m64 RM Valid N.E. Exchange quadword from r/m64 with r64.
	{ NULL, 0x0000, 0x00C48000, { 0x87, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R_W, FCML_NA, FCML_NA, FCML_NA } },
	{ NULL, 0x0000, 0x00C48000, { 0x87, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM_W, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XGETBV[] = {
	// 0F 01 D0 XGETBV NP Valid Valid Reads an XCR specified by ECX into EDX:EAX.
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xD0 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XLAT[] = {
	// D7 XLAT m8 NP Valid Valid Set AL to memory byte DS:[(E)BX + unsigned AL].
	{ NULL, 0x0000, 0x00C40000, { 0xD7, 0x00, 0x00 },
			{ FCML_OP_EXPLICIT_GPS_REG_ADDRESSING( FCML_REG_BX, FCML_EOS_BYTE, FCML_SEG_ENCODE_REGISTER( FCML_REG_DS, FCML_SEG_ALLOW_OVERRIDE ) ),
			FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// D7 XLATB NP Valid Valid Set AL to memory byte DS:[(E)BX + unsigned AL].
	// REX.W + D7 XLATB NP Valid N.E. Set AL to memory byte [RBX + unsigned AL].
	// TODO: Assembler.
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XOR[] = {
	// 34 ib XOR AL, imm8 I Valid Valid AL XOR imm8.
	{ NULL, 0x0001, 0x00C40000, { 0x34, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_BYTE ), FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 35 iw XOR AX, imm16 I Valid Valid AX XOR imm16.
	// 35 id XOR EAX, imm32 I Valid Valid EAX XOR imm32.
	{ NULL, 0x0001, 0x03C40000, { 0x35, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 35 id XOR RAX, imm32 I Valid N.E. RAX XOR imm32 (sign-extended).
	{ NULL, 0x0001, 0x04840000, { 0x35, 0x00, 0x00 }, { FCML_OP_EXPLICIT_REG( FCML_REG_GPR, FCML_REG_AL, FCML_EOS_EOSA ) | FCML_OA_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 80 /6 ib XOR r/m8, imm8 MI Valid Valid r/m8 XOR imm8.
	// REX + 80 /6 ib XOR r/m8*, imm8 MI Valid N.E. r/m8 XOR imm8.
	{ NULL, 0x0001, 0x00C5B000, { 0x80, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA } },
	// 81 /6 iw XOR r/m16, imm16 MI Valid Valid r/m16 XOR imm16.
	// 81 /6 id XOR r/m32, imm32 MI Valid Valid r/m32 XOR imm32.
	{ NULL, 0x0001, 0x03C5B000, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IMM_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 81 /6 id XOR r/m64, imm32 MI Valid N.E. r/m64 XOR imm32 (sign-extended).
	{ NULL, 0x0001, 0x0485B000, { 0x81, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_ID_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 83 /6 ib XOR r/m16, imm8 MI Valid Valid r/m16 XOR imm8 (sign-extended).
	// 83 /6 ib XOR r/m32, imm8 MI Valid Valid r/m32 XOR imm8 (sign-extended).
	{ NULL, 0x0001, 0x03C5B000, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 83 /6 ib XOR r/m64, imm8 MI Valid N.E. r/m64 XOR imm8 (sign-extended).
	{ NULL, 0x0001, 0x0485B000, { 0x83, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_IB_EX_EOSA, FCML_NA, FCML_NA, FCML_NA } },
	// 30 /r XOR r/m8, r8 MR Valid Valid r/m8 XOR r8.
	// REX + 30 /r XOR r/m8*, r8* MR Valid N.E. r/m8 XOR r8.
	{ NULL, 0x0001, 0x00C48000, { 0x30, 0x00, 0x00 }, { FCML_OP_MODRM_RM_8_W, FCML_OP_MODRM_R_8, FCML_NA, FCML_NA, FCML_NA } },
	// 31 /r XOR r/m16, r16 MR Valid Valid r/m16 XOR r16.
	// 31 /r XOR r/m32, r32 MR Valid Valid r/m32 XOR r32.
	// REX.W + 31 /r XOR r/m64, r64 MR Valid N.E. r/m64 XOR r64.
	{ NULL, 0x0001, 0x00C48000, { 0x31, 0x00, 0x00 }, { FCML_OP_MODRM_RM_W, FCML_OP_MODRM_R, FCML_NA, FCML_NA, FCML_NA } },
	// 32 /r XOR r8, r/m8 RM Valid Valid r8 XOR r/m8.
	// REX + 32 /r XOR r8*, r/m8* RM Valid N.E. r8 XOR r/m8.
	{ NULL, 0x0001, 0x00C48000, { 0x32, 0x00, 0x00 }, { FCML_OP_MODRM_R_8_W, FCML_OP_MODRM_RM_8, FCML_NA, FCML_NA, FCML_NA } },
	// 33 /r XOR r16, r/m16 RM Valid Valid r16 XOR r/m16.
	// 33 /r XOR r32, r/m32 RM Valid Valid r32 XOR r/m32.
	// REX.W + 33 /r XOR r64, r/m64 RM Valid N.E. r64 XOR r/m64.
	{ NULL, 0x0001, 0x00C48000, { 0x33, 0x00, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XORPD[] = {
	// 66 0F 57 /r XORPD xmm1,xmm2/m128 RM V/V SSE2 Bitwise exclusive-OR of xmm2/m128 and xmm1.
	{ NULL, 0x1000, 0x00D88000, { 0x0F, 0x57, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.66.0F.WIG 57 /r VXORPD xmm1,xmm2,xmm3/m128 RVM V/V AVX Return the bitwise logical XOR of packed double-precision floating-point values in xmm2 and xmm3/mem.
	// VEX.NDS.256.66.0F.WIG 57 /r VXORPD ymm1,ymm2,ymm3/m256 RVM V/V AVX Return the bitwise logical XOR of packed double-precision floating-point values in ymm2 and ymm3/mem.
	{ "vxorpd", 0x1080, 0x00D88000, { 0x0F, 0x57, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XORPS[] = {
	// 0F 57 /r XORPS xmm1,xmm2/m128 RM V/V SSE Bitwise exclusive-OR of xmm2/m128 and xmm1.
	{ NULL, 0x0000, 0x00D88000, { 0x0F, 0x57, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDS.128.0F.WIG 57 /r VXORPS xmm1,xmm2,xmm3/m128 RVM V/V AVX Return the bitwise logical XOR of packed single-precision floating-point values in xmm2 and xmm3/mem.
	// VEX.NDS.256.0F.WIG 57 /r VXORPS ymm1,ymm2,ymm3/m256 RVM V/V AVX Return the bitwise logical XOR of packed single-precision floating-point values in ymm2 and ymm3/mem.
	{ "vxorps", 0x0080, 0x00D88000, { 0x0F, 0x57, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XRSTOR[] = {
	// 0F AE /5 XRSTOR mem M Valid Valid Restore processor extended states from memory. The states are specified by EDX:EAX
	{ NULL, 0x0010, 0x03D9A800, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_512B, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W+ 0F AE /5 XRSTOR64 mem M Valid N.E. Restore processor extended states from memory. The states are specified by EDX:EAX
	{ "xrstor64", 0x0008, 0x0499A800, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_512B, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XSAVE[] = {
	// 0F AE /4 XSAVE mem M Valid Valid Save processor extended states to memory. The states are specified by EDX:EAX
	{ NULL, 0x0010, 0x03D9A000, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_512B, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W+ 0F AE /4 XSAVE64 mem M Valid N.E. Save processor extended states to memory. The states are specified by EDX:EAX
	{ "xsave64", 0x0008, 0x0499A000, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_512B, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XSAVEOPT[] = {
	// 0F AE /6 XSAVEOPT mem M V/V XSAVEOPT Save processor extended states specified in EDX:EAX to memory, optimizing the state save operation if possible.
	{ NULL, 0x0010, 0x03D9B000, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_UNDEF_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 0F AE /6 XSAVEOPT64 mem M V/V XSAVEOPT Save processor extended states specified in EDX:EAX to memory, optimizing the state save operation if possible.
	{ "xsaveopt64", 0x0008, 0x0499B000, { 0x0F, 0xAE, 0x00 }, { FCML_OP_MODRM_M_UNDEF_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XSETBV[] = {
	// 0F 01 D1 XSETBV NP Valid Valid Write the value in EDX:EAX to the XCR specified by ECX.
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xD1 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

/****************
 * AMD 3D Now!
 ****************/

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_FEMMS[] = {
	// FEMMS 0F 0Eh Faster Enter/Exit of the MMX or floating-point state
	{ NULL, 0x0000, 0x00D80000, { 0x0F, 0x0E, 0x00 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PAVGUSB[] = {
	// PAVGUSB mmreg1, mmreg2/mem64 0F 0Fh / BFh Average of unsigned packed 8-bit values
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0xBF }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};
struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PF2ID[] = {
	// PF2ID mmreg1, mmreg2/mem64 0Fh 0Fh / 1Dh Converts packed floating-point operand to packed 32-bit integer
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0x1D }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFACC[] = {
	// PFACC mmreg1, mmreg2/mem64 0Fh 0Fh / AEh Floating-point accumulate
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0xAE }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFADD[] = {
	// PFADD mmreg1, mmreg2/mem64 0Fh 0Fh / 9Eh Packed, floating-point addition
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0x9E }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFCMPEQ[] = {
	// PFCMPEQ mmreg1, mmreg2/mem64 0Fh 0Fh / B0h Packed floating-point comparison, equal to
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0xB0 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFCMPGE[] = {
	// PFCMPGE mmreg1, mmreg2/mem64 0Fh 0Fh / 90h Packed floating-point comparison, greater than or equal to
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0x90 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFCMPGT[] = {
	// PFCMPGT mmreg1, mmreg2/mem64 0Fh 0Fh / A0h Packed floating-point comparison, greater than
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0xA0 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFMAX[] = {
	// PFMAX mmreg1, mmreg2/mem64 0Fh 0Fh / A4h Packed floating-point maximum
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0xA4 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFMIN[] = {
	// PFMIN mmreg1, mmreg2/mem64 0Fh 0Fh / 94h Packed floating-point minimum
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0x94 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFMUL[] = {
	// PFMUL mmreg1, mmreg2/mem64 0Fh 0Fh / B4h Packed floating-point multiplication
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0xB4 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFRCP[] = {
	// PFRCP mmreg1, mmreg2/mem64 0Fh 0Fh / 96h Floating-point reciprocal approximation
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0x96 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFRCPIT1[] = {
	// PFRCPIT1 mmreg1, mmreg2/mem64 0Fh 0Fh / A6h Packed floating-point reciprocal, first iteration step
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0xA6 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFRCPIT2[] = {
	// PFRCPIT2 mmreg1, mmreg2/mem64 0Fh 0Fh / B6h Packed floating-point reciprocal/reciprocal square root, second iteration step
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0xB6 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFRSQIT1[] = {
	// PFRSQIT1 mmreg1, mmreg2/mem64 0Fh 0Fh / A7h Packed floating-point reciprocal square root, first iteration step
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0xA7 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFRSQRT[] = {
	// PFRSQRT mmreg1, mmreg2/mem64 0Fh 0Fh / 97h Floating-point reciprocal square root approximation
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0x97 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFSUB[] = {
	// PFSUB mmreg1, mmreg2/mem64 0Fh 0Fh / 9Ah Packed floating-point subtraction
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0x9A }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFSUBR[] = {
	// PFSUBR mmreg1, mmreg2/mem64 0Fh 0Fh / AAh Packed floating-point reverse subtraction
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0xAA }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PI2FD[] = {
	// PI2FD mmreg1, mmreg2/mem64 0Fh 0Fh / 0Dh Packed 32-bit integer to floating-point conversion
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0x0D }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PMULHRW[] = {
	// PMULHRW mmreg1, mmreg2/mem64 0F 0Fh/B7h Multiply signed packed 16-bit values with rounding and store the high 16 bits.
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0xB7 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PREFETCH[] = {
	// PREFETCH mem8 0F 0Dh Prefetch processor cache line into L1 data cache (Dcache)
	{ NULL, 0x0000, 0x80D98000, { 0x0F, 0x0D, 0x00 }, { FCML_OP_MODRM_M_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
	// PREFETCHW mem8 0F 0Dh Prefetch processor cache line into L1 data cache (Dcache)
	{ "prefetchw", 0x0000, 0x80D98800, { 0x0F, 0x0D, 0x00 }, { FCML_OP_MODRM_M_8, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

// Extensions to the 3DNow!

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PF2IW[] = {
	// PF2IW mmreg1, mmreg2/mem64 0Fh 0Fh / 1Ch Packed floating-point to integer word conversion with PF2IW sign extend
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0xC1 }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFNACC[] = {
	// PFNACC mmreg1, mmreg2/mem64 0Fh 0Fh / 8Ah Packed floating-point negative accumulate
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0x8A }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PFPNACC[] = {
	// PFPNACC mmreg1, mmreg2/mem64 0Fh 0Fh / 8Eh Packed floating-point mixed positive-negative accumulate
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0x8E }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PI2FW[] = {
	// PI2FW mmreg1, mmreg2/mem64 0Fh 0Fh / 0Ch Packed 16-bit integer to floating-point conversion
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0x0C }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PSWAPD[] = {
	// PSWAPD mmreg1, mmreg2/mem64 0Fh 0Fh / BBh Packed swap doubleword
	{ NULL, 0x0000, 0x00EC8000, { 0x0F, 0x0F, 0xBB }, { FCML_OP_MODRM_R_MMX_W, FCML_OP_MODRM_RM_MMX, FCML_NA, FCML_NA, FCML_NA } }
};

/* FMA */

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFMADDPD[] = {
	// VEX.DDS.128.66.0F38.W1 98 /r VFMADD132PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 98 /r VFMADD132PD ymm0,ymm1,ymm2/m256
	{ "vfmadd132pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0x98 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 A8 /r VFMADD213PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 A8 /r VFMADD213PD ymm0,ymm1,ymm2/m256
	{ "vfmadd213pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0xA8 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 B8 /r VFMADD231PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 B8 /r VFMADD231PD ymm0,ymm1,ymm2/m256
	{ "vfmadd231pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0xB8 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VFMADDPD xmm1, xmm2, xmm3/mem128, xmm4 C4 RXB.00011 0.src.0.01 69 /r /is4
	// VFMADDPD ymm1, ymm2, ymm3/mem256, ymm4 C4 RXB.00011 0.src.1.01 69 /r /is4
	{ "vfmaddpd", 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x69 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFMADDPD xmm1, xmm2, xmm3, xmm4/mem128 C4 RXB.00011 1.src.0.01 69 /r /is4
	// VFMADDPD ymm1, ymm2, ymm3, ymm4/mem256 C4 RXB.00011 1.src.1.01 69 /r /is4
	{ "vfmaddpd", 0x1088, 0x00EC8000, { 0x0F, 0x3A, 0x69 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_SIMD_L, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFMADDPS[] = {
	// VEX.DDS.128.66.0F38.W0 98 /r VFMADD132PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 98 /r VFMADD132PS ymm0,ymm1,ymm2/m256
	{ "vfmadd132ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0x98 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 A8 /r VFMADD213PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 A8 /r VFMADD213PS ymm0,ymm1,ymm2/m256
	{ "vfmadd213ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0xA8 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 B8 /r VFMADD231PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 B8 /r VFMADD231PS ymm0,ymm1,ymm2/m256
	{ "vfmadd231ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0xB8 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VFMADDPS xmm1, xmm2, xmm3/mem128, xmm4 C4 RXB.00011 0.src.0.01 68 /r /is4
	// VFMADDPS ymm1, ymm2, ymm3/mem256, ymm4 C4 RXB.00011 0.src.1.01 68 /r /is4
	{ "vfmaddps", 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x68 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFMADDPS xmm1, xmm2, xmm3, xmm4/mem128 C4 RXB.00011 1.src.0.01 68 /r /is4
	// VFMADDPS ymm1, ymm2, ymm3, ymm4/mem256 C4 RXB.00011 1.src.1.01 68 /r /is4
	{ "vfmaddps", 0x1088, 0x00EC8000, { 0x0F, 0x3A, 0x68 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_SIMD_L, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFMADDSD[] = {
	// VEX.DDS.LIG.128.66.0F38.W1 99 /r VFMADD132SD xmm0,xmm1,xmm2/m64
	{ "vfmadd132sd", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0x99 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W1 A9 /r VFMADD213SD xmm0,xmm1,xmm2/m64
	{ "vfmadd213sd", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0xA9 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W1 B9 /r VFMADD231SD xmm0,xmm1,xmm2/m64
	{ "vfmadd231sd", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0xB9 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } },
	// VFMADDSD xmm1, xmm2, xmm3/mem128, xmm4 C4 RXB.00011 0.src.X.01 6B /r /is4
	{ "vfmaddsd", 0x10D0, 0x00EC8000, { 0x0F, 0x3A, 0x6B }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFMADDSD xmm1, xmm2, xmm3, xmm4/mem128 C4 RXB.00011 1.src.X.01 6B /r /is4
	{ "vfmaddsd", 0x10C8, 0x00EC8000, { 0x0F, 0x3A, 0x6B }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_XMM_128, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFMADDSS[] = {
	// VEX.DDS.LIG.128.66.0F38.W0 99 /r VFMADD132SS xmm0,xmm1,xmm2/m32
	{ "vfmadd132ss", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0x99 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W0 A9 /r VFMADD213SS xmm0,xmm1,xmm2/m32
	{ "vfmadd213ss", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0xA9 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W0 B9 /r VFMADD231SS xmm0,xmm1,xmm2/m32
	{ "vfmadd231ss", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0xB9 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } },
	// VFMADDSS xmm1, xmm2, xmm3/mem32, xmm4 C4 RXB.00011 0.src.X.01 6A /r /is4
	{ "vfmaddss", 0x10D0, 0x00EC8000, { 0x0F, 0x3A, 0x6A }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_32, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFMADDSS xmm1, xmm2, xmm3, xmm4/mem32 C4 RXB.00011 1.src.X.01 6A /r /is4
	{ "vfmaddss", 0x10C8, 0x00EC8000, { 0x0F, 0x3A, 0x6A }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_XMM_32, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFMADDSUBPD[] = {
	// VEX.DDS.128.66.0F38.W1 96 /r VFMADDSUB132PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 96 /r VFMADDSUB132PD ymm0,ymm1,ymm2/m256
	{ "vfmaddsub132pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0x96 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 A6 /r VFMADDSUB213PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 A6 /r VFMADDSUB213PD ymm0,ymm1,ymm2/m256
	{ "vfmaddsub213pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0xA6 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 B6 /r VFMADDSUB231PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 B6 /r VFMADDSUB231PD ymm0,ymm1,ymm2/m256
	{ "vfmaddsub231pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0xB6 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VFMADDSUBPD xmm1, xmm2, xmm3/mem128, xmm4 C4 RXB.00011 0.src.0.01 5D /r /is4
	// VFMADDSUBPD ymm1, ymm2, ymm3/mem256, ymm4 C4 RXB.00011 0.src.1.01 5D /r /is4
	{ "vfmaddsubpd", 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x5D }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFMADDSUBPD xmm1, xmm2, xmm3, xmm4/mem128 C4 RXB.00011 1.src.0.01 5D /r /is4
	// VFMADDSUBPD ymm1, ymm2, ymm3, ymm4/mem256 C4 RXB.00011 1.src.1.01 5D /r /is4
	{ "vfmaddsubpd", 0x1088, 0x00EC8000, { 0x0F, 0x3A, 0x5D }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_SIMD_L, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFMADDSUBPS[] = {
	// VEX.DDS.128.66.0F38.W0 96 /r VFMADDSUB132PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 96 /r VFMADDSUB132PS ymm0,ymm1,ymm2/m256
	{ "vfmaddsub132ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0x96 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 A6 /r VFMADDSUB213PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 A6 /r VFMADDSUB213PS ymm0,ymm1,ymm2/m256
	{ "vfmaddsub213ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0xA6 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 B6 /r VFMADDSUB231PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 B6 /r VFMADDSUB231PS ymm0,ymm1,ymm2/m256
	{ "vfmaddsub231ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0xB6 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VFMADDSUBPS xmm1, xmm2, xmm3/mem128, xmm4 C4 RXB.00011 0.src.0.01 5C /r /is4
	// VFMADDSUBPS ymm1, ymm2, ymm3/mem256, ymm4 C4 RXB.00011 0.src.1.01 5C /r /is4
	{ "vfmaddsubps", 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x5C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFMADDSUBPS xmm1, xmm2, xmm3, xmm4/mem128 C4 RXB.00011 1.src.0.01 5C /r /is4
	// VFMADDSUBPS ymm1, ymm2, ymm3, ymm4/mem256 C4 RXB.00011 1.src.1.01 5C /r /is4
	{ "vfmaddsubps", 0x1088, 0x00EC8000, { 0x0F, 0x3A, 0x5C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_SIMD_L, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFMSUBADDPD[] = {
	// VEX.DDS.128.66.0F38.W1 97 /r VFMSUBADD132PD xmm0,xmm1,xmm2/m128
	{ "vfmsubadd132pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0x97 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 A7 /r VFMSUBADD213PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 A7 /r VFMSUBADD213PD ymm0,ymm1,ymm2/m256
	{ "vfmsubadd213pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0xA7 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 B7 /r VFMSUBADD231PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 B7 /r VFMSUBADD231PD ymm0,ymm1,ymm2/m256
	{ "vfmsubadd231pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0xB7 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VFMSUBADDPD xmm1, xmm2, xmm3/mem128, xmm4 C4 RXB.00011 0.src.0.01 5F /r /is4
	// VFMSUBADDPD ymm1, ymm2, ymm3/mem256, ymm4 C4 RXB.00011 0.src.1.01 5F /r /is4
	{ "vfmsubaddpd", 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x5F }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFMSUBADDPD xmm1, xmm2, xmm3, xmm4/mem128 C4 RXB.00011 1.src.0.01 5F /r /is4
	// VFMSUBADDPD ymm1, ymm2, ymm3, ymm4/mem256 C4 RXB.00011 1.src.1.01 5F /r /is4
	{ "vfmsubaddpd", 0x1088, 0x00EC8000, { 0x0F, 0x3A, 0x5F }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_SIMD_L, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFMSUBADDPS[] = {
	// VEX.DDS.128.66.0F38.W0 97 /r VFMSUBADD132PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 97 /r VFMSUBADD132PS ymm0,ymm1,ymm2/m256
	{ "vfmsubadd132ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0x97 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 A7 /r VFMSUBADD213PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 A7 /r VFMSUBADD213PS ymm0,ymm1,ymm2/m256
	{ "vfmsubadd213ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0xA7 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 B7 /r VFMSUBADD231PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 B7 /r VFMSUBADD231PS ymm0,ymm1,ymm2/m256
	{ "vfmsubadd231ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0xB7 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VFMSUBADDPS xmm1, xmm2, xmm3/mem128, xmm4 C4 RXB.00011 0.src.0.01 5E /r /is4
	// VFMSUBADDPS ymm1, ymm2, ymm3/mem256, ymm4 C4 RXB.00011 0.src.1.01 5E /r /is4
	{ "vfmsubaddps", 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x5E }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFMSUBADDPS xmm1, xmm2, xmm3, xmm4/mem128 C4 RXB.00011 1.src.0.01 5E /r /is4
	// VFMSUBADDPS ymm1, ymm2, ymm3, ymm4/mem256 C4 RXB.00011 1.src.1.01 5E /r /is4
	{ "vfmsubaddps", 0x1088, 0x00EC8000, { 0x0F, 0x3A, 0x5E }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_SIMD_L, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFMSUBPD[] = {
	// VEX.DDS.128.66.0F38.W1 9A /r VFMSUB132PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 9A /r VFMSUB132PD ymm0,ymm1,ymm2/m256
	{ "vfmsub132pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0x9A }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 AA /r VFMSUB213PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 AA /r VFMSUB213PD ymm0,ymm1,ymm2/m256
	{ "vfmsub213pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0xAA }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 BA /r VFMSUB231PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 BA /r VFMSUB231PD ymm0,ymm1,ymm2/m256
	{ "vfmsub231pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0xBA }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VFMSUBPD xmm1, xmm2, xmm3/mem128, xmm4 C4 RXB.00011 0.src.0.01 6D /r /is4
	// VFMSUBPD ymm1, ymm2, ymm3/mem256, ymm4 C4 RXB.00011 0.src.1.01 6D /r /is4
	{ "vfmsubpd", 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x6D }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFMSUBPD xmm1, xmm2, xmm3, xmm4/mem128 C4 RXB.00011 1.src.0.01 6D /r /is4
	// VFMSUBPD ymm1, ymm2, ymm3, ymm4/mem256 C4 RXB.00011 1.src.1.01 6D /r /is4
	{ "vfmsubpd", 0x1088, 0x00EC8000, { 0x0F, 0x3A, 0x6D }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_SIMD_L, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFMSUBPS[] = {
	// VEX.DDS.128.66.0F38.W0 9A /r VFMSUB132PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 9A /r VFMSUB132PS ymm0,ymm1,ymm2/m256
	{ "vfmsub132ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0x9A }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 AA /r VFMSUB213PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 AA /r VFMSUB213PS ymm0,ymm1,ymm2/m256
	{ "vfmsub213ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0xAA }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 BA /r VFMSUB231PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 BA /r VFMSUB231PS ymm0,ymm1,ymm2/m256
	{ "vfmsub231ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0xBA }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VFMSUBPS xmm1, xmm2, xmm3/mem128, xmm4 C4 RXB.00011 0.src.0.01 6C /r /is4
	// VFMSUBPS ymm1, ymm2, ymm3/mem256, ymm4 C4 RXB.00011 0.src.1.01 6C /r /is4
	{ "vfmsubps", 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x6C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFMSUBPS xmm1, xmm2, xmm3, xmm4/mem128 C4 RXB.00011 1.src.0.01 6C /r /is4
	// VFMSUBPS ymm1, ymm2, ymm3, ymm4/mem256 C4 RXB.00011 1.src.1.01 6C /r /is4
	{ "vfmsubps", 0x1088, 0x00EC8000, { 0x0F, 0x3A, 0x6C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_SIMD_L, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFMSUBSD[] = {
	// VEX.DDS.LIG.128.66.0F38.W1 9B /r VFMSUB132SD xmm0,xmm1,xmm2/m64
	{ "vfmsub132sd", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0x9B }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W1 AB /r VFMSUB213SD xmm0,xmm1,xmm2/m64
	{ "vfmsub213sd", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0xAB }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W1 BB /r VFMSUB231SD xmm0,xmm1,xmm2/m64
	{ "vfmsub231sd", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0xBB }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } },
	// VFMSUBSD xmm1, xmm2, xmm3/mem64, xmm4 C4 RXB.00011 0.src.X.01 6F /r /is4
	{ "vfmsubsd", 0x10D0, 0x00EC8000, { 0x0F, 0x3A, 0x6F }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_64, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFMSUBSD xmm1, xmm2, xmm3, xmm4/mem64 C4 RXB.00011 1.src.X.01 6F /r /is4
	{ "vfmsubsd", 0x10C8, 0x00EC8000, { 0x0F, 0x3A, 0x6F }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_XMM_64, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFMSUBSS[] = {
	// VEX.DDS.LIG.128.66.0F38.W0 9B /r VFMSUB132SS xmm0,xmm1,xmm2/m32
	{ "vfmsub132ss", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0x9B }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W0 AB /r VFMSUB213SS xmm0,xmm1,xmm2/m32
	{ "vfmsub213ss", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0xAB }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W0 BB /r VFMSUB231SS xmm0,xmm1,xmm2/m32
	{ "vfmsub231ss", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0xBB }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } },
	// VFMSUBSS xmm1, xmm2, xmm3/mem32, xmm4 C4 RXB.00011 0.src.X.01 6E /r /is4
	{ "vfmsubss", 0x10D0, 0x00EC8000, { 0x0F, 0x3A, 0x6E }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_32, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFMSUBSS xmm1, xmm2, xmm3, xmm4/mem32 C4 RXB.00011 1.src.X.01 6E /r /is4
	{ "vfmsubss", 0x10C8, 0x00EC8000, { 0x0F, 0x3A, 0x6E }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_XMM_32, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFNMADDPD[] = {
	// VEX.DDS.128.66.0F38.W1 9C /r VFNMADD132PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 9C /r VFNMADD132PD ymm0,ymm1,ymm2/m256
	{ "vfnmadd132pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0x9C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 AC /r VFNMADD213PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 AC /r VFNMADD213PD ymm0,ymm1,ymm2/m256
	{ "vfnmadd213pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0xAC }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 BC /r VFNMADD231PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 BC /r VFNMADD231PD ymm0,ymm1,ymm2/m256
	{ "vfnmadd231pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0xBC }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VFNMADDPD xmm1, xmm2, xmm3/mem128, xmm4 C4 RXB.00011 0.src.0.01 79 /r /is4
	// VFNMADDPD ymm1, ymm2, ymm3/mem256, ymm4 C4 RXB.00011 0.src.1.01 79 /r /is4
	{ "vfnmaddpd", 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x79 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFNMADDPD xmm1, xmm2, xmm3, xmm4/mem128 C4 RXB.00011 1.src.0.01 79 /r /is4
	// VFNMADDPD ymm1, ymm2, ymm3, ymm4/mem256 C4 RXB.00011 1.src.1.01 79 /r /is4
	{ "vfnmaddpd", 0x1088, 0x00EC8000, { 0x0F, 0x3A, 0x79 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_SIMD_L, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFNMADDPS[] = {
	// VEX.DDS.128.66.0F38.W0 9C /r VFNMADD132PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 9C /r VFNMADD132PS ymm0,ymm1,ymm2/m256
	{ "vfnmadd132ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0x9C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 AC /r VFNMADD213PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 AC /r VFNMADD213PS ymm0,ymm1,ymm2/m256
	{ "vfnmadd213ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0xAC }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 BC /r VFNMADD231PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 BC /r VFNMADD231PS ymm0,ymm1,ymm2/m256
	{ "vfnmadd231ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0xBC }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VFNMADDPS xmm1, xmm2, xmm3/mem128, xmm4 C4 RXB.00011 0.src.0.01 78 /r /is4
	// VFNMADDPS ymm1, ymm2, ymm3/mem256, ymm4 C4 RXB.00011 0.src.1.01 78 /r /is4
	{ "vfnmaddps", 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x78 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFNMADDPS xmm1, xmm2, xmm3, xmm4/mem128 C4 RXB.00011 1.src.0.01 78 /r /is4
	// VFNMADDPS ymm1, ymm2, ymm3, ymm4/mem256 C4 RXB.00011 1.src.1.01 78 /r /is4
	{ "vfnmaddps", 0x1088, 0x00EC8000, { 0x0F, 0x3A, 0x78 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_SIMD_L, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFNMADDSD[] = {
	// VEX.DDS.LIG.128.66.0F38.W1 9D /r VFNMADD132SD xmm0,xmm1,xmm2/m64
	{ "vfnmadd132sd", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0x9D }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W1 AD /r VFNMADD213SD xmm0,xmm1,xmm2/m64
	{ "vfnmadd213sd", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0xAD }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W1 BD /r VFNMADD231SD xmm0,xmm1,xmm2/m64
	{ "vfnmadd231sd", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0xBD }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } },
	// VFNMADDSD xmm1, xmm2, xmm3/mem64, xmm4 C4 RXB.00011 0.src.X.01 7B /r /is4
	{ "vfnmaddsd", 0x10D0, 0x00EC8000, { 0x0F, 0x3A, 0x7B }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_64, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFNMADDSD xmm1, xmm2, xmm3, xmm4/mem64 C4 RXB.00011 1.src.X.01 7B /r /is4
	{ "vfnmaddsd", 0x10C8, 0x00EC8000, { 0x0F, 0x3A, 0x7B }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_XMM_64, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFNMADDSS[] = {
	// VEX.DDS.LIG.128.66.0F38.W0 9D /r VFNMADD132SS xmm0,xmm1,xmm2/m32
	{ "vfnmadd132ss", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0x9D }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W0 AD /r VFNMADD213SS xmm0,xmm1,xmm2/m32
	{ "vfnmadd213ss", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0xAD }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W0 BD /r VFNMADD231SS xmm0,xmm1,xmm2/m32
	{ "vfnmadd231ss", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0xBD }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } },
	// VFNMADDSS xmm1, xmm2, xmm3/mem32, xmm4 C4 RXB.00011 0.src.X.01 7A /r /is4
	{ "vfnmaddss", 0x10D0, 0x00EC8000, { 0x0F, 0x3A, 0x7A }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_32, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFNMADDSS xmm1, xmm2, xmm3, xmm4/mem32 C4 RXB.00011 1.src.X.01 7A /r /is4
	{ "vfnmaddss", 0x10C8, 0x00EC8000, { 0x0F, 0x3A, 0x7A }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_XMM_32, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFNMSUBPD[] = {
	// VEX.DDS.128.66.0F38.W1 9E /r VFNMSUB132PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 9E /r VFNMSUB132PD ymm0,ymm1,ymm2/m256
	{ "vfnmsub132pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0x9E }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 AE /r VFNMSUB213PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 AE /r VFNMSUB213PD ymm0,ymm1,ymm2/m256
	{ "vfnmsub213pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0xAE }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W1 BE /r VFNMSUB231PD xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W1 BE /r VFNMSUB231PD ymm0,ymm1,ymm2/m256
	{ "vfnmsub231pd", 0x1088, 0x00EC8000, { 0x0F, 0x38, 0xBE }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VFNMSUBPD xmm1, xmm2, xmm3/mem128, xmm4 C4 RXB.00011 0.src.0.01 7D /r /is4
	// VFNMSUBPD ymm1, ymm2, ymm3/mem256, ymm4 C4 RXB.00011 0.src.1.01 7D /r /is4
	{ "vfnmsubpd", 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x7D }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFNMSUBPD xmm1, xmm2, xmm3, xmm4/mem128 C4 RXB.00011 1.src.0.01 7D /r /is4
	// VFNMSUBPD ymm1, ymm2, ymm3, ymm4/mem256 C4 RXB.00011 1.src.1.01 7D /r /is4
	{ "vfnmsubpd", 0x1088, 0x00EC8000, { 0x0F, 0x3A, 0x7D }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_SIMD_L, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFNMSUBPS[] = {
	// VEX.DDS.128.66.0F38.W0 9E /r VFNMSUB132PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 9E /r VFNMSUB132PS ymm0,ymm1,ymm2/m256
	{ "vfnmsub132ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0x9E }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 AE /r VFNMSUB213PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 AE /r VFNMSUB213PS ymm0,ymm1,ymm2/m256
	{ "vfnmsub213ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0xAE }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VEX.DDS.128.66.0F38.W0 BE /r VFNMSUB231PS xmm0,xmm1,xmm2/m128
	// VEX.DDS.256.66.0F38.W0 BE /r VFNMSUB231PS ymm0,ymm1,ymm2/m256
	{ "vfnmsub231ps", 0x1090, 0x00EC8000, { 0x0F, 0x38, 0xBE }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA } },
	// VFNMSUBPS xmm1, xmm2, xmm3/mem128, xmm4 C4 RXB.00011 0.src.0.01 7C /r /is4
	// VFNMSUBPS ymm1, ymm2, ymm3/mem256, ymm4 C4 RXB.00011 0.src.1.01 7C /r /is4
	{ "vfnmsubps", 0x1090, 0x00EC8000, { 0x0F, 0x3A, 0x7C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFNMSUBPS xmm1, xmm2, xmm3, xmm4/mem128 C4 RXB.00011 1.src.0.01 7C /r /is4
	// VFNMSUBPS ymm1, ymm2, ymm3, ymm4/mem256 C4 RXB.00011 1.src.1.01 7C /r /is4
	{ "vfnmsubps", 0x1088, 0x00EC8000, { 0x0F, 0x3A, 0x7C }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_SIMD_L, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFNMSUBSD[] = {
	// VEX.DDS.LIG.128.66.0F38.W1 9F /r VFNMSUB132SD xmm0,xmm1,xmm2/m64
	{ "vfnmsub132sd", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0x9F }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W1 AF /r VFNMSUB213SD xmm0,xmm1,xmm2/m64
	{ "vfnmsub213sd", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0xAF }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W1 BF /r VFNMSUB231SD xmm0,xmm1,xmm2/m64
	{ "vfnmsub231sd", 0x10C8, 0x00EC8000, { 0x0F, 0x38, 0xBF }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA } },
	// VFNMSUBSD xmm1, xmm2, xmm3/mem64, xmm4 C4 RXB.00011 0.src.X.01 7F /r /is4
	{ "vfnmsubsd", 0x10D0, 0x00EC8000, { 0x0F, 0x3A, 0x7F }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_64, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFNMSUBSD xmm1, xmm2, xmm3, xmm4/mem64 C4 RXB.00011 1.src.X.01 7F /r /is4
	{ "vfnmsubsd", 0x10C8, 0x00EC8000, { 0x0F, 0x3A, 0x7F }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_XMM_64, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFNMSUBSS[] = {
	// VEX.DDS.LIG.128.66.0F38.W0 9F /r VFNMSUB132SS xmm0,xmm1,xmm2/m32
	{ "vfnmsub132ss", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0x9F }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W0 AF /r VFNMSUB213SS xmm0,xmm1,xmm2/m32
	{ "vfnmsub213ss", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0xAF }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } },
	// VEX.DDS.LIG.128.66.0F38.W0 BF /r VFNMSUB231SS xmm0,xmm1,xmm2/m32
	{ "vfnmsub231ss", 0x10D0, 0x00EC8000, { 0x0F, 0x38, 0xBF }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA } },
	// VFNMSUBSS xmm1, xmm2, xmm3/mem32, xmm4 C4 RXB.00011 0.src.X.01 7E /r /is4
	{ "vfnmsubss", 0x10D0, 0x00EC8000, { 0x0F, 0x3A, 0x7E }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_32, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VFNMSUBSS xmm1, xmm2, xmm3, xmm4/mem32 C4 RXB.00011 1.src.X.01 7E /r /is4
	{ "vfnmsubss", 0x10C8, 0x00EC8000, { 0x0F, 0x3A, 0x7E }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_XMM_32, FCML_NA } }
};

/* END OF FAM */

/* VEX-Encoded GPR instructions. */

// TODO: Zastanowic sie jak informowac ze dana instrukcja nie moze posiadac danych prefixow. tu np 66.
// Mozna w sumie to waruek przy VEX i GPR, zaimplementowac jak dojda flagi CPUID dla poszczegolnych instrukcji
// czyli jezeli BMI1 i jest prefix to #UD. (Na chwile obecna obsluzoe inaczej.)

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ANDN[] = {
	// VEX.NDS.LZ.0F38.W0 F2 /r ANDN r32a, r32b, r/m32
	{ NULL, 0x02D0, 0x00EC8000, { 0x0F, 0x38, 0xF2 }, { FCML_OP_MODRM_R_32_W, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ), FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA } },
	// VEX.NDS.LZ.0F38.W1 F2 /r ANDN r64a, r64b, r/m64
	{ NULL, 0x02C8, 0x00EC8000, { 0x0F, 0x38, 0xF2 }, { FCML_OP_MODRM_R_64_W, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ), FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA } }
};

// TODO: BEXTR taki opcoe jest w AMD, moe dodac w assemblerze jako synonim.
// BEXTR reg32, reg/mem32, reg32 C4 RXB.02 0.cntl.0.00 F7 /r
// BEXTR reg64, reg/mem64, reg64 C4 RXB.02 1.cntl.0.00 F7 /r

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BEXR[] = {
	// VEX.NDS1.LZ.0F38.W0 F7 /r BEXR r32a, r/m32, r32b
	{ NULL, 0x02D0, 0x00EC8000, { 0x0F, 0x38, 0xF7 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_32, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ), FCML_NA, FCML_NA } },
	// VEX.NDS1.LZ.0F38.W1 F7 /r BEXR r64a, r/m64, r64b
	{ NULL, 0x02C8, 0x00EC8000, { 0x0F, 0x38, 0xF7 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_64, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ), FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BEXTR[] = {
	// BEXTR reg32, reg/mem32, imm32 8F RXB.0A 0.1111.0.00 10 /r /id
	{ NULL, 0x0550, 0x00D88000, { 0x0A, 0x10, 0x00 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_32, FCML_OP_ID, FCML_NA, FCML_NA } },
	// BEXTR reg64, reg/mem64, imm32 8F RXB.0A 1.1111.0.00 10 /r /id
	{ NULL, 0x0548, 0x00D88000, { 0x0A, 0x10, 0x00 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_64, FCML_OP_ID, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLCFILL[] = {
	// BLCFILL reg32, reg/mem32 8F RXB.09 0.dest.0.00 01 /1
	{ NULL, 0x0450, 0x00D98800, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// BLCFILL reg64, reg/mem64 8F RXB.09 1.dest.0.00 01 /1
	{ NULL, 0x0448, 0x00D98800, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLCI[] = {
	// BLCI reg32, reg/mem32 8F RXB.09 0.dest.0.00 02 /6
	{ NULL, 0x0450, 0x00D9B000, { 0x09, 0x02, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// BLCI reg64, reg/mem64 8F RXB.09 1.dest.0.00 02 /6
	{ NULL, 0x0448, 0x00D9B000, { 0x09, 0x02, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLCIC[] = {
	// BLCIC reg32, reg/mem32 8F RXB.09 0.dest.0.00 01 /5
	{ NULL, 0x0450, 0x00D9A800, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// BLCIC reg64, reg/mem64 8F RXB.09 1.dest.0.00 01 /5
	{ NULL, 0x0448, 0x00D9A800, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLCMSK[] = {
	// BLCMSK reg32, reg/mem32 8F RXB.09 0.dest.0.00 02 /1
	{ NULL, 0x0450, 0x00D98800, { 0x09, 0x02, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// BLCMSK reg64, reg/mem64 8F RXB.09 1.dest.0.00 02 /1
	{ NULL, 0x0448, 0x00D98800, { 0x09, 0x02, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLCS[] = {
	// BLCS reg32, reg/mem32 8F RXB.09 0.dest.0.00 01 /3
	{ NULL, 0x0450, 0x00D99800, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// BLCS reg64, reg/mem64 8F RXB.09 1.dest.0.00 01 /3
	{ NULL, 0x0448, 0x00D99800, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLSFILL[] = {
	// BLSFILL reg32, reg/mem32 8F RXB.09 0.dest.0.00 01 /2
	{ NULL, 0x0450, 0x00D99000, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// BLSFILL reg64, reg/mem64 8F RXB.09 1.dest.0.00 01 /2
	{ NULL, 0x0448, 0x00D99000, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLSI[] = {
	// VEX.NDD.LZ.0F38.W0 F3 /3 BLSI r32, r/m32
	{ NULL, 0x02D0, 0x00ED9800, { 0x0F, 0x38, 0xF3 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDD.LZ.0F38.W1 F3 /3 BLSI r64, r/m64
	{ NULL, 0x02C8, 0x00ED9800, { 0x0F, 0x38, 0xF3 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLSIC[] = {
	// BLSIC reg32, reg/mem32 8F RXB.09 0.dest.0.00 01 /6
	{ NULL, 0x0450, 0x00D9B000, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// BLSIC reg64, reg/mem64 8F RXB.09 1.dest.0.00 01 /6
	{ NULL, 0x0448, 0x00D9B000, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLSMSK[] = {
	// VEX.NDD.LZ.0F38.W0 F3 /2 BLSMSK r32, r/m32
	{ NULL, 0x02D0, 0x00ED9000, { 0x0F, 0x38, 0xF3 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDD.LZ.0F38.W1 F3 /2 BLSMSK r64, r/m64
	{ NULL, 0x02C8, 0x00ED9000, { 0x0F, 0x38, 0xF3 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BLSR[] = {
	// VEX.NDD.LZ.0F38.W0 F3 /1 BLSR r32, r/m32
	{ NULL, 0x02D0, 0x00ED8800, { 0x0F, 0x38, 0xF3 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// VEX.NDD.LZ.0F38.W1 F3 /1 BLSR r64, r/m64
	{ NULL, 0x02C8, 0x00ED8800, { 0x0F, 0x38, 0xF3 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_BZHI[] = {
	// VEX.NDS1.LZ.0F38.W0 F5 /r BZHI r32a, r/m32, r32b
	{ NULL, 0x02D0, 0x00EC8000, { 0x0F, 0x38, 0xF5 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_32, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ), FCML_NA, FCML_NA } },
	// VEX.NDS1.LZ.0F38.W1 F5 /r BZHI r64a, r/m64, r64b
	{ NULL, 0x02C8, 0x00EC8000, { 0x0F, 0x38, 0xF5 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_64, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ), FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_LZCNT[] = {
	// F3 0F BD /r LZCNT r16,r/m16
	// F3 0F BD /r LZCNT r32,r/m32
	// REX.W + F3 0F BD /r LZCNT r64,r/m64
	{ NULL, 0x4000, 0x00D88000, { 0x0F, 0xBD, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_MULX[] = {
	// VEX.NDD.LZ.F2.0F38.W0 F6 /r MULX r32a, r32b, r/m32
	{ NULL, 0x22D0, 0x00EC8000, { 0x0F, 0x38, 0xF6 }, { FCML_OP_MODRM_R_32_W, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ), FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA } },
	// VEX.NDD.LZ.F2.0F38.W1 F6 /r MULX r64a, r64b, r/m64
	{ NULL, 0x22C8, 0x00EC8000, { 0x0F, 0x38, 0xF6 }, { FCML_OP_MODRM_R_64_W, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ), FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PDEP[] = {
	// VEX.NDS.LZ.F2.0F38.W0 F5 /r PDEP r32a, r32b, r/m32
	{ NULL, 0x22D0, 0x00EC8000, { 0x0F, 0x38, 0xF5 }, { FCML_OP_MODRM_R_32_W, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ), FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA } },
	// VEX.NDS.LZ.F2.0F38.W1 F5 /r PDEP r64a, r64b, r/m64
	{ NULL, 0x22C8, 0x00EC8000, { 0x0F, 0x38, 0xF5 }, { FCML_OP_MODRM_R_64_W, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ), FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_PEXT[] = {
	// VEX.NDS.LZ.F3.0F38.W0 F5 /r PEXT r32a, r32b, r/m32
	{ NULL, 0x42D0, 0x00EC8000, { 0x0F, 0x38, 0xF5 }, { FCML_OP_MODRM_R_32_W, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ), FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA } },
	// VEX.NDS.LZ.F3.0F38.W1 F5 /r PEXT r64a, r64b, r/m64
	{ NULL, 0x42C8, 0x00EC8000, { 0x0F, 0x38, 0xF5 }, { FCML_OP_MODRM_R_64_W, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ), FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RORX[] = {
	// VEX.LZ.F2.0F3A.W0 F0 /r ib RORX r32, r/m32, imm8
	{ NULL, 0x22D0, 0x00EC8000, { 0x0F, 0x38, 0xF0 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_32, FCML_OP_IB, FCML_NA, FCML_NA } },
	// VEX.LZ.F2.0F3A.W1 F0 /r ib RORX r64, r/m64, imm8
	{ NULL, 0x22C8, 0x00EC8000, { 0x0F, 0x38, 0xF0 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_64, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SHLX[] = {
	// VEX.NDS1.LZ.66.0F38.W0 F7 /r SHLX r32a, r/m32, r32b
	{ NULL, 0x12D0, 0x00EC8000, { 0x0F, 0x38, 0xF7 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_32, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ), FCML_NA, FCML_NA } },
	// VEX.NDS1.LZ.66.0F38.W1 F7 /r SHLX r64a, r/m64, r64b
	{ NULL, 0x12C8, 0x00EC8000, { 0x0F, 0x38, 0xF7 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_64, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ), FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SHRX[] = {
	// VEX.NDS1.LZ.F2.0F38.W0 F7 /r SHRX r32a, r/m32, r32b
	{ NULL, 0x22D0, 0x00EC8000, { 0x0F, 0x38, 0xF7 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_32, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ), FCML_NA, FCML_NA } },
	// VEX.NDS1.LZ.F2.0F38.W1 F7 /r SHRX r64a, r/m64, r64b
	{ NULL, 0x22C8, 0x00EC8000, { 0x0F, 0x38, 0xF7 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_64, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ), FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_SARX[] = {
	// VEX.NDS1.LZ.F3.0F38.W0 F7 /r SARX r32a, r/m32, r32b
	{ NULL, 0x42D0, 0x00EC8000, { 0x0F, 0x38, 0xF7 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_32, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ), FCML_NA, FCML_NA } },
	// VEX.NDS1.LZ.F3.0F38.W1 F7 /r SARX r64a, r/m64, r64b
	{ NULL, 0x42C8, 0x00EC8000, { 0x0F, 0x38, 0xF7 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_64, FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ), FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_TZCNT[] = {
	// F3 0F BC /r TZCNT r16, r/m16
	// F3 0F BC /r TZCNT r32, r/m32
	// REX.W + F3 0F BC /r TZCNT r64, r/m64
	{ NULL, 0x4000, 0x00D88000, { 0x0F, 0xBC, 0x00 }, { FCML_OP_MODRM_R_W, FCML_OP_MODRM_RM, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_TZMSK[] = {
	// TZMSK reg32, reg/mem32 8F RXB.09 0.dest.0.00 01 /4
	{ NULL, 0x0450, 0x00D9A000, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_DWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// TZMSK reg64, reg/mem64 8F RXB.09 1.dest.0.00 01 /4
	{ NULL, 0x0448, 0x00D9A000, { 0x09, 0x01, 0x00 }, { FCML_OP_VEX_VVVV_REG( FCML_REG_GPR, FCML_EOS_QWORD ) | FCML_OA_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

/* END OF VEX-GPR */

/* HLE */

// TODO: Zaimplmentowac jak wrocimy do prefixow, lock rpne itd.
// F2 XACQUIRE
// F3 XRELEASE

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XABORT[] = {
	// C6 F8 ib XABORT imm8
	{ NULL, 0x0000, 0x00D80000, { 0xC6, 0xF8, 0x00 }, { FCML_OP_IB, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XBEGIN[] = {
	// C7 F8 XBEGIN rel16
	// C7 F8 XBEGIN rel32
	{ NULL, 0x0000, 0x00D80000, { 0xC7, 0xF8, 0x00 }, { FCML_OP_IMMEDIATE_DIS_RELATIVE_EOSA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XEND[] = {
	// 0F 01 D5 XEND
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xD5 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_XTEST[] = {
	// 0F 01 D6 XTEST
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xD6 }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

/* END OF HLE */

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ADCX[] = {
	// 66 0F 38 F6 /r ADCX r32, r/m32
	{ NULL, 0x1010, 0x00EC8000, { 0x0F, 0x38, 0xF6 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// REX.W + 66 0F 38 F6 /r ADCX r64, r/m64
	{ NULL, 0x1008, 0x00EC8000, { 0x0F, 0x38, 0xF6 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_ADOX[] = {
	// F3 0F 38 F6 /r ADOX r32, r/m32
	{ NULL, 0x4010, 0x00EC8000, { 0x0F, 0x38, 0xF6 }, { FCML_OP_MODRM_R_32_W, FCML_OP_MODRM_RM_32, FCML_NA, FCML_NA, FCML_NA } },
	// REX.w + F3 0F 38 F6 /r ADOX r64, r/m64
	{ NULL, 0x4008, 0x00EC8000, { 0x0F, 0x38, 0xF6 }, { FCML_OP_MODRM_R_64_W, FCML_OP_MODRM_RM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_RDSEED[] = {
	// 0F C7 /7 RDSEED r16
	// 0F C7 /7 RDSEED r32
	// REX.W + 0F C7 /7 RDSEED r64
	{ NULL, 0x0000, 0x00DBB800, { 0x0F, 0xC7, 0x00 }, { FCML_OP_RM( FCML_REG_GPR, FCML_EOS_EOSA, FCML_EOS_UNDEFINED, FCML_RMF_R ) | FCML_OA_W, FCML_NA, FCML_NA, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_CLAC[] = {
	// 0F 01 CA CLAC
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xCA }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_STAC[] = {
	// 0F 01 CB STAC
	{ NULL, 0x0000, 0x00EC0000, { 0x0F, 0x01, 0xCB }, { FCML_NA, FCML_NA, FCML_NA, FCML_NA, FCML_NA } }
};

// XOP

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFRCZPD[] = {
	// VFRCZPD xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 81 /r
	// VFRCZPD ymm1, ymm2/mem256 8F RXB.01001 0.1111.1.00 81 /r
	{ NULL, 0x0510, 0x00D88000, { 0x09, 0x81, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFRCZPS[] = {
	// VFRCZPS xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 80 /r
	// VFRCZPS ymm1, ymm2/mem256 8F RXB.01001 0.1111.1.00 80 /r
	{ NULL, 0x0510, 0x00D88000, { 0x09, 0x80, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_MODRM_RM_SIMD_L, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFRCZSD[] = {
	// VFRCZSD xmm1,xmm2/mem64 8F RXB.01001 0.1111.0.00 83 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0x83, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_64, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VFRCZSS[] = {
	// VFRCZSS xmm1, xmm2/mem32 8F RXB.01001 0.1111.0.00 82 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0x82, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_32, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPCMOV[] = {
	// VPCMOV xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 0.src.0.00 A2 /r ib
	// VPCMOV ymm1, ymm2, ymm3/mem256, ymm4 8F RXB.01000 0.src.1.00 A2 /r ib
	{ NULL, 0x0410, 0x00D88000, { 0x08, 0xA2, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_MODRM_RM_SIMD_L, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VPCMOV xmm1, xmm2, xmm3, xmm4/mem128 8F RXB.01000 1.src.0.00 A2 /r ib
	// VPCMOV ymm1, ymm2, ymm3, ymm4/mem256 8F RXB.01000 1.src.1.00 A2 /r ib
	{ NULL, 0x0408, 0x00D88000, { 0x08, 0xA2, 0x00 }, { FCML_OP_MODRM_R_SIMD_L_W, FCML_OP_VEX_VVVV_SIMD_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_SIMD_L, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPCOM[] = {
	// VPCOMB xmm1, xmm2, xmm3/mem128, imm8 8F RXB.01000 0.src.0.00 CC /r ib
	{ "vpcomb", 0x0450, 0x00D88000, { 0x08, 0xCC, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA } },
	// VPCOMW xmm1, xmm2, xmm3/mem128, imm8 8F RXB.01000 0.src.0.00 CD /r ib
	{ "vpcomw", 0x0450, 0x00D88000, { 0x08, 0xCD, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA } },
	// VPCOMD xmm1, xmm2, xmm3/mem128, imm8 8F RXB.01000 0.src.0.00 CE /r ib
	{ "vpcomd", 0x0450, 0x00D88000, { 0x08, 0xCE, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA } },
	// VPCOMQ xmm1, xmm2, xmm3/mem128, imm8 8F RXB.01000 0.src.0.00 CF /r ib
	{ "vpcomq", 0x0450, 0x00D88000, { 0x08, 0xCF, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA } }
	// TODO: virtualne operandy sluzace tylko do indetyfikacji, a nie sa renderowane.
	// TODO: Obsluzyc mnemoniki warunkowe na podstawie imm8.
	// imm8[2:0] Comparison Mnemonic
	// 000 Less Than VPCOMLTB
	// 001 Less Than or Equal VPCOMLEB
	// 010 Greater Than VPCOMGTB
	// 011 Greater Than or Equal VPCOMGEB
	// 100 Equal VPCOMEQB
	// 101 Not Equal VPCOMNEQB
	// 110 False VPCOMFALSEB
	// 111 True VPCOMTRUEB
	// TODO: Ponizsze wariacje takze.
};


struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPCOMU[] = {
	// VPCOMUB xmm1, xmm2, xmm3/mem128, imm8 8F RXB.01000 0.src.0.00 EC /r ib
	{ "vpcomub", 0x0450, 0x00D88000, { 0x08, 0xEC, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA } },
	// VPCOMUW xmm1, xmm2, xmm3/mem128, imm8 8F RXB.01000 0.src.0.00 ED /r ib
	{ "vpcomuw", 0x0450, 0x00D88000, { 0x08, 0xED, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA } },
	// VPCOMUD xmm1, xmm2, xmm3/mem128, imm8 8F RXB.01000 0.src.0.00 EE /r ib
	{ "vpcomud", 0x0450, 0x00D88000, { 0x08, 0xEE, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA } },
	// VPCOMUQ xmm1, xmm2, xmm3/mem128, imm8 8F RXB.01000 0.src.0.00 EF /r ib
	{ "vpcomuq", 0x0450, 0x00D88000, { 0x08, 0xEF, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA } }
	// TODO: Obsluzyc mnemoniki warunkowe na podstawie imm8.
	// imm8[2:0] Comparison Mnemonic
	// 000 Less Than VPCOMLTB
	// 001 Less Than or Equal VPCOMLEB
	// 010 Greater Than VPCOMGTB
	// 011 Greater Than or Equal VPCOMGEB
	// 100 Equal VPCOMEQB
	// 101 Not Equal VPCOMNEQB
	// 110 False VPCOMFALSEB
	// 111 True VPCOMTRUEB
};

// TODO: VPERMIL2PD,VPERMIL2PS

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHADDBD[] = {
	// VPHADDBD xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 C2 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xC2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHADDBW[] = {
	// VPHADDBW xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 C1 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xC1, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHADDBQ[] = {
	// VPHADDBQ xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 C3 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xC3, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHADDDQ[] = {
	// VPHADDDQ xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 CB /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xCB, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHADDUBD[] = {
	// VPHADDUBD xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 D2 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xD2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHADDUBQ[] = {
	// VPHADDUBQ xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 D3 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xD3, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHADDUBWD[] = {
	// VPHADDUBWD xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 D1 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xD1, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHADDUDQ[] = {
	// VPHADDUDQ xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 DB /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xDB, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHADDUWD[] = {
	// VPHADDUWD xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 D6 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xD6, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHADDUWQ[] = {
	// VPHADDUWQ xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 D7 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xD7, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHADDWD[] = {
	// VPHADDWD xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 C6 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xC6, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHADDWQ[] = {
	// VPHADDWQ xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 C7 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xC7, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHSUBBW[] = {
	// VPHSUBBW xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 E1 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xE1, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHSUBDQ[] = {
	// VPHSUBDQ xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 E3 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xE3, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPHSUBWD[] = {
	// VPHSUBWD xmm1, xmm2/mem128 8F RXB.01001 0.1111.0.00 E2 /r
	{ NULL, 0x0550, 0x00D88000, { 0x09, 0xE2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPMACSDD[] = {
	// VPMACSDD xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 0.src.0.00 9E /r ib
	{ NULL, 0x0450, 0x00D88000, { 0x08, 0x9E, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPMACSDQH[] = {
	// VPMACSDQH xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 0.src.0.00 9F /r ib
	{ NULL, 0x0450, 0x00D88000, { 0x08, 0x9F, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPMACSDQL[] = {
	// VPMACSDQL xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 0.src.0.00 97 /r ib
	{ NULL, 0x0450, 0x00D88000, { 0x08, 0x97, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPMACSSDD[] = {
	// VPMACSSDD xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 X.src.0.00 8E /r ib
	{ NULL, 0x0450, 0x00D88000, { 0x08, 0x8E, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPMACSSDQH[] = {
	// VPMACSSDQH xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 0.src.0.00 8F /r ib
	{ NULL, 0x0450, 0x00D88000, { 0x08, 0x8F, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPMACSSDQL[] = {
	// VPMACSSDQL xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 0.src.0.00 87 /r ib
	{ NULL, 0x0450, 0x00D88000, { 0x08, 0x87, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPMACSSWD[] = {
	// VPMACSSWD xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 0.src.0.00 86 /r ib
	{ NULL, 0x0450, 0x00D88000, { 0x08, 0x86, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPMACSSWW[] = {
	// VPMACSSWW xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 X.src.0.00 85 /r ib
	{ NULL, 0x0450, 0x00D88000, { 0x08, 0x85, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPMACSWD[] = {
	// VPMACSWD xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 0.src.0.00 96 /r ib
	{ NULL, 0x0450, 0x00D88000, { 0x08, 0x96, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPMACSWW[] = {
	// VPMACSWW xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 0.src.0.00 95 /r ib
	{ NULL, 0x0450, 0x00D88000, { 0x08, 0x95, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPMADCSSWD[] = {
	// VPMADCSSWD xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 0.src.0.00 A6 /r ib
	{ NULL, 0x0450, 0x00D88000, { 0x08, 0xA6, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPMADCSWD[] = {
	// VPMADCSWD xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 0.src.0.00 B6 /r ib
	{ NULL, 0x0450, 0x00D88000, { 0x08, 0xB6, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPPERM[] = {
	// VPPERM xmm1, xmm2, xmm3/mem128, xmm4 8F RXB.01000 0.src.0.00 A3 /r ib
	{ NULL, 0x0450, 0x00D88000, { 0x08, 0xA3, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_OP_OPERAND_IS4, FCML_NA } },
	// VPPERM xmm1, xmm2, xmm3, xmm4/mem128 8F RXB.01000 1.src.0.00 A3 /r ib
	{ NULL, 0x0448, 0x00D88000, { 0x08, 0xA3, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_OPERAND_IS4, FCML_OP_MODRM_RM_XMM_128, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPROTD[] = {
	// VPROTD xmm1, xmm2/mem128, xmm3 8F RXB.01001 0.src.0.00 92 /r
	{ NULL, 0x0450, 0x00D88000, { 0x09, 0x92, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_VEX_VVVV_XMM_REG, FCML_NA, FCML_NA } },
	// VPROTD xmm1, xmm2, xmm3/mem128 8F RXB.01001 1.src.0.00 92 /r
	{ NULL, 0x0448, 0x00D88000, { 0x09, 0x92, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VPROTD xmm1, xmm2/mem128, imm8 8F RXB.01000 0.1111.0.00 C2 /r ib
	{ NULL, 0x0550, 0x00D88000, { 0x08, 0xC2, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPROTB[] = {
	// VPROTB xmm1, xmm2/mem128, xmm3 8F RXB.01001 0.src.0.00 90 /r
	{ NULL, 0x0450, 0x00D88000, { 0x09, 0x90, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_VEX_VVVV_XMM_REG, FCML_NA, FCML_NA } },
	// VPROTB xmm1, xmm2, xmm3/mem128 8F RXB.01001 1.src.0.00 90 /r
	{ NULL, 0x0448, 0x00D88000, { 0x09, 0x90, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VPROTB xmm1, xmm2/mem128, imm8 8F RXB.01000 0.1111.0.00 C0 /r ib
	{ NULL, 0x0550, 0x00D88000, { 0x08, 0xC0, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPROTQ[] = {
	// VPROTQ xmm1, xmm2/mem128, xmm3 8F RXB.01001 0.src.0.00 93 /r
	{ NULL, 0x0450, 0x00D88000, { 0x09, 0x93, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_VEX_VVVV_XMM_REG, FCML_NA, FCML_NA } },
	// VPROTQ xmm1, xmm2, xmm3/mem128 8F RXB.01001 1.src.0.00 93 /r
	{ NULL, 0x0448, 0x00D88000, { 0x09, 0x93, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VPROTQ xmm1, xmm2/mem128, imm8 8F RXB.01000 0.1111.0.00 C3 /r ib
	{ NULL, 0x0550, 0x00D88000, { 0x08, 0xC3, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPROTW[] = {
	// VPROTW xmm1, xmm2/mem128, xmm3 8F RXB.01001 0.src.0.00 91 /r
	{ NULL, 0x0450, 0x00D88000, { 0x09, 0x91, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_VEX_VVVV_XMM_REG, FCML_NA, FCML_NA } },
	// VPROTW xmm1, xmm2, xmm3/mem128 8F RXB.01001 1.src.0.00 91 /r
	{ NULL, 0x0448, 0x00D88000, { 0x09, 0x91, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
	// VPROTW xmm1, xmm2/mem128, imm8 8F RXB.01000 0.1111.0.00 C1 /r ib
	{ NULL, 0x0550, 0x00D88000, { 0x08, 0xC1, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_IB, FCML_NA, FCML_NA } }
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPSHAB[] = {
	// VPSHAB xmm1, xmm2/mem128, xmm3 8F RXB.01001 0.src.0.00 98 /r
	{ NULL, 0x0450, 0x00D88000, { 0x09, 0x98, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_VEX_VVVV_XMM_REG, FCML_NA, FCML_NA } },
	// VPSHAB xmm1, xmm2, xmm3/mem128 8F RXB.01001 1.src.0.00 98 /r
	{ NULL, 0x0448, 0x00D88000, { 0x09, 0x98, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPSHAD[] = {
	// VPSHAD xmm1, xmm2/mem128, xmm3 8F RXB.01001 0.src.0.00 9A /r
	{ NULL, 0x0450, 0x00D88000, { 0x09, 0x9A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_VEX_VVVV_XMM_REG, FCML_NA, FCML_NA } },
	// VPSHAD xmm1, xmm2, xmm3/mem128 8F RXB.01001 1.src.0.00 9A /r
	{ NULL, 0x0448, 0x00D88000, { 0x09, 0x9A, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPSHAQ[] = {
	// VPSHAQ xmm1, xmm2/mem128, xmm3 8F RXB.01001 0.src.0.00 9B /r
	{ NULL, 0x0450, 0x00D88000, { 0x09, 0x9B, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_VEX_VVVV_XMM_REG, FCML_NA, FCML_NA } },
	// VPSHAQ xmm1, xmm2, xmm3/mem128 8F RXB.01001 1.src.0.00 9B /r
	{ NULL, 0x0448, 0x00D88000, { 0x09, 0x9B, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPSHAW[] = {
	// VPSHAW xmm1, xmm2/mem128, xmm3 8F RXB.01001 0.src.0.00 99 /r
	{ NULL, 0x0450, 0x00D88000, { 0x09, 0x99, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_VEX_VVVV_XMM_REG, FCML_NA, FCML_NA } },
	// VPSHAW xmm1, xmm2, xmm3/mem128 8F RXB.01001 1.src.0.00 99 /r
	{ NULL, 0x0448, 0x00D88000, { 0x09, 0x99, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPSHLB[] = {
	// VPSHLB xmm1, xmm2/mem128, xmm3 8F RXB.01001 0.src.0.00 94 /r
	{ NULL, 0x0450, 0x00D88000, { 0x09, 0x94, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_VEX_VVVV_XMM_REG, FCML_NA, FCML_NA } },
	// VPSHLB xmm1, xmm2, xmm3/mem128 8F RXB.01001 1.src.0.00 94 /r
	{ NULL, 0x0448, 0x00D88000, { 0x09, 0x94, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPSHLD[] = {
	// VPSHLD xmm1, xmm3/mem128, xmm2 8F RXB.01001 0.src.0.00 96 /r
	{ NULL, 0x0450, 0x00D88000, { 0x09, 0x96, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_VEX_VVVV_XMM_REG, FCML_NA, FCML_NA } },
	// VPSHLD xmm1, xmm2, xmm3/mem128 8F RXB.01001 1.src.0.00 96 /r
	{ NULL, 0x0448, 0x00D88000, { 0x09, 0x96, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPSHLQ[] = {
	// VPSHLQ xmm1, xmm3/mem128, xmm2 8F RXB.01001 0.src.0.00 97 /r
	{ NULL, 0x0450, 0x00D88000, { 0x09, 0x97, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_VEX_VVVV_XMM_REG, FCML_NA, FCML_NA } },
	// VPSHLQ xmm1, xmm2, xmm3/mem128 8F RXB.01001 1.src.0.00 97 /r
	{ NULL, 0x0448, 0x00D88000, { 0x09, 0x97, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
};

struct fcml_st_def_addr_mode_desc _fcml_st_def_addr_mode_desc_VPSHLW[] = {
	// VPSHLW xmm1, xmm3/mem128, xmm2 8F RXB.01001 0.src.0.00 95 /r
	{ NULL, 0x0450, 0x00D88000, { 0x09, 0x95, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_MODRM_RM_XMM_128, FCML_OP_VEX_VVVV_XMM_REG, FCML_NA, FCML_NA } },
	// VPSHLW xmm1, xmm2, xmm3/mem128 8F RXB.01001 1.src.0.00 95 /r
	{ NULL, 0x0448, 0x00D88000, { 0x09, 0x95, 0x00 }, { FCML_OP_MODRM_R_XMM_W, FCML_OP_VEX_VVVV_XMM_REG, FCML_OP_MODRM_RM_XMM_128, FCML_NA, FCML_NA } },
};

struct fcml_st_def_instruction_description fcml_ext_instructions_def[] = {
		FCML_IA_INSTRUCTION( "aaa", _fcml_st_def_addr_mode_desc_AAA ),
		FCML_IA_INSTRUCTION( "aad", _fcml_st_def_addr_mode_desc_AAD ),
		FCML_IA_INSTRUCTION( "aam", _fcml_st_def_addr_mode_desc_AAM ),
		FCML_IA_INSTRUCTION( "aas", _fcml_st_def_addr_mode_desc_AAS ),
		FCML_IA_INSTRUCTION( "adc", _fcml_st_def_addr_mode_desc_ADC ),
		FCML_IA_INSTRUCTION( "add", _fcml_st_def_addr_mode_desc_ADD ),
		FCML_IA_INSTRUCTION( "addpd", _fcml_st_def_addr_mode_desc_ADDPD ),
		FCML_IA_INSTRUCTION( "addps", _fcml_st_def_addr_mode_desc_ADDPS ),
		FCML_IA_INSTRUCTION( "addsd", _fcml_st_def_addr_mode_desc_ADDSD ),
		FCML_IA_INSTRUCTION( "addss", _fcml_st_def_addr_mode_desc_ADDSS ),
		FCML_IA_INSTRUCTION( "addsubpd", _fcml_st_def_addr_mode_desc_ADDSUBPD ),
		FCML_IA_INSTRUCTION( "addsubps", _fcml_st_def_addr_mode_desc_ADDSUBPS ),
		FCML_IA_INSTRUCTION( "aesdec", _fcml_st_def_addr_mode_desc_AESDEC ),
		FCML_IA_INSTRUCTION( "aesdeclast", _fcml_st_def_addr_mode_desc_AESDECLAST ),
		FCML_IA_INSTRUCTION( "aesenc", _fcml_st_def_addr_mode_desc_AESENC ),
		FCML_IA_INSTRUCTION( "aesenclast", _fcml_st_def_addr_mode_desc_AESENCLAST ),
		FCML_IA_INSTRUCTION( "aesimc", _fcml_st_def_addr_mode_desc_AESIMC ),
		FCML_IA_INSTRUCTION( "aeskeygenassist", _fcml_st_def_addr_mode_desc_AESKEYGENASSIST ),
		FCML_IA_INSTRUCTION( "and", _fcml_st_def_addr_mode_desc_AND ),
		FCML_IA_INSTRUCTION( "andpd", _fcml_st_def_addr_mode_desc_ANDPD ),
		FCML_IA_INSTRUCTION( "andps", _fcml_st_def_addr_mode_desc_ANDPS ),
		FCML_IA_INSTRUCTION( "andnpd", _fcml_st_def_addr_mode_desc_ANDNPD ),
		FCML_IA_INSTRUCTION( "andnps", _fcml_st_def_addr_mode_desc_ANDNPS ),
		FCML_IA_INSTRUCTION( "arpl", _fcml_st_def_addr_mode_desc_ARPL ),
		FCML_IA_INSTRUCTION( "blendpd", _fcml_st_def_addr_mode_desc_BLENDPD),
		FCML_IA_INSTRUCTION( "blendps", _fcml_st_def_addr_mode_desc_BLENDPS),
		FCML_IA_INSTRUCTION( "blendvpd", _fcml_st_def_addr_mode_desc_BLENDVPD),
		FCML_IA_INSTRUCTION( "blendvps", _fcml_st_def_addr_mode_desc_BLENDVPS),
		FCML_IA_INSTRUCTION( "vbroadcastss", _fcml_st_def_addr_mode_desc_VBROADCASTSS),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VPBROADCAST),
		FCML_IA_INSTRUCTION( "bound", _fcml_st_def_addr_mode_desc_BOUND),
		FCML_IA_INSTRUCTION( "bsf", _fcml_st_def_addr_mode_desc_BSF),
		FCML_IA_INSTRUCTION( "bsr", _fcml_st_def_addr_mode_desc_BSR),
		FCML_IA_INSTRUCTION( "bswap", _fcml_st_def_addr_mode_desc_BSWAP),
		FCML_IA_INSTRUCTION( "bt", _fcml_st_def_addr_mode_desc_BT),
		FCML_IA_INSTRUCTION( "btc", _fcml_st_def_addr_mode_desc_BTC),
		FCML_IA_INSTRUCTION( "btr", _fcml_st_def_addr_mode_desc_BTR),
		FCML_IA_INSTRUCTION( "bts", _fcml_st_def_addr_mode_desc_BTS),
		FCML_IA_INSTRUCTION( "call", _fcml_st_def_addr_mode_desc_CALL),
		FCML_IA_INSTRUCTION( "cbw", _fcml_st_def_addr_mode_desc_CBW),
		FCML_IA_INSTRUCTION( "clc", _fcml_st_def_addr_mode_desc_CLC),
		FCML_IA_INSTRUCTION( "cld", _fcml_st_def_addr_mode_desc_CLD),
		FCML_IA_INSTRUCTION( "clflush", _fcml_st_def_addr_mode_desc_CLFLUSH),
		FCML_IA_INSTRUCTION( "cli", _fcml_st_def_addr_mode_desc_CLI),
		FCML_IA_INSTRUCTION( "clgi", _fcml_st_def_addr_mode_desc_CLGI),
		FCML_IA_INSTRUCTION( "clts", _fcml_st_def_addr_mode_desc_CLTS),
		FCML_IA_INSTRUCTION( "cmc", _fcml_st_def_addr_mode_desc_CMC),
		FCML_IA_INSTRUCTION( "cmov", _fcml_st_def_addr_mode_desc_CMOV),
		FCML_IA_INSTRUCTION( "cmp", _fcml_st_def_addr_mode_desc_CMP),
		FCML_IA_INSTRUCTION( "cmppd", _fcml_st_def_addr_mode_desc_CMPPD),
		FCML_IA_INSTRUCTION( "cmpps", _fcml_st_def_addr_mode_desc_CMPPS),
		FCML_IA_INSTRUCTION( "cmps", _fcml_st_def_addr_mode_desc_CMPS),
		FCML_IA_INSTRUCTION( "cmpsd", _fcml_st_def_addr_mode_desc_CMPSD),
		FCML_IA_INSTRUCTION( "cmpss", _fcml_st_def_addr_mode_desc_CMPSS),
		FCML_IA_INSTRUCTION( "cmpxchg", _fcml_st_def_addr_mode_desc_CMPXCHG),
		FCML_IA_INSTRUCTION( "cmpxchg8b", _fcml_st_def_addr_mode_desc_CMPXCHGxB),
		FCML_IA_INSTRUCTION( "comisd", _fcml_st_def_addr_mode_desc_COMISD),
		FCML_IA_INSTRUCTION( "comiss", _fcml_st_def_addr_mode_desc_COMISS),
		FCML_IA_INSTRUCTION( "cpuid", _fcml_st_def_addr_mode_desc_CPUID),
		FCML_IA_INSTRUCTION( "crc32", _fcml_st_def_addr_mode_desc_CRC32),
		FCML_IA_INSTRUCTION( "cvtdq2pd", _fcml_st_def_addr_mode_desc_CVTDQ2PD),
		FCML_IA_INSTRUCTION( "cvtdq2ps", _fcml_st_def_addr_mode_desc_CVTDQ2PS),
		FCML_IA_INSTRUCTION( "cvtpd2dq", _fcml_st_def_addr_mode_desc_CVTPD2DQ),
		FCML_IA_INSTRUCTION( "cvtpd2pi", _fcml_st_def_addr_mode_desc_CVTPD2PI),
		FCML_IA_INSTRUCTION( "cvtpd2ps", _fcml_st_def_addr_mode_desc_CVTPD2PS),
		FCML_IA_INSTRUCTION( "cvtpi2pd", _fcml_st_def_addr_mode_desc_CVTPI2PD),
		FCML_IA_INSTRUCTION( "cvtpi2ps", _fcml_st_def_addr_mode_desc_CVTPI2PS),
		FCML_IA_INSTRUCTION( "cvtps2dq", _fcml_st_def_addr_mode_desc_CVTPS2DQ),
		FCML_IA_INSTRUCTION( "cvtps2pd", _fcml_st_def_addr_mode_desc_CVTPS2PD),
		FCML_IA_INSTRUCTION( "cvtps2pi", _fcml_st_def_addr_mode_desc_CVTPS2PI),
		FCML_IA_INSTRUCTION( "cvtsd2si", _fcml_st_def_addr_mode_desc_CVTSD2SI),
		FCML_IA_INSTRUCTION( "cvtsd2ss", _fcml_st_def_addr_mode_desc_CVTSD2SS),
		FCML_IA_INSTRUCTION( "cvtsi2sd", _fcml_st_def_addr_mode_desc_CVTSI2SD),
		FCML_IA_INSTRUCTION( "cvtsi2ss", _fcml_st_def_addr_mode_desc_CVTSI2SS),
		FCML_IA_INSTRUCTION( "cvtss2sd", _fcml_st_def_addr_mode_desc_CVTSS2SD),
		FCML_IA_INSTRUCTION( "cvtss2si", _fcml_st_def_addr_mode_desc_CVTSS2SI),
		FCML_IA_INSTRUCTION( "cvttpd2dq", _fcml_st_def_addr_mode_desc_CVTTPD2DQ),
		FCML_IA_INSTRUCTION( "cvttpd2pi", _fcml_st_def_addr_mode_desc_CVTTPD2PI),
		FCML_IA_INSTRUCTION( "cvttps2dq", _fcml_st_def_addr_mode_desc_CVTTPS2DQ),
		FCML_IA_INSTRUCTION( "cvttps2pi", _fcml_st_def_addr_mode_desc_CVTTPS2PI),
		FCML_IA_INSTRUCTION( "cvttsd2si", _fcml_st_def_addr_mode_desc_CVTTSD2SI),
		FCML_IA_INSTRUCTION( "cvttss2si", _fcml_st_def_addr_mode_desc_CVTTSS2SI),
		FCML_IA_INSTRUCTION( "cwd", _fcml_st_def_addr_mode_desc_CWD_CDQ_CQO),
		FCML_IA_INSTRUCTION( "daa", _fcml_st_def_addr_mode_desc_DAA),
		FCML_IA_INSTRUCTION( "das", _fcml_st_def_addr_mode_desc_DAS),
		FCML_IA_INSTRUCTION( "dec", _fcml_st_def_addr_mode_desc_DEC),
		FCML_IA_INSTRUCTION( "div", _fcml_st_def_addr_mode_desc_DIV),
		FCML_IA_INSTRUCTION( "divpd", _fcml_st_def_addr_mode_desc_DIVPD),
		FCML_IA_INSTRUCTION( "divps", _fcml_st_def_addr_mode_desc_DIVPS),
		FCML_IA_INSTRUCTION( "divsd", _fcml_st_def_addr_mode_desc_DIVSD),
		FCML_IA_INSTRUCTION( "divss", _fcml_st_def_addr_mode_desc_DIVSS),
		FCML_IA_INSTRUCTION( "dppd", _fcml_st_def_addr_mode_desc_DPPD),
		FCML_IA_INSTRUCTION( "dpps", _fcml_st_def_addr_mode_desc_DPPS),
		FCML_IA_INSTRUCTION( "emms", _fcml_st_def_addr_mode_desc_EMMS),
		FCML_IA_INSTRUCTION( "vextractf128", _fcml_st_def_addr_mode_desc_VEXTRACTF128),
		FCML_IA_INSTRUCTION( "enter", _fcml_st_def_addr_mode_desc_ENTER),
		FCML_IA_INSTRUCTION( "extractps", _fcml_st_def_addr_mode_desc_EXTRACTPS),
		FCML_IA_INSTRUCTION( "extrq", _fcml_st_def_addr_mode_desc_EXTRQ),
		FCML_IA_INSTRUCTION( "f2xm1", _fcml_st_def_addr_mode_desc_F2XM1),
		FCML_IA_INSTRUCTION( "fabs", _fcml_st_def_addr_mode_desc_FABS),
		FCML_IA_INSTRUCTION( "fadd", _fcml_st_def_addr_mode_desc_FADD),
		FCML_IA_INSTRUCTION( "fbld", _fcml_st_def_addr_mode_desc_FBLD),
		FCML_IA_INSTRUCTION( "fbstp", _fcml_st_def_addr_mode_desc_FBSTP),
		FCML_IA_INSTRUCTION( "fchs", _fcml_st_def_addr_mode_desc_FCHS),
		FCML_IA_INSTRUCTION( "fclex", _fcml_st_def_addr_mode_desc_FCLEX),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_FCMOV),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_FCOM),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_FCOMI),
		FCML_IA_INSTRUCTION( "fcos", _fcml_st_def_addr_mode_desc_FCOS),
		FCML_IA_INSTRUCTION( "fdecstp", _fcml_st_def_addr_mode_desc_FDECSTP),
		FCML_IA_INSTRUCTION( "fdiv", _fcml_st_def_addr_mode_desc_FDIV),
		FCML_IA_INSTRUCTION( "fdivr", _fcml_st_def_addr_mode_desc_FDIVR),
		FCML_IA_INSTRUCTION( "ffree", _fcml_st_def_addr_mode_desc_FFREE ),
		FCML_IA_INSTRUCTION( "ficom", _fcml_st_def_addr_mode_desc_FICOM ),
		FCML_IA_INSTRUCTION( "fild", _fcml_st_def_addr_mode_desc_FILD ),
		FCML_IA_INSTRUCTION( "fincstp", _fcml_st_def_addr_mode_desc_FINCSTP ),
		FCML_IA_INSTRUCTION( "finit", _fcml_st_def_addr_mode_desc_FINIT ),
		FCML_IA_INSTRUCTION( "fist", _fcml_st_def_addr_mode_desc_FIST ),
		FCML_IA_INSTRUCTION( "fisttp", _fcml_st_def_addr_mode_desc_FISTTP ),
		FCML_IA_INSTRUCTION( "fld", _fcml_st_def_addr_mode_desc_FLD ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_FLDx ),
		FCML_IA_INSTRUCTION( "fldcw", _fcml_st_def_addr_mode_desc_FLDCW),
		FCML_IA_INSTRUCTION( "fldenv", _fcml_st_def_addr_mode_desc_FLDENV),
		FCML_IA_INSTRUCTION( "fmul", _fcml_st_def_addr_mode_desc_FMUL ),
		FCML_IA_INSTRUCTION( "fnop", _fcml_st_def_addr_mode_desc_FNOP ),
		FCML_IA_INSTRUCTION( "fpatan", _fcml_st_def_addr_mode_desc_FPATAN ),
		FCML_IA_INSTRUCTION( "fprem", _fcml_st_def_addr_mode_desc_FPREM ),
		FCML_IA_INSTRUCTION( "fprem1", _fcml_st_def_addr_mode_desc_FPREM1 ),
		FCML_IA_INSTRUCTION( "fptan", _fcml_st_def_addr_mode_desc_FPTAN ),
		FCML_IA_INSTRUCTION( "frndint", _fcml_st_def_addr_mode_desc_FRNDINT ),
		FCML_IA_INSTRUCTION( "frstor", _fcml_st_def_addr_mode_desc_FRSTOR),
		FCML_IA_INSTRUCTION( "fsave", _fcml_st_def_addr_mode_desc_FSAVE ),
		FCML_IA_INSTRUCTION( "fscale", _fcml_st_def_addr_mode_desc_FSCALE ),
		FCML_IA_INSTRUCTION( "fsin", _fcml_st_def_addr_mode_desc_FSIN ),
		FCML_IA_INSTRUCTION( "fsincos", _fcml_st_def_addr_mode_desc_FSINCOS ),
		FCML_IA_INSTRUCTION( "fsqrt", _fcml_st_def_addr_mode_desc_FSQRT ),
		FCML_IA_INSTRUCTION( "fst", _fcml_st_def_addr_mode_desc_FST ),
		FCML_IA_INSTRUCTION( "fstcw", _fcml_st_def_addr_mode_desc_FSTCW ),
		FCML_IA_INSTRUCTION( "fstenv", _fcml_st_def_addr_mode_desc_FSTENV ),
		FCML_IA_INSTRUCTION( "fstsw", _fcml_st_def_addr_mode_desc_FSTSW ),
		FCML_IA_INSTRUCTION( "fsub", _fcml_st_def_addr_mode_desc_FSUB ),
		FCML_IA_INSTRUCTION( "fsubr", _fcml_st_def_addr_mode_desc_FSUBR ),
		FCML_IA_INSTRUCTION( "ftst", _fcml_st_def_addr_mode_desc_FTST ),
		FCML_IA_INSTRUCTION( "fucom", _fcml_st_def_addr_mode_desc_FUCOM ),
		FCML_IA_INSTRUCTION( "fxam", _fcml_st_def_addr_mode_desc_FXAM ),
		FCML_IA_INSTRUCTION( "fxch", _fcml_st_def_addr_mode_desc_FXCH ),
		FCML_IA_INSTRUCTION( "fxrstor", _fcml_st_def_addr_mode_desc_FXRSTOR ),
		FCML_IA_INSTRUCTION( "fxsave", _fcml_st_def_addr_mode_desc_FXSAVE ),
		FCML_IA_INSTRUCTION( "fxtract", _fcml_st_def_addr_mode_desc_FXTRACT ),
		FCML_IA_INSTRUCTION( "fyl2x", _fcml_st_def_addr_mode_desc_FYL2X ),
		FCML_IA_INSTRUCTION( "fyl2xp1", _fcml_st_def_addr_mode_desc_FYL2XP1 ),
		FCML_IA_INSTRUCTION( "haddpd", _fcml_st_def_addr_mode_desc_HADDPD ),
		FCML_IA_INSTRUCTION( "haddps", _fcml_st_def_addr_mode_desc_HADDPS ),
		FCML_IA_INSTRUCTION( "hlt", _fcml_st_def_addr_mode_desc_HLT ),
		FCML_IA_INSTRUCTION( "hsubpd", _fcml_st_def_addr_mode_desc_HSUBPD ),
		FCML_IA_INSTRUCTION( "hsubps", _fcml_st_def_addr_mode_desc_HSUBPS ),
		FCML_IA_INSTRUCTION( "idiv", _fcml_st_def_addr_mode_desc_IDIV ),
		FCML_IA_INSTRUCTION( "imul", _fcml_st_def_addr_mode_desc_IMUL ),
		FCML_IA_INSTRUCTION( "in", _fcml_st_def_addr_mode_desc_IN ),
		FCML_IA_INSTRUCTION( "inc", _fcml_st_def_addr_mode_desc_INC ),
		FCML_IA_INSTRUCTION( "ins", _fcml_st_def_addr_mode_desc_INS ),
		FCML_IA_INSTRUCTION( "insertps", _fcml_st_def_addr_mode_desc_INSERTPS ),
		FCML_IA_INSTRUCTION( "insertq", _fcml_st_def_addr_mode_desc_INSERTQ ),
		FCML_IA_INSTRUCTION( "vinsertf128", _fcml_st_def_addr_mode_desc_VINSERTF128 ),
		FCML_IA_INSTRUCTION( "int", _fcml_st_def_addr_mode_desc_INT ),
		FCML_IA_INSTRUCTION( "invd", _fcml_st_def_addr_mode_desc_INVD ),
		FCML_IA_INSTRUCTION( "invlpg", _fcml_st_def_addr_mode_desc_INVLPG ),
		FCML_IA_INSTRUCTION( "invlpga", _fcml_st_def_addr_mode_desc_INVLPGA ),
		FCML_IA_INSTRUCTION( "invpcid", _fcml_st_def_addr_mode_desc_INVPCID ),
		FCML_IA_INSTRUCTION( "iret", _fcml_st_def_addr_mode_desc_IRET ),
		FCML_IA_INSTRUCTION( "jcxz", _fcml_st_def_addr_mode_desc_JCXZ),
		FCML_IA_INSTRUCTION( "j", _fcml_st_def_addr_mode_desc_Jcc),
		FCML_IA_INSTRUCTION( "jmp", _fcml_st_def_addr_mode_desc_JMP),
		FCML_IA_INSTRUCTION( "lahf", _fcml_st_def_addr_mode_desc_LAHF),
		FCML_IA_INSTRUCTION( "lar", _fcml_st_def_addr_mode_desc_LAR),
		FCML_IA_INSTRUCTION( "lddqu", _fcml_st_def_addr_mode_desc_LDDQU),
		FCML_IA_INSTRUCTION( "ldmxcsr", _fcml_st_def_addr_mode_desc_LDMXCSR),
		FCML_IA_INSTRUCTION( "vldmxcsr", _fcml_st_def_addr_mode_desc_VLDMXCSR),
		FCML_IA_INSTRUCTION( "lds", _fcml_st_def_addr_mode_desc_LDS),
		FCML_IA_INSTRUCTION( "lea", _fcml_st_def_addr_mode_desc_LEA),
		FCML_IA_INSTRUCTION( "leave", _fcml_st_def_addr_mode_desc_LEAVE),
		FCML_IA_INSTRUCTION( "lfence", _fcml_st_def_addr_mode_desc_LFENCE),
		FCML_IA_INSTRUCTION( "llwpcb", _fcml_st_def_addr_mode_desc_LLWPCB),
		FCML_IA_INSTRUCTION( "lgdt", _fcml_st_def_addr_mode_desc_LGDT),
		FCML_IA_INSTRUCTION( "lldt", _fcml_st_def_addr_mode_desc_LLDT),
		FCML_IA_INSTRUCTION( "lmsw", _fcml_st_def_addr_mode_desc_LMSW),
		FCML_IA_INSTRUCTION( "lods", _fcml_st_def_addr_mode_desc_LODS),
		FCML_IA_INSTRUCTION( "loop", _fcml_st_def_addr_mode_desc_LOOP),
		FCML_IA_INSTRUCTION( "lwpins", _fcml_st_def_addr_mode_desc_LWPINS),
		FCML_IA_INSTRUCTION( "lwpval", _fcml_st_def_addr_mode_desc_LWPVAL),
		FCML_IA_INSTRUCTION( "lsl", _fcml_st_def_addr_mode_desc_LSL),
		FCML_IA_INSTRUCTION( "ltr", _fcml_st_def_addr_mode_desc_LTR),
		FCML_IA_INSTRUCTION( "maskmovdqu", _fcml_st_def_addr_mode_desc_MASKMOVDQU),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VMASKMOVP),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VPMASKMOVD),
		FCML_IA_INSTRUCTION( "maskmovq", _fcml_st_def_addr_mode_desc_MASKMOVQ),
		FCML_IA_INSTRUCTION( "maxpd", _fcml_st_def_addr_mode_desc_MAXPD),
		FCML_IA_INSTRUCTION( "maxps", _fcml_st_def_addr_mode_desc_MAXPS),
		FCML_IA_INSTRUCTION( "maxsd", _fcml_st_def_addr_mode_desc_MAXSD),
		FCML_IA_INSTRUCTION( "maxss", _fcml_st_def_addr_mode_desc_MAXSS),
		FCML_IA_INSTRUCTION( "mfence", _fcml_st_def_addr_mode_desc_MFENCE),
		FCML_IA_INSTRUCTION( "minpd", _fcml_st_def_addr_mode_desc_MINPD),
		FCML_IA_INSTRUCTION( "minps", _fcml_st_def_addr_mode_desc_MINPS),
		FCML_IA_INSTRUCTION( "minsd", _fcml_st_def_addr_mode_desc_MINSD),
		FCML_IA_INSTRUCTION( "minss", _fcml_st_def_addr_mode_desc_MINSS),
		FCML_IA_INSTRUCTION( "monitor", _fcml_st_def_addr_mode_desc_MONITOR),
		FCML_IA_INSTRUCTION( "movapd", _fcml_st_def_addr_mode_desc_MOVAPD),
		FCML_IA_INSTRUCTION( "movaps", _fcml_st_def_addr_mode_desc_MOVAPS),
		FCML_IA_INSTRUCTION( "movbe", _fcml_st_def_addr_mode_desc_MOVBE),
		FCML_IA_INSTRUCTION( "mov", _fcml_st_def_addr_mode_desc_MOV),
		FCML_IA_INSTRUCTION( "mov", _fcml_st_def_addr_mode_desc_MOV_CR),
		FCML_IA_INSTRUCTION( "mov", _fcml_st_def_addr_mode_desc_MOV_DR),
		FCML_IA_INSTRUCTION( "movd", _fcml_st_def_addr_mode_desc_MOVD),
		FCML_IA_INSTRUCTION( "movddup", _fcml_st_def_addr_mode_desc_MOVDDUP),
		FCML_IA_INSTRUCTION( "movdqa", _fcml_st_def_addr_mode_desc_MOVDQA),
		FCML_IA_INSTRUCTION( "movdqu", _fcml_st_def_addr_mode_desc_MOVDQU),
		FCML_IA_INSTRUCTION( "movdq2q", _fcml_st_def_addr_mode_desc_MOVDQ2Q),
		FCML_IA_INSTRUCTION( "movhlps", _fcml_st_def_addr_mode_desc_MOVHLPS),
		FCML_IA_INSTRUCTION( "movhpd", _fcml_st_def_addr_mode_desc_MOVHPD),
		FCML_IA_INSTRUCTION( "movhps", _fcml_st_def_addr_mode_desc_MOVHPS),
		FCML_IA_INSTRUCTION( "movlhps", _fcml_st_def_addr_mode_desc_MOVLHPS),
		FCML_IA_INSTRUCTION( "movlpd", _fcml_st_def_addr_mode_desc_MOVLPD),
		FCML_IA_INSTRUCTION( "movlps", _fcml_st_def_addr_mode_desc_MOVLPS),
		FCML_IA_INSTRUCTION( "movmskpd", _fcml_st_def_addr_mode_desc_MOVMSKPD),
		FCML_IA_INSTRUCTION( "movmskps", _fcml_st_def_addr_mode_desc_MOVMSKPS),
		FCML_IA_INSTRUCTION( "movntdqa", _fcml_st_def_addr_mode_desc_MOVNTDQA),
		FCML_IA_INSTRUCTION( "movntdq", _fcml_st_def_addr_mode_desc_MOVNTDQ),
		FCML_IA_INSTRUCTION( "movnti", _fcml_st_def_addr_mode_desc_MOVNTI),
		FCML_IA_INSTRUCTION( "movntpd", _fcml_st_def_addr_mode_desc_MOVNTPD),
		FCML_IA_INSTRUCTION( "movntps", _fcml_st_def_addr_mode_desc_MOVNTPS),
		FCML_IA_INSTRUCTION( "movntsd", _fcml_st_def_addr_mode_desc_MOVNTSD),
		FCML_IA_INSTRUCTION( "movntss", _fcml_st_def_addr_mode_desc_MOVNTSS),
		FCML_IA_INSTRUCTION( "movntq", _fcml_st_def_addr_mode_desc_MOVNTQ),
		FCML_IA_INSTRUCTION( "movq", _fcml_st_def_addr_mode_desc_MOVQ),
		FCML_IA_INSTRUCTION( "movq2dq", _fcml_st_def_addr_mode_desc_MOVQ2DQ),
		FCML_IA_INSTRUCTION( "movs", _fcml_st_def_addr_mode_desc_MOVS),
		FCML_IA_INSTRUCTION( "movsd", _fcml_st_def_addr_mode_desc_MOVSD),
		FCML_IA_INSTRUCTION( "movshdup", _fcml_st_def_addr_mode_desc_MOVSHDUP),
		FCML_IA_INSTRUCTION( "movsldup", _fcml_st_def_addr_mode_desc_MOVSLDUP),
		FCML_IA_INSTRUCTION( "movss", _fcml_st_def_addr_mode_desc_MOVSS),
		FCML_IA_INSTRUCTION( "movsx", _fcml_st_def_addr_mode_desc_MOVSX),
		FCML_IA_INSTRUCTION( "movupd", _fcml_st_def_addr_mode_desc_MOVUPD),
		FCML_IA_INSTRUCTION( "movups", _fcml_st_def_addr_mode_desc_MOVUPS),
		FCML_IA_INSTRUCTION( "movzx", _fcml_st_def_addr_mode_desc_MOVZX),
		FCML_IA_INSTRUCTION( "mpsadbw", _fcml_st_def_addr_mode_desc_MPSADBW),
		FCML_IA_INSTRUCTION( "mul", _fcml_st_def_addr_mode_desc_MUL),
		FCML_IA_INSTRUCTION( "mulpd", _fcml_st_def_addr_mode_desc_MULPD),
		FCML_IA_INSTRUCTION( "mulps", _fcml_st_def_addr_mode_desc_MULPS),
		FCML_IA_INSTRUCTION( "mulsd", _fcml_st_def_addr_mode_desc_MULSD),
		FCML_IA_INSTRUCTION( "mulss", _fcml_st_def_addr_mode_desc_MULSS),
		FCML_IA_INSTRUCTION( "mwait", _fcml_st_def_addr_mode_desc_MWAIT),
		FCML_IA_INSTRUCTION( "neg", _fcml_st_def_addr_mode_desc_NEG),
		FCML_IA_INSTRUCTION( "nop", _fcml_st_def_addr_mode_desc_NOP),
		FCML_IA_INSTRUCTION( "not", _fcml_st_def_addr_mode_desc_NOT),
		FCML_IA_INSTRUCTION( "or", _fcml_st_def_addr_mode_desc_OR),
		FCML_IA_INSTRUCTION( "orpd", _fcml_st_def_addr_mode_desc_ORPD),
		FCML_IA_INSTRUCTION( "orps", _fcml_st_def_addr_mode_desc_ORPS),
		FCML_IA_INSTRUCTION( "out", _fcml_st_def_addr_mode_desc_OUT),
		FCML_IA_INSTRUCTION( "outs", _fcml_st_def_addr_mode_desc_OUTS),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PABS),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PACKSS),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PACKUSD),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PACKUSW),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PADD),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PADDS),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PADDUS),
		FCML_IA_INSTRUCTION( "paddq", _fcml_st_def_addr_mode_desc_PADDQ),
		FCML_IA_INSTRUCTION( "palignr", _fcml_st_def_addr_mode_desc_PALIGNR),
		FCML_IA_INSTRUCTION( "pand", _fcml_st_def_addr_mode_desc_PAND),
		FCML_IA_INSTRUCTION( "pandn", _fcml_st_def_addr_mode_desc_PANDN),
		FCML_IA_INSTRUCTION( "pause", _fcml_st_def_addr_mode_desc_PAUSE),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PAVG),
		FCML_IA_INSTRUCTION( "pblendvb", _fcml_st_def_addr_mode_desc_PBLENDVB),
		FCML_IA_INSTRUCTION( "pblendw", _fcml_st_def_addr_mode_desc_PBLENDW),
		FCML_IA_INSTRUCTION( "vpblendd", _fcml_st_def_addr_mode_desc_VPBLENDD),
		FCML_IA_INSTRUCTION( "pclmulqdq", _fcml_st_def_addr_mode_desc_PCLMULQDQ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PCMPEQ),
		FCML_IA_INSTRUCTION( "pcmpeqq", _fcml_st_def_addr_mode_desc_PCMPEQQ),
		FCML_IA_INSTRUCTION( "pcmpestri", _fcml_st_def_addr_mode_desc_PCMPESTRI),
		FCML_IA_INSTRUCTION( "pcmpestrm", _fcml_st_def_addr_mode_desc_PCMPESTRM),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PCMPGT),
		FCML_IA_INSTRUCTION( "pcmpgtq", _fcml_st_def_addr_mode_desc_PCMPGTQ),
		FCML_IA_INSTRUCTION( "pcmpistri", _fcml_st_def_addr_mode_desc_PCMPISTRI),
		FCML_IA_INSTRUCTION( "pcmpistrm", _fcml_st_def_addr_mode_desc_PCMPISTRM),
		FCML_IA_INSTRUCTION( "pextr", _fcml_st_def_addr_mode_desc_PEXTR),
		FCML_IA_INSTRUCTION( "pextrw", _fcml_st_def_addr_mode_desc_PEXTRW),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PHADD),
		FCML_IA_INSTRUCTION( "phaddsw", _fcml_st_def_addr_mode_desc_PHADDSW),
		FCML_IA_INSTRUCTION( "phminposuw", _fcml_st_def_addr_mode_desc_PHMINPOSUW),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PHSUB),
		FCML_IA_INSTRUCTION( "phsubsw", _fcml_st_def_addr_mode_desc_PHSUBSW),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PINSR),
		FCML_IA_INSTRUCTION( "pinsrw", _fcml_st_def_addr_mode_desc_PINSRW),
		FCML_IA_INSTRUCTION( "pmaddubsw", _fcml_st_def_addr_mode_desc_PMADDUBSW),
		FCML_IA_INSTRUCTION( "pmaddwd", _fcml_st_def_addr_mode_desc_PMADDWD),
		FCML_IA_INSTRUCTION( "pmaxsb", _fcml_st_def_addr_mode_desc_PMAXSB),
		FCML_IA_INSTRUCTION( "pmaxsd", _fcml_st_def_addr_mode_desc_PMAXSD),
		FCML_IA_INSTRUCTION( "pmaxsw", _fcml_st_def_addr_mode_desc_PMAXSW),
		FCML_IA_INSTRUCTION( "pmaxub", _fcml_st_def_addr_mode_desc_PMAXUB),
		FCML_IA_INSTRUCTION( "pmaxud", _fcml_st_def_addr_mode_desc_PMAXUD),
		FCML_IA_INSTRUCTION( "pmaxuw", _fcml_st_def_addr_mode_desc_PMAXUW),
		FCML_IA_INSTRUCTION( "pminsb", _fcml_st_def_addr_mode_desc_PMINSB),
		FCML_IA_INSTRUCTION( "pminsd", _fcml_st_def_addr_mode_desc_PMINSD),
		FCML_IA_INSTRUCTION( "pminsw", _fcml_st_def_addr_mode_desc_PMINSW),
		FCML_IA_INSTRUCTION( "pminuw", _fcml_st_def_addr_mode_desc_PMINUW),
		FCML_IA_INSTRUCTION( "pminub", _fcml_st_def_addr_mode_desc_PMINUB),
		FCML_IA_INSTRUCTION( "pminud", _fcml_st_def_addr_mode_desc_PMINUD),
		FCML_IA_INSTRUCTION( "pmovmskb", _fcml_st_def_addr_mode_desc_PMOVMSKB),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PMOVSX),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PMOVZX),
		FCML_IA_INSTRUCTION( "pmuldq", _fcml_st_def_addr_mode_desc_PMULDQ),
		FCML_IA_INSTRUCTION( "pmulhrsw", _fcml_st_def_addr_mode_desc_PMULHRSW),
		FCML_IA_INSTRUCTION( "pmulhuw", _fcml_st_def_addr_mode_desc_PMULHUW),
		FCML_IA_INSTRUCTION( "pmulhw", _fcml_st_def_addr_mode_desc_PMULHW),
		FCML_IA_INSTRUCTION( "pmuludq", _fcml_st_def_addr_mode_desc_PMULUDQ),
		FCML_IA_INSTRUCTION( "pmullw", _fcml_st_def_addr_mode_desc_PMULLW),
		FCML_IA_INSTRUCTION( "pmulld", _fcml_st_def_addr_mode_desc_PMULLD),
		FCML_IA_INSTRUCTION( "pop", _fcml_st_def_addr_mode_desc_POP),
		FCML_IA_INSTRUCTION( "popa", _fcml_st_def_addr_mode_desc_POPA),
		FCML_IA_INSTRUCTION( "popcnt", _fcml_st_def_addr_mode_desc_POPCNT),
		FCML_IA_INSTRUCTION( "popf", _fcml_st_def_addr_mode_desc_POPF),
		FCML_IA_INSTRUCTION( "por", _fcml_st_def_addr_mode_desc_POR),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PREFETCHT),
		FCML_IA_INSTRUCTION( "psadbw", _fcml_st_def_addr_mode_desc_PSADBW),
		FCML_IA_INSTRUCTION( "pshufb", _fcml_st_def_addr_mode_desc_PSHUFB),
		FCML_IA_INSTRUCTION( "pshufd", _fcml_st_def_addr_mode_desc_PSHUFD),
		FCML_IA_INSTRUCTION( "pshufhw", _fcml_st_def_addr_mode_desc_PSHUFHW),
		FCML_IA_INSTRUCTION( "pshuflw", _fcml_st_def_addr_mode_desc_PSHUFLW),
		FCML_IA_INSTRUCTION( "pshufw", _fcml_st_def_addr_mode_desc_PSHUFW),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PSIGN),
		FCML_IA_INSTRUCTION( "pslldq", _fcml_st_def_addr_mode_desc_PSLLDQ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PSLL),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PSRA),
		FCML_IA_INSTRUCTION( "psrldq", _fcml_st_def_addr_mode_desc_PSRLDQ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PSRL),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PSUB),
		FCML_IA_INSTRUCTION( "psubq", _fcml_st_def_addr_mode_desc_PSUBQ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PSUBS),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PSUBUS),
		FCML_IA_INSTRUCTION( "ptest", _fcml_st_def_addr_mode_desc_PTEST),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PUNPCKL),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_PUNPCKH),
		FCML_IA_INSTRUCTION( "push", _fcml_st_def_addr_mode_desc_PUSH),
		FCML_IA_INSTRUCTION( "pusha", _fcml_st_def_addr_mode_desc_PUSHA),
		FCML_IA_INSTRUCTION( "pushf", _fcml_st_def_addr_mode_desc_PUSHF),
		FCML_IA_INSTRUCTION( "pxor", _fcml_st_def_addr_mode_desc_PXOR),
		FCML_IA_INSTRUCTION( "rcl", _fcml_st_def_addr_mode_desc_RCL),
		FCML_IA_INSTRUCTION( "rcr", _fcml_st_def_addr_mode_desc_RCR),
		FCML_IA_INSTRUCTION( "rol", _fcml_st_def_addr_mode_desc_ROL),
		FCML_IA_INSTRUCTION( "ror", _fcml_st_def_addr_mode_desc_ROR),
		FCML_IA_INSTRUCTION( "rcpps", _fcml_st_def_addr_mode_desc_RCPPS),
		FCML_IA_INSTRUCTION( "rcpss", _fcml_st_def_addr_mode_desc_RCPSS),
		FCML_IA_INSTRUCTION( "rdfsbase", _fcml_st_def_addr_mode_desc_RDFSBASE),
		FCML_IA_INSTRUCTION( "rdrand", _fcml_st_def_addr_mode_desc_RDRAND),
		FCML_IA_INSTRUCTION( "rdtscp", _fcml_st_def_addr_mode_desc_RDTSCP),
		FCML_IA_INSTRUCTION( "rdtsc", _fcml_st_def_addr_mode_desc_RDTSC),
		FCML_IA_INSTRUCTION( "rdpmc", _fcml_st_def_addr_mode_desc_RDPMC),
		FCML_IA_INSTRUCTION( "rdmsr", _fcml_st_def_addr_mode_desc_RDMSR),
		FCML_IA_INSTRUCTION( "ret", _fcml_st_def_addr_mode_desc_RET),
		FCML_IA_INSTRUCTION( "roundpd", _fcml_st_def_addr_mode_desc_ROUNDPD),
		FCML_IA_INSTRUCTION( "roundps", _fcml_st_def_addr_mode_desc_ROUNDPS),
		FCML_IA_INSTRUCTION( "roundsd", _fcml_st_def_addr_mode_desc_ROUNDSD),
		FCML_IA_INSTRUCTION( "roundss", _fcml_st_def_addr_mode_desc_ROUNDSS),
		FCML_IA_INSTRUCTION( "rsm", _fcml_st_def_addr_mode_desc_RSM),
		FCML_IA_INSTRUCTION( "rsqrtps", _fcml_st_def_addr_mode_desc_RSQRTPS),
		FCML_IA_INSTRUCTION( "rsqrtss", _fcml_st_def_addr_mode_desc_RSQRTSS),
		FCML_IA_INSTRUCTION( "sahf", _fcml_st_def_addr_mode_desc_SAHF),
		FCML_IA_INSTRUCTION( "sar", _fcml_st_def_addr_mode_desc_SAR),
		FCML_IA_INSTRUCTION( "shl", _fcml_st_def_addr_mode_desc_SHL),
		FCML_IA_INSTRUCTION( "shr", _fcml_st_def_addr_mode_desc_SHR),
		FCML_IA_INSTRUCTION( "sbb", _fcml_st_def_addr_mode_desc_SBB),
		FCML_IA_INSTRUCTION( "scas", _fcml_st_def_addr_mode_desc_SCAS),
		FCML_IA_INSTRUCTION( "set", _fcml_st_def_addr_mode_desc_SETcc),
		FCML_IA_INSTRUCTION( "sfence", _fcml_st_def_addr_mode_desc_SFENCE),
		FCML_IA_INSTRUCTION( "sgdt", _fcml_st_def_addr_mode_desc_SGDT),
		FCML_IA_INSTRUCTION( "shld", _fcml_st_def_addr_mode_desc_SHLD),
		FCML_IA_INSTRUCTION( "shrd", _fcml_st_def_addr_mode_desc_SHRD),
		FCML_IA_INSTRUCTION( "skinit", _fcml_st_def_addr_mode_desc_SKINIT),
		FCML_IA_INSTRUCTION( "slwpcb", _fcml_st_def_addr_mode_desc_SLWPCB),
		FCML_IA_INSTRUCTION( "shufpd", _fcml_st_def_addr_mode_desc_SHUFPD),
		FCML_IA_INSTRUCTION( "shufps", _fcml_st_def_addr_mode_desc_SHUFPS),
		FCML_IA_INSTRUCTION( "sidt", _fcml_st_def_addr_mode_desc_SIDT),
		FCML_IA_INSTRUCTION( "sldt", _fcml_st_def_addr_mode_desc_SLDT),
		FCML_IA_INSTRUCTION( "smsw", _fcml_st_def_addr_mode_desc_SMSW),
		FCML_IA_INSTRUCTION( "sqrtpd", _fcml_st_def_addr_mode_desc_SQRTPD),
		FCML_IA_INSTRUCTION( "sqrtps", _fcml_st_def_addr_mode_desc_SQRTPS),
		FCML_IA_INSTRUCTION( "sqrtsd", _fcml_st_def_addr_mode_desc_SQRTSD),
		FCML_IA_INSTRUCTION( "sqrtss", _fcml_st_def_addr_mode_desc_SQRTSS),
		FCML_IA_INSTRUCTION( "stc", _fcml_st_def_addr_mode_desc_STC),
		FCML_IA_INSTRUCTION( "std", _fcml_st_def_addr_mode_desc_STD),
		FCML_IA_INSTRUCTION( "stgi", _fcml_st_def_addr_mode_desc_STGI),
		FCML_IA_INSTRUCTION( "sti", _fcml_st_def_addr_mode_desc_STI),
		FCML_IA_INSTRUCTION( "stmxcsr", _fcml_st_def_addr_mode_desc_STMXCSR),
		FCML_IA_INSTRUCTION( "stos", _fcml_st_def_addr_mode_desc_STOS),
		FCML_IA_INSTRUCTION( "str", _fcml_st_def_addr_mode_desc_STR),
		FCML_IA_INSTRUCTION( "sub", _fcml_st_def_addr_mode_desc_SUB),
		FCML_IA_INSTRUCTION( "t1mskc", _fcml_st_def_addr_mode_desc_T1MSKC),
		FCML_IA_INSTRUCTION( "subpd", _fcml_st_def_addr_mode_desc_SUBPD),
		FCML_IA_INSTRUCTION( "subps", _fcml_st_def_addr_mode_desc_SUBPS),
		FCML_IA_INSTRUCTION( "subsd", _fcml_st_def_addr_mode_desc_SUBSD),
		FCML_IA_INSTRUCTION( "subss", _fcml_st_def_addr_mode_desc_SUBSS),
		FCML_IA_INSTRUCTION( "swapgs", _fcml_st_def_addr_mode_desc_SWAPGS),
		FCML_IA_INSTRUCTION( "syscall", _fcml_st_def_addr_mode_desc_SYSCALL),
		FCML_IA_INSTRUCTION( "sysenter", _fcml_st_def_addr_mode_desc_SYSENTER),
		FCML_IA_INSTRUCTION( "sysexit", _fcml_st_def_addr_mode_desc_SYSEXIT),
		FCML_IA_INSTRUCTION( "sysret", _fcml_st_def_addr_mode_desc_SYSRET),
		FCML_IA_INSTRUCTION( "test", _fcml_st_def_addr_mode_desc_TEST),
		FCML_IA_INSTRUCTION( "ucomisd", _fcml_st_def_addr_mode_desc_UCOMISD),
		FCML_IA_INSTRUCTION( "ucomiss", _fcml_st_def_addr_mode_desc_UCOMISS),
		FCML_IA_INSTRUCTION( "ud2", _fcml_st_def_addr_mode_desc_UD2),
		FCML_IA_INSTRUCTION( "unpckhpd", _fcml_st_def_addr_mode_desc_UNPCKHPD),
		FCML_IA_INSTRUCTION( "unpckhps", _fcml_st_def_addr_mode_desc_UNPCKHPS),
		FCML_IA_INSTRUCTION( "unpcklpd", _fcml_st_def_addr_mode_desc_UNPCKLPD),
		FCML_IA_INSTRUCTION( "unpcklps", _fcml_st_def_addr_mode_desc_UNPCKLPS),
		FCML_IA_INSTRUCTION( "vcvtph2ps", _fcml_st_def_addr_mode_desc_VCVTPH2PS),
		FCML_IA_INSTRUCTION( "vcvtps2ph", _fcml_st_def_addr_mode_desc_VCVTPS2PH),
		FCML_IA_INSTRUCTION( "verr", _fcml_st_def_addr_mode_desc_VERR),
		FCML_IA_INSTRUCTION( "verw", _fcml_st_def_addr_mode_desc_VERW),
		FCML_IA_INSTRUCTION( "vmload", _fcml_st_def_addr_mode_desc_VMLOAD),
		FCML_IA_INSTRUCTION( "vmmcall", _fcml_st_def_addr_mode_desc_VMMCALL),
		FCML_IA_INSTRUCTION( "vmrun", _fcml_st_def_addr_mode_desc_VMRUN),
		FCML_IA_INSTRUCTION( "vmsave", _fcml_st_def_addr_mode_desc_VMSAVE),
		FCML_IA_INSTRUCTION( "vpermilpd", _fcml_st_def_addr_mode_desc_VPERMILPD),
		FCML_IA_INSTRUCTION( "vpermilps", _fcml_st_def_addr_mode_desc_VPERMILPS),
		FCML_IA_INSTRUCTION( "vperm2f128", _fcml_st_def_addr_mode_desc_VPERM2F128),
		FCML_IA_INSTRUCTION( "vperm2i128", _fcml_st_def_addr_mode_desc_VPERM2I128),
		FCML_IA_INSTRUCTION( "vextracti128", _fcml_st_def_addr_mode_desc_VEXTRACTI128),
		FCML_IA_INSTRUCTION( "vinserti128", _fcml_st_def_addr_mode_desc_VINSERTI128),
		FCML_IA_INSTRUCTION( "vpsravd", _fcml_st_def_addr_mode_desc_VPSRAVD),
		FCML_IA_INSTRUCTION( "vpermd", _fcml_st_def_addr_mode_desc_VPERMD),
		FCML_IA_INSTRUCTION( "vpsllvd", _fcml_st_def_addr_mode_desc_VPSLLVD),
		FCML_IA_INSTRUCTION( "vpsrlvd", _fcml_st_def_addr_mode_desc_VPSRLVD),
		FCML_IA_INSTRUCTION( "vpermpd", _fcml_st_def_addr_mode_desc_VPERMPD),
		FCML_IA_INSTRUCTION( "vpermq", _fcml_st_def_addr_mode_desc_VPERMQ),
		FCML_IA_INSTRUCTION( "vpermps", _fcml_st_def_addr_mode_desc_VPERMPS),
		FCML_IA_INSTRUCTION( "vtestps", _fcml_st_def_addr_mode_desc_VTESTPS),
		FCML_IA_INSTRUCTION( "vgatherdpd", _fcml_st_def_addr_mode_desc_VGATHERDPD),
		FCML_IA_INSTRUCTION( "vgatherdps", _fcml_st_def_addr_mode_desc_VGATHERDPS),
		FCML_IA_INSTRUCTION( "vpgatherdd", _fcml_st_def_addr_mode_desc_VPGATHERDD),
		FCML_IA_INSTRUCTION( "vpgatherdq", _fcml_st_def_addr_mode_desc_VPGATHERDQ),
		FCML_IA_INSTRUCTION( "vzeroall", _fcml_st_def_addr_mode_desc_VZEROALL),
		FCML_IA_INSTRUCTION( "vzeroupper", _fcml_st_def_addr_mode_desc_VZEROUPPER),
		FCML_IA_INSTRUCTION( "wait", _fcml_st_def_addr_mode_desc_WAIT),
		FCML_IA_INSTRUCTION( "wbinvd", _fcml_st_def_addr_mode_desc_WBINVD),
		FCML_IA_INSTRUCTION( "wrfsbase", _fcml_st_def_addr_mode_desc_WRFSBASE),
		FCML_IA_INSTRUCTION( "wrmsr", _fcml_st_def_addr_mode_desc_WRMSR),
		FCML_IA_INSTRUCTION( "xadd", _fcml_st_def_addr_mode_desc_XADD),
		FCML_IA_INSTRUCTION( "xchg", _fcml_st_def_addr_mode_desc_XCHG),
		FCML_IA_INSTRUCTION( "xgetbv", _fcml_st_def_addr_mode_desc_XGETBV),
		FCML_IA_INSTRUCTION( "xlat", _fcml_st_def_addr_mode_desc_XLAT),
		FCML_IA_INSTRUCTION( "xor", _fcml_st_def_addr_mode_desc_XOR),
		FCML_IA_INSTRUCTION( "xorpd", _fcml_st_def_addr_mode_desc_XORPD),
		FCML_IA_INSTRUCTION( "xorps", _fcml_st_def_addr_mode_desc_XORPS),
		FCML_IA_INSTRUCTION( "xrstor", _fcml_st_def_addr_mode_desc_XRSTOR),
		FCML_IA_INSTRUCTION( "xsave", _fcml_st_def_addr_mode_desc_XSAVE),
		FCML_IA_INSTRUCTION( "xsaveopt", _fcml_st_def_addr_mode_desc_XSAVEOPT),
		FCML_IA_INSTRUCTION( "xsetbv", _fcml_st_def_addr_mode_desc_XSETBV),
		// AMD 3D Now!
		FCML_IA_INSTRUCTION( "femms", _fcml_st_def_addr_mode_desc_FEMMS),
		FCML_IA_INSTRUCTION( "pavgusb", _fcml_st_def_addr_mode_desc_PAVGUSB),
		FCML_IA_INSTRUCTION( "pf2id", _fcml_st_def_addr_mode_desc_PF2ID),
		FCML_IA_INSTRUCTION( "pfacc", _fcml_st_def_addr_mode_desc_PFACC),
		FCML_IA_INSTRUCTION( "pfadd", _fcml_st_def_addr_mode_desc_PFADD),
		FCML_IA_INSTRUCTION( "pfcmpeq", _fcml_st_def_addr_mode_desc_PFCMPEQ),
		FCML_IA_INSTRUCTION( "pfcmpge", _fcml_st_def_addr_mode_desc_PFCMPGE),
		FCML_IA_INSTRUCTION( "pfcmpgt", _fcml_st_def_addr_mode_desc_PFCMPGT),
		FCML_IA_INSTRUCTION( "pfmax", _fcml_st_def_addr_mode_desc_PFMAX),
		FCML_IA_INSTRUCTION( "pfmin", _fcml_st_def_addr_mode_desc_PFMIN),
		FCML_IA_INSTRUCTION( "pfmul", _fcml_st_def_addr_mode_desc_PFMUL),
		FCML_IA_INSTRUCTION( "pfrcp", _fcml_st_def_addr_mode_desc_PFRCP),
		FCML_IA_INSTRUCTION( "pfrcpit1", _fcml_st_def_addr_mode_desc_PFRCPIT1),
		FCML_IA_INSTRUCTION( "pfrcpit2", _fcml_st_def_addr_mode_desc_PFRCPIT2),
		FCML_IA_INSTRUCTION( "pfrsqit1", _fcml_st_def_addr_mode_desc_PFRSQIT1),
		FCML_IA_INSTRUCTION( "pfrsqrt", _fcml_st_def_addr_mode_desc_PFRSQRT),
		FCML_IA_INSTRUCTION( "pfsub", _fcml_st_def_addr_mode_desc_PFSUB),
		FCML_IA_INSTRUCTION( "pfsubr", _fcml_st_def_addr_mode_desc_PFSUBR),
		FCML_IA_INSTRUCTION( "pi2fd", _fcml_st_def_addr_mode_desc_PI2FD),
		FCML_IA_INSTRUCTION( "pmulhrw", _fcml_st_def_addr_mode_desc_PMULHRW),
		FCML_IA_INSTRUCTION( "prefetch", _fcml_st_def_addr_mode_desc_PREFETCH),
		// Extensions to the 3DNow!
		FCML_IA_INSTRUCTION( "pf2iw", _fcml_st_def_addr_mode_desc_PF2IW),
		FCML_IA_INSTRUCTION( "pfnacc", _fcml_st_def_addr_mode_desc_PFNACC),
		FCML_IA_INSTRUCTION( "pfpnacc", _fcml_st_def_addr_mode_desc_PFPNACC),
		FCML_IA_INSTRUCTION( "pi2fw", _fcml_st_def_addr_mode_desc_PI2FW),
		FCML_IA_INSTRUCTION( "pswapd", _fcml_st_def_addr_mode_desc_PSWAPD),
		// FMA
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFMADDPD ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFMADDPS ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFMADDSD ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFMADDSS ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFMADDSUBPD ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFMADDSUBPS ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFMSUBADDPD ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFMSUBADDPS ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFMSUBPD ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFMSUBPS ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFMSUBSD ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFMSUBSS ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFNMADDPD ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFNMADDPS ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFNMADDSD ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFNMADDSS ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFNMSUBPD ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFNMSUBPS ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFNMSUBSD ),
		FCML_IA_INSTRUCTION( FCML_EMPTY_MNEMONIC, _fcml_st_def_addr_mode_desc_VFNMSUBSS ),
		// XOP
		FCML_IA_INSTRUCTION( "bextr", _fcml_st_def_addr_mode_desc_BEXTR ),
		FCML_IA_INSTRUCTION( "blcfill", _fcml_st_def_addr_mode_desc_BLCFILL ),
		FCML_IA_INSTRUCTION( "blci", _fcml_st_def_addr_mode_desc_BLCI ),
		FCML_IA_INSTRUCTION( "blcic", _fcml_st_def_addr_mode_desc_BLCIC ),
		FCML_IA_INSTRUCTION( "blcmsk", _fcml_st_def_addr_mode_desc_BLCMSK ),
		FCML_IA_INSTRUCTION( "blcs", _fcml_st_def_addr_mode_desc_BLCS ),
		FCML_IA_INSTRUCTION( "blsfill", _fcml_st_def_addr_mode_desc_BLSFILL ),
		FCML_IA_INSTRUCTION( "blsic", _fcml_st_def_addr_mode_desc_BLSIC ),
		// VEX/XOP-Encoded GPR instructions.
		FCML_IA_INSTRUCTION( "andn", _fcml_st_def_addr_mode_desc_ANDN ),
		FCML_IA_INSTRUCTION( "bexr", _fcml_st_def_addr_mode_desc_BEXR ),
		FCML_IA_INSTRUCTION( "blsi", _fcml_st_def_addr_mode_desc_BLSI ),
		FCML_IA_INSTRUCTION( "blsmsk", _fcml_st_def_addr_mode_desc_BLSMSK ),
		FCML_IA_INSTRUCTION( "blsr", _fcml_st_def_addr_mode_desc_BLSR ),
		FCML_IA_INSTRUCTION( "bzhi", _fcml_st_def_addr_mode_desc_BZHI ),
		FCML_IA_INSTRUCTION( "lzcnt", _fcml_st_def_addr_mode_desc_LZCNT ),
		FCML_IA_INSTRUCTION( "mulx", _fcml_st_def_addr_mode_desc_MULX ),
		FCML_IA_INSTRUCTION( "pdep", _fcml_st_def_addr_mode_desc_PDEP ),
		FCML_IA_INSTRUCTION( "pext", _fcml_st_def_addr_mode_desc_PEXT ),
		FCML_IA_INSTRUCTION( "rorx", _fcml_st_def_addr_mode_desc_RORX ),
		FCML_IA_INSTRUCTION( "shlx", _fcml_st_def_addr_mode_desc_SHLX ),
		FCML_IA_INSTRUCTION( "shrx", _fcml_st_def_addr_mode_desc_SHRX ),
		FCML_IA_INSTRUCTION( "sarx", _fcml_st_def_addr_mode_desc_SARX ),
		FCML_IA_INSTRUCTION( "tzcnt", _fcml_st_def_addr_mode_desc_TZCNT ),
		FCML_IA_INSTRUCTION( "tzmsk", _fcml_st_def_addr_mode_desc_TZMSK ),
		// HLE
		FCML_IA_INSTRUCTION( "xabort", _fcml_st_def_addr_mode_desc_XABORT ),
		FCML_IA_INSTRUCTION( "xbegin", _fcml_st_def_addr_mode_desc_XBEGIN ),
		FCML_IA_INSTRUCTION( "xend", _fcml_st_def_addr_mode_desc_XEND ),
		FCML_IA_INSTRUCTION( "xtest", _fcml_st_def_addr_mode_desc_XTEST ),
		// END OF HLE.
		FCML_IA_INSTRUCTION( "adcx", _fcml_st_def_addr_mode_desc_ADCX ),
		FCML_IA_INSTRUCTION( "adox", _fcml_st_def_addr_mode_desc_ADOX ),
		FCML_IA_INSTRUCTION( "rdseed", _fcml_st_def_addr_mode_desc_RDSEED ),
		FCML_IA_INSTRUCTION( "clac", _fcml_st_def_addr_mode_desc_CLAC ),
		FCML_IA_INSTRUCTION( "stac", _fcml_st_def_addr_mode_desc_STAC ),
		// XOP
		FCML_IA_INSTRUCTION( "vfrczpd", _fcml_st_def_addr_mode_desc_VFRCZPD ),
		FCML_IA_INSTRUCTION( "vfrczps", _fcml_st_def_addr_mode_desc_VFRCZPS ),
		FCML_IA_INSTRUCTION( "vfrczsd", _fcml_st_def_addr_mode_desc_VFRCZSD ),
		FCML_IA_INSTRUCTION( "vfrczss", _fcml_st_def_addr_mode_desc_VFRCZSS ),
		FCML_IA_INSTRUCTION( "vpcmov", _fcml_st_def_addr_mode_desc_VPCMOV ),
		FCML_IA_INSTRUCTION( "vpcomb", _fcml_st_def_addr_mode_desc_VPCOM ),
		FCML_IA_INSTRUCTION( "vpcomu", _fcml_st_def_addr_mode_desc_VPCOMU ),
		FCML_IA_INSTRUCTION( "vphaddbd", _fcml_st_def_addr_mode_desc_VPHADDBD ),
		FCML_IA_INSTRUCTION( "vphaddbw", _fcml_st_def_addr_mode_desc_VPHADDBW ),
		FCML_IA_INSTRUCTION( "vphaddbq", _fcml_st_def_addr_mode_desc_VPHADDBQ ),
		FCML_IA_INSTRUCTION( "vphadddq", _fcml_st_def_addr_mode_desc_VPHADDDQ ),
		FCML_IA_INSTRUCTION( "vphaddubd", _fcml_st_def_addr_mode_desc_VPHADDUBD ),
		FCML_IA_INSTRUCTION( "vphaddubq", _fcml_st_def_addr_mode_desc_VPHADDUBQ ),
		FCML_IA_INSTRUCTION( "vphaddubwd", _fcml_st_def_addr_mode_desc_VPHADDUBWD ),
		FCML_IA_INSTRUCTION( "vphaddudq", _fcml_st_def_addr_mode_desc_VPHADDUDQ ),
		FCML_IA_INSTRUCTION( "vphadduwd", _fcml_st_def_addr_mode_desc_VPHADDUWD ),
		FCML_IA_INSTRUCTION( "vphadduwq", _fcml_st_def_addr_mode_desc_VPHADDUWQ ),
		FCML_IA_INSTRUCTION( "vphaddwd", _fcml_st_def_addr_mode_desc_VPHADDWD ),
		FCML_IA_INSTRUCTION( "vphaddwq", _fcml_st_def_addr_mode_desc_VPHADDWQ ),
		FCML_IA_INSTRUCTION( "vphsubbw", _fcml_st_def_addr_mode_desc_VPHSUBBW ),
		FCML_IA_INSTRUCTION( "vphsubdq", _fcml_st_def_addr_mode_desc_VPHSUBDQ ),
		FCML_IA_INSTRUCTION( "vphsubdq", _fcml_st_def_addr_mode_desc_VPHSUBDQ ),
		FCML_IA_INSTRUCTION( "vphsubwd", _fcml_st_def_addr_mode_desc_VPHSUBWD ),
		FCML_IA_INSTRUCTION( "vpmacsdd", _fcml_st_def_addr_mode_desc_VPMACSDD ),
		FCML_IA_INSTRUCTION( "vpmacsdqh", _fcml_st_def_addr_mode_desc_VPMACSDQH ),
		FCML_IA_INSTRUCTION( "vpmacsdql", _fcml_st_def_addr_mode_desc_VPMACSDQL ),
		FCML_IA_INSTRUCTION( "vpmacssdd", _fcml_st_def_addr_mode_desc_VPMACSSDD ),
		FCML_IA_INSTRUCTION( "vpmacssdqh", _fcml_st_def_addr_mode_desc_VPMACSSDQH ),
		FCML_IA_INSTRUCTION( "vpmacssdql", _fcml_st_def_addr_mode_desc_VPMACSSDQL ),
		FCML_IA_INSTRUCTION( "vpmacsswd", _fcml_st_def_addr_mode_desc_VPMACSSWD ),
		FCML_IA_INSTRUCTION( "vpmacssww", _fcml_st_def_addr_mode_desc_VPMACSSWW ),
		FCML_IA_INSTRUCTION( "vpmacswd", _fcml_st_def_addr_mode_desc_VPMACSWD ),
		FCML_IA_INSTRUCTION( "vpmacsww", _fcml_st_def_addr_mode_desc_VPMACSWW ),
		FCML_IA_INSTRUCTION( "vpmadcsswd", _fcml_st_def_addr_mode_desc_VPMADCSSWD ),
		FCML_IA_INSTRUCTION( "vpmadcswd", _fcml_st_def_addr_mode_desc_VPMADCSWD ),
		FCML_IA_INSTRUCTION( "vpperm", _fcml_st_def_addr_mode_desc_VPPERM ),
		FCML_IA_INSTRUCTION( "vprotd", _fcml_st_def_addr_mode_desc_VPROTD ),
		FCML_IA_INSTRUCTION( "vprotb", _fcml_st_def_addr_mode_desc_VPROTB ),
		FCML_IA_INSTRUCTION( "vprotq", _fcml_st_def_addr_mode_desc_VPROTQ ),
		FCML_IA_INSTRUCTION( "vprotw", _fcml_st_def_addr_mode_desc_VPROTW ),
		FCML_IA_INSTRUCTION( "vpshab", _fcml_st_def_addr_mode_desc_VPSHAB ),
		FCML_IA_INSTRUCTION( "vpshad", _fcml_st_def_addr_mode_desc_VPSHAD ),
		FCML_IA_INSTRUCTION( "vpshaq", _fcml_st_def_addr_mode_desc_VPSHAQ ),
		FCML_IA_INSTRUCTION( "vpshaw", _fcml_st_def_addr_mode_desc_VPSHAW ),
		FCML_IA_INSTRUCTION( "vpshlb", _fcml_st_def_addr_mode_desc_VPSHLB ),
		FCML_IA_INSTRUCTION( "vpshld", _fcml_st_def_addr_mode_desc_VPSHLD ),
		FCML_IA_INSTRUCTION( "vpshlq", _fcml_st_def_addr_mode_desc_VPSHLQ ),
		FCML_IA_INSTRUCTION( "vpshlw", _fcml_st_def_addr_mode_desc_VPSHLW ),
		{ NULL, 0, 0, NULL }
};

