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
#define REP(i,n) for (int i = 0; i <(n); ++i)
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }


int main(){
  ll x,k,d;
  cin >> x >> k >> d;

  //回数が十分ではないとき
  if(k < abs(x)/d){
    ll ans = (ll)abs(x) - k*d;
    cout << ans << endl;
    return 0;
  }

  ll c = abs(x)/d;
  debug(c);
  ll e_pos = abs(x) - c*d;
  ll o_pos = abs(e_pos - d);

  k -= c;
  if(k%2 == 0) cout << e_pos << endl;
  else  cout << o_pos << endl;
  return 0;
}