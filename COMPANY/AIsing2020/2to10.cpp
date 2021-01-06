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
  int n;
  cin >> n; //桁数
  string s; //2進数文字列
  cin >> s;

  /*
  2進数の文字列をint型の配列に変換
  */
  vector<int> x(n);
  REP(i,n) x[i] = s[i] - '0';


  /*
  2進数int型から１０進数に変換；
  左から計算できる．
  1101

  ケタが一つ増えると ×２ する
  ケタが　１　なら　＋１　する

  1 >> 3 >> 6 >> 13;
  左からｎ桁目までを10進数変換したときの値になる
  */
  int r = 0;
  REP(i,n){
    r = r*2;
    r += x[i];
  }

  cout << r << endl;

  return 0;
}
