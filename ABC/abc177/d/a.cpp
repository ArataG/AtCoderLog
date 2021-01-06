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

struct UnionFind {
vector<int> d;
UnionFind(int n=0): d(n,-1) {}
int find(int x) {
  if (d[x] < 0) return x;
  return d[x] = find(d[x]);
}
bool unite(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return false;
  if (d[x] > d[y]) swap(x,y);
  d[x] += d[y];
  d[y] = x;
  return true;
}
bool same(int x, int y) { return find(x) == find(y);}
int size(int x) { return -d[find(x)];}
};

int main(){
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  REP(i,m){
    int a, b;
    cin >> a >> b;
    --a, --b;
    uf.unite(a,b);
  }  

  int minx = 0;
  REP(i,n){
    minx = max(uf.size(i),minx);
  }

  cout << minx << endl;

  return 0;
}