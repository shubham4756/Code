/*
Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/non-intersecting-segments-c414f948/description/
Editorial is already open
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;
#define L first
#define R second
const int maxn = 1e5 + 100;
int fix[maxn], fiy[maxn], sex[maxn], sey[maxn], arr[maxn];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector <pair<pii,int> > Fi, Se;
	for (int i = 0; i < n; i++) {
		cin >> fix[i] >> fiy[i] >> sex[i] >> sey[i];
		Fi.push_back({{fix[i], fiy[i]}, i});
		Se.push_back({{sex[i], sey[i]}, i});
	}
	sort (Fi.begin(), Fi.end());
	sort (Se.begin(), Se.end());
	for (int i = 0; i < n; i++) {
		int idF = lower_bound(Fi.begin(), Fi.end(), make_pair(make_pair(fix[i], fiy[i]), -1)) - Fi.begin();
		int idS = lower_bound(Se.begin(), Se.end(), make_pair(make_pair(sex[i], sey[i]), -1)) - Se.begin();
		arr[idF] = idS;
	}
	set <int> s;
	for (int i = 0; i < Fi.size(); i++) {
		if (s.lower_bound(arr[i]) != s.end())
			s.erase(s.lower_bound(arr[i]));
		s.insert(arr[i]);
	}
	cout << s.size() << endl;
	return 0;
}
