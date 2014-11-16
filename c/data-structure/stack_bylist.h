//
//  one_way_link_list.h
//  data-structure
//
//  Created by zhangle on 14/11/3.
//  Copyright (c) 2014年 zhangle. All rights reserved.
//

#ifndef stack_bylist_h
#define stack_bylist_h
struct Node;

typedef struct Node * node;
typedef node stack;

struct Node{
    int data;
    node next;
};

void init(stack*);
bool empty(stack);
void push(stack,int);
node pop(stack);
node top(stack);
void make_empty(stack);
#endif