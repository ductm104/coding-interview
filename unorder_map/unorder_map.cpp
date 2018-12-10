/*	Problem:
 *		Given array A with N elements.
 *		Find a subsequence that, after sorting, we have increasily natural sequence,
 *		and the length is maximum
 *	Input:
 *		First line: N < 1e6
 *		Second line: a_1 .. a_n, a_i < 1e9
 *	Output:
 *		The maximum length
 */

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<int, int> data;
bool visited[10000];
int q[10000];

int find(int value, int dot) {
	do {
		unordered_map<int, int>::iterator got = data.find(value + dot);
		if (got == data.end()) {
			return value;
		}
		value = value + dot;
		visited[got->second] = true;
	} while(true);
	return value;
}

int main() {
	int n, a[10000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		data[a[i]] = i;
	}

	for (int i = 0; i < n; i++)
		visited[i] = false;

	int res = -1;
	
	for (int i = 0; i < n; i++) {
		if (!visited[i] || data.find(a[i]) == data.end()) {
			int lt = find(a[i], -1);
			int rt = find(a[i], +1);
			res = max(res, rt-lt+1);
			visited[i] = true;
		}
	}

	cout << res;
	return 0;
}
