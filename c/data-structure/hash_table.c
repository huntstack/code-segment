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
#include <string.h>
#include "hash_table.h"

int main(int argc, const char * argv[]) {
    
}

int hash(char * str,int size){
    int i=0;
    while (*str!='\0') {
        i += *str++;
    }
    return i % size;
}

char * copy_str(char * s){
    char * p;
    p = malloc(strlen(s));
    if (p != NULL) {
        strcpy(p,s);
    }
    return p;
}

hash_table init(int size){
    int i;
    hash_table h = (hash_table)malloc(sizeof(struct Hash_Table));
    if (h == NULL) {
        printf("out of space\n");
        exit(1);
    }
    h->table_size = size;
    h->table_list = malloc(sizeof(list)*size);
    if (h->table_list == NULL) {
        printf("out of space\n");
        exit(1);
    }
    for (i = 0; i<size; i++) {
        h->table_list[i] = malloc(sizeof(struct Node));
        if (h->table_list[i] == NULL) {
            printf("out of space\n");
            exit(1);
        }
        h->table_list[i]->next = NULL;
    }
    return h;
}

node find(hash_table t,char * str){
    node n = t->table_list[hash(str, t->table_size)];
    while (n->next != NULL && strcmp(n->next->key_words, str) != 0) {
        n = n->next->next;
    }
    return n;
}

void insert(hash_table t,char * str){
    node n;
    list l;
    n = malloc(sizeof(struct Node));
    n->key_words = copy_str(str);
    l = t->table_list[hash(str, t->table_size)];
    n->next = l->next;
    l->next = n;
}
