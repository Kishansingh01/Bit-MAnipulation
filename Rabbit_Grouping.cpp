 #include<bits/stdc++.h>
 using namespace std;

 vector<int> dp((1<<16),INT_MAX);
 vector<int> sums((1<<16),0);

 int calc(vector<vector<int>> &compat,int mask){
         int ans=0;
         for(int i=0;i<=16;i++){
            for(int j=i+1;j<=16;j++){
                if(((mask & (1<<i))!=0) and ((mask &(1<<j))!=0)){
                    ans+=compat[i][j];
                }
            }
         }
 }

 void precompute(vector<vector<int>> &compat,int n){
     for(int mask=1;mask<=((1<<n)-1);mask++){
        sums[mask]=calc(compat,mask);
     }
 }
 int f(vector<vector<int>> &compact,int mask){
    if(mask==0) return 0;
    if(dp[mask]!=INT_MAX) return dp[mask];
    int ans=0;
    for(int g=mask;g!=0;g=((g-1) & mask)){
        ans=max(ans,sums[g]+ f(compat,mask ^g)); 
    }
    return dp[mask]=ans;
 }
 int main(){
    int n;
    cin>>n;
    vector<vector<int>> compat(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>compat[i][j];
        }
    }
    precompute(compat,n);
    cout<<f(compat,((1<<n)-1));
    return 0;
 }

// // //  3
// // //  0 10 20
// // //  10 0 100
// // //  20 -100 0 

Below is the correct one.

// #include<bits/stdc++.h>
// using namespace std;

// vector<int> dp, sums;

// int calc(vector<vector<int>> &compat, int mask) {
//     int ans = 0;
//     int n = compat.size();
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (((mask & (1 << i)) != 0) && ((mask & (1 << j)) != 0)) {
//                 ans += compat[i][j];
//             }
//         }
//     }
//     return ans;
// }

// void precompute(vector<vector<int>> &compat, int n) {
//     for (int mask = 1; mask < (1 << n); mask++) {
//         sums[mask] = calc(compat, mask);
//     }
// }

// int f(vector<vector<int>> &compat, int mask) {
//     if (mask == 0) return 0;
//     if (dp[mask] != INT_MAX) return dp[mask];

//     int ans = 0;
//     for (int g = mask; g != 0; g = (g - 1) & mask) {
//         ans = max(ans, sums[g] + f(compat, mask ^ g));
//     }

//     return dp[mask] = ans;
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<vector<int>> compat(n, vector<int>(n));

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> compat[i][j];
//         }
//     }

//     dp.assign((1 << n), INT_MAX);
//     sums.assign((1 << n), 0);

//     precompute(compat, n);

//     cout << f(compat, (1 << n) - 1) << endl;

//     return 0;
// }

      

