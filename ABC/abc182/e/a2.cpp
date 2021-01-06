#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }


int main(){
  int H, W;
  int n,m;
  cin >> H >> W;
  cin >> n >> m;
  // vector<int> a(n);
  // vector<int> b(n);
  //vector<int> c(n), d(n);
  bool light[H][W];
  REP(h,H)REP(w,W) {
    light[h][w] = false;
  }
  REP(i,n) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    light[a][b] = true;
  }

  bool block[H][W];
    REP(h,H)REP(w,W) {
    block[h][w] = false;
  }

  REP(i,m){
    int c, d;
    cin >> c >> d;
    --c; --d;
    block[c][d] = true;
  }

  // REP(h,H){
  //   REP(w,W){
  //     if(seen[h][w])cout << "#" ;
  //     else cout << "o" ;
  //   }
  //   cout << endl;
  // }

  bool ans[H][W];
  REP(h,H)REP(w,W) ans[h][w] = false;
  //右
  bool on = false;
  for(int h = 0; h < H; h++){
    for(int w = 0; w < W; w++){
      //block?
      if(block[h][w]) on = false;
      //light?
      if(light[h][w]) on = true;

      if(on) ans[h][w] = true;
    }
    on = false;
  }
  //左
  on = false;
  for(int h = 0; h < H  ; h++){
    for(int w = W-1; w >= 0; w--){
      //block?
      if(block[h][w]) on = false;
      //light?
      if(light[h][w]) on = true;
      if(on) ans[h][w] = true;
    }
    on = false;
  }

  //下
  on = false;
 for(int w = 0; w < W; w++){
  for(int h = 0; h < H; h++){
      //block?
      if(block[h][w]) on = false;
      //light?
      if(light[h][w]) on = true;

      if(on) ans[h][w] = true;
    }
    on = false;
  }

 on = false;
 for(int w = 0; w < W; w++){
  for(int h = H-1; h >= 0 ; h--){
      //block?
      if(block[h][w]) on = false;
      //light?
      if(light[h][w]) on = true;

      if(on) ans[h][w] = true;
    }
    on = false;
  }

  int cnt = 0;
  REP(h,H)REP(w,W){
    if(ans[h][w]) cnt++;
  }

  cout << cnt << endl;
  return 0;
}
