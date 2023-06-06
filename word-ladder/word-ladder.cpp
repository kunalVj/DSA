
class Solution {
public:
// take the begin word and push it into queue with count as 1
// now we can only change word by one letter to process further 
// store the given list in set
// while processing a word from queue change it's letter one by one from 'a' to 'z' and check if the word that we got by changing word[i] exists in set
// if exists then push it into the queue by incrementing count by +1 and remove from the set because we don't want to visit it again

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>>q;
        unordered_set<string> st (wordList.begin(), wordList.end());  // isert given wordlist into set
        q.push({beginWord, 1}); // push the starting word wit count as 1
        st.erase(beginWord);  // remove the word from set that we pushed into queue

        while(!q.empty()){
            string word = q.front().first; // 
            int count = q.front().second;
            q.pop();
            if(word == endWord){
                return count;
            }

            for(int i = 0; i < word.size(); i++){ // traverse aal the characters of the word
                char original = word[i];  // store the original character of word in original that we are going to change 
                // for eg. hit, store h in original as we are going to change h with characters a to z 

                for(char ch = 'a'; ch <= 'z'; ch++){  // change the character
                    word[i] = ch;
                    if(st.find(word) != st.end()){ // if the character is found in set 
                        q.push({word, count + 1}); // push it into queue and increase count
                        st.erase(word); // erase it from set 
                    }
                }

                word[i] = original; // change back the characterto it's original form, for eg. from ait, bit,___, zit to original 'hit' and now change other chracters like i and t one by one
            }
        }

       return 0; // return 0 if no sequence exist
    }
};
// tc = N X word.lenght * 26, where N = N is the total number of words in the input word list.