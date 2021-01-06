#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<ll> iwasi(n);

  REP(i,n){
    ll a, b;
    cin >> a >> b;
    iwasi[i] = a*b;
  }

  REP(i,n) cout << iwasi[i] << endl;

  return 0;
}
