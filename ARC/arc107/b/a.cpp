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

int n, k;

ll sum(int x){
  if( x == 2) return 1;
  if(x == 2*n) return 1;

  int minx = max(x - n, 1);
  int maxx = min(n,x);
  ll ans = maxx - minx+1;
  if(x%2 == 0) ans--;
  return ans;
}


int main(){
  //int n, k;
  cin >> n >> k;

  ll ans = 0;

  REP2(i, 2, 2*n+1){
    int m = i - k;
    if(m < 2 ) continue;
    if(m > 2*n) continue;
    debug(i);
    debug(m);
    ll sump = sum(i);
    ll summ = sum(m);
    // debug(sump);
    // debug(summ);
    ans += (ll)sump*summ;
  }

  cout << ans << endl;
  //10314607400
  //10314605301

  
  return 0;
}