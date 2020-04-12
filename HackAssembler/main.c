//
//  main.c
//  HackAssembler
//
//  Created by kyanmulji on 4/2/20.
//  Copyright © 2020 kyanmulji. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "coder.h"
#include "map.h"
#include "parser.h"
#include "SymbolTable.h"


int main(int argc, const char * argv[]) {
    
//    printf("%s %s",argv[1], argv[2]);
  static const char filename[] = "hello.asm";
    FILE *file = fopen ( argv[1], "r" );
    FILE *file2= fopen(argv[2], "w+");
    int ROMcounter=0;
    int RAMcounter=16;
    initST(); // initialize ST
    
    // first pass
    if ( file != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
        {
            convert(line);
            int ctype = commandType();
            if(ctype==1){
                ROMcounter++;
            }else if(ctype==4){
                ROMcounter++;
            }else if(ctype==0){
                addEntry(symbol(), ROMcounter);
            }
        }
        fclose ( file );
    }
    else
    {
        perror ( filename ); /* why didn't the file open? */
    }
    
    // second pass
    file = fopen ( argv[1], "r" );
    if ( file != NULL )
        {
            char line [ 128 ]; /* or other suitable maximum line size */
            while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
            {
                convert(line);
                int ctype = commandType();
                if(ctype==1){
                    char* temp=symbol();
                    
                    if(isNumber(temp)){
//                      printf("%s\n",convertBinary(temp));
                      fputs(convertBinary(temp), file2);
                    }
                    else if(contains(temp)>0){
//                        printf("%s",convertBinary(GetAddress(temp)));
                        fputs(convertBinary(GetAddress(temp)),file2);
                    }else{
                        addEntry(temp, RAMcounter);
                        RAMcounter++;
                        //printf("%s",convertBinary(GetAddress(temp)));
                        fputs(convertBinary(GetAddress(temp)),file2);
                    }
                    
                    //printf("%s\n",convertBinary(symbol()));

                }else if(ctype==4){
                    fputs(combineC(convertComp(computation()),convertDest(destination()), convertJump(jump())), file2);
                   //printf("%s",combineC(convertComp(computation()), convertDest(destination()), convertJump(jump())));
            
                }
            }
            fclose ( file );
        }
        else
        {
            perror ( filename ); /* why didn't the file open? */
        }
    
    
    return 0;
}
