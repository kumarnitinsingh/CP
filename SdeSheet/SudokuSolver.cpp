// Created by Nitin kumar singh
// problem link -> https://leetcode.com/problems/sudoku-solver/

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

bool canplace(vector<vector<char>>& board,int i,int j,char no){
    for(int k=0;k<board.size();k++){
        if(board[i][k]==no or board[k][j]==no)return false;
    }
    int p=sqrt(board.size());
    int x=(i/p)*p;
    int y=(j/p)*p;
    for(int k=x;k<(x+p);k++){
        for(int q=y;q<(y+p);q++){
            if(board[k][q]==no)return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>& board,int i,int j){
    if(i==board.size())return true;;
    if(j==board.size()){
       return  solve(board,i+1,0);
        
    }
        
    if(board[i][j]!='.')return solve(board,i,j+1);
    
    for(char  k='1';k<='9';k++){
        if(canplace(board,i,j,k)){
            board[i][j]=k;
            bool po=solve(board,i,j+1);
            if(po)return true;
           
        }
        
    }
     board[i][j]='.';
    return false;
}


    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board,0,0);
        
      
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