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
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  
  if(a == b) return x;

  if(a < b ){
    //廊下のみ
    int ans = 0;
    ans = ((b - a) * 2 + 1) * x;
    //廊下と階段
    ans = min(ans, (b-a)* y + x);
    return ans;
  }

  if(a > b ){
    //廊下のみ
    int ans = 0;
    ans = ((a - b) * 2 - 1) * x;
    //廊下と階段
    ans = min(ans, (a - b -1)* y + x);
    return ans;
  }
  return -1;
}

int main(){
  cout << solve() << endl;
  return 0;
}
