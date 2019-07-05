#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable: 4996)

#define Max_V 10000

vector< vector<int> > v(Max_V, vector<int>(4,0));
vector< vector<int> > dist(Max_V, vector<int>(4,0));

int main() {
	int house;
	cin >> house;

	int color;
	for (int i = 1; i <= house; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> color;
			v[i][j] = color;
		}
	}

	for (int i = 1; i <= house; i++) {
		dist[i][1] = min(dist[i - 1][2], dist[i - 1][3]) + v[i][1];
		dist[i][2] = min(dist[i - 1][1], dist[i - 1][3]) + v[i][2];
		dist[i][3] = min(dist[i - 1][1], dist[i - 1][2]) + v[i][3];
	}

	cout << min(dist[house][1],min(dist[house][2],dist[house][3])) << endl;
	return 0;
}