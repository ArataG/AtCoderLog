#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int H = 410;
int W = 410;
vector<string> field;

//search
int seen[410][410];

int cnt;

void dfs(int h, int w){
  seen[h][w] = true;

  //4方向を探索
  REP(dir,4){
    int nh = h + dx[dir];
    int nw = w + dy[dir];

    //範囲外はスキップ
    if(nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
    //壁ならばスキップ
    if(field[nh][nw] == '#') continue;
    //探索済ならスキップ
    if(seen[nh][nw] == true) continue;

    // //探索の様子の可視化　探索済みをo
    // field2  = field;
    // field2[nh][nw] = 'o';
    // REP(i,H) cout << field2[i] << endl;
    // cout << endl << endl;

    //上の条件がスルーできたら再帰的に次のコマに移動；
    dfs(nh, nw);


  }

}


int main(){

  //input
  int n, gh, gw;
  cin n >> gh >> gw;
  int sh,sw;
  sh = 200;  sw = 200;
  gh += 200; gw += 200;

  REP(h,H){
    REP(w,W) field[h][w] = "."
  }

  field[sh][sw] = 's';
  field[gh][gw] = 'g';


  REP(i,n){
    int x, y;
    cin >> x >> y;
    x += 200; y += 200;
    field[x][y] = '#';
  }

  //DFS search;
  //Start DFS search
  memset(seen, 0, sizeof(seen)); // seenをfalseに初期化
  dfs(sh,sw);

  return 0;
}
