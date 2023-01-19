#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"

p_node createGraph(int num_nodes)
{
    p_node newNode, temp, head = NULL;
    
    head = (p_node)malloc(sizeof(node));
    if (head == NULL)
    exit(1);

    head->nodeId = 0;
    head->next = NULL;
    head->edges = NULL;

    temp = head;
    
    for (int i = 0; i < num_nodes-1; i++)
    {
        newNode = (p_node)malloc(sizeof(node));
        if (newNode == NULL)
        exit(1);
        
        temp->next = newNode;

        newNode->nodeId = (i+1);
        newNode->next = NULL;
        newNode->edges = NULL;

        temp = temp->next;
    }
    return head;
}

void deleteGraph(p_node *head)
{
    p_node tempNode = *head;
    while (tempNode != NULL)
    {
        p_edge tempEdge = tempNode->edges;
        while (tempEdge != NULL)
        {
            p_edge tempEdgefree = tempEdge;
            tempEdge = tempEdge->next;
            free(tempEdgefree);
        }
        p_node tempFree = tempNode;
        tempNode = tempNode->next;
        free(tempFree);
    }
    free(tempNode);
}
