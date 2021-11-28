#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl "\n"
#define ii pair<ll,ll>
#define ic pair<char,ll>
#define pb push_back
#define vi vector<ll>
#define popb pop_back
#define all(v) (v).begin(), (v).end()
#define F first
#define S second
const int N=3*1e5+10;
ll M= 1e9+7;
long long lcm(ll a, ll b)
{
    return (a / __gcd(a, b)) * b;
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
ll a,b,c,k;
ll func(ll x)
{
    ll pp= a*x*x+b*x+c;
    return pp;
}
int main()
{
    fast;
    ll tt=1,i,j,num;
    cin>>tt;
    sos:
    while(tt--)
    {
       cin>>a>>b>>c>>k;
       ll l=0,h=ceil((double)sqrt(k));
       if(func(l)>=k)
       {
           cout<<l<<"\n";continue;
       }
       while(l<=h)
       {
           ll mid=(l+h)/2;
           if(func(l)>=k)
           {
               cout<<l<<"\n";goto sos;
           }
           if(func(mid)==k)
           {
               cout<<mid<<"\n";goto sos;
           }
           else if(func(mid+1)>k&&func(mid)<k)
           {
               cout<<mid+1<<"\n";goto sos;
           }
           else if(func(mid)>k)
           {
               h=mid-1;
           }
           else
           {
               l=mid+1;
           }
       }

    }

}
