#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

//------------------------------
// tが文字列Sの部分列かどうか
// S = 123123
// t=213
// 貪欲法で解ける
//または，各文字が現れるインデックスを先に集めておく
//貪欲法でインデックスを取る． >　二分探索で解ける．



int main(){
  int n;
  string s;
  cin >> n >> s;



	//数字の文字列をint型に一文字ずつ変換するラムダ式
	auto strTOint = [&](char c){
		return c - '0';
	};
	vector<int> a(s.size());
		REP(i,s.size()){
	     a[i] = strTOint(s[i]);
	}

  int ans = 0;
  REP(key,1000){
    bool ok = false;
    int key1 = key/100;
    int key2 = (key-key1*100)/10;
    int key3 = key-key1*100-key2*10;
    //cout << key << endl;
    //cout << key1 << key2 << key3 << endl;
    //findの計算量はO[調べる範囲] = 30000;
    int f1 = find(a.begin() , a.end(), key1) - a.begin();
    if (f1 == n) continue;
    int f2 = find(a.begin() + f1 +1, a.end(), key2) -  a.begin();
    if (f2 == n) continue;
    int f3 = find(a.begin() + f2 + 1, a.end(), key3) - a.begin();
    if(f3 != n){
      ++ans;
    }
}

  cout << ans << endl;
  return 0;
}
