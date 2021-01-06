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

  REP(i, 50000){
    double ans = 1;
    ans = i * 1.08;
    //少数だと誤差が出る可能性があるので， x100 して計算したほうがいい．
    //ans = i * 108 / 100
    ans = (int)ans;
    if(n == ans){
      cout << i << endl;
      return 0;
    }
  }

  cout << ":(" << endl;
  return 0;
}
