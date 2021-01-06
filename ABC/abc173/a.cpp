#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


int main () {
  int n;
  cin >> n;
  int num = (n + (1000-1))/1000; //切り上げ求める

  //割り切れるときだけ例外処理しても良い．
  // int num = n/1000;
  // if (n % 1000 != 0) ++num;

  int ans = num * 1000 - n;
  cout << ans << endl;
  return 0;
}

// int main(){
//   int n;
//   cin >> n;
//   int ans = 0;
//
//   REP(i,1000){
//     n -= 1000;
//     if(n <= 0) break;
//
//   }
//
//   ans = abs (n);
//
//   cout << ans << endl;
//
//
//   return 0;
//
// }
