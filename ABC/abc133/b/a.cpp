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

bool f(int s){
  REP(i,400){
    if(s == i*i) return true;
  }
  return false;
}

int main(){
  //#define int long long
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n);
  REP(i,n){
    REP(j,d){
      int a;
      cin >> a;
      x[i].push_back(a);
    }
  }
  debug(x);
  int ans = 0;
  REP(i,n-1){
    REP2(j,i+1,n){
      int sum = 0;
      REP(k,d){
       sum += abs(x[i][k] - x[j][k])*abs(x[i][k] - x[j][k]);
      }
      debug(sum);
      if(f(sum)) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}