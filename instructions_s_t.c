/*
 * instructions.c
 *
 *  Created on: 01-06-2013
 *      Author: tAs
 */

#include "fcml_env.h"
#include "fcml_assembler.h"
#include "instructions_s_t.h"

int fcml_tf_instructions_s_suite_init(void) {
	return 0;
}

int fcml_tf_instructions_s_suite_cleanup(void) {
	return 0;
}

void fcml_tf_instruction_SAHF(void) {
    // 9E SAHF
    FCML_I3264( "sahf", 0x9E );
}

void fcml_tf_instruction_SHL(void) {
    // D0 /4 SHL r/m8, 1 M1 Valid Valid Multiply r/m8 by 2, once.
    // REX + D0 /4 SHL r/m8**, 1 M1 Valid N.E. Multiply r/m8 by 2, once.
    FCML_I32_M( "shl byte ptr [eax],01h", 2, FCML_MI( 0xc0, 0x20, 0x01 ), FCML_MI( 0xd0, 0x20 ) );
    FCML_I32_M( "shl al,01h", 2, FCML_MI( 0xc0, 0xe0, 0x01 ), FCML_MI( 0xd0, 0xe0 ) );
    FCML_I64_D( "shl al,01h", 0x48, 0xD0, 0xE0 );
    // D2 /4 SHL r/m8, CL MC Valid Valid Multiply r/m8 by 2, CL times.
    // REX + D2 /4 SHL r/m8**, CL MC Valid N.E. Multiply r/m8 by 2, CL times.
    FCML_I32( "shl byte ptr [eax],cl", 0xD2, 0x20 );
    FCML_I32( "shl al,cl", 0xD2, 0xE0 );
    FCML_I64_D( "shl al,cl", 0x48, 0xD2, 0xE0 );
    // C0 /4 ib SHL r/m8, imm8 MI Valid Valid Multiply r/m8 by 2, imm8 times.
    // REX + C0 /4 ib SHL r/m8**, imm8 MI Valid N.E. Multiply r/m8 by 2, imm8 times.
    FCML_I32( "shl byte ptr [eax],0ffh", 0xC0, 0x20, 0xFF );
    FCML_I32( "shl al,0ffh", 0xC0, 0xE0, 0xFF );
    FCML_I64_D( "shl al,0ffh", 0x48, 0xC0, 0xE0, 0xFF );
    // D1 /4 SHL r/m16,1 M1 Valid Valid Multiply r/m16 by 2, once.
    // D1 /4 SHL r/m32,1 M1 Valid Valid Multiply r/m32 by 2, once.
    // REX.W + D1 /4 SHL r/m64,1 M1 Valid N.E. Multiply r/m64 by 2, once.
    FCML_I32_M( "shl dword ptr [eax],01h", 2, FCML_MI( 0xc1, 0x20, 0x01 ), FCML_MI( 0xd1, 0x20 ) );
    FCML_I32_M( "shl eax,01h", 2, FCML_MI( 0xc1, 0xe0, 0x01 ), FCML_MI( 0xd1, 0xe0 ) );
    FCML_I64_M( "shl rax,01h", 2, FCML_MI( 0x48, 0xc1, 0xe0, 0x01 ), FCML_MI( 0x48, 0xd1, 0xe0 ) );
    // D3 /4 SHL r/m16, CL MC Valid Valid Multiply r/m16 by 2, CL times.
    // D3 /4 SHL r/m32, CL MC Valid Valid Multiply r/m32 by 2, CL times.
    // REX.W + D3 /4 SHL r/m64, CL MC Valid N.E. Multiply r/m64 by 2, CL times.
    FCML_I32( "shl dword ptr [eax],cl", 0xD3, 0x20 );
    FCML_I32( "shl eax,cl", 0xD3, 0xE0 );
    FCML_I64( "shl rax,cl", 0x48, 0xD3, 0xE0 );
    // C1 /4 ib SHL r/m16, imm8 MI Valid Valid Multiply r/m16 by 2, imm8 times.
    // C1 /4 ib SHL r/m32, imm8 MI Valid Valid Multiply r/m32 by 2, imm8 times.
    // REX.W + C1 /4 ib SHL r/m64, imm8 MI Valid N.E. Multiply r/m64 by 2, imm8 times.
    FCML_I32( "shl dword ptr [eax],0ffh", 0xC1, 0x20, 0xff );
    FCML_I32( "shl eax,0ffh", 0xC1, 0xE0, 0xff );
    FCML_I64( "shl rax,0ffh", 0x48, 0xC1, 0xE0, 0xff );
}

void fcml_tf_instruction_SAL(void) {
    // D0 /4 SAL r/m8, 1 M1 Valid Valid Multiply r/m8 by 2, once.
    // REX + D0 /4 SAL r/m8**, 1 M1 Valid N.E. Multiply r/m8 by 2, once.
    FCML_I32_M_A( "sal byte ptr [eax],01h", 2, FCML_MI( 0xc0, 0x20, 0x01 ), FCML_MI( 0xd0, 0x20 ) );
    FCML_I32_M_A( "sal al,01h", 2, FCML_MI( 0xc0, 0xe0, 0x01 ), FCML_MI( 0xd0, 0xe0 ) );
    // D2 /4 SAL r/m8, CL MC Valid Valid Multiply r/m8 by 2, CL times.
    // REX + D2 /4 SAL r/m8**, CL MC Valid N.E. Multiply r/m8 by 2, CL times.
    FCML_I32_A( "sal byte ptr [eax],cl", 0xD2, 0x20 );
    FCML_I32_A( "sal al,cl", 0xD2, 0xE0 );
    // C0 /4 ib SAL r/m8, imm8 MI Valid Valid Multiply r/m8 by 2, imm8 times.
    // REX + C0 /4 ib SAL r/m8**, imm8 MI Valid N.E. Multiply r/m8 by 2, imm8 times.
    FCML_I32_A( "sal byte ptr [eax],0ffh", 0xC0, 0x20, 0xFF );
    FCML_I32_A( "sal al,0ffh", 0xC0, 0xE0, 0xFF );
    // D1 /4 SAL r/m16,1 M1 Valid Valid Multiply r/m16 by 2, once.
    // D1 /4 SAL r/m32,1 M1 Valid Valid Multiply r/m32 by 2, once.
    // REX.W + D1 /4 SAL r/m64,1 M1 Valid N.E. Multiply r/m64 by 2, once.
    FCML_I32_M_A( "sal dword ptr [eax],01h", 2, FCML_MI( 0xc1, 0x20, 0x01 ), FCML_MI( 0xd1, 0x20 ) );
    FCML_I32_M_A( "sal eax,01h", 2, FCML_MI( 0xc1, 0xe0, 0x01 ), FCML_MI( 0xd1, 0xe0 ) );
    FCML_I64_M_A( "sal rax,01h", 2, FCML_MI( 0x48, 0xc1, 0xe0, 0x01 ), FCML_MI( 0x48, 0xd1, 0xe0 ) );
    // D3 /4 SAL r/m16, CL MC Valid Valid Multiply r/m16 by 2, CL times.
    // D3 /4 SAL r/m32, CL MC Valid Valid Multiply r/m32 by 2, CL times.
    // REX.W + D3 /4 SAL r/m64, CL MC Valid N.E. Multiply r/m64 by 2, CL times.
    FCML_I32_A( "sal dword ptr [eax],cl", 0xD3, 0x20 );
    FCML_I32_A( "sal eax,cl", 0xD3, 0xE0 );
    FCML_I64_A( "sal rax,cl", 0x48, 0xD3, 0xE0 );
    // C1 /4 ib SAL r/m16, imm8 MI Valid Valid Multiply r/m16 by 2, imm8 times.
    // C1 /4 ib SAL r/m32, imm8 MI Valid Valid Multiply r/m32 by 2, imm8 times.
    // REX.W + C1 /4 ib SAL r/m64, imm8 MI Valid N.E. Multiply r/m64 by 2, imm8 times.
    FCML_I32_A( "sal dword ptr [eax],0ffh", 0xC1, 0x20, 0xff );
    FCML_I32_A( "sal eax,0ffh", 0xC1, 0xE0, 0xff );
    FCML_I64_A( "sal rax,0ffh", 0x48, 0xC1, 0xE0, 0xff );
}

