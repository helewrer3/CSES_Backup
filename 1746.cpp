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

ll n, m;
ll del[] = { -1, 0, 1};

void Input() {
	cin >> n >> m;
}

void Solve() {
	vll a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	ll b[n][m + 1];
	for (ll i = 0; i < n; i++) for (ll j = 0; j <= m; j++) b[i][j] = 0;
	if (a[0])b[0][a[0]] = 1;
	else for (ll i = 0; i <= m; i++)b[0][i] = 1;

	for (ll i = 1; i < n; i++) {
		if (a[i]) {
			for (ll k = 0; k < 3; k++) if (a[i] + del[k] >= 1 and a[i] + del[k] <= m)
					b[i][a[i]] = (b[i][a[i]] + b[i - 1][a[i] + del[k]]) % MOD;

		}
		else {
			for (ll j = 1; j <= m; j++) {
				for (ll k = 0; k < 3; k++) if (j + del[k] >= 1 and j + del[k] <= m)
						b[i][j] = (b[i][j] + b[i - 1][j + del[k]]) % MOD;
			}
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= m; i++) ans = (ans + b[n - 1][i]) % MOD;
	cout << ans;

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