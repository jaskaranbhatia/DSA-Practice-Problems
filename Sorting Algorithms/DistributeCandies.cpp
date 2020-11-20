#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> boxes(n);
        for(int i=0;i<n;i++){
            cin>>boxes[i];
        }
        sort(boxes.begin(),boxes.end());
        int start = 0;
        int end = boxes[n-1];
        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            int persons = 0;
            for(int i=0;i<n;i++){
                persons += (boxes[i]/mid);
            }
            if(persons >= k){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

