#include<bits/stdc++.h>
using namespace std;

#define Good_Luck ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pb push_back
#define pp pop_back
#define pf push_front
#define ub upper_bound
#define lb lower_bound
#define lNT_MAX 2147483647
#define LL_MAX 1e18
#define MP make_pair
#define YES cout<<"YES\n"
#define NO  cout<<"NO\n"
#define endl "\n"
//#define N 200005

ll Ans(ll n)
{
    ll ans=1;
    while((n-1)!=0) ans*=(n-1),n--;
    return ans;
}

int main()
{
    Good_Luck;
    ll T,t;
    cin>>T;
    //for(ll t=1;t<=T;t++){
    while(T--){
        ll n,m,i,k,j,in,q;
        vector<ll>v,vv;
        set<ll>ms;
        map<ll,ll>mp;
        string s;
        cin>>n;
        ll sum=0;
        for(i=0;i<n;i++)
        {
            cin>>in,sum+=in;
            v.pb(in);
            mp[in]++;
        }
        float f=sum*2.0/n;
        k=f;
        //cout<<k<<" "<<f<<endl;
        if(k!=f) cout<<"0"<<endl;
        else
        {
            ll sum=0;
            for(i=0;i<v.size();i++)
            {
                if(mp[v[i]] && mp[k-v[i]])
                {
                    mp[v[i]]--;
                    sum+=mp[k-v[i]];
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}