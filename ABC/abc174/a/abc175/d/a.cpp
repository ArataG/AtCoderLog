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
#define REP(i,n) for (int i = 0; i <(n); ++i)
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }


int main(){
  int n, k;
  cin >> n >> k;
  vector<pair<int,int>> p(n);
  vector<int> c(n);
  REP(i,n){
    int px;
    cin >> px;
    px--;
    p[i].first = px;
    p[i].second = 0;
  }
  REP(i,n) cin >> c[i];

  

  int now = 0;
  REP(i,n){
    vector<int> roop;
    if(p[i].second != 0) continue;
    debug(i);
    now = i;
    while(1){
      int next = p[now].first;
      if(p[next].second == 2) break;
      else p[next].second++;  //探索済み
      
      roop.push_back(c[next]);  
      now = p[now].first;
    }
    for(auto x: roop) cout << x << endl;
    cout << endl;
    //
    int len = roop.size();
    vector<ll> sum(len);
    ll s = 0;
    REP2(j,0,len){
      s += roop[j];
      sum[j] += s;
    }

    // k < len
    REP(j, len){

      while(left - right <= k )
    }


    //MAXの候補
    if(s > 0){
      ll adroop = s/2;
      ll ans = adroop * (k/len);
      int rest = k % len;
      
    }

    if(s < 0){
      ll mxsum = -1000000100;
      REP(j,len - 1){
        REP2(k,j+1,len){
          mxsum = max(mxsum, sum[k] - sum[j]); 
        }      
      }
    }


  }

  return 0;
}