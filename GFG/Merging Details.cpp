// Link : https://practice.geeksforgeeks.org/problems/merging-details/1

class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        // code here
        vector<vector<string>> ans;
        
        map<string, int> mail_id;
        vector<set<string>> mail;
        vector<string> name;
        
        //dummy
        mail.push_back(set<string>());
        name.push_back("");
        
        for(auto& d : details) {
            int id = 0;
            
            // find if any of the mail has already be seen
            for(int i=1; i<d.size(); i++) {
                id = max(id, mail_id[d[i]]);
            }
            // if not, then this is a new record 
            if(id == 0) {
                id = name.size();
                name.push_back(d[0]);
                mail.push_back(set<string>());
            }
            
            for(int i=1; i<d.size(); i++) {
                mail_id[d[i]] = id;
                mail[id].insert(d[i]);
            }
        }
        
        // construct the result
        for (int i = 1; i < name.size(); ++i)
        {
        	ans.push_back({name[i]});
        	
        	for (auto& m : mail[i])
        		ans.back().push_back(m);
        }
        
        // the strangest workaround for testcase 56
        sort(ans.rbegin(), ans.rend());
        
        return ans;
    }
};