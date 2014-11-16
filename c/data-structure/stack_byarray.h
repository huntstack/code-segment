//
//  stack_byarray.h
//  data-structure
//
//  Created by zhangle on 14/11/8.
//  Copyright (c) 2014年 zhangle. All rights reserved.
//

#ifndef data_structure_stack_byarray_h
#define data_structure_stack_byarray_h

#define TOP -1

struct stack_head;
typedef struct stack_head * stack;

struct stack_head{
    int max_length;
    int top;
    int *data;
};

void init(stack * s,int length);
bool is_empty(stack s);
bool is_full(stack s);
void push(stack s,int data);
int top(stack s);
int pop(stack s);
void make_empty(stack s);
void delete(stack s);
#endif
