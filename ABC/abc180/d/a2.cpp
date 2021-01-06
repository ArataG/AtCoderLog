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

//最初の方はA，その後はBでやるとよい．


int main(){
  ll x, y, a, b;
  cin >> x >> y >> a >> b;
  ll ans = 0;
  while(1){
     if(y/a < x) break;
     if(a*x >= y) break;
     if(a*x >= x+b) break;
     x*=a;
     ++ans;
  }
  ans += (y-1-x)/b; //ここの境界条件を具体例で調べるべきだった．
  cout << ans << endl;
  return 0;
}