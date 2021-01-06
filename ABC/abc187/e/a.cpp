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

using Graph = vector<vector<int>>;
int N, Q;
Graph G;

void dfs(int v, int p, vector<long long> &res, int b) {
  if (p != -1) res[v] += res[p];
  for (auto e : G[v]) {
    if (e == p) continue;
    if (e == b) continue;
    dfs(e, v, res, b);
  }
}

int main(){
  int n;
  cin >> n;
  G.assign(n, vector<int>());
  vector<pair<int, int>> edge(n-1);
  REP(i,n-1){
    int a, b;
    cin >> a >> b;
    --a; --b;
    edge[i].first = a;
    edge[i].second = b;
    
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<ll> val(n,0);
  int q;
  cin >> q;

  for(auto i: {0,2,1,3}){
    int t, e, x;
    cin >> t >> e >> x;
    --e;
    
    int a = edge[e].first;
    int b = edge[e].second;
    if(t == 2 ) swap(a,b); 
    val[a] += x;
    dfs(a, -1, val, b);
  }

  for (auto v : val) cout << v << endl;
  cout << endl;

  return 0;
}