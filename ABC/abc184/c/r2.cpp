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

int solve(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = c - a;
  int y = d - b;
  //0
  if(x == 0 && y == 0) return 0;
  //1
  if( x - y == 0 || x + y == 0) return 1;
  if(abs(x)+abs(y) <= 3) return 1;
  //2
  //斜め移動 2
  if((x+y)%2 == 0) return 2;
  //斜め１，縦横1
  for(int i =  -3; i <= 3; i++){
    for(int j = -3; j <= 3; j++){
      if(abs(i)+abs(j) > 3) continue;
      if((x+i) - (y+j) == 0 || (x+i) + (y+j) == 0 ) return 2;
    }
  }
  //縦横2
  if(abs(x)+abs(y) <= 3*2) return 2;
  //3: 0,1,2以外なら3手
  return 3;
}

int main(){
  cout << solve() << endl;
  return 0;
}