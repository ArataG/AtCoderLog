#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

//-----DPでもとける

int main(){
  int x;
  cin >> x;

  int INF = 100005;

  bool dp[INF];
  REP(i,INF) dp[i] = false;
  REP2(i,100, 106) dp[i] = true;

  REP2(i,106,x+1){
    if(dp[i-100] || dp[i-101] || dp[i-102] || dp[i-103] || dp[i-104] || dp[i-105]){
      dp[i] = true;
    }
  }

  if(dp[x]) cout << 1 << endl;
  else cout << 0 << endl;
  return 0;
}

// int main(){
//   int x;
//   cin >> x;
//   int num = x / 100;
//
//   int l = num * 100;
//   int r = num * 105;
//
//   if(x >= l && x <= r) cout << 1 << endl;
//   else cout << 0 << endl;
//   return 0;
// }
