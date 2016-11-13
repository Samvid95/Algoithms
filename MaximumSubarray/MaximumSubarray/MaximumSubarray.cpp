// MaximumSubarray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <tuple>
#include <array>
#include <math.h>

using namespace std;

const size_t SIZE=100;


tuple<int, int, int> find_max_crossing_subarray(array<int, SIZE> A, int low, int mid, int high) {
	int left_sum = numeric_limits<int>::min();
	int sum = 0;
	int max_left;
	for (int i = mid; i > low; i--) {
		sum = sum + A[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = numeric_limits<int>::min();
	sum = 0;
	int max_right;
	for (int i = mid+1; i < high; i++) {
		sum = sum + A[i];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = i;
		}
	}
	return make_tuple(max_left, max_right, left_sum + right_sum);
}

tuple<int,int,int> find_maximum_subarray(array<int, SIZE> A, int low, int high) {
	if (high == low) {
		return make_tuple(low, high, A[low]);
	}
	else{
		int mid = floor((low + high) / 2);
		//get<0>(leftTuple) is left_low;get<1>(leftTuple) is left_high; get<2>(leftTuple) is left_sum;
		auto leftTuple = find_maximum_subarray(A, low, mid); 
		//get<0>(rightTuple) is right_low;get<1>(rightTuple) is right_high; get<2>(rightTuple) is right_sum;
		auto rightTuple = find_maximum_subarray(A, mid + 1, high);
		//get<0>(crossTuple) is cross_low;get<1>(crossTuple) is cross_high; get<2>(crossTuple) is cross_sum;
		auto crossTuple = find_max_crossing_subarray(A, low, mid, high);

		if (get<2>(leftTuple) >= get<2>(rightTuple) && get<2>(leftTuple) >= get<2>(crossTuple)) {
			return leftTuple;
		}
		else if (get<2>(rightTuple) >= get<2>(leftTuple) && get<2>(rightTuple) >= get<2>(crossTuple)) {
			return rightTuple;
		}
		else {
			return crossTuple;
		}
	}
}

int main()
{

	array<int, SIZE> A = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	auto answer = find_maximum_subarray(A, 0, 15);
	std::cout << "the lower index is: " << get<0>(answer) + 1  << "\n"
		<< " the higher index i:s " << get<1>(answer) + 1 << "\n"
		<< " and the sum is: " << get<2>(answer) << endl;


	return 0;
}

