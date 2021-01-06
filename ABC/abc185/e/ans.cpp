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

template<class T>
void chmin(T& a, const T& b){ a = min(a,b);}

const int NMAX = 1005;
int dp[NMAX][NMAX];

int main(){
  //#define int long long
    int n, m;
  cin >> n >> m;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<int> b(m);
  REP(i,m) cin >> b[i];
  
  REP(i, NMAX)REP(j,NMAX) dp[i][j] = INF;

  dp[0][0] = 0;
  REP(i, n+1)REP(j,m+1){
    if(i < n) chmin(dp[i+1][j], dp[i][j]+1);
    if(j < m) chmin(dp[i][j+1], dp[i][j]+1);
    if(i < n && j < m) {
      int cost = 0;
      if(a[i] != b[j]) cost = 1;
      chmin(dp[i+1][j+1], dp[i][j]+cost);
    }
  }

  cout << dp[n][m] << endl;
  return 0;
}


/*
  編集距離という典型問題に含まれるらしい

*/