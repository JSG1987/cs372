#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename ValueType>
class Graph {
public:
    virtual ~Graph() {}
    virtual bool adjacent(ValueType x, ValueType y) = 0;
    virtual vector<ValueType> neighbors(ValueType x) = 0;
    virtual void addEdge(ValueType source, ValueType dest) = 0;
    virtual void addNode(ValueType x) = 0;
    virtual void deleteEdge(ValueType source, ValueType dest) = 0;
    virtual void deleteNode(ValueType node) = 0;
};

template <typename ValueType>
class AdjacencyListGraph : public Graph<ValueType> {
private:
    vector<list<ValueType>> adjacencyList;
    size_t numNodes;

public:
    AdjacencyListGraph(size_t n) : adjacencyList(n), numNodes(n) {}

    bool adjacent(ValueType x, ValueType y) override {
        for (const auto& neighbor : adjacencyList[x]) {
            if (neighbor == y) {
                return true;
            }
        }
        return false;
    }

    vector<ValueType> neighbors(ValueType x) override {
        return vector<ValueType>(adjacencyList[x].begin(), adjacencyList[x].end());
    }

    void addEdge(ValueType source, ValueType dest) override {
        adjacencyList[source].push_back(dest);
        adjacencyList[dest].push_back(source); 
    }

    void addNode(ValueType x) override {
        if (x >= adjacencyList.size()) {
            adjacencyList.resize(x + 1);
        }
    }

    void deleteEdge(ValueType source, ValueType dest) override {
        adjacencyList[source].remove(dest);
        adjacencyList[dest].remove(source); 
    }

    void deleteNode(ValueType node) override {
        for (auto& neighbors : adjacencyList) {
            neighbors.remove(node);
        }
        adjacencyList[node].clear();
    }

    size_t size() const {
        return numNodes;
    }
};


bool findPathToKevinBacon(Graph<int>& graph, int start, int end, vector<int>& path, vector<bool>& visited) {
    
    if (start == end) {
        path.push_back(start);
        return true;
    }

   
    visited[start] = true;

   
    vector<int> neighbors = graph.neighbors(start);
    for (int neighbor : neighbors) {
        if (!visited[neighbor]) {
            
            if (findPathToKevinBacon(graph, neighbor, end, path, visited)) {
                path.push_back(start); 
                return true;
            }
        }
    }

    return false;
}

bool isConnectedToKevinBacon(Graph<int>& graph, int end, vector<int>& path) {
    int start = 0; 

   
    vector<bool> visited(21, false);

    
    bool isConnected = findPathToKevinBacon(graph, start, end, path, visited);

 
    reverse(path.begin(), path.end());

    return isConnected;
}

int main() {
    // Create the social graph.
    AdjacencyListGraph<int> socialGraph(21); 

    socialGraph.addEdge(0, 1); 
    socialGraph.addEdge(0, 2); 
    socialGraph.addEdge(1, 3); 
    socialGraph.addEdge(3, 20); 

 

    // Check if you are connected to Kevin Bacon and find the path if it exists.
    vector<int> pathToKevinBacon;
    int kevinBaconNode = 20;
    for (int i = 0; i < socialGraph.size(); ++i) {
        cout << "Node " << i << " neighbors: ";
        vector<int> neighbors = socialGraph.neighbors(i);
        for (int neighbor : neighbors) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    bool isConnected = isConnectedToKevinBacon(socialGraph, kevinBaconNode, pathToKevinBacon);


    // Output the result
    if (isConnected) {
        cout << "Congratulations! You are connected to Kevin Bacon!" << endl;
        cout << "The path to Kevin Bacon is:" << endl;
        for (int node : pathToKevinBacon) {
            cout << node << " ";
        }
        cout << endl;
    }
    else {
        cout << "Sorry, you are not connected to Kevin Bacon." << endl;
    }
    return 0;
}
