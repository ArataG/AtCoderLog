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


int main(){
  //#define int long long
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  vector<pair<char, int>> mv;

  REP(i,n){
    if(i+1 - a[i] == 0) {
      cout << -1 << endl;
      return 0;
    }

    if((i+1) - a[i] < 0) mv.emplace_back('r', abs(i+1-a[i]));
    else mv.emplace_back('l', abs(i+1-a[i])); 
  }

  // REP(i,n){
  //   cout << i << " " << mv[i].first<< " " << mv[i].second << endl;
  // }

 vector<int> ans;
 for(int j = n-1; j >= 1; j--){
   
   REP(i,n){
     if(mv[i].second == j) {
       if(mv[i].first == 'r' && mv[i].first == 'l') {
         mv[i].second--;
         mv[i+1].second--;
         swap(mv[i], mv[i+1]); 
         cout << i+1 << endl;
         //ans.push_back(i+1);
       }
       else if(mv[i].first == 'l' && mv[i-1].first == 'r'){
         mv[i-1].second--;
         mv[i].second--; 
         swap(mv[i-1], mv[i]);
         cout << i << endl;
         //ans.push_back(i);
       }
     }
   }
 } 
  return 0;
}