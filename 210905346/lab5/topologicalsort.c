#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int a[100];
    int top;
} stack;

typedef struct {
    int n;
    int **adjL;
} graph;

void push(stack *s, int x){
    (s->a)[++(s->top)] = x;
}

void insert(int *list, int x){
    int i = 0;
    while(list[i] != -1)
        i++;
    list[i] = x;
    list[i+1] = -1;
}

graph create(int n){//returns a graph,n is the no of nodes
    graph g;//creates a graph variable g to store the graph information.
    g.n = n;//assigns the value of n to g.n, which represents the number of nodes in the graph.
    int i, j, x;
    g.adjL = (int **)malloc(n * sizeof(int *));//creates a graph with n nodes by dynamically allocating memory for the adjacency list (adjL) using nested loops
    for(i = 0; i < n; i++){//The function enters a loop that iterates from 0 to n-1.
        g.adjL[i] = (int *)malloc(n * sizeof(int));//Inside the loop, it allocates memory for the i-th adjacency list using malloc
        g.adjL[i][0] = -1;//It initializes the first element of the adjacency list g.adjL[i] to -1. This value -1 is used as a marker to indicate the end of the adjacency list.
        for(j = 0; j < n; j++){//enters another loop that iterates from 0 to n-1
            if(i != j){//Inside this nested loop, it checks if i is not equal to j
                printf("edge from %d to %d? ", i, j);//If the condition is true, it prompts the user to enter whether there is an edge from node i to node j using printf
                scanf("%d", &x);//scans the input using scanf, storing it in the variable x.
                if(x == 1)//x is 1, indicating an edge exists from i to j              
                    insert(g.adjL[i], j);//calls the insert function to add j to the adjacency list of i
            }
        }
    }
    return g;
}

void dfs(graph g, int *v, stack *s, int in){
    v[in] = 1;//marks the current node in as visited by setting v[in] to 1
    int *list = g.adjL[in];
    int i = 0;
    while(list[i] != -1){
        if(v[list[i]] == 0)
            dfs(g, v, s, in + 1);
        i++;
    }
    push(s, in);
}

int check(int a[], int n, int x){
    for(int i = 0; i < n; i++){
        if(a[i] == x)
            return 1;
    }
    return 0;
}

void srcRem(graph *g, int *rem, int *in){
    int i, j, min = 100;
    int *list;
    int *deg = (int*)calloc(g->n, sizeof(int));
    for(i = 0; i < g -> n; i++){
        j = 0;
        list = g->adjL[i];
        if (!check(rem, *in, i)) {
            while (list[j] != -1) {
                if (!check(rem, *in, list[j]))
                    deg[list[j]]++;
                j++;
            }    
        }
        else
            deg[i] = -1;
    }
    for (i = 0; i < g -> n; i++) {
        if (deg[i] < min && deg[i] != -1) {
            min = deg[i];
            j = i;
        }
    }
    rem[*in] = j;
    *in = *in + 1;
    printf("%d ", j);
}

void main(){
    int n, i, x;//n store the number of nodes in the graph, i is a loop counter, and x is used for temporary storage
    printf("enter no. of nodes ");
    scanf("%d",&n);
    int * v = (int *) calloc(n,sizeof(int));//dynamic array used to keep track of visited nodes 
    int * rem = (int *) calloc(n,sizeof(int));//dynamic array used to keep track of removed nodes 
    int in = 0;//used to track the current index in the rem array
    stack s;//stack s is declared and initialized with top = -1 to represent an empty stack
    s.top = -1;
    graph g = create(n);//creates a graph g using the create function and passes n as the number of nodes.
    for(i = 0; i < n; i++)
        v[i] = 0;//initializes all elements of the v array to 0.

    printf("dfs: \n");
    for (i = 0; i < n ; i++)//It iterates through each node index from 0 to n-1
        if (v[i] == 0)//If a node has not been visited
            dfs(g, v, &s, i);//calls dfs function 
    while (s.top != -1) 
        printf("%d ",(s.a[s.top--]));
    printf("\nsource removal: \n");
    for (i = 0; i < n; i++) 
        srcRem(&g, rem, &in);
}