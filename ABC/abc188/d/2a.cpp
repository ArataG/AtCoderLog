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

ll sum[INF];

int main(){
  //#define int long long
  ll n, c;
  cin >> n >> c;
  REP(i,n){
    int a, b, cost;
    cin >> a >> b >> cost;
    ++b;
    sum[a] += cost;
    sum[b] += -cost;
  }

  REP2(i,1,INF){
    sum[i] = sum[i-1] + sum[i];
  }

  //debug(sum);
  ll ans = 0;
  REP(i,INF){
    ans += min(c, sum[i]);
  }

  cout << ans << endl;


  return 0;
}