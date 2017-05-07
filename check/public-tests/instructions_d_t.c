/*
 * FCML - Free Code Manipulation Library.
 * Copyright (C) 2010-2015 Slawomir Wojtasiak
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <fcml_assembler.h>
#include "instructions_d_t.h"
#include "instructions_base_t.h"

fcml_bool fcml_tf_instructions_d_suite_init(void) {
    return FCML_TRUE;
}

fcml_bool fcml_tf_instructions_d_suite_cleanup(void) {
    return FCML_TRUE;
}

void fcml_tf_instruction_DAA(void) {
    FCML_I32( "daa", 0x27 );
    FCML_A32( "daa", 0x27 );
    FCML_I64_FAILED( "daa", 0x27 );
}

void fcml_tf_instruction_DAS(void) {
    FCML_I32( "das", 0x2F );
    FCML_A32( "das", 0x2F );
    FCML_I64_FAILED( "das", 0x2F );
}

void fcml_tf_instruction_DEC(void) {

    FCML_I32_M( "dec eax", 2, FCML_MI( 0x48 ), FCML_MI( 0xFF, 0xC8 ) );
    FCML_A32_M( "dec %eax", 2, FCML_MI( 0x48 ), FCML_MI( 0xFF, 0xC8 ) );
    FCML_I32_M( "dec ax", 2, FCML_MI( 0x66, 0x48 ), FCML_MI( 0x66, 0xff, 0xc8 ) );
    FCML_I64_FAILED( "dec eax", 0x48 );
    FCML_I64_FAILED( "dec spl", 0x48 );

    FCML_I32( "dec byte ptr [ebx]", 0xFE, 0x0B );
    FCML_A32( "decb (%ebx)", 0xFE, 0x0B );
    FCML_A32_D( "decb %dl", 0xFE, 0xca );
    FCML_A32_A( "dec %dl", 0xFE, 0xca );
    FCML_I32( "lock dec byte ptr [ebx]", 0xF0, 0xFE, 0x0B );
    FCML_I32( "xacquire lock dec byte ptr [ebx]", 0xF2, 0xF0, 0xFE, 0x0B );
    FCML_A32( "xacquire lock decb (%ebx)", 0xF2, 0xF0, 0xFE, 0x0B );
    FCML_I32( "xrelease lock dec byte ptr [ebx]", 0xF3, 0xF0, 0xFE, 0x0B );
    FCML_I64( "dec byte ptr [rbx]", 0xFE, 0x0B );
    FCML_A64( "decb (%rbx)", 0xFE, 0x0B );
    FCML_I64_D( "dec byte ptr [rbx]", 0x48, 0xFE, 0x0B );
    FCML_I64( "dec spl", 0x40, 0xFE, 0xCC );

    FCML_I32( "dec dword ptr [ebx]", 0xFF, 0x0B );
    FCML_A32( "decl (%ebx)", 0xFF, 0x0B );
    FCML_I32( "lock dec dword ptr [ebx]", 0xF0, 0xFF, 0x0B );
    FCML_I32( "xacquire lock dec dword ptr [ebx]", 0xF2, 0xF0, 0xFF, 0x0B );
    FCML_A32( "xacquire lock decl (%ebx)", 0xF2, 0xF0, 0xFF, 0x0B );
    FCML_I32( "xrelease lock dec dword ptr [ebx]", 0xF3, 0xF0, 0xFF, 0x0B );
    FCML_I32( "dec word ptr [ebx]", 0x66, 0xFF, 0x0B );
    FCML_I64( "dec dword ptr [rbx]", 0xFF, 0x0B );
    FCML_I64( "dec qword ptr [rbx]", 0x48, 0xFF, 0x0B );
    FCML_A64( "decq (%rbx)", 0x48, 0xFF, 0x0B );
    FCML_A64( "decq %rbx", 0x48, 0xFF, 0xCB );
    FCML_A64_A( "dec %rbx", 0x48, 0xFF, 0xCB );
    FCML_I64_D( "dec word ptr [rbx]", 0x66, 0x40, 0xFF, 0x0B );
    FCML_I64( "dec r12", 0x49, 0xFF, 0xCC );
}

void fcml_tf_instruction_DIV(void) {

    FCML_I32( "div ax,byte ptr [ebx]", 0xF6, 0x33 );
    FCML_A32( "divb (%ebx),%ax", 0xF6, 0x33 );
    FCML_A32( "divb %bl,%ax", 0xF6, 0xF3 );
    FCML_A32_A( "div %bl,%ax", 0xF6, 0xF3 );
    FCML_I32( "div ax,byte ptr [ebx]", 0x66, 0xF6, 0x33 );
    FCML_I64( "div ax,sil", 0x40, 0xF6, 0xF6 );
    FCML_I64( "div ax,dh", 0xF6, 0xF6 );

    FCML_I32( "div eax,dword ptr [ebx]", 0xF7, 0x33 );
    FCML_A32( "divl (%ebx),%eax", 0xF7, 0x33 );
    FCML_I32( "div ax,word ptr [ebx]", 0x66, 0xF7, 0x33 );
    FCML_A32( "divw (%ebx),%ax", 0x66, 0xF7, 0x33 );
    FCML_I64( "div rax,rsi", 0x48, 0xF7, 0xF6 );
    FCML_A64( "divq %rsi,%rax", 0x48, 0xF7, 0xF6 );
    FCML_A64_A( "div %rsi,%rax", 0x48, 0xF7, 0xF6 );
    FCML_I64( "div eax,esi", 0xF7, 0xF6 );
}

void fcml_tf_instruction_DIVPD(void) {
    FCML_I32( "divpd xmm2,xmmword ptr [ecx+eax]", 0x66, 0x0F, 0x5E, 0x14, 0x01 );
    FCML_I64( "divpd xmm2,xmmword ptr [rcx+rax]", 0x66, 0x0F, 0x5E, 0x14, 0x01 );
    FCML_A64( "divpd (%rcx,%rax),%xmm2", 0x66, 0x0F, 0x5E, 0x14, 0x01 );

    FCML_I64_M("vdivpd ymm10,ymm14,ymmword ptr [r9+rax]", 2, FCML_MI(0x62, 0x51, 0x8d, 0x28, 0x5e, 0x14, 0x01), FCML_MI(0xc4, 0x41, 0x0d, 0x5e, 0x14, 0x01));
    FCML_A64_M("vdivpd (%r9,%rax),%ymm14,%ymm10", 2, FCML_MI(0x62, 0x51, 0x8d, 0x28, 0x5e, 0x14, 0x01), FCML_MI(0xc4, 0x41, 0x0d, 0x5e, 0x14, 0x01));
    FCML_I32_D("vdivpd xmm2,xmm7,xmmword ptr [ecx+eax]", 0xC4, 0xC1, 0x41, 0x5E, 0x14, 0x01 );
    FCML_I32_D("vdivpd xmm2,xmm2,xmmword ptr [ecx+eax]", 0xC4, 0xC1, 0x69, 0x5E, 0x14, 0x01 );
    FCML_I32_M("vdivpd xmm2,xmm7,xmmword ptr [ecx+eax]", 2, FCML_MI(0x62, 0xf1, 0xc5, 0x08, 0x5e, 0x14, 0x01), FCML_MI(0xc5, 0xc1, 0x5e, 0x14, 0x01));
    FCML_I32_M("vdivpd xmm2,xmm2,xmmword ptr [ecx+eax]", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x5e, 0x14, 0x01), FCML_MI(0xc5, 0xe9, 0x5e, 0x14, 0x01));
    FCML_A32_M("vdivpd (%ecx,%eax),%xmm2,%xmm2", 2, FCML_MI(0x62, 0xf1, 0xed, 0x08, 0x5e, 0x14, 0x01), FCML_MI(0xc5, 0xe9, 0x5e, 0x14, 0x01));

    /* AVX-512 */

    /* {k} */
    FCML_I64("vdivpd ymm10{k1},ymm14,ymmword ptr [r9+r8]", 0x62, 0x11, 0x8D, 0x29, 0x5e, 0x14, 0x01);
    FCML_A64("vdivpd (%r9,%r8),%ymm14,%ymm10{%k1}", 0x62, 0x11, 0x8D, 0x29, 0x5e, 0x14, 0x01);
    FCML_I64("vdivpd xmm10{k1},xmm14,xmmword ptr [r9+r8]", 0x62, 0x11, 0x8D, 0x09, 0x5e, 0x14, 0x01);
    FCML_A64("vdivpd (%r9,%r8),%xmm14,%xmm10{%k1}", 0x62, 0x11, 0x8D, 0x09, 0x5e, 0x14, 0x01);
    FCML_I64("vdivpd zmm1{k1},zmm2,zmmword ptr [r9+r8]", 0x62, 0x91, 0xED, 0x49, 0x5e, 0x0C, 0x01);
    FCML_A64("vdivpd (%r9,%r8),%zmm2,%zmm1{%k1}", 0x62, 0x91, 0xED, 0x49, 0x5e, 0x0C, 0x01);
    FCML_I32("vdivpd xmm1{k1},xmm1,xmmword ptr [ebp+00000000h]", 0x62, 0xF1, 0xF5, 0x09, 0x5e, 0x4D, 0x00);

    /* {k}{z} */
    FCML_I64("vdivpd ymm10{k1}{z},ymm14,ymmword ptr [r9+r8]", 0x62, 0x11, 0x8D, 0xA9, 0x5e, 0x14, 0x01);
    FCML_A64("vdivpd (%r9,%r8),%ymm14,%ymm10{%k1}{z}", 0x62, 0x11, 0x8D, 0xA9, 0x5e, 0x14, 0x01);
    FCML_I64("vdivpd xmm10{k1}{z},xmm14,xmmword ptr [r9+r8]", 0x62, 0x11, 0x8D, 0x89, 0x5e, 0x14, 0x01);
    FCML_A64("vdivpd (%r9,%r8),%xmm14,%xmm10{%k1}{z}", 0x62, 0x11, 0x8D, 0x89, 0x5e, 0x14, 0x01);
    FCML_I64("vdivpd zmm1{k1}{z},zmm2,zmmword ptr [r9+r8]", 0x62, 0x91, 0xED, 0xC9, 0x5e, 0x0C, 0x01);
    FCML_A64("vdivpd (%r9,%r8),%zmm2,%zmm1{%k1}{z}", 0x62, 0x91, 0xED, 0xC9, 0x5e, 0x0C, 0x01);
    FCML_I32("vdivpd xmm1{k1}{z},xmm1,xmmword ptr [ebp+00000000h]", 0x62, 0xF1, 0xF5, 0x89, 0x5e, 0x4D, 0x00);

    /* {bcast} */
    FCML_I64("vdivpd zmm31,zmm21,mmword ptr [rsi]{1to8}", 0x62, 0x61, 0xD5, 0x50, 0x5e, 0x3E);
    FCML_A64("vdivpd (%rsi){1to8},%zmm21,%zmm31", 0x62, 0x61, 0xD5, 0x50, 0x5e, 0x3E);
    FCML_I64("vdivpd ymm31,ymm21,mmword ptr [rsi]{1to4}", 0x62, 0x61, 0xD5, 0x30, 0x5e, 0x3E);
    FCML_A64("vdivpd (%rsi){1to4},%ymm21,%ymm31", 0x62, 0x61, 0xD5, 0x30, 0x5e, 0x3E);
    FCML_I64("vdivpd xmm31,xmm21,mmword ptr [rsi]{1to2}", 0x62, 0x61, 0xD5, 0x10, 0x5e, 0x3E);
    FCML_A64("vdivpd (%rsi){1to2},%xmm21,%xmm31", 0x62, 0x61, 0xD5, 0x10, 0x5e, 0x3E);
    FCML_I32("vdivpd xmm1,xmm1,mmword ptr [esi]{1to2}", 0x62, 0xf1, 0xF5, 0x18, 0x5e, 0x0e);

    /* {k}{z}{bcast} */
    FCML_I64("vdivpd ymm31{k7}{z},ymm21,mmword ptr [rsi]{1to4}", 0x62, 0x61, 0xD5, 0xB7, 0x5e, 0x3E);
    FCML_A64("vdivpd (%rsi){1to4},%ymm21,%ymm31{%k7}{z}", 0x62, 0x61, 0xD5, 0xB7, 0x5e, 0x3E);

    /* {rn} */
    FCML_I64("vdivpd zmm31{k7}{z},zmm21,zmm4,{rn-sae}", 0x62, 0x61, 0xD5, 0x97, 0x5e, 0xFC);
    FCML_A64("vdivpd {rn-sae},%zmm4,%zmm21,%zmm31{%k7}{z}", 0x62, 0x61, 0xD5, 0x97, 0x5e, 0xFC);
}

