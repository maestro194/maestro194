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
int a[500050];
vector<int> b;
ll T[2000020];

void update(int x, int v) {
  while(x <= n) {
    T[x] += v;
    x += x & (-x);
  }
}

ll get(int x) {
  ll res = 0;
  while (x > 0) {
    res += T[x];
    x -= x & (-x);
  }
  return res;
}

void Solve()
{
  cin >> n;
  for(int i = 1; i <= n; i ++) {
    cin >> a[i];
    b.push_back(a[i]);
  }
  sort(all(b));
  b.resize(unique(all(b)) - b.begin());

  for(int i = 1; i <= n; i ++)
    a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;

  ll ans = 0;
  for(int i = n; i > 0; i --) {
    ans += get(a[i] - 1);
    update(a[i], 1);
  }
  cout << ans;
  
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

