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

///int dx[]= {-1,-1,0,0,1,1};
///int dy[]= {-1,0,-1,1,0,1};
///int dx[]= {0,0,1,-1};/*4 side move*/
///int dy[]= {-1,1,0,0};/*4 side move*/
///int dx[]= {1,1,0,-1,-1,-1,0,1};/*8 side move*/
///int dy[]= {0,1,1,1,0,-1,-1,-1};/*8 side move*/
///int dx[]={1,1,2,2,-1,-1,-2,-2};/*knight move*/
///int dy[]={2,-2,1,-1,2,-2,1,-1};/*knight move*/
/*................Code Starts Here................*/

int cnt;
void rec(int temp) {
    cnt++; int sum = 0;
    while(temp) {
        sum += temp%10;
        temp/=10;
    }

    if(sum==9) return;
    rec(sum);
}

int main() {
    //freopen("input.txt","r",stdin);
    string str;
    while(cin>>str&&str[0]!='0') {
        int temp = 0, i, l = str.size();
        for(i=0;i<l;i++) temp += (str[i]-'0');

        if(temp%9) cout<<str<<" is not a multiple of 9."<<endl;
        else {
            cnt = 1;
            if(temp>9) rec(temp);
            cout<<str<<" is a multiple of 9 and has 9-degree "<<cnt<<"."<<endl;
        }
    }
    return 0;
}
