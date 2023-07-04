class Solution {
public:
    string reverseWords(string s) {
   stack<string> reversed; // Create a stack to store the reversed words
   string result; // Create an empty string variable to store the final result

   for(int i = 0; i < s.size(); i++){ // Loop through each character in the input string
       string word; // Create an empty string variable to store individual words
       if(s[i] == ' ') // Skip whitespace characters
            continue;
        while(i < s.size() && s[i] != ' '){ // Construct a word by iterating until a space is encountered
            word += s[i]; // Append the current character to the word
            i++; // Move to the next character
        }
        reversed.push(word); // Push the constructed word to the stack
   }
   
   // Pop the words from the stack and construct the reversed sentence
   while(!reversed.empty()){
       result += reversed.top(); // Append the top word from the stack to the result string
       reversed.pop(); // Remove the top word from the stack
       if(!reversed.empty())
        result += " "; // Add a space between words, except for the last word
   }
   
   return result; // Return the final reversed sentence
}
       
    };