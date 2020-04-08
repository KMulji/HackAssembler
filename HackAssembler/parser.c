//
//  parser.c
//  HackAssembler
//
//  Created by kyanmulji on 4/2/20.
//  Copyright © 2020 kyanmulji. All rights reserved.
//

#include "parser.h"
#include "map.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char line[1000];
int counter=0;
FILE* file;
char fileName[20];
char currentline[20];


// opens file
void openFile(char filename[20]){
    strcpy(fileName,filename);
}

// goto next line
char* advance(void){
    file = fopen(fileName, "r");
    char* line=(char*)malloc(sizeof(char));
    char* temp=(char*)malloc(sizeof(char));
    int i = 0;
    counter++;
    //read input
    
    while (fgets(line, sizeof(line), file)) {
        i++;
        if(i == counter )
        {
            //remove newline character at the end from fgets
            long len = strlen(line);
            if( line[len-1] == '\n' ){
                line[len-1] = 0;
                strcpy(temp, line);
            }
        }
    }
     //remove spaces from current line
    int x=0;
    int y=0;
    long len=strlen(temp);
    for(x=0; x<len; x++)
    {
        if(temp[x]==' ')
        {
            for(y=x; y<len; y++)
            {
                temp[y]=temp[y+1];
            }
        len--;
        }
    }
    strcpy(currentline, temp);
    //printf("%s\n current line is",currentline);
    return currentline;
}

// if the command is a A,C OR L Command or a comment to skip
int commandType(void){
    if(currentline[0]=='('){
       // L COMMAND
        return 0;
    }
    else if (currentline[0]=='@'){
        // A COMMAND
        return 1;
    }
    else if (currentline[0]=='/'){
        //comment to skip
        return 2;
    }
    else if (currentline[0]=='\0'){
        return 3;
    }
    // c command
    return 4;
}

//L command string
char* symbol(void){
    // a command or () label. remove @ and ()
    char* sym=(char*) malloc(20*sizeof(char));
    if(currentline[0]=='@'){
        int k=0;
        int i=0;
        for (i=0; i<strlen(currentline); i++) {
            sym[k]=currentline[i+1];
            k++;
        }
    }else if(currentline[0]=='('){
        int k=0;
        int i=0;
        for (i=0; i<strlen(currentline); i++) {
            if(currentline[i]==')'){
                break;
            }else if(currentline[i]!=')') {
                sym[k]=currentline[k];
                k++;
            }
        }
        
    }
    removeChar(sym, '(');
    return sym;
}

// destination command string
char* destination(void){
    char* dest=(char*) malloc(20*sizeof(char));
    int i=0;
    int j=0;
    long length= strlen(currentline);
        while(j<length&&currentline[i]!='='){
            dest[j]=currentline[i];
            i++;
            j++;
        }
    return dest;
}

// computation command string
char* computation(void){
    char* comp=(char*) malloc(20*sizeof(char));
    int i=0;
    int j=0;
    long length= strlen(currentline);
    
    while (i<length) {
        if(currentline[i]=='='){
            int k=0;
            for (j=i; j<length; j++) {
                comp[k]=currentline[j];
                if(currentline[j]==';'){
                    break;
                }
                k++;
            }
            break;
            }
        
        i++;
    }
    removeChar(comp, '=');
    removeChar(comp, ';');
    return comp;
    
}

// jump command string
char* jump(void){
    int i=0;
    int j=0;
    char* jump=(char*)malloc(20*sizeof(char));
    long length = strlen(currentline);
    while(i<length){
        if(currentline[i]==';'){
            int k=0;
            for (j=i; j<length; j++) {
                jump[k]=currentline[j+1];
                k++;
            }
            break;
        }
        i++;
    }
    return jump;
}

 void removeChar(char *str, char garbage) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

