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

int a, b, c;
int d[1005][3];

void Solve()
{
  cin >> a >> b >> c;

  for(int i = 0; i < 16 + 12 + 6; i ++) {
    cin >> d[i][0] >> d[i][1] >> d[i][2];
  }

  for(int i = 0; i < a; i ++) {
    for(int j = 0; j < b; j ++) {
      for(int k = 0; k < c; k ++) {
        vector<pair<int, pii>> v;
        for(int gt2 = i * 4; gt2 < (i + 1) * 4; gt2 ++)
          v.pb({d[gt2][0], {d[gt2][1], d[gt2][2]}});
        for(int ktct = 16 + j * 2; ktct < 16 + (j + 1) * 2; ktct ++)
          v.pb({d[ktct][0], {d[ktct][1], d[ktct][2]}});
        // for(int thht = 28 + k * 3; thht < 28 + (k + 1) * 3; thht ++)
        //   v.pb({d[thht][0], {d[thht][1], d[thht][2]}});
        
        sort(all(v));

        for(int id = 0; id < v.size() - 1; id ++)
          if(v[id] == v[id + 1])
            break;
        for(int id = 0; id < v.size() - 1; id ++)
          if(v[id].X == v[id + 1].X && v[id].Y.Y + 1 == v[id + 1].Y.X)
            v[id].Y = {v[id].Y.X, v[id + 1].Y.Y}, v.erase(v.begin() + id + 1);
        
        if (v.size() <= 5) {
          cout << "Total: " << v.size() << endl;
          for(int id = 0; id < v.size(); id ++)
            cout << v[id].X << " " << v[id].Y.X << " " << v[id].Y.Y << endl;
          cout << endl;
        }
      }
    }
  }
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

