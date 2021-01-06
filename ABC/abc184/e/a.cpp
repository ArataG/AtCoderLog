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
//debug 
#ifdef _DEBUG
#define debug(var)  do{cout << #var << " :";view(var);}while(0)
#else
#define debug(...)
#endif
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){for(const auto& e : v){ cout << e << " "; } cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){ for(const auto& v : vv){ view(v); } }


/* 4 方向への隣接頂点への移動を表すベクトル */
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };


int main() {
    //input
    /* 縦と横の長さ */
    int height, width;
    cin >> height >> width;
    /* 盤面 */
    vector<string> field(height);
    for (int h = 0; h < height; ++h) cin >> field[h];
    
    /* スタート地点とゴール地点 */
    int sx, sy, gx, gy;

    // vector<pair<int,int>> a;
    // vector<pair<int,int>> b;
    map <char, vector<pair<int,int>>> alp;

    REP(h,height)REP(w,width){
      if(field[h][w] == '.') continue;
      if(field[h][w] == '#') continue;
      if(field[h][w] == 'S') sx = h, sy = w;
      else if(field[h][w] == 'G') gx = h, gy = w;
      else alp[field[h][w]].push_back(make_pair(h,w));
    }
  
    // Init BFS
    // 各セルの最短距離 (訪れていないところは -1 としておく)
    vector<vector<int> > dist(height, vector<int>(width, -1));
    dist[sx][sy] = 0; // スタートを 0 に

    // 「一度見た頂点」のうち「まだ訪れていない頂点」を表すキュー
    queue<pair<int, int> > que;
    que.push(make_pair(sx, sy)); // スタートを push

    //Start BFS
    /* キューが空になるまで */
    while (!que.empty()) {
        pair<int, int> current_pos = que.front(); 
        int x = current_pos.first;
        int y = current_pos.second;
        que.pop(); // キューから pop を忘れずに

        //a-z teleport
        //次に移動可能な座標をリストにする
        vector<pair<int,int>> next; //x,y
        if(field[x][y] != '.' && field[x][y] != 'G' && field[x][y] != 'S' ){
          next = alp[field[x][y]];
          alp[field[x][y]].clear();
          //clearしておかないと，重複して移動可能なリストに追加されてしまうので注意
        }
        
        for (int dir = 0; dir < 4; ++dir) {
          next.push_back(make_pair(x + dx[dir], y + dy[dir]));
        }

       
        REP(i,next.size()){
            int next_x = next[i].first;
            int next_y = next[i].second;
            //探索先が場外の場合
            if (next_x < 0 || next_x >= height || next_y < 0 || next_y >= width) continue; 

            //探索先が壁（＃）の場合
            if (field[next_x][next_y] == '#') continue; // 壁はダメ

            // まだ見ていない頂点なら push
            if (dist[next_x][next_y] == -1) {
                que.push(make_pair(next_x, next_y));
                dist[next_x][next_y] = dist[x][y] + 1;
            }            
        }
    }

    //output 最短距離
    cout << dist[gx][gy] << endl;
    return 0;
}