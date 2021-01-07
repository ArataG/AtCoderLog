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

int n;
vector<vector<int>> to;
vector<int> a;
vector<int> b;
vector<int> depth;

vector<ll> dp;

//DFSで深さを求める(根つき木として扱いたい.)
void depthDFS(int v, int d){
  depth[v] = d;
  for(auto next: to[v]){
    if(depth[next] == -1){
      depthDFS(next, d+1);
    }
  }
}

void imosDFS(int v, ll now){
  now += dp[v];
  dp[v] = now;
  for(auto next: to[v]){
    if(depth[next] > depth[v] ){
      imosDFS(next, now);
    }
  }
}

int main(){
  //#define int long long
  cin >> n;
  to.resize(n);
  dp.resize(n);
  depth = vector<int>(n,-1);

  REP(i,n-1){
    int ax, bx;
    cin >> ax >> bx;
    --ax; --bx;
    a.push_back(ax);
    b.push_back(bx);
    to[ax].push_back(bx);
    to[bx].push_back(ax);
  } 

  depthDFS(0,0); //0をrootとして扱う
  debug(depth);

  int q;
  cin >> q;
  REP(i, q){
    int t, e, x;
    cin >> t >> e >> x;
    --e;
    int va, vb;
    va = a[e];
    vb = b[e];
    if(t == 2) swap(va, vb);

    //通る方が根の上の場合, 全体に足して部分木をマイナスにする.
    if(depth[va] < depth[vb]){
      dp[0] += x; //rootに足す
      dp[vb] -= x; //部分木を減算する
    }
    else{
      dp[va] += x;
    }
  }

  //木に対する累積和
  imosDFS(0,0);

  REP(i,n){
    cout << dp[i] << endl;
  }
  return 0;
}