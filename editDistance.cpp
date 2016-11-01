#include <iostream>
#include <string>
using namespace std;

int main(){
    string S1, S2;
    cin>>S1>>S2;
    
    int l1 = S1.length();
    int l2 = S2.length();
    
    int DP[l1+1][l2+1];
    
    for(int i=0; i<=l1; i++) DP[i][0]=i;
    for(int i=0; i<=l2; i++) DP[0][i]=i;
    
    for(int i=1; i<=l1; i++){
        for(int j=1; j<=l2; j++){
            if(S1[i-1]==S2[j-1]){
                DP[i][j] = DP[i-1][j-1];
            }else{
                DP[i][j] = 1+min(min(DP[i-1][j], DP[i][j-1]),DP[i-1][j-1]);
            }
        }
    }
    
    cout<<" No of steps = "<<DP[l1][l2]<<endl;
    
    return 0;
}