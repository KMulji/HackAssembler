//
//  parser.h
//  HackAssembler
//
//  Created by kyanmulji on 4/2/20.
//  Copyright © 2020 kyanmulji. All rights reserved.
//

#ifndef parser_h
#define parser_h

#include <stdio.h>

// check to see if the file has more lines
void hasMoreCommands(void);

// goto next line
char* convert(char* convert);

// if the command is a A,C OR L Command
int commandType(void);

//L command string
char* symbol(void);

// destination command string
char* destination(void);

// computation command string
char* computation(void);

// jump command string
char* jump(void);


void removeChar(char *str, char garbage);

void freeParser(void);

#endif /* parser_h */
