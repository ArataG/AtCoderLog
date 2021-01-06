#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


//----------------------------
//累積和の問題
//サンプルは通すことができたが，
//入力が２つWAで断念
//---------------------------

static const int CMAX = 31;
static const int INF = 100005;
int p[CMAX][INF];


int main(){
  int n, c;
  cin >> n >> c;
  //int p[35][100005]; //cannel, 時間
  REP(i,CMAX)REP(j,INF) p[i][j] = 0;

  REP(i,n){
    int s, t, x;
    cin >> s >> t >> x;
    --x;
    --s;
    //++t;
    if(p[x][s+1] == -1){ //連続で録画
        ++p[x][s+1];
        //--p[x][t];
        //continue;
    }
    else ++p[x][s];

    if(p[x][t-1] == 1){ //連続で録画
        //++p[x][t];
        --p[x][t-1];
        continue;
    }
    else --p[x][t];
    //++p[x][s];

  }


  // REP(j,c){
  //   REP(i,40){
  //   cout << p[j][i] << " ";
  // }
  // cout << endl;
  // }

  vector<int> sum(INF);
  int maxSum = 0;

  REP(i,CMAX){
    REP(j,INF){
      sum[j] += p[i][j];
    }
  }

  // REP(j,100){
  //   cout << sum[j] << " ";// += p[i][j];
  // }
  // cout << endl;


  int sumsum = 0;

  REP(i,INF){
    sumsum += sum[i-1];
    maxSum = max(maxSum, sumsum);
  }


  cout << maxSum << endl;
  return 0;
}
