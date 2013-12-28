/*
 * fcml_asm_dialect_intel.h
 *
 *  Created on: 1 wrz 2013
 *      Author: tAs
 */

#ifndef FCML_ASM_DIALECT_GAS_H_
#define FCML_ASM_DIALECT_GAS_H_

#include "fcml_ceh.h"
#include "fcml_dialect.h"

fcml_ceh_error fcml_fn_init_gas_dialect(void);
void fcml_fn_gas_dialect_free(void);
fcml_st_dialect *fcml_fn_get_gas_dialect_context();

#endif /* FCML_ASM_DIALECT_GAS_H_ */