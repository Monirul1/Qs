#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int val;
    vector<Node*> children;
    
    Node() {}
    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
double ans=INT_MIN;
Node *res;
vector<double> dfs(Node *node){
    if(!node){
        return {0,0};
    }
    double currVal=node->val;
    double count=1;
    for(auto child:node->children){
        vector<double> temp=dfs(child);
        count+=temp[1];
        currVal+=temp[0];
    }
    double avg=currVal/count;
    if(count>1 && avg>ans){
        ans=avg;
        res=node;
    }
    return {currVal,count};
}
int maximumAverageSubtree(Node *root){
    if(!root){
        return 0;
    }
    dfs(root);
    return res->val;
}
int main() {
    Node *node0=new Node(20);
    Node *node1=new Node(12);
    Node *node2=new Node(18);
    Node *node3=new Node(11);
    Node *node4=new Node(2);
    Node *node5=new Node(3);
    Node *node6=new Node(15);
    Node *node7=new Node(8);
    node0->children={node1,node2};
    node1->children={node3,node4,node5};
    node2->children={node6,node7};
    int ans=maximumAverageSubtree(node0);
    cout << ans << endl;
    return 0;
}
