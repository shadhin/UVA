/*
Author: Golam Rahman Tushar
........Aust Cse 27th batch.........
*/

//{ Template

//{ C-headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ C++-headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;
//}

//}
//{ Floating-points
#define EPS DBL_EPSILON
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
#define INF (1<<29)
#define ll long long
#define CountOne(mask) __builtin_popcountll(mask)

template<class T1> void debug(T1 e){cout<<e<<endl;}
template<class T1,class T2> void debug(T1 e1,T2 e2){cout<<e1<<"\t"<<e2<<endl;}
template<class T1,class T2,class T3> void debug(T1 e1,T2 e2,T3 e3){cout<<e1<<"\t"<<e2<<"\t"<<e3<<endl;}
template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}
//}
template <class T> T gcd(T a,T b){if(b==0) return a;else return gcd(b,a%b);}
template <class T> T lcm(T a,T b){return (a*b)/gcd(a,b);}
template <class T> T power( T a, T b){if(b==0) return 1; T x=a;for(T i=2;i<=b;i++) a=a*x;return a;}
template <class T> T BigMod(T a,T b,T c){if(a==0) return 0;if(b==0) return 1;if(b%2==0){T x=BigMod(a,b/2,c)%c;return (x*x)%c;}else return  ((a%c)*BigMod(a,b-1,c)%c)%c;}

bool isVowel(char ch){ch=tolower(ch);if(ch=='a' | ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}

/*................Code Starts Here................*/

struct info {
    double x, y;
}gr[107], hole[107];
int n, m, cx[107], cy[107], vis[107];
vector<int>graph[107];

bool dfs(int u) {
    for(int i=0;i<graph[u].size();i++) {
        int v=graph[u][i];
        if(!vis[v]) {
            vis[v] = true;
            if(cy[v]==-1||dfs(cy[v])) {
                cy[v]=u;
                cx[u]=v;
                return true;
            }
        }
    }
    return false;
}
int BPM() {
    int ans=0;
    for(int i=0;i<n;i++) cx[i] = cy[i] = -1;

    for(int i=0;i<n;i++) {
        if(cx[i]==-1) {
            memset(vis, false, sizeof(vis));
            if(dfs(i))
                ans++;
        }
    }
    return ans;
}

double line_dist(double x, double y, double x1, double y1) {
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}

int main() {
    freopen("input.txt","r",stdin);
    int s, v, i, j;
    while(scanf("%d %d %d %d",&n, &m, &s, &v)!=EOF) {
        for(i=0;i<n;i++) {graph[i].clear(); scanf("%lf %lf",&gr[i].x, &gr[i].y); }
        for(i=0;i<m;i++) scanf("%lf %lf",&hole[i].x, &hole[i].y);

        for(i=0;i<n;i++) {
            for(j=0;j<n;j++) {
                double dist = line_dist(gr[i].x, gr[i].y, hole[j].x, hole[j].y);
                if(s*v >= dist) graph[i].push_back(j);
            }
        }

        printf("%d\n",n-BPM());
    }
    return 0;
}
