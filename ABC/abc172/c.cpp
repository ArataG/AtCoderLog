#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, m;
  ll k;
  cin >> n >> m >> k;
  queue<int> a;
  queue<int> b;
  REP(i,n){
    int x;
    cin >> x;
    a.push(x);
  }
  REP(i,m){
    int x;
    cin >> x;
    b.push(x);
  }

  int ans = 0;

  while(k >0 ){
    ll ax,bx;

    if(a.empty()){
      bx = b.front();
      k -= bx;
      b.pop();
      ++ans;
      continue;
    }
    if(b.empty()){
      ax = a.front();
      k -= ax;
      a.pop();
      ++ans;
      continue;
    }
    if(a.empty() && b.empty()) break;
//-------
    ax = a.front();
    bx = b.front();
    //min
    if(ax < bx){
      a.pop();
      k -= ax;
      ++ans;
    }
    else{
      b.pop();
      k -= bx;
      ++ans;
    }

  }
  if(!(a.empty() && b.empty())) --ans;

  cout << ans << endl;


  return 0;
}
