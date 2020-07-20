/*May The Force Be With Me*/
#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>
#pragma GCC optimize ("Ofast")
#define ll long long
#define MOD 1000000007
#define endl "\n"
#define vll vector<long long>
#define mll map<long long,long long>
#define pll pair<long long, long long>
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define pb push_back
#define f first
#define s second
#define inf INT_MAX
#define size_1d 10000000
#define size_2d 1000
#define rep(i,v,n) for(ll i = v; i < n; i++)
//Snippets: delta, sieve, fastexp, dfs, bfs, dijkstra, floodfill

using namespace std;


void Input() {
}

void Solve() {
	string a, b;
	cin >> a >> b;
	ll n = a.size(), m = b.size();
	ll c[n + 1][m + 1];
	for (ll i = 0; i < n + 1; i++) for (ll j = 0; j < m + 1; j++)c[i][j] = inf;
	c[0][0] = 0;
	for (ll i = 0; i < n + 1; i++) for (ll j = 0; j < m + 1; j++) {
			if (i)c[i][j] = min(c[i][j], c[i - 1][j] + 1);
			if (j)c[i][j] = min(c[i][j], c[i][j - 1] + 1);
			if (i and j)c[i][j] = min(c[i][j], c[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
		}
	cout << c[n][m];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll T = 1;
	//cin >> T;
	//ll t = 1;
	while (T--) {
		Input();
		//cout << "Case " << t << ": ";
		Solve();
		//t++;
	}
	return 0;
}