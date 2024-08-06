class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int i=0,j=0;
        while(i<words.size()){
            int charCnt=words[i].length(),spaceCnt=0;
            j=i+1;
            // By defaultly taking that every word has to be put a space for it which is less than max width
            while(j<words.size() and charCnt+spaceCnt+1+words[j].length()<=maxWidth){
                charCnt+=words[j].length();
                spaceCnt++;
                j++;
            }
            // Remaining number of spaces to be put
            int rem=maxWidth-charCnt;
            // To commonly distribute among taken set of words
            int equalDistribute=(spaceCnt==0)?0:rem/spaceCnt;
            // Remaining spaces out of evenly distributed has to be spread somewhere inside some words
            int extraDistribute=(spaceCnt==0)?0:rem%spaceCnt;
            // The last word has to be left justified
            if(j==words.size()){
                equalDistribute=1;
                extraDistribute=0;
            }
            string s;
            for(int k=i;k<j;k++){
                s+=words[k];
                if(k==j-1)
                    break;
                for(int p=0;p<equalDistribute;p++){
                    s.push_back(' ');
                }
                // One extra space for every word to get distributed
                if(extraDistribute>0){
                    s.push_back(' ');
                    extraDistribute--;
                }
            }
            // If the words and spaces cannot fill it upto the given maxWidth, then append as many spaces as possible at right side
            while(s.length()<maxWidth){
                s.push_back(' ');
            }
            ans.push_back(s);
            // Upto j we have made a justified string
            i=j;
        }
        return ans;
    }
};