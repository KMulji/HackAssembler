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
    
    if ( file != NULL )
    {
       char line [ 128 ]; /* or other suitable maximum line size */
       while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
       {
           
           convert(line);
           //printf("%s",convert(line));
           //printf("%s\n",convertComp(computation()));
           printf("%s\n",combineC(convertComp(computation()), convertDest(destination()), convertJump(jump())));
           //printf("%d",commandType());
          //fputs ( line, stdout ); /* write the line */
           
       }
       fclose ( file );
    }
    else
    {
       perror ( filename ); /* why didn't the file open? */
    }
       
    return 0;
}
