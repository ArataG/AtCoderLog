#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

//-------------------
//制約が小さいので，　全探索を考える
//t = coder のいちを固定して考える．
//--------


int main(){
  string a, t;
  cin >> a >> t;

  int n =  a.size() - t.size() + 1;
  //cout << n << endl;
  if( a.size() < t.size() ){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  // if(n == 1){
  //   REP(i,t.size()){
  //     if (a[i] == t[i] ||　a[i] == '?') continue;
  //     else ok = false;
  //   }
  //
  // }

  //init
  vector<string> vec_s;
  string firstS;
  REP(i,a.size()) firstS += 'z';


  REP(k,n){
    bool ok = true;
    string s = firstS;

    REP2(i,0,k){
      if (a[i] == '?') s[i] = 'a';
      else s[i] = a[i];
    }
    REP2(i,k,k + t.size()){
      if (a[i] == t[i-k] || a[i] == '?' ){
        s[i] = t[i-k];
      }
      else {
        ok = false;
        break;
      }
    }
    REP2(i,k+t.size(),a.size()) {
        if (a[i] == '?') s[i] = 'a';
        else s[i] = a[i];
      }

    //cout << s << " " << ok <<endl;
    if(ok) vec_s.push_back(s);
  }

  if(vec_s.empty()){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  sort(ALL(vec_s));

  cout << vec_s[0] << endl;

  return 0;
}
