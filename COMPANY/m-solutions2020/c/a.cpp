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

/*
  掛け算にも計算時間がカカkるのを忘れずに
  ほぼ桁数に比例？


*/

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // ll pre = 1;
  //
  // REP(i,k){
  //   pre *= (ll)a[i];
  // }

  //cout << pre << endl;


  REP2(i,k,n){
    // ll now = (ll)pre/a[i-k];
    // now *= (ll)a[i];
    //cout << now << endl;
    if(a[i] > a[i-k]) cout << "Yes" << endl;
    else cout << "No" << endl;

  }


  return 0;
}
