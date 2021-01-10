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
  int n;
  cin >> n;
  int len = pow(2,n);
  debug(len);
  vector<vector<int>> a(n);
  vector<pair<int,int>> num(len);
  REP(i,len) {
    int x;
    cin >> x;
    a[0].push_back(x);
    num[i] = make_pair(x, i+1);
  }
  // debug(a[0]);
  //debug(num);

  REP2(i,1, n){
    //cout << "hi"<< endl;
    for(int j = 0; j < len; j += 2){
      int r = a[i-1][j];
      int l = a[i-1][j+1];
      a[i].push_back(max(r,l));
      
    }
    debug(a[i]);
    len /=2;
  }
  int ans = min(a[n-1][0], a[n-1][1]);

  //cout << ans << endl;

  for(auto x: num){
    if(x.first == ans){
      cout << x.second << endl;
      return 0;
    }
  }


  return 0;
}