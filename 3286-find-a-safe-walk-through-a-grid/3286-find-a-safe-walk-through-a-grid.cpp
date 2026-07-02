typedef long long ll;
struct hnod{
    int hx,hy,hhleft;
};
class Solution {
public:
    bool isvalidated(int hx,int hy,int hm,int hn){
        return hx>=0 and hy>=0 and hx<hm and hy<hn;
    }
    bool findSafeWalk(vector<vector<int>> &hgrid,int hh){
        int hm=hgrid.size(),hn=hgrid[0].size();
        vector<pair<int,int>> hdir={{0,1},{1,0},{0,-1},{-1,0}};
        queue<hnod> hq;
        hq.push({0,0,hh-hgrid[0][0]});
        vector<vector<int>> hvist(hm,vector<int>(hn,-1));
        hvist[0][0]=hh;
        while(!hq.empty()){
            hnod hcurr=hq.front();
            hq.pop();
            int hx=hcurr.hx,hy=hcurr.hy;
            int hcurrh=hcurr.hhleft;
            if(hx==hm-1 and hy==hn-1 and hcurrh>=1){
                return true;
            }
            for(auto dir:hdir){
                int hnx=hx+dir.first,hny=hy+dir.second;
                if(isvalidated(hnx,hny,hm,hn)){
                    int hnewh=hcurrh-hgrid[hnx][hny];
                    if(hnewh>0 and hvist[hnx][hny]<hnewh){
                        hvist[hnx][hny]=hnewh;
                        hq.push({hnx,hny,hnewh});
                    }
                }
            }
        }
        return false;
    }
};