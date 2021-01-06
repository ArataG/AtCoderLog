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

  int n,m,q;
  cin >> n >> m >> q;
  vector<int> point(m+1);
  int score[n+1][m+1];     //参加者のポイント
  REP(i, m+1) point[i] = n;   //現在の問題Mのポイント
  REP(i,n+1){
    REP(j,m+1) score[i][j] = 0;
  }

  REP(i,q){
    int f;
    cin >> f;
    if(f == 1){
      int answer;
      cin >> answer;
      int pp = 0;
      REP(i,m+1){
        pp += score[answer][i] * point[i];
      }
      cout << pp << endl;

    }
    if(f == 2){
      int answer;
      int problem;
      cin >> answer >> problem;
      --point[problem];
      score[answer][problem] = 1;
    }
  }

  return 0;
}
