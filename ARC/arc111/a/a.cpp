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
  ll n, m;
  cin >> n >> m;
  vector<int> d(m);
  REP(i,m) d[i] = -1;
  vector<int> a;
  
  ll cnt = 0;
  ll st = 0;
  ll et = 0;

  ll p = 1;
  REP(i,n){
    p *= 10;
    p /= m;
    p %= m;
    cout << p << endl;
    // if(d[p] == -1) {
    //   d[p] = cnt;
    //   a.push_back(p);
    // }
    // else {
    //   st = d[p];
    //   et = cnt;
    //    a.push_back(p);
    //   break;
    // }
    cnt++;
  }
//   debug(a);
//   debug(st);
//   debug(et);

//   ll x = m%(et-st);
//   debug(x);
  
//   cout << a[x] << endl;
//  cout << 1000300090%9997 << endl; 

  // ll ans = p/m;
  // cout << ans << endl;
  // //ans %= m;
  // cout << ans << endl;
  // // vector<int> d;
  // int p = 1;
  // REP(i,n){
  //   p *= 10;
  //   ll dx = p % m;
  //   bool ok = false;
  //   REP(j,d.size()){
  //     if(d[i] == dx){
  //       ok = true;
  //     }
  //   }
  //   if(ok) break;
  //   else d.push_back(dx);
  //   debug(d);
  // }
  // debug(d);

  return 0;
}