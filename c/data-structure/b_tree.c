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
#include "b_tree.h"

int main(int argc, const char * argv[]) {
    b_tree t;
    add(&t, "abc");
    add(&t, "efg");
    printf("%s",t->right->key_words);
    
    return 0;
}

bool is_empty(b_tree tree){
    return tree->key_words == NULL;
}

char * copy_str(char * str){
    char * s;
    s = (char *)malloc(strlen(str)+1);
    if (s!=NULL) {
        strcpy(s, str);
    }
    return s;
}

void add(b_tree *tree, char * str){
    if (*tree == NULL) {
        *tree = (node)malloc(sizeof(tree_node));
        (*tree)->key_words = copy_str(str);
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }else if(strcmp((*tree)->key_words, str) > 0){
        add(&(*tree)->left,str);
    }else if(strcmp((*tree)->key_words, str) < 0){
        add(&(*tree)->right,str);
    }else{
        printf("node is already exist\n");
    }
}

node find_min(b_tree tree){
    if (tree == NULL) {
        printf("not found");
        return NULL;
    }
    if (tree->left == NULL) {
        return tree;
    }else{
        return find_min(tree->left);
    }
}

node find_max(b_tree tree){
    if (tree == NULL) {
        printf("not found");
        return NULL;
    }
    if (tree->right == NULL) {
        return tree;
    }else{
        return find_max(tree->right);
    }
}

b_tree delete(b_tree tree, char * str){
    node n;
    if (tree == NULL) {
        printf("not found");
        return NULL;
    }
    if (strcmp(tree->key_words, str) > 0) {
        tree->right = delete(tree->right,str);
    }else if (strcmp(tree->key_words, str) < 0) {
        tree->left = delete(tree->left,str);
    }else{
        if (tree->right && tree->left) {
            n = find_min(tree->right);
            tree->key_words = copy_str(n->key_words);
            tree->right = delete(tree->right, tree->key_words);
        }else{
            n = tree;
            if (tree->left == NULL) {
                tree = tree->right;
            }else if (tree->right == NULL){
                tree = tree->left;
            }
            free(n);
        }
    }
    
    return tree;
}