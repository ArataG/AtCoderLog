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


void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int x = 0;
  REP(i,n) x ^= a[i];
  
  int cnt = 0;
  REP(i,n){
    if(a[i] %2 == 0) cnt++;
  }
  
  if(cnt % 2 == 0){
      if(x!=0) cout << "First" << endl;
     else cout << "Second" << endl;
  }
  else{
      if(x!=0) cout << "Second" << endl;
       else cout << "First" << endl;
  }


}

int main(){
  int t;
  cin >> t;
  REP(i,t) solve();
  return 0;
}