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
  int a, b, c;
  cin >> a >> b >> c;
  
  //
  int n = 100;
  double dp[n+1][n+1];
  REP(i,n+1)REP(j,n+1) dp[i][j] = 0;

  dp[a][b] = 1;
  double EPS = 0.000000001;

  //dpテーブルを埋める
  REP2(i,1,n+1){
    REP2(j,1,n+1){
      if(i <= a && j <= b) continue;
      dp[i][j] = dp[i-1][j]* (i-1)/(i+j-1) + dp[i][j-1]*(j-1)/(i+j-1);
      if(dp[i][j] < EPS) dp[i][j] = 0;
    }
  }

  //回数　= i + j -  a- b;
  double sum = 0;
  REP2(i,a,n) {
    //cout << "num" << n-b +i-a << endl;
    sum += dp[i][n] * (n-b +i-a);
    //cout << dp[i][n] << endl;
  }
  //REP2(i,b,n) sum += dp[n][i];
  REP2(i,b,n) {
    //cout << "num:" << n-a +i-b << endl;
    sum += dp[n][i] * (n-a +i-b);
    //cout << dp[n][i] << endl;
  }

  cout << sum << endl;

  return 0;
}