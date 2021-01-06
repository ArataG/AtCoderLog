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
//const int mod = 1000000007;
const int mod = 998244353;
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

int NMAX = 200100;
mint dp[200100];
mint sum[200100];

/*
    累積和をつかってDP高速化
*/

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> l(k);
  vector<int> r(k);
  REP(i,k) {
    cin >> l[i] >> r[i];
    r[i]++;
  }

  debug(l);
  debug(r);

  //dpの初期化
  REP(i, NMAX) dp[i] = 0;
  REP(i, NMAX) sum[i] = 0; //累積和
 // REP(i,n) cout << dp[i] << endl;

  dp[1] = 1;
  sum[1] = 1;

  //dpループ
  REP2(i,2,n+1){
    REP(j,k){
      int left  = max(0,i-r[j]);
      int right = max(0,i-l[j]);
      dp[i] += sum[right] - sum[left];
    }
    sum[i] = sum[i-1] + dp[i];
  }
  cout << dp[n] << endl;
  return 0;
}

//配るDP,もらうDP
//とりあえずdpが思いつく　>>　計算量間に合わない
// 区間のDP
// 累積和を使う
//　累積和のインデックスとDPのインデックスでこんがらがってしまった．
//順番にバグとりしたおかげで，時間かかったが解くことができた．
//dpを求めながら，累積和を求めるので，やや難しかった．