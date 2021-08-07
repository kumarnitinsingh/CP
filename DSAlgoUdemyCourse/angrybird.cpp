// Created by Nitin kumar singh
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/trie_policy.hpp>


//using namespace_-gnu_pbds;
using namespace std;

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

bool canPlace(vector<int>v,int n,int b,int diff){
    int bird_placed_so_far=1;
    int lastlocation=v[0];
    for(int i=1;i<n;i++){
        int current_location=v[i];
        if(current_location-lastlocation>=diff){
            bird_placed_so_far++;
            lastlocation=current_location;
            if(bird_placed_so_far==b)return true;
        }
        
    }

    return false;
}
int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
    int n,b;
    cin>>n>>b;
    vector<int>v(n);
    loop(i,n)cin>>v[i];
    sort(v.begin(),v.end());
    int s=v[0];int e=v[n-1];
    int ans=0;
    while(s<=e){
        int mid=(s+e)/2;
        if(canPlace(v,n,b,mid)){
            ans=mid;
            s=mid+1;
        }
        else e=mid-1;
    }

    cout<<ans<<endl;



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}