#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"

/* function to add the edge with a given src(our node), dest and weight of edge */
void addEdge(p_node currentNode, int dest, int w, p_node *head)
{
    // if there are edges on the current node
    if (currentNode->edges != NULL)
    {
        p_edge edgesOfNode = currentNode->edges;
        while (edgesOfNode->next != NULL)
        {
            edgesOfNode = edgesOfNode->next;
        }
        // allocate memory and check if it allocated
        edgesOfNode->next = (p_edge)malloc(sizeof(edge));
        if (edgesOfNode->next == NULL)
        exit(1);
        p_edge new_1 = edgesOfNode->next;
        // add edge in the end of node's list of edges
        node *D = getNode(dest, head);
        new_1 ->dest = &(*D);
        new_1 ->next = NULL;
        new_1 ->weight = w;
      
    }
        
    else // if there are no edges on the current node
    {
               // allocate memory in size of sruct Edge and return pointer to this struct
        currentNode->edges = (p_edge)malloc(sizeof(edge)); 

        if (currentNode->edges == NULL)
       exit(1);
        // add edge in empty list
        currentNode->edges->weight = w;
        currentNode->edges->next = NULL;
        node *D = getNode(dest, head);
        currentNode->edges->dest = &(*D);
        
    }
}

/* finds edges with node with id=nodeId and removes (free the memory) */
void deleteEdge(p_node *head, int nodeId)
{
    p_node tempNode = *head;

    while (tempNode != NULL)
    {
        if (tempNode->nodeId != nodeId && tempNode->edges != NULL)
        {

            if (tempNode->edges->dest->nodeId != nodeId)
            {
                p_edge tempEdge = tempNode->edges;

                while (tempEdge->next != NULL)
                {
                    if (tempEdge->next->dest->nodeId == nodeId)
                    {
                        p_edge p1 = tempEdge->next;
                        tempEdge->next = tempEdge->next->next;
                        free(p1);
                        break;
                    }
                    tempEdge = tempEdge->next;
                }
            }
            else
            {   
                if (tempNode->edges->next == NULL)
                {
                    p_edge p1 = tempNode->edges;
                    tempNode->edges = NULL;
                    free(p1);
                }
                else
                {
                    p_edge p1 = tempNode->edges;
                    tempNode->edges = p1->next;
                    free(p1);
                }
            }
        }
        tempNode = tempNode->next;
    }
}
