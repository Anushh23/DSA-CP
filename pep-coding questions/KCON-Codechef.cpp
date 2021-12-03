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
long long binpow(long long a, long long b) {
    a %= M;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
vector<ll>dp(1005,1);
void fac()
{
    ll fcto=1;
    for(ll i=2;i<=1000;i++)
    {
        fcto*=i;
        fcto%=M;
        dp[i]=fcto;
    }
}
ll binexp(ll a , ll b)
{
    if(a==0||a==1){return a;}
    if(b==0){return 1;}
    ll ret= binexp(a,b/2);
    if(b%2) return (((ret*ret)%M)*a)%M;
    else return (ret*ret)%M;
}
ll inv_fac(ll x)
{
    return binexp(dp[x],M-2);
}
ll ncr(ll n,ll r)
{
    return (((dp[n]*inv_fac(n-r))%M)*inv_fac(r))%M;
}
int main()
{
    fast;
    ll tt=1,i,j,num;
    cin>>tt;
    sos:
    while(tt--)
    {
        ll n,k,mx=0,sum=0;
        cin>>n>>k;
        vector<ll>a(n),dp(n),dpp(n);
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
            dp[i]=sum;
            if(i!=n-1) mx=max(mx,dp[i]);
        }
        ll suma=0,mxx=-1e18;
        for(i=n-1;i>=0;i--)
        {
            suma+=a[i];
            dpp[i]=suma;
            mxx=max(mxx,dpp[i]);
        }
        ll pp=mxx+(k-1)*sum;
        if(k>=2)
        {
            pp=max(pp,mx+mxx);
            pp=max(pp,mxx+(k-2)*sum+mx);
        }
        ll mx1=0;suma=0;
        for(i=0;i<n-1;i++)
        {
            if(suma+a[i]>=0){suma+=a[i];}
            else
            {
                suma=0;
            }
            mx1=max(mx1,suma);
        }
        if(mx1==0)
        {
            mx1=-1e18;
            for(i=0;i<n;i++)
            {
                mx1=max(mx1,a[i]);
            }
            cout<<mx1<<"\n";
        }
        else
        {
            pp=max(mx1,pp);
            cout<<pp<<"\n";
        }

    }

}
