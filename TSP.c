#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

//*********function for solving TSP*********//




void TSP(p_node head)
{
	int arrlen = -1;
    p_node graph = head;
    scanf("%d", &arrlen);

    int *arr = (int *)(calloc(arrlen, sizeof(int)));
    for (int i = 0; i < arrlen; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    //calculates all permutations of a given nodes and
    //on each permutation calculates all shortest paths between nodes
    int j, i, temp;
    int best_path, current_path;
    int existsPath, pathFound; //flags
    pathFound = 0;
    best_path = 999999;

    for(j=1; j <= arrlen; j++){

        for(i=0; i < arrlen-1; i++){

            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
              
            //one more loop that goes over all given nodes and finds shortest path between each node
            current_path = 0;
            existsPath = 1;
            for(int node = 0; node<arrlen-1;  node++){
                int dijk = shortestPath(graph, *(arr+node), *(arr+(node+1)));
                if (dijk == -1)
                    existsPath = 0;
                current_path += dijk;
            }
             //finds best solution

            if (existsPath && (current_path < best_path)){
                best_path = current_path;
                pathFound = 1;
            }
        }
    }
    if(!pathFound){
        best_path = -1;
    }  

    printf("TSP shortest path: %d \n",best_path);

    //free the memory
    free(arr);
}
