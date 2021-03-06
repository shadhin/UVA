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

int main ()
{
        double x1, y1, x2, y2, x3, y3, x4, y4, x, y;

        while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)==8)
        {
                if(x3==x4&&y3==y4){
                        x = x2+(x1-x3);
                        y = y2+(y1-y3);
                }
                else if(x4==x1&&y4==y1){
                        x = x3+(x2-x1);
                        y = y3+(y2-y1);
                }
                else if(x1==x2&&y1==y2){
                        x = x3+(x4-x1);
                        y = y3+(y4-y1);
                }
                else if(x1==x3&&y1==y3){
                        x = x2+(x4-x1);
                        y = y2+(y4-y1);
                }
                else if(x2==x3&&y2==y3){
                        x = x1+(x4-x2);
                        y = y1+(y4-y2);
                }

                else {
                        x = x1+(x3-x2);
                        y = y1+(y3-y2);
                }

                printf("%.3lf %.3lf\n",x,y);
        }

        return 0;
}

