//
//  SymbolTable.h
//  HackAssembler
//
//  Created by Hung Dinh Nguyen on 4/10/20.
//  Copyright © 2020 kyanmulji. All rights reserved.
//

#ifndef SymbolTable_h
#define SymbolTable_h

#include <stdio.h>
#include "map.h"

// Create a new initialized Symbol Table
void initST(void);
// Adds the pair (symbol,address) to the table.
void addEntry(char* symbol, int address);
// Does the symbol table contain the given symbol?
int contains(char* symbol);
//Returns the address associated with the symbol.
char* GetAddress(char* symbol);

#endif /* SymbolTable_h */
