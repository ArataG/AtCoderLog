#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define DREP(i,n) for (int i = (n-1); i >=0; --i)
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
template<typename T1, typename T2> void view(pair<T1,T2> e) { cout << "("<< e.first << ", " << e.second <<")"  << endl;}
template<typename T1, typename T2> void view(const vector<pair<T1,T2>>& v) {for(const auto& e: v){view(e);}}
// end debug


int main(){
  //#define int long long
  int n, m;
  cin >> n >> m;
  vector<int> a;
  a.push_back(0);
  REP(i,m){
    int ax;
    cin >> ax;
    a.push_back(ax);
  }
  a.push_back(n+1);
  sort(ALL(a));
  debug(a);


  int k = INF;
  REP(i,m+1){
    if(a[i+1]-a[i] - 1 == 0) continue;
    k = min(k,a[i+1] - a[i]-1);
  }

  ll cnt = 0;

  debug(k);
    REP(i,m+1){
    if(a[i+1]-a[i] -1 == 0) continue;
    cnt += ((ll)a[i+1] - a[i] -1 + (k-1))/k;
  }

  cout << cnt << endl;
  return 0;
}


/*

- ハンコの大きさkのminは, 連続する白色のマスが最も短い場所(ただし0を除く)なので,
  - min(a[i+1] - a[i] - 1) (a[i+1] - a[i] -1 != 0)
  - a[i]の番兵として, 最初にa[0] = 0, 最後にa[m+1] = n+1を追加しとくと実装が楽 

- 各白色の領域のマスでハンコを押す回数は, 幅/ハンコのサイズkの切り上げになるので.

```cpp
cnt += ((ll)a[i+1] - a[i] -1 + (k-1))/k;
```
先にa[i+1] - a[i] -1の配列作ったほうがスッキリかけそう.

*/