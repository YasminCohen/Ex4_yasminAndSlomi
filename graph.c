#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"

/* function to create the graph with a given number of nodes */
p_node createGraph(int num_nodes)
{
    node *head = NULL;
    p_node newNode, temp = NULL;
    
    head = (p_node)malloc(sizeof(node));
    if (head == NULL)
    {
        perror("there is no enough space to create the graph, sorry\n");
        exit(0);
    }
    head->nodeId = 0;
    head->next = NULL;
    head->edges = NULL;
    temp = head;
    
    for (int i = 1; i < num_nodes; i++)
    {
        newNode = (p_node)malloc(sizeof(node));
        if (newNode == NULL)
        {
            perror("there is no enough space to create the node, sorry\n");
            exit(0);
        }
        newNode->nodeId = i;
        newNode->next = NULL;
        newNode->edges = NULL;
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

/* function to delete the graph, goes over all
*  edges and then nodes and free their memories */
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
        node *tempFree = tempNode;
        tempNode = tempNode->next;
        free(tempFree);
    }
    free(tempNode);
}

//print fuction in order to check myself (can be deleted)
void printGraph(p_node head)
{ 
    p_node tempNode = head;
    while (tempNode != NULL)
    {
        printf("Node: %d {", tempNode->nodeId);
        p_edge tempEdge = tempNode->edges;
        while (tempEdge != NULL)
        {
            printf("dest: %d weight: %d ", tempEdge->dest->nodeId, tempEdge->weight);
            tempEdge = tempEdge->next;
        }
        printf("}");
        tempNode = tempNode->next;
    }
}
