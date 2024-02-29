#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct item {
	float value;
	int weight;

	item(float v, int w) {
		value = v;
		weight = w;
	}
	item() {}
};

int items_num;
item *items;
int capacity;

// to store finals solutions where value and weight are sum
struct sol {
	float t_value; // total value
	int t_weight; // total weight
	
	sol(float v, int w) {
		t_value = v;
		t_weight = w;
	}
	sol() {}
};

stack<item> stk;

// find sum of stack to items to get total value
// returns potential solution
sol find_sol() {
	stack<item> tmp;

	float t_v = 0;
	int t_w = 0;
	while(!stk.empty()) {
		t_v += stk.top().value;
		t_w += stk.top().weight;
		tmp.push(stk.top());
		stk.pop();
	}

	while(!tmp.empty()) {
		stk.push(tmp.top());
		tmp.pop();
	}
	return sol(t_v, t_w);
}

// take input
void get_input() {
	cin >> items_num >> capacity;
	items = new item[items_num];

	for (int i = 0; i < items_num; i++) {
		float tmp_v;
		int tmp_w;
		cin >> tmp_v >> tmp_w;
		items[i] = item(tmp_v, tmp_w);
	}
}

// utility function
void print_stack(string name) {
	cerr << name << " ";
	stack<item> tmp;
	float t_v = 0;
	int t_w = 0;

	while(!stk.empty()) {
		t_v += stk.top().value;
		t_w += stk.top().weight;
		tmp.push(stk.top());
		stk.pop();
	}
	cerr << t_v << " " << t_w << "\n";
	while(!tmp.empty()) {
		stk.push(tmp.top());
		tmp.pop();
	}
}

// maintain solution with max value and weight < capacity
sol ans = sol(0, 0);
// utility function
void print_sol() {
	cerr << "	ans: " << ans.t_value << " " << ans.t_weight << "\n";
}

void pop() {
	if (!stk.empty()) {
		stk.pop();
	}
}

void solution(int sum, int ptr) {
	cerr << "START " << sum << " " << ptr << "\n";
	if (sum > capacity) {
		print_stack("sum > capacity");
		print_sol();
		pop();
		cerr << "END " << sum << " " << ptr << "\n";
		return;
	} else if (sum == capacity) {
		sol tmp = find_sol();
		if (tmp.t_value > ans.t_value) {
			ans = tmp;
		}
		print_stack("sum == capacity");
		print_sol();
		pop();
		cerr << "END " << sum << " " << ptr << "\n";
		return;
	}

	for (int i = ptr; i < items_num; i++) {
		stk.push(items[i]);
		solution(sum + items[i].weight, i + 1);
	}

	sol tmp = find_sol();
	if (tmp.t_value > ans.t_value) {
		ans = tmp;
	}
	pop();
	print_stack("end of array");
	print_sol();
	cerr << "END " << sum << " " << ptr << "\n";
}


void print_input(string name) {
	cerr << name << "\n";
	for (int i = 0; i < items_num; i++) {
		cerr << "value: " << items[i].value << " weight: " << items[i].weight << "\n";
	}
}

int main() {
	cout << "Apurva Mishra 22BCE2791\n";
	get_input();
	print_input("Take Input");
	solution(0, 0);
	print_stack("after solution");
	cout << "Value: " << ans.t_value << ", Weight: " << ans.t_weight << "\n";
}