void fcml_tf_instruction_SAR(void) {
    // D0 /7 SAR r/m8, 1 M1 Valid Valid Signed divide* r/m8 by 2, once.
    // REX + D0 /7 SAR r/m8**, 1 M1 Valid N.E. Signed divide* r/m8 by 2, once.
    FCML_I32_M( "sar byte ptr [eax],01h", 2, FCML_MI( 0xc0, 0x38, 0x01 ), FCML_MI( 0xd0, 0x38 ) );
    FCML_I32_M( "sar al,01h", 2, FCML_MI( 0xc0, 0xf8, 0x01 ), FCML_MI( 0xd0, 0xf8 ) );
    FCML_I64_D( "sar al,01h", 0x48, 0xD0, 0xF8 );
    // D2 /7 SAR r/m8, CL MC Valid Valid Signed divide* r/m8 by 2, CL times.
    // REX + D2 /7 SAR r/m8**, CL MC Valid N.E. Signed divide* r/m8 by 2, CL times.
    FCML_I32( "sar byte ptr [eax],cl", 0xD2, 0x38 );
    FCML_I32( "sar al,cl", 0xD2, 0xF8 );
    FCML_I64_D( "sar al,cl", 0x48, 0xD2, 0xF8 );
    // C0 /7 ib SAR r/m8, imm8 MI Valid Valid Signed divide* r/m8 by 2, imm8 time.
    // REX + C0 /7 ib SAR r/m8**, imm8 MI Valid N.E. Signed divide* r/m8 by 2, imm8 times.
    FCML_I32( "sar byte ptr [eax],0ffh", 0xC0, 0x38, 0xFF );
    FCML_I32( "sar al,0ffh", 0xC0, 0xF8, 0xFF );
    FCML_I64_D( "sar al,0ffh", 0x48, 0xC0, 0xF8, 0xFF );
    // D1 /7 SAR r/m16,1 M1 Valid Valid Signed divide* r/m16 by 2, once.
    // D1 /7 SAR r/m32, 1 M1 Valid Valid Signed divide* r/m32 by 2, once.
    // REX.W + D1 /7 SAR r/m64, 1 M1 Valid N.E. Signed divide* r/m64 by 2, once.
    FCML_I32_M( "sar dword ptr [eax],01h", 2, FCML_MI( 0xc1, 0x38, 0x01 ), FCML_MI( 0xd1, 0x38 ) );
    FCML_I32_M( "sar eax,01h", 2, FCML_MI( 0xc1, 0xf8, 0x01 ), FCML_MI( 0xd1, 0xf8 ) );
    FCML_I64_M( "sar rax,01h", 2, FCML_MI( 0x48, 0xc1, 0xf8, 0x01 ), FCML_MI( 0x48, 0xd1, 0xf8 ) );
    // D3 /7 SAR r/m16, CL MC Valid Valid Signed divide* r/m16 by 2, CL times.
    // D3 /7 SAR r/m32, CL MC Valid Valid Signed divide* r/m32 by 2, CL times.
    // REX.W + D3 /7 SAR r/m64, CL MC Valid N.E. Signed divide* r/m64 by 2, CL times.
    FCML_I32( "sar dword ptr [eax],cl", 0xD3, 0x38 );
    FCML_I32( "sar eax,cl", 0xD3, 0xF8 );
    FCML_I64( "sar rax,cl", 0x48, 0xD3, 0xF8 );
    // C1 /7 ib SAR r/m16, imm8 MI Valid Valid Signed divide* r/m16 by 2, imm8 times.
    // C1 /7 ib SAR r/m32, imm8 MI Valid Valid Signed divide* r/m32 by 2, imm8 times.
    // REX.W + C1 /7 ib SAR r/m64, imm8 MI Valid N.E. Signed divide* r/m64 by 2, imm8 times
    FCML_I32( "sar dword ptr [eax],0ffh", 0xC1, 0x38, 0xff );
    FCML_I32( "sar eax,0ffh", 0xC1, 0xF8, 0xff );
    FCML_I64( "sar rax,0ffh", 0x48, 0xC1, 0xF8, 0xff );
}

void fcml_tf_instruction_SHR(void) {
    // D0 /5 SHR r/m8,1 M1 Valid Valid Unsigned divide r/m8 by 2, once.
    // REX + D0 /5 SHR r/m8**, 1 M1 Valid N.E. Unsigned divide r/m8 by 2, once.
    FCML_I32_M( "shr byte ptr [eax],01h", 2, FCML_MI( 0xc0, 0x28, 0x01 ), FCML_MI( 0xd0, 0x28 ) );
    FCML_I32_M( "shr al,01h", 2, FCML_MI( 0xc0, 0xe8, 0x01 ), FCML_MI( 0xd0, 0xe8 ) );
    FCML_I64_D( "shr al,01h", 0x48, 0xD0, 0xE8 );
    // D2 /5 SHR r/m8, CL MC Valid Valid Unsigned divide r/m8 by 2, CL times.
    // REX + D2 /5 SHR r/m8**, CL MC Valid N.E. Unsigned divide r/m8 by 2, CL times.
    FCML_I32( "shr byte ptr [eax],cl", 0xD2, 0x28 );
    FCML_I32( "shr al,cl", 0xD2, 0xE8 );
    FCML_I64_D( "shr al,cl", 0x48, 0xD2, 0xE8 );
    // C0 /5 ib SHR r/m8, imm8 MI Valid Valid Unsigned divide r/m8 by 2, imm8 times.
    // REX + C0 /5 ib SHR r/m8**, imm8 MI Valid N.E. Unsigned divide r/m8 by 2, imm8 times.
    FCML_I32( "shr byte ptr [eax],0ffh", 0xC0, 0x28, 0xFF );
    FCML_I32( "shr al,0ffh", 0xC0, 0xE8, 0xFF );
    FCML_I64_D( "shr al,0ffh", 0x48, 0xC0, 0xE8, 0xFF );
    // D1 /5 SHR r/m16, 1 M1 Valid Valid Unsigned divide r/m16 by 2, once.
    // D1 /5 SHR r/m32, 1 M1 Valid Valid Unsigned divide r/m32 by 2, once.
    // REX.W + D1 /5 SHR r/m64, 1 M1 Valid N.E. Unsigned divide r/m64 by 2, once.
    FCML_I32_M( "shr dword ptr [eax],01h", 2, FCML_MI( 0xc1, 0x28, 0x01 ), FCML_MI( 0xd1, 0x28 ) );
    FCML_I32_M( "shr eax,01h", 2, FCML_MI( 0xc1, 0xe8, 0x01 ), FCML_MI( 0xd1, 0xe8 ) );
    FCML_I64_M( "shr rax,01h", 2, FCML_MI( 0x48, 0xc1, 0xe8, 0x01 ), FCML_MI( 0x48, 0xd1, 0xe8 ) );
    // D3 /5 SHR r/m16, CL MC Valid Valid Unsigned divide r/m16 by 2, CL times
    // D3 /5 SHR r/m32, CL MC Valid Valid Unsigned divide r/m32 by 2, CL times.
    // REX.W + D3 /5 SHR r/m64, CL MC Valid N.E. Unsigned divide r/m64 by 2, CL times.
    FCML_I32( "shr dword ptr [eax],cl", 0xD3, 0x28 );
    FCML_I32( "shr eax,cl", 0xD3, 0xE8 );
    FCML_I64( "shr rax,cl", 0x48, 0xD3, 0xE8 );
    // C1 /5 ib SHR r/m16, imm8 MI Valid Valid Unsigned divide r/m16 by 2, imm8 times.
    // C1 /5 ib SHR r/m32, imm8 MI Valid Valid Unsigned divide r/m32 by 2, imm8 times.
    // REX.W + C1 /5 ib SHR r/m64, imm8 MI Valid N.E. Unsigned divide r/m64 by 2, imm8 times.
    FCML_I32( "shr dword ptr [eax],0ffh", 0xC1, 0x28, 0xff );
    FCML_I32( "shr eax,0ffh", 0xC1, 0xE8, 0xff );
    FCML_I64( "shr rax,0ffh", 0x48, 0xC1, 0xE8, 0xff );
}

