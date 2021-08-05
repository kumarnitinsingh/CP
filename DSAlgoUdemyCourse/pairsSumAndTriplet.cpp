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

vector<int> pairs(vector<int> v,int s,int index){
	vector<int>ans;
	int i=index;int j=v.size()-1;
	while(i<j){
		if((v[i]+v[j])==s){
			ans.push_back(v[i]);
			ans.push_back(v[j]);
			return ans;
		}
		else if((v[i]+v[j])>s)j--;
		else i++;
	}
	return {};
}

vector<vector<int>> solve(vector<int> v, int s){
	vector<vector<int>>ans;
	 sort(v.begin(),v.end());

	 for(int i=0;i<v.size();i++){
	 	int x=v[i];
	 	vector<int>res=pairs(v,s-x,i+1);
	 	if(res.size()==2 ){vector<int>o={x,res[0],res[1]};
	 	ans.push_back(o);
	 	}

	 }

	 return ans;
}


int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here

   int n,s;
   cin>>n>>s;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
     vector<vector<int>>ans=solve(v,s);

     for(int i=0;i<ans.size();i++){
     	for(auto x:ans[i]){
     		cout<<x<<" ";
     	}
     	cout<<endl;
     }
     
     // vector<int>ans=pairs(v,s,0);
     //  if(ans.size()==2){cout<<ans[0]<<" "<<ans[1];}
   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}