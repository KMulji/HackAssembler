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
    // insert code here...
  static const char filename[] = "hello.asm";
    FILE *file = fopen ( filename, "r" );
    FILE *file2= fopen("hello.hack", "w+");
    int ROMcounter=0;
    int RAMcounter=16;
    initST();
    if ( file != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
        {
            convert(line);
            if(commandType()==1){
                ROMcounter++;
               

            }else if(commandType()==4){
                ROMcounter++;
                
            }else if(commandType()==0){
                
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
    file = fopen ( filename, "r" );
    if ( file != NULL )
        {
            char line [ 128 ]; /* or other suitable maximum line size */
            while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
            {

                convert(line);
                if(commandType()==1){
                    char* temp=symbol();
                    
                    if(isNumber(temp)){
                      printf("%s\n",convertBinary(temp));
                    
                      //fputs(convertBinary(temp), file2);
                    }
                    else if(contains(temp)>0){
                        printf("%s",convertBinary(GetAddress(temp)));
                    }else{
                        addEntry(temp, RAMcounter);
                        RAMcounter++;
                        printf("%s",convertBinary(GetAddress(temp)));
                    }
                    
                    //printf("%s\n",convertBinary(symbol()));

                }else if(commandType()==4){
                    
                    //fputs(combineC(convertComp(computation()),convertDest(destination()), convertJump(jump())), file2);
                   printf("%s",combineC(convertComp(computation()), convertDest(destination()), convertJump(jump())));
            
            }
            }
            fclose ( file );
        }
        else
        {
            perror ( filename ); /* why didn't the file open? */
        }
    
    //addEntry("Hungry", 69);
    //printf("Has Key Hunger? No %d\n", contains("Hunger"));
    //printf("Has Key Hungry? Yes %d\n", contains("Hungry"));
    //printf("Binary of %s is: %s\n", GetAddress("Hungry"), convertBinary(GetAddress("Hungry")));
    
    return 0;
}
