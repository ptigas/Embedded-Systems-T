#include "cute.h"
#include "demo.h"

int plus(int lhs, int rhs) {
	return lhs + rhs;
}

int minus(int lhs, int rhs) {
	return lhs - rhs;
}

int fibonacci(int input) {
	if (input < 0) {
		return -1;
	}
	if (input < 2) {
		return 1;
	}
	return fibonacci(input - 1) + fibonacci(input - 2);
}

void testZeroPlusZero() {
	ASSERT_EQUAL(0, plus(0, 0));
}

void testSevenPlusThree() {
	ASSERT_EQUAL(10, plus(7, 3));
}

cute::suite make_suite_demo() {
	cute::suite s;
	s.push_back(CUTE(testZeroPlusZero));
	s.push_back(CUTE(testSevenPlusThree));
	return s;
}
