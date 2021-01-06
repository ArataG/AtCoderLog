#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int M = 1000005;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  vector<int> cnt(M); //カウント用の変数：数列Aの倍数のイテレータを+１
  for(int x : a){
    if(cnt[x] != 0){
      cnt[x] = 2;
      continue;
      //重複している数列の処理（cnt[x] が１以上　ー>　重複する数字orその約数がすでに存在
      //それ以降は更新する必要ないためcontinueでスキップする
    }

    for(int i = x; i < M; i += x) cnt[i]++; //数字の倍数をインクリメント

  }

  //output
  int ans = 0;
  for(int x : a){
    if(cnt[x] == 1) ans++;
  }

  cout << ans << endl;
  return 0;
}


//範囲for:配列のすべての要素に処理を行う
//for(int x: a)
//for(int x = 0; x < a.size(); ++x)
//と同義
