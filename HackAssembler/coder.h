//
//  coder.h
//  HackAssembler
//
//  Created by kyanmulji on 4/8/20.
//  Copyright © 2020 kyanmulji. All rights reserved.
//

#ifndef coder_h
#define coder_h

#include <stdio.h>

char* convertBinary(char* a);
char* convertJump(char* jump);
char* convertDest(char* Dest);
char* convertComp(char* comp);
char* combineC(char* comp,char* Dest, char* jump);

#endif /* coder_h */
