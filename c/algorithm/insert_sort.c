//
//  main.c
//  algorithm
//
//  Created by zhangle on 14/11/2.
//  Copyright (c) 2014年 zhangle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void insert_sort(int * array,int length);
int main(int argc, const char * argv[]) {
    int i;
    int input_array[10] = {-4,-3,5,-2,-1,2,6,-2,9,-5};
    int len = sizeof(input_array)/sizeof(int);
    insert_sort(input_array, len);
    for (i=0; i<len; i++) {
        printf("%d ",input_array[i]);
    }
    return 0;
}

void insert_sort(int * array,int length){
    int temp,i,j;
    for (i=0; i<length; i++) {
        temp = array[i];
        for (j=i; j>0 && array[j-1] > temp; j--) {
            array[j] = array[j-1];
        }
        array[j] = temp;
    }
}