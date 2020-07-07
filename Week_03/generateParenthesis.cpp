class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        vector<string> cur;
        cur.push_back("(");
        cur.push_back(")");
        generateAll(cur, 1, n*2, ans);
        return std::move( ans );
    }
private:
    void generateAll( vector< string>& cur, int pos, int len, vector<string>& ans ) {
        //terminator
        if ( pos == len ){
            //isvalid
            for ( auto it : cur ) {
                if ( isvalid ( it ) ){
                    ans.push_back( it );
                }
            }
            return;
        }
        //process current logic
        vector< string > next;
        for ( auto it : cur ) {
            next.push_back( it + '(' );
            next.push_back( it + ')' );
        }
        //drill down
        generateAll( next, pos+1, len, ans );
        //restore current status
    }

    bool isvalid( const string& cur ){
        stack<char> left;
        for ( auto it : cur ) {
            if ( it == '(' ){
                left.push( it );
            }else {
                if ( left.empty() == false ){
                    left.pop();
                }else {
                    return false;
                }
            }
        }
        return left.empty();
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        vector<string> cur;
        cur.push_back("(");
        generateAll(cur, 1, n*2, ans);
        return std::move( ans );
    }
private:
    void generateAll( vector< string>& cur, int pos, int len, vector<string>& ans ) {
        //terminator
        if ( pos == len ){
            //isvalid
            for ( auto it : cur ) {
                if ( isvalid ( it ) ){
                    ans.push_back( it );
                }
            }
            return;
        }
        //process current logic
        vector< string > next;
        for ( auto it : cur ) {
            next.push_back( it + '(' );
            next.push_back( it + ')' );
        }
        //drill down
        generateAll( next, pos+1, len, ans );
        //restore current status
    }

    bool isvalid( const string& cur ){
        stack<char> left;

        for ( auto it : cur ) {
            if ( it == '(' ){
                left.push( it );
            }else {
                if ( left.empty() == false ){
                    left.pop();
                }else {
                    return false;
                }
            }
        }
        return left.empty();
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string tmp;
        backtrack( tmp,0,0, n, ans);
        return std::move( ans );
    }
private:
    void backtrack( string& cur, int open, int close,int n,vector<string>& res ){
        //terminator
        if ( close == n ){
            res.push_back(cur);
            return ;
        }

        //process current logic
        if ( open < n ){
            cur += '('; // append open
            //drill down
            backtrack( cur, open+1, close, n,res );
            cur.resize( cur.length() - 1 );
        }

        if ( close < open ) {
            cur +=')'; //append close
            //drill down
            backtrack( cur, open, close+1, n, res);
            cur.resize( cur.length() - 1 );
        }

        //restore current status
    }
};
