#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i <(n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  //以下の２行を追加すると入出力が高速化する．理由は不明， なくても可
  //ただしprintf, scanfのほうが早いらしい
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //------------------------
  int n;
  cin >> n;
  vector<int> boss_num(n-1);
  vector<int> buka_num(n+1); //初期化

  rep(i, n-1) cin >> boss_num.at(i);
  rep(i,n-1){
    buka_num.at(boss_num.at(i))++;
  }

 for (int i = 1; i < n + 1 ; ++i){
   cout << buka_num.at(i) << endl;
 }
  //TLE
  // rep(i, n){
  //   cout << count(all(boss_num), i+1) << endl;
  // }

}
