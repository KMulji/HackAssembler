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


//char currentline[40];
char* currentline;

// goto next line
void convert(char* convert){
     removeChar(convert, ' ');
     removeChar(convert, '\t');
    removeChar(convert, '\n');
    // printf("convert input: %s\n", convert);
//    char* temp=(char*) malloc(40*sizeof(char));
    currentline=(char*) malloc(40*sizeof(char));
    
     //remove spaces from current line
    int x=0;
    
    long len=strlen(convert);
    int hasComment = 0;
    for(x=0; x<len; x++){ // copy until reaches '//'
        
        if (convert[x] == '/') {
            currentline[x]='\0';
            hasComment = 1;
            break;
        }
        currentline[x] = convert[x];
    }
    if(!hasComment)
        currentline[x-1]='\0';
    
//    strcpy(currentline, temp);
    
//    free(temp); doesn't work since strcpy to currentline
    // printf("%s\n",currentline);
//    return currentline;
}

// if the command is a A,C OR L Command or a comment to skip
int commandType(void){
    //printf("%s", currentline);
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
        // printf("We got \\0 here.\n with currentline %s", currentline);
        return 3;
    }
    // c command
    return 4;
}

//L command string
char* symbol(void){
    // a command or () label. remove @ and ()
    char* sym=(char*) malloc(40*sizeof(char));
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
//    printf("comp is %s\n", comp);
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

void freeParser() {
    free(currentline);
    // printf("Free(currentline) Successful\n");
}

