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

// int f2(){

// }


int main(){
  //#define int long long
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<int> sum(n+1);
  sum[0] = 0;
  int s = 0;
  REP(i,n){
    s ^= a[i];
    sum[i+1] = s;
  }

  debug(sum);

  //cout << (sum[3]^sum[0]) << endl;

  REP(i, q){
    int t, x, y;
    cin >> t >> x >> y;

    if(t == 1){
       REP2(j,x,n+1) sum[j]^a[x-1];
       debug(sum);
       REP2(j,x,n+1) sum[j]^y;
       a[x-1] = y;
       debug(a);
       debug(sum);
    }
    else if(t == 2){
      --x;
      cout << (sum[y]^sum[x]) << endl; 
    }
  }

  
  return 0;
}