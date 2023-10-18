#ifndef GRAPH_H
#define GRAPH_H

#include "LocatorHeap.h"

#include <vector>
using std::vector;

class Edge;

class Vertex
{
public:
    int label;
    vector<Edge *> edges;

    // helpers stored inside a vertex to help with path finding
    // you can use different auxilliary structures if desired
    bool visited;
    float distanceTo;
    vector<Vertex *> pathTo;
    Heap<Vertex *>::Locator locator;
    bool operator<(const Vertex &v) const
    {
        // TODO for locator heap implementation
        return distanceTo < v.distanceTo;
    }

    Vertex(int l) : label(l) {}
};

class Edge
{
public:
    Vertex *v1, *v2;
    float weight;

    Edge(Vertex *nv1, Vertex *nv2, float newWeight) : v1(nv1), v2(nv2), weight(newWeight) {}
};

class Graph
{
protected:
    vector<Vertex *> v;
    vector<Edge *> e;

public:
    Graph() {}

    ~Graph()
    {
        // TODO
        for (Vertex *vertex : v)
        {
            delete vertex;
        }
        for (Edge *edge : e)
        {
            delete edge;
        }
    }

    Graph(const Graph& other)
    {
        // Copy vertices
        for (Vertex* vertex : other.v)
        {
            Vertex* newVertex = new Vertex(vertex->label);
            newVertex->visited = vertex->visited;
            newVertex->distanceTo = vertex->distanceTo;
            newVertex->locator = vertex->locator;
            v.push_back(newVertex);
        }

        // Copy edges
        for (Edge* edge : other.e)
        {
            Vertex* newV1 = nullptr;
            Vertex* newV2 = nullptr;

            // Find the corresponding vertices in the new graph
            for (Vertex* vertex : v)
            {
                if (vertex->label == edge->v1->label)
                {
                    newV1 = vertex;
                }
                if (vertex->label == edge->v2->label)
                {
                    newV2 = vertex;
                }
            }

            // Create a new edge and add it to the new graph
            Edge* newEdge = new Edge(newV1, newV2, edge->weight);
            newV1->edges.push_back(newEdge);
            newV2->edges.push_back(newEdge);
            e.push_back(newEdge);
        }
    }


    Graph& operator=(const Graph& other)
    {
        // Check for self-assignment
        if (this == &other)
        {
            return *this;
        }

        // Delete existing vertices and edges
        for (Vertex* vertex : v)
        {
            delete vertex;
        }
        for (Edge* edge : e)
        {
            delete edge;
        }
        v.clear();
        e.clear();

        // Copy vertices
        for (Vertex* vertex : other.v)
        {
            Vertex* newVertex = new Vertex(vertex->label);
            newVertex->visited = vertex->visited;
            newVertex->distanceTo = vertex->distanceTo;
            newVertex->locator = vertex->locator;
            v.push_back(newVertex);
        }

        // Copy edges
        for (Edge* edge : other.e)
        {
            Vertex* newV1 = nullptr;
            Vertex* newV2 = nullptr;

            // Find the corresponding vertices in the new graph
            for (Vertex* vertex : v)
            {
                if (vertex->label == edge->v1->label)
                {
                    newV1 = vertex;
                }
                if (vertex->label == edge->v2->label)
                {
                    newV2 = vertex;
                }
            }

            // Create a new edge and add it to the new graph
            Edge* newEdge = new Edge(newV1, newV2, edge->weight);
            newV1->edges.push_back(newEdge);
            newV2->edges.push_back(newEdge);
            e.push_back(newEdge);
        }

        return *this;
    }

    // TODO: complete rule of 3

    void insertVertex(int label)
    {
        // TODO
        v.push_back(new Vertex(label));
    }

    void insertEdge(int l1, int l2, float weight)
    {
        // TODO
        Vertex *v1 = v[l1];
        Vertex *v2 = v[l2];
        Edge *edge = new Edge(v1, v2, weight);
        v1->edges.push_back(edge);
        v2->edges.push_back(edge);
        e.push_back(edge);
    }

    vector<Vertex *> shortestPath(int start, int end)
    {
        // TODO: Dijkstra's algorithm
        Heap<Vertex *> heap;
        v[start]->distanceTo = 0;
        v[start]->locator = heap.insertElement(v[start]);

        while (!heap.isEmpty())
        {
            Vertex *current = heap.removeMin();
            current->visited = true;
            if (current->label == end)
                break;

            for (Edge *edge : current->edges)
            {
                Vertex *neighbor = (edge->v1 == current) ? edge->v2 : edge->v1;
                if (neighbor->visited)
                    continue;

                float newDistance = current->distanceTo + edge->weight;
                if (newDistance < neighbor->distanceTo)
                {
                    neighbor->distanceTo = newDistance;
                    neighbor->pathTo = current->pathTo;
                    neighbor->pathTo.push_back(current);

                    if (neighbor->locator)
                    {
                        heap.update(neighbor->locator);
                    }
                    else
                    {
                        neighbor->locator = heap.insertElement(neighbor);
                    }
                }
            }
        }
        return v[end]->pathTo;
    }
};

#endif