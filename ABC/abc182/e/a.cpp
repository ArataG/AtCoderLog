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
  vector<int> a(n);
  vector<int> b(n);
  //vector<int> c(n), d(n);
  REP(i,n) {
    cin >> a[i] >> b[i];
  }
  
  bool seen[H+1][W+1];
  REP(h,H+1)REP(w,W+1) {
    seen[h][w] = false;
  }

  REP(i,m){
    int c, d;
    cin >> c >> d;
    --c; --d;
    seen[c][d] = true;
  }

  REP(h,H){
    REP(w,W){
      if(seen[h][w])cout << "#" ;
      else cout << "o" ;
    }
    cout << endl;
  }

  int ans = 0;

  REP(i,n){
    int ai = a[i]-1;
    int bi = b[i]-1;

    if(seen[ai][bi]) continue;
    seen[ai][bi] = true;
    ans++;
    //右
    for(int h = ai+1; h < H; h++){
      if(seen[h][bi]) break;
      seen[h][bi] = true;
      ans++;
    }

    //右
    for(int h = ai - 1 ; h >= 0; h--){
      if(seen[h][bi]) break;
      seen[h][bi] = true;
      ans++;
    }

    //右
    for(int w = bi + 1 ; w < W; w++){
      if(seen[ai][w]) break;
      seen[ai][w] = true;
      ans++;
    }
    for(int w = bi - 1 ; w >= 0; w--){
      if(seen[ai][w]) break;
      seen[ai][w] = true;
      ans++;
    }

  //   //
    cout<< "m: " << i << endl;
    REP(h,H){
    REP(w,W){
      if(seen[h][w])cout << "#" ;
      else cout << "o" ;
    }
    cout << endl;
  }
  }

  cout << ans << endl;

  return 0;
}