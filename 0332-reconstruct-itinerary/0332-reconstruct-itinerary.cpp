class Solution {
private:
    void visit(string airport, map<string, multiset<string>> &targets, 
              vector<string> &route) {
        while (size(targets[airport])) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next, targets, route);
        }
        route.emplace_back(airport);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> route;
        map<string, multiset<string>> targets;
        for (const vector<string> &ticket : tickets)
            targets[ticket[0]].insert(ticket[1]);
        visit("JFK", targets, route);
        return vector<string> (rbegin(route), rend(route));
    }
};