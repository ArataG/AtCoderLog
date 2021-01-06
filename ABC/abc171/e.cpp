#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);  //EX: (a1^a2^a3)

  REP(i,n) cin >> a[i];
  int s = 0;  //a[1]-a[n]のXORの総和
  REP(i,n) s ^= a[i]; //^=：XOR
  REP(i,n) a[i] ^= s;
  //EX: (a1^a2^a3^a4) ^ (a1^a2^a3) = a4
  //s = (a1^a2^a3^a4)
  REP(i,n-1) cout << a[i] << " ";
  cout << a[n-1] << endl;
  return 0;
}
