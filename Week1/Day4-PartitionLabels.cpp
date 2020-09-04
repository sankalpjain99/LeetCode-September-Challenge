class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int last[26];
        memset(last,-1,sizeof(last));
        int n = s.size();
        
        //Find the last index where every letter occurs, else -1
        for(int i=0;i<n;i++){
            int c = (int)(s[i]-'a');
            last[c]=i;
        }
        
        //Visited array to keep track of used letters
        bool vis[26]={false};
        
        int start=0,end=last[(int)(s[0]-'a')];
        vis[(int)(s[0]-'a')]=true;
        
        for(int i=1;i<n;i++){
            int d = (int)(s[i]-'a');
            if(!vis[d]){
                vis[d]=true;
                
                //If letter starts after the current end, push current partition length to ans and update start and end
                if(i>end){
                    ans.push_back(end-start+1);
                    start=i;
                    end=last[d];
                }
                
                //Update end if last occurence is after current end
                if(last[d]>end)
                    end=last[d];   
            }
        }
        //Add last partition to ans
        ans.push_back(n-1-start+1);
        
        return ans;
    }
};
