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

   bool isPalindrome(ListNode* head) {
        vector<int>v;
        while(head){
            int x=head->val;
            v.push_back(x);
            head=head->next;
        }
        
        int i=0,j=v.size()-1;
        while(i<j){
            if(v[i++]!=v[j--])return false;
        }
        return true;
    }


     bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        if(!head->next)  return true;
        while(fast->next && fast->next->next){              // finding middle of linked list 
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*prev=NULL,*curr=slow->next,*temp;
        while(curr!=NULL){                                 // reversing the linked list after the middle node
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        slow->next=prev;                                   // joining the reversed linked list after the middle node
        ListNode *start=head,*mid=slow->next;
        while(mid){                                        // valued being checked here
            if(start->val!=mid->val) return false;
            start=start->next;
            mid=mid->next;
        }
        return true;
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