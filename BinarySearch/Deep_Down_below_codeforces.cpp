// Created by Nitin kumar singh
// problem link ->https://codeforces.com/contest/1561/problem/C

#include <bits/stdc++.h>

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/trie_policy.hpp>

using namespace std;

//using namespace __gnu_pbds;
//typedef tree <int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>Set;

//find_by_order(k) and order_of_key(k)



#define ll             long long int
#define ld             long double
#define mod            1000000007
#define inf            1e18
#define vec            vector<long long>
#define vect           vector<vector<long long>>
#define vecb           vector<vector<bool>
#define pb             push_back
#define all(n)         n.begin(),n.end()
#define loop(i,n)      for(int i=0;i<(n);++i)
#define loopa(i,a,n)    for(int i=a;i<=(n);++i)
#define loopr(i,a,n)   for(int i=a;i>=(n);--i)
#define sq(x)          x*x
#define cube(x)        x*x*x



void init_code(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

bool ispossible(vector<vector<ll>>&v,ll n,ll mid){

             for(int i=0;i<n;i++){
                vector<ll>temp=v[i];

                for(int j=0;j<temp.size();j++){
                    if(temp[j]>=mid)return false;
                     mid++;
                }
             }

            return true;
}

ll binarySearch(vector<vector<ll>>v,ll n){
    ll low=0;
    ll high=99999999999;

    ll ans=0;
    while(low<=high){
        ll mid=low+(high-low)/2;
        if(ispossible(v,n,mid)){
            ans=mid;
           
            high=mid-1;
        }
        else low=mid+1;
    }

    return ans;
}



bool mycom(vector<ll>v1,vector<ll>v2){
  
     ll val=0;
     for(ll j=0;j<v1.size();++j)
        {
            ll s;
            s=v1[j];
            
            val=max(val,s-j+1);
        }

        ll val2=0;
         for(ll j=0;j<v2.size();++j)
        {
            ll s;
            s=v2[j];
            
            val2=max(val2,s-j+1);
        }
                      

                ll enter1=val;
                ll leave1=enter1+(v1.size());

                 ll enter2=val2;
                ll leave2=enter2+(v2.size());

                if(enter1<enter2)return true;
                if(enter2==enter1 and leave1>leave2)return true;
                return false;
             
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     ll t;
     cin>>t;
     while(t--){
        ll n;cin>>n;
        vector<vector<ll>>v;
        
        for(int i=1;i<=n;i++){
            ll k;cin>>k;
            vector<ll>temp(k);
            loop(i,k)cin>>temp[i];
            v.push_back(temp);
        }

        sort(v.begin(),v.end(),mycom);      
       ll ans=binarySearch(v,n);
        cout<<ans<<endl;

       
}


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}