#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

//テストケースTに対すスコア

int main(){
  int D;
  cin >> D;
  vector<int> c(D);
  int s[D][26];

  REP(i,26) cin >> c[i];
  REP(d,D){
    REP(i,26){
      int x;
      cin >> x;
      s[d][i] = x;
    }
  }
  vector<int> t(D);

  REP(d,D){
    int x;
    cin >> x;
    --x;
    t[d] = x;
  }

  int last[26];  //コンテストが最後に行われた日
  REP(i,26) last[i] = -1;
  int ans = 0;

  REP(d,D){
    int ci = t[d];
    ans += s[d][ci];
    last[ci] = d;

    REP(i,26){
      ans -= c[i] * (d - last[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
