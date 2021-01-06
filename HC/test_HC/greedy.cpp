#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


//Inputdata
static const int D = 365;
vector<int> c(D);
int s[D][26];
ll ans[D];
int last[26];  //コンテストが最後に行われた日
vector<int> t(D);

int checkScore(int d, int t){
 int score = 0;
 score += s[d][t];
 //last[t] = d;
 REP(i,26){
   score -= c[i] * (d - last[i]);
 }
 return score;
}

void input(){
  //input data
  int _;
  cin >> _;

  REP(i,26) cin >> c[i];
  REP(d,D){
    REP(i,26){
      int x;
      cin >> x;
      s[d][i] = x;
    }
  }

}

void initial(){
  REP(i,26) last[i] = -1;
  REP(d, D) ans[d] = 0;
  REP(d, D) t[d] = 1;
  //ans = 0;
}

void finScore(vector<int> t){
  int score = 0;
  REP(i,26) last[i] = -1;

    REP(d,D){
      int ci = t[d] - 1;
      score += s[d][ci];
      last[ci] = d;

      REP(i,26){
        score -= c[i] * (d - last[i]);
      }
      cout << score << endl;
    }
}




int main(){
  input();

  initial();

  int MX_score = 0;
  int MX_i = 0;

  //maxscore
  REP(d,D){
    MX_score = 0;
    REP(i,26){
      int score = 0;
      ans[d] = 0;
      score = checkScore(d, i);
      if(score > MX_score){
        MX_score = max(MX_score, score);
        t[d] = i + 1;
        MX_i = i;
      }
      //last[i] = 0;
    }
    ans[d] = MX_score;
    last[MX_i] = d;
    //cout << d   << " "<< MX_score << endl;
  }

  REP(d,D) cout << t[d] <<  endl;

  finScore(t);


  //ll sum = 0;

  // REP(d,D){
  //   cout << ans[d] << endl;
  //   sum += ans[d];
  // }
  //cout << sum << endl;

  return 0;
}




//input testcase //最終的に求めたい答え
// vector<int> t(D);
// REP(d,D){
//   int x;
//   cin >> x;
//   --x;
//   t[d] = x;
// }
//initial;
