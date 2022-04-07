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

 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=nullptr,*last;
         if(list1 and list2){
             if(list1->val<list2->val){
                 head=new ListNode(list1->val);
                 last=head;
                 list1=list1->next;
             }
             else{
                 head=new ListNode(list2->val);
                 last=head;
                 list2=list2->next;
             }
         }
        
        else if(list1 and !list2)return list1;
        else if(list2 and !list1)return list2;
        
        
         while(list1 and list2){
             if(list1->val<list2->val){
            
                     ListNode* temp=new ListNode(list1->val);
                     last->next=temp;
                     last=temp;
                 
                 list1=list1->next;
             }
             
              else {
               
                 
                     ListNode* temp=new ListNode(list2->val);
                     last->next=temp;
                     last=temp;
                 
                  list2=list2->next;
             }
         }
        
        if(list1!=NULL and last!=NULL){
            last->next=list1;
    
        }
        if(list2!=NULL and last!=NULL){
            last->next=list2;
        }
        return head;
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