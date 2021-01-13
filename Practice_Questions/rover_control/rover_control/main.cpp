#include <iostream>
#include <vector>
using namespace std;

int position(vector<string>command, int n);


int main()
{
    vector<string>command = {"RIGHT", "UP", "DOWN", "LEFT", "DOWN", "DOWN"};
    int n = 4;
    int res = position(command, n);
    cout << "RESS: " << res << endl;
    
    return 0;
}

int position(vector<string>command, int n)
{
   if(command.size()==0){
        return 0;
    }
    int pos=0;
    for(string s:command){
        int r=pos/n;
        if(s=="RIGHT"){
            if(pos<((r+1)*n)-1){
                pos++;
            }
        }
        else if(s=="LEFT"){
            if(pos>(r*n)){
                pos--;
            }
        }
        else if(s=="UP"){
            
            if(r>0){
                pos=pos-n;
            }
        }
        else if(s=="DOWN"){
            
            if(r<n-1){
                pos=pos+n;
            }
        }
    }
    
    return pos;
    

    
    
}
