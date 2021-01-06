#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

//計算量をへらすために，累積和の利用，収束する値の見積もり
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  REP(i, n) cin >> a[i];

  REP(ki,k){
    vector<int> b(n+1);
    REP(i,n){
      //ライトがテラス範囲の始点に；＋１　終点に−１　後で累積和
      int first = max(0            , i - a[i]);
      int last  = min(i  + a[i] + 1, n       );
      b[first]++;
      b[last]--;
    }
    REP(i,n) b[i+1] += b[i]; //累積和
    b.pop_back();               //n+1番目の配列削除

    //収束する点, ステップ数抑えられる
    if(a == b) break;
    a = b;

  }

  REP(i, n) cout << a[i] << endl;
  return 0;


}
