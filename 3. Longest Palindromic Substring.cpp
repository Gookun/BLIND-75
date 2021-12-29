class Solution {
public:
    string expand(string& s, int i, int j){
        if(s[i]!=s[j])
            return "";
        while(i-1>=0&&j+1<s.length()&&s[i-1]==s[j+1]){
            --i;
            ++j;
        }
        return s.substr(i,j-i+1);
    }
    
    string longestPalindrome(string s) {
        if(s.length()==0)
            return "";
        if(s.length()==1)
            return s;
        string ans;
        for(int i=0;i<s.length();i++){
           string str1=expand(s,i,i);
           string str2=expand(s,i,i+1);
           str1=(str1.length()>=str2.length())?str1:str2;
           ans=(ans.length()>=str1.length())?ans:str1;
        }
        return ans;
    }
};