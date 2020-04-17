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
 // static const char filename[] = "hello.asm";
    FILE *file = fopen ( argv[1], "r" );
    FILE *file2= fopen(argv[2], "w+");
    int ROMcounter=0;
    int RAMcounter=16;
    
    initCoder(); // initialize coder map
    initST(); // initialize ST
    // first pass
    if ( file != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
        {
            convert(line); //initialize currentline char*
            int ctype = commandType();
            if(ctype==1){
                ROMcounter++;
            }else if(ctype==4){
                ROMcounter++;
            }else if(ctype==0){
                char* temp_symbol = symbol();
                addEntry(temp_symbol, ROMcounter);
                //free(temp_symbol);
            }
            freeParser(); // free currentline char*
            
        }
        fclose ( file );
    }
    else
    {
        perror ( argv[1] ); /* why didn't the file open? */
    }
    
//    printf("Entry count: %d\n", EntryCount);
//    printf("\n\n----Moving to second pass----\n\n");
    
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
                        char *cvbi = convertBinary(temp);
                        fputs(cvbi, file2);
                        free(cvbi);
                    }
                    else if(contains(temp)>=0){
//                        printf("%s",convertBinary(GetAddress(temp)));
                        char *cvbi = convertBinary(GetAddress(temp));
                        fputs(cvbi,file2);
                        free(cvbi);
                    }else{
                        addEntry(temp, RAMcounter);
                        RAMcounter++;
                        //printf("%s",convertBinary(GetAddress(temp)));
                        char *cvbi = convertBinary(GetAddress(temp));
                        fputs(cvbi,file2);
                        free(cvbi);
                    }
                    free(temp);
                    
                    //printf("%s\n",convertBinary(symbol()));

                }else if(ctype==4){
                    fputs(combineC(convertComp(computation()),convertDest(destination()), convertJump(jump())), file2);
                   //printf("%s",combineC(convertComp(computation()), convertDest(destination()), convertJump(jump())));
//                    free(c_temp);
//                    free(d_temp);
//                    free(j_temp);
            
                }
                freeParser();
            }
            fclose ( file );
        }
        else
        {
            perror ( argv[1] ); /* why didn't the file open? */
        }
    
    freeCoder();    // freeMap in Coder
    freeST();       //freeMap Symbol Table
    
    
    return 0;
}
