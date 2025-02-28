class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r= n-1;
        int max_a=INT_MIN;

        while(l<r){

            int area= (r-l)*(min(height[r],height[l]));
            max_a=max(max_a,area);

            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return max_a;

        
    }
};