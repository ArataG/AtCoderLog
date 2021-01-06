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
  find(x); 各連結成分の代表を取得
  unite(x,y); 要素xと要素yを連結する
  same(x,y);  連結しているかを返す
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

vector<ll> to[200005];

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  vector<int> b(n);

  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  //
  UnionFind uF(n);
  REP(i,m){
    int c, d;
    cin >> c >> d;
    --c; --d;
    uF.unite(c, d);
  }

  REP(i,n){
    int x = uF.find(i);
    to[x].push_back(i);
  }

  REP(i, n){
    ll asum = 0;
    ll bsum = 0;
    if(to[i].size() == 0) continue;
    REP(j, to[i].size()){
      asum += (ll)a[to[i][j]];
      bsum += (ll)b[to[i][j]];
    }
    if(asum != bsum ) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}

/*
  連結ではないグラフ
  連結成分ごとに見るとそれぞれ独立している
  
  連結成分全体の和は常に等しい

  連結成分に分解　>> unionFind


*/



//      asum += a[num];
//      bsum += b[num];
//   }
//   if(asum != bsum ) {
//     cout << "No" << endl;
//     return 0;
//   }
// bool ok = true;
// vector<bool> seen(n,false); 
// REP(j,n){
//   if(seen[j]) continue;
//   vector<int> uflist;
//   uflist.push_back(j);
//   seen[j] = true;
//   int size = uF.size(j);
  
//   REP2(i, j+1, n){
//     if(size == 1) break;
//     if(uF.same(j, i)){
//       uflist.push_back(i);
//       seen[i] = true;
//       //
//       size--;
//       if(size == 0) break;
//     }
//   }
//   // REP(i,uflist.size()) cout << uflist[i] << " " ;
//   // cout << endl;
//   //check
//   ll asum = 0;
//   ll bsum = 0;
//   REP(i,uflist.size()){
//      ll num = uflist[i];
//      asum += a[num];
//      bsum += b[num];
//   }
//   if(asum != bsum ) {
//     cout << "No" << endl;
//     return 0;
//   }
// }

// cout << "Yes" << endl;


