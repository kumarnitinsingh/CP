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

node * Merge(node *a,node *b){
	if(a==NULL)return b;
	if(b==NULL)return a;
	node *c;
	if(a->data<b->data){
		c=a;
		c->next=Merge(a->next,b);
	}
	else {
		c=b;
		c->next=Merge(a,b->next);
	}
	return c;
}
node* FindMid(node *head){
	node *s=head;
	node* f=head;

	while(f){
		f=f->next;
		if(f)=f->next;
		if(f)s=s->next;
	}
	return s;
}

node* MergeSort(node* head){
	if(head==NULL or head->next==NULL)return head;

	node* mid=FindMid(head);
	node* a=head;
	node* b=mid->next;
	mid->next=NULL;
	a=MergeSort(a);
	b=MergeSort(b);

	return Merge(a,b);
}

int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here





   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}