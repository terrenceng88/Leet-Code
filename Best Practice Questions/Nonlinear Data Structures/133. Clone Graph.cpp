/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
*/

/*
Deep Clone -------------------------------------------------------------------------
An alternative is a deep copy, meaning that fields are dereferenced: 
rather than references to objects being copied, new copy objects are 
created for any referenced objects, and references to these placed in B. 
The result is different from the result a shallow copy gives in that the 
objects referenced by the copy B are distinct from those referenced by A, 
and independent. Deep copies are more expensive, due to needing to create 
additional objects, and can be substantially more complicated, due to 
references possibly forming a complicated graph.

Deep copy is a process in which the copying process occurs recursively. 
It means first constructing a new collection object and then recursively 
populating it with copies of the child objects found in the original. 
In case of deep copy, a copy of object is copied in other object. 
It means that any changes made to a copy of object do not reflect in the original object. 
In python, this is implemented using “deep copy()” function.
*/

//Runs in O(V + E) time complexity using DFS

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour; //vector to hold deep copy (clone) of graph
        Node* clone=new Node(cur->val); //create new cloned node
        mp[cur]=clone; //set current node in map to clone
            for(auto it:cur->neighbors) //iterate through all the neighbors of the current nodea
            {
                if(mp.find(it)!=mp.end())   //already clone and stored in map
                {
                    neighbour.push_back(mp[it]);    //directly push back the clone node from map to neighbor
                }
                else
                    neighbour.push_back(dfs(it,mp)); //recursively call dfs on neighbors of current node
            }
            clone->neighbors=neighbour; //directly push back all the cloned nodes to the original clone's neighbor vector
            return clone;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp; //map to store all the nodes that have been cloned so far
        if(node==NULL) //return NULL if invalid graph
            return NULL;
        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone = new Node(node->val); //clone and return sole node
            return clone; 
        }
        return dfs(node,mp); //recursively perform DFS to deep copy (clone) and return graph
    }
};