//
//  one_way_link_list.h
//  data-structure
//
//  Created by zhangle on 14/11/3.
//  Copyright (c) 2014年 zhangle. All rights reserved.
//

#ifndef data_structure_link_list_h
#define data_structure_link_list_h

struct Node;
typedef struct Node * node;
typedef node list;

struct Node{
    int data;
    node next;
};

void add_node(list,int);
void init(list *);
bool is_empty(list);
node move_to_end(list);
void print_list(list);
node find_node(list,int);
node find_node_by_index(list,int);
void insert_node(list,int,int);
void delete_node(list,int);
void delete_list(list);
#endif
