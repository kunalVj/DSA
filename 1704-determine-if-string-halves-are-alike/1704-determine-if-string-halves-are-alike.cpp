class Solution {
public:
    bool vowel(char c){
        if(c=='a'|| c=='A'|| c=='e'|| c=='E'|| c=='i'|| c=='I'|| c=='o'|| c=='O'||c=='u'||c=='U'){
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int l=s.length();
        int c1=0, c2=0
;
        for(int i=0; i<l/2; i++){
            if(vowel(s[i])) c1++;
        }
        
        for(int i=l/2; i<l; i++){
            if(vowel(s[i])) c2++;
        }
        
        return c1==c2;
    }
};