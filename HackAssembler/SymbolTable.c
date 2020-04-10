//
//  SymbolTable.c
//  HackAssembler
//
//  Created by Hung Dinh Nguyen on 4/10/20.
//  Copyright © 2020 kyanmulji. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SymbolTable.h"
#include "map.h"

map SymbolTable;

/** Initialize a Symbol Table with Predefined symbols
 Label: RAM
 SP         : 0
 LCL       : 1
 ARG      : 2
 THIS      : 3
 THAT     : 4
 R0-R15  : 0-15
 SCREEN: 16384
 KBD        : 24576
 */
void initST(void) {
    SymbolTable = createMap(300);
    insertKey(SymbolTable, "SP", "0");
    insertKey(SymbolTable, "LCL", "1");
    insertKey(SymbolTable, "ARG", "2");
    insertKey(SymbolTable, "THIS", "3");
    insertKey(SymbolTable, "THAT", "4");
    insertKey(SymbolTable, "R0", "0");
    insertKey(SymbolTable, "R1", "1");
    insertKey(SymbolTable, "R2", "2");
    insertKey(SymbolTable, "R3", "3");
    insertKey(SymbolTable, "R4", "4");
    insertKey(SymbolTable, "R5", "5");
    insertKey(SymbolTable, "R6", "6");
    insertKey(SymbolTable, "R7", "7");
    insertKey(SymbolTable, "R8", "8");
    insertKey(SymbolTable, "R9", "9");
    insertKey(SymbolTable, "R10", "10");
    insertKey(SymbolTable, "R11", "11");
    insertKey(SymbolTable, "R12", "12");
    insertKey(SymbolTable, "R13", "13");
    insertKey(SymbolTable, "R14", "14");
    insertKey(SymbolTable, "R15", "15");
    insertKey(SymbolTable, "SCREEN", "16384");
    insertKey(SymbolTable, "KBD", "24576");
}

void addEntry(char* symbol, int address) {
    
    
}

// Label Symbols
void addLabel(char* symbol) {
    insertKey(SymbolTable, symbol, "16");
}

// Variable Symbols
// Start from @16 and mapped consecutive memory after that
void addVariable(char* symbol) {
    
}

int contains(char* symbol) {
    return 0;
}

int GetAddress(char* symbol) {
    return 0;
}

/**
 [V] ]Initialize: Predefined symbols
 - Initialize ST with predefined symbols and their pre-allocated RAM addresses
 
 [  ] First Pass:  Label Symbols
 1. Counter for all instructions (except for (xxx) label and comments) for the  ROM address
 2. Find Pseudocommand (xxx) -> Add a new entry (xxx, counter) as counter = ROM address of xxx
 
 [  ] ]Second Pass: Lookup + Var Symbols
 1. If meet @xxx, lookup xxx and RETURN the associated RAM/ROM address -> binary
 2. if not found in ST, it's a Variable Symbol => Add a new entry (xxx, n)
 where n starts at 16 and is the next available space.
 */

// Add '//' comments
// Add "Ignore white space/next-line"
// Prevent Memory Leak
