// Last updated: 8/16/2026, 6:54:34 PM
class Solution {
public:
    struct TrieNode{
      TrieNode* child[26];
      int count;
  };
  TrieNode* getNode(){
      TrieNode* newNode= new TrieNode();
      for(int i=0;i<26;i++){
        newNode->child[i]=NULL;
      }
      newNode->count=0;
      return newNode;
  }
  TrieNode* root;
  Solution(){
      root=getNode();
  }
  void insert(string s){
      TrieNode* curr=root;
      for(int i=0;i<s.length();i++){
        char c=s[i];
        if(curr->child[c-'a']==NULL){
            curr->child[c-'a']=getNode();
        }
        curr=curr->child[c-'a'];
        curr->count+=1;
      }
  }
  int find(string s){
    TrieNode* curr=root;
    int sum=0;
      for(int i=0;i<s.length();i++){
        char c=s[i];
        if(curr->child[c-'a']==NULL){
           break;
        }
        curr=curr->child[c-'a'];
        sum+=curr->count;
      }
      return sum;
  }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++){
            insert(words[i]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(find(words[i]));
        }
        return ans;
    }
};