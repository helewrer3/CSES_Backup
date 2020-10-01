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
	for (int i = 0; i < n; i++) cin >> a[i];
	mll mp;
	mp[0] = 1;
	for (int i = 0; i < n; i++) {
		auto it = mp.rbegin();
		while (it != mp.rend()) {
			mp[a[i] + it->f] = 1;
			it++;
		}
	}
	vll ans;
	for (auto it : mp)
	    ans.pb(it.f);
	cout << (int)ans.size() - 1 << "\n";
	for (auto it : ans) 
	    if (it) 
	        cout << it << " ";
	cout << "\n";
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
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