void fcml_tf_instruction_SBB(void) {
    // 1C ib SBB AL,imm8
    FCML_I32_M( "sbb al,42h", 2, FCML_MI( 0x80, 0xd8, 0x42 ), FCML_MI( 0x1c, 0x42 ) );
    FCML_I32_A_FAILED( "sbb al,42h", 0xF0, 0x80, 0xd8, 0x42 );
    // 1D iw SBB AX,imm16
    // 1D id SBB EAX,imm32
    FCML_I32_M( "sbb ax,8042h", 2, FCML_MI( 0x66, 0x81, 0xd8, 0x42, 0x80 ), FCML_MI( 0x66, 0x1d, 0x42, 0x80 ) );
    FCML_I32_M( "sbb eax,42806521h", 2, FCML_MI( 0x81, 0xd8, 0x21, 0x65, 0x80, 0x42 ), FCML_MI( 0x1d, 0x21, 0x65, 0x80, 0x42 ) );
    FCML_I64_M( "sbb ax,6521h", 2, FCML_MI( 0x66, 0x81, 0xd8, 0x21, 0x65 ), FCML_MI( 0x66, 0x1d, 0x21, 0x65 ) );
    // REX.W + 1D id SBB RAX,imm32X.
    FCML_I64_M( "sbb rax,0000000042806521h", 2, FCML_MI( 0x48, 0x81, 0xd8, 0x21, 0x65, 0x80, 0x42 ), FCML_MI( 0x48, 0x1d, 0x21, 0x65, 0x80, 0x42 ) );
    // 80 /3 ib SBB r/m8,imm8
    // REX + 80 /3 ib SBB r/m8,imm8
    FCML_I32( "lock sbb byte ptr [eax],0ffh", 0xF0, 0x80, 0x18, 0xff );
    FCML_I32_M( "sbb al,0ffh", 2, FCML_MI( 0x80, 0xd8, 0xff ), FCML_MI( 0x1c, 0xff ) );
    FCML_I64_D( "sbb byte ptr [rax],0ffh", 0x48, 0x80, 0x18, 0xff );
    FCML_I64( "sbb byte ptr [rax],0ffh", 0x80, 0x18, 0xff );
    // 81 /3 iw SBB r/m16,imm16
    // 81 /3 id SBB r/m32,imm32
    FCML_I32( "sbb ebp,04030201h", 0x81, 0xDD, 0x01, 0x02, 0x03, 0x04 );
    FCML_I32( "sbb bp,0201h", 0x66, 0x81, 0xDD, 0x01, 0x02 );
    FCML_I64_D( "sbb bp,0201h", 0x67, 0x66, 0x40, 0x81, 0xDD, 0x01, 0x02 ); // 32 bit mode doesn't not allow REX.
    // REX.W + 81 /3 id SBB r/m64,imm32
    FCML_I64( "sbb rbp,0000000004030201h", 0x48, 0x81, 0xDD, 0x01, 0x02, 0x03, 0x04 );
    // 83 /3 ib SBB r/m16,imm8
    // 83 /3 ib SBB r/m32,imm8
    FCML_I32_M( "lock sbb dword ptr [eax],0ffffffffh", 2, FCML_MI( 0xF0, 0x83, 0x18, 0xff ), FCML_MI( 0xF0, 0x81, 0x18, 0xff, 0xff, 0xff, 0xff ) );
    FCML_I32_M( "sbb word ptr [eax],0ffffh", 2, FCML_MI( 0x66, 0x83, 0x18, 0xff ), FCML_MI( 0x66, 0x81, 0x18, 0xff, 0xff ) );
    FCML_I32_M( "sbb eax,0ffffffffh", 3, FCML_MI( 0x83, 0xd8, 0xff ), FCML_MI( 0x81, 0xd8, 0xff, 0xff, 0xff, 0xff ), FCML_MI( 0x1d, 0xff, 0xff, 0xff, 0xff ) );
    // REX.W + 83 /3 ib SBB r/m64,imm8
    FCML_I64_M( "lock sbb qword ptr [rdi+0000000004030201h],0000000000000005h", 2, FCML_MI( 0xF0, 0x48, 0x83, 0x9f, 0x01, 0x02, 0x03, 0x04, 0x05 ), FCML_MI( 0xF0, 0x48, 0x81, 0x9f, 0x01, 0x02, 0x03, 0x04, 0x05, 0x00, 0x00, 0x00 ) );
    FCML_I64_M( "sbb qword ptr [rdi+0000000004030201h],0ffffffffffffffffh", 2, FCML_MI( 0x48, 0x83, 0x9f, 0x01, 0x02, 0x03, 0x04, 0xff ), FCML_MI( 0x48, 0x81, 0x9f, 0x01, 0x02, 0x03, 0x04, 0xff, 0xff, 0xff, 0xff ) );
    // 18 /r SBB r/m8,r8
    // REX + 18 /r SBB r/m8,r8
    FCML_I32( "sbb byte ptr [ebp+04030201h],ah", 0x18, 0xa5, 0x01, 0x02, 0x03, 04 );
    FCML_I64( "sbb byte ptr [rbp+0000000004030201h],spl", 0x40, 0x18, 0xa5, 0x01, 0x02, 0x03, 0x04 );
    FCML_I64( "sbb byte ptr [rbp+0000000000000001h],spl", 0x40, 0x18, 0x65, 0x01 );
    // 19 /r SBB r/m16,r16
    // 19 /r SBB r/m32,r32
    // REX.W + 19 /r SBB r/m64,r64
    FCML_I32( "lock sbb dword ptr [ebp+04030201h],esp", 0xF0, 0x19, 0xa5, 0x01, 0x02, 0x03, 04 );
    FCML_I32( "sbb word ptr [di+0201h],sp", 0x66, 0x67, 0x19, 0xa5, 0x01, 0x02 );
    FCML_I32( "sbb dword ptr [di+0201h],esp", 0x67, 0x19, 0xa5, 0x01, 0x02 );
    FCML_I64( "sbb qword ptr [r9+rcx*4+0000000000000001h],r12", 0x4D, 0x19, 0x64, 0x89, 0x01 );
    // 1A /r SBB r8,r/m8
    // REX + 1A /r SBB r8,r/m8
    FCML_I32( "sbb ah,byte ptr [ebp+04030201h]", 0x1A, 0xa5, 0x01, 0x02, 0x03, 04 );
    FCML_I64( "sbb spl,byte ptr [rbp+0000000004030201h]", 0x40, 0x1a, 0xa5, 0x01, 0x02, 0x03, 0x04 );
    FCML_I64( "sbb spl,byte ptr [rbp+0000000000000001h]", 0x40, 0x1a, 0x65, 0x01 );
    // 1B /r SBB r16,r/m16
    // 1B /r SBB r32,r/m32
    // REX.W + 1B /r SBB r64,r/m64
    FCML_I32( "sbb esp,dword ptr [ebp+04030201h]", 0x1B, 0xa5, 0x01, 0x02, 0x03, 04 );
    FCML_I32( "sbb sp,word ptr [di+0201h]", 0x66, 0x67, 0x1b, 0xa5, 0x01, 0x02 );
    FCML_I32( "sbb esp,dword ptr [di+0201h]", 0x67, 0x1B, 0xa5, 0x01, 0x02 );
    FCML_I64( "sbb r12,qword ptr [r9+rcx*4+0000000000000001h]", 0x4D, 0x1B, 0x64, 0x89, 0x01 );
}

void fcml_tf_instruction_SCAS(void) {
    // AE SCAS m8 NP Valid Valid Compare AL with byte at ES:(E)DI or RDI, then set status flags.
    FCML_I32( "scas byte ptr [edi]", 0xAE );
    // AF SCAS m16 NP Valid Valid Compare AX with word at ES:(E)DI or RDI, then set status flags.
    // AF SCAS m32 NP Valid Valid Compare EAX with doubleword at ES(E)DI or RDI then set status flags.
    // REX.W + AF SCAS m64 NP Valid N.E. Compare RAX with quadword at RDI or EDI then set status flags.
    FCML_I32( "scas dword ptr [edi]", 0xAF );
    FCML_I32( "scas word ptr [edi]", 0x66, 0xAF );
    FCML_I64( "scas qword ptr [rdi]", 0x48, 0xAF );
    // AE SCASB NP Valid Valid Compare AL with byte at ES:(E)DI or RDI then set status flags.
    // AF SCASW NP Valid Valid Compare AX with word at ES:(E)DI or RDI then set status flags.
    // AF SCASD NP Valid Valid Compare EAX with doubleword at ES:(E)DI or RDI then set status flags.
    // REX.W + AF SCASQ NP Valid N.E. Compare RAX with quadword at RDI or EDI then set status flags.
    FCML_I32_A( "scasb", 0xAE );
    FCML_I32_A( "scasw", 0x66, 0xAF );
    FCML_I32_A( "scasd", 0xAF );
    FCML_I64_A( "scasq", 0x48, 0xAF );
}

