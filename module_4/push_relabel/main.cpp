#include <iostream>
using namespace std;

struct vertex {
	int ht;    // height
	int ef; // excess flow
};

int v, e;
int **cap;
int **flow;
struct vertex *vs; // list of arrays

void initialize() {
	// initialize
	cap = new int*[v];
	flow = new int*[v];

	for (int i = 0; i < v; i++) {
		cap[i] = new int[v];
		flow[i] = new int[v];
	}

	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) { 
			cap[i][j] = 0;
			flow[i][j] = 0;
		}
	}

	vs = new vertex[v];
	for (int i = 0; i<v; i++) {
		vs[i].ht = 0;
		vs[i].ef = 0;
	}
}

void get_input() {
	cout << "Number of vertices and edges: ";
	cin >> v >> e;
	initialize();
	// input
	cout << "Enter edges in format: source, destination, capacity\n";
	for (int i = 0; i < e; i++) {
		int source, destination, capacity;
		cin >> source >> destination >> capacity;
		cap[source][destination] = capacity;
	}
}

void preflow(int s) {
	vs[s].ht = v;

	for (int i = 0; i < v; i++) {
		if (cap[s][i] != 0 && i != s) {
			flow[s][i] += cap[s][i];
			flow[i][s] -= cap[s][i];
			vs[i].ef += cap[s][i];
		}
	}
}

int get_active_node(int source, int sink) {
	for (int i = 0; i < v; i++) {
		if (i == source || i == sink) {
			continue;
		}

		if (vs[i].ef > 0) {
			for (int j = 0; j < v; j++) {
				if (cap[i][j] != 0 || flow[i][j] != 0) {
					if (cap[i][j] != flow[i][j]) {
						return i;
					}
				}
			}
		}
	}
	return -1;
}

int minm(int a, int b) {return a<b?a:b;}

bool push(int u) {
	for (int j = 0; j < v; j++) {
		if (cap[u][j] != 0 || flow[u][j] != 0) {
			if (cap[u][j] != flow[u][j]) {
				if (vs[u].ht > vs[j].ht) {
					int Flow = minm(cap[u][j] - flow[u][j], vs[u].ef);
					vs[u].ef -= Flow;
					vs[j].ef += Flow;
					return true;
				}
			}
		}
	}
	return false;
}

void relabel(int u) {
	int minh = INT_MAX;
	for (int j = 0; j < v; j++) {
		if (cap[u][j] != 0 || flow[u][j] != 0) {
			if (cap[u][j] != flow[u][j]) {
				if (vs[j].ht < minh) {
					minh = vs[j].ht;
				}
			}
			vs[u].ht = minh + 1;
		}
	}
}

int maxflow(int source, int sink) {
	preflow(source);
	int u = get_active_node(source, sink);

	while(u != -1) {
		if (!push(u)) {
			relabel(u);
		}
		u = get_active_node(source, sink);
	}

	return vs[sink].ef;
}

int main() {
	get_input();
	cout << "Apurva Mishra 22BCE2791" << endl;
	cout << "MaxFlow: \n";
	cout << maxflow(0, v-1);
}
