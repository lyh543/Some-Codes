#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

char * tmpp = new char;

int main()
{
#if !defined(_DEBUG) && !defined(ONLINE_JUDGE)
    //freopen("dig.in", "r", stdin);
    //freopen("dig.out", "w", stdout);
#endif
    
    int n, m;
    cin >> n >> m;
    vector<long double> times, dists;
    times.reserve(n);
    dists.reserve(n + 1);
    for(int i = 0; i < n; ++i)
    {
        char m[6];
        long long dat;
        scanf("%s%lld", m, &dat);
        if(m[0] == 'T')
            times.push_back(dat);
        else
            dists.push_back(dat);
    }
    dists.push_back(m);

    sort(dists.begin(), dists.end());
    sort(times.begin(), times.end());
    
    long double curtm = 0;
    long double hcnt = 1;
    long double cur_time = 0, cur_dist = 0;
    for(long double curdm = 0; curdm < dists.size(); ++curdm)
    {
        while(curtm < times.size())
        {
            long double nxt_time = cur_time + (dists[curdm] - cur_dist) * hcnt;
            if(nxt_time < times[curtm])
                break;
            //cerr << "cur_dist: " << cur_dist << " -> ";
            cur_dist += (times[curtm] - cur_time) / hcnt;
            //cerr << cur_dist << endl;
            //cerr << "cur_time: " << cur_time << " -> ";
            cur_time = times[curtm];
            //cerr << cur_time << endl;
            ++curtm;
            ++hcnt;
        }
        //cerr << "cur_time: " << cur_time << " -> ";
        cur_time += (dists[curdm] - cur_dist) * hcnt;
        //cerr << cur_time << endl;
        //cerr << "cur_dist: " << cur_dist << " -> ";
        cur_dist = dists[curdm];
        //cerr << cur_dist << endl;
        ++hcnt;
    }

#ifdef ONLINE_JUDGE
    cout << (long long)(cur_time) / 10 << "\n";
#else
    cout << (long long)(cur_time) << "\n";
#endif
}

