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
#define REP(i,n) for (int i = 0; i <(n); ++i)

int main(){
  int a, b, c;
  //  a = 1;
  //  b = 2;
  //  c = 3;
  cin >> a >> b >> c;
  a +=b;
  if(a < c && c < b) cout << "Yes" << endl;
  else if(c < a && b < c) cout << "Yes" << endl;
  else cout << "N" << endl;

  return 0;

}
