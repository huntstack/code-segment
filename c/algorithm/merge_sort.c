//
//  main.c
//  algorithm
//
//  Created by zhangle on 14/11/26.
//  Copyright (c) 2014年 zhangle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void merge_sort(int * array, int size);
void sort(int * array,int * temp,int left,int right);
void merge(int * array,int * temp,int left,int right,int end);


int main(int argc, const char * argv[]) {
    int i;
    int input_array[10] = {-4,-3,5,-2,-1,2,6,-2,9,-5};
    int len = sizeof(input_array)/sizeof(int);
    merge_sort(input_array, len);
    for (i=0; i<len; i++) {
        printf("%d ",input_array[i]);
    }
    return 0;
}


void merge_sort(int * array, int size){
    int * temp;
    temp = malloc(sizeof(int) * size);
    if (temp == NULL) {
        printf("No space\n");
        exit(1);
    }
    sort(array,temp,0,size-1);
}

void sort(int * array,int * temp,int left,int right){
    int center;
    if (left<right) {
       center = (left+right)/2;
        sort(array,temp,left,center);
        sort(array,temp,center+1,right);
        merge(array,temp,left,center+1,right);
    }
}

void merge(int * array,int * temp,int left,int right,int right_end){
    int i,left_end,num,t;
    left_end = right-1;
    t = left;
    num = right_end - left +1;
    
    while (left<=left_end && right <= right_end) {
        if (array[left]<= array[right]) {
            temp[t++] = array[left++];
        }else{
            temp[t++] = array[right++];
        }
    }
    
    while (left<=left_end) {
        temp[t++] = array[left++];
    }
    while (right<=right_end) {
        temp[t++] = array[right++];
    }
    
    for (i=0; i< num; i++,right_end--) {
        array[right_end] = temp[right_end];
    }
}