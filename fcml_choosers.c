/*
 * fcml_choosers.c
 *
 *  Created on: Nov 7, 2013
 *      Author: tas
 */

#include "fcml_choosers.h"

#include <fcml_assembler.h>
#include <fcml_coll.h>

fcml_st_asm_assembled_instruction *fcml_fn_asm_no_instruction_chooser( fcml_st_coll_list *instructions ) {
	return NULL;
}

fcml_st_asm_assembled_instruction *fcml_fn_asm_default_instruction_chooser( fcml_st_coll_list *instructions ) {
	fcml_st_asm_assembled_instruction *shortest = NULL;
	if( instructions->size ) {
		fcml_st_coll_list_element *element = instructions->head;
		while( element ) {
			if( !shortest ) {
				shortest = (fcml_st_asm_assembled_instruction *)element->item;
			} else {
				fcml_st_asm_assembled_instruction *current = (fcml_st_asm_assembled_instruction *)element->item;
				if( current->code_length < shortest->code_length ) {
					shortest = current;
				}
			}
			element = element->next;
		}
	}
	return shortest;
}
