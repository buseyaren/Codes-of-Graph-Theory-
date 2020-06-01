#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include<stdbool.h>
struct node
{
    int label;
    int weight;
    struct node* next;
};
typedef struct node Node;

struct graph
{
    int num_vertices;
    Node** adj_list;
};

typedef struct graph Graph;

Node* createNode(int v,int weight)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->label = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}


Graph* CreateNullGraph(int vertices)
{

    Graph* G = malloc(sizeof(Graph));
    G->num_vertices = vertices;

    G->adj_list = malloc(vertices * sizeof(Node*));

    int i;
    for (i = 0; i < vertices; i++) {
        G->adj_list[i] = NULL;
    }
    return G;
}

void add_edge(Graph* G, int src, int dest,int directed, int weight)
{
    if(directed==0)
        weight=1;
    Node* newNode = createNode(dest,weight);
    newNode->next = G->adj_list[src];
    G->adj_list[src] = newNode;

    if(!directed)
    {
        Node* srcNode = createNode(src,weight);
        srcNode->next = G->adj_list[dest];
        G->adj_list[dest] = srcNode;
    }
}

bool isSafe(int k, int c)
{
    for (int i= 0; i < n; i++){ 
        if (G[k][i]== 1 && c == x[i])
		{
            return false;
		}	
	}
    return true;
}

void grafRenklendir(int r){
	for(int c=1; c<=m; c++)
	{
		if(isSafe(r,c)){
			x[r] = count;
			if(r+1 < n)
				grafRenklendir(r+1);
			else
				print("Dizi : %d\n",x[r]);
				return;
		}
	}
}

Graph* createHararyGraph(int n,int m){
	// n: olusturulan düðüm sayýsý  -- m: olusan kenar sayýsý
	if(n < 1)
		printf("Dugum sayýsý 1' den buyuk veya esit olmalýdýr");
	if(m < n-1)
		printf("Kenar sayýsý (n-1)' den buyuk veya esit olmalýdýr");
	if(m > (n*(n-1))/2)
		printf("Kenarlarýn sayýsý toplamdan buyuk veya esit olmalýdýr");
	degree = 2*m/n;
	//dugum sayýsý ve derece esitlik kontrolu
	if (n % 2 == 0 || degree % 2 == 0){
		//d dereceli graf
		dnew = d/2;
		for(int i=0; i<n; i++){
			for(int j=1; j<dnew+1; j++){
				add_edge(G,i,(i-j)%n,0,0);
				add_edge(G,i,(i+j)%n,0,0);
			}
		}
		if (d & 2 == 1){  // d tek n cift
			nnew=n/2;
			for(int i=0;i<nnew;i++){
				//kenarlarýn capraz olarak eklenmesi
				add_edge(G,i,i+nnew,0,0);
			}
		}
		//mod alma
		mode= 2*m%n;
		if(mode > 0){
			for(int i=0;i<(mode+2);i++){
				add_edge(G,i,i+dnew,0,0);
			}
		}
	}
	else{
		second_d = (d-1)/2;
		for(int i=0;i<n;i++){
			for(int j=0;(j<second_d+1);j++){
				add_edge(G,i,(i-j)%n,0,0);
				add_edge(G,i,(i+j)%n,0,0);
			}
		}
		second_half = n/2;
		for(int i=0; i<(m-n*second_d);i++){
			add_edge(G,i,i+second_d,0,0);
		}
	}
	return G;
}

int main()
{
    int noV=5;
    Graph* G=CreateNullGraph(noV);
    add_edge(G,0,1,0,0);
    add_edge(G,0,5,0,0);
    add_edge(G,1,2,0,0);
    add_edge(G,2,3,0,0);
    add_edge(G,3,4,0,0);
    add_edge(G,4,5,0,0);

    //AdjMatris(G);
    createHararyGraph(6,noV);

}

