#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

  int n, q;
  cin >> n >> q;
  vector<int> a(n), b(n); //レート，所属の幼稚園

  vector<multiset<int>> s(200005); //各幼稚園のレートの値の集合
  multiset<int> maxs;      //すべての幼稚園の最大値の集合


  //ラムダ式
  auto getMax = [&](int i){
    //園児がいない場合
    if(s[i].size() == 0) return -1;
    //いる場合
    return *(s[i].rbegin()); //setの最後の値を返す
  };



  auto addYochien = [&](int i){
    int x = getMax(i);
    if( x == -1) return;  //園児がいなかったら無視
    maxs.insert(x);
  };

  auto delYochien = [&](int i){
    int x = getMax(i);
    if( x == -1) return;  //園児がいなかったら無視
    maxs.erase(maxs.find(x));
    // maxs.erase(x)とするとすべてび値が消えてしまうのでｘのあるイテレータの値を消去
  };

  auto addEnji = [&](int i, int x){
    delYochien(i);
    s[i].insert(x);
    addYochien(i);
  };

  auto delEnji = [&](int i, int x){
    delYochien(i);
    s[i].erase(s[i].find(x));
    addYochien(i);
  };


  REP(i,n) {
    cin >> a[i] >> b[i];
    addEnji(b[i], a[i]); //各幼稚園に園児のデータを挿入
  }

  REP(i,q){
    int c, d;
    cin >> c >> d;
    --c;
    delEnji(b[c], a[c]);
    b[c] = d;
    addEnji(b[c], a[c]);
    int ans = *maxs.begin();
    printf("%d\n", ans);

  }

  return 0;
}
