#pragma once
#include "../DoublyLinkedLists/DoublyLinkedListTemplate.hpp"

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
};