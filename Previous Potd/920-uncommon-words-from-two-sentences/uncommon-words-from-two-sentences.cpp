class Solution {
public:
    void countWords( string &sentence, unordered_map<string, int> &wordCount) {
        stringstream ss(sentence);//stl use to split the string
        string word;
        while (ss >> word) {  //imp operter it push words form ss,one by one into word string 
          // cout<<word<<endl;
           wordCount[word]++;
         }
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
         unordered_map<string, int> wordCount;
         countWords(s1, wordCount);
         countWords(s2, wordCount);
    
         vector<string> result;
    
         for (auto x : wordCount) {
            if (x.second == 1) {
               result.push_back(x.first);
            }
         }
         return result;
    }
};