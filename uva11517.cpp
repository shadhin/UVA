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
//}

#define INF (1<<29)
#define ll long long

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

int dp[30000+7];
bool vis[30000+7];

int main ()
{
    freopen("input.txt","r",stdin);
    int t, coin[107], i, n, value, j, k;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&value,&n);
        for(i=0;i<n;i++) scanf("%d",&coin[i]);

        for(i=0;i<=20000;i++) { vis[i] = false; dp[i] = INF;}
        dp[0] = 0;
        vis[0] = true;

        for(i=0;i<n;i++) {
            //map<int,bool>mp;
            for(j=20000;j>=0;j--) {
                if(vis[j]&&(j+coin[i])<=20000&&dp[j+coin[i]]>(dp[j]+1)) {
                    dp[j+coin[i]] = dp[j]+1;
                    //cout<<coin[i]<<"  "<<j<<"   "<<dp[j+coin[i]]<<endl;
                    //mp[j+coin[i]] = true;
                    vis[j+coin[i]] = true;
                }
            }
        }
        for(i=value;i<=20000;i++) {
            if(dp[i]!=INF) {
                printf("%d %d\n",i,dp[i]);
                break;
            }
        }
        //while(dp[value]==INF) value++;
        //cout<<value<<" "<<dp[value]<<endl;
    }
    return 0;
}
