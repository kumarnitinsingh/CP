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

ll solve(vector<ll>v,ll n){
	unordered_map<ll,ll>m;

	for(int i=0;i<n;i++){
		ll no=v[i];
		if(m.count(no-1)==0 and m.count(no+1)==0){
			m[no]=1;
		}
		else if(m.count(no-1) and m.count(no+1)){
			ll len1=m[no-1];
			ll len2=m[no+1];
			ll streak=len1+1+len2;
			m[no-len1]=streak;
			m[no+len2]=streak;
		}
		else if(m.count(no-1) and m.count(no+1)==0){
			ll len1=m[no-1];
			m[no-len1]=len1+1;
		}
		else if(m.count(no+1) and m.count(no-1)==0){
			ll len2=m[no+1];
			m[no+len2]=len2+1;
		}
	}

	ll ans=INT_MIN;
	for(auto p:m){
		ans=max(ans,p.second);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
     clock_t start=clock();
     init_code();
    
     //write your code here

     	ll n;
     	cin>>n;
     	vector<ll>v(n);
     	loop(i,n)cin>>v[i];
     	ll ans=solve(v,n);
     	cout<<ans<<endl;



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}