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
    // it will return the copied node that satisfies everything
    Node *clone(Node *node, map<Node *, Node *> &copies) {
        if (!node) return nullptr;
        if (copies.contains(node)) return copies[node]; // we have already gone through this one
        copies[node] = new Node(node->val);
        for (Node *neighbor : node->neighbors) {
            copies[node]->neighbors.push_back(clone(neighbor, copies));
        }
        return copies[node];
    }
    Node* cloneGraph(Node* node) {
        // let's do dfs approach
        map<Node *, Node *> copies;
        return clone(node, copies);
    }
};