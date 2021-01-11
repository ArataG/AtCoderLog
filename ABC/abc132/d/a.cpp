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


static const ll mod = INF;

vector<vector<ll>> comb(int n, int r) {
  vector<vector<ll>> v(n + 1,vector<ll>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
      v[j][k] %= mod;
    }
  }
  debug(v);
  return v;
}


int main(){
  //#define int long long
  //input
  int n, k;
  cin >> n >> k;
  vector<int> ans(k+1,0);

  //前処理
  vector<vector<ll>> c = comb(n+1,k+1);
  
  //赤丸に区切りを入れる位置の場合の数
  //for i 1..k  comb(n-k+1, i)
  REP2(i,1,k+1){
    ans[i] += c[n-k+1][i];
  }

  //青丸をどのように配置するかの場合の数
  //ooo の間は2つなのでk-1
  REP2(i,1,k+1){
    ans[i] *= c[k-1][i-1];
  } 

  //output
  REP2(i,1,k+1) cout << ans[i] << endl;
  return 0;
}