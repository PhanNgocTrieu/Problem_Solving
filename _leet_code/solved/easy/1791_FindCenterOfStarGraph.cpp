/*
    There is an undirected star graph consisting of n nodes labeled from 1 to n. 
    A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.
    
    You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi.
    Return the center of the given star graph.
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
	    cin.tie(nullptr);
#ifdef GREEDY
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
#endif

#ifdef DegreeCount
        int res = 0;
        map<int,int> mapping;
        for (auto e : edges) {
            if (++mapping[e[0]] >= 2) {
                return e[0];
            }
            if (++mapping[e[1]] >= 2) {
                return e[1];
            }
        }
        return res;
#endif
    }
};
