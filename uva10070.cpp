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
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
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
//}

int l;
string str;

bool div(int x)
{
        int i,temp=0;
        for(i=0;i<l;i++) {
                temp=temp*10+str[i]-48;
                if(temp>=x) temp%=x;
        }
        if(temp) return false;
        return true;
}

int main () {

        int s=0;
        while(cin>>str)
        {
                if(s) printf("\n"); s=1;
                l = str.length();
                if(div(400)||!div(100)&&div(4)||div(15))
                {
                        if(div(400)||!div(100)&&div(4)) { printf("This is leap year.\n");}
                        if(div(15)) { printf("This is huluculu festival year.\n");}
                        if((div(400)||!div(100)&&div(4)) &&div(55)) { printf("This is bulukulu festival year.\n");}
                }
                else printf("This is an ordinary year.\n");
        }
        return 0;
}
