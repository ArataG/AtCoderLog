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
  cin >> H >> W;
  vector<string> s(H);
  REP(h,H) cin >> s[h];

  int cnt = 0;
  REP(h,H){
    REP(w,W-1){
      if(s[h][w] == '.' && s[h][w+1] == '.') cnt++; 
    }
  }

  REP(w,W){
    REP(h,H-1){
      if(s[h][w] == '.' && s[h+1][w] == '.') cnt++;
    }
  }

  cout << cnt << endl;
  
  return 0;
}