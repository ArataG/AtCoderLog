#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  string s, t;
  cin >> s >> t;

  if(s == t){
    cout << "same" << endl;
    return 0;
  }

  REP(i,3){
    if(isupper(s[i])) s[i] += 32;
    if(isupper(t[i])) t[i] += 32;
  }

  if(s == t){
    cout << "case-insensitive" << endl;
    return 0;
  }
  else{
    cout << "different" << endl;
    return 0;
  }
  return 0;
}
