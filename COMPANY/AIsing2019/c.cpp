#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };


int main (){
  int H, W;
  cin >> H >> W;
  vector<string> field(H);
  REP(h,H) cin >> field[h];

  // 各セルの最短距離 (訪れていないところは -1 としておく)
  vector<vector<int> > dist(H, vector<int>(W, -1));
  //dist[0][0] = 0; // スタートを 0 に

  ll ans = 0;
  REP(h,H)REP(w,W){
    if(dist[h][w] != -1) continue;
    dist[h][w] = 1;
  //------------------------------------------------

  // 「一度見た頂点」のうち「まだ訪れていない頂点」を表すキュー
  queue<pair<int, int> > que;
  que.push(make_pair(h, w)); // スタートを push
  int black = 0;
  int white = 0;
  if(field[h][w] == '#') ++black;
  else ++white;

  //BFS
  while(!que.empty()){
    pair<int,int> now = que.front();
    int x = now.first;
    int y = now.second;
    que.pop();
    //隣接頂点を探索
    REP(dir,4){
      int next_x = x + dx[dir];
      int next_y = y + dy[dir];

      //
      //探索先が場外の場合
      if (next_x < 0 || next_x >= H || next_y < 0 || next_y >= W) continue;
      //探索先が同じ種類の場合はスキップ
      if (field[x][y] == field[next_x][next_y]) continue;

      // まだ見ていない頂点なら push
      if (dist[next_x][next_y] == -1) {
          que.push(make_pair(next_x, next_y));
          dist[next_x][next_y] = 1;
          if(field[next_x][next_y] == '#') ++black;
          else ++white;
      }
    }
  }

  //cout << h << " "<< w << " "<< black << " "<< white << endl;
  ans += white*black;

  //-------------------------------------
}
  cout << ans << endl;

  return 0;


}
