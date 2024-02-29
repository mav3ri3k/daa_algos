#include <iostream>

//test case {2, -3, 4, 5} => ans 9
int *arr;
int size;

int m(int a, int b) {
  return a>b?a:b;
}

void take_input() {
	std::cin >> size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		std::cin >> arr[i];
	}
}

int max(int a, int b, int c) {
  int tmp = m(a, b);
  return m(tmp, c);
}

int cross_sum(int low, int high) {
  int mid = low + (high - low)/2;

  int sum = 0;
  int left_sum = -99;
  for (int i = mid; i >= low; i--) {
    sum += arr[i];

    if (sum > left_sum) {
      left_sum = sum;
    }
  }

  sum = 0;
  int right_sum = -99;
  for (int i = mid+1; i <= high; i++) {
    sum += arr[i];

    if (sum > right_sum) {
      right_sum = sum;
    }
  }

  return max(left_sum, right_sum, left_sum + right_sum);
}

int max_subarray(int low, int high) {
  if (low >= high) {
    return arr[low];
  }
  int mid = low + (high - low)/2;

  int sum_left = max_subarray(low, mid);
  int sum_right = max_subarray(mid + 1, high);

  int sum_cross = cross_sum(low, high);

  return max(sum_left, sum_cross, sum_right);
}

int main() {
  std::cout << "Apurva Mishra 22BCE2791\n";
  take_input();
  std::cout << "Max Sum: " << max_subarray(0, size - 1);
}
