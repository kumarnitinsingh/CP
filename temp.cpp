// Created by Nitin kumar singh
// problem link ->

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


ll solve(vector<ll>timeRec,vector<ll>timeHave,ll n,ll total,vect &v){
	if(n==0)return 0;

	ll ans=INT_MIN;
	if(timeRec[n-1]<=timeHave[n-1] and timeHave[n-1]>=total){
		ll op1=solve(timeRec,timeHave,n-1,total,v);
		ll op2=	1+solve(timeRec,timeHave,n-1,total+timeRec[n-1],v);
		if(op2>op1){
			v.push_back({n,total,total+timeRec[n-1]});
		}
		else v.pop_back();
		ans=max(op2,op1);
	}
	else ans=solve(timeRec,timeHave,n-1,total,v);

	return ans;
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
       	   vector<ll>timeRec(n),timeHave(n);
       	   loop(i,n)cin>>timeRec[i];
       	   loop(i,n)cin>>timeHave[i];

       	   	vect v;
       	   	
       	   ll ans=solve(timeRec,timeHave,n,0,v);

       	   cout<<ans<<endl;
       	   for(int i=0;i<v.size();i++){
       	   	 cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
       	   }
       }




   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}