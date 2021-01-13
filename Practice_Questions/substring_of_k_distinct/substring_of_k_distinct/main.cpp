#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

string subHelp(char start, int i, string&s, int size, int k);
vector<string>kSubstring(string s, int k);

int main()
{
    string input = "abcabc";
    int k = 3;
    
    
    vector<string> res = kSubstring(input, k);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    
    
    
    return 0;
}

string subHelp(char start, int i, string&s, int size, int k){
    unordered_set<char>chars;
    string temp, empty;
    int j =0;
    if(!s[i]){
        return temp;
    }
    temp.push_back(start);
    while(j < k-1){
        if(s[i]==start ||chars.find(s[i])!=chars.end()){
            return empty;
        }
        chars.insert(s[i]);
        temp.push_back(s[i]);
        ++j;
        ++i;
    }
    return temp;
}
vector<string>kSubstring(string s, int k){
    int size = s.size();
    vector<string>sub;
    if(size==0||size<k){
        return sub;
    }
    unordered_set<string>set;
    for(int i =0; i < size-k; ++i){
        char start = s[i];
        string check = subHelp(start, i+1, s, size, k);
        if(!check.empty() && set.find(check)==set.end()){
            sub.push_back(check);
            set.insert(check);
        }
    }
    return sub;
}
