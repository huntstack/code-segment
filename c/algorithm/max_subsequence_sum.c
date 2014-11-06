//
//  main.c
//  algorithm
//
//  Created by zhangle on 14/11/2.
//  Copyright (c) 2014年 zhangle. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max_subsequence_sum1(const int *,int);
int max_subsequence_sum2(const int *,int);
int max_subsequence_sum3(const int *,int,int);
int max_subsequence_sum4(const int *,int);

int main(int argc, const char * argv[]) {
    
    int input_array[10] = {-4,-3,5,-2,-1,2,6,-2,9,-5};
    int len = sizeof(input_array)/sizeof(int);
    printf("the max sum is %d\n",max_subsequence_sum1(input_array,len));
    printf("the max sum is %d\n",max_subsequence_sum2(input_array,len));
    printf("the max sum is %d\n",max_subsequence_sum3(input_array,0,len-1));
    printf("the max sum is %d\n",max_subsequence_sum4(input_array,len));
    return 0;
}

//O(N^3)
int max_subsequence_sum1(const int *input,int length){
    int sum,max_sum = 0;
    int i,j,k;
    int begin = 0;
    int end = 0;
    for (i=0; i<length; i++) {
        for (j=i; j<length; j++) {
            sum = 0;
            for (k=i; k<=j; k++) {
                sum += input[k];
            }
            if (sum > max_sum) {
                max_sum = sum;
                begin = i;
                end = j;
            }
        }
    }
    return max_sum;
}

//O(N^2)
int max_subsequence_sum2(const int *input,int length){
    int sum,max_sum = 0;
    int i,j;
    int begin = 0;
    int end = 0;
    for (i=0; i<length; i++) {
        sum = 0;
        for (j=i; j<length; j++) {
            sum += input[j];
            if (sum > max_sum) {
                max_sum = sum;
                begin = i;
                end = j;
            }
        }
    }
    return max_sum;
}

//O(NlogN)
int max_subsequence_sum3(const int *input,int left,int right){
    int i,sum,mid,l_sum,r_sum,max_sum=0;
    int max_left,max_right,max_left_borer,max_right_border;
    
    if (right == left) {
        return input[left];
    }
    
    mid = (left+right)/2;
    max_left = max_subsequence_sum3(input, left, mid);
    max_right = max_subsequence_sum3(input, mid+1, right);
    
    l_sum=0;max_left_borer = 0;
    for (i=mid; i>=left; i--) {
        l_sum += input[i];
        if (l_sum>max_left_borer) {
            max_left_borer = l_sum;
        }
    }
    
    r_sum=0;max_right_border = 0;
    for (i=mid+1; i<=right; i++) {
        r_sum += input[i];
        if (r_sum>max_right_border) {
            max_right_border = r_sum;
        }
    }
    
    sum = max_left_borer+max_right_border;
    max_sum = max_left>max_right?max_left:max_right;
    
    return max_sum>sum?max_sum:sum;
}

//O(N)
int max_subsequence_sum4(const int *input,int length){
    int sum,max_sum;
    int i;
    sum=max_sum=0;
    for (i=0; i<length; i++) {
        sum += input[i];
        if (sum>max_sum) {
            max_sum = sum;
        }else if(sum<0){
            sum = 0;
        }
    }
    return max_sum;
}
