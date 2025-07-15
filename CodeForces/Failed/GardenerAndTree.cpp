#include <iostream>
#include <vector>
#include <algorithm>


int main ()
{
    int t;
    std::cin >> t;

    int outputs[t];
    
    for (int c1 = 0; c1 < t; c1++)
    {
        int n; int k;
        std::cin >> n >> k;
    
        struct Node
        {
            Node ** neighbours;
            bool isPruned;
            int nCount;
            int sampleSize;
            Node(int n = 0)
            {
                isPruned = false;
                sampleSize = n;
                nCount = 0;
                neighbours = (Node**) malloc(sizeof(Node*) * n);
                for (int i = 0; i < n; i++) { neighbours[i] = nullptr; }
            }

            void AddNeighbour (Node * nb, int index) { neighbours[index] = nb; nCount++; }
            bool Operation (int thisIndex, Node * prior, std::vector<Node *> prevNodes)
            {
                prevNodes.push_back(this);
                if (nCount <= 0) return false;

                int pCount = nCount;
                for (int i = 0; i < sampleSize; i++)
                {
                    if (neighbours[i] != nullptr && neighbours[i] != prior)
                    {
                        if (!std::count(prevNodes.begin(), prevNodes.end(), neighbours[i]))
                        {
                            bool hasPruned = neighbours[i]->Operation(i, this, prevNodes);
                            if (prior == nullptr && pCount <= 1)
                            {
                                isPruned = true;
                                if (!hasPruned)
                                {
                                    neighbours[i]->neighbours[thisIndex] = nullptr;
                                    neighbours[i]->nCount--;
                                    neighbours[i] = nullptr;
                                    nCount = 0; 
                                }
                                return true;
                            }
                        }
                    }
                }

                if (pCount <= 1 && prior != nullptr)
                { 
                    prior->neighbours[thisIndex] = nullptr;
                    prior->nCount--;
                    nCount = 0;
                    isPruned = true;
                    return true;
                }
                return false;
            } 
        };
        
        Node nodeList[n];
        for (int i = 0; i < n; i++) { nodeList[i] = Node(n); }

        for (int i = 0; i < n - 1; i++)
        {
            int u; int v;
            std::cin >> u >> v;
            
            nodeList[u-1].AddNeighbour(&nodeList[v-1], v-1);
            nodeList[v-1].AddNeighbour(&nodeList[u-1], u-1);
        }
        
        bool cC = false;

        Node * root = &nodeList[0];
        std::vector<Node *> visited = { nullptr };
        int rootIndex;
        for (int i = 0; i < k; i++)
        {
            bool rootDeleted = root->Operation(rootIndex, nullptr, visited);
            bool foundReplacement = !rootDeleted;
            if (rootDeleted)
            {
                root = nullptr;
                for (int i = 0; i < n; i++)
                {
                    if (nodeList[i].nCount >= 1) { foundReplacement = true; root = &nodeList[i]; rootIndex = i; break; }
                }
            }
            if (!foundReplacement) { cC = true; outputs[c1] = 0; break; }
        }
        if (cC) continue;

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!nodeList[i].isPruned) { count++; }
        }
        outputs[c1] = count;
    }
    

    for (int i = 0; i < t; i++)
    {
        std::cout << outputs[i] << std::endl;
    }

    return 0;
}