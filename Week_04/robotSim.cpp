class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        set<string> o;
        for ( vector<int> obstacle: obstacles ) {
            string tmp = "("+ std::to_string(obstacle[0])+","+ to_string(obstacle[1]) +")";
            o.insert(  tmp  );
        }
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;

        for ( int cmd : commands ) {
            switch ( cmd ){
                case -2:
                    di = ( di + 3 )%4;
                break;
                case -1:
                    di = ( di + 1) %4;
                break;
                default:
                    for ( int k = 0; k < cmd; ++k ) {
                        int nx = x + dx[di];
                        int ny = y + dy[di];
                        string tmp = "("+ to_string(nx)+","+ to_string(ny)+")"; 
                        if ( o.find( tmp ) == o.end()) {
                            x = nx;
                            y = ny;
                            ans = max( ans, x*x + y*y);
                        }
                    }
                break;
            }
        }

        return ans;
    }
};


