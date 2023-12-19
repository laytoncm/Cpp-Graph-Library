#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string edgeString(tuple<string, string, int>); //Useful for print edges

void printResult(const std::vector<std::string>& result, const std::string& testName);
void printMST(const Graph& mst, const std::string& testName);

void DFSTest(Graph graph);
void BFSTest(Graph graph);
void PrimsTest(Graph graph);

int main() {
      // Create a Graph instance
  Graph graph;

  // Add nodes and edges to the graph
    graph.addNode("A");
    graph.addNode("B");
    graph.addNode("C");
    graph.addNode("D");
    graph.addNode("E");
    graph.addNode("F");
    graph.addNode("G");
    graph.addEdge("A", "B");
    graph.addEdge("B", "C");
    graph.addEdge("B", "D");
    graph.addEdge("D", "E");
    graph.addEdge("F", "G");

    cout << graph.getInfo() << endl;
    DFSTest(graph);
    BFSTest(graph);
    PrimsTest(graph);

    return 0;
}

void printResult(const std::vector<std::string>& result, const std::string& testName) {
    std::cout << testName << ": ";
    if (result.empty()) {
        std::cout << "Path not found or invalid input.";
    } else {
        for (const auto& node : result) {
            std::cout << node << " ";
        }
    }
    std::cout << std::endl;
}

void printMST(const Graph& mst, const std::string& testName) {
    std::cout << testName << " MST Edges: ";
    for (const auto& edge : mst.getEdges()) {
        std::cout << std::get<0>(edge) << " - " << std::get<1>(edge) << " (" << std::get<2>(edge) << ") ";
    }
    std::cout << std::endl;
}

string edgeString(tuple<string, string, int> edge) {
  string str = get<0>(edge) + get<1>(edge) + to_string(get<2>(edge));
  return str;
}

void DFSTest(Graph graph){

    // Test Case 1: Valid path from "A" to "E"
    std::vector<std::string> result1 = graph.DFS("A", "E");
    printResult(result1, "DFS Test Case 1");

    // Test Case 2: Valid path from "B" to "D"
    std::vector<std::string> result2 = graph.DFS("B", "D");
    printResult(result2, "DFS Test Case 2");

    // Test Case 3: Source node does not exist
    std::vector<std::string> result3 = graph.DFS("X", "E");
    printResult(result3, "DFS Test Case 3");

    // Test Case 4: Target node does not exist
    std::vector<std::string> result4 = graph.DFS("A", "Y");
    printResult(result4, "DFS Test Case 4");

    // Test Case 5: Source and target nodes do not exist
    std::vector<std::string> result5 = graph.DFS("X", "Y");
    printResult(result5, "DFS Test Case 5");

    // Test Case 6: Source and target nodes are the same
    std::vector<std::string> result6 = graph.DFS("A", "A");
    printResult(result6, "DFS Test Case 6");

    // Test Case 7: Node F has no valid path
    std::vector<std::string> result7 = graph.DFS("A", "F");
    printResult(result7, "DFS Test Case 7");

    // Test Case 8: Node F to E is a valid path
    std::vector<std::string> result8 = graph.DFS("F", "G");
    printResult(result8, "DFS Test Case 8");


    std::cout << "All DFS test cases executed!" << std::endl << std::endl;
}

void BFSTest(Graph graph){

    // Test Case 1: Valid path from "A" to "E"
    std::vector<std::string> result1 = graph.BFS("A", "E");
    printResult(result1, "BFS Test Case 1");

    // Test Case 2: Valid path from "B" to "D"
    std::vector<std::string> result2 = graph.BFS("B", "D");
    printResult(result2, "BFS Test Case 2");

    // Test Case 3: Source node does not exist
    std::vector<std::string> result3 = graph.BFS("X", "E");
    printResult(result3, "BFS Test Case 3");

    // Test Case 4: Target node does not exist
    std::vector<std::string> result4 = graph.BFS("A", "Y");
    printResult(result4, "BFS Test Case 4");

    // Test Case 5: Source and target nodes do not exist
    std::vector<std::string> result5 = graph.BFS("X", "Y");
    printResult(result5, "BFS Test Case 5");

    // Test Case 6: Source and target nodes are the same
    std::vector<std::string> result6 = graph.BFS("A", "A");
    printResult(result6, "BFS Test Case 6");

    // Test Case 7: Node F has no valid path
    std::vector<std::string> result7 = graph.BFS("A", "F");
    printResult(result7, "BFS Test Case 7");

    // Test Case 8: Node F to E is a valid path
    std::vector<std::string> result8 = graph.BFS("F", "G");
    printResult(result8, "BFS Test Case 8");


    std::cout << "All BFS test cases executed!" << std::endl << std::endl;
}

void PrimsTest(Graph graph){
    
    // Test Case 1: Prim's MST for the given graph
    Graph mst1 = graph.Prims();
    printMST(mst1, "Prim's Test Case 1");

    // Test Case 2: Prim's MST for a disconnected graph (should return an empty tree)
    Graph disconnectedGraph(false);
    disconnectedGraph.addNode("W");
    disconnectedGraph.addNode("X");
    disconnectedGraph.addNode("Y");
    disconnectedGraph.addNode("Z");
    disconnectedGraph.addEdge("W", "X", 2);
    disconnectedGraph.addEdge("Y", "Z", 3);
    Graph mst2 = disconnectedGraph.Prims();
    printMST(mst2, "Prim's Test Case 2");
    cout << mst2.getInfo() << endl;


    // Test Case 3: Prim's MST for a graph with multiple connected components
    Graph multiComponentGraph;
    multiComponentGraph.addNode("M");
    multiComponentGraph.addNode("N");
    multiComponentGraph.addNode("O");
    multiComponentGraph.addEdge("M", "N", 6);
    multiComponentGraph.addEdge("O", "N", 7);
    multiComponentGraph.addEdge("M", "O", 3);
    Graph mst3 = multiComponentGraph.Prims();
    printMST(mst3, "Prim's Test Case 3");
    cout << mst3.getInfo() << endl;

    std::cout << "All Prim's test cases executed!" << std::endl << std::endl;
}