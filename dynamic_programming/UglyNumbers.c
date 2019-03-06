#include "UglyNumbers.h"

/* Ugly Numbers
 * ------------
 * https://www.geeksforgeeks.org/ugly-numbers/
 *
 * Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The
 * sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly
 * numbers. By convention, 1 is included. Given a number n, the task is to
 * find n’th Ugly number.
 */

uint64_t nthUglyNumber(uint64_t n) {
	uint64_t maxDivide(uint64_t a, uint64_t b) {
		while(a%b==0) {
			a = a/b;
		}
		return a;
	}
	uint64_t isUgly(uint64_t no) {
		no = maxDivide(no, 2);
		no = maxDivide(no, 3);
		no = maxDivide(no, 5);

		return (no == 1)? 1 : 0;
	}
	int i = 1;
	int count = 1; // ugly number counter

	while (n > count) {
		i++;
		if (isUgly(i))
			count++;
	}
	return i;
}


uint64_t nthUglyNumberDynamic(uint64_t n) {
	uint64_t ugly[n]; // store ugly numbers
	uint64_t i2 = 0, i3 = 0, i5 = 0;
	uint64_t nextMultipleOf2 = 2;
	uint64_t nextMultipleOf3 = 3;
	uint64_t nextMultipleOf5 = 5;
	uint64_t nextUglyNumber = 1;

	ugly[0] = 1;
	for(int i=1; i<n; i++) {
		nextUglyNumber = fmin(nextMultipleOf2, fmin(nextMultipleOf3, nextMultipleOf5));
		ugly[i] = nextUglyNumber;
		if (nextUglyNumber == nextMultipleOf2) {
			i2 = i2+1;
			nextMultipleOf2 = ugly[i2]*2;
		}
		if (nextUglyNumber == nextMultipleOf3) {
			i3 = i3+1;
			nextMultipleOf3 = ugly[i3]*3;
		}
		if (nextUglyNumber == nextMultipleOf5) {
			i5 = i5+1;
			nextMultipleOf5 = ugly[i5]*5;
		}
	}
	return nextUglyNumber;
}

void runUgly(UGLY_FUNC ugly_func) {
    int n;
    printf("Enter desired ugly number index: ");
    fflush(stdout);
    scanf("%d", &n);

    printf("Ugly Numbers: ");

    begin = clock();
	printf("%"PRIu64", ", ugly_func(n));
    end = clock();
    printf("\r\n");
    printf("Time: %lf", (double)(end - begin) / CLOCKS_PER_SEC);
}

void compareUglyFunctions() {
	runUgly(&nthUglyNumber);
	printf("\r\n");
	runUgly(&nthUglyNumberDynamic);
}
