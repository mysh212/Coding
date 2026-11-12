// Author : ysh
// 2026/11/12 Thu 12:40:49
#include<iostream>
#include<cassert>
#include<mpi.h>
#include<slow>
using namespace std;
#define world MPI_COMM_WORLD
vector<int>f;
inline deque<int> mg(int l, int r) {
    if(l == r) return {f.at(l)};

    int mid = (l + r) >> 1;

    auto ll = mg(l, mid);
    auto rr = mg(mid + 1, r);

    #undef nl
    int nl, nr;nl = nr = 0;
    int now = 0;

    deque<int>f(r - l + 1);
    while(!(nl == mid - l + 1 && nr == r - mid)) {
        if(nl == mid - l + 1) f.at(now++) = rr.at(nr++);
        else if(nr == r - mid) f.at(now++) = ll.at(nl++);
        else {
            if(ll.at(nl) < rr.at(nr)) f.at(now++) = ll.at(nl++);
            else f.at(now++) = rr.at(nr++);
        }
    }

    return f;
}
int main(int ac, char* as[]) {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    MPI_Init(&ac, &as);

    int rank, ws;

    MPI_Comm_rank(world, &rank);
    MPI_Comm_size(world, &ws);

    {
        int n;
        if(rank == 0) cin>>n;

        MPI_Bcast(&n, 1, MPI_INT, 0, world);

        vector<int>f(n);
        if(rank == 0) cin>>f;
        while(n % ws) n++, f.push_back(-1);

        int m = n / ws;
        vector<int>v(m);

        MPI_Scatter(f.data(), m, MPI_INT, v.data(), m, MPI_INT, 0, world);

        ::f = v;

        auto p = mg(0, m - 1);
        vector<int>ans(p.begin(), p.end());

        MPI_Gather(ans.data(), m, MPI_INT, f.data(), m, MPI_INT, 0, world);

        outl(f);
    }

    MPI_Finalize();
}