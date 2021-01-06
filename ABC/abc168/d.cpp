#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;
vector<int> to[100005];

int main(){
  int n, m;
  cin >> n >> m;
  REP(i,m){
    int a, b;
    cin >> a >> b;
    --a; --b; //始点を０からにするため
    //ノードにつながる他のノードを配列に格納
    to[a].push_back(b);
    to[b].push_back(a);
  }

  //BFS
  queue<int> q;
  vector<int> dist(n, INF); //すべての要素にINFを代入して初期化
  vector<int> pre(n, -1); //直前の頂点
  //始点の０をキューに入れる
  q.push(0);
  while(!q.empty()){
    //キューの先頭から取り出し
    int v = q.front();
    q.pop();
    //vを訪れる
    for(int u : to[v]){
      if(dist[u] != INF) continue; //既に訪れていたら何もしない
      dist[u] = dist[v] + 1;
      pre[u] = v;
      q.push(u);
    }
  }

  cout << "Yes" << endl;
  REP(i,n){
    if(i == 0) continue;
    int ans = pre[i];
    ++ans; //始点を１に戻す
    cout << ans << endl;
  }

  return 0;
}
//BFSを利用する．＞＞キューを使う
//隣接するノードが埋まっていなかったら，更新する
//親の情報をpreとして保存しておく
//vector<int> v{1,2,3,4,5,6,7};
//範囲ベースforループ　for(int x: v) >> for(変数宣言：範囲)
//http://vivi.dyndns.org/tech/cpp/range-for.html
//配列を範囲として指定できる
