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

// debug methods
// usage: debug(x,y);
#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,a4,x,...) x
#define debug_1(x1) cout<<#x1<<": "<<x1<<endl
#define debug_2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug_3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl
#define debug_4(x1,x2,x3,x4) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<endl
#define debug_5(x1,x2,x3,x4,x5) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<", "#x4<<": "<<x4<<", "#x5<<": "<<x5<<endl
#ifdef _DEBUG
#define debug(...) CHOOSE((__VA_ARGS__,debug_5,debug_4,debug_3,debug_2,debug_1,~))(__VA_ARGS__)
#else
#define debug(...)
#endif




/*

*/

int main(){
  int n;
  cin >> n;
  //debug(n);
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  debug(n);
  REP(i,n) debug(a[i]);
  vector<int> sell;
  vector<int> buy;
  bool hold = false;

  REP(i,n-1){
    if(hold){
      if(a[i] > a[i+1] ){
        sell.push_back(a[i]);
        hold = false;
      }
    }

    if(!hold){
      if(a[i] < a[i + 1]){
        buy.push_back(a[i]);
        hold = true;
      }
    }
  }

  if(buy.empty()){
    cout << 1000 << endl;
    return 0;
  }

  if(sell.size() != buy.size()){
    sell.push_back(a[n-1]);
  }

  //
  // for(auto x: buy) cout << x << " ";
  // cout << endl;
  //
  // for(auto x: sell) cout << x <<" ";
  // cout <<  endl;



  ll sum = 1000;
  ll nmb = 0;

  REP(i,sell.size()){
    nmb =  sum/buy[i];
    sum %= buy[i];
    //sell
    sum += nmb*sell[i];
    nmb = 0;
  }

  cout << sum << endl;

  return 0;
}
