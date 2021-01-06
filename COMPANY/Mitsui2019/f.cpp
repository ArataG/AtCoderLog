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
  int t1, t2;
  ll a1, a2;
  ll b1, b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

  ll A1 = a1 * t1;
  ll A2 = A1 + a2 * t2;
  ll B1 = b1 * t1;
  ll B2 = B1+ b2 * t2;

  if(A2 == B2){
    cout << "infinity" << endl;
    return 0;
  }

  //A1 > B1にセットしておく
  if(A2 < B2){
    swap(A1,B1);
    swap(A2,B2);
  }

  ll d = A2 - B2;
  ll c = B1 - A1;

  ll ans = 0;

  if (c > 0){
    ans = (c-1)/d +1;
    ans *= 2;
    if(c%d != 0) --ans;
  }
  else{
    ans = 0;
  }

  cout << ans << endl;


  return 0;
}
/*

ダイアグラム書くと楽．二次元のグラフ
解答を参照
https://img.atcoder.jp/sumitrust2019/editorial.pdf

A1 = a1 * t1
A2 = a2 * t2
A1 = b1 * t1
A2 = b2 * t2

- A1 + A2 = B1 + B2:INF

- A1 > B1 : 0

- A1 < B1 :
  C = (B1-A1)
  D = (A1 + A2) - (B1 + B2)
  とする．
  ans = C/D * 2 -1

  if(C%D == 0) ans = C/D * 2

  ** 丁度接して終わるときは　１回しか交差しないので注意する．

*/
