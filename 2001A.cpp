#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int maxi=*max_element(a.begin(),a.end());
        vector<int>freq(maxi+1,0);
        for(int i=0;i<n;i++){
            freq[a[i]]++;
        }
        int maxif=*max_element(freq.begin(),freq.end());
        int ans=n-maxif;
        cout<<ans<<endl;

    }
}