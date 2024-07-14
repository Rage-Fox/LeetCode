class Solution {
public:
    string countOfAtoms(string formula) {
        map<string,int> atomCount;
        formula+=')';
        int n=formula.size();
        stack<pair<string,int>> s;
        s.push({"(",0});
        for(int i=0;i<n;){
            if(isupper(formula[i])){ 
                int j=i;
                string atom="";
                atom+=formula[j++];
                while(j<n and islower(formula[j])){
                    atom+=formula[j++];
                }
                int freq=0;
                while(j<n and isdigit(formula[j])){
                    freq=freq*10+formula[j++]-'0';
                }
                if(freq==0){
                    freq=1;
                }
                s.push({atom,freq});
                i=j;
            }
            else if(formula[i]==')'){ 
                int j=i+1;
                int freq=0;
                while(j<n and isdigit(formula[j])){
                    freq=freq*10+formula[j++]-'0';
                }
                if(freq==0){
                    freq=1;
                }
                stack<pair<string,int>> temp;
                while(s.top().first!="("){
                    auto t=s.top();
                    s.pop();
                    temp.push({t.first,t.second*freq});
                }
                s.pop();
                while(!temp.empty()){
                    s.push(temp.top());
                    temp.pop();
                }
                i=j;
            }
            else if(formula[i]=='('){
                s.push({"(",0});
                i++;
            }
        }
        while(!s.empty()){
            auto t=s.top();
            s.pop();
            atomCount[t.first]+=t.second; 
        }
        string result;
        for(auto x:atomCount){
            result+=x.first+(x.second>1?to_string(x.second):"");
        }
        return result;
    }
};