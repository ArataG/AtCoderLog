#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
//const int mod = 998244353;
struct mint {
	ll x; // typedef long long ll;
	mint(ll x=0):x((x%mod+mod)%mod){}
	mint operator-() const { return mint(-x);}
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod-a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
	mint operator+(const mint a) const { return mint(*this) += a;}
	mint operator-(const mint a) const { return mint(*this) -= a;}
	mint operator*(const mint a) const { return mint(*this) *= a;}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t>>1);
		a *= a;
		if (t&1) a *= *this;
		return a;
	}
	// for prime mod
	mint inv() const { return pow(mod-2);}
	mint& operator/=(const mint a) { return *this *= a.inv();}
	mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<int> c(n+1);//候補数の分布の配列
  /*
  候補数の分布を更新．
  c[0] = 3;               c[0] = 2;
  c[1] = 0;   a[i]= 0     c[1] = 1;
  c[2] = 0;     >>        c[2] = 0;
  :
  c[n] = 0;               c[n] = 0;

  */

  c[0] = 3;
  mint ans = 1;
  REP(i,n){
    ans *= c[a[i]]; //候補数分，分岐する．
  // 候補数を更新
    c[a[i]]--;
    c[a[i]+1]++;
  }

  cout << ans.x << endl;
  return 0;

}
