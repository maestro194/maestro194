/*
  Author: CNH_Tourist as history - ICPC Northern Provincial Regional 2023
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

int n, k;
map<int, int> mp;

struct line{
  int x, y, col, p;
  line(int _x, int _y, int _col, int _p) {
    x = _x; y = _y; col = _col; p = _p;
  }
};

bool cmp(line a, line b) {
  if(a.col == b.col)
    return a.x < b.x;
  return a.col < b.col;
}
vector<line> v;

// segtree
int t[400040];
int lz[400040];
int tmin[400040];

void down(int id) {
  lz[id * 2] += lz[id];
  lz[id * 2 + 1] += lz[id];
  t[id * 2] += lz[id];
  t[id * 2 + 1] += lz[id];
  tmin[id * 2] = tmin[id];
  tmin[id * 2 + 1] = tmin[id];
  lz[id] = 0;
}

void update(int id, int l, int r, int L, int R, int val) {
  if(r < L || R < l)
    return;
  if(L <= l && r <= R) {
    lz[id] += val;
    t[id] += val;
    tmin[id] += val;
    return;
  }
  down(id);

  int m = (l + r) >> 1;

  update(id * 2, l, m, L, R, val);
  update(id * 2, m + 1, r, L, R, val);

  t[id] = t[id * 2] + t[id * 2 + 1];
  tmin[id] = min(tmin[id * 2], tmin[id * 2 + 1]);
}

int query_min(int id, int l, int r, int L, int R) {
  if(r < L || R < l)
    return 0;
  if(L <= l && r <= R) {
    return 
  }
}

void Solve()
{
  cin >> k >> n;
  char c;
  int l;
  long long x = 0, y = 0;
  
  for(int i = 0; i < n; i ++) {
    cin >> c >> l;

    if(c == 'N') {
      v.push_back(line(y, y + l + k, x, 1));
      v.push_back(line(y, y + l + k, x + k, -1));
      y += l;
    }
    if(c == 'S') {
      v.push_back(line(y - l, y + k, x, 1));
      v.push_back(line(y - l, y + k, x + k, -1));
      y -= l;
    }
    if(c == 'W') {
      v.push_back(line(y, y + k, x - l, 1));
      v.push_back(line(y, y + k, x + k, -1));
      x -= l;
    }
    if(c == 'E') {
      v.push_back(line(y, y + k, x, 1));
      v.push_back(line(y, y + k, x + l + k, -1));
      x += l;
    }
  }

  sort(all(v), cmp);
  set<int> s;
  
  for(int i = 0; i < v.size(); i ++)
    s.insert(v[i].x),
    s.insert(v[i].y);
  
  int n = 0;
  for(auto x : s) {
    mp[x] = ++ n;
  }



  for(int i = 0; i < v.size(); i ++) 
    cout << v[i].x << " " << v[i].y << " " << v[i].col << " " << v[i].p << endl;

}

int32_t main()
{
  FileInOut();

  int test = 1;
  // cin >> test;
  while(test--)
    Solve();
}