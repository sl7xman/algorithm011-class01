class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int word_len = beginWord.length();
        int word_num = wordList.size();
        vector<set<string>> levels ( word_num + 1, set<string>() );
        vector<int> flags( word_num, 0);

        levels[0].insert(beginWord);

        for( int i = 0; i < levels.size(); ++i ) {
            for( auto it = levels[i].begin(); it != levels[i].end(); ++it ) {
                for ( int k = 0; k < word_num; ++k ){
                    if ( flags[k] == 1) {
                        continue;
                    }
                    int l = 0;
                    int cnt = 0;

                    while( l < word_len && cnt <=1 ) {
                        if ( (*it)[l] != wordList[k][l] ){
                            ++cnt;
                        }
                        ++l;
                    }
                    if ( cnt == 1 ){
                        flags[k] = 1;
                        levels[i+1].insert(wordList[k]);
                        if ( wordList[k] == endWord ){
                            return i+2;
                        }
                    }
                }
            }
        }
        return 0;
    }
};
