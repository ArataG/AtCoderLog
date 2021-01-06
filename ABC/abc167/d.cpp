#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n, m, x;
  cin >> n >> m >> x;
  int c[n];
  int a[n][m];
  int c_sum[];
  int a_sum[];

  REP(i, n){
    cin >> c[i];
    REP(j, m){
      cin >> a[i][j];
    }
  }
//bit全探索　2^12

  for(int bit = 0; bit < (1<<n); ++i){

    int c_sum = 0;

    REP(i,n){
      if(bit & (1 << i)){ //bitに１が入ってるなら
        sum +=
      }
    }
  }

  return 0;

}
