#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  ll a, v, b, w, t;
  cin >> a >> v;
  cin >> b >> w;
  cin >> t;

  ll le, vs;
  //vs * t = 10^１８となるのでオーバーフローする．intは１０＾９まで．llは１０＾１９辺りまで使える　オーバーフローを意識していなかったため，WAを連発してしまった．

  le = abs(a - b); //min = 1;
  vs = v - w;

  if(vs * t >= le) cout << "YES" << endl;
  // if(ll(vs * t) > = le) cout << "YES" << endl; //としてもよい
  else cout << "NO" << endl;
  return 0;
}
