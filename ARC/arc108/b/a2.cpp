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
  int n;
  cin >> n;
  string s;
  cin >> s;

  string t;

  REP(i,n){
    t += s[i];
    int it = t.size();
    if(it < 3) continue;
    //if(t[it-1] == 'x' && t[it-2]=='o' && t[it-3] == 'f'){
    if(t.substr(t.size() - 3) == "fox"){
      REP( _, 3) t.pop_back();
    }
  }

  int ans = t.size();

  cout << ans << endl;
  
  return 0;
}