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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  //0
  if(a == c && b == d) {
    cout << 0 << endl;
    return 0;
  }
  
  //1
  if(a+b == c+d || a-b == c-d){
    cout << 1 << endl;
    return 0;
  }

  if(abs(a-c)+abs(b-d) <= 3){
    cout << 1 << endl;
    return 0;
  }

  //2
  //int cnt = 0;
    //cout << cnt << endl;
  //
  // if(a%2 == c%2 && b%2 == d%2){
  //   cout << 2 << endl;
  //   return 0;
  // }
  if((a+b)%2 == (c+d)%2){
    cout << 2 << endl;
    return 0;
  }

  REP2(i,-3,4){
    REP2(j,-3,4){
      //if(i == 0 && j == 0) continue;
      if((abs(i)+abs(j) <= 3) || (abs(i) == 2 && abs(j) == 2)){
        //cout << i << " " << j << endl;
        if(a+b == (ll)c+i+d+j || a-b == (ll)(c+i)-(d+j)) {
          cout << 2 << endl;
          return 0;
       }

      }

    }
  }



  cout << 3 << endl;
  return 0;

}
