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
  int n;
  cin >> n;
  vector<ll> a(n);
  REP(i,n) cin >> a[i];

  sort(RALL(a));



  if(n == 2){
    cout << a[0] << endl;
    return 0;
  }

  ll sum = 0;
  int ai = 1;

    sum = a[0];
    for(int i = 1; i < n-1; ++i){
      if(i%2 ==1) sum += (ll)a[ai];
      else{
        sum += (ll)a[ai];
        ++ai;
      }
    }

  cout << sum << endl;

  return 0;
}
