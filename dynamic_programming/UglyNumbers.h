/*
 * UglyNumbers.h
 *
 *  Created on: Mar 6, 2019
 *      Author: SawyerPC
 */

#ifndef DYNAMIC_PROGRAMMING_UGLYNUMBERS_H_
#define DYNAMIC_PROGRAMMING_UGLYNUMBERS_H_

#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

typedef uint64_t(*UGLY_FUNC)(uint64_t);

clock_t begin;
clock_t end;
double time_spent;

uint64_t nthUglyNumber(uint64_t n);
uint64_t nthUglyNumberDynamic(uint64_t n);

void runUgly(UGLY_FUNC ugly_func);
void compareUglyFunctions();

#endif /* DYNAMIC_PROGRAMMING_UGLYNUMBERS_H_ */
