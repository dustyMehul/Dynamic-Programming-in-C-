#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int A[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(A)/sizeof(A[0]);
    int L[n];
    
    L[0] =1;
    
    for(int i=1; i<n; i++){
        int maxi = 0;
        for(int j=0; j<i; j++){
            if(A[i]>A[j]){
                maxi = max(maxi, L[j]);
            }
        }
        
        L[i] = 1+maxi;
    }
    int maxi = 1;
    for(int i=0; i<n; i++) maxi = max(maxi, L[i]);
    int ans [maxi];
    
    for(int i=n-1; i>=0; i--){
        if(L[i]==maxi){
            ans[maxi-1] = A[i];
            maxi--;
        }
    }
    
    for(int i=0; i<sizeof(ans)/sizeof(ans[0]); i++) cout<<ans[i]<<" ";
    
}