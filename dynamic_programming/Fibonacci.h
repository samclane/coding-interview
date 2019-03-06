/*
 * Fibonacci.h
 *
 *  Created on: Mar 5, 2019
 *      Author: SawyerPC
 */

#ifndef DYNAMIC_PROGRAMMING_FIBONACCI_H_
#define DYNAMIC_PROGRAMMING_FIBONACCI_H_

#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <inttypes.h>

typedef uint64_t(*FIB_FUNC)(uint64_t);

clock_t begin;
clock_t end;
double time_spent;

uint64_t fib(uint64_t n);
uint64_t fibDynamic(uint64_t n);

void runFibonacci(FIB_FUNC fib_func, bool printList);
void compareFibFunctions();

#endif /* DYNAMIC_PROGRAMMING_FIBONACCI_H_ */
