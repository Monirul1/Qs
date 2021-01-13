#include <iostream>
#include <vector>
using namespace std;

int findWinner(vector<vector<string>>codeList, vector<string>cart);

int main()
{
    vector<vector<string>>code = {{"apple", "apple"}, {"apple", "apple", "banana"}};
    vector<string>cart = {"apple", "apple", "apple", "banana"};
    
    int res = findWinner(code, cart);
    cout << "Input1: " << res << endl;
    
    
    return 0;
}

int findWinner(vector<vector<string>>codeList, vector<string>cart)
{
    if(codeList.empty() || codeList.size()==0) return 1;
    if(cart.empty() || cart.size() == 0) return 0;
    
    int i = 0, j = 0;
    
    while(i < codeList.size() && j+codeList[i].size() <= cart.size())
    {
        bool match = true;
        
        for(int k = 0; k < codeList[i].size(); k++)
        {
            if(!(codeList[i][k] == "anything") && !(cart[j+k] == codeList[i][k]))
            {
                match = false;
                break;
            }
        }
        if(match)
        {
            j += codeList[i].size();
            i++;
        } else {
            j++;
        }
        
    }
    
    return (i == codeList.size());
    
}
