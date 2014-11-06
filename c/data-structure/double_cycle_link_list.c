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
#include "double_cycle_link_list.h"

int main(int argc, const char * argv[]) {
    double_cycle_link_list link_list;
//    init(&link_list);
    add_node(&link_list, 10);
    add_node(&link_list, 11);
    add_node(&link_list, 12);
    add_node(&link_list, 11);
    add_node(&link_list, 13);
//    add_node(&link_list, 15);
//    insert_node(link_list,20,0);
//    insert_node(link_list,30,3);
    delete_node(link_list,11);
    delete_list(&link_list);
    print_list(link_list);
    return 0;
}

//void init(double_cycle_link_list * p_link_list){
//    *p_link_list = (double_cycle_link_list)malloc(sizeof(struct Node));
//    (*p_link_list)->next = *p_link_list;
//    (*p_link_list)->previous = *p_link_list;
//}

bool is_empty(double_cycle_link_list link_list){
    return 0==(int)link_list;
}

node move_to_end(double_cycle_link_list link_list){
    if (is_empty(link_list)) {
        return link_list;
    }
    return link_list->previous;
}

void add_node(double_cycle_link_list *link_list,int data){
    node n = (node)malloc(sizeof(struct Node));
    if (is_empty(*link_list)) {
        *link_list = n;
        n->previous = *link_list;
    }else{
        n->previous = (*link_list)->previous;
    }
    n->data = data;
    n->next = *link_list;
    (*link_list)->previous->next = n;
    (*link_list)->previous = n;
}

void print_list(double_cycle_link_list link_list){
    int i;
    node n;
    if (is_empty(link_list)) {
        fprintf(stderr, "the list is empty!\n");
        exit(1);
    }
    for (i=1,n=link_list; n!=link_list->next; i++,link_list=link_list->next) {
        printf("第%d个节点:%d\n",i,link_list->data);
    }
    printf("第%d个节点:%d\n",i,link_list->data);
}

node find_node(double_cycle_link_list link_list,int data){
    node n;
    if (is_empty(link_list)) {
        fprintf(stderr, "the list is empty!\n");
        exit(1);
    }
    for (n=link_list; n!=link_list->next; link_list=link_list->next) {
        if (link_list->data == data) {
            return link_list;
        }
    }
    return NULL;
}

node find_node_by_index(double_cycle_link_list link_list,int index){
    node n;
    if (is_empty(link_list)) {
        fprintf(stderr, "the list is empty!\n");
        exit(1);
    }
    for (n=link_list; n!=link_list->next && --index>0; link_list=link_list->next) {
        ;
    }
    if (index>0) {
        fprintf(stderr, "exceed index\n");
        exit(1);
    }
    return link_list;
}

void insert_node(double_cycle_link_list link_list,int data,int position){
    node n;
    n = (node)malloc(sizeof(struct Node));
    n->data = data;
    n->previous = find_node_by_index(link_list, position);
    n->next = find_node_by_index(link_list, position)->next;
    find_node_by_index(link_list, position)->next = n;
}

void delete_node(double_cycle_link_list link_list,int data){
    node n,temp;
    if (is_empty(link_list)) {
        printf("list is empty\n");
    }else{
        for (n=link_list; n!=link_list->next; link_list=link_list->next) {
            if (link_list->data == data) {
                link_list->previous->next = link_list->next;
                link_list->next->previous = link_list->previous;
                temp = link_list;
                free(temp);
            }
        }
    }
}

void delete_list(double_cycle_link_list *link_list){
    node temp,n;
    n = (*link_list)->previous;
    while (n!=(*link_list)->next) {
        temp = n->previous;
        free(n);
        n = temp;
    }
    free(*link_list);
    *link_list = NULL;
}