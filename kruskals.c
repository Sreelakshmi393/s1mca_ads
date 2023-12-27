#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_NODES 100

int isSpanningTree(int n, int graph[][MAX_NODES]); //to check if spanning tree is completed(means every node got connected)
int DFS(int node, int n, int graph[][MAX_NODES], int visited[], int recStack[], int parent);
//node->current node, n->number of nodes, graph[][]->adjacency matrix,
//visited[][]->array to track visited nodes, recStack[]->keep track of nodes in the current path, parent->parent of the current node

void main(){
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);

    //aacepting graph as adjacency matrix
    int A[MAX_NODES][MAX_NODES],u,v;
    int n2=n*n;
    int toSort[n2]; 
    int sorted[n2];
    int cost=0;
    printf("Enter the adjacency matrix : \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("A[%d][%d] : ",i,j );
            scanf("%d", &A[i][j]);
            if(A[i][j]==0)//Assigning maximum value if no edge btwn two nodes
                A[i][j]=INT_MAX;

            toSort[(n*i)+j]=A[i][j];  
            sorted[(n*i)+j]=A[i][j];
        }
    }
     // Sort the flattened array: Bubble Sort
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2 - 1; j++) {
            if (sorted[j + 1] < sorted[j]) {
                int tmp = sorted[j + 1];
                sorted[j + 1] = sorted[j];
                sorted[j] = tmp;
            }
        }
    }

//Construct the MST
    printf("The egdes in the Minimum Spanning Tree are : \n");
    int mst[MAX_NODES][MAX_NODES]={0};
    for(int i=0; i<n2; i++){
        for(int j=0; i<n2; j++){
            //Finding where each value in the sorted array was in the adjacency matrix
            if(sorted[i]==toSort[j]){ //for loop iterate till the first value in sorted array is found on toSort (likewise for all values)
                int row = j/n;  //3 4
                int col = j%n;  // 2 1   3/2=1 , 3%2=1 finds row and col of that value in aj matrix
                
                //checking if that edge exist
                if(A[row][col]==INT_MAX){
                    mst[row][col]=0;
                    break;
                }

                //if exist inserting into MST
                mst[row][col]=sorted[i];

                //marking that value as INT_MAX to avoid any further iteration
                toSort[j]=INT_MAX;

                //Checking the existence of any cycle
                int isCyclic=0;
                for(int k=0; k<n; k++){
                    int V[MAX_NODES]={0};
                    int parents[MAX_NODES]={0};
                    if(DFS(k, n, mst, V, parents, -1)){ 
                        mst[row][col]=0;
                        isCyclic=1; 
                        break;
                    }
                }
                if(isCyclic)
                    break; //if cycle exist break
                //print the unique edge that exist and increment cost
                if(!mst[col][row]){
                    cost+=mst[row][col];
                    printf("{%d, %d} = %d\n", row, col, mst[row][col]);
                }
                //after finished the mst
                if(isSpanningTree(n,mst)){ //if every node is connected
                    printf("Minimum Cost : %d\n", cost);
                    return;
                }
            }
        }
    }
    printf("Minimum cost : %d\n",cost);
}

//Checking if all nodes are visted and connected
int isSpanningTree(int n, int graph[][MAX_NODES]){
    int visited[MAX_NODES]={0}; //to track visited nodes
    int recStack[MAX_NODES]={0}; //keep track of nodes in current recursion stack
    DFS(0,n,graph,visited,recStack,-1);
    for(int i=0; i<n; i++){
        if(!visited[i]) //node in the i'th index has not visited means graph not connected
        return 0;
    }
    return 1; //graph connected
}

//DFS function to detect cycle in graph
int DFS(int node, int n, int graph[][MAX_NODES], int visited[], int recStack[], int parent){
    if(visited[node]==0){ //checks if current node has not been visited
        visited[node]=1; //mark as visited
        //recStack is used to keep track of nodes in the current path of traversal
        recStack[node]=1; // add to recursion stack
        for(int i=0; i<n; i++){
            if(graph[node][i]!=0){ // check if there is node between node and i
                // Recursively calling the function on each unvisited node
                if(!visited[i] && DFS(i,n,graph,visited,recStack,node)){ //if node not visited it recursively calls DFS
                    return 1;
                } else if(recStack[i] && i != parent){ //if i already visited and in recStack and not the parent of current node
                    return 1;
                }
            }
        }
    }
    //Remove the node from the recursion stack
    recStack[node]=0;
    return 0;
}


