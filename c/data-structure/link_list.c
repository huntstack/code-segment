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
#include "link_list.h"

int main(int argc, const char * argv[]) {
    list link_list;
    init(&link_list);
    add_node(link_list, 10);
    add_node(link_list, 11);
    add_node(link_list, 11);
    add_node(link_list, 15);
    insert_node(link_list,20,0);
    insert_node(link_list,30,3);
    delete_node(link_list,30);
    print_list(link_list);
    delete_list(link_list);
    print_list(link_list);
    return 0;
}

void init(list * p_link_list){
    *p_link_list = (list)malloc(sizeof(struct Node));
    /*
     * parentheses is mandatory
     * p_link_list's type is list *
     * *p_link_list->next = *(p_link_list->next)
     */
    (*p_link_list)->next = NULL;
}

bool is_empty(list link_list){
    return link_list->next==NULL;
}

node move_to_end(list link_list){
    node n;
    if (link_list->next == NULL) {
        n = link_list;
    }else{
        n = move_to_end(link_list->next);
    }
    return n;
}

void add_node(list link_list,int data){
    node n = (node)malloc(sizeof(struct Node));
    n->data = data;
    n->next = NULL;
    move_to_end(link_list)->next = n;
}

void print_list(list link_list){
    int i;
    node n;
    if (is_empty(link_list)) {
        fprintf(stderr, "the list is empty!\n");
        exit(1);
    }
    for (i=1,n=link_list->next; n!=NULL; i++,n=n->next) {
        printf("第%d个节点:%d\n",i,n->data);
    }
}

node find_node(list link_list,int data){
    node n;
    if (is_empty(link_list)) {
        fprintf(stderr, "the list is empty!\n");
        exit(1);
    }
    for (n=link_list->next; n!=NULL; n=n->next) {
        if (n->data == data) {
            return n;
        }
    }
    return NULL;
}

node find_node_by_index(list link_list,int index){
    node n;
    if (is_empty(link_list)) {
        fprintf(stderr, "the list is empty!\n");
        exit(1);
    }
    for (n=link_list->next; n!=NULL && --index>0; n=n->next) {
        ;
    }
    if (index>0) {
        fprintf(stderr, "exceed index\n");
        exit(1);
    }
    return n;
}

//position 0:next of header node
void insert_node(list link_list,int data,int position){
    node n;
    n = (node)malloc(sizeof(struct Node));
    n->data = data;
    if (position == 0) {
        n->next = link_list->next;
        link_list->next = n;
    }else{
        n->next = find_node_by_index(link_list, position)->next;
        find_node_by_index(link_list, position)->next = n;
    }
    
}

void delete_node(list link_list,int data){
    node temp;
    if (is_empty(link_list)) {
        printf("list is empty\n");
    }else{
        while (link_list->next!=NULL) {
            if (link_list->next->data == data) {
                temp = link_list->next;
                link_list->next = link_list->next->next;
                free(temp);
            }
            link_list = link_list->next;
        }
    }
}

void delete_list(list link_list){
    node temp;
    temp = link_list->next;
    link_list->next = NULL;
    link_list = temp;
    while (link_list!=NULL) {
        temp = link_list->next;
        free(link_list);
        link_list = temp;
    }
}