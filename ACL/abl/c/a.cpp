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


/*
  UnionFind
*/
struct UnionFind {
vector<int> d;
UnionFind(int n = 0): d(n,-1) {}
int find(int x) {
  if (d[x] < 0) return x;
  return d[x] = find(d[x]);   //経路縮尺(メモ化再帰)
}
bool unite(int x, int y) {  //連結する
  x = find(x); y = find(y);
  if (x == y) return false;
  if (d[x] > d[y]) swap(x,y); //根の高さが小さい方に連結する
  d[x] += d[y];
  d[y] = x;
  return true;
}
bool same(int x, int y) { return find(x) == find(y);} //連結しているかを返す
int size(int x) { return -d[find(x)];}  //連結成分サイズを返す
};

int deg[100005];//直接接続している友人数のリスト
vector<int> to[100005]; //ブロック関係の連結リスト


int main(){
  int n, m;
  cin >> n >> m;
  UnionFind uF(n);

  REP(i,m){
    int a, b;
    cin >> a >> b;
    --a; --b;
    uF.unite(a,b);
  }
 
  int ans = 0;
  REP(i,n-1){
    if(uF.same(i,i+1)) continue;
    ans++;
    uF.unite(i,i+1);
  }

  cout << ans << endl;
  
  return 0;
}