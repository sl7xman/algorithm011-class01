class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0];
        int c = click[1];
        int nr = board.size();
        int nc = board[0].size();
        if ( board[r][c] == 'M' ){
            board[r][c] ='X';
            return board;
        }

        int m_count = cal_m_count(board, click);
        if( m_count ){
            board[r][c] =m_count+'0';
            return board;
        }
        board[r][c] ='B';
        set<vector<int>> search_pos;
        set<vector<int>> visited;
        visited.insert(click);
        
        add_search_pos(search_pos, click, nr, nc, visited);

        while( search_pos.size() ){
            auto it = search_pos.begin();
            vector<int> cur_click = *it;
            visited.insert(cur_click);
            search_pos.erase(it);
            int cr = cur_click[0];
            int cc = cur_click[1];
            m_count = 0;
            m_count = cal_m_count(board, cur_click);
            if( m_count ){
                board[cr][cc] =m_count+'0';
            }else{
                board[cr][cc] ='B';
                add_search_pos(search_pos, cur_click, nr, nc, visited);
            }
        }

        return board;
    }

private:
    void add_search_pos(set<vector<int>>& search_pos, vector<int>& click, int nr, int nc , set<vector<int>>& visited) {

        int r = click[0];
        int c = click[1];
        if( r -1 >=0  ){
            if( visited.find({r-1, c}) == visited.end())
                search_pos.insert({r-1, c});    
        }

        if( r -1 >=0  && c - 1 >= 0){
            if( visited.find({r-1, c-1}) == visited.end())
                search_pos.insert({r-1, c-1});
        }

        if( r -1 >=0  && c + 1 < nc ){
            if( visited.find({r-1, c+1}) == visited.end())
                search_pos.insert({r-1, c+1});
        }

        if(  c - 1 >= 0){
            if( visited.find({r, c-1}) == visited.end())
                search_pos.insert({r, c-1});
        }
        
        if( c + 1 < nc){
            if( visited.find({r, c+1}) == visited.end())    
                search_pos.insert({r, c+1});
        }

        if( r + 1 < nr  ){
            if( visited.find({r+1, c}) == visited.end())
                search_pos.insert({r+1, c});
        }

        if( r + 1 < nr  && c - 1 >= 0){
            if( visited.find({r+1, c-1}) == visited.end())
                search_pos.insert({r+1, c-1});
        }

        if( r + 1 < nr  && c + 1 < nc){
            if( visited.find({r+1, c+1}) == visited.end())
                search_pos.insert({r+1, c+1});
        }
    }

    int cal_m_count(vector<vector<char>>& board, vector<int>& click ){
        int nr = board.size();
        int nc = board[0].size();
        int r = click[0];
        int c = click[1];
        int m_count =0;
        if ( r -1 >= 0 && board[r-1][c] =='M' ){
            ++m_count;
        }
        if( r+1 < nr && board[r+1][c] =='M' ){
            ++m_count;
        }
        if( c -1 >=0 && board[r][c-1] == 'M' ){
            ++m_count;
        }
        if( c + 1 < nc && board[r][c+1] == 'M' ){
            ++m_count;
        }
        if( c-1 >=0 && r-1 >=0 && board[r-1][c-1] == 'M' ) {
            ++m_count;
        }
        if( c -1 >= 0 && r+1 <nr && board[r+1][c-1] =='M') {
            ++m_count;
        }
        if( c+1 < nc && r-1 >=0 && board[r-1][c+1] =='M'){
            ++m_count;
        }
        if( c+1 < nc && r+1 < nr && board[r+1][c+1] =='M' ) {
            ++m_count;
        }
        return m_count;
    }
};
