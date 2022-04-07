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
//----------------------------------------------------------------------------------------
class node{
   public:
   	node* left;
   	int data;
   	node* right;

   	node(int d){
   		data=d;
   		left=NULL;
   		right=NULL;
   	}
   };

//---------------------------------------------------------------------------------------------
   node* buildTree(){
   	 int x;
   	 cin>>x;
   	 if(x==-1)return NULL;
   	 node* n=new node(x);
   	 n->left=buildTree();
   	 n->right=buildTree();
   	 return n;
   }

  //---------------------------------------------------------------------------------------------- 

   int MaximumValue(node* root){
   	if(root==NULL)return INT_MIN;
   	int left=MaximumValue(root->left);
   	int right=MaximumValue(root->right);

   	return max(root->data,max(left,right));
   }


   //------------------------------------------------------------------------------------------------


   int MinimumValue(node* root){
   	if(root==NULL)return INT_MAX;
   	int left=MinimumValue(root->left);
   	int right=MinimumValue(root->right);

   	return min(root->data,min(left,right));
   }

//------------------------------------------------------------------------------------------------------

   void levelorder(node* root){
   	queue<node*>q;
   	q.push(root);
   	q.push(NULL);

   	while(!q.empty()){
   		node* temp=q.front();
   		q.pop();
   		if(temp and temp->left)q.push(temp->left);
   		if(temp and temp->right)q.push(temp->right);
   		if(temp)cout<<temp->data<<" ";
   		if(!temp){
   			cout<<endl;
   			if( !q.empty())q.push(NULL);
   		}
   	}
   }

   //------------------------------------------------------------------------------------------------------

   void PreOrder(node* root){
   	if(root==NULL)return;
   	cout<<root->data<<" ";
   	PreOrder(root->left);
   	PreOrder(root->right);
   }

   //------------------------------------------------------------------------------------------------------

   void Inorder(node* root){
   	if(root==NULL)return;
   	Inorder(root->left);
   	cout<<root->data<<" ";
   	Inorder(root->right);
   }

   //-------------------------------------------------------------------------------------------------------

   void Postorder(node* root){
   	if(root==NULL)return;
   	Postorder(root->left);
   	Postorder(root->right);
   	cout<<root->data<<" ";
   }

   //-------------------------------------------------------------------------------------------------------

   int NodeCount(node* root){
   	if(root==NULL)return 0;
   	int left =NodeCount(root->left);
   	int right=NodeCount(root->right);

   	return (left+right+1);
   }

 //------------------------------------------------------------------------------------------------------------


   int height(node* root){
   	if(root==NULL)return 0;
   	int left=height(root->left);
   	int right=height(root->right);

   	 return (1+max(left,right));
   }

//-------------------------------------------------------------------------------------------------------------

   int sumOfAllNodes(node* root){
   	if(root==NULL)return 0;
   	int left=sumOfAllNodes(root->left);
   	int right=sumOfAllNodes(root->right);

   	return (root->data+left+right);
   }

  //----------------------------------------------------------------------------------------------------------
  

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

//-----------------------------------------------------------------------------------------------------------------  
  //  T=O(N^2)
  int Diameter(node* root){
  	if(root==NULL || (root->left==NULL and root->right==NULL))return 0;

  	int leftHeight=height(root->left);
  	int rightHeight=height(root->right);
  	int leftDiameter=Diameter(root->left);
  	int rightDiameter=Diameter(root->right);
  	return max((leftHeight+rightHeight),max(leftDiameter,rightDiameter));
  }

  //-----------------------------------------------------------------------------------------------------------------

  class HDPair{
  public:
  	int height;
  	int diameter;
  };
    
    //  T=O(N)
HDPair OptimizedDiameter(node* root){
	HDPair p;
	if(root==NULL){
       p.height=0;
       p.diameter=0;
       return p;
	}

	HDPair left=OptimizedDiameter(root->left);
	HDPair right=OptimizedDiameter(root->right);
    p.height=1+max(left.height,right.height);

    int d1=left.height+right.height;
    int d2=left.diameter;
    int d3=right.diameter;
    p.diameter=max(d1,max(d2,d3));
    return p;

}


//----------------------------------------------------------------------------------------------------------------------
node* Sumreplacement(node* root){
    if(root==NULL)return NULL;
  node* left=  Sumreplacement(root->left);
  node* right=  Sumreplacement(root->right);
   
    if(left){
        root->data+=left->data;
    }
    if(right){
        root->data+=right->data;
    }
    return root;
}


//--------------------------------------------------------------------------------------------------------------------

bool isBalanced(node* root){
    if(root==NULL)return true;
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    if(abs(leftHeight-rightHeight)>1)return false;
    bool left=isBalanced(root->left);
    if(!left)return false;
    bool right=isBalanced(root->right);
    if(!right)return false;
return true;

}

//----------------------------------------------------------------------------------------------------------------------

