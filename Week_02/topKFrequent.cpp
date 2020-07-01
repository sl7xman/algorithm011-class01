class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto i : nums){
            ++m[i];
        }
        priority_queue< pair<int,int>, vector< pair<int,int> >, CmpByValue> heap;
        int count = 0;
        auto it = m.begin();
        for (; it != m.end(); ++it,++count ) {
            if ( count == k ) {
                break;
            }
            heap.push( *it );
        }
        for (; it != m.end(); ++it ) {
            if ( heap.top().second < it->second ){
                heap.pop();
                heap.push(*it);
            }
        }
        vector<int> ans;
        while( !heap.empty() ) {
            ans.push_back(heap.top().first);
            heap.pop();
        }
        return std::move(ans);
    }

    struct CmpByValue {
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs ) {
            return lhs.second > rhs.second;
        }
    };
};
