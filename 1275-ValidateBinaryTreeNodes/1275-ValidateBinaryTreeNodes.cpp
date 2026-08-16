// Last updated: 8/16/2026, 7:04:03 PM
class Solution {
public:
    vector<int> parent;
    int find(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
    bool findunion(int parentNode,int child,int& components){
        int child_parent=find(child);
        if(child_parent!=child){
            return false;
        }
        int parent_parentNode=find(parentNode);
        if(parent_parentNode==child_parent){
            return false;
        }
        parent[child]=parentNode;
        components--;
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        parent.resize(n);
        int components=n;
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<leftChild.size();i++){
            if(leftChild[i]!=-1 && !findunion(i,leftChild[i],components)){
                return false;
            }
            if(rightChild[i]!=-1 && !findunion(i,rightChild[i],components)){
                return false;
            }
        }
        return components==1;;
    }
};