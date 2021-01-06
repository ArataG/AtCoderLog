#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int hp_taka, at_taka;
  int hp_aoki, at_aoki;
  cin >> hp_taka >> at_taka >> hp_aoki >> at_aoki;


  while(hp_taka > 0 || hp_aoki > 0){

    hp_aoki -= at_taka;

    if(hp_aoki <= 0){
      cout << "Yes" << endl;
      break;
    }

    hp_taka -= at_aoki;

    if(hp_taka <= 0){
      cout << "No" << endl;
      break;
    }

  }

  //別の回答
  int num_taka = (hp_aoki + at_taka - 1) / at_taka;
  int num_aoki = (hp_taka + at_aoki - 1) / at_aoki;
  //割り切れないときに攻撃回数を＋１するための計算式
  // EX：hp_aoki = 11, at_taka = 2
  // のとき，攻撃回数は，６になる

  if (num_taka > num_aoki) cout << "Yes" << endl;
  else cout << "No" << endl;


  return 0;
}
