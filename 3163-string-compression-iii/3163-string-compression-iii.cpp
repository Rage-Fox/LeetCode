class Solution {
public:
    string compressedString(string hword) {
        string hcomp="";
        int hn=hword.length(),hi=0;
        while(hi<hn){
            char hc=hword[hi];
            int hcount=0;
            while(hi<hn && hword[hi]==hc && hcount<9){
                hcount++;
                hi++;
            }
            hcomp+=to_string(hcount)+hc;
        }
        return hcomp;
    }
};