//Min Chang
//Github: Minyc510

#include "Graph.h"
#include <iostream>
#include <sstream>

using namespace std;

//Substitute "to_string"
string int2String(int i)
{
  stringstream ss;
    ss << i;
    return ss.str();
}

int main() {
  //Undirected Graph Object
  Graph G(false);

  vector<string> nodes = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
  G.addNodes(nodes);

  G.addEdge("A", "B");
  G.addEdge("A", "C");
  G.addEdge("A", "D");
  G.addEdge("E", "B");
  G.addEdge("E", "F");
  G.addEdge("F", "G");
  G.addEdge("H", "G");
  G.addEdge("I", "G");
  G.addEdge("I", "J");

  //Print results of BFS
  cout << "BFS on G:" << endl;
  for (auto x : G.BFS("A")) {
    cout << x.first << " " << x.second << endl;
  }

}
