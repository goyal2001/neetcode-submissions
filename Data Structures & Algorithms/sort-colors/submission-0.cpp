class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int two = nums.size()-1;
        int k=0;
        if(two==0) return;
        while(k<=two){
            if(nums[k]==2){
                swap(nums[k],nums[two--]);
            }
            else if(nums[k]==0){
                swap(nums[k++],nums[zero++]);
            }
            else
              k++;
        }
    }
};