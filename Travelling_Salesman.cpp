  // Travelling Salesman Problem  (DP with BitMASS)

//   Hamiltonian cycle is defined as the set of edges having 
//   every node. Once and after traverse all the node . 
//  Mtlb jis node se starting usi node se aakar ktm krna hai.

// Ex->0,1,2,3 So, if i will start from 0 i will go from 
// 01230,1321,1231 etc.

BITMASKING means to hide any type of information 

#include<bits/stdc++.h>
// #include<iostream>
// #include<climits>
using namespace std;

int grid[4][4]={
    {1,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};
 int dp[10][1<<10];
int tsp(int curr,int mask,int n){ // O(n^2 * 2^n)
    if(mask==(1<<n)-1){
        return grid[curr][0];
    }
    if(dp[curr][mask]!=-1) return dp[curr][mask];

    int ans=INT_MAX;
    for(int neigh=0;neigh<n;neigh++){
        if((mask & (1<<neigh))==0){
            ans=min(ans,grid[curr][neigh]+ tsp(neigh,mask | (1<< neigh),n));
        }
    }
    return dp[curr][mask]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cout<<tsp(0,1,4); 
    return 0;
}


// In BackTracking what i have did is i can do it by using 
// the bit manipulation where i well deals diagonala by 
// making the (r-c+n-1) so that the queen check that 
// another queen can be inserted there or not.