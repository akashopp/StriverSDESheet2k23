#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	graphNode* clone = new graphNode(node->data);
	unordered_map<graphNode*, graphNode*>mpp;
	queue<graphNode*>q;
	mpp[node] = clone;
	q.push(node);
	while(!q.empty()){
		auto temp = q.front();
		q.pop();
		for(auto it : temp->neighbours){
			if(mpp.find(it) == mpp.end()){
				mpp[it] = new graphNode(it->data);
				q.push(it);
			}
			mpp[temp]->neighbours.push_back(mpp[it]);
		}
	}
	return clone;
}
