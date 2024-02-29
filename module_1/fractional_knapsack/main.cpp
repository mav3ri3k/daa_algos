#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item {
	float value;
	float weight;
	float ratio;

	item(float v, float w) {
		value = v;
		weight = w;
		ratio = v/w;
	}
	item() {}
};

vector<item> items;
int n;
int target;

bool compare(item a, item b) {
	return a.ratio>b.ratio;
}

void get_input() {
	cin >> n >> target;
	for (int i = 0; i < n; i++) {
		item tmp;
		cin >> tmp.value >> tmp.weight;
		tmp.ratio = tmp.value/tmp.weight;

		items.push_back(tmp);
	}

	sort(items.begin(), items.end(), compare);
}

int main() {
	cout << "Apurva Mishra 22BCE2791\n";
	get_input();

	float t_value = 0; // total value
					  //
	int i = 0;
	while(true) {
		if (items[i].weight <= target) {
			t_value += items[i].value;
			target -= items[i].weight;
			i += 1;
		} else {
			float ratio = target/items[i].weight;
			t_value += items[i].value*ratio;
			break;
		}
	}
	cout << "Max Value: " << t_value << "\n";
}
