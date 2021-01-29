/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <implementation file for first Coursera assignment >
 *
 *
 * @author <Edwin Lantigua >
 * @date <01/28/20 >
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
								
	//print_array(test, SIZE);
	//unsigned char max = find_maximum(test, SIZE);
	//printf("Maximum: %u\n", max);
	//unsigned char min = find_minimum(test, SIZE);
	//printf("Minimum: %u\n", min);
	//unsigned char mean = find_mean(test, SIZE);
	//printf("Mean %u\n", mean);
	sort_array(test, SIZE);
	print_array(test, SIZE);
	
}

/* Add other Implementation File Code Here */

int comp(const void * elem1, const void * elem2) {	
	
	return ( *(int *)elem1 - *(int *)elem2);
	
}

unsigned char find_maximum(unsigned char * arr, unsigned int length) {
	
	unsigned char max = arr[0];
	
	for (int i = 1; i < length; i++) {
		
		if (max < arr[i]) max = arr[i];
		
	}
	
	return max;
	
}

unsigned char find_minimum(unsigned char * arr, unsigned int length) {
		
	unsigned char min = arr[0];
	
	for (int i = 1; i < length; i++) {
		
		if (min > arr[i]) min = arr[i];
		
	}
	
	return min;

}

unsigned char find_mean(unsigned char * arr, unsigned int length) {
	
	unsigned int sum = find_sum(arr, length);
	return (sum / length);
	
}

unsigned char find_median(unsigned char * arr, unsigned int length);

unsigned int find_sum(unsigned char * arr, unsigned int length) {
	
	unsigned int sum = arr[0];
	
	for (int i = 1; i < length; i++) {
		
		sum += arr[i];
		
	}
	
	return sum;
	
}

void print_array(unsigned char * arr, unsigned int n) {
	
	for (int i = 0; i < n; i++) {
		
		printf("[%d]: %u\n", i, arr[i]);
	
	}
		
	return;
	
}

void print_statistics(unsigned char * arr);

void sort_array(unsigned char * arr, unsigned int length) {
	
	//unsigned char art[4] = {12, 45, 2, 7};
	qsort(arr, sizeof(arr) / sizeof(*arr), sizeof(*arr), comp);
	//print_array(art, 4);
	
}