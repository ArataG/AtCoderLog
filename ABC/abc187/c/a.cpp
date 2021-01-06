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
  vector<string> s;
  vector<string> t;
  REP(i,n){
    string x;
    cin >> x;
    if(x[0] != '!') t.push_back(x);
    else{
      string y;
      REP2(i,1,x.size()){
        y += x[i];
      }
      s.push_back(y);
    }
  }
  
  sort(ALL(s));
  sort(ALL(t));
  

  REP(i, t.size()){
   if(binary_search(ALL(s), t[i])){
      cout << t[i] << endl;
      return 0;
   }
  }
  
  debug(s);
  debug(t);

  cout << "satisfiable" << endl;

  return 0;
}