void fcml_tf_instruction_SETcc(void) {
    // 0F 97 SETA r/m8 M Valid Valid Set byte if above (CF=0 and ZF=0).
    // REX + 0F 97 SETA r/m8*
    FCML_I32( "setnbe byte ptr [eax]", 0x0F, 0x97, 0x00 );
    FCML_I32( "setnbe al", 0x0F, 0x97, 0xC0 );
    FCML_I32( "setc al", 0x0F, 0x92, 0xC0 );
    FCML_I32_A( "setb al", 0x0F, 0x92, 0xC0 );
    FCML_I64_D( "setnbe al", 0x40, 0x0F, 0x97, 0xC0 );
}

void fcml_tf_instruction_SFENCE(void) {
    // 0F AE /7 SFENCE
    FCML_I3264( "sfence", 0x0f, 0xae, 0xf8 );
}

void fcml_tf_instruction_SGDT(void) {
    // 0F 01 /0 SGDT m
    FCML_I32( "sgdt [eax]", 0x0f, 0x01, 0x00 );
    FCML_I64( "sgdt [rax]", 0x0f, 0x01, 0x00 );
}

void fcml_tf_instruction_SHLD(void) {
    // 0F A4 SHLD r/m16,r16,imm8
    // 0F A4 SHLD r/m32,r32,imm8
    // REX.W + 0F A4 SHLD r/m64,r64,imm8
    FCML_I32( "shld dword ptr [eax],eax,0ffh", 0x0f, 0xA4, 0x00, 0xFF );
    FCML_I32( "shld word ptr [eax],ax,0ffh", 0x66, 0x0f, 0xA4, 0x00, 0xFF );
    FCML_I64( "shld qword ptr [rax],rax,0ffh", 0x48, 0x0f, 0xA4, 0x00, 0xFF );
    // 0F A5 SHLD r/m16,r16,CL
    // 0F A5 SHLD r/m32,r32,CL
    // REX.W + 0F A5 SHLD r/m64,r64,CL
    FCML_I32( "shld dword ptr [eax],eax,cl", 0x0f, 0xA5, 0x00 );
    FCML_I32( "shld word ptr [eax],ax,cl", 0x66, 0x0f, 0xA5, 0x00 );
    FCML_I64( "shld qword ptr [rax],rax,cl", 0x48, 0x0f, 0xA5, 0x00 );
}

void fcml_tf_instruction_SHRD(void) {
    // 0F AC SHRD r/m16, r16, imm8 MRI Valid Valid Shift r/m16 to right imm8 places while shifting bits from r16 in from the left.
    // 0F AC SHRD r/m32, r32, imm8 MRI Valid Valid Shift r/m32 to right imm8 places while shifting bits from r32 in from the left.
    // REX.W + 0F AC SHRD r/m64, r64, imm8 MRI Valid N.E. Shift r/m64 to right imm8 places while shifting bits from r64 in from the left.
    FCML_I32( "shrd dword ptr [eax],eax,0ffh", 0x0f, 0xAC, 0x00, 0xFF );
    FCML_I32( "shrd word ptr [eax],ax,0ffh", 0x66, 0x0f, 0xAC, 0x00, 0xFF );
    FCML_I64( "shrd qword ptr [rax],rax,0ffh", 0x48, 0x0f, 0xAC, 0x00, 0xFF );
    // 0F AD SHRD r/m16, r16, CL MRC Valid Valid Shift r/m16 to right CL places while shifting bits from r16 in from the left.
    // 0F AD SHRD r/m32, r32, CL MRC Valid Valid Shift r/m32 to right CL places while shifting bits from r32 in from the left.
    // REX.W + 0F AD SHRD r/m64, r64, CL MRC Valid N.E. Shift r/m64 to right CL places while shifting bits from r64 in from the left.
    FCML_I32( "shrd dword ptr [eax],eax,cl", 0x0f, 0xAD, 0x00 );
    FCML_I32( "shrd word ptr [eax],ax,cl", 0x66, 0x0f, 0xAD, 0x00 );
    FCML_I64( "shrd qword ptr [rax],rax,cl", 0x48, 0x0f, 0xAD, 0x00 );
}

void fcml_tf_instruction_SKINIT(void) {
    // SKINIT EAX 0F 01 DE Secure initialization and jump, with attestation.
    FCML_I32( "skinit eax", 0x0F, 0x01, 0xDE );
    FCML_I64( "skinit eax", 0x0F, 0x01, 0xDE );
}

void fcml_tf_instruction_SLWPCB(void) {
    // SLWPCB reg32 8F RXB.09 0.1111.0.00 12 /1
    FCML_I32_D( "slwpcb eax", 0x8F, 0xE9, 0x60, 0x12, 0xC8 );
    FCML_I32( "slwpcb eax", 0x8F, 0xE9, 0x78, 0x12, 0xC8 );
    // SLWPCB reg64 8F RXB.09 1.1111.0.00 12 /1
    FCML_I32_D( "slwpcb eax", 0x8F, 0xE9, 0x60, 0x12, 0xC8 );
    FCML_I32( "slwpcb eax", 0x8F, 0xE9, 0x78, 0x12, 0xC8 );
}

void fcml_tf_instruction_SHUFPD(void) {
    // 66 0F C6 /r ib SHUFPD xmm1,xmm2/m128,imm8
    FCML_I32( "shufpd xmm2,xmmword ptr [ecx+eax],0ffh", 0x66, 0x0F, 0xC6, 0x14, 0x01, 0xFF );
    FCML_I64( "shufpd xmm2,xmmword ptr [rcx+rax],0ffh", 0x66, 0x0F, 0xC6, 0x14, 0x01, 0xFF );
    // VEX.NDS.128.66.0F.WIG C6 /r ib VSHUFPD xmm1,xmm2,xmm3/m128,imm8
    // VEX.NDS.256.66.0F.WIG C6 /r ib VSHUFPD ymm1,ymm2,ymm3/m256,imm8
    FCML_I32( "vshufpd xmm2,xmm6,xmmword ptr [ecx+eax],20h", 0xc5, 0xc9, 0xc6, 0x14, 0x01, 0x20 );
    FCML_I64( "vshufpd xmm2,xmm6,xmmword ptr [rcx+rax],20h", 0xc5, 0xc9, 0xc6, 0x14, 0x01, 0x20 );
}

void fcml_tf_instruction_SHUFPS(void) {
    // 0F C6 /r ib SHUFPS xmm1, xmm2/m128, imm8 RMI V/V SSE Shuffle packed single-precision floating-point values selected by imm8 from xmm1 and xmm1/m128 to xmm1.
    FCML_I32( "shufps xmm2,xmmword ptr [ecx+eax],0ffh", 0x0F, 0xC6, 0x14, 0x01, 0xFF );
    FCML_I64( "shufps xmm2,xmmword ptr [rcx+rax],0ffh", 0x0F, 0xC6, 0x14, 0x01, 0xFF );
    // VEX.NDS.128.0F.WIG C6 /r ib VSHUFPS xmm1, xmm2, xmm3/m128, imm8 RVMI V/V AVX Shuffle Packed single-precision floating-point values selected by imm8 from xmm2 and xmm3/mem.
    // VEX.NDS.256.0F.WIG C6 /r ib VSHUFPS ymm1, ymm2, ymm3/m256, imm8 RVMI V/V AVX Shuffle Packed single-precision floating-point values selected by imm8 from ymm2 and ymm3/mem.
    FCML_I32( "vshufps xmm2,xmm6,xmmword ptr [ecx+eax],20h", 0xc5, 0xc8, 0xc6, 0x14, 0x01, 0x20 );
    FCML_I64( "vshufps xmm2,xmm6,xmmword ptr [rcx+rax],20h", 0xc5, 0xc8, 0xc6, 0x14, 0x01, 0x20 );
}

void fcml_tf_instruction_SIDT(void) {
    // 0F 01 /1 SIDT m M Valid Valid Store IDTR to m.
    FCML_I32( "sidt [eax]", 0x0f, 0x01, 0x08 );
    FCML_I64( "sidt [rax]", 0x0f, 0x01, 0x08 );
}

void fcml_tf_instruction_SLDT(void) {
    // 0F 00 /0 SLDT r/m16 M Valid Valid Stores segment selector from LDTR in r/m16.
    FCML_I32( "sldt word ptr [eax]", 0x0f, 0x00, 0x00 );
    FCML_I64( "sldt ax", 0x0f, 0x00, 0xC0 );
    // REX.W + 0F 00 /0 SLDT r64/m16 M Valid Valid Stores segment selector from LDTR in r64/m16.
    FCML_I64( "sldt rax", 0x48, 0x0f, 0x00, 0xC0 );
    FCML_I64_D( "sldt word ptr [rax]", 0x48, 0x0f, 0x00, 0x00 );
}

