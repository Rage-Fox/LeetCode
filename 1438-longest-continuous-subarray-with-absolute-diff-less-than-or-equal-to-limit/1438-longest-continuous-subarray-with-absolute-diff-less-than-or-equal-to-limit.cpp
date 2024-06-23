class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // In a subarray, if max-min<=limit, then all other elements will definitely pass it
        // Multi set can store duplicate elements in a sorted order all the time
        multiset<int> ms;
        int left=0,ans=1;
        for(int right=0;right<nums.size();right++){
            // Using sliding window and moving right pointer till the condition satisfies
            ms.insert(nums[right]);
            // If not, then move left pointer and erasing nums[left] from multiset
            // No matter you erase any times, you always find min and max from multiset
            while(!ms.empty() && *ms.rbegin()-*ms.begin()>limit){
                ms.erase(ms.find(nums[left++]));
            }
            // Store the size of the longest non-empty subarray
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};