#include "Fibonacci.h"
uint64_t fib(uint64_t n) {
	if (n <= 1)
		return n;
	return fib(n-1) + fib(n-2);
}

uint64_t fibDynamic(uint64_t n) {
	uint64_t f[n+2];
	uint64_t i;

	f[0] = 0, f[1] = 1;

	for (i = 2;i <= n; i++) {
		f[i] = f[i-1] + f[i-2];
	}

	return f[n];
}

void runFibonacci(FIB_FUNC fib_func, bool printList) {
    int i, n;
    printf("Enter the number of terms: ");
    fflush(stdout);
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    begin = clock();
    if (printList) {
		for (i = 0; i < n; ++i)
		{
			printf("%"PRIu64", ", fib_func(i));
		}
    }
    else {
    	printf("%"PRIu64", ", fib_func(n-1));
    }
    end = clock();
    printf("\r\n");
    printf("Time: %lf", (double)(end - begin) / CLOCKS_PER_SEC);
}

void compareFibFunctions() {
	runFibonacci(&fib, false);
	printf("\r\n");
	runFibonacci(&fibDynamic, false);
}
