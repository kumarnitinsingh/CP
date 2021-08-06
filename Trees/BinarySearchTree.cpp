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

class node{
  public:
  	int data;
  	node* left;
  	node* right;
  	node(int value){
  		data=value;
  		left=NULL;
  		right=NULL;
  	}
};

//---------------------------------------------------------------------------------------------------------------------------

node* InsertBST(node* root,int value){
	if(root==NULL){
		return new node(value);
	}
	if(root->data==value)return NULL;
	if(root->data>value)root->left=InsertBST(root->left,value);
	else if(root->data<value)root->right=InsertBST(root->right,value);

	return root;
}

//---------------------------------------------------------------------------------------------------------------------------

node* BSTSearch(node* root ,int value){
	if(root==NULL)return NULL;
	if(root->data==value)return root;
	if(root->data>value)return BSTSearch(root->left,value);
	return BSTSearch(root->right,value);
}


//--------------------------------------------------------------------------------------------------------------------------

node* InorderSuccessor(node* root){

	while(root and root->left!=NULL){
		root=root->left;
	}
	return root;
}

//-------------------------------------------------------------------------------------------------------------------------

node* DeleteBST(node* root,int value){
	if(root==NULL)return NULL;
	if(root->data>value)root->left=DeleteBST(root->left,value);
	else if(root->data<value)root->right=DeleteBST(root->right,value);
	else{
        //if leaf node
        if(root->left==NULL and root->right==NULL){
        	delete root;
        	return NULL;
 
        }
        //if(left child is null)
        if(root->left==NULL){
        	node* temp=root->right;
        	delete root;
        	return temp;
        }
        // if(right child is null)
        if(root->right==NULL){
        	node* temp=root->left;
        	delete root;
        	return temp;
        }
        node* temp=InorderSuccessor(root->right);
        root->data=temp->data;
         root->right=DeleteBST(root->right,temp->data);

	}
	return root;
}

//------------------------------------------------------------------------------------------------------------------------------

node* BSTUsingPreorder(int preorder[],int *preorderidx,int key,int min,int max,int n){
    if(*preorderidx>=n)return NULL;
    node* root=NULL;
     if(min<key and key<max){
        root=new node(key);
        
        *preorderidx=*preorderidx+1;

        if(*preorderidx<n)root->left=BSTUsingPreorder(preorder,preorderidx,preorder[*preorderidx],min,key,n);
        if(*preorderidx<n)root->right=BSTUsingPreorder(preorder,preorderidx,preorder[*preorderidx],key,max,n);
     }  

    return root;
}


//-----------------------------------------------------------------------------------------------------------------------------

bool isBST(node* root,node* min=NULL,node* max=NULL){
    if(root==NULL )return true;
    if(min!=NULL and root->data<=min->data)return false;
    if(max!=NULL and root->data>=max->data)return false;

    bool left=isBST(root->left,min,root);
    bool right=isBST(root->right,root,max);
    return left and right;
}

//----------------------------------------------------------------------------------------------------------------------------

 node* buildTree(){
     int x;
     cin>>x;
     if(x==-1)return NULL;
     node* n=new node(x);
     n->left=buildTree();
     n->right=buildTree();
     return n;
   }



  node* LevelOrderBuild(){
    queue<node*>q;
    node* root;
    int x;
    cin>>x;
    root=new node(x);
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
         q.pop();
         int x,y;
         cin>>x;
         if(x!=-1){
         node* left=new node(x);
         temp->left=left;
         q.push(left);
        }
         cin>>y;
         if(y!=-1){
             node* right=new node(y);
         temp->right=right;
         q.push(right);
         }
    }
    return root;
  } 

  //-------------------------------------------------------------------------------------------------------------------------------

   node* buildBstUsingSortedArray(vector<int>v,int s,int e){
    if(s>e)return NULL;
       int mid=(s+e)/2;
       node*root=new node(v[mid]);
       root->left=buildBstUsingSortedArray(v,s,mid-1);
       root->right=buildBstUsingSortedArray(v,mid+1,e);
       return root;

   }

//--------------------------------------------------------------------------------------------------------------------------------

ll catalan(ll n){
    if(n<=1)return 1;
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=catalan(i)*catalan(n-i-1);
    }
    return ans;
}

//-------------------------------------------------------------------------------------------------------------------------------

vector<node*> ConstructAllBST(int start,int end){
    vector<node*>trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
   for(int i=start;i<=end;i++){
         vector<node*>leftTree=ConstructAllBST(start,i-1);
         vector<node*>rightTree=ConstructAllBST(i+1,end);

         for(int j=0;j<leftTree.size();j++){
            node*left=leftTree[j];
            for(int k=0;k<rightTree.size();k++){
                node*right=rightTree[k];
                node* root= new node(i);
                root->left=left;
                root->right=right;
                trees.push_back(root);
            }
         }
   }
  return trees;
}

//-------------------------------------------------------------------------------------------------------------------------------

int findClosestInBst(node* root,int target){
    int minimum=INT_MAX;
     int closest;

    while(root!=NULL){
        if(root->data==target)return root->data;

        int curr_diff=abs(root->data-target);
        if(curr_diff<minimum){
            minimum=curr_diff;
            closest=root->data;
        }
        if(root and root->data<target){
           
            root=root->right;

        }
        if(root and root->data>target){
           
            root=root->left;
        }
    }
    return closest;
}

//------------------------------------------------------------------------------------------------------------------------------

class linkedList{
public:
    node* head;
    node* tail;
};

linkedList TreeToLinkedList(node* root){
    linkedList ls;
    if(root==NULL){
        ls.head=NULL;
        ls.tail=NULL;
        return ls;
    }

      if(root->left==NULL and root->right==NULL){
        ls.head=root;
        ls.tail=root;
        return ls;
      }
     if(root->left!=NULL and root->right!=NULL){
       
     linkedList left=TreeToLinkedList(root->left);
     linkedList right=TreeToLinkedList(root->right);

       left.tail->right=root;
       root->right=right.head;
       ls.head=left.head;
       ls.tail=right.tail;
     } 
     else if(root->left!=NULL){
         linkedList left=TreeToLinkedList(root->left);
          left.tail->right=root;
          ls.head=left.head;
          ls.tail=root;
     }   
     else if(root->right!=NULL){
        linkedList right=TreeToLinkedList(root->right);
          root->right=right.head;
          ls.head=root;
          ls.tail=right.tail;
     }   

    return ls;
}

//----------------------------------------------------------------------------------------------------------------------------

node* InorderSucc(node* root,node* target){
    //if right subtree exist;
    if(root->right!=NULL){
        node* temp=root->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }

    node* succ=NULL;
    node* temp=root;
    while(temp!=NULL){
    if(temp->data>target->data){
        succ=temp;
        temp=temp->left;
    }
    else if(temp->data<target->data){ temp=temp->right;}
    else break;
}
    return succ;

}

void Inorder(node* root){
	if(root==NULL)return;

	Inorder(root->left);
    cout<<root->data<<" ";	
	Inorder(root->right);
}
int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
    node* root=NULL;
    root=InsertBST(root,5);
    	InsertBST(root,1);
      	InsertBST(root,3);
        InsertBST(root,4);
        InsertBST(root,2);
        InsertBST(root,7);
        InsertBST(root,5);

          root=DeleteBST(root,8);
          Inorder(root);
            cout<<endl;     
          int n;cin>>n;
          vector<int>v(n);
          loop(i,n)cin>>v[i];
      
        node* myroot=TreeToLinkedList(root).head;

        while(myroot){
            cout<<myroot->data<<" ";
            myroot=myroot->right;
        }

        


   
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}