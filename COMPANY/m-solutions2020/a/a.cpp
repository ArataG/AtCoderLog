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
  int x;
  cin >> x;

  if( x < 600) {
    cout << 8 << endl;
    return 0;
  }

  if( x < 800) {
    cout << 7 << endl;
    return 0;
  }

  if( x < 1000) {
    cout << 6 << endl;
    return 0;
  }

  if( x < 1200) {
    cout << 5 << endl;
    return 0;
  }
  if( x < 1400) {
    cout << 4 << endl;
    return 0;
  }

  if( x < 1600) {
    cout << 3 << endl;
    return 0;
  }

  if( x < 1800) {
    cout << 2 << endl;
    return 0;
  }

  if( x < 2000) {
    cout << 1 << endl;
    return 0;
  }

  return 0;
}
