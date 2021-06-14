class Solution {
public:
    
    int first(vector<int>& nums,int n,int lb,int ub, int key){
        if(ub >= lb){
            int mid = lb + (ub-lb)/2;
            
            if( (mid == 0  || key > nums[mid-1]) && key == nums[mid])
                return mid;
            else if(key > nums[mid])
              return first(nums,n,mid+1,ub,key);
            else
                return first(nums,n,lb,mid-1,key);
            
        }
        return -1;
    }
    
    int last(vector<int>& nums, int n,int lb,int ub, int key){
        if(ub >= lb){
            int mid = lb+ (ub-lb)/2;
            
            if((mid == n-1 || key < nums[mid+1]) && key == nums[mid])
                return mid;
            else if(key < nums[mid])
                return last(nums,n,lb,mid-1,key);
            else
                return last(nums,n,mid+1,ub,key);
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        if(n == 0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(first(nums,n,0,n-1,target));
        ans.push_back(last(nums,n,0,n-1,target));
return ans;
    }
};
