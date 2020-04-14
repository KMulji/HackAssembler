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

map destmap, compmap, jumpmap;
void initCoder() {
    destmap = createMap(8);
    compmap = createMap(28);
    jumpmap = createMap(8);
    
    // dest
    insertKey(destmap, "", "000");
    insertKey(destmap, "M", "001");
    insertKey(destmap, "D", "010");
    insertKey(destmap, "MD", "011");
    insertKey(destmap, "A", "100");
    insertKey(destmap, "AM", "101");
    insertKey(destmap, "AD", "110");
    insertKey(destmap, "AMD", "111");
    
    // comp
    insertKey(compmap, "0", "0101010");
    insertKey(compmap, "1", "0111111");
    insertKey(compmap, "-1", "0111010");
    insertKey(compmap, "D", "0001100");
    insertKey(compmap, "A", "0110000");
    insertKey(compmap, "!D", "0001101");
    insertKey(compmap, "!A", "0110001");
    insertKey(compmap, "-D", "0001111");
    insertKey(compmap, "-A", "0110011");
    insertKey(compmap, "D+1", "0011111");
    insertKey(compmap, "A+1", "0110111");
    insertKey(compmap, "D-1", "0001110");
    insertKey(compmap, "A-1", "0110010");
    insertKey(compmap, "D+A", "0000010");
    insertKey(compmap, "D-A", "0010011");
    insertKey(compmap, "A-D", "0000111");
    insertKey(compmap, "D&A", "0000000");
    insertKey(compmap, "D|A", "0010101");
    insertKey(compmap, "M", "1110000");
    insertKey(compmap, "!M", "1110001");
    insertKey(compmap, "-M", "1110011");
    insertKey(compmap, "M+1", "1110111");
    insertKey(compmap, "M-1", "1110010");
    insertKey(compmap, "D+M", "1000010");
    insertKey(compmap, "D-M", "1010011");
    insertKey(compmap, "M-D", "1000111");
    insertKey(compmap, "D&M", "1000000");
    insertKey(compmap, "D|M", "1010101");
    
    // jump
    insertKey(jumpmap, "", "000");
    insertKey(jumpmap, "JGT", "001");
    insertKey(jumpmap, "JEQ", "010");
    insertKey(jumpmap, "JGE", "011");
    insertKey(jumpmap, "JLT", "100");
    insertKey(jumpmap, "JNE", "101");
    insertKey(jumpmap, "JLE", "110");
    insertKey(jumpmap, "JMP", "111");
}

char* convertBinary(char* a) {
    // Convert char* a -> int
    int dec = atoi(a);
    //printf("%s %d\n", "Mario", dec);
    
    // Convert int -> String
    int temp[16], i;
    char* binary = (char*) malloc(sizeof(char) * 17);
    
    for (i = 15; dec > 0; i--) {
        temp[i] = dec%2;
        dec = dec/2;
    }
    //printf("i is %d\n", i);
    for (; i >= 0; i--) {
        temp[i] = 0;
    }
    
    int index = 0;
    for (int i = 0; i < 16; i++) {
        index += sprintf (&binary[index], "%d", temp[i]);
    }
    //printf("%s %s\n", "Peach", binary);
    strcat(binary,"\n");
    return binary;
}

// constructs jmp table and converts jump command
char* convertJump(char* jump){
     char* binaryJump=(char*) malloc(20*sizeof(char));
    
    binaryJump=lookupKey(jumpmap, jump);
    
    return binaryJump;
}

// constructs destination table and converts destination string
char* convertDest(char* dest){
    char* binaryDest=(char*) malloc(20*sizeof(char));
    
    binaryDest=lookupKey(destmap, dest);
    
    return binaryDest;
}

//constructs comp table and converts comp string
char* convertComp(char* comp){
    char* binaryComp=(char*) malloc(20*sizeof(char));
    
    binaryComp=lookupKey(compmap, comp);

    return binaryComp;
}

char* combineC(char* comp,char* Dest, char* jump){
    char* combined=(char*) malloc(20*sizeof(char));
    sprintf(combined, "%s%s%s%s%s","111" ,comp, Dest, jump,"\n");
    return combined;
}

void freeCoder() {
    freeMap(destmap);
    freeMap(compmap);
    freeMap(jumpmap);
}
