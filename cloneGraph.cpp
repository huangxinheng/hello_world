/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<int,UndirectedGraphNode*> map;
        return clone(node,map);
    }
    UndirectedGraphNode* clone(UndirectedGraphNode* node,unordered_map<int,UndirectedGraphNode*>& map){
        if(node==NULL)
            return node;
        if(map.count(node->label))
            return map[node->label]; // has found node
        UndirectedGraphNode* t=new UndirectedGraphNode(node->label);
        map[node->label]=t;
        for(int i=0;i<node->neighbors.size();i++){
            (t->neighbors).push_back(clone(node->neighbors[i],map));
        }
        return t;
    }
};