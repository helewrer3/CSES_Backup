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

ll n;

void Input() {
	cin >> n;
}

void Solve() {
	vll a(n);
	ll su = 0;
	for (ll i = 0; i < n; i++) cin >> a[i], su += a[i];
	ll b[n][n];
	for (ll i = 0; i < n; i++) for (ll j = 0; j < n; j++)b[i][j] = 0;
	for (ll i = n - 1; i >= 0; i--)for (ll j = i; j < n; j++) {
			if (i == j)b[i][j] = a[i];
			else b[i][j] = max(a[i] - b[i + 1][j], a[j] - b[i][j - 1]);
		}
	cout << (su + b[0][n - 1]) / 2;
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