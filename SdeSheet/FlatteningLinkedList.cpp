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

Node *flatten(Node *root)
{
   // Your code here
   vector<int>v;
   while(root){
       v.push_back(root->data);
       Node* temp=root->bottom;
       while(temp){
           v.push_back(temp->data);
           temp=temp->bottom;
       }
       root=root->next;
       
   }
   
   Node* first,*last,*temp;
   sort(v.begin(),v.end());
   
   for(int i=0;i<v.size();i++){
       if(i==0){
           first=new Node(v[i]);
           last=first;
           
       }
       else{
           temp=new Node(v[i]);
           last->bottom=temp;
           last=temp;
       }
   }
   
   return first;
   
}



//optimised spacecomplexity
Node* merge(Node* a, Node* b)
{
    
    // If first linked list is empty then second
    // is the answer
    if (a == NULL)
        return b;

    // If second linked list is empty then first
    // is the result
    if (b == NULL)
        return a;

    // Compare the data members of the two linked 
    // lists and put the larger one in the result
    Node* result;

    if (a->data < b->data) 
    {
        result = a;
        result->down = merge(a->down, b);
    }

    else 
    {
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}

Node* flatten(Node* root)
{
    
    // Base Cases
    if (root == NULL || root->right == NULL)
        return root;

    // Recur for list on right
    root->right = flatten(root->right);

    // Now merge
    root = merge(root, root->right);

    // Return the root
    // it will be in turn merged with its left
    return root;
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