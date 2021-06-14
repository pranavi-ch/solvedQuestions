class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> umap;
        
        // fill the entire map
        for(int i=0;i<nums2.size();i++){
            if(st.empty() || nums2[i] <= st.top()){
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && st.top() < nums2[i]){
                    int num = st.top(); st.pop();
                    umap[num] = nums2[i];
                }
                st.push(nums2[i]);
            }
        } // end for
        for(int i=0;i<nums1.size();i++){
            nums1[i] = (umap.find(nums1[i])!=umap.end())?umap[nums1[i]]:-1;
        }
        return nums1;
    }
};