void fcml_tf_instruction_SMSW(void) {
    // 0F 01 /4 SMSW r/m16 M Valid Valid Store machine status word to r/m16.
    // 0F 01 /4 SMSW r32/m16 M Valid Valid Store machine status word in low-order 16 bits of r32/m16; high-order 16 bits of r32 are undefined.
    // REX.W + 0F 01 /4 SMSW r64/m16 M Valid Valid Store machine status word in low-order 16 bits of r64/m16; high-order 16 bits of r32 are undefined.
    FCML_I32( "smsw word ptr [eax]", 0x0f, 0x01, 0x20 );
    FCML_I32( "smsw eax", 0x0f, 0x01, 0xE0 );
    FCML_I32( "smsw word ptr [eax]", 0x66, 0x0f, 0x01, 0x20 );
    FCML_I32( "smsw ax", 0x66, 0x0f, 0x01, 0xE0 );
    FCML_I64_D( "smsw word ptr [rax]", 0x48, 0x0f, 0x01, 0x20 );
    FCML_I64( "smsw rax", 0x48, 0x0f, 0x01, 0xE0 );
}

void fcml_tf_instruction_SQRTPD(void) {
    // 66 0F 51 /r SQRTPD xmm1,xmm2/m128 RM V/V SSE2 Computes square roots of the packed doubleprecision floating-point values in xmm2/m128 and stores the results in xmm1.
    FCML_I64( "sqrtpd xmm0,xmmword ptr [rax]", 0x66, 0x0F, 0x51, 0x00 );
    FCML_I32( "sqrtpd xmm0,xmm1", 0x66, 0x0F, 0x51, 0xC1 );
    // VEX.128.66.0F.WIG 51 /r VSQRTPD xmm1,xmm2/m128 RM V/V AVX Computes Square Roots of the packed doubleprecision floating-point values in xmm2/m128 and stores the result in xmm1.
    // VEX.256.66.0F.WIG 51 /r VSQRTPD ymm1,ymm2/m256 RM V/V AVX Computes Square Roots of the packed doubleprecision floating-point values in ymm2/m256 and stores the result in ymm1.
    FCML_I64( "vsqrtpd xmm3,xmm0", 0xc5, 0xf9, 0x51, 0xd8 );
    FCML_I32( "vsqrtpd xmm3,xmm0", 0xc5, 0xf9, 0x51, 0xd8 );
    FCML_I32( "vsqrtpd ymm0,ymmword ptr [eax]", 0xc5, 0xfd, 0x51, 0x00 );
}

void fcml_tf_instruction_SQRTPS(void) {
    // 0F 51 /r SQRTPS xmm1,xmm2/m128
    FCML_I64( "sqrtps xmm0,xmmword ptr [rax]", 0x0F, 0x51, 0x00 );
    FCML_I32( "sqrtps xmm0,xmm1", 0x0F, 0x51, 0xC1 );
    // VEX.128.0F.WIG 51 /r VSQRTPS xmm1,xmm2/m128
    // VEX.256.0F.WIG 51 /r VSQRTPS ymm1,ymm2/m256
    FCML_I64( "vsqrtps xmm3,xmm0", 0xc5, 0xf8, 0x51, 0xd8 );
    FCML_I32( "vsqrtps xmm3,xmm0", 0xc5, 0xf8, 0x51, 0xd8 );
    FCML_I32( "vsqrtps ymm0,ymmword ptr [eax]", 0xc5, 0xfc, 0x51, 0x00 );
}

void fcml_tf_instruction_SQRTSD(void) {
    // F2 0F 51 /r SQRTSD xmm1,xmm2/m64
    FCML_I32( "sqrtsd xmm2,mmword ptr [ecx+eax]", 0xF2, 0x0F, 0x51, 0x14, 0x01 );
    FCML_I64( "sqrtsd xmm2,mmword ptr [rcx+rax]", 0xF2, 0x0F, 0x51, 0x14, 0x01 );
    // VEX.NDS.LIG.F2.0F.WIG 51 /r VSQRTSD xmm1,xmm2,xmm3/m64
    FCML_I32( "vsqrtsd xmm2,xmm5,mmword ptr [ecx+eax]", 0xc5, 0xd3, 0x51, 0x14, 0x01 );
    FCML_I32( "vsqrtsd xmm2,xmm4,mmword ptr [ecx+eax]", 0xC5, 0xDB, 0x51, 0x14, 0x01 );
}

void fcml_tf_instruction_SQRTSS(void) {
    // F3 0F 51 /r SQRTSS xmm1,xmm2/m32
    FCML_I32( "sqrtss xmm2,dword ptr [ecx+eax]", 0xF3, 0x0F, 0x51, 0x14, 0x01 );
    FCML_I64( "sqrtss xmm2,dword ptr [rcx+rax]", 0xF3, 0x0F, 0x51, 0x14, 0x01 );
    FCML_I64( "sqrtss xmm0,xmm0", 0xF3, 0x0F, 0x51, 0xC0 );
    // VEX.NDS.LIG.F3.0F.WIG 51 VSQRTSS xmm1, xmm2, xmm3/m32
    FCML_I32( "vsqrtss xmm2,xmm5,dword ptr [ecx+eax]", 0xc5, 0xd2, 0x51, 0x14, 0x01 );
    FCML_I32( "vsqrtss xmm2,xmm4,dword ptr [ecx+eax]", 0xC5, 0xDA, 0x51, 0x14, 0x01 );
}

void fcml_tf_instruction_STC(void) {
    // F9 STC NP Valid Valid Set CF flag.
    FCML_I3264( "stc", 0xF9 );
}

void fcml_tf_instruction_STD(void) {
    // FD STD NP Valid Valid Set DF flag.
    FCML_I3264( "std", 0xFD );
}

void fcml_tf_instruction_STGI(void) {
    // STGI 0F 01 DC Sets the global interrupt flag (GIF)
    FCML_I3264( "stgi", 0x0F, 0x01, 0xDC );
}

void fcml_tf_instruction_STI(void) {
    // FB STI NP Valid Valid Set interrupt flag; external, maskable interrupts enabled at the end of the next instruction.
    FCML_I3264( "sti", 0xFB );
}

void fcml_tf_instruction_STMXCSR(void) {
    // 0F AE /3 STMXCSR m32 M V/V SSE Store contents of MXCSR register to m32.
    FCML_I32( "stmxcsr dword ptr [eax+00000020h]", 0x0F, 0xAE, 0x58, 0x20 );
    FCML_I64( "stmxcsr dword ptr [rax+0000000000000020h]", 0x0F, 0xAE, 0x58, 0x20 );
    // VEX.LZ.0F.WIG AE /3 VSTMXCSR m32 M V/V AVX Store contents of MXCSR register to m32.
    FCML_I64( "vstmxcsr dword ptr [r8]", 0xC4, 0xC1, 0x78, 0xAE, 0x18 );
    FCML_I32( "vstmxcsr dword ptr [eax]", 0xc5, 0xf8, 0xae, 0x18 );
    FCML_I32( "vstmxcsr dword ptr [eax]", 0xC5, 0xF8, 0xAE, 0x18 );
}

