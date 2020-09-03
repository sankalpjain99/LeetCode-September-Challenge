//TAKEN FROM  @lllllll2

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        //Add string to itself
        string temp = s+s;
        
        //Remove first and last characters to avoid taking the whole string into account
        temp=temp.substr(1);
        temp=temp.substr(0,temp.size()-1);
        
        return temp.find(s)!=-1;
    }
};
