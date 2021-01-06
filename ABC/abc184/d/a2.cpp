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

const int N = 100;
double dp[N+1][N+1][N+1]; //金 i 枚，銀 j 枚，銅 k枚ある状態の期待値とする．

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  //DPテーブルを大きい方から埋めていく
  for(int i = N - 1; i >= 0; i--){
    for(int j = N - 1; j >= 0; j--){
      for(int k = N - 1; k >= 0; k--){
        if(i+j+k == 0) continue;
        double tmp = 0;
        tmp += dp[i+1][j][k] * i;
        tmp += dp[i][j+1][k] * j;
        tmp += dp[i][j][k+1] * k;

        dp[i][j][k] = tmp/(i+j+k) + 1; 
      }
    }
  }
  double ans = dp[a][b][c];
  cout << fixed << setprecision(10) << ans << endl;  
  return 0;
}