#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main() {

  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  REP(i,h) cin >> s[i];
  int ans = 0;

  //---------------------------//
//   REP(is, 1 << h)
//   仮に，h = 3のとき，このループは 0 to 111までの２進数のループになる．
//   この理由は，1 << h は１を左に３回シフトする，つまり，1000．
//   1000-1 = 111 (２進数表記)のため
//
// //各ケタの処理を書く
//   REP(i,h){
//     if(is >> j&1){//最下位ビットが１ならtrue ０ならfalse
//
//     }
//   }

//本問題では，グリッドなので二重のbit全探索
//---------------------------//


  REP(is, 1 << h){
    REP(js, 1 << w){
      int cnt = 0;

      REP(i,h)REP(j,w){
        //消される行，列は飛ばす．
        if(is >> i&1) continue;
        if(js >> j&1) continue;

        //消されていない行の＃のマスをカウント
        if(s[i][j] == '#') ++cnt;
      }

      if(cnt == k) ++ans;

    }
  }

  cout << ans << endl;

  return 0;
}
