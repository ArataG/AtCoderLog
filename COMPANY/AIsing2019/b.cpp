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
  int a, b;
  cin >> n >> a >> b;
  int ca = 0;
  int cb = 0;
  int cc = 0;
  REP(i,n){
    int p;
    cin >> p;
    if(p <= a ) ++ca;
    else if(p > b) ++ cc;
    else ++ cb;
  }

  int ans = min({ca,cb,cc});
  cout << ans << endl;
  return 0;
}
