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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> b(300005,0);
  REP(i,n){
    b[a[i]]++;
  }

  
  vector<int> ans;

  bool ok = true;
  while(ok){
    if(b[0] == 0) break;
    b[0]--;

    REP2(i,1,300005){
    if(b[i] == 0) {
      ans.push_back(i);
      break;
    }
    b[i]--;
    }
  }

  debug(ans);

  ll res = 0;

  REP(i,k){
    if(i >= ans.size()) continue;
    res += (ll)ans[i];
  }

  cout << res << endl;
  return 0;
}