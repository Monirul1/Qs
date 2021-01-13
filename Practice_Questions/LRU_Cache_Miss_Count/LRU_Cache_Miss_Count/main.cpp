#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;


class Node {
       int value;
        Node( int value ) {
           this->value = value;
       }
};

int lruCacheMiss(vector<int>pages, int maxCacheSize);

int main()
{
    vector<int>input = {1, 2, 1, 3, 1, 2};
    int n = 2;
    
    int res = lruCacheMiss(input, n);
    cout << "RESS: " << res << endl;
    
    
    return 0;
}

int lruCacheMiss(vector<int>pages, int maxCacheSize)
{
//    List<Integer> list = new LinkedList<>();
//       int count = 0;
//       for(int i: input)
//       {
//           if(list.contains(i)) list.remove(new Integer(i));
//           else
//           {
//               if(list.size() == size) list.remove(0);
//               count++;
//           }
//           list.add(i);
//       }
//       return count;
    
//    vector<int>list;
    unordered_set<int>list;
    
    int count = 0;
    for(int i = 0; i < pages.size(); i++)
    {
        if(list.find(pages[i]) != list.end())
        {
            list.erase(pages[i]);
        } else {
            if(list.size() == maxCacheSize)
            {
                list.erase(list.begin());
                count++;
            }
            list.insert(i);
        }
    }
    return count;
}
