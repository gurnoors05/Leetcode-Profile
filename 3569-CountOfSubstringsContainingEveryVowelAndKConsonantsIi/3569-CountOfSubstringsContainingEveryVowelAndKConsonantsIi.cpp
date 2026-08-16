// Last updated: 8/16/2026, 6:51:04 PM
class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return solve(word,k);
    }
    long long solve(string word,int k){
        int l=0;
        int r=0;
        int n=word.size();
        unordered_map<char,int> mp;
        int cons=0;
        vector<int> lastCons(n);
        int lastSeen=n;
        long long noOfSub=0;
        for(int i=n-1;i>=0;i--){
            lastCons[i]=lastSeen;
            if(!isVowel(word[i])){
                lastSeen=i;
            }
        }
        while(r<n){
            if(isVowel(word[r])){
                mp[word[r]]++;
            }
            else{
                cons++;
            };
            while(cons>k){
                if(isVowel(word[l])){
                    mp[word[l]]--;
                    if(mp[word[l]]==0){
                        mp.erase(word[l]);
                    }
                }
                else{
                    cons--;
                }
                l++;
            }
            while(l<n && mp.size()==5 && cons==k){
                int idx=lastCons[r];
                int length=idx-r;
                noOfSub+=length;
                if(isVowel(word[l])){
                    mp[word[l]]--;
                    if(mp[word[l]]==0){
                        mp.erase(word[l]);
                    }
                }
                else{
                    cons--;
                }
                l++;
            }
            r++; // expand(invalid)
        }
        return noOfSub;
        
    }
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='o' || ch=='i' || ch=='u'){
            return true;
        }
        return false;
    }
};