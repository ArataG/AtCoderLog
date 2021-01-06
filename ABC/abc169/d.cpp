#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll a;
  double b;
  cin >> a >> b;
  ll bb = 100*b;

  ll ans = a*b/100;

  //printf("%.f", ans);
  cout << ans << endl;

}
