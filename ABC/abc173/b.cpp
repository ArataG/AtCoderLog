#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



//連想配列を利用する

int main (){
  int n;
  cin >> n;
  map<string, int> mp;
  REP(i,n){
    string s;
    cin >> s;
    mp[s]++;
  }


  cout << "AC" << " x " << mp["AC"]<< endl;
  cout << "WA" << " x " << mp["WA"] << endl;
  cout << "TLE" << " x " << mp["TLE"] << endl;
  cout << "RE" << " x " << mp["RE"] << endl;

  //c++ mapは， 存在しないキーは　０　で返されるので


  return 0;

}

// if文でべったり書く場合
// 
// int main(){
//   int n;
//   cin >> n;
//   int ac, wa, tle, re;
//   ac = 0;
//   wa = 0;
//   tle = 0;
//   re = 0;
//
//   REP(i,n){
//     string s;
//     cin >> s;
//     if(s == "AC") ++ac;
//     if(s == "WA") ++wa;
//     if(s == "TLE") ++tle;
//     if(s == "RE") ++re;
//   }
//   cout << "AC" << " x " << ac << endl;
//   cout << "WA" << " x " << wa << endl;
//   cout << "TLE" << " x " << tle << endl;
//   cout << "RE" << " x " << re << endl;
//
//
//   return 0;
// }
