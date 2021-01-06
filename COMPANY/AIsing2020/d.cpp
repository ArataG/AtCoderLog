#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

static const int MX = 200005;
static int pop[MX];
static int f[MX];

void setpop(){
  int n = 18;
  REP(i, 1 << n){
    //cout << i << endl;
    int cnt = 0;
    REP(j,n) if(i >> j&1){  //i の j ビット目が１であるかの判定
      ++cnt;
    }
    pop[i] = cnt;
    if(i >= MX-1) break;
  }
}


int main(){

  setpop();
  //SET f[x];
  REP(i,MX) f[i] = 0;
  REP2(i,1,MX){
    int cnt = 1;
    int x = i;
    while(1){
      if(x%pop[x] == 0) {
        f[i] = cnt;
        break;
        //cout << " here" << i << endl;
      }
      else{
        //cout << " here2" << i << endl;
        ++cnt;
        x %= pop[x];
        if(f[x] == 0) continue;

        f[i] = f[x] + cnt;
        break;
      }
    }
  }

  int n;
  string s;
  cin >> n >> s;

  int a = 0;
  REP(i,n){
    if(s[i] == '0') continue;
    a += pow(2,n-i-1);
  }

  //cout << pow(2,0) << endl;

  cout << a << endl;
  //REP2(i,1,n) cout << i << "x: "<< f[i] << endl;
  //
  // cout << f[7] << endl;
  // cout << f[1] << endl;
  // cout << f[100] << endl;

  return 0;
}