void fcml_tf_instruction_STOS(void) {
    // AA STOS m8 NA Valid Valid For legacy mode, store AL at address ES:(E)DI; For 64-bit mode store AL at address RDI or EDI.
    FCML_I32( "stos byte ptr [si],byte ptr [di]", 0x67, 0xAA );
    FCML_I32_D( "stos byte ptr [si],byte ptr [di]", 0x66, 0x67, 0xAA );
    FCML_I32( "stos byte ptr [esi],byte ptr [edi]", 0xAA );
    FCML_I64_D( "stos byte ptr [rsi],byte ptr [rdi]", 0x48, 0xAA );
    FCML_I64_D( "stos byte ptr [rsi],byte ptr [rdi]", 0x40, 0xAA );
    FCML_I64_D( "stos byte ptr [esi],byte ptr [edi]", 0x67, 0x40, 0xAA );
    FCML_I64_D( "stos byte ptr [esi],byte ptr [edi]", 0x66, 0x67, 0x40, 0xAA );
    // AB STOS m16 NA Valid Valid For legacy mode, store AX at address ES:(E)DI; For 64-bit mode store AX at address RDI or EDI.
    // AB STOS m32 NA Valid Valid For legacy mode, store EAX at address ES:(E)DI; For 64-bit mode store EAX at address RDI or EDI.
    // REX.W + AB STOS m64 NA Valid N.E. Store RAX at address RDI or EDI.
    FCML_I32( "stos dword ptr [si],dword ptr [di]", 0x67, 0xAB );
    FCML_I32( "stos word ptr [si],word ptr [di]", 0x66, 0x67, 0xAB );
    FCML_I32( "stos dword ptr [esi],dword ptr [edi]", 0xAB );
    FCML_I64( "stos qword ptr [rsi],qword ptr [rdi]", 0x48, 0xAB );
    FCML_I64_D( "stos dword ptr [rsi],dword ptr [rdi]", 0x40, 0xAB );
    FCML_I64_D( "stos dword ptr [esi],dword ptr [edi]", 0x67, 0x40, 0xAB );
    FCML_I64_D( "stos word ptr [esi],word ptr [edi]", 0x66, 0x67, 0x40, 0xAB );
    // AA STOSB NA Valid Valid For legacy mode, store AL at address ES:(E)DI; For 64-bit mode store AL at address RDI or EDI.
    // AB STOSW NA Valid Valid For legacy mode, store AX at address ES:(E)DI; For 64-bit mode store AX at address RDI or EDI.
    // AB STOSD NA Valid Valid For legacy mode, store EAX at address ES:(E)DI; For 64-bit mode store EAX at address RDI or EDI.
    // REX.W + AB STOSQ NA Valid N.E. Store RAX at address RDI or EDI.
    FCML_I32_A( "stosb", 0xAA );
    FCML_I32_A( "stosw", 0x66, 0xAB );
    FCML_I32_A( "stosd", 0xAB );
    FCML_I64_A( "stosq", 0x48, 0xAB );
}

void fcml_tf_instruction_STR(void) {
    // 0F 00 /1 STR r/m16 M Valid Valid Stores segment selector from TR in r/m16.
    FCML_I32( "str word ptr [eax]",  0x0F, 0x00, 0x08 );
    FCML_I64( "str word ptr [rax]", 0x0F, 0x00, 0x08 );
}

void fcml_tf_instruction_SUB(void) {
    // 2C ib SUB AL, imm8 I Valid Valid Subtract imm8 from AL.
    FCML_I32_M( "sub al,42h", 2, FCML_MI( 0x80, 0xe8, 0x42 ), FCML_MI( 0x2c, 0x42 ) );
    FCML_I32_A_FAILED( "lock sub al,42h", 0xF0, 0x80, 0xe8, 0x42 );
    // 2D iw SUB AX, imm16 I Valid Valid Subtract imm16 from AX.
    // 2D id SUB EAX, imm32 I Valid Valid Subtract imm32 from EAX.
    FCML_I32_M( "sub ax,8042h", 2, FCML_MI( 0x66, 0x81, 0xe8, 0x42, 0x80 ), FCML_MI( 0x66, 0x2d, 0x42, 0x80 ) );
    FCML_I32_M( "sub eax,42806521h", 2, FCML_MI( 0x81, 0xe8, 0x21, 0x65, 0x80, 0x42 ), FCML_MI( 0x2d, 0x21, 0x65, 0x80, 0x42 ) );
    FCML_I64_M( "sub eax,42806521h", 2, FCML_MI( 0x81, 0xe8, 0x21, 0x65, 0x80, 0x42 ), FCML_MI( 0x2d, 0x21, 0x65, 0x80, 0x42 ) );
    FCML_I64_M( "sub ax,6521h", 2, FCML_MI( 0x66, 0x81, 0xe8, 0x21, 0x65 ), FCML_MI( 0x66, 0x2d, 0x21, 0x65 ) );
    // REX.W + 2D id SUB RAX, imm32 I Valid N.E. Subtract imm32 sign-extended to 64-bits from RAX.
    FCML_I64_M( "sub rax,0000000042806521h", 2, FCML_MI( 0x48, 0x81, 0xe8, 0x21, 0x65, 0x80, 0x42 ), FCML_MI( 0x48, 0x2d, 0x21, 0x65, 0x80, 0x42 ) );
    FCML_I64_M( "sub rax,0ffffffffffffffffh", 3, FCML_MI( 0x48, 0x83, 0xe8, 0xff ), FCML_MI( 0x48, 0x81, 0xe8, 0xff, 0xff, 0xff, 0xff ), FCML_MI( 0x48, 0x2d, 0xff, 0xff, 0xff, 0xff ) );
    // 80 /5 ib SUB r/m8, imm8 MI Valid Valid Subtract imm8 from r/m8.
    // REX + 80 /5 ib SUB r/m8*, imm8 MI Valid N.E. Subtract imm8 from r/m8.
    FCML_I32( "lock sub byte ptr [04030201h],0ffh", 0xF0, 0x80, 0x2D, 0x01, 0x02, 0x03, 0x04, 0xff );
    FCML_I32( "sub byte ptr [esi+04030201h],0ffh", 0x80, 0xae, 0x01, 0x02, 0x03, 0x04, 0xff );
    FCML_I32( "sub byte ptr [ecx+eax+00000002h],03h", 0x80, 0x6C, 0x01, 0x02, 0x03 );
    // 81 /5 iw SUB r/m16, imm16 MI Valid Valid Subtract imm16 from r/m16.
    // 81 /5 id SUB r/m32, imm32 MI Valid Valid Subtract imm32 from r/m32.
    FCML_I32( "sub ebp,04030201h", 0x81, 0xED, 0x01, 0x02, 0x03, 0x04 );
    FCML_I32( "sub bp,0201h", 0x66, 0x81, 0xED, 0x01, 0x02 );
    FCML_I64_D( "sub bp,0201h", 0x67, 0x66, 0x40, 0x81, 0xED, 0x01, 0x02 ); // 32 bit mode doesn't not allow REX.
    // REX.W + 81 /5 id SUB r/m64, imm32 MI Valid N.E. Subtract imm32 sign-extended to 64-bits from r/m64.
    FCML_I64( "sub rbp,0000000004030201h", 0x48, 0x81, 0xed, 0x01, 0x02, 0x03, 0x04 );
    FCML_I64_M( "sub rbp,0ffffffffffffffffh", 2, FCML_MI( 0x48, 0x83, 0xed, 0xff ), FCML_MI( 0x48, 0x81, 0xed, 0xff, 0xff, 0xff, 0xff ) );
    // 83 /5 ib SUB r/m16, imm8 MI Valid Valid Subtract sign-extended imm8 from r/m16.
    // 83 /5 ib SUB r/m32, imm8 MI Valid Valid Subtract sign-extended imm8 from r/m32.
    FCML_I32_M( "lock sub dword ptr [esi],00000001h", 2, FCML_MI( 0xF0, 0x83, 0x2e, 0x01 ), FCML_MI( 0xF0, 0x81, 0x2e, 0x01, 0x00, 0x00, 0x00 ) );
    FCML_I32_M( "sub word ptr [esi],0001h", 2, FCML_MI( 0x66, 0x83, 0x2e, 0x01 ), FCML_MI( 0x66, 0x81, 0x2e, 0x01, 0x00 ) );
    FCML_I32_M( "sub dword ptr [0201h],00000003h", 2, FCML_MI( 0x67, 0x83, 0x2e, 0x01, 0x02, 0x03 ), FCML_MI( 0x67, 0x81, 0x2e, 0x01, 0x02, 0x03, 0x00, 0x00, 0x00 ) );
    // REX.W + 83 /5 ib SUB r/m64, imm8 MI Valid N.E. Subtract sign-extended imm8 from r/m64.
    FCML_I64_M( "lock sub qword ptr [rdi+0000000004030201h],0000000000000005h", 2, FCML_MI( 0xF0, 0x48, 0x83, 0xaf, 0x01, 0x02, 0x03, 0x04, 0x05 ), FCML_MI( 0xF0, 0x48, 0x81, 0xaf, 0x01, 0x02, 0x03, 0x04, 0x05, 0x00, 0x00, 0x00 ) );
    FCML_I64_M( "sub qword ptr [rdi+0000000004030201h],0ffffffffffffffffh", 2, FCML_MI( 0x48, 0x83, 0xaf, 0x01, 0x02, 0x03, 0x04, 0xff ), FCML_MI( 0x48, 0x81, 0xaf, 0x01, 0x02, 0x03, 0x04, 0xff, 0xff, 0xff, 0xff ) );
    // 28 /r SUB r/m8, r8 MR Valid Valid Subtract r8 from r/m8.
    // REX + 28 /r SUB r/m8*, r8* MR Valid N.E. Subtract r8 from r/m8.
    FCML_I32( "lock sub byte ptr [ebp+04030201h],ah", 0xF0, 0x28, 0xa5, 0x01, 0x02, 0x03, 04 );
    FCML_I64( "sub byte ptr [rbp+0000000004030201h],spl", 0x40, 0x28, 0xa5, 0x01, 0x02, 0x03, 0x04 );
    FCML_I64( "sub byte ptr [rbp+0000000000000001h],spl", 0x40, 0x28, 0x65, 0x01 );
    // 29 /r SUB r/m16, r16 MR Valid Valid Subtract r16 from r/m16.
    // 29 /r SUB r/m32, r32 MR Valid Valid Subtract r32 from r/m32.
    // REX.W + 29 /r SUB r/m64, r32 MR Valid N.E. Subtract r64 from r/m64.
    FCML_I32( "lock sub dword ptr [ebp+04030201h],esp", 0xF0, 0x29, 0xa5, 0x01, 0x02, 0x03, 04 );
    FCML_I32( "sub word ptr [di+0201h],sp", 0x66, 0x67, 0x29, 0xa5, 0x01, 0x02 );
    FCML_I32( "sub dword ptr [di+0201h],esp", 0x67, 0x29, 0xa5, 0x01, 0x02 );
    FCML_I64( "sub qword ptr [r9+rcx*4+0000000000000001h],r12", 0x4D, 0x29, 0x64, 0x89, 0x01 );
    FCML_I64( "sub dword ptr [rcx+rax*4+0000000000000001h],esp", 0x29, 0x64, 0x81, 0x01 );
    // 2A /r SUB r8, r/m8 RM Valid Valid Subtract r/m8 from r8.
    // REX + 2A /r SUB r8*, r/m8* RM Valid N.E. Subtract r/m8 from r8.
    FCML_I32_A_FAILED( "lock sub ah,byte ptr [ebp+04030201h]", 0xF0, 0x2A, 0xa5, 0x01, 0x02, 0x03, 04 );
    FCML_I32( "sub ah,byte ptr [ebp+04030201h]", 0x2A, 0xa5, 0x01, 0x02, 0x03, 04 );
    FCML_I64( "sub spl,byte ptr [rbp+0000000004030201h]", 0x40, 0x2a, 0xa5, 0x01, 0x02, 0x03, 0x04 );
    FCML_I64( "sub spl,byte ptr [rbp+0000000000000001h]", 0x40, 0x2a, 0x65, 0x01 );
    // 2B /r SUB r16, r/m16 RM Valid Valid Subtract r/m16 from r16.
    // 2B /r SUB r32, r/m32 RM Valid Valid Subtract r/m32 from r32.
    // REX.W + 2B /r SUB r64, r/m64 RM Valid N.E. Subtract r/m64 from r64.
    FCML_I32_A_FAILED( "lock sub esp,dword ptr [ebp+04030201h]", 0xF0, 0x2b, 0xa5, 0x01, 0x02, 0x03, 04 );
    FCML_I32( "sub esp,dword ptr [ebp+04030201h]", 0x2b, 0xa5, 0x01, 0x02, 0x03, 04 );
    FCML_I32( "sub sp,word ptr [di+0201h]", 0x66, 0x67, 0x2b, 0xa5, 0x01, 0x02 );
    FCML_I32( "sub esp,dword ptr [di+0201h]", 0x67, 0x2b, 0xa5, 0x01, 0x02 );
    FCML_I64( "sub r12,qword ptr [r9+rcx*4+0000000000000001h]", 0x4D, 0x2b, 0x64, 0x89, 0x01 );
}

