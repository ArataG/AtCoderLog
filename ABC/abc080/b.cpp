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
  int a = n;
  int f = 0;
  REP(i,9){
    int div = 1;
    REP(j,8-i) div *= 10;
    f += a/div;
    a %= div;
  }
  //cout << f << endl;


  if(n%f == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
