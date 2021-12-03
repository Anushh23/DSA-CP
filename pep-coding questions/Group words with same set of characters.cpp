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
        ll n;
        cin>>n;
        string s[n];
        map<string,vector<string>>mp;
        for(i=0;i<n;i++)
        {
            cin>>s[i]; 
            string p=s[i],k="";
            sort(all(p));
            k+=p[0];
            for(j=1;j<p.size();j++)
            {
                if(p[j]!=p[j-1]){k+=p[j];}
            }
            mp[p].push_back(s[i]);
        }
        for(auto u:mp)
        {
            for(auto v:u.S)
            {
                cout<<v<<", ";
            }
            cout<<"\n";
        }
    }

}
