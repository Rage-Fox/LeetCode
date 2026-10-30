class Solution {
public:
    int shortestPath(int hn, vector<vector<int>> &hedges, string hlabels, int hk) {
        vector<vector<pair<int,int>>> hg(hn);
        for(auto he:hedges){
            hg[he[0]].push_back({he[1],he[2]});
        }
        const long long hmaxx=1e18;
        vector<vector<long long>> hd(hn,vector<long long>(hk+1,hmaxx));
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> hpq;
        hd[0][1]=0;
        hpq.push({0,0,1});
        while(!hpq.empty()){
            auto hcurr=hpq.top();
            hpq.pop();
            long long hdist=hcurr[0];
            int hu=hcurr[1],hst=hcurr[2];
            if(hdist!=hd[hu][hst]){
                continue;
            }
            if(hu==hn-1){
                return hdist;
            }
            for(auto he:hg[hu]){
                int hv=he.first,hw=he.second;
                int hnst=(hlabels[hv]==hlabels[hu])?(hst+1):1;
                if(hnst>hk){
                    continue;
                }
                long long hnd=hdist+hw;
                if(hnd<hd[hv][hnst]){
                    hd[hv][hnst]=hnd;
                    hpq.push({hnd,hv,hnst});
                }
            }
        }
        return -1;
    }
};