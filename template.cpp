#include <bits/stdc++.h>
 
#define scd second
#define fst first
#define pb push_back
#define mkp make_pair
#define all(x) x.begin(), x.end()
#define VT(T) vector<T>
 
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vint;
typedef vector<ll> vlong;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vint> vvint;
typedef vector<vlong> vvlong;
typedef list<int> lint;
typedef list<ll> llong;
typedef list<pii> lpii;
typedef list<pll> lpll;
typedef list<lint> llint;
typedef list<llong> lllong;
 
ll const LINF=numeric_limits<long long int>::max();
int const INF=numeric_limits<int>::max();
 
ll gcd(ll a, ll b){
	return b ? gcd(b,a%b) : a;
}
 
ll pow_mod(ll a, ll e, ll m){
	ll res=1;
	while(e){
		if(e&1) res=res*a%m;
		a=a*a%m;
		e>>=1;
	}
	return res;
}
 
ll inv_mod(ll b, ll m){
	b%=m;
	ll x=0, y=1, r, q, a=m;
	while(b){
		q=a/b;
		r=a%b;
		a=b;
		b=r;
		r=x;
		x=y;
		y=r-q*y;
	}
	x+=m;
	return x%m;
}