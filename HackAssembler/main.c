//
//  main.c
//  HackAssembler
//
//  Created by kyanmulji on 4/2/20.
//  Copyright © 2020 kyanmulji. All rights reserved.
//

#include <stdio.h>
#include "parser.h"
#include <string.h>
#include "coder.h"
#include "map.h"
#include <stdlib.h>


int main(int argc, const char * argv[]) {
    // insert code here...
    openFile("hello.asm");
    FILE *fp = fopen("hello.asm", "r");
    //char* temp= (char*)malloc(20*sizeof(char));
    int ch = getc(fp);
    int i=0;
     while (1)
     {
         //printf("%s",advance());
         advance();
         //printf("%s",jump());
         printf("%s\n",combineC(convertComp(computation()), convertDest(destination()), convertJump(jump())));
         ch = getc(fp);

         if(ch==-1){
             break;
         }
         i++;
        
     }
       
    return 0;
}
