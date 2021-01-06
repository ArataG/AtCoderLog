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


int main(){
  //#define int long long
  int n;
  cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];
  ll ans = 0;
  sort(ALL(a));
  vector<ll> sum(n);
  sum[0] = a[0];
  REP2(i,1, n) sum[i] = sum[i-1]+a[i];
  debug(sum);
  REP(i,n){
   if(i != 0  ) ans += abs(sum[i-1] - a[i]*i);
   if(i != n-1) ans += abs(sum[n-1]-sum[i] - a[i]*(n-1-i));
   debug(i);
   debug(ans);
  }
  
  cout << ans/2 << endl;

  return 0;
}