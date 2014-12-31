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
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define INF 1<<29
#define ll long long
#define db double
#define pii pair<int ,int >
#define NL puts("")
#define G getchar()

template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}
//}

//compute b^p
ll Pow(ll  b,ll  p){
    ll  ret = 1;
    while(p){
        if(p&1) ret *= b ;
        p >>= (1ll) , b *= b ;
    }
    return ret ;
}

//compute b^p%m
ll BigMod(ll  b,ll  p ,ll  m ){
     ll  ret = 1 ;
     while(p)  {
        if(p&1) ret = (ret * b ) % m ;
        p >>= (1ll) , b = (b*b)%m ;
     }
    return ret ;
}

//compute gcd of (a,b)
ll GCD(ll a , ll b){
    while(b) b ^=  a ^= b ^= a %= b ;
    return a;
}

//compute lcm of (a,b)
ll LCM(ll a , ll b) {
     return (a / GCD(a,b)*b);
}

ll power(ll n,ll m)
{
    ll ans=1,p=n;
    while(m)
    {
        if(m&1) ans*=p;
        p*=p;
        m=m>>1;
    }
    return ans;
}


int main ()
{
        int Case = 1, n, m, c, sum, mx, i, no, pwr[25];
        bool onf[25];

        while(scanf("%d %d %d",&n,&m ,&c))
        {
                if(n==0&&m==0&&c==0) break;

                for(i=0;i<n;i++) {
                        scanf("%d",&pwr[i]);
                        onf[i] = false;
                }

                bool fuse = false;
                sum = 0;
                mx = -1;

                for(i=0;i<m;i++)
                {
                        scanf("%d",&no);
                        no--;
                        if(onf[no])
                        {
                                sum-=pwr[no];
                                onf[no] = false;
                        }
                        else
                        {
                                onf[no] = true;
                                sum+=pwr[no];
                                if(sum>c) fuse = true;

                                mx = max(mx, sum);
                        }
                }

                printf("Sequence %d\n",Case++);

                if(fuse)
                {
                        printf("Fuse was blown.\n");
                }
                else
                {
                        printf("Fuse was not blown.\n");
                        printf("Maximal power consumption was %d amperes.\n",mx);
                }

                cout<<endl;
        }
        return 0;
}
