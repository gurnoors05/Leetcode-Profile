// Last updated: 8/16/2026, 6:51:52 PM
class Solution {
public:
    struct TrieNode{
        int idx;
        TrieNode* children[26];
        ~TrieNode() {
            for (int i = 0; i < 26; i++) {
                delete children[i];
            }
        }
    };
    TrieNode* getNode(int idx){
        TrieNode* root=new TrieNode();
        root->idx=idx;
        for(int i=0;i<26;i++){
            root->children[i]=NULL;
        }
        return root;
    }
    void insert(vector<string>& wordsContainer,int i,TrieNode* root){
        int index=root->idx;
        string s=wordsContainer[i];
        int n=wordsContainer[i].length();
        TrieNode* crawl=root;
        for(int j=n-1;j>=0;j--){
            int ch=s[j]-'a';
            if(crawl->children[ch]==NULL){
                crawl->children[ch]=getNode(i);
            }
            crawl=crawl->children[ch];
            if(wordsContainer[crawl->idx].size()>n){
                crawl->idx=i;
            }
        }
    }
    int search(string s,TrieNode* root){
        int result=root->idx;
        int n=s.length();
        TrieNode* crawl=root;
        for(int j=n-1;j>=0;j--){
            int ch=s[j]-'a';
            if(crawl->children[ch] == NULL){
                return result;
            }

            crawl = crawl->children[ch];

            result = crawl->idx;
                
        }
        return result;
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordQuery) {
        int n=wordsContainer.size();
        int m=wordQuery.size();
        vector<int> result(m);
        TrieNode* root=getNode(0);
        for(int i=0;i<n;i++){
            if(wordsContainer[root->idx].size()>wordsContainer[i].size()){
                root->idx=i;
            }
            insert(wordsContainer,i,root);
        }
        for(int i=0;i<m;i++){
            result[i]=search(wordQuery[i],root);
        }
        delete root;
        return result;
    }
};