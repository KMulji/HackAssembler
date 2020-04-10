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
  static const char filename[] = "hello.asm";
    FILE *file = fopen ( filename, "r" );
    FILE *file2= fopen("hello.hack", "w+");
    if ( file != NULL )
    {
       char line [ 128 ]; /* or other suitable maximum line size */
       while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
       {
           
           convert(line);
           if(commandType()==1){
               fputs(convertBinary(symbol()), file2);
               //printf("%s\n",convertBinary(symbol()));
               
           }else if(commandType()==4){
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
