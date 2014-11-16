//
//  Header.h
//  data-structure
//
//  Created by zhangle on 14/11/11.
//  Copyright (c) 2014年 zhangle. All rights reserved.
//

#ifndef data_structure_hash_table_h
#define data_structure_hash_table_h

struct Node;
typedef struct Node * node;
typedef node list;
typedef struct Hash_Table * hash_table;

struct Node{
    char * key_words;
    node next;
};

struct Hash_Table{
    int table_size;
    list *table_list;
};

hash_table init(int size);
node find(hash_table t,char * str);
void insert(hash_table t,char * str);
#endif
