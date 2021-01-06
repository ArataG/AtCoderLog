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

static const int n = 101;
int dp[n];

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  

  REP(i,n) dp[i] = 0;
  REP(i,a+1) dp[i] = 1;

  REP(i,n){
    if(i <= a ) continue;
    dp[i] = dp[i-1]*1; //1 >> dp[i-1]/sumになる
  }

  int ans = dp[100]*ope;

  //REP(i,n) cout << dp[i] << endl;

  return 0;
}