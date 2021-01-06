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
  int n, m;
  cin >> n >> m;
  vector<int> child(n);
  REP(i,n) child[i] = 0;
  REP(i,m){
    int a;
    cin >> a;
    REP(j, n){
      if( a > child[i] ) {
        child[i] = a;
        cout << j + 1 << endl;
        continue;
      }
      else( )
    }
    //else cout << -1 << endl;
  }
  return 0;
}
