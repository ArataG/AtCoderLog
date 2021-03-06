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

int f1(int k){
  int res = k*k*k;
  return res;
}

int f2(int k, int n){
  int res = k * k * k - 3 * (k-n)*(k-n)*(k-n);
  return res;
}

int f3(int k, int n){
  int res = 6 * n * n * n - (3*n-k)*(3*n-k)*(3*n-k);
  return res;
}

int f4(int n){
  int res = 6 * n * n * n;
  return res;
}

int main(){
  //#define int long long
  int n, k;
  cin >> n >> k;
  int ans = 0;
  if(k <= n) ans = f1(k);
  else if(k <= 2*n) ans = f2(k,n);
  else if(k <= 3*n) ans = f3(k,n);
  else if (k >= 3*n) ans = f4(n);
  //else ans = f2(n,k);

  cout << ans << endl;
  return 0;
}