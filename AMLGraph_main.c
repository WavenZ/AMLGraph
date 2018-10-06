/*
	@brief:多重邻接表存储无向图
	@author:WavenZ
	@time:2018/10/6
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define Status int 
#define MAX_VERTEX_NUM 20
#define VertexType char
typedef enum { unvisited, visited }VisitIf;
typedef struct EBox {
	VisitIf		mark;
	int			ivex, jvex;
	struct	EBox *ilink, *jlink;
	int			*info;
}EBox;
typedef struct VerBox {
	VertexType	data;
	EBox		*firstedge;
}VerBox;
typedef struct {
	VerBox	adjmulist[MAX_VERTEX_NUM];
	int		vexnum, edgenum;
}AMLGraph;

int LocateVex(AMLGraph *G,VertexType vex) {
	int i;
	for (i = 0; i < G->vexnum; ++i) {
		if(vex==G->adjmulist[i].data)
			return i;
	}
	return -1;
}

Status CreateUDG(AMLGraph *G) {
	int i;
	char ivex, jvex;
	EBox *p = NULL;
	printf("请输入无向图的顶点数和边数：");
	scanf("%d %d", &G->vexnum, &G->edgenum);
	getchar();
	printf("请输入各顶点的名称：");
	for (i = 0; i < G->vexnum; ++i) {
		scanf("%c", &G->adjmulist[i].data);
		G->adjmulist[i].firstedge = NULL;
	}
	getchar();
	for (i = 0; i < G->edgenum; ++i) {
		printf("请输入第%d条边依附的两个顶点:",i+1);
		scanf("%c %c", &ivex, &jvex);
		getchar();
		p = (EBox *)malloc(sizeof(EBox));
		p->ivex = LocateVex(G, ivex);
		p->jvex = LocateVex(G, jvex);
		p->ilink = G->adjmulist[p->ivex].firstedge;
		p->jlink = G->adjmulist[p->jvex].firstedge;
		G->adjmulist[p->ivex].firstedge = p;
	/*	G->adjmulist[p->jvex].firstedge = p;*/
	}
}

printAMLGraph(AMLGraph *G) {
	int i;
	EBox *p;
	for (i = 0; i < G->vexnum; ++i) {
		printf("%c: ", G->adjmulist[i].data);
		p = G->adjmulist[i].firstedge;
		while (p){
			printf("%c --> %c  ", G->adjmulist[p->ivex].data, G->adjmulist[p->jvex].data);
			p = p->ilink;
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {

	AMLGraph G;
	CreateUDG(&G);
	printAMLGraph(&G);
	system("pause");
	return 1;
}