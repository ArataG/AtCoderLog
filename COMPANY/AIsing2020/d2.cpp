#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

//------------------------
//popcountは２パターンしか存在しない．
//つまり，もとのpopcount ± 1
//sそれぞれのパターンでまとめてけいさん
//また． bitを反転させたものの数値は，元の数字からいくら変わったかを考える．
//再帰関数

int pcnt(int x){
  return __builtin_popcount(x);
  //２進数にしたときにbitが立っているところの数を返す
  //long long のときは
  // __builtin_popcountll(x)
}

int f(int x){
  if(x == 0) return 0;
  return f(x%pcnt(x))+1;
}

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> x(n);//桁ごとのintのvectorに直しておく．
  REP(i,n) x[i] = s[i] - '0'; //char >> int;

  int pc = 0; //もとの数字のpopcount (bitが立っている数)
  REP(i,n) pc += x[i];  //popcountの数え上げ

  vector<int> ans(n);
  REP(b,2) {
    int npc = pc;
    if(b == 0) ++npc;
    else --npc;

    //npc = 0 のときの例外処理
    if(npc <= 0) continue;

    //
    int r0 = 0;   //もとの数字の割ったあまり
    //2進数を１０進数に変換し，npcで割っている．割り算のあまりはいつ計算しても一緒
    REP(i,n){
      r0 = (r0*2)%npc;
      r0 += x[i];
    }

    int k = 1;
    //ループを下から回す
    for (int i = n-1; i >= 0; --i){

      //r : フリップさせた数をpopcount でわったあまり
      if(x[i] == b){
        int r = r0;
        if(b == 0) r = (r+k)%npc;
        else r = (r-k+npc)%npc; //(r-k) < 0 を防ぐために，r-k+npc;
        ans[i] = f(r) + 1;
      }

      k = (k*2)%npc;  //2^n
    }

  }

  REP(i,n) cout << ans[i] << endl;
  return 0;
}
