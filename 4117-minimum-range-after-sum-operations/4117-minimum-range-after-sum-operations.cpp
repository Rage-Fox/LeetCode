class Solution {
public:
    int minRange(int a, int b, int c) {
        /*
        (a,b,c) = sort(a,b,c) , a<=b<=c
            0. no ops. ans = mx - mn == c-a
            1. a=b+c , ans = b+c-b = c
            2. b=a+c , ans = a+c-a = c
            3. c=a+b , ans = a+b-a = b
        */
        vector<int> arr = {a, b, c};
        sort(arr.begin(), arr.end());
        a = arr[0], b = arr[1], c = arr[2];
        return min({c - a, b, c});
    }
};