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
#define MY_VAR 100000
using namespace std;

ll n;

void Input() {
	cin >> n;
}

void Solve() {
	ll t = n * (n + 1) / 2;
	if (t % 2)cout << 0;
	else {
		t /= 2;
		ll b[n][t + 1];
		for (ll i = 0; i < n; i++)for (ll j = 0; j <= t; j++)b[i][j] = 0;
		b[0][0] = 1;
		for (ll i = 1; i < n; i++)for (ll j = 0; j <= t; j++) {
				b[i][j] += b[i - 1][j];
				b[i][j] %= MOD;
				if (j - i >= 0)b[i][j] += b[i - 1][j - i];
				b[i][j] %= MOD;
			}
		cout << b[n - 1][t];
	}
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
