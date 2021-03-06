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

#define N 500
bool prime[N];
vector<int>primes;

void sieve()
{
        int i,j,sqr = sqrt(N);
        prime[0]=prime[1]=true;

        primes.push_back(2);
        for(i=4;i<N;i+=2)
                prime[i]=true;

        for(i=3;i<sqr;i+=2)
        {
                if(prime[i]==false)
                {
                        primes.push_back(i);
                        for(j=i*i;j<N;j+=2*i)
                                prime[j]=true;
                }
        }

        while(i<N)
        {
                if(prime[i]==false)
                        primes.push_back(i);
                i+=2;
        }
}

int phi(int n)
{
        int j, sz= primes.size(), ans = n;
        for(j=0;j<sz&&primes[j]<=sqrt(n);j++)
        {
                if(n%primes[j]==0)
                {
                        ans=ans-ans/primes[j];
                        while(n%primes[j]==0) n/=primes[j];
                }

                if(n==1) break;
        }

        if(n>1) ans=ans-ans/n;
        return ans;
}

vector<ll>sol; //12,158,598,919

void pre_cal()
{
        ll i;
        sol.push_back(0);
        sol.push_back(2);
        for(i=2;i<=200000;i++){
                sol.push_back(sol[i-1]+phi(i));
        }

        //cout<<sol[i-1]<<endl;
}

int main()
{
        sieve();
        pre_cal();

        ll n, idx, i, k;
        while(scanf("%lld",&n)==1&&n)
        {
                idx = (lower_bound(sol.begin(),sol.end(),n)-sol.begin())-1;
                k = sol[idx];

                if(sol[idx]==n)
                {
                        k = idx;

                        while(GCD(idx,k)!=1) k--;
                        printf("%lld/%lld\n",k,idx);
                        continue;
                }

                //cout<<idx<<endl;

                for(i=0;i<=idx+1;i++)
                {
                        if(GCD(i,idx+1)==1) k++;
                        if(k==n) break;
                }

                printf("%lld/%lld\n",i,idx+1);
        }

        return 0;
}

