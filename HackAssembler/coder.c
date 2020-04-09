//
//  coder.c
//  HackAssembler
//
//  Created by kyanmulji on 4/8/20.
//  Copyright © 2020 kyanmulji. All rights reserved.
//

#include "coder.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// constructs jmp table and converts jump command
char* convertJump(char* jump){
     map newmap=createMap(300);
    insertKey(newmap, "", "000");
    insertKey(newmap, "JGT", "001");
    insertKey(newmap, "JEQ", "010");
    insertKey(newmap, "JGE", "011");
    insertKey(newmap, "JLT", "100");
    insertKey(newmap, "JNE", "101");
    insertKey(newmap, "JLE", "110");
    insertKey(newmap, "JMP", "111");
     char* binaryJump=(char*) malloc(20*sizeof(char));
    
    binaryJump=lookupKey(newmap, jump);
    
    return binaryJump;
}
// constructs destination table and converts destination string
char* convertDest(char* dest){
    map newmap=createMap(300);
    insertKey(newmap, "", "000");
    insertKey(newmap, "M", "001");
    insertKey(newmap, "D", "010");
    insertKey(newmap, "MD", "011");
    insertKey(newmap, "A", "100");
    insertKey(newmap, "AM", "101");
    insertKey(newmap, "AD", "110");
    insertKey(newmap, "AMD", "111");
    char* binaryDest=(char*) malloc(20*sizeof(char));
    
    binaryDest=lookupKey(newmap, dest);
    
    return binaryDest;
}

//constructs comp table and converts comp string

char* convertComp(char* comp){
    map newmap=createMap(300);
    
    insertKey(newmap, "0", "0101010");
    insertKey(newmap, "1", "0111111");
    insertKey(newmap, "-1", "0111010");
    insertKey(newmap, "D", "0001100");
    insertKey(newmap, "A", "0110000");
    insertKey(newmap, "!D", "0001101");
    insertKey(newmap, "!A", "0110001");
    insertKey(newmap, "-D", "0001111");
    insertKey(newmap, "-A", "0110011");
    insertKey(newmap, "D+1", "0011111");
    insertKey(newmap, "A+1", "0110111");
    insertKey(newmap, "D-1", "0001110");
    insertKey(newmap, "A-1", "0110010");
    insertKey(newmap, "D+A", "0000010");
    insertKey(newmap, "D-A", "0010011");
    insertKey(newmap, "A-D", "0000111");
    insertKey(newmap, "D&A", "0000000");
    insertKey(newmap, "D|A", "0010101");
    insertKey(newmap, "M", "1110000");
    insertKey(newmap, "!M", "1110001");
    insertKey(newmap, "-M", "1110011");
    insertKey(newmap, "M+1", "1110111");
    insertKey(newmap, "M-1", "1110010");
    insertKey(newmap, "D+M", "1000010");
    insertKey(newmap, "D-M", "1010011");
    insertKey(newmap, "M-D", "1000111");
    insertKey(newmap, "D&M", "1000000");
    insertKey(newmap, "D|M", "1010101");
    
    char* binaryComp=(char*) malloc(20*sizeof(char));
    
    binaryComp=lookupKey(newmap, comp);
    
    return binaryComp;
    
    
}
char* combineC(char* comp,char* Dest, char* jump){
    char* combined=(char*) malloc(20*sizeof(char));
    sprintf(combined, "%s%s%s%s","111" ,comp, Dest, jump);
   
    return combined;
    
}
