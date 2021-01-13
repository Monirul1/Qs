#include <iostream>
using namespace std;

void tagged(string originalTag, int limit);

int main()
{
    string input = "cbdd";
    int limit = 2;
    
    tagged(input, limit);
//    cout << res << endl;
}

void tagged(string originalTag, int limit)
{
    string getLimit;
    
    
    for(int i = originalTag.size()-1; i >= originalTag.size()-limit; i--)
    {
        getLimit += originalTag[i];
    }
    sort(originalTag.begin(), originalTag.end(), greater<char>());
    cout << getLimit << endl;
    cout << originalTag << endl;
    
//    string newOriginalTag = getLimit+originalTag;;
//    string res = originalTag.substr(0, newOriginalTag.size()-originalTag.size());
//    cout << res;
    
    
}
