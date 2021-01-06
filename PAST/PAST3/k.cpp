#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, q;
  cin >> n >> q;
  vector<stack<int>> s(n);
  //init
  REP(i,n){
    s[i].push(i);
  }

  //クエリ
  REP(i,q){
    int f, t, x;
    cin >> f >> t >> x;
    --f; --t; --x;
   int c = -1;
   bool flg = true;

    while(flg){
      c = s[f].top();
      cout <<"c" <<  c << endl;
      s[f].pop();
      s[t].push(c);
      if(c == x) {
        flg = false;
        cout << " break" << endl;
      }
    }
  }

  // while( !s[2].empty()){
  //   int x = s[2].top();
  //   s[2].pop();
  //   cout << x << endl;
  // }
  vector<int> ans(n);   //各荷物の積まれている机

  REP(i,n){//各テーブルについて
    while( !s[i].empty() ){
      int c;
      c = s[i].top();
      ans[c] = i;
      s[i].pop();
    }
  }

  REP(i,n){
    cout << ans[i] << endl;
  }



  return 0;
}
