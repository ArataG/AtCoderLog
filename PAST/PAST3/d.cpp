#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);

int lamp[10][205];
int main(){

  vector<string> s(5);

  s[0] = ".###..#..###.###.#.#.###.###.###.###.###.";
  s[1] = ".#.#.##....#...#.#.#.#...#.....#.#.#.#.#.";
  s[2] = ".#.#..#..###.###.###.###.###...#.###.###.";
  s[3] = ".#.#..#..#.....#...#...#.#.#...#.#.#...#.";
  s[4] = ".###.###.###.###...#.###.###...#.###.###.";

  vector<string> a(10);

  REP(i, 5){
    REP(j,10)
    a[j] += s[i][j*4+1] + s[i][j*4+2] + s[i][j*4+3];// + s[i][2] + s[i][3];
    }
  //
  // REP(i,10){
  //   cout<< a[i]<< endl;
  // }

  auto change = [&](string str){
    REP(i,10){
      if( str == a[i]) return i;
    }
  };

  int n;
  cin >> n;

  string s1, s2, s3, s4, s5;
  cin >> s1 >> s2 >> s3 >> s4 >> s5;

  string ans

  return 0;
}
