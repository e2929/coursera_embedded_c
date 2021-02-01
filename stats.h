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
 * @file <stats.h> 
 * @brief <Header file for first Coursera assignment >
 *
 *
 * @author <Edwin Lantigua >
 * @date <01/28/20 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <A compare function. Largest to smallest order)>
 *
 * <Given two pointers elem1 and elem2, if elem1 is <= elem2, return 1, otherwise -1 (largest to smallest)>
 *
 * @param <const void * elem1> <first element>
 * @param <const void * elem1> <second element>
 *
 * @return <int, result of comparison>
 */
int comp(const void * elem1, const void * elem2);

/**
 * @brief <Returns a copy of unsigned char array>
 *
 * <Given an array of data and a length, returns a copy of the array>
 *
 * @param <unsigned char * arr> <The array>
 * @param <unsigned int length> <The length of the array>
 *
 * @return <unsigned car *, copy of the array>
 */
unsigned char * copy_array(unsigned char * arr, unsigned int length);

/**
 * @brief <Returns the max value in array>
 *
 * <Given an array of data and a length, returns the maximum>
 *
 * @param <unsigned char * arr> <The array>
 * @param <unsigned int n> <The length of the array>
 *
 * @return <unsigned int>
 */
unsigned char find_maximum(unsigned char * arr, unsigned int length);

/**
 * @brief <Returns the min value in array>
 *
 * <Given an array of data and a length, returns the minimum>
 *
 * @param <unsigned char * arr> <The array>
 * @param <unsigned int n> <The length of the array>
 *
 * @return <unsigned int>
 */
unsigned char find_minimum(unsigned char * arr, unsigned int length);

/**
 * @brief <Returns the mean value in array>
 *
 * <Given an array of data and a length, returns the mean>
 *
 * @param <unsigned char * arr> <The array>
 * @param <unsigned int n> <The length of the array>
 *
 * @return <unsigned int>
 */
unsigned char find_mean(unsigned char * arr, unsigned int length);

/**
 * @brief <Returns the median value in array>
 *
 * <Given an array of data and a length, returns the median>
 *
 * @param <unsigned char * arr> <The array>
 * @param <unsigned int n> <The length of the array>
 *
 * @return <unsigned int>
 */
unsigned char find_median(unsigned char * arr, unsigned int length);

/**
 * @brief <Returns the sum of values in array>
 *
 * <Given an array of data and a length, returns the sum of all values>
 *
 * @param <unsigned char * arr> <The array>
 * @param <unsigned int n> <The length of the array>
 *
 * @return <unsigned int>
 */
unsigned int find_sum(unsigned char * arr, unsigned int length);

/**
 * @brief <Prints an array>
 *
 * <Given an array of data and a length, prints the array to the screen>
 *
 * @param <unsigned char * arr> <The array to be printed>
 * @param <unsigned int n> <The length of the array>
 *
 * @return <Void>
 */
void print_array(unsigned char * arr, unsigned int length);

/**
 * @brief <Print stats of an array>
 *
 * <A function that prints the statistics of an array including minimum, maximum, mean, and median.>
 *
 * @param <unsigned char * arr> <The array to be provided stats for>
 *
 * @return <Void>
 */
void print_statistics(unsigned char * arr, unsigned int length);

/**
 * @brief <Sorts an array>
 *
 * <Given an array of data and a length, sorts the array from largest to smallest.>
 *
 * @param <unsigned char * arr> <The array to be sorted>
 * @param <unsigned int n> <The length of the array>
 *
 * @return <Void>
 */
void sort_array(unsigned char * arr, unsigned int length);

#endif /* __STATS_H__ */
