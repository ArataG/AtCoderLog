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
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

ll INFL = 1e18 + 7;

int main(){
  ll n;
  cin >> n;
  ll a, b;
  vector<pair<int,ll>> b5(30);
  vector<pair<int,ll>> a3(100);
  ll bcnt = 1;
  REP2(i,1,30){
    bcnt *= 5;
    b5[i].first= i;
    b5[i].second = bcnt;
    
    if(bcnt > INFL/5) break;
  }
  //REP(i,b5.size()) cout << b5[i].first << " " <<b5[i].second << endl;

 ll acnt = 1;
 REP2(i,1,50){
    acnt *= 3;
    a3[i].first= i;
    a3[i].second = acnt;
    
    if(acnt > INFL/3) break; 
 } 


 REP2(i,1, a3.size()){
   if(a3[i].second == 0) continue;
   REP2(j,1, b5.size()){
     if(b5[j].second == 0) continue;
     if( n == a3[i].second + b5[j].second) {
       cout << i << " " << j << endl;
       return 0;
     }
   }
 }

 cout << -1 << endl;

  return 0;
}