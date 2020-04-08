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
char* advance(char* convert);

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

// open a file with a specific name. 
void openFile(char filename[20]);

void removeChar(char *str, char garbage);

#endif /* parser_h */
