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


int main(){
  ll x, y, a, b;
  cin >> x >> y >> a >> b;

  ll na = 0;
  ll nb = 0;
  if(b > y){
      while(1){
      if(x >= y/a) break;
      na++;
      x *= a;
     }
     cout << na << endl; 
     return 0;
  }
  
  //y > b
  while(1){
    if(x >= b/a) break;
    if(x < b) na++;
    x *= a;
  }

  debug(x);
  debug(na);
 
  if( y-x > 0) nb = (y-x)/b;
  
  ll ans = na + nb;

  cout << ans << endl;


  return 0;
}