void fcml_tf_instruction_DIVPS(void) {
    FCML_I32( "divps xmm2,xmmword ptr [ecx+eax]", 0x0F, 0x5E, 0x14, 0x01 );
    FCML_I64( "divps xmm2,xmmword ptr [rcx+rax]", 0x0F, 0x5E, 0x14, 0x01 );
    FCML_A64( "divps (%rcx,%rax),%xmm2", 0x0f, 0x5e, 0x14, 0x01 );

    FCML_I64( "vdivps ymm10,ymm14,ymmword ptr [r9+rax]", 0xC4, 0x41, 0x0C, 0x5E, 0x14, 0x01 );
    FCML_A64( "vdivps (%r8),%ymm14,%ymm8", 0xc4, 0x41, 0x0c, 0x5e, 0x00 );
    FCML_I32_D( "vdivps xmm2,xmm7,xmmword ptr [ecx+eax]", 0xC4, 0xC1, 0x40, 0x5E, 0x14, 0x01 );
    FCML_I32_D( "vdivps xmm2,xmm2,xmmword ptr [ecx+eax]", 0xC4, 0xC1, 0x68, 0x5E, 0x14, 0x01 );
    FCML_I32( "vdivps xmm2,xmm7,xmmword ptr [ecx+eax]", 0xc5, 0xc0, 0x5e, 0x14, 0x01 );
    FCML_I32( "vdivps xmm2,xmm2,xmmword ptr [ecx+eax]", 0xc5, 0xe8, 0x5e, 0x14, 0x01 );
}

