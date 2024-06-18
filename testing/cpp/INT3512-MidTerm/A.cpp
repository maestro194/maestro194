/*
  Author: CNH_Tourist
  Status: Not submitted
*/

#include <bits/stdc++.h>
#pragma GCC optimization ("unrolled-loops")
using namespace std;

#define filename "test"
#define endl '\n'
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ll long long
#define all(x) (x).begin(),(x).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define CBIT __builtin_popcount
#define gcd __gcd

void FileInOut()
{
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  ifstream *fi = new ifstream (filename".inp");
  ofstream *fo = new ofstream (filename".out");
  if(*fi)
  {
    cin.rdbuf( fi->rdbuf() );
    cout.rdbuf( fo->rdbuf() );
  }

}
// unusual mod : 1000003999
// atan2(y, x): tinh goc tao boi oX va diem co toa do (x, y)

int n;
long long k;
int p[1000010];

void Solve()
{
  cin >> n >> k;

  int cur = n;

  for(int i = 1; i <= n; i ++) {
    if(k >= n - i) {
      p[i] = cur;
      cur --;
      k -= n - i;
    }
    else {
      if (k == 0)
        i --;
      else
        p[i] = k + 1;
      
      p[i + 1] = 1;

      for(int j = i + 2; j <= n; j ++) {
        p[j] = p[j - 1] + 1;

        if(p[i] == p[j])
          p[j] ++;
      }
      break;
    }
  }

  for(int i = 1; i <= n; i ++)
    cout << p[i] << " ";
}

int32_t main()
{
  using namespace std::chrono;
  auto start = high_resolution_clock::now(); 
  FileInOut(); 

  int test = 1;
  // cin >> test;
  while(test--)
    Solve();

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  double t = duration.count() * 1.0 / 1000000;
  // cout << endl << "Runtime: " << t << endl;
}

