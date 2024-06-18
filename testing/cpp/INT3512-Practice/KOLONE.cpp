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

int n, m;
string a, b;
int t;

void Solve()
{
  cin >> n >> m;
  cin >> a >> b;
  cin >> t;

  bool sw = (t > 0);
  int cnt = 0;
  vector<char> v;
  vector<int> pos;

  for(int i = n - 1; i >= 0; i --)
    v.push_back(a[i]), pos.push_back(1);
  for(int i = 0; i < m; i ++)
    v.push_back(b[i]), pos.push_back(2);

  while(sw) {
    sw = false;
    cnt ++;

    for (int i = 0; i < n + m - 1; i ++) {
      if (pos[i] == 1 && pos[i + 1] == 2) {
        swap(v[i], v[i + 1]);
        swap(pos[i], pos[i + 1]);
        i ++;
        sw = true;
      }
    }

    if (cnt == t)
      sw = false;
  }

  for(char c : v) cout << c;

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