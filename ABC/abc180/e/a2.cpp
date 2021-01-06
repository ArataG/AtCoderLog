#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1001001001;

void chmin(int& x, int y) {x = min(x,y);}

int main(){
  //cout << INF << endl;
  int n;
  cin >> n;
  vector<int> x(n), y(n), z(n);
  REP(i,n) cin >> x[i] >> y[i] >> z[i];
  
  int n2  = 1<<n; //nの二乗
  vector<vector<int>> dp(n2, vector<int>(n, INF));

  vector<vector<int>> dist(n, vector<int>(n));
  

  //distの前計算
  REP(i,n)REP(j,n){
    dist[i][j] = abs(x[i] - x[j]) + abs(y[i]- y[j]) + max(0,z[j]- z[i]);
  }


  //初期状態は0のなる
  REP(i,n) {
    if(i == 0) continue;
    dp[1 << i][i] = dist[0][i];
  }
//cout << "hi" << endl;
  REP(i,n2)REP(j,n){
    if(~i>>j&1) continue; //~ はnotをとっている
    REP(k,n) {
      if( i >> k&1) continue;
      chmin(dp[i|1<<k][k], dp[i][j]+dist[j][k]);
     }
  }
  cout << dp[n2-1][0] << endl;
  return 0;
}
