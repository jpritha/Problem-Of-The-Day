// Link : https://leetcode.com/problems/my-calendar-i/

/*T.C : O(logN), O(log(N)) time complexity is required for insert and lowerbound operation of the set.
S.C: O(N), for maintaining all the booked slots.                 */


class MyCalendar {
    set<pair<int, int>> times;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        auto next = times.lower_bound({start, end});
        if(next != times.end() && next->first<end) return false;
        if(next != times.begin() && start < (--next)->second) return false;
        
        times.insert({start, end});
        
        return true;
    }
};


/*                              O(N) Solution :
class MyCalendar {
    vector<pair<int, int>> times;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for(pair<int,int> p : times) {
            if(max(p.first, start) < min(p.second, end)) {
                return false;
            }
        }
        times.push_back({start, end});
        
        return true;
    }
};
*/

/* eg :1> [10,20] and [15,25]      :false
       2> [10,20] and [15,18]      :false
*/



/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */