#include <iostream>
#include <string>
#include <stack>
using namespace std;

int lenght_values;
int target;
// 6 55
int *values;
// {15, 20, 30, 40, 22, 33};

void get_input() {
	cin >> lenght_values >> target;
	values = new int[lenght_values];
	for (int i = 0; i < lenght_values; i++) {
		cin >> values[i];
	}
}

stack<int> stk;

void print_stack() {
  stack<int> tmp;

  while(!stk.empty()) {
    int t = stk.top();
    tmp.push(t);
    stk.pop();
  }

  while (!tmp.empty()) {
    int t = tmp.top();
    cout << t << " ";

    stk.push(t);
    tmp.pop();
  }
  cout << endl;
}

void log(int ptr, int i, string str, bool end) {
  for (int j = 0; j < ptr + 1; j++) {
    cout << " | ";
  }
  if (end) {
    cout << str << " " << ptr << "." << i << " ";
    cout << endl;
  }
}

int find_array(int capacity_sum, int ptr) {
  if (capacity_sum > target) {
    stk.pop();
    return 0;
  }

  if (capacity_sum == target) {
    cout << "Match: " << " ";
    print_stack();
    stk.pop();
    return 0;
  }


  for (int i = ptr; i < lenght_values; i++) {
    stk.push(values[i]);
    find_array(capacity_sum + values[i], i + 1);
  }
  stk.pop();
  return 0;
} 

int main() {
  cout << "Apurva Mishra 22BCE2791\n";
  get_input();
  find_array(0, 0);
  exit(0);
}