void fcml_tf_instruction_SUBPD(void) {
    // 66 0F 5C /r SUBPD xmm1,xmm2/m128
    FCML_I32( "subpd xmm0,xmmword ptr [eax]", 0x66, 0x0F, 0x5C, 0x00 );
    FCML_I32( "subpd xmm0,xmm0", 0x66, 0x0F, 0x5C, 0xC0 );
    FCML_I64( "subpd xmm0,xmmword ptr [rax]", 0x66, 0x0F, 0x5C, 0x00 );
    // VEX.NDS.128.66.0F.WIG 5C /r VSUBPD xmm1,xmm2,xmm3/m128
    // VEX.NDS.256.66.0F.WIG 5C /r VSUBPD ymm1,ymm2,ymm3/m256
    FCML_I32( "vsubpd xmm0,xmm6,xmmword ptr [eax]", 0xc5, 0xc9, 0x5c, 0x00 );
    FCML_I32( "vsubpd xmm0,xmm6,xmm0", 0xc5, 0xc9, 0x5c, 0xc0 );
    FCML_I64( "vsubpd xmm0,xmm6,xmmword ptr [rax]", 0xc5, 0xc9, 0x5c, 0x00 );
}

void fcml_tf_instruction_SUBPS(void) {
    // 0F 5C /r SUBPS xmm1 xmm2/m128
    FCML_I32( "subps xmm0,xmmword ptr [eax]", 0x0F, 0x5C, 0x00 );
    FCML_I32( "subps xmm0,xmm0", 0x0F, 0x5C, 0xC0 );
    FCML_I64( "subps xmm0,xmmword ptr [rax]", 0x0F, 0x5C, 0x00 );
    // VEX.NDS.128.0F.WIG 5C /r VSUBPS xmm1,xmm2,xmm3/m128
    // VEX.NDS.256.0F.WIG 5C /r VSUBPS ymm1,ymm2,ymm3/m256
    FCML_I32( "vsubps xmm0,xmm6,xmmword ptr [eax]", 0xc5, 0xc8, 0x5c, 0x00 );
    FCML_I32( "vsubps xmm0,xmm6,xmm0", 0xc5, 0xc8, 0x5c, 0xc0 );
    FCML_I64( "vsubps xmm0,xmm6,xmmword ptr [rax]", 0xc5, 0xc8, 0x5c, 0x00 );
}

void fcml_tf_instruction_SUBSD(void) {
    // F2 0F 5C /r SUBSD xmm1,xmm2/m64 RM V/V SSE2 Subtracts the low double-precision floatingpoint values in xmm2/mem64 from xmm1.
    FCML_I32( "subsd xmm2,mmword ptr [ecx+eax]", 0xF2, 0x0F, 0x5C, 0x14, 0x01 );
    FCML_I64( "subsd xmm2,mmword ptr [rcx+rax]", 0xF2, 0x0F, 0x5C, 0x14, 0x01 );
    // VEX.NDS.LIG.F2.0F.WIG 5C /r VSUBSD xmm1,xmm2,xmm3/m64 RVM V/V AVX Subtract the low double-precision floatingpoint value in xmm3/mem from xmm2 and store the result in xmm1.
    FCML_I32( "vsubsd xmm2,xmm5,mmword ptr [ecx+eax]", 0xc5, 0xd3, 0x5c, 0x14, 0x01 );
    FCML_I32( "vsubsd xmm2,xmm4,mmword ptr [ecx+eax]", 0xC5, 0xDB, 0x5C, 0x14, 0x01 );
}

void fcml_tf_instruction_SUBSS(void) {
    // F3 0F 5C /r SUBSS xmm1,xmm2/m32
    FCML_I32( "subss xmm2,dword ptr [ecx+eax]", 0xF3, 0x0F, 0x5C, 0x14, 0x01 );
    FCML_I64( "subss xmm2,dword ptr [rcx+rax]", 0xF3, 0x0F, 0x5C, 0x14, 0x01 );
    // VEX.NDS.LIG.F3.0F.WIG 5C /r VSUBSS xmm1,xmm2,xmm3/m32
    FCML_I32( "vsubss xmm2,xmm5,dword ptr [ecx+eax]", 0xc5, 0xd2, 0x5c, 0x14, 0x01 );
    FCML_I32( "vsubss xmm2,xmm4,dword ptr [ecx+eax]", 0xC5, 0xDA, 0x5C, 0x14, 0x01 );
}

void fcml_tf_instruction_SWAPGS(void) {
    // 0F 01 F8 SWAPGS NP Valid Invalid Exchanges the current GS base register value with the value contained in MSR address C0000102H.
    FCML_I64( "swapgs", 0x0F, 0x01, 0xF8 );
    FCML_I32_FAILED( "swapgs", 0x0F, 0x01, 0xF8 );
}

