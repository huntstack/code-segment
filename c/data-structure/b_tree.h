//
//  Header.h
//  data-structure
//
//  Created by zhangle on 14/11/11.
//  Copyright (c) 2014年 zhangle. All rights reserved.
//

#ifndef data_structure_b_tree_h
#define data_structure_b_tree_h

typedef struct Node tree_node;
typedef tree_node * b_tree;
typedef tree_node * node;

struct Node{
    char * key_words;
    node left;
    node right;
};

void add(b_tree * tree, char * str);
char * copy_str(char * str);
bool is_empty(b_tree tree);

#endif
