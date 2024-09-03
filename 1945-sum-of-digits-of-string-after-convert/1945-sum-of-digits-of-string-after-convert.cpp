class Solution {
public:
    int getLucky(string s,int k){
        int hsum=0;
        string hres;
        for(char hc:s){
            hres.append(to_string((int)hc-97+1));
        }
        for(int i=0;i<k;i++){
            for(char hc:hres){
                hsum+=(int)hc-48;
            }
            hres.clear();
            hres.append(to_string(hsum));
            hsum=0;
        }
        return stoi(hres);
    }
};