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
  貪欲法で，条件式を満たす最小の回数を調べる，
  kと値を比較としてもよい．

  自分は全探索でといた．

*/

int main(){
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  REP(m,k){
    int bx = b;
    int cx = c;

    REP(i,m){
      bx *= 2;
    }
    REP2(i,m,k){
      cx *= 2;
    }

    //cout << m << " "<< bx << " " << cx << endl;

    if(a < bx && bx < cx){
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;

}
