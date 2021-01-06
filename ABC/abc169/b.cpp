#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MX = 1e18;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  
  ll ans = 1;
  REP(i, n){
    cin >> a[i];
    //1e18を超えて，その後に０となるとansが０なのにー１と出力してしまうため，先にチェックしておく．
    if(a[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }

  REP(i,n){

    //かけてから判定するとオーバーフローしてしまう．9*10^18くらい
    // if(ans > MX){
    //   cout << -1 << endl;
    //   return 0;
    if(MX/ans < a[i]){
      cout << -1 << endl;
      return 0;

    }
    ans *= a[i];
  }


  cout << ans << endl;
  return 0;
}
