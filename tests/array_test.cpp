#include <lib/Array.h>
#include <gtest/gtest.h>
#include <sstream>

TEST(ArrayTestSuite, initialization_test) {
	Array arr = Array::MakeArray(10, 10, 10);

	ASSERT_TRUE(sizeof(arr) > 0);
}

TEST(ArrayTestSuite, operator_index_test) {
	Array arr = Array::MakeArray(10, 10, 10);
	arr[0][0][0] = 1;

	ASSERT_TRUE(1 == arr[0][0][0]);
}

TEST(ArrayTestSuite, add_test) {
	Array arr = Array::MakeArray(10, 10, 10);
	Array arr1 = Array::MakeArray(10, 10, 10);
	arr1[1][0][2] = 5;
	arr[1][0][2] = 3;
    Array arr2 = Array::MakeArray(10, 10, 10);
    arr2=arr+arr1;
	ASSERT_TRUE(8 == arr2[1][0][2]);
}

TEST(ArrayTestSuite, difference_test) {
	Array arr = Array::MakeArray(10, 10, 10);
	arr[1][0][2] = 200;
	Array arr1 = Array::MakeArray(10, 10, 10);
	arr1[1][0][2] = 150;
	arr = arr - arr1;
	ASSERT_TRUE(50 == arr[1][0][2]);
}

TEST(ArrayTestSuite, multiplication_test) {
	Array arr = Array::MakeArray(10, 10, 10);
	int num = 5;
	arr[1][0][2] = 15;
	arr = arr * num;
	ASSERT_TRUE(75 == arr[1][0][2]);
}