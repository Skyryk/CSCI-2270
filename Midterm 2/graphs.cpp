#include "graphs.hpp"
#include <iostream>
#include <list>

Graph::Graph()
{

}

Graph::~Graph()
{

}

void Graph::addEdge(int v1, int v2)
{
     vertex *vert1 = findVertex(v1);
     vertex *vert2 = findVertex(v2);

     vert1->Edges.push_back(vert2);
}

void Graph::addVertex(int id)
{
     vertex *newVertex = new vertex();
     newVertex->id = id;
     newVertex->visited = false;
     vertices.push_back(*newVertex);
}

void Graph::displayEdges()
{
     for(int i=0; i<vertices.size(); i++)
     {
          std::cout << vertices[i].id << "-->";

          for(int j=0; j<vertices[i].Edges.size(); j++)
          {
               std::cout << vertices[i].Edges[j]->id;
               if(j+1 != vertices[i].Edges.size())
               {
                    std::cout << "***";
               }
          }

          std::cout << '\n';
     }
}

void Graph::printDFT()
{
     setAllVerticesUnvisited();

     for(int i = 0; i<vertices.size(); i++)
     {
          if(!vertices[i].visited)
          {
               DFTraversal(&vertices[i]);
          }
     }
}

void Graph::printBFT()
{
     setAllVerticesUnvisited();

     for(int i = 0; i<vertices.size(); i++)
     {
          if(!vertices[i].visited)
          {
               BFTraversal(&vertices[i]);
          }
     }
}

void Graph::setAllVerticesUnvisited()
{
     for(int i=0; i<vertices.size(); i++)
     {
          vertices[i].visited = false;
     }
}

vertex* Graph::findVertex(int id)
{
     for(int i=0; i<vertices.size(); i++)
     {
          if(vertices[i].id == id)
          {
               return &vertices[i];
          }
     }
}

void Graph::BFTraversal(vertex *v)
{
     std::list<vertex*> queue;

     v->visited = true;
     queue.push_back(v);

     while(!queue.empty())
     {
          v = queue.front();
          std::cout << v->id << '\n';
          queue.pop_front();

          for(int i=0; i<v->Edges.size(); i++)
          {
               if(!v->Edges[i]->visited)
               {
                    v->Edges[i]->visited = true;
                    queue.push_back(v->Edges[i]);
               }
          }
     }
}

void Graph::DFTraversal(vertex *v)
{
     v->visited = true;
     std::cout << v->id << '\n';

     for(int i=0; i<v->Edges.size(); i++)
     {
          if(!v->Edges[i]->visited)
          {
               DFTraversal(v->Edges[i]);
          }
     }
}
