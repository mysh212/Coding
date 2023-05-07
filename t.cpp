#include<bits/stdc++.h> 
# 1 "ccb.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "ccb.cpp"

using namespace std;
typedef pair <int, int> pi;
const int N = 1000;
typedef int grid[N][N];
typedef bool gb[N][N];
typedef long long ll;




int n, m;
grid a;

void init()
{
    memset(a, 0, sizeof(a));
}

inline bool valid(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}

ll dfs(int y, int x)
{
    static int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};

    ll re = a[y][x];
    a[y][x] = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i], nx = x + dx[i];
        if (valid(ny, nx) && a[ny][nx])
            re += dfs(ny, nx);
    }
    return re;
}


ll bfs(int y, int x)
{
    static int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
    queue <pi> q;

    ll re = a[y][x];
    q.push({y,x});
    a[y][x] = 0;

    while (!q.empty())
    {
        pi v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = v.first + dy[i], nx = v.second + dx[i];
            if (!valid(ny, nx) || a[ny][nx] == 0) continue;
            pi nv = {ny, nx};
            q.push(nv);
            re += a[ny][nx];
            a[ny][nx] = 0;
        }
    }
    return re;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        ll ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (a[i][j])
                    ans = max(ans, bfs(i, j));
            }
        cout << ans << "\n";
    }
    return 0;
}
