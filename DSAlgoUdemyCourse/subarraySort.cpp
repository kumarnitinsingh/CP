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

vector<int>solve(vector<int> v, int n){
	vector<int> b(v);
	sort(b.begin(),b.end());
	int i=0;
	int j=n-1;
	while(i<n and v[i]==b[i])i++;
	while(j>=0 and v[j]==b[j])j--;
	if(i==v.size())return {-1,-1};
	return {i,j};
}

vector<int>solve2(vector<int> v,int n){
	int smallest=INT_MAX;
	int largest=INT_MIN;

	for(int i=1;i<n-1;i++){
		if(v[i-1]>v[i] || v[i]>v[i+1]){
			smallest=min(v[i],smallest);

			largest=max(largest,v[i]);
		}
	}
	int j=0;
	int k=n-1;
	if(smallest==INT_MAX)return{-1,-1};
	
		while(j<n and v[j]<smallest)j++;
	
	
		while(k>=0 and v[k]>largest)k--;
	
     

	return {j,k};
}
int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
      int n;
      cin>>n;
      vector<int>v(n);
      for(int i=0;i<n;i++)cin>>v[i];

      	vector<int> ans=solve2(v,n);
       cout<<ans[0]<<" "<<ans[1];



   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}