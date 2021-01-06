#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

//----------------------------------//
// 1-100 までのループを回して計算した
// if文だけで解くならば．
//f(x) = 1 から x のdの倍数の個数とすると
//f(x) = x/d;
//ans = f(R) - f(L-1);
//
//こちらのほうが，制約が大きくなっても得ことができる．
//
//----------------------------------//



int main(){
  int l, r, d;
  cin >> l >> r >> d;
  int cnt = 0;
  REP2(i,l,r+1){
    if(i%d == 0) ++cnt;
  }

  cout << cnt << endl;
  return 0;
}
