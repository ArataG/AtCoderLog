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

/*

年齢調査の問題
入力
n: 人数　< 10e5
q ：回答数 < 10e5
a: 回答者 aとbの年齢差をｃとする．(age_b = age_a + c)
-100 <= c < 100
入力形式
n q
a1 b1 c1
:
:
aq bq cq

出力
矛盾が生じる場合-1

それ以外，年齢差の最大値を出力


*/


static const int MAX = 100005;
using Graph =  vector<vector<pair<int,int>>>;

vector<bool>  seen;
vector<int> age;
bool ok = true;
int NIL = -210; //-200 <= age <= 200が入力される可能性ある．


void dfs(const Graph &G, int v){
  seen[v] = true;
  for(auto next_v :G[v]){
    int pos = next_v.first;
    int nage = next_v.second;
    if(seen[pos]) continue;  //探索済ならばスキップ
   //年齢を更新 既に入力済みなら，　矛盾していないか確認する．
    if(age[pos] != NIL){
      if(age[pos] != age[v]+nage){
        ok = false;
      }
    }

    age[pos] = age[v] + nage;
    dfs(G, pos); //再帰関数
  }
}

int main(){
  int n, q;
  cin >> n >> q;
  age.resize(n);
  seen.resize(n);
  Graph G(n);
  REP(i,q){
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    P pa = make_pair(b,c);
    P pb = make_pair(a,-c);
    G[a].push_back(pa);
    G[b].push_back(pb);
  }



  REP(i,n) seen[i] = false;

  REP(i,n) age[i] = NIL;


  //id 0の村人の年齢を０として，DFS
  REP(i,n){
    if(seen[i]) continue;
    age[i] = 0;
    dfs(G, i);
  }


  //for (auto x: age) cout << x << endl;
  sort(ALL(age));
  //age == NIL のときを除去しなければいけない（全ての人から独立しているとき）
  int minage = *lower_bound(ALL(age), -200);
  int maxage = *(age.end()-1);
  int ans = abs(maxage - minage);


  //年齢差が１００歳以上だと，条件に矛盾している．
  //cout << ok << endl;
  if(ans > 100 || ok == false) cout << -1 << endl;
  else cout << ans << endl;
  return 0;

  //誰かが嘘をついているときの判定の方法がわからない
}
/*

input 1

3 6
1 2 -5
3 2 1
3 1 6
2 3 -1
2 1 5
1 3 -6
*/
//-6

/*input 2
3 3
2 3 7
1 2 -13
2 1 3
*/
//-1
