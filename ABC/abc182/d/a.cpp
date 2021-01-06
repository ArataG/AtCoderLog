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


int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> sum(n);

  REP(i,n) cin >> a[i];

  ll s = 0;
  REP(i,n){
    s += a[i];
    sum[i] = s;
  }

  vector<ll> tmpmax(n);
  
  ll ts = 0;
  REP(i,n){
    ts += a[i];
    if(i == 0){
      tmpmax[i] = max((ll)0,ts);
      continue;
    }
    tmpmax[i] = max(ts, tmpmax[i-1]);
  }

  //debug(tmpmax);

  ll ans = 0;
  ll tmp = 0;

  REP(i,n){
    ans  = max(ans, tmp+tmpmax[i]);
    tmp += sum[i];
  }

  cout << ans << endl;
  return 0;
}