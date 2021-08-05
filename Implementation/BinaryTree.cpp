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



class node{
	public:
node* lchild;
int data;
node* rchild;

}*root=NULL;


//inserting in binary tree;

void Insert(node* t,int data){
node *p;
queue<node*>q;
if(!t){
	t=new node;
	t->data=data;
	t->lchild=NULL;
	t->rchild=NULL;
	root=t;
	q.push(t);

}
while(!q.empty()){
	p=q.front();q.pop();
	cout<<"enter left child of "<<p->data<<endl;
	int x;
	cin>>x;
	if(x!=-1){
	node* temp=new node;
	temp->data=x;
	temp->lchild=NULL;
	temp->rchild=NULL;
	p->lchild=temp;
	q.push(temp);}
	cout<<"enter right child of"<<p->data<<endl;
	int y;
	cin>>y;
	if(y!=-1){
		node* temp=new node;
		temp->data=y;
		temp->lchild=NULL;
		temp->rchild=NULL;
		p->rchild=temp;
		q.push(temp);
	}

}

}


void Search(node *t,int data){

if(t){
if(t->data==data)cout<<"found "<<data;
Search(t->lchild,data);
Search(t->rchild,data);
}
}

void Preorder(node* t){
if(t){
	cout<<t->data<<" ";
	Preorder(t->lchild);
	Preorder(t->rchild);
}
}

void Inorder(node* t){
if(t){
  Inorder(t->lchild);
  cout<<t->data<<" ";
  Inorder(t->rchild);
}
}

void Postorder(node* t){
if(t){
  Postorder(t->lchild);
  Postorder(t->rchild);
  cout<<t->data<< " ";
}
}


int Count(node* t){
	if(!t)return 0;

	int x=Count(t->lchild);
	int y=Count(t->rchild);
	return x+y+1;

}

int height(node* t){
if(!t)return -1;

int x=height(t->lchild);
int y=height(t->rchild);
return x>y?x+1:y+1;

}


void levelorder(node* t){
	queue<node*> q;
if(t){
	cout<<t->data<<" ";
	q.push(t);
}
while(!q.empty()){
	node* temp=q.front();q.pop();
	if(temp->lchild){
	cout<<temp->lchild->data<<" ";
	q.push(temp->lchild);}
	if(temp->rchild){
	cout<<temp->rchild->data<<" ";
	  q.push(temp->rchild);
	}
}

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