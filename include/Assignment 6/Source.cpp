#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
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
    virtual size_t size() const = 0; 
};

template <typename ValueType>
class AdjacencyListGraph : public Graph<ValueType> {
private:
    vector<list<ValueType>> adjacencyList;

public:
    AdjacencyListGraph(size_t n) : adjacencyList(n) {}

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
        adjacencyList[dest].push_back(source); // For undirected graph
    }

    void addNode(ValueType x) override {
        if (x >= adjacencyList.size()) {
            adjacencyList.resize(x + 1);
        }
    }

    void deleteEdge(ValueType source, ValueType dest) override {
        adjacencyList[source].remove(dest);
        adjacencyList[dest].remove(source); // For undirected graph
    }

    void deleteNode(ValueType node) override {
        for (auto& neighbors : adjacencyList) {
            neighbors.remove(node);
        }
        adjacencyList[node].clear();
    }
    size_t size() const override {
        return adjacencyList.size();
    }
};

template <typename ValueType>
class AdjacencyMatrixGraph : public Graph<ValueType> {
private:
    vector<vector<bool>> adjacencyMatrix;

public:
    AdjacencyMatrixGraph(size_t n) : adjacencyMatrix(n, vector<bool>(n, false)) {}

    bool adjacent(ValueType x, ValueType y) override {
        return adjacencyMatrix[x][y];
    }

    vector<ValueType> neighbors(ValueType x) override {
        vector<ValueType> result;
        for (ValueType i = 0; i < adjacencyMatrix.size(); ++i) {
            if (adjacencyMatrix[x][i]) {
                result.push_back(i);
            }
        }
        return result;
    }

    void addEdge(ValueType source, ValueType dest) override {
        adjacencyMatrix[source][dest] = true;
        adjacencyMatrix[dest][source] = true; // For undirected graph
    }

    void addNode(ValueType x) override {
        if (x >= adjacencyMatrix.size()) {
            size_t n = x + 1;
            adjacencyMatrix.resize(n, vector<bool>(n, false));
            for (size_t i = 0; i < n; ++i) {
                adjacencyMatrix[i].resize(n, false);
            }
        }
    }

    void deleteEdge(ValueType source, ValueType dest) override {
        adjacencyMatrix[source][dest] = false;
        adjacencyMatrix[dest][source] = false; // For undirected graph
    }

    void deleteNode(ValueType node) override {
        size_t n = adjacencyMatrix.size();
        if (node < n) {
            for (size_t i = 0; i < n; ++i) {
                adjacencyMatrix[i][node] = false;
                adjacencyMatrix[node][i] = false;
            }
        }
    }
    size_t size() const override {
        return adjacencyMatrix.size();
    }
};

bool isSimpleCycleHelper(Graph<int>& graph, int current, int start, vector<bool>& visited, vector<int>& path) {
    if (current == start) {
        return path.size() == graph.size() && count(visited.begin(), visited.end(), true) == graph.size();
    }

    // Mark the current node as visited.
    visited[current] = true;
    path.push_back(current);

    // Recursive call to check neighbors.
    vector<int> neighbors = graph.neighbors(current);
    for (int neighbor : neighbors) {
        if (!visited[neighbor]) {
            if (isSimpleCycleHelper(graph, neighbor, start, visited, path)) {
                return true;
            }
        }
    }

   
    visited[current] = false;
    path.pop_back();
    return false;
}

bool isSimpleCycle(Graph<int>& graph, const vector<int>& path) {
    if (path.empty()) {
        return false;
    }

    // Find the maximum node in the graph to determine the size of the visited vector.
    int maxNode = *max_element(path.begin(), path.end());

    // Initialize visited array with the correct size and set all elements to false.
    vector<bool> visited(maxNode + 1, false);

    // Check if the first and last node in the path are the same.
    if (path.front() != path.back()) {
        return false;
    }
    else {
        return true;
    }

    // Check if the path visits each node at least once.
    for (size_t i = 0; i < path.size() - 1; ++i) {
        if (!graph.adjacent(path[i], path[i + 1])) {
            return false; // The path is not valid.
        }
    }

    // Check if the path is a simple cycle starting from the first node.
    return isSimpleCycleHelper(graph, path.front(), path.front(), visited, const_cast<vector<int>&>(path));
}


int main() {
    // Test the graph classes
    AdjacencyListGraph<int> graphList(5);
    graphList.addEdge(0, 1);
    graphList.addEdge(0, 2);
    graphList.addEdge(1, 3);
    graphList.addEdge(2, 4);
    graphList.addNode(5);

    cout << "Adjacency List Graph:" << endl;
    cout << "Is node 0 adjacent to node 1? " << (graphList.adjacent(0, 1) ? "Yes" : "No") << endl;
    cout << "Neighbors of node 0: ";
    vector<int> neighbors0 = graphList.neighbors(0);
    for (int neighbor : neighbors0) {
        cout << neighbor << " ";
    }
    cout << endl;

    AdjacencyMatrixGraph<int> graphMatrix(5);
    graphMatrix.addEdge(0, 1);
    graphMatrix.addEdge(0, 2);
    graphMatrix.addEdge(1, 3);
    graphMatrix.addEdge(2, 4);
    graphMatrix.addNode(5);

    cout << "\nAdjacency Matrix Graph:" << endl;
    cout << "Is node 0 adjacent to node 1? " << (graphMatrix.adjacent(0, 1) ? "Yes" : "No") << endl;
    cout << "Neighbors of node 0: ";
    vector<int> neighbors0Matrix = graphMatrix.neighbors(0);
    for (int neighbor : neighbors0Matrix) {
        cout << neighbor << " ";
    }
    cout << endl;

    // Create a graph (use either AdjacencyListGraph or AdjacencyMatrixGraph)
    AdjacencyListGraph<int> graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);
    graph.addEdge(0, 5);
    graph.addEdge(5, 1);

    // Test isSimpleCycle function with various paths
    vector<int> path1 = { 0, 1, 2, 3, 4, 0 };
    vector<int> path2 = { 0, 1, 2, 3, 4, 1, 0 };
    vector<int> path3 = { 0, 1, 2, 3, 4 };
    vector<int> path4 = { 0, 1, 2, 3, 4, 0, 5, 1 };

    cout << "Is path1 a simple cycle? " << (isSimpleCycle(graph, path1) ? "Yes" : "No") << endl;
    cout << "Is path2 a simple cycle? " << (isSimpleCycle(graph, path2) ? "Yes" : "No") << endl;
    cout << "Is path3 a simple cycle? " << (isSimpleCycle(graph, path3) ? "Yes" : "No") << endl;
    cout << "Is path4 a simple cycle? " << (isSimpleCycle(graph, path4) ? "Yes" : "No") << endl;

    return 0;
}
    