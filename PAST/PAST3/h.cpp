#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

int LM = 100005;
int dp[4][LM];
static const int INF = 100000009;

int main(){

  int n, l;
  cin >> n >> l;
  vector<int> x(l);
  REP(i,l) x[i] = 0;
  REP(i,n) {
    int a;
    cin >> a;
    x[a] = 1;
  }
  int t1, t2, t3;
  cin >> t1 >> t2 >> t3;

  //REP(i,l) dp[0][i] = INF;
  dp[1][0] = 0;
  dp[2][0] = 0;
  dp[3][0] = 0;

  REP2(i,1,l) {
    if(x[i]== 0) dp[1][i] = dp[i-1] + t1;
    else dp[1][i] = dp[i-1] + t3;
  }

  REP2(i,1,l){
    int pre = max(0, i-2);
    if(x[i] == 0){
      dp[2][i] = min(dp[1][i], dp[2][pre]+t2);
    }
    else{
      dp[2][i] = min(dp[1],[j], dp[2][pre]+t2)
    }
  }

  REP2(i,1,l){
    int pre = max(0, i - 4);
    if(x[i] == 0){
      dp[3][i] = min(dp[2][i], dp[3][pre]+t2);
    }
    else{
      dp[3][i] = min(dp[2],[j], dp[3][pre]+t2)
    }

  }


  cout << dp[3][l] << endl;




  return 0;
}