void fcml_tf_instruction_SYSCALL(void) {
    // 0F 05 SYSCALL NP Valid Invalid Fast call to privilege level 0 system procedures.
    FCML_I64( "syscall", 0x0F, 0x05 );
    FCML_I32_FAILED( "syscall", 0x0F, 0x05 );
}

void fcml_tf_instruction_SYSENTER(void) {
    // 0F 34 SYSENTER NP Valid Valid Fast call to privilege level 0 system procedures.
    FCML_I3264( "sysenter", 0x0F, 0x34 );
}

void fcml_tf_instruction_SYSEXIT(void) {
    // 0F 35 SYSEXIT NP Valid Valid Fast return to privilege level 3 user code.
    // REX.W + 0F 35 SYSEXIT NP Valid Valid Fast return to 64-bit mode privilege level 3 user code.
    FCML_I32( "sysexit", 0x0F, 0x35 );
    FCML_I64( "sysexit", 0x0F, 0x35 );
    FCML_I64_D( "sysexit", 0x48, 0x0F, 0x35 );
}

void fcml_tf_instruction_SYSRET(void) {
    // 0F 07 SYSRET NP Valid Invalid Return to compatibility mode from fast system call
    // REX.W + 0F 07 SYSRET NP Valid Invalid Return to 64-bit mode from fast system call
    FCML_I32_FAILED( "sysret", 0x0F, 0x07 );
    FCML_I64( "sysret", 0x0F, 0x07 );
    FCML_I64_D( "sysret", 0x48, 0x0F, 0x07 );
}

void fcml_tf_instruction_SHLX_SHRX_SARX(void) {
    // VEX.NDS1.LZ.66.0F38.W0 F7 /r SHLX r32a, r/m32, r32b
    // VEX.NDS1.LZ.66.0F38.W1 F7 /r SHLX r64a, r/m64, r64b
    FCML_I32( "shlx eax,dword ptr [eax],edi", 0xC4, 0xE2, 0x41, 0xF7, 0x00 );
    FCML_I32( "shlx eax,eax,edi", 0xC4, 0xE2, 0x41, 0xF7, 0xC0 );
    FCML_I32( "shlx rax,qword ptr [eax],rdi", 0xC4, 0xE2, 0xC1, 0xF7, 0x00 );
    FCML_I32( "shlx rax,rax,rdi", 0xC4, 0xE2, 0xC1, 0xF7, 0xC0 );
    // VEX.NDS1.LZ.F2.0F38.W0 F7 /r SHRX r32a, r/m32, r32b
    // VEX.NDS1.LZ.F2.0F38.W1 F7 /r SHRX r64a, r/m64, r64b
    FCML_I32( "shrx eax,dword ptr [eax],edi", 0xC4, 0xE2, 0x43, 0xF7, 0x00 );
    FCML_I32( "shrx eax,eax,edi", 0xC4, 0xE2, 0x43, 0xF7, 0xC0 );
    FCML_I32( "shrx rax,qword ptr [eax],rdi", 0xC4, 0xE2, 0xC3, 0xF7, 0x00 );
    FCML_I32( "shrx rax,rax,rdi", 0xC4, 0xE2, 0xC3, 0xF7, 0xC0 );
    // VEX.NDS1.LZ.F3.0F38.W0 F7 /r SARX r32a, r/m32, r32b
    // VEX.NDS1.LZ.F3.0F38.W1 F7 /r SARX r64a, r/m64, r64b
    FCML_I32( "sarx eax,dword ptr [eax],edi", 0xC4, 0xE2, 0x42, 0xF7, 0x00 );
    FCML_I32( "sarx eax,eax,edi", 0xC4, 0xE2, 0x42, 0xF7, 0xC0 );
    FCML_I32( "sarx rax,qword ptr [eax],rdi", 0xC4, 0xE2, 0xC2, 0xF7, 0x00 );
    FCML_I32( "sarx rax,rax,rdi", 0xC4, 0xE2, 0xC2, 0xF7, 0xC0 );
}

void fcml_tf_instruction_STAC(void) {
    // 0F 01 CB STAC
    FCML_I3264( "stac", 0x0F, 0x01, 0xCB );
}

CU_TestInfo fctl_ti_instructions_s[] = {
    { "fcml_tf_instruction_SAHF", fcml_tf_instruction_SAHF },
    { "fcml_tf_instruction_SHL", fcml_tf_instruction_SHL },
    { "fcml_tf_instruction_SAL", fcml_tf_instruction_SAL },
    { "fcml_tf_instruction_SAR", fcml_tf_instruction_SAR },
    { "fcml_tf_instruction_SHR", fcml_tf_instruction_SHR },
    { "fcml_tf_instruction_SBB", fcml_tf_instruction_SBB },
    { "fcml_tf_instruction_SCAS", fcml_tf_instruction_SCAS },
    { "fcml_tf_instruction_SETcc", fcml_tf_instruction_SETcc },
    { "fcml_tf_instruction_SFENCE", fcml_tf_instruction_SFENCE },
    { "fcml_tf_instruction_SGDT", fcml_tf_instruction_SGDT },
    { "fcml_tf_instruction_SHLD", fcml_tf_instruction_SHLD },
    { "fcml_tf_instruction_SHRD", fcml_tf_instruction_SHRD },
    { "fcml_tf_instruction_SKINIT", fcml_tf_instruction_SKINIT },
    { "fcml_tf_instruction_SLWPCB", fcml_tf_instruction_SLWPCB },
    { "fcml_tf_instruction_SHUFPD", fcml_tf_instruction_SHUFPD },
    { "fcml_tf_instruction_SHUFPS", fcml_tf_instruction_SHUFPS },
    { "fcml_tf_instruction_SIDT", fcml_tf_instruction_SIDT },
    { "fcml_tf_instruction_SLDT", fcml_tf_instruction_SLDT },
    { "fcml_tf_instruction_SMSW", fcml_tf_instruction_SMSW },
    { "fcml_tf_instruction_SQRTPD", fcml_tf_instruction_SQRTPD },
    { "fcml_tf_instruction_SQRTPS", fcml_tf_instruction_SQRTPS },
    { "fcml_tf_instruction_SQRTSD", fcml_tf_instruction_SQRTSD },
    { "fcml_tf_instruction_SQRTSS", fcml_tf_instruction_SQRTSS },
    { "fcml_tf_instruction_STC", fcml_tf_instruction_STC },
    { "fcml_tf_instruction_STD", fcml_tf_instruction_STD },
    { "fcml_tf_instruction_STGI", fcml_tf_instruction_STGI },
    { "fcml_tf_instruction_STI", fcml_tf_instruction_STI },
    { "fcml_tf_instruction_STMXCSR", fcml_tf_instruction_STMXCSR },
    { "fcml_tf_instruction_STOS", fcml_tf_instruction_STOS },
    { "fcml_tf_instruction_STR", fcml_tf_instruction_STR },
    { "fcml_tf_instruction_SUB", fcml_tf_instruction_SUB },
    { "fcml_tf_instruction_SUBPD", fcml_tf_instruction_SUBPD },
    { "fcml_tf_instruction_SUBPS", fcml_tf_instruction_SUBPS },
    { "fcml_tf_instruction_SUBSD", fcml_tf_instruction_SUBSD },
    { "fcml_tf_instruction_SUBSS", fcml_tf_instruction_SUBSS },
    { "fcml_tf_instruction_SWAPGS", fcml_tf_instruction_SWAPGS },
    { "fcml_tf_instruction_SYSCALL", fcml_tf_instruction_SYSCALL },
    { "fcml_tf_instruction_SYSENTER", fcml_tf_instruction_SYSENTER },
    { "fcml_tf_instruction_SYSEXIT", fcml_tf_instruction_SYSEXIT },
    { "fcml_tf_instruction_SYSRET", fcml_tf_instruction_SYSRET },
    { "fcml_tf_instruction_SHLX_SHRX_SARX", fcml_tf_instruction_SHLX_SHRX_SARX },
    { "fcml_tf_instruction_STAC", fcml_tf_instruction_STAC },
    CU_TEST_INFO_NULL,
};

CU_SuiteInfo fctl_si_instructions_s[] = {
    { "suite-fctl_ti_instructions_s", fcml_tf_instructions_s_suite_init, fcml_tf_instructions_s_suite_cleanup, fctl_ti_instructions_s },
    CU_SUITE_INFO_NULL,
};