void fcml_tf_instruction_DIVSD(void) {
    FCML_I64( "divsd xmm0,mmword ptr [rax+0000000000000020h]", 0xF2, 0x0F, 0x5E, 0x40, 0x20 );
    FCML_A64( "divsd 0x0000000000000020(%rax),%xmm0", 0xf2, 0x0f, 0x5e, 0x40, 0x20 );
    FCML_I32( "divsd xmm0,xmm2", 0xF2, 0x0F, 0x5E, 0xC2 );
    FCML_I32( "divsd xmm0,mmword ptr [eax+00000020h]", 0xF2, 0x0F, 0x5E, 0x40, 0x20 );

    FCML_I32_D( "vdivsd xmm2,xmm6,mmword ptr [ecx+eax]", 0xC4, 0xE1, 0x4B, 0x5E, 0x14, 0x01 );
    FCML_I64_D( "vdivsd xmm2,xmm6,mmword ptr [rcx+rax]", 0xC4, 0xE1, 0x4B, 0x5E, 0x14, 0x01 );
    FCML_I32( "vdivsd xmm2,xmm6,mmword ptr [ecx+eax]", 0xc5, 0xcb, 0x5e, 0x14, 0x01 );
    FCML_I64( "vdivsd xmm2,xmm6,mmword ptr [rcx+rax]", 0xc5, 0xcb, 0x5e, 0x14, 0x01 );
    FCML_A64( "vdivsd (%rcx,%rax),%xmm6,%xmm2", 0xc5, 0xcb, 0x5e, 0x14, 0x01 );
}

