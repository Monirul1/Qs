#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;


vector<string> fetchItems(int numOfItems, unordered_map<string, pair<int, int>>items, int sortParameter, int sortOder, int itemsPerPage, int pageNumber);

int main()
{
    int sortParameter = 1;
    int sortOrder = 0;
    int itemsPerPage = 2;
    int pageNumber = 1;
    int numOfItems = 3;
   
    
    pair<int, int>p1 = {10, 15};
    pair<int, int>p2 = {3, 4};
    pair<int, int>p3 = {17, 8};
    pair<int, int>p4 = {17, 9};


    unordered_map<string, pair<int, int>>map;
    
    map["item1"] = p1;
    map["item2"] = p2;
    map["item3"] = p3;
    map["item4"] = p4;

    
    vector<string> res = fetchItems(numOfItems, map, sortParameter, sortOrder, itemsPerPage, pageNumber);
    
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "    ";
    }
    cout << endl;

}

vector<string> fetchItems(int numOfItems, unordered_map<string, pair<int, int>>items, int sortParameter, int sortOder, int itemsPerPage, int pageNumber)
{
    vector<string>res;
    vector<vector<string>>getItems;
    vector<vector<string>>buildAnswer;

    
    for(auto it = items.begin(); it != items.end(); it++)
    {
        vector<string>temp;
        temp.push_back(it->first);
        
        string j = to_string(it->second.first);
        string k = to_string(it->second.second);
        temp.push_back(j);
        temp.push_back(k);
        
        getItems.push_back(temp);
    }
    
    if(sortParameter == 0)
    {
        if(sortOder == 0)
        {
            for(int i = 0; i < getItems.size(); i++)
            {
                string getNum = "";
                for(int j = 0; j < getItems[i][0].size(); j++)
                {
                    if(isdigit(getItems[i][0][j]))
                    {
                        getNum += getItems[i][0][j];
                    }
                }
                int getNumberi = stoi(getNum);
                
                for(int k = i+1; k < getItems.size(); k++)
                {
                    for(int j = 0; j < getItems[i][0].size(); j++)
                    {
                        if(isdigit(getItems[i][0][j]))
                        {
                            getNum += getItems[i][0][j];
                        }
                    }
                    int getNumberj = stoi(getNum);
                    
                    if(getNumberi > getNumberj)
                    {
                        vector<string>temp = getItems[i];
                        getItems[i] = getItems[k];
                        getItems[k] = temp;
                    }
                }
                
            }
            
        }
        
        if(sortOder == 1)
        {
            for(int i = 0; i < getItems.size(); i++)
            {
                      string getNum = "";
                      for(int j = 0; j < getItems[i][0].size(); j++)
                      {
                          if(isdigit(getItems[i][0][j]))
                          {
                              getNum += getItems[i][0][j];
                          }
                      }
                      int getNumberi = stoi(getNum);
                      
                      for(int k = i+1; k < getItems.size(); k++)
                      {
                          for(int j = 0; j < getItems[i][0].size(); j++)
                          {
                              if(isdigit(getItems[i][0][j]))
                              {
                                  getNum += getItems[i][0][j];
                              }
                          }
                          int getNumberj = stoi(getNum);
                          
                          if(getNumberi < getNumberj)
                          {
                              vector<string>temp = getItems[i];
                              getItems[i] = getItems[k];
                              getItems[k] = temp;
                          }
                      }
                      
                  }
                  
            }
    }

    if(sortParameter == 1)
    {
        if(sortOder == 0)
        {
           for(int i = 0; i < getItems.size(); i++)
            {
                for(int j = i+1; j < getItems.size(); j++)
                {
                    if(stoi(getItems[i][1]) > stoi(getItems[j][1]))
                    {
                         vector<string>temp = getItems[i];
                         getItems[i] = getItems[j];
                         getItems[j] = temp;
                    }
                }
            }
            
        } else if(sortOder == 1)
        {
            
            for(int i = 0; i < getItems.size(); i++)
            {
                for(int j = i+1; j < getItems.size(); j++)
                {
                    if(stoi(getItems[i][1]) < stoi(getItems[j][1]))
                    {
                         vector<string>temp = getItems[i];
                         getItems[i] = getItems[j];
                         getItems[j] = temp;
                    }
                }
            }
        }
    }
    
    if(sortParameter == 2)
    {
        if(sortOder == 0)
        {
           for(int i = 0; i < getItems.size(); i++)
            {
                for(int j = i+1; j < getItems.size(); j++)
                {
                    if(stoi(getItems[i][2]) > stoi(getItems[j][2]))
                    {
                         vector<string>temp = getItems[i];
                         getItems[i] = getItems[j];
                         getItems[j] = temp;
                    }
                }
            }
            
        } else if(sortOder == 1)
        {
            
            for(int i = 0; i < getItems.size(); i++)
            {
                for(int j = i+1; j < getItems.size(); j++)
                {
                    if(stoi(getItems[i][2]) < stoi(getItems[j][2]))
                    {
                         vector<string>temp = getItems[i];
                         getItems[i] = getItems[j];
                         getItems[j] = temp;
                    }
                }
            }
        }
        
    }
    
    vector<vector<string>>buildRes;
    
    for(int i = 0; i < getItems.size(); i++)
    {
        int j = 0;
        vector<string>temp;
        while(j < itemsPerPage && i < getItems.size())
        {
            temp.push_back(getItems[i][0]);
            j++;
            i++;
        }
        i--;
        buildRes.push_back(temp);
        
    }
    
    res = buildRes[pageNumber];

    return res;
}
