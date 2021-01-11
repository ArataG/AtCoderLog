#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define DREP(i,n) for (int i = (n-1); i >=0; --i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
template<typename T1, typename T2> void view(pair<T1,T2> e) { cout << "("<< e.first << ", " << e.second <<")"  << endl;}
template<typename T1, typename T2> void view(const vector<pair<T1,T2>>& v) {for(const auto& e: v){view(e);}}
// end debug



/*
  mint mod int
*/
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


//pascal の三角形を前計算
mint c[4005][4005];
void init(){
  c[0][0] = 1;
  for(int i = 0; i <= 4000; i++){
    for(int j = 0; j <= i; j++){
      c[i+1][j] += c[i][j];
      c[i+1][j+1] += c[i][j];
    }
  }
}

mint comb(int n, int k){
   return c[n][k];
}

mint f2(int n, int k){
  return comb(n+k-1, k-1);
}

mint f(int n, int k){
  if(n < k) return 0;
  if(n==0 && k == 0) return 1;
  if(k < 1 ) return 0;
  return f2(n-k, k);
}


int main(){
  //#define int long long
  int n, k;
  cin >> n >> k;
  init();
  REP2(i, 1, k+1){
    mint blue = f(k, i);
    mint red = 0;
    {
      red += f(n-k, i-1);
      red += f(n-k, i);
      red += f(n-k, i);
      red += f(n-k, i+1);
    }
    mint ans = blue * red;
    cout << ans.x << endl;
  }

  
  return 0;
}