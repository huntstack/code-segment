//
//  main.c
//  data-structure
//
//  Created by zhangle on 14/11/2.
//  Copyright (c) 2014年 zhangle. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack_byarray.h"

int main(int argc, const char * argv[]) {
    stack s;
    init(&s, 10);
    push(s, 1);
    push(s, 10);
    push(s, 100);
    printf("%d\n",top(s));
    pop(s);
    printf("%d\n",top(s));
    make_empty(s);
    printf("%d\n",top(s));
    
}

void init(stack * s,int length){
    int *d;
    if (length <= 0) {
        fprintf(stderr, "stack length must larger than 0");
        exit(1);
    }
    *s = malloc(sizeof(struct stack_head));
    (*s)->top = TOP;
    (*s)->max_length = length;
    d = (int *)malloc(sizeof(int)*length);
    (*s)->data = d;
}

bool is_empty(stack s){
    return s->top == TOP;
}

bool is_full(stack s){
    if (s ==NULL) {
        fprintf(stderr, "stack is null");
        exit(1);
    }
    return s->top >= --s->max_length;
}

void push(stack s,int data){
    if (is_full(s)) {
        fprintf(stderr, "stack is full");
    }else{
        s->data[++s->top] = data;
    }
}

int top(stack s){
    if (is_empty(s)) {
        fprintf(stderr, "stack is empty");
        exit(1);
    }else{
        return s->data[s->top];
    }
    return 0;
}

int pop(stack s){
    if (is_empty(s)) {
        fprintf(stderr, "stack is empty");
    }else{
        return s->data[s->top--];
    }
    return 0;
}

void make_empty(stack s){
    if (is_empty(s)) {
        printf("stack is already empty");
    }else{
        s->top = TOP;
    }
}

void delete(stack s){
    if (s != NULL) {
        free(s->data);
        free(s);
    }
}