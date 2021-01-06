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

ll f(int x){
  ll res = x*(x-1)/2;
  return res;
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  REP(i,n) cin >> a[i] >> b[i];

  ll ans = 0;

  REP(i,n){
    ll tmp = (ll)(b[i]-a[i]+1)*((ll)a[i]+b[i])/2;
    ans += tmp;
  }

  cout << ans << endl;

}