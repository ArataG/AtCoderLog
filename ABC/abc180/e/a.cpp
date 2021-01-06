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

int N;
int dist[21][21];

/* メモ再帰 */
int dp[(1<<20) + 1][21]; // dpテーブルは余裕をもったサイズにする
int rec(int bit, int v)
{
    // すでに探索済みだったらリターン
    if (dp[bit][v] != -1) return dp[bit][v];

    // 初期値
    if (bit == (1<<v)) {
        return dp[bit][v] = 0;
    }

    // 答えを格納する変数
    int res = INF;

    // bit の v を除いたもの
    int prev_bit = bit & ~(1<<v);

    // v の手前のノードとして u を全探索
    for (int u = 0; u < N; ++u) {
        if (!(prev_bit & (1<<u))) continue; // u が prev_bit になかったらダメ

        // 再帰的に探索
        if (res > rec(prev_bit, u) + dist[u][v]) {
            res = rec(prev_bit, u) + dist[u][v];
        }
    }

    return dp[bit][v] = res; // メモしながらリターン
}

int main(){
  //int N;
  cin >> N;
  vector<int> x(N);
  vector<int> y(N);
  vector<int> z(N);
  REP(i,N) cin >> x[i] >> y[i] >> z[i];
  //int dist[n][n];
  REP(i,N){
    REP(j,N) {
      dist[i][j] = abs(x[i] - x[j]) + abs(y[i]- y[j]) + max(0,z[j]- z[i]);
    }
  }
  int mindist = INF;
  REP2(i,1,N){
      mindist = min(mindist, abs(x[0] - x[i]) + abs(y[0]- y[i]) + max(0,z[i]- z[0]));
  }
  // REP(i,n){
  //   REP(j,n) {
  //     cout << dist[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  for (int bit = 0; bit < (1<<N); ++bit) for (int v = 0; v < N; ++v) dp[bit][v] = -1;

    // 探索
    int res = INF;
    for (int v = 0; v < N; ++v) {
        if (res > rec((1<<N)-1, v)) {
            res = rec((1<<N)-1, v);
        }
    }
    cout << res+mindist << endl;
    return 0;
}
