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
    Node* cloneGraph(Node* node) {
        // maybe we do a mapping of og to our new nodes.
        // in our first pass we only worry about getting value right and then we can do neighbors.
        unordered_set<Node *> visited;
        queue<Node *> q;
        unordered_map<Node *, Node *> ogToNew;
        if (node) q.push(node);
        if (node) visited.insert(node);
        while (!q.empty()) {
            Node * curr = q.front();
            q.pop();
            Node *copy = new Node(curr->val);
            ogToNew[curr] = copy;
            // iteratre through the neighbors:
            for (const auto& nxt : curr->neighbors) {
                if (!visited.contains(nxt)) {
                    visited.insert(nxt);
                    q.push(nxt);
                }
            }
        }
        // now we have all our nodes and need to link them up correctly
        // q is empty
        visited.clear();
        visited.insert(node);
        if (node) q.push(node);
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();
            Node *currCopy = ogToNew[curr];
            for (const auto& nxt : curr->neighbors) {
                if (!visited.contains(nxt)) {
                    visited.insert(nxt);
                    q.push(nxt);
                }
                currCopy->neighbors.push_back(ogToNew[nxt]);
            }
            
        }

        return ogToNew[node];
    }
};