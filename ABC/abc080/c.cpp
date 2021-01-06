#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


//-----------
//bit　全探索．調べながら解けた．
//-----------



int main(){
  int n;
  cin >> n;
  int f[n][10];
  int p[n][11];
  REP(i,n)REP(j,10) cin >> f[i][j];
  REP(i,n)REP(j,11) cin >> p[i][j];

  int MX = -2000000000;


  REP2(bi, 1, 1 << 10){
    int profit  = 0;
    //cout << bi << endl;
    REP(i,n){
      int cnt = 0;
      REP(j, 10) {
        if(bi >> j&1){
          if(f[i][j]) ++cnt;
        }
      }
      profit += p[i][cnt];
      }
    MX = max(profit, MX);
  }


  cout << MX << endl;



  return 0;
}
