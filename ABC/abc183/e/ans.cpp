#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
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

static const int NMAX = 2005;
mint dp[NMAX][NMAX];
mint dpx[NMAX][NMAX];
mint dpy[NMAX][NMAX];
mint dpxy[NMAX][NMAX];

// int dp[NMAX][NMAX];
// int dpx[NMAX][NMAX];
// int dpy[NMAX][NMAX];
// int dpxy[NMAX][NMAX];

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];
  
  dp[0][0] = 1;
  dpx[0][0] = 1;
  dpy[0][0] = 1;
  dpxy[0][0] = 1;

  REP(i,h) REP(j,w){
    if(i == 0 && j == 0) continue;
    if(s[i][j] == '#') continue;

    //配列外参照に注意:
    if(j > 0) dpx[i][j] += dpx[i][j-1];
    if(i > 0) dpy[i][j] += dpy[i-1][j];
    if (i > 0 && j > 0) dpxy[i][j] += dpxy[i-1][j-1];

    dp[i][j] += dpx[i][j];
    dp[i][j] += dpy[i][j];
    dp[i][j] += dpxy[i][j];

    dpx[i][j] += dp[i][j];
    dpy[i][j] += dp[i][j];
    dpxy[i][j] += dp[i][j];

  }

  cout << dp[h-1][w-1].x << endl;
  

  return 0;
}