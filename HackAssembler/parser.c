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

char line[1000];
int counter=0;
FILE* file;
char fileName[20];
char currentline[20];

// goto next line
char* convert(char* convert){
    char* temp=(char*) malloc(20*sizeof(char));
    strcpy(temp, convert);
     //remove spaces from current line
    int x=0;
    int y=0;
    long len=strlen(convert);
    for(x=0; x<len; x++){
        if( temp[len-1] == '\n' ){
            temp[len-1] = 0;
        }
    }
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
    //printf("%s",currentline);
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
    // A-instruction @
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
            }else {
                sym[k]=currentline[k];
                k++;
            }
        }
    }
    removeChar(sym, '(');
    //printf("%s\n",sym);
    return sym;
}


// destination command string
char* destination(void){
    char* dest=(char*) malloc(20*sizeof(char));
    int i=0;
    int c=0;
    long length= strlen(currentline);
    while (i<length) {
        if(currentline[i]=='='){
            c=1;
            i--;
            break;
        }
        i++;
    }
    if(c){
        while (i>=0) {
            
            dest[i]=currentline[i];
        i--;
    }
    }
    
    return dest;
}
// computation command string
char* computation(void){
    char* comp=(char*) malloc(20*sizeof(char));
    int i=0;
    int j=0;
    int c=0;
    long length= strlen(currentline);
    while (i<length) {
        if(currentline[i]=='='){
            j=i;
            c=1;
            break;
        }
        i++;
    }
    if(c){
        int k=0;
        for (; j<length; j++) {
            
            if(currentline[j]==';'){
                break;
            }
            comp[k]=currentline[j];
            k++;
        }
    }
    else{
        int k;
        for (k=0; k<length; k++) {
            
            if(currentline[k]==';'){
                break;
            }
            comp[k]=currentline[k];
            k++;
        }
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

