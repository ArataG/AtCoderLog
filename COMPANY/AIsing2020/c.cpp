#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



//--------------------------------------//
//N <= 10^4
//x*x + y*y + z*z + x*y + y*z + z*x = n
// x,y,z <=100
//毎回ループを回せないので，先に集計する．
//全探索を工夫するタイプ
//--------------------------------------//

int main(){
  int n;
  cin >> n;
  vector<int> a(10001);
  for(int x = 1; x <= 100; x++){
    for(int y = 1; y <= 100; y++){
      for(int z = 1; z <= 100; z++){
        int f =  x*x + y*y + z*z + x*y + y*z + z*x;
        if(f <= 10000) ++a[f];
      }
    }
  }

  REP2(i,1,n+1) cout << a[i] << endl;
}

//-------------------------------------//
//想定解法では．nをループ内で一気に求めている．
//先にn<200005の配列を用意しといて，x-y-zを順番にループさせるたときの値を，配列に格納していく
//よく見る問題かな．
//今回は，枝刈りによってなんとかもとまったx<=y<=zと仮において，なんとか正解
//計算量見積もってだめ解法だと気がつくべきだったかな．
//-----------------------------------//



/*//提出した解答//
int main(){
  int n;
  cin >> n;

  REP2(i,1,n+1){
    int cnt = 0;

    for(int x = 1; x*x <= n ;x++){
      for(int y = x; y*y <= n - x*x ;y++){
          for(int z = y; z*z <= n-x*x-y*y ;z++){
          int f = 0;
          f = x*x + y*y + z*z + x*y + y*z + z*x;
          if(f == i){
            if (x == y && y == z) ++cnt;
            else if(x == y || y == z) cnt += 3;
            else cnt += 6;
            break;
          }
        }
      }
    }
    printf("%d\n",cnt);
  }
  return 0;
}
*/
