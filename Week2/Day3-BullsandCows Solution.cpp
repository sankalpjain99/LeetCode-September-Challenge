class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int a=0,b=0;
        
        //Find Bulls and replace them with ' '
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                a++;
                secret[i]=' ';
                guess[i]=' ';
            }
        }
        
        //Make a set of remaining char in secret
        unordered_multiset<char> m;
        for(int i=0;i<n;i++){
            if(secret[i]!=' '){
                m.insert(secret[i]);
            }
        }
        
        //Check if remaining char of guess are in secret or not
        for(int i=0;i<n;i++){
            if(guess[i]!=' '){
                auto itr = m.find(guess[i]);
                if(itr!=m.end()){
                    b++;
                    m.erase(itr);
                }
            }
        }
        return to_string(a)+'A'+to_string(b)+'B';
    }
};
