#include <iostream>
#include <string>
using namespace std;

int main(){
    string S1, S2;
    cin>>S1>>S2;
    
    int l1 = S1.length();
    int l2 = S2.length();
    
    int DP[l1+1][l2+1];
    
    for(int i=0; i<=l1; i++) DP[i][0]=0;
    for(int i=0; i<=l2; i++) DP[0][i]=0;
    
    for(int i=1; i<=l1; i++){
        for(int j=1; j<=l2; j++){
            if(S1[i-1]==S2[j-1]){
                DP[i][j] = DP[i-1][j-1] +1;
            }else{
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
            }
        }
    }
    
    cout<<"Length of LCS = "<<DP[l1][l2]<<endl;
    
    string S;
    S.resize(DP[l1][l2]);
    
    int x=l1, y=l2;
    int LCS = DP[l1][l2];
    while(x>0 || y>0){
        if(S1[x-1]==S2[y-1]){
            S[LCS-1] = S1[x-1];
            LCS--;
            x--;
            y--;
        }else if(DP[x][y] == DP[x][y-1]){
            y--;
        }else{
            x--;
        }
    }
    
    cout<<S<<endl;
    return 0;
}