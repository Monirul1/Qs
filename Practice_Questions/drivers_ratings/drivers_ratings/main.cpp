#include <iostream>
#include <vector>
#include <stack>
using namespace std;
long maxValue(vector<int> v){
    
    int n=v.size();
    vector<int> p1(n),p2(n);
    stack<int> S;
    
    for(int i=0;i<n;i++){
        while(!S.empty() && v[S.top()]>=v[i]) S.pop();
        
        if(S.empty())p1[i]=0;
        else p1[i]=S.top()+1;
        
        S.push(i);
    }
    stack<int> temp;
    S.swap(temp);
    for(int i=n-1;i>=0;i--){
        while(!S.empty() && v[S.top()]>=v[i]) S.pop();
        
        if(S.empty())p2[i]=n-1;
        else p2[i]=S.top()-1;
        
        S.push(i);
    }
    
    vector<int> T(n);
    for(int i=0;i<n;i++)T[i]=v[i]+(i==0?0:T[i-1]);
    
    long ans=(long)v[0]*v[0];
    for(int i=0;i<n;i++)
        ans=max(ans,(long)v[i]*(T[p2[i]]-(p1[i]==0?0:T[p1[i]-1])));
    return ans;
}
    

int main(void){
    
    cout<<maxValue({3,1,6,4,5,2})<<endl;
    
    return 0;
}
// output: 60
