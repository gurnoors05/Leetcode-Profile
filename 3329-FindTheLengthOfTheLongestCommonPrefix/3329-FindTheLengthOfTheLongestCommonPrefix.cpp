// Last updated: 8/16/2026, 6:52:07 PM
struct TrieNode{
    TrieNode* children[10];
};
class Solution {
public:
    TrieNode* getNode(){
        TrieNode* root=new TrieNode();
        for(int i=0;i<10;i++){
            root->children[i]=NULL;
        }
        return root;
    }
    void insertNode(TrieNode* root,int num){
        TrieNode* crawl=root;
        string n=to_string(num);
        for(int i=0;i<n.length();i++){
            int idx=n[i]-'0';
            if(!crawl->children[idx]){
                crawl->children[idx]=getNode();
            }
            crawl=crawl->children[idx];
        }

    }
    int search(TrieNode* root,int num){
        string s=to_string(num);
        TrieNode* crawl=root;
        int count=0;
        for(char ch:s){
            int n=ch-'0';
            if(crawl->children[n]){
                crawl=crawl->children[n];
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root=getNode();
        for(int num:arr1){
            insertNode(root,num);
        }
        int result=INT_MIN;
        for(int num:arr2){
            int length=search(root,num);
            result=max(result,length);
        }
        return result;
    }
};