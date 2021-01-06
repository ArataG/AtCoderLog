#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


//-------------------------
//再帰関数を使う
//------------------------
string f(ll n){
  if(n == 0) return "";
  n--;
  return(f(n/26)) + string(1, 'a' + n %26);
}

int main() {
  ll n;
  //string al = "abcdefghijklmnopqrstuvwxyz";
  cin >> n;
  cout << f(n) << endl;
  return 0;
}




//   vector<int> rname();
//
//   int cnt = 0;
//
//   REP(i,12){
//     rname[i] = al[n%26];
//     n /= 26;
//     if(n == 0) {
//       cnt = i;
//       break;
//     }
//   }
//
//   for(int i = cnt; i >= 0; --i){
//     cout << rname[i] << endl;
//   }
//   return 0;
// }
  //cout<< al[n/26] << endl;

  // for(int i = 12; i > 0 ; i--){
  //   ll x = pow(26, i);
  //
  //   if(n/x == 0) continue;
  //   if(n/x == 1 && n%x == 26*(i-1)) {
  //     cout << 'z' << endl;
  //     n -= (n/x) * x;
  //     continue;
  //   }
  //   cout << al[n/x];
  //   n -= (n/x) * x;
  // }
  // cout<< al[n] << endl;
  // return 0;
