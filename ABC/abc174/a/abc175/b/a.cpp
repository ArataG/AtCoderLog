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
  int n;
  cin >> n;
  vector<int> l(n);
  REP(i,n) cin >> l[i];
  debug(l);
  sort(ALL(l));
  ll cnt = 0;
  REP(i,n-2){
    REP2(j,i+1,n-1){
      REP2(k,j+1,n){
        if(l[i]==l[j] || l[j] == l[k] || l[k] == l[i]) continue;
        ll sum = (ll)l[i]+l[j]+l[k];
        int maxl = max({l[i],l[j],l[k]});
        if(maxl < (ll)sum - maxl) cnt++;
      }
    }    
  }
  cout << cnt << endl;
  return 0;
}