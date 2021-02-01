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
	
	print_array(test, SIZE);
	print_statistics(test, SIZE);
	
}

int comp(const void * elem1, const void * elem2) {	
	
	// cast value stored at pointers into unsigned char
	unsigned char e1 = (*(unsigned char *)elem1);
	unsigned char e2 = (*(unsigned char *)elem2);
	
	// return result of comparison of e1 and e2
	if (e1 <= e2) return 1;
	return -1;
	
}

unsigned char * copy_array(unsigned char * arr, unsigned int length) {
	
	// manually allocate memory for copy array
	unsigned char * copy = malloc(length);
	
	// check memory 
	if (!copy) return NULL;
	
	// copy over each value
	for (int i = 0; i < length; i++) {
		
			copy[i] = arr[i];
			
	}
	
	return copy;
}

unsigned char find_maximum(unsigned char * arr, unsigned int length) {
	
	// assume first value is max
	unsigned char max = arr[0];
	
	// iterate through rest of the array, while updating max
	for (int i = 1; i < length; i++) {
		
		if (max < arr[i]) max = arr[i];
		
	}
	
	return max;
	
}

unsigned char find_minimum(unsigned char * arr, unsigned int length) {
	
	// assume first value is min
	unsigned char min = arr[0];
	
	// iterate through rest of the array, while updating min
	for (int i = 1; i < length; i++) {
		
		if (min > arr[i]) min = arr[i];
		
	}
	
	return min;

}

unsigned char find_mean(unsigned char * arr, unsigned int length) {
	
	// calculate mean using sum and length
	unsigned int sum = find_sum(arr, length);
	unsigned int mean = (sum / length); 
	
	// cast from unsigned int it unsigned char
	// this is safe because guaranteed to yield mean that is between 0-255
	return (unsigned char)mean;
	
}

unsigned char find_median(unsigned char * arr, unsigned int length) {
	
	unsigned char median = 0;
	
	// make a copy of array, sort copied array
	unsigned char * temp_arr = copy_array(arr, length);
	sort_array(temp_arr, length);
	
	// calculate median based on sorted temp array
	unsigned int median_index = length / 2;
	
	// if length is odd, median is middle value; if length is odd, median is avg of middle values
	if (length % 2 == 0) {
		
		median_index = length / 2;
		
		median = (temp_arr[median_index] + temp_arr[median_index - 1]) / 2;
		
	} else {
		
		median = temp_arr[median_index];
	
	}
	
	// manually dealllocate memory from temp_arr
	free(temp_arr);
	
	return median;
	
}

unsigned int find_sum(unsigned char * arr, unsigned int length) {
	
	// set sum to first element
	unsigned int sum = arr[0];
	
	// iterate through rest of the array, adding each element to sum
	for (int i = 1; i < length; i++) {
		
		sum += arr[i];
		
	}
	
	return sum;
	
}

void print_array(unsigned char * arr, unsigned int length) {
	
	// iterate thorugh array, print each element
	for (int i = 0; i < length; i++) {
		
		printf("[%d]: %u, ", i, arr[i]);
	
	}
	
	printf("\n");
		
	return;
	
}

void print_statistics(unsigned char * arr, unsigned int length) {
	
	// calculate stats
	unsigned char max = find_maximum(arr, length);
	unsigned char mean = find_mean(arr, length);
	unsigned char median = find_median(arr, length);
	unsigned char min = find_minimum(arr, length);
		
	// print stats
	printf("Array Stats:\n\tMax: %u\n\tMean: %u\n\tMedian: %u\n\tMin: %u\n",
			max, mean, median, min);
	
}

void sort_array(unsigned char * arr, unsigned int length) {
	
	// sort the array using comp() comparison function
	qsort(arr, length / sizeof(*arr), sizeof(*arr), comp);
	
}