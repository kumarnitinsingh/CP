// Created by Nitin
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


//node structure
class node{
public:
	node* lchild;
	int data;
	node* rchild;
}*root=NULL;


//search for key
int Search(node* t,int key){

if(t){
if(t->data==key)return 1;
if(t->data>key)Search(t->lchild,key);
else Search(t->rchild,key);
}

}


//node insertion
node* Insert(node* t,int data){
if(Search(t,data)==1)return NULL;
node* p;
if(!t){
	p=new node;
	p->data=data;
	p->lchild=NULL;
	p->rchild=NULL;
	if(!root)root=p;
	return p;
}
if(t->data>data){
	t->lchild=Insert(t->lchild,data);
}
else{
	t->rchild=Insert(t->rchild,data);
}
return t;

}

//inorder or sorted order
void Inorder(node* t){

if(t){

	Inorder(t->lchild);
	cout<<t->data<<" ";
	Inorder(t->rchild);

}
}


//height of binary searchTree
int height(node* t){
if(t==NULL)return -1;
int x=height(t->lchild);
int y =height(t->rchild);
return x>y?x+1:y+1;
}

//inorder predecessor
node* Inpre(node* t){
	//if(t)t=t->lchild;
while(t and t->rchild){
	t=t->rchild;
}
return t;

}

//inorder successor
node* Insucc(node* t){
	//if(t)t=t->rchild;
while(t and t->lchild){
	t=t->lchild;
}
return t;
}

//deleting node
node* Delete(node* t,int data){
node *q;
if(t==NULL)return NULL;
if( t->lchild==NULL and t->rchild==NULL){
	if(t==root)root=NULL;
	delete t;
	return NULL;
}
if(data<t->data)t->lchild=Delete(t->lchild,data);
else if(data>t->data){
	t->rchild=Delete(t->rchild,data);
}
else{
	if(height(t->lchild)>height(t->rchild)){
		q=Inpre(t->lchild);
		t->data=q->data;
		t->lchild=Delete(t->lchild,q->data);
	}
	else{
		q=Insucc(t->rchild);
		t->data=q->data;
		t->rchild=Delete(t->rchild,q->data);
	}
}
return t;

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