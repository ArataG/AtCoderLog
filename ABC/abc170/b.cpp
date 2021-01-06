#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){

  int x, y; //総数　足の数
  cin >> x >> y;

  int turu, kame;
  // if(x == 1){
  //   if(2*)
  // }

  REP(i,x+1){
    turu = i;
    kame = x - i;
    if(turu*2+kame*4 == y){
      cout << "Yes" << endl;
      return 0;
    }

  }

  cout << "No" << endl;

  return 0;
}
