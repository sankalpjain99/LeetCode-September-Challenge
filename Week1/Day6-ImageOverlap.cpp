class Solution {
public:
    
    int helper(vector<vector<int>>& a, vector<vector<int>>& b){
        int n = a.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int temp=0;
                for(int x=i;x<n;x++){
                    for(int y=j;y<n;y++){
                        if(a[x][y] && b[x-i][y-j])
                            temp++;
                    }
                }
                ans=max(ans,temp);
            }
        }
        return ans;
    }

    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        return max(helper(a,b),helper(b,a));
    }
    
};