void fcml_tf_instruction_DIVSS(void) {
    FCML_I64( "divss xmm0,dword ptr [rax+0000000000000020h]", 0xF3, 0x0F, 0x5E, 0x40, 0x20 );
    FCML_A64( "divss 0x0000000000000020(%rax),%xmm0", 0xf3, 0x0f, 0x5e, 0x40, 0x20 );
    FCML_I32( "divss xmm0,xmm2", 0xF3, 0x0F, 0x5E, 0xC2 );
    FCML_I32( "divss xmm0,dword ptr [eax+00000020h]", 0xF3, 0x0F, 0x5E, 0x40, 0x20 );

    FCML_I32_D( "vdivss xmm2,xmm6,dword ptr [ecx+eax]", 0xC4, 0xE1, 0x4A, 0x5E, 0x14, 0x01 );
    FCML_I64_D( "vdivss xmm2,xmm6,dword ptr [rcx+rax]", 0xC4, 0xE1, 0x4A, 0x5E, 0x14, 0x01 );
    FCML_I32( "vdivss xmm2,xmm6,dword ptr [ecx+eax]", 0xc5, 0xca, 0x5e, 0x14, 0x01 );
    FCML_I64( "vdivss xmm2,xmm6,dword ptr [rcx+rax]", 0xc5, 0xca, 0x5e, 0x14, 0x01 );
    FCML_A64( "vdivss (%rcx,%rax),%xmm6,%xmm2", 0xc5, 0xca, 0x5e, 0x14, 0x01 );
}

