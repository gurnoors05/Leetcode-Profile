// Last updated: 8/16/2026, 6:56:20 PM
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int l=encodedText.size();
        int col=l/rows;
        string originalText="";
        for(int c=0;c<col;c++){
            for(int j=c;j<l;j+=(col+1)){
                originalText+=encodedText[j];
            }
        }
        while(!originalText.empty() && originalText.back()==' '){
            originalText.pop_back();
        }
        return originalText;
    }
};