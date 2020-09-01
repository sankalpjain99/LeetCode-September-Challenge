class Solution {
public:
    
    //Function to check if given string is a valid timestamp or not
    bool isOkay(string s){
        int n1 = (int)(s[0]-'0');
        int n2 = (int)(s[1]-'0');
        int n3 = (int)(s[2]-'0');
        int n4 = (int)(s[3]-'0');
        int hrs = n1*10+n2;
        int mins = n3*10+n4;
        if(hrs>23 || mins>59)
            return false;
        return true;
    }
    
    //Backtracking function to check for all permutations of the given array
    void findPerms(string curr,vector<int>& a,string& ans){
        if(curr.size()==4){
            if(isOkay(curr))
                //Updating maximum possible time
                ans=max(ans,curr);
            return;
        }
        int n = a.size();
        for(int i=0;i<n;i++){
            int temp = a[i];
            curr+=to_string(temp);
            a.erase(a.begin()+i);
            findPerms(curr,a,ans);
            
            //BACKTRACK
            a.insert(a.begin()+i,temp);
            curr.pop_back();
        }
    }
    
    string largestTimeFromDigits(vector<int>& a) {
        string ans="";
        findPerms("",a,ans);
        
        //If empty, just return
        if(!ans.size())
            return ans;
        
        //Else add ':' to answer
        return ans.substr(0,2)+":"+ans.substr(2,2);
    }
};