void fcml_tf_instruction_DPPD(void) {
    FCML_I32( "dppd xmm2,xmmword ptr [ecx+eax],0ffh", 0x66, 0x0F, 0x3A, 0x41, 0x14, 0x01, 0xFF );
    FCML_I64( "dppd xmm2,xmmword ptr [rcx+rax],0ffh", 0x66, 0x0F, 0x3A, 0x41, 0x14, 0x01, 0xFF );
    FCML_A64( "dppd $0xff,(%rcx,%rax),%xmm2", 0x66, 0x0f, 0x3a, 0x41, 0x14, 0x01, 0xff );

    FCML_I32( "vdppd xmm2,xmm6,xmmword ptr [ecx+eax],20h", 0xC4, 0xE3, 0x49, 0x41, 0x14, 0x01, 0x20 );
    FCML_I64( "vdppd xmm2,xmm6,xmmword ptr [rcx+rax],20h", 0xC4, 0xE3, 0x49, 0x41, 0x14, 0x01, 0x20 );
    FCML_A64( "vdppd $0x20,(%rcx,%rax),%xmm6,%xmm2", 0xc4, 0xe3, 0x49, 0x41, 0x14, 0x01, 0x20 );
}
void fcml_tf_instruction_DPPS(void) {
    FCML_I32( "dpps xmm2,xmmword ptr [ecx+eax],0ffh", 0x66, 0x0F, 0x3A, 0x40, 0x14, 0x01, 0xFF );
    FCML_I64( "dpps xmm2,xmmword ptr [rcx+rax],0ffh", 0x66, 0x0F, 0x3A, 0x40, 0x14, 0x01, 0xFF );
    FCML_A64( "dpps $0xff,(%rcx,%rax),%xmm2", 0x66, 0x0f, 0x3a, 0x40, 0x14, 0x01, 0xff );

    FCML_I32( "vdpps xmm2,xmm6,xmmword ptr [ecx+eax],20h", 0xC4, 0xE3, 0x49, 0x40, 0x14, 0x01, 0x20 );
    FCML_I64( "vdpps xmm2,xmm6,xmmword ptr [rcx+rax],20h", 0xC4, 0xE3, 0x49, 0x40, 0x14, 0x01, 0x20 );
    FCML_A64( "vdpps $0x20,(%rcx,%rax),%xmm6,%xmm2", 0xc4, 0xe3, 0x49, 0x40, 0x14, 0x01, 0x20 );
}

fcml_stf_test_case fctl_ti_instructions_d[] = {
    { "fcml_tf_instruction_DAA", fcml_tf_instruction_DAA },
    { "fcml_tf_instruction_DAS", fcml_tf_instruction_DAS },
    { "fcml_tf_instruction_DEC", fcml_tf_instruction_DEC },
    { "fcml_tf_instruction_DIV", fcml_tf_instruction_DIV },
    { "fcml_tf_instruction_DIVPD", fcml_tf_instruction_DIVPD },
    { "fcml_tf_instruction_DIVPS", fcml_tf_instruction_DIVPS },
    { "fcml_tf_instruction_DIVSD", fcml_tf_instruction_DIVSD },
    { "fcml_tf_instruction_DIVSS", fcml_tf_instruction_DIVSS },
    { "fcml_tf_instruction_DPPD", fcml_tf_instruction_DPPD },
    { "fcml_tf_instruction_DPPS", fcml_tf_instruction_DPPS },
    FCML_STF_NULL_TEST
};

fcml_stf_test_suite fctl_si_instructions_d = {
    "suite-fctl_ti_instructions_d", fcml_tf_instructions_d_suite_init, fcml_tf_instructions_d_suite_cleanup, fctl_ti_instructions_d
};



