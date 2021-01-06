#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


//=====================
//貪欲法
//次の状態の値を最適にすることだけを考える
//値が小さいと次の値も小さくできるので
//=====================



int main(){
  int n, k;
  cin >> n >> k;
  int x = 1;
  REP(i,n){
    int xa = x * 2;
    int xb = x + k;
    x = min(xa,xb);
  }

  cout << x << endl;
  return 0;
}
