#pragma once
#include "../DoublyLinkedLists/DoublyLinkedListTemplate.hpp"
#include "../Queue/Queue.hpp"
template <typename T>
class Vertex {
public:
    T data;
    DoublyLinkedList<unsigned int> edges;
    bool visited;
    Vertex() : data(0), visited(false) {}
};

template <typename T>
class Graph {
private:
    Vertex<T>* vertexes;
    unsigned int size;

    void clearVisited() {
        for (unsigned int i = 0; i < size; ++i) {
            vertexes[i].visited = false;
        }
    }

public:
    Graph() {
        vertexes = nullptr;
        size = 0;
    }

    ~Graph() { deleteGraph(); }

    bool createGraph(unsigned int nSize) {
        if (nSize = 0 || vertexes != nullptr) {
            return false;
        }

        vertexes = new (nothrow) Vertex<T>[nSize];
        if (!vertexes) {
            return false;
        }

        size = nSize;
        for (unsigned int i = 0; i < size; ++i) {
            vertexes[i].data = UINT32_MAX;
            vertexes[i].visited = false;
        }

        return true;
    }

    void deleteGraph() {
        if (!size) {
            return;
        }
        if (vertexes) {
            delete[] vertexes;
            vertexes = nullptr;
            size = 0;
        }
    }

    bool insertEdge(unsigned int source, unsigned int destination) {
        if (!vertexes) {
            return false;
        }

        if (source >= size || destination >= size) {
            return false;
        }

        if (vertexes[source].edges.search(destination)) {
            return false;
        }

        return vertexes[source].edges.append(destination)) 
    }

    bool deleteEdge(unsigned int source, unsigned int destination) {
        if (!vertexes) {
            return false;
        }

        if (source >= size || destination >= size) {
            return false;
        }

        return vertexes[source].edges.deleteElement(destination);
    }

    void printGraph() {
        for (unsigned int i = 0; i < size; ++i) {
            cout << "Vertex " << i << " (Data: " << vertexes[i].data << "):";
            vertexes[i].edges.printListForwards();
            cout << endl;
        }
    }

    void DFS(unsigned int vertex) {
        vertexes[vertex].visited = true;
        cout << vertex << " ";

        DoublyLinkedList<int>::Iterator i(nullptr);
        for (auto edge : vertexes[vertex].edges) {
            if (!vertexes[*edge].visited) {
                DFS(*edge);
            }
        }
    }

    bool BFS(unsigned int startVertex) {
        Queue<unsigned int> queue;

        if (!size || startVertex >= size) {
            return false;
        }

        clearVisited();

        cout << "BFS(" << startVertex << "): ";

        if (!queue.enqueue(startVertex)) {
            return false;
        }
        vertexes[startVertex].visited = true;

        while (!queue.isEmpty()) {
            unsigned int vertex = *queue.peek();

            cout << vertex << " ";
            queue.deque();

            for (auto edge : vertexes[vertex].edges) {
                if (!vertexes[edge].visited) {
                    if (!queue.enqueue(edge)) {
                        return false;
                    }
                    vertexes[edge].visited = true;
                }
            }
        }

        cout << "\n";
        return true;
    }
    
    bool loadFile(const string& filename) {
		ifstream        file(filename);
		string          line;
		unsigned int source = 0, nSize = 0;

		if (!file.is_open()) {
			cerr << "Error opening file: " << filename << endl;
			return false;
		}
		if (!getline(file, line)) {
			cout << "No header" << endl;
			file.close();
			return false;
		}
		if (line != "Grafo") {
			file.close();
			return false;
		}
		if (!getline(file, line)) {  
			cout << "No graph size" << endl;
			file.close();
			return false;
		}
		if (!isdigit(line)) {
			cout << "Graph size is not numerical" << endl;
			file.close();
			return false;
		}
		nSize = stoi(line);
		if (nSize <= 0) {
			cout << "Incorrect graph size" << endl;
			file.close();
			return false;
		}
		deleteGraph();   
		if (!crearGrafo(nSize)) {   
			cout << "The graph could not be created" << endl;
			file.close();
			return false;
		}
		for (source = 0; source < size; source++) {
			if (!getline(file, line)) {  
				cout << "No edges" << endl;
				file.close();
				return false;
			}
			if (line.length()) {    
				stringstream ss(line);
				string cell;
				while (getline(ss, cell, ' ')) {
					int destination = 0;
					if (!isValidNumeric(cell)) {
						file.close();
						return false;
					}
					destination = stoi(cell);
					if (!insertEdge(source, destination)) {
						file.close();
						return false;
					}
				}
			}
		}
		file.close();
		return true;
	}

	bool saveFile(const string& filename) {
		ofstream file;
		if (!size) {
			return false;
		}
		file.open(filename, ios::out);
		if (!file.is_open()) {
			cerr << "Error saving file: " << filename << endl;
			return false;
		}
		file << "Grafo" << endl;    
		file << size << endl;       
		for (unsigned int i = 0; i < size; i++) {
			for (auto edge : vertexes[vertex].edges) {
				file << edge << " ";
			}
			file << endl;
		}
		file.close();
		return true;
	}

};