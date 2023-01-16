#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    char choice, c;
    int src, v;
    src = 0;
    v = src;
    p_node temp = NULL;
    p_node *head = &temp;
    while (scanf("%c", &choice) != EOF)
    {
        if (choice == 'A')
        {
            deleteGraph(head);
            scanf("%d", &v);
            *head = createGraph(v);

            scanf("%c", &c);

            while (scanf("%c", &c) != 0)
            {
                if (c == 'n')
                {
                    scanf("%d", &src);
                    addNode(head, src);
                }
                else
                {
                    break;
                }
            }
            choice = c;
        }
        if (choice == 'B')
        {

            addNode_B(head);

            continue;
        }
        if (choice == 'D')
        {
            deleteNode(head);

            continue;
        }
        if (choice == 'S')
        {
            int start = -1, end = -1;
            scanf("%d %d", &start, &end);
            int dist = shortestPath(*head, start, end);
            printf("Dijsktra shortest path: %d \n", dist);
            continue;
        }
        if (choice == 'T')
        {
            TSP(*head);
            continue;
        }
    }
    deleteGraph(head);
}
