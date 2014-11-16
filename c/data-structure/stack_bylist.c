//
//  stack_bylist.c
//  data-structure
//
//  Created by zhangle on 14/11/8.
//  Copyright (c) 2014年 zhangle. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack_bylist.h"

void init(stack * s){
    stack st = (stack)malloc(sizeof(struct Node));
    if (st == NULL) {
        fprintf(stderr,"out of space\n");
        exit(1);
    }
    st->next = NULL;
    *s = st;
}

bool empty(stack s){
    return s->next == NULL?true:false;
}

void push(stack s,int data){
    node n = (node)malloc(sizeof(struct Node));
    if (n == NULL) {
        fprintf(stderr,"out of space\n");
        exit(1);
    }
    n->data = data;
    n->next = s->next;
    s->next = n;
}

node top(stack s){
    if (empty(s)) {
        printf("stack is empty\n");
        exit(1);
    }else
        return s->next;
}

node pop(stack s){
    node d;
    if (!empty(s)) {
        d = s->next;
        s->next = s->next->next;
        free(s->next);
        return d;
    }
    printf("stack is empty\n");
    exit(1);
}

void make_empty(stack s){
    while (!empty(s)) {
        pop(s);
    }
}
