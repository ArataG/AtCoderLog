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
  int n;
  cin >> n;


  map<char,int> mp;
  REP(i,n){
    string s;
    cin >> s;
    REP(j,n){
      char x = s[j];
      ++mp[x];
    }
  }

  if(n == 1){
    for(char c = 'a'; c <= 'z'; ++c){
      if(mp[c]>0){
      cout << c << endl;
      return 0;
    }
  }
}


  string ans;

  for(char c = 'a'; c <= 'z'; ++c){
    //cout << mp[c] << endl;
    int numc = mp[c];
    if (numc/2 > 0){
      REP(i,numc/2){
        ans += c;
        --mp[c];
        //cout << c << endl;
        if(ans.size() == n/2) break;//++cnt;
      }
      if(ans.size() == n/2) break;//++cnt;
    }
    if(ans.size() == n/2) break;//++cnt;
  }

  //cout << "ans"<<ans.size() << endl;

  if(ans.size() < n/2){
    cout << -1 << endl;
    return 0;
  }

  //回分の作製

  string ans2 = ans;
  sort(RALL(ans2));
  if(n % 2 == 0){
    ans += ans2;
  }
  else{
    char c1 = '1';
    for(char c = 'a'; c <= 'z'; ++c){
      if(mp[c] > 0){
        c1 = c;
        break;
      }
    }
    if(c1 == '1'){
      cout << -1 << endl;
      return 0;
    }
    ans += c1;
    ans += ans2;
  }


  cout << ans << endl;


  return 0;
}
