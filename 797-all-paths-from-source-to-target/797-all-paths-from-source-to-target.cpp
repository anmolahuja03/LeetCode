class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int>& currPath, int node) {
        // Adding the node to current path
        currPath.push_back(node);
        // Adding the current path when reached the (n - 1) node
        if(node == graph.size() - 1) 
            // Storing all the paths
            paths.push_back(currPath);
        else {
            // Graph traversal
            for(auto x : graph[node]) {
                dfs(graph, paths, currPath, x);
            }
        }
        // Backtrack
        currPath.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // Resultant vector to store all the formed paths
        vector<vector<int>> paths;
        // Inorder to store the current path
        vector<int> currPath;
        // Starting from node 0 initially
        dfs(graph, paths, currPath, 0);
        return paths;
    }
};