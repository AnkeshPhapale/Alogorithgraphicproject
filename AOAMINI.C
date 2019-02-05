#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int G[50][50],x[50],y[50],z[50];

int tostring(int i)
{
    int j, rem, len = 0, n,num;
    char str[10];
    n = i;
    while (n != 0)
    {
	len++;
	n /= 10;
    }
    for (i = 0; i < len; i++)
    {
	rem = num % 10;
	num = num / 10;
	str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
    return str[len];
}
void connectvertex( int G[50][50],int n,int y[50],int z[50])
{
 int i,j;


  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(G[i][j]==1)
	 {
	  line(y[i],z[i],y[j],z[j]);
	  }


}

void drawgraphvertex(int a,int b)
{
circle( a,b,20);
}

void next_color(int k)
{
   int i,j;
   x[k]=1;  //coloring vertex with color1
   for(i=0;i<k;i++){ //dchecking all k-1 vertices-backtracking
     if(G[i][k]!=0 && x[k]==x[i])  //if connected and has same color
       x[k]=x[i]+1;  //assign higher color than x[i]
   }
}


void  main()
{
  int n,e,i,j,k,l,a,b,ch;
  char st[10];
    int gdriver = DETECT, gmode;
    clrscr();
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
 printf("................................WELCOME..............................\n\n\n");
 printf("...................Graph Colouring Algorithm...........................\n\n\n");
  printf("Enter no. of vertices : ");
  scanf("%d",&n);  //total vertices
  printf("Enter no. of edges : ");
  scanf("%d",&e);  //total edges

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      G[i][j]=0;  //assign 0 to all index of adjacency matrix

  printf("Enter indexes where value is 1-->\n");
  for(i=0;i<e;i++){
    scanf("%d %d",&k,&l);
    G[k][l]=1;
    G[l][k]=1;
  }


  for(i=0;i<n;i++)
    next_color(i);  //coloring each vertex

  printf("Colors of vertices -->\n");
  for(i=0;i<n;i++)  //displaying color of each vertex
    printf("Vertex[%d] : %d\n",i+1,x[i]);
a =300;
b =100;
for(i=0;i<(n/2);i++)
{ y[i] = a;
  z[i] = b;
drawgraphvertex(a,b);
setcolor(7);
tostring(i);
outtextxy(a+25,b+25,st);
setcolor(x[i]);
setfillstyle(SOLID_FILL,x[i]);
fillellipse(a,b,20,20);
a = a+100;
b =b;
}

a = 300;
b = 200;
for(i=(n/2);i<n;i++)
{
y[i] = a;
z[i] = b;
drawgraphvertex(a,b);
setcolor(7);
outtextxy(a+25,b+25,st);
setfillstyle(SOLID_FILL,x[i]);
fillellipse(a,b,20,20);
a = a+100;
b = b;
}
connectvertex(G,n,y,z);
printf("\n\n\n\n");
printf("do you want to see information(1,0)\n");
scanf("%d",&ch);
if(ch==1)
{
  clrscr();
printf(".................................INFORMATION................................\n\n\n");
printf("Graph coloring problem is to assign colors to certain elements of a graph\n");
printf("Vertex coloring is the most common graph coloring problem. The problem is\n");
printf(" given  n vertex and m edges find a way of coloring the vertices of a graph\n");
printf("such that no two adjacent vertices are not colored using same color \n\n");
printf("Vertex coloring\n\n");
printf("a coloring of a graph is almost always a proper vertex coloring\n");
printf("A coloring using at most k colors is called a (proper) k-coloring\n");
printf("The smallest number of colors needed to color a graph G is called its chromatic number\n");
}
getch();
closegraph();
}