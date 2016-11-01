#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    vector< vector <int> > mat(n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            mat[i].push_back(x);
        }
    }
    
    
    vector < vector <int> > DP(n, vector <int>(m) );
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 && j==0) DP[0][0] = mat[0][0];
            else if(i==0) DP[i][j] = DP[i][j-1] + mat[i][j];
            else if(j==0) DP[i][j] = DP[i-1][j] + mat[i][j];
            else{
                DP[i][j] = mat[i][j] + min(DP[i-1][j-1], min(DP[i-1][j],DP[i][j-1]));
            }
        }
    }
    
    
    cout<<DP[n-1][m-1];
    
    
    return 0;
}