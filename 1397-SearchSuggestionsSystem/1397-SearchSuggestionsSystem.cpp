// Last updated: 8/16/2026, 7:02:52 PM
class Solution {
public:
    struct TrieNode{
    TrieNode* child[26];
     bool isEndOfWord;
     vector<string> sugg;
  };
  TrieNode* getNode(){
      TrieNode* newNode= new TrieNode();
      for(int i=0;i<26;i++){
        newNode->child[i]=NULL;
      }
      newNode->isEndOfWord=0;
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
        if(curr->sugg.size()<3){
            curr->sugg.push_back(s);
        }
      }
      curr->isEndOfWord=true;
  }
  vector<string> find(string s){
    TrieNode *curr=root;
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(curr->child[c-'a']!=NULL){
            curr=curr->child[c-'a'];
        }
        else{
            return {};
        }
    }
    return curr->sugg;
  }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        for(int i=0;i<products.size();i++){
            insert(products[i]);
        }
        vector<vector<string>> result;
        for(int i=0;i<searchWord.length();i++){
           
            vector<string> arr=find((searchWord.substr(0,i+1)));
            result.push_back(arr);
        }
        return result;
    }
};