#include<bits/stdc++.h>
using namespace std;


int main(){
    
    string s;
    cin>>s;
    int n = s.size();
    int kmp[n+1];
    
    int i=0,j=-1;kmp[0] =-1;
    while(i<n){
        while(j!=-1 && s[i]!=s[j])j = kmp[j];
        j++;i++;
        kmp[i] = j;
    }
    for(i=0;i<=n;i++){
        cout<<kmp[i]<<" ";
    }
    
    
    
}
