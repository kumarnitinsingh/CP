
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

int RodCutting(vector<int> p,int n){
	if(n==0)return 0;

	int q=-9999;
	for(int i=1;i<=n;i++){
		q=max(q,p[i]+RodCutting(p,n-i));
	}

	return q;
}



int TopDownDp(vector<int> p,int n,vector<int> r){
	if(r[n]>=0)return r[n];
	int q;
	if(n==0)q=0;
	else q=-999;
	for(int i=1;i<=n;i++){
		q=max(q,p[i]+TopDownDp(p,n-i,r));
	}
	r[n]=q;

	return q;
}

int TopDown(vector<int>p,int n){
	vector<int>r(n+1,-999);
	return TopDownDp(p,n,r);

}

int BottomUpDp(vector<int>p,int n){
	vector<int>r(n+1,0);
	
	for(int j=1;j<=n;j++){
        int q=-999;
		for(int i=1;i<=j;i++){
			q=max(q,p[i]+r[j-i]);
		}
		r[j]=q;
	}
return r[n];
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here

     int n;
     cin>>n;
     vector<int>p(n+1);
     for(int i=1;i<=n;i++){
     	cin>>p[i];
     }

     cout<<"Max profit "<<BottomUpDp(p,10);


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}