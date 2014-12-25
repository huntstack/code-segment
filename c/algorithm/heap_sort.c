//
//  main.c
//  algorithm
//
//  Created by zhangle on 14/11/2.
//  Copyright (c) 2014年 zhangle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct HeapNode;
typedef struct HeapNode * heap;

struct HeapNode{
    int capacity;
    int size;
    int * data;
};

heap init(int max, int min_data);
bool if_full(heap h);
void insert(int d, heap h);
void sort(heap h,int index);

int main(int argc, const char * argv[]) {
    heap H;
    int i;
    H = init(5, -1);
    insert(3, H);
    insert(10, H);
    insert(5, H);
    insert(7, H);
    insert(4, H);
    for (i = H->size; i >= 1; i--) {
        sort(H, i);
    }
    for (i = 1; i<=H->size; i++) {
        printf("%d ",H->data[i]);
    }
}

heap init(int max, int min_data){
    heap h;
    h = malloc(sizeof(struct HeapNode));
    if (h == NULL) {
        fprintf(stderr, "out of space");
        exit(1);
    }
    
    h->data = malloc(sizeof(int) * (max+1));
    
    if (h->data == NULL) {
        fprintf(stderr, "out of space");
        exit(1);
    }
    
    h->capacity = max;
    h->size = 0;
    h->data[0] = min_data;
    
    return h;
}

bool if_full(heap h){
    return h->size > h->capacity;
}

void insert(int d, heap h){
    int i;
    if (if_full(h)) {
        printf("heap is full");
        return;
    }
    
    for (i = ++h->size; h->data[i/2] > d; i/= 2) {
        h->data[i] = h->data[i/2];
    }
    h->data[i] = d;
}

void sort(heap h, int index){
    int i,child,min,last;
    min = h->data[1];
    last = h->data[index];
    for (i=1; i *2 < index; i = child) {
        child = i * 2;
        if (child != index && h->data[child+1] < h->data[child]) {
            child++;
        }
        if (last > h->data[child]) {
            h->data[i] = h->data[child];
        }else
            break;
    }
    h->data[i] = last;
    h->data[index] = min;
}