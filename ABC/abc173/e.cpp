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


int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> s, t;   //正の配列， tの配列
  REP(i,n){
    cin >> a[i];
    if(a[i] < 0 ) t.push_back(a[i]);
    else s.push_back(a[i]);
  }

  int S = s.size();
  int T = t.size();

  bool ok = false;  //積が正にできるか？

  if(S > 0){
    if(n == k) ok = (T%2 == 0);
    else ok = true;
  }
  else{ //正の数が０個のとき
  ok = (k%2 == 0);
  }

  mint ans = 1;


  //答えが負になるとき
  if(!ok){
    sort(a.begin(), a.end(), [](int x, int y) {
      return abs(x) < abs(y);
    });
    REP(i,k) ans *= a[i];
  }
  //答えが正
  else{
    sort(ALL(s));
    sort(RALL(t));
    if(k % 2 == 1){
      ans *= s.back();  //最後の値を参照
      s.pop_back(); //最後の値を除去
    }


    //二個セットの配列を作製

    vector <ll> p;
    while(s.size() >= 2){
      ll x = s.back();
      s.pop_back();
      x *= s.back(); s.pop_back();
      p.push_back(x);
    }

    while(t.size() >= 2){
      ll x = t.back();
      t.pop_back();
      x *= t.back(); t.pop_back();
      p.push_back(x);
    }

    sort(RALL(p));
    REP(i,k/2) ans *= p[i];
  }

  cout << ans << endl;


  return 0;


}


// int main(){
//   int n,k;
//   cin >> n >> k;
//   vector<int> a(n);
//   // REP(i,n) cin >> a[i];
//   //
//   // sort(ALL(a));
//   vector<int> plus;
//   vector<int> minus;
//   REP(i,n){
//     int a;
//     cin >> a;
//     if( a >= 0) plus.push_back(a);
//     else minus.push_back(-a);
//   }
//
//   sort(RALL(plus));
//   sort(RALL(minus));
//
//   for(auto x: plus) cout << x << endl;
//   for(auto x: minus) cout << x << endl;
//
//   int pi = 0;
//   int mi = 0;
//   ll sum = 1;
//
//   for(int i = 0; i < k -1 ; i + 2){
//
//     if(plus[pi] * plus[pi + 1] > minus[mi]* minus[mi+1]){
//       sum *= plus[pi]%mod * plus[pi+1]%mod;
//       pi+=2;
//     }
//
//     else{
//       sum *= minus[mi]%mod*minus[mi+1]%mod;
//       mi+=2;
//     }
//
//   }
//
//   if(k%2 == 1){
//     sum *= plus[pi];
//   }
//
//   cout << sum << endl;
//
//   return 0;
// }