void RightView(node* root){
    if(root==NULL)return;
    queue<node*>q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();
        node* temp;
        for(int i=1;i<=n;i++){
            temp=q.front();
            q.pop();
            if(i==n)cout<<temp->data<<endl;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}

//------------------------------------------------------------------------------------------------------------------------

void LeftView(node* root){
    if(root==NULL)return;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        node* temp;
        for(int i=1;i<=n;i++){
            temp=q.front();
            q.pop();
            if(i==1)cout<<temp->data<<endl;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}

//--------------------------------------------------------------------------------------------------------------------------
    vector<int> topView(node *root)
    {
        //Your code here
             if(!root)return {};
   vector<int>ans;
   map<int,int>mp;
     queue<pair<node*,int>>q;
  
     q.push({root,0});
     while(!q.empty()){
    
          node* temp=q.front().first;
          int hd=q.front().second;
             q.pop();
             if(mp.count(hd)==0){mp[hd]=temp->data;}
            
             if(temp->left){q.push({temp->left,hd-1});}
             if(temp->right){q.push({temp->right,hd+1});}
         
     }
     
      for (auto i = mp.begin(); i != mp.end(); i++) {
         ans.push_back(i->second);
    }
  
     return ans;
    
    }

     vector<int> bottomView(node *root)
    {
        //Your code here
             if(!root)return {};
   vector<int>ans;
   map<int,int>mp;
     queue<pair<node*,int>>q;
  
     q.push({root,0});
     while(!q.empty()){
    
          node* temp=q.front().first;
          int hd=q.front().second;
             q.pop();
             mp[hd]=temp->data;
            
             if(temp->left){q.push({temp->left,hd-1});}
             if(temp->right){q.push({temp->right,hd+1});}
         
     }
     
      for (auto i = mp.begin(); i != mp.end(); i++) {
         ans.push_back(i->second);
    }
  
     return ans;
    
    }


//-------------------------------------------------------------------------------------------------------------------------

node* LCA(node* root,int n1,int n2){
    if(root==NULL)return NULL;
    if(root->data==n1 || root->data==n2)return root;

    node* LeftLCA=LCA(root->left,n1,n2);
    node* RightLCA=LCA(root->right,n1,n2);

    if(LeftLCA and RightLCA)return root;
    if(!LeftLCA and !RightLCA)return NULL;

    if(LeftLCA)return LCA(root->left,n1,n2);
    else return LCA(root->right,n1,n2);
}

//--------------------------------------------------------------------------------------------------------------------------

int distance(node* root,int n1, int dist){
    if(root==NULL)return -1;
    if(root->data==n1)return dist;
     int left=distance(root->left,n1,(dist+1));
     if(left!=-1)return left;
     return distance(root->right,n1,(dist+1));
}


//-------------------------------------------------------------------------------------------------------------------------

int MinimumDistBtwTwoNodes(node* root,int n1,int n2){
    if(root==NULL)return -1;
    node* temp=LCA(root,n1,n2);
    
    int d1=distance(temp,n1,0);
    int d2=distance(temp,n2,0);
   return d1+d2;

}

//------------------------------------------------------------------------------------------------------------------------
int Position(int inorder[],int start,int end,int key){
    for(int i=start;i<=end;i++){
        if(inorder[i]==key)return i;
    }
    return -1;
}

node* buildPreorderInorder(int preorder[],int inorder[],int start,int end){
    if(start>end)return NULL;
    static int idx=0;
    node* root=new node(preorder[idx]);
    int key=preorder[idx];
    idx++;

    int pos=Position(inorder,start,end,key);
    root->left=buildPreorderInorder(preorder,inorder,start,pos-1);
    root->right=buildPreorderInorder(preorder,inorder,pos+1,end);
    return root;

}

node* buildPostorderInorder(int postorder[],int inorder[],int start,int end){
   if(start>end)return NULL;
    static int idx=end;
    node* root=new node(postorder[idx]);
    int key=postorder[idx];
    idx--;
      if(start==end)return root;
    int pos=Position(inorder,start,end,key);
    root->right=buildPostorderInorder(postorder,inorder,pos+1,end);
    root->left=buildPostorderInorder(postorder,inorder,start,pos-1);
    return root;
}


//------------------------------------------------------------------------------------------------------------------


void Flatten(node*root){
    if(root==NULL ||(root->left==NULL && root->right==NULL))return;
    if(root->left){
        Flatten(root->left);
        node* temp=root->right;
        root->right=root->left;
        root->left=NULL;

        node* p=root->right;
        while(p->right!=NULL){
            p=p->right;
        }
        p->right=temp;
    }
    Flatten(root->right);
}

//---------------------------------------------------------------------------------------------------------------------

bool getPath(node* root,int key,vector<int>& path){
    if(root==NULL)return false;

    path.push_back(root->data);
    if(root->data==key)return true;
    if(getPath(root->left,key,path) || getPath(root->right,key,path))return true;

    path.pop_back();
    return false;
}

//--------------------------------------------------------------------------------------------------------------------
int maximum=INT_MIN;

int maxSumPath(node* root){
    if(root==NULL)return 0;
   int left= maxSumPath(root->left);
    int right=maxSumPath(root->right);

    int nodeValue=root->data;
     int leftSum=left+root->data;
     int rightSum=right+root->data;
     int bothleftandRight=left+right+root->data;
     maximum=max(maximum,max(nodeValue,(max(leftSum,max(rightSum,bothleftandRight)))));
     int singlePath=max(root->data,max(root->data+left,root->data+right));
     return  singlePath;

 }

 //---------------------------------------------------------------------------------------------------------------------

 pair<int,bool> isheightBlanced(node* root){
    pair<int,bool>p,left,right;
    if(root=NULL){
        p.first==0;
        p.second=true;
    }

    left=isheightBlanced(root->left);
    right=isheightBlanced(root->right);

    int height=max(left.first,right.first)+1;

    if(abs(left.first-right.first)<=1 and left.second and right.second){
        return make_pair(height,true);
    }
    return make_pair(height,false);
 }


//------------------------------------------------------------------------------------------------------------------------

class Pair{
 public:
    int inc;
    int exc;
};


 Pair maxSubsetSumTree(node* root){
    Pair p;
   if(root==NULL){
    p.inc=0;
    p.exc=0;
    return p;

   }

   Pair left=maxSubsetSumTree(root->left);
   Pair right=maxSubsetSumTree(root->right);

   p.inc=root->data+left.exc+right.exc;
   p.exc=max(left.inc,left.exc)+max(right.inc,right.exc);

   return p;

 }

 //---------------------------------------------------------------------------------------------------------------------

 void PrintAtlevelK(node* root,int k){
    if(root==NULL)return;
    if(k==0){
        cout<<root->data<<" ";
        return ;
    }
  
  PrintAtlevelK(root->left,k-1);
  PrintAtlevelK(root->right,k-1);
  return;

 }

 //----------------------------------------------------------------------------------------------------------------------


int PrintAllnodeAtDistanceK(node* root,node* target,int k){

     if(root==NULL)return -1;
     if(root==target){
        PrintAtlevelK(root,k);
        return 0;
     }

     int left=PrintAllnodeAtDistanceK(root->left,target,k);
     if(left!=-1){
        if(left+1==k)cout<<root->data<<" ";
        else{
            PrintAtlevelK(root->right,k-left-2);
        }
        return left+1;
     }

     int right=PrintAllnodeAtDistanceK(root->right,target,k);
     if(right!=-1){
        if(right+1==k)cout<<root->data<<" ";
        else{
            PrintAtlevelK(root->left,k-right-2);
        }
        return right+1;
     }


return -1;
}
//-------------------------------------------------------------------------------------------------------------------------------

void treeTraversal(node* root,int d,map<int,vector<int>>&m){
    if(root==NULL)return;
    m[d].push_back(root->data);
    treeTraversal(root->left,d-1,m);
    treeTraversal(root->right,d+1,m);
    return;
}

void VerticalPrint(node* root){
    map<int,vector<int>>m;
    int d=0;
    treeTraversal(root,d,m);
    for(auto key:m){
        vector<int>v=key.second;
        for(auto data:v){
            cout<<data<<" ";
        }
        cout<<endl;
    }
}

//------------------------------------------------------------------------------------------------------------------
//maximumPathSum

int solve(TreeNode* root,int& ans){
     if(root==NULL)return 0;
        int left=solve(root->left,ans);
        int right=solve(root->right,ans);
        int temp1=left+root->val;
         int temp2=right+root->val;
         int temp3=root->val;
          int temp4=0;
         ans=max(ans,left+right+root->val);
         return max({temp1,temp2,temp3,temp4});

}

    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
        
    }

//-----------------------------------------------------------------------------------------------------------------


int main(int argc, char const *argv[])
{
    clock_t start=clock();
    init_code();
    

    //write your code here
    node *root=LevelOrderBuild();
    levelorder(root);
    Postorder(root);
    cout<<endl;
   // cout<<MinimumDistBtwTwoNodes(root,7,6);
   
    // int preorder[]={1, 2 ,4, 5, 7, 3, 6 };
    // int inorder[]={4, 2, 7, 5, 1,3, 6 };
    // int postorder[]={4, 7 ,5, 2, 6, 3, 1 };
    VerticalPrint(root);
    
   PrintAtlevelK(root,1);
    #ifndef  ONLINE_JUDGE
     clock_t end=clock();
    cout<<"\n\n\n\nExecuted in: "<<double(end-start)/(CLOCKS_PER_SEC*1000)<<" ms"<<endl;
    #endif
   return 0;
}