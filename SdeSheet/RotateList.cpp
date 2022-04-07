// Created by Nitin kumar singh
// problem link ->  https://leetcode.com/problems/rotate-list/

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

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) 
        {
            return head;
        }
        
        int sz = 0;
        ListNode* cnt = head;
        while(cnt!=NULL) {
            sz++;
            cnt = cnt->next;
        }
 
        for ( int i=0; i<k%sz; i++) 
        {
            int first = head->val;
            ListNode* temp = head->next;
            int curr;
            
            while(temp!=NULL) {
                curr = temp->val;
                temp->val = first;
                first = curr;
                temp=temp->next;
            }
            
            head->val = first;
        }
        
        return head;
    }


  ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return nullptr;
        vector<int>v;
        ListNode* temp=head,*first,*last;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
     if(v.size()>0 )   rotate(v.begin(),v.begin()+(v.size()-k%v.size()),v.end());
        for(int i=0;i<v.size();i++){
            if(i==0){
                first=new ListNode(v[i]);
                last=first;
            }
            else{
                temp=new ListNode(v[i]);
                last->next=temp;
                last=temp;
            }
        }
        return first;
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