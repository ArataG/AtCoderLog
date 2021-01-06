#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int m = 2019;

int main(){
string s;
cin >> s;
int n = s.size();
reverse(ALL(s)); //10^ｎ　と配列の値を一致させるため
int x = 1;    //累乗根
int tot = 0;  //累積和
vector<int> cnt(m);

ll ans = 0;
REP(i,n){
  cnt[tot]++;
  tot += (s[i] - '0')*x;
  tot %= m;
  ans += cnt[tot];
  x = x*10%m;
}
cout << ans << endl;

return 0;


}
