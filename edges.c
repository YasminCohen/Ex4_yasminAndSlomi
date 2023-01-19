#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"

void addEdge(p_node currentNode, int dest, int w, p_node *head)
{
    if (currentNode->edges != NULL)
    {
        p_edge edgesOfNode = currentNode->edges;
        while (edgesOfNode->next != NULL)
        {
            edgesOfNode = edgesOfNode->next;
        }
        edgesOfNode->next = (p_edge)malloc(sizeof(edge));
        if (edgesOfNode->next == NULL)
        exit(1);
        p_edge new_1 = edgesOfNode->next;
        node *D = getNode(dest, head);
        new_1 ->dest = &(*D);
        new_1 ->next = NULL;
        new_1 ->weight = w;
      
    }
        
    else 
    {
               
        currentNode->edges = (p_edge)malloc(sizeof(edge)); 

        if (currentNode->edges == NULL)
       exit(1);
    
        currentNode->edges->weight = w;
        currentNode->edges->next = NULL;
        node *D = getNode(dest, head);
        currentNode->edges->dest = &(*D);
        
    }
}


void deleteEdge(p_node *head, int nodeId)
{
    p_node tempNode = *head;

    while (tempNode != NULL)
    {
        if (tempNode->nodeId != nodeId && tempNode->edges != NULL)
        {

            if (tempNode->edges->dest->nodeId == nodeId)
            {
                if (tempNode->edges->next != NULL)
                {
                    p_edge p1 = tempNode->edges;
                    tempNode->edges = p1->next;
                    free(p1);
                   
                }
                else
                {
                     p_edge p1 = tempNode->edges;
                    tempNode->edges = NULL;
                    free(p1);
                }
            }
            else
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
                    }else{
                    tempEdge = tempEdge->next;
                    }
                }
            }
        }
        tempNode = tempNode->next;
    }
}
