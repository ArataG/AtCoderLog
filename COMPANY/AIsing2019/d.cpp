#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<int> x(q);
  REP(i,q) cin >> x[i];
  //前処理
  vector<ll> sum(n);
  vector<ll> sum_e(n);
  ll s = 0;
  ll se = 0;
  REP(i,n) {
    s += a[i];
    if(i%2 == 0) se += a[i];
    sum[i] = s;
    sum_e[i] = se;
  }
  cout << endl;
  //
  // for(auto x : sum) cout << x << endl;
  // for(auto x : sum_e) cout << x << endl;

  REP(i,q){
    
  }




  //
  // REP(i,q){
  //   int x;
  //   cin >> x;
  //   auto Iter = lower_bound(ALL(a),x) - a.begin();
  //   cout << Iter << endl;
  //   vector<int> f;
  //   vector<int> b;
  //   REP(i,Iter) f.push_back(a[i]);
  //   REP2(i,Iter,n) b.push_back(a[i]);
  //   for(auto x: f) cout <<"f" <<  x << endl;
  //   for(auto x: b) cout <<"b" << x << endl;
  //   ll ans = 0;
  //   REP(i,n){
  //
  //     ans += *f.back(); f.pop();
  //
  //
  //   }
  //
  //
  //
  //
  //   // f = (a.begin(), a.begin()+Iter);
  //   // b = (a.begin()+Iter+1, a.end());
  // //for(auto x: f) cout << x << endl;
  //
  // }
  return 0;
}
