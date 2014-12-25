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

void shell_sort(int * array, int size);

int main(int argc, const char * argv[]) {
    int i;
    int input_array[10] = {-4,-3,5,-2,-1,2,6,-2,9,-5};
    int len = sizeof(input_array)/sizeof(int);
    shell_sort(input_array, len);
    for (i=0; i<len; i++) {
        printf("%d ",input_array[i]);
    }
    return 0;
}


void shell_sort(int * array, int size){
    int i,j,increment,temp;
    for (increment = size/2; increment > 0; increment /= 2) {
        for (i = increment; i < size; i++) {
            temp = array[i];
            for (j = i; j >= increment; j-= increment) {
                if (temp < array[j-increment]) {
                    array[j] = array[j-increment];
                }
                else
                    break;
            }
            array[j] = temp;
        }
    }
    
}
