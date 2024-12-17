class Solution {
public:
    auto profit(double pass,double total){
        return ((pass+1)/(total+1))-((pass)/(total));
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // The more students you add to a class, the smaller the change in pass ratio becomes.
        double total=0;
        priority_queue<pair<double,vector<int>>> pq;
        for(int i=0;i<classes.size();i++){
            total+=(double)classes[i][0]/classes[i][1];
            pq.push({profit(classes[i][0],classes[i][1]), {classes[i][0],classes[i][1]}});
        }
        while(extraStudents--){
            auto [pfit,arr]=pq.top();
            pq.pop();
            total+=pfit;
            pq.push({profit(arr[0]+1,arr[1]+1),{arr[0]+1,arr[1]+1}});
        }
        return total/classes.size();
    }
};