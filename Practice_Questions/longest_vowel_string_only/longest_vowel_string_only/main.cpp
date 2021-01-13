#include <iostream>
#include <vector>
using namespace std;

int longestString(string s);

int main()
{
    string input = "letsgosomewhere";
    
    int res = longestString(input);
    
    cout << res << endl;
    
    
    return 0;
}

int longestString(string s){
    int start=0,end=s.size()-1,res=0,c=0,i=0;
    vector<int> h;
    while(start<=end){
        if(s[start]=='a' || s[start]=='o' || s[start]=='u' || s[start]=='e' || s[start]=='i')
           ++start;
        else if(s[end]=='a' || s[end]=='o' || s[end]=='u' || s[end]=='e' || s[end]=='i')
            --end;
        else break;
    }
    if(start>end) return s.size();
    for(i=start;i<=end;i++){
        if(s[i]=='a' || s[i]=='o' || s[i]=='u' || s[i]=='e' || s[i]=='i') ++c;
        else{
            if(c>0) h.push_back(c);
            c=0;
        }
    }
    end=s.size()-end-1;
    for(i=0;i<h.size();i++){
        res=max(res,max(start+h[i],max(end+h[i],start+h[i]+end)));
    }
  return res;
}
