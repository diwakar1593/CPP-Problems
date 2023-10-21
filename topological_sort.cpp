class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V] = {0};
	    for(int i = 0; i<V; i++){
	        for(auto it : adj[i]) indegree[it]++;
	    }
	    queue<int> qu;
	    for(int i = 0; i<V; i++){
	        if(indegree[i] == 0)
	            qu.push(i);
	    }
	    vector<int> topoSort;
	    while(!qu.empty()){
	        int node = qu.front();
	        qu.pop();
	        topoSort.push_back(node);
	        for(auto it : adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) qu.push(it);
	        }
	    }
	    return topoSort;
	}
};
