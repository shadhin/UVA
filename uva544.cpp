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
template <class T, class U> inline T swap (T &a, U &b) { T tmp = a; a = b; b = tmp; }

bool isVowel(char ch){ch=tolower(ch);if(ch=='a' | ch=='e' || ch=='i' || ch=='o' || ch=='u')return true;return false;}

///int dx[]= {-1,-1,0,0,1,1};
///int dy[]= {-1,0,-1,1,0,1};
///int dx[]= {0,0,1,-1};/*4 side move*/
///int dy[]= {-1,1,0,0};/*4 side move*/
///int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
///int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/
/*................Code Starts Here................*/

struct edge {
    int u,v,w;

    bool operator < ( const edge& p ) const {
        return w > p.w;
    }
};

vector<edge>graph;
int n,parent[207];

int parent_find(int u) {
    return (u == parent[u])? u : parent_find(parent[u]);
}

int mst(int src, int des) {
    int i, sz = graph.size(), cnt = 0;

    sort(graph.begin(), graph.end());

    for(i=0; i<=n; i++) parent[i] = i;

    int ret = 0;
    for(i=0; i<sz; i++) {
        int u=parent_find(graph[i].u);
        int v=parent_find(graph[i].v);

        if(u != v) {
            parent[u]=v;
            cnt++;

            if(parent_find(src) == parent_find(des)) {
                ret = graph[i].w;
                break;
            }
        }

        if(ret != 0 || cnt == n-1) break;
    }

    return ret;
}

int main() {
    freopen("input.txt","r",stdin);
    int r, i, Case = 1;

    while(scanf("%d %d", &n, &r)) {
        if(n == 0 && r == 0) break;

        map<string, int>mp;
        string str1, str2;
        int idx = 0;

        for(i=0; i<r; i++) {

            int w;
            cin>>str1>>str2>>w;

            if(mp[str1] == 0) mp[str1] = idx++;
            if(mp[str2] == 0) mp[str2] = idx++;

            edge e;

            e.u = mp[str1];
            e.v = mp[str2];
            e.w = w;

            graph.push_back(e);

        }

        cin>>str1>>str2;

        printf("Scenario #%d\n%d tons\n\n", Case++, mst(mp[str1], mp[str2]));

        graph.clear();
    }

    return 0;
}
