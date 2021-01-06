#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

static const int INF = 1000000000;

int main(){
  int a, r, n;
  cin >> a >> r >> n;
  ll ans = a;
  if(ans > INF){
    cout << "large" << endl;
  }

  REP2(i,1,n){
    ans *= r;
    if(ans > INF){
      cout << "large" << endl;
      return 0;
    }
  }

  cout << ans << endl;
  return 0;
}
