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
  vector<int> p(n);
  REP(i,n) cin >> p[i];
  map<int, bool> mp;
  int min = 0;

  REP(i,n){
    mp[p[i]] = true;
    if(min < p[i]){
      cout << min << endl;
      continue;
    }
    else{
      int pos = min;
      while(1){
        if(mp[pos] == false){
          min = pos;
          cout << min << endl;
          break;
        }
        else {
          pos++;
        }
      }
    }
  }

  return 0;

}

/*
mex
数列に含まれない数値の中で最小のもの．
ならしで見るとオーダー１
全体の計算量はオーダーN
*/