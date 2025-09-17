class FoodRatings {
public:
    map<string,pair<int,string>> foodRating;
    map<string,map<int,set<string>>> cuisineRating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodRating[foods[i]] = {ratings[i],cuisines[i]};
            cuisineRating[cuisines[i]][ratings[i]].insert(foods[i]);
        }
    }
    void changeRating(string food, int newRating) {
        auto it = foodRating[food];
        cuisineRating[it.second][it.first].erase(food);
        if(cuisineRating[it.second][it.first].size()==0){
            cuisineRating[it.second].erase(it.first);
        }
        cuisineRating[it.second][newRating].insert(food);
        foodRating[food] = {newRating,it.second};
    }
    string highestRated(string cuisine) {
        auto it = cuisineRating[cuisine].rbegin()->second;
        return *it.begin();
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */