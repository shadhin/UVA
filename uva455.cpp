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

#define INF 1<<29
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


int main () {

    int n, len;
    char str[90];
    scanf("%d", &n);
    while (n--) {
        scanf("%s", &str);
        len = strlen(str);
        for (int i = 1; i <= len; ++i) {
            if (len % i == 0) {
                bool ok = true;
                for (int j = i; j < len; ++j) {
                    if (str[j] != str[j % i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    printf("%d\n", i);
                    if (n) puts("");
                    break;
                }
            }
        }
    }

    return 0;
}
/*
string str;
int l, cnt;

bool check (int a, int b)
{
        int i = a, d = b+1, track;
        while(d<l)
        {
                for(track=0;track<=(b-a);track++) {
                        if(str[i++]!=str[d++]) return false;
                }

                cnt++;

                i=a;
        }

        return true;
}
int main ()
{
        int i, t;
        scanf("%d",&t);

        while(t--)
        {
                cin>>str;
                l = str.size();

                int mn = 99999;
                for(i=0;i<l;i++)
                {
                        cnt = 0;
                        if(check(0,i)&&mn>cnt) {
                                if(cnt>0)
                                        mn = cnt;
                        }
                }

                cout<<cnt+1<<endl;
                if(t) cout<<endl;
        }
        return 0;
}
*/

