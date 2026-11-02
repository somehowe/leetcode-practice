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
        if (!node) return nullptr;
        queue<Node *> q;
        unordered_map<Node *, Node *> ogToNew;
        q.push(node);
        ogToNew[node] = new Node(node->val);
        // our invariant is if it is in the visited list then we have added it to our map
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();
            for (const auto& nxt : curr->neighbors) {
                if (!ogToNew.contains(nxt)) {
                    // means we have yet to create the new node either
                    ogToNew[nxt] = new Node(nxt->val);
                    q.push(nxt);
                }
                // we should add this as a connection
                ogToNew[curr]->neighbors.push_back(ogToNew[nxt]);
            }
        }
        return ogToNew[node];
    }
};