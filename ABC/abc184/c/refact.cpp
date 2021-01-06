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
  if(a+b == c+d || a-b == c-d || abs(a-c)+abs(b-d) <= 3){
    cout << 1 << endl;
    return 0;
  }

  //2
  //斜め移動 2
  bool ok_2 = false;
  if((a+b)%2 == (c+d)%2) ok_2 = true;
  //斜め１，縦横1
  for(int i =  -3; i <= 3; i++){
    for(int j = -3; j <= 3; j++){
      //if(i == 0 && j == 0) continue; //既に１で除去しているからいらない．
      if(abs(i)+abs(j) > 3) continue;
      if(a+b == (c+i)+(d+j) || a-b == (c+i)-(d+j)) {
        ok_2 = true;
        break;
      }
    }
  }
  //縦横2
  if(abs(a-c)+abs(b-d) <= 3*2) ok_2 = true;

  if(ok_2) {
    cout << 2 << endl;
    return 0;
  }

//0,1,2以外なら3手
  cout << 3 << endl;
  return 0;
}