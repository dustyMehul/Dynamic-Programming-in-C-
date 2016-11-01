#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int x;
    vector <int> coins(n);
    
    for(int i=0; i<n; i++) cin>>coins[i];

    vector < vector <int> > DP(n+1, vector <int>(m+1) );
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0) DP[i][j] =0;
            else if(j==0) DP[i][j] = 1;
            else if(j-coins[i-1] >=0 ){
                
                DP[i][j] = DP[i][j-coins[i-1]] + DP[i-1][j];
            }else{
                DP[i][j] = DP[i-1][j];
            }
        
        }
    }
    
    
    cout<<DP[n][m];
    
    
    return 0;
}