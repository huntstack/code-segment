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
typedef node double_cycle_link_list;

struct Node{
    int data;
    node previous;
    node next;
};

void add_node(double_cycle_link_list *,int);
void init(double_cycle_link_list *);
bool is_empty(double_cycle_link_list);
node move_to_end(double_cycle_link_list);
void print_list(double_cycle_link_list);
node find_node(double_cycle_link_list,int);
node find_node_by_index(double_cycle_link_list,int);
void insert_node(double_cycle_link_list,int,int);
void delete_node(double_cycle_link_list,int);
void delete_list(double_cycle_link_list*);
#endif