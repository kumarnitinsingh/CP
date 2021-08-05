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


void BuildTree(vector<int>& tree,vector<int> &v,int ss,int se,int index){
//considering leaf in base case
	if(ss==se){
		tree[index]=v[ss];
		return;
	}

	int mid=(ss+se)/2;
	//left subtree
	BuildTree(tree,v,ss,mid,2*index);
	//right subtree
	BuildTree(tree,v,mid+1,se,2*index+1);
	//updating current node with minimum of left and right subtree
	//tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
  

}


int Query(vector<int> &tree,int ss,int se,int l,int h,int index){
 
 //complete overlap
	if(ss>=l and se<=h )return tree[index];

	//no overlap
	if(h<ss || l>se)return INT_MAX;

	//partial overlap
	int mid=(ss+se)/2;
	int left=Query(tree,ss,mid,l,h,2*index);
	int right=Query(tree,mid+1,se,l,h,2*index+1);
	return min(left,right);


}

void UpdateTree(vector<int> &tree,int ss,int se,int l,int r,int inc,int index){
 //out of bound
	if(l>se || r<ss)return;

  //updating leaf nodes;

 if(ss==se){tree[index]+=inc;return;}

 int mid=(ss+se)/2;
 UpdateTree(tree,ss,mid,l,r,inc,2*index);
 UpdateTree(tree,mid+1,se,l,r,inc,2*index+1);
 tree[index]=min(tree[2*index],tree[2*index+1]);
 return;

}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
    
    int n,q;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<int>tree(4*n,0);
     BuildTree(tree,v,0,n-1,1);

     for(int i=1;i<3*n;i++){
     	cout<<tree[i]<<" ";
     }
   UpdateTree(tree,0,n-1,2,4,-5,1);

    int l,r;
    cin>>l>>r;
    cout<<endl<<Query(tree,0,n-1,l,r,1);

   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}