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
  
  int H,W;
  cin >> H >> W;

  vector<string> s(H);

  REP(h,H) cin >> s[h];

 //REP(h,H) cout << s[h] << endl;
 ll a[H][W];
 REP(h,H)REP(w,W) a[h][w] = 0;


 ll sumH = 1;
 ll sumW = 0;
 a[0][0] = 1;
 //h = 0;
int sum = 1; 
REP2(w,1,W){
   a[0][w] = sum;
   sum += a[0][w]; 
}

 //???
 REP2(h,1,H){
    a[h][0] = sumH;
    sumW = sumH;
    sumH += a[h][0];
    REP2(w,1,W){
      //?
      a[h][w] = sumW;
      //?
      a[h][w] += a[h-1][w];
      //?

      sumW += a[h][w];
 }
}

  REP(h,H){
    REP(w,W){
      cout << a[h][w] << " ";
    } 
    cout << endl;
  }
  // vector<int> a(W);
  // a[0] = 1;
  // int sum = 1;
  // REP2(w,1,W){
  //   a[w] = sum;
  //   sum += a[w];
  // }

  // debug(a);

  return 0;
}