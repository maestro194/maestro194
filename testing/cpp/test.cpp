/*
  Author: _Maestro
  Status: Not submitted
*/

#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
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

ll m, n;
ll a[100005], b[100005];
ll ans;

bool check(ll r){
	ll top=0;
	for(ll i=0; i<n; i++){
		if(abs(a[i]-b[top])>r){
			while(top < m && abs(a[i]-b[top])>r){
				top++;
			}
			if(top == m){
				return 0;
			}
		}
	}
	return 1;
}

void Solve()
{
  cin >> n >> m;
  for(int i = 0; i < n; i ++)
      cin >> a[i];
  for(int i = 0; i < m; i ++)
      cin >> b[i];
  
  ll l=0, r=max(abs(a[0]-b[m-1]), abs(a[n-1]-b[0]));
  while(r>l){
    ans=(r+l)/2;

    if(check(ans))
      r=ans;
    else
      l=ans+1;
  }
  cout << r;
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

