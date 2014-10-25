//
//  main.c
//  cpl
//
//  Created by zhangle on 14-8-20.
//  Copyright (c) 2014年 zhangle. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "1.h"
#include "5.h"

#define OPERATOR "+-*/()"
#define MAXLENGTH 100

void four_arithmetic_operation();
void transfer_char_to_int(char);
int in_operator(char);
void push_char(char);
char pop_char();
void push_int(int);
int pop_int();

int  operands[MAXLENGTH];
char operators[MAXLENGTH];
int  operands_buffers = 0;
int  operators_buffers = 0;
char flag;

int main(int argc, const char * argv[])
{
    four_arithmetic_operation();
}

void four_arithmetic_operation(){
    char ch;
    int i;
    while ((ch = getchar())!=EOF) {
        if(in_operator(ch)){
            push_char(ch);
        }else if(isdigit(ch)){
            transfer_char_to_int(ch);
        }else if(isspace(ch)){
            continue;
        }else{
            printf("the input %c is illegal!\n",ch);
            exit(0);
        }
        if(flag =='\n' || ch=='\n'){
            for (i=0; i<operands_buffers; i++) {
                printf("operands[%d]=%d\n",i,operands[i]);
            }
            for (i=0; i<operators_buffers; i++) {
                printf("%c",operators[i]);
            }
            printf("\n");
        }
    }
}

int in_operator(char ch){
    int i = 0;
    while (OPERATOR[i]!='\0') {
        if(ch == OPERATOR[i++]){
            return 1;
        }
    }
    return 0;
}

void transfer_char_to_int(char ch){
    char next;
    int res=0;
    res += ch-'0';
    while ((next = getchar())!=EOF) {
        if (isdigit(next)) {
            res = res*10+(next-'0');
        }else if(next == '\n'){
            push_int(res);
            flag = next;
            break;
        }else if(in_operator(next)){
            push_int(res);
            push_char(next);
            flag = next;
            break;
        }else if(isspace(next)) {
            continue;
        }else{
            printf("the input %c is illegal!\n",next);
            exit(0);
        }
        
    }
}

void calc(){
    while(operators_buffers - operands_buffers == -1 && operators_buffers>1){
        if(operators[operators_buffers-2] == '*' || operators[operators_buffers-2] == '/'){
            
        }
    }
}

void push_char(char ch){
    if(operators_buffers<MAXLENGTH){
        operators[operators_buffers++] = ch;
    }else{
        printf("operator array is full!\n");
        exit(0);
    }
}
char pop_char(){
    if (operators_buffers>-1) {
        return operators[--operators_buffers];
    }else{
        printf("operators index error!\n");
        exit(0);
    }
}
void push_int(int ch){
    if(operands_buffers<MAXLENGTH){
        operands[operands_buffers++] = ch;
    }else{
        printf("operands array is full!\n");
        exit(0);
    }
}
int pop_int(){
    if (operands_buffers>-1) {
        return operands[--operands_buffers];
    }else{
        printf("operands index error!\n");
        exit(0);
    }
}