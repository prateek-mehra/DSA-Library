class Solution {
public:
    
    
    bool dfs(string &s, long long prev, int index, int cnt)
    {
        if(index == s.size()) return cnt > 1;
        
        unsigned long long num = 0;
        
        for(int i = index; i < s.size(); i++){
            
            num = num * 10 + s[i] - '0';
            
            if(prev == - 1 || num == prev - 1){
                if(dfs(s, num, i + 1, cnt + 1)) return true;
            }
                   
            if(num > prev && prev != -1)
                   break;
        }
        
        return false;
    }
    
    
    
    bool splitString(string s) {
        int n = s.size();
        
        if(n <= 1)
            return false;
        
        return dfs(s, -1, 0, 0);
    }
};
