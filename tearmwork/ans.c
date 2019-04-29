#include<stdio.h>
#include<stdlib.h>
FILE *fp,*gp;
int **soc;
int *visited;
int *q;
int N;
int f=-1,r=-1;
void assign(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			soc[i][j]=0;
		}
	}
}
void findmax(int i,int n,int *pos,int *max)
{
	int j;
	for(j=0;j<n;j++)
	{
		if(*max<soc[i][j])
		{
			*pos=j;
			*max=soc[i][j];
		}
	}
}
void enqueue(int data)
{
	if(r<N-1)
	{
		if(r==-1)
			f=0;
			r++;
		q[r]=data;
	}
}
int dequeue()
{
	int tmp;
	if(f>-1)
	{
		
		tmp=q[f];
		if(f==r)
			f=r=-1;
		else
			f++;
		return tmp;
	}
}
int isempty()
{
	if(f==-1 && r==-1)
		return 1;
	else 
		return 0;
		
}
void makeunvisited(int n)
{
	int i;
	for(i=0;i<n;i++)
		visited[i]=0;	
}
int outdegree(int i,int n)
{
	int c=0,j;
	for(j=0;j<n;j++)
	{
		if(soc[i][j]!=0)
			c++;
	}
	return c;
}
int indegree(int i,int n)
{
	int c=0,j;
	for(j=0;j<n;j++)
	{
		if(soc[j][i]!=0)
			c++;
	}
	return c;
}
void DFSTraversal(int s,int n)
{
	int i;
	visited[s]=1;
	printf("%4d",s);
	for(i=0;i<n;i++)
	{
		if(soc[s][i]!=0 && visited[i]==0)
			DFSTraversal(i,n);
	}
	
}
int frirndoffriend(int s,int n)
{
	int a[n],c=0,pos=0,i,j;
	makeunvisited(n);
	visited[s]=1;		
	for(i=0;i<n;i++)
	{
			if(soc[s][i]!=0)
			{
				a[pos]=i;
				pos++;
			}
	}
	for(i=0;i<pos;i++)
	{
		for(j=0;j<n;j++)
		{
			if(soc[a[i]][j] != 0 && visited[j]==0)
			{
				visited[j]=1;
				c++;
			}
		}
	}
	return c;
}
void BFSTraversal(int s,int n)
{
	
	int cur,i;
	visited[s]=1;
	enqueue(s);
	printf("%4d",s);
	while(!isempty())
	{
		cur=dequeue();
		
		for(i=0;i<n;i++)
		{
			
			if(soc[cur][i]!=0 && visited[i]==0)
			{
				enqueue(i);
				visited[i]=1;
				printf("%4d",i);
			}
		}
		
	}
}
int main()
{
	char *filename;
	int flag,u,i,v,w,j,n,e,threshold;
	printf("Enter filename : ");
	scanf("%s",filename);
	fp=fopen("ans.txt","r");
	if(fp == NULL)
	{
		printf("File Not found !\n");
		exit(0);
	}
	fscanf(fp,"%s",filename);
	fscanf(fp,"%d",&threshold);
	printf("using file : %s",filename);
	gp=fopen(filename,"r");
	if(gp == NULL)
	{
		printf("File Not found !\n");
	}
	fscanf(gp,"%d",&flag);
	if(flag == 1)
	{
	
		fscanf(gp,"%d",&flag);
		fscanf(gp,"%d",&n);
		fscanf(gp,"%d",&e);
		printf("\nGraph is directed and unweighted and has %d nodes and %d edges\n",n,e);
		soc=(int **)malloc(n * sizeof(int *));
		for(i=0;i<n;i++)
			soc[i]=(int *)malloc(n * sizeof(int));
		visited=(int *)malloc(n * sizeof(int));
		q=(int *)malloc(n * sizeof(int));
		N=n;
		makeunvisited(n);
		assign(n);
		while(fscanf(gp,"%d",&u)!= EOF && fscanf(gp,"%d",&v)!=EOF)
		{
			soc[u][v]=1;
		}
		printf("DFS Traversal  : ");
		DFSTraversal(0,n);
		printf("\nBFS Traversal  : ");
		makeunvisited(n);
		BFSTraversal(0,n);
		for(i=0;i<n;i++)
		{
			int in,out;
			float popularity;
			out=outdegree(i,n);
			in=indegree(i,n);
			if(out==0)
			{
				if(in>=threshold)
				{
					printf("\nPerson %d IS popular     .Followed by : %d  Follows : %d",i,in,out);	
				}
				else
				{
					printf("\nPerson %d is NOT popular .Followed by : %d  Follows : %d",i,in,out);
				}
					
			}
			else
			{
				popularity=(float)in/(float)out;
				if(popularity>=2)
				{
					printf("\nPerson %d IS popular     .Followed by : %d  Follows : %d Popularity score : %.2f  ",i,in,out,popularity);		
				}
				else
				{
					printf("\nPerson %d is NOT popular .Followed by : %d  Follows : %d Popularity score : %.2f  ",i,in,out,popularity);		
				}	
			}	
		}	
		
	}
	else
	{
		fscanf(gp,"%d",&flag);
		fscanf(gp,"%d",&n);
		fscanf(gp,"%d",&e);
		printf("\nGraph is undirected and weighted and has %d nodes and %d edges\n",n,e);
		soc=(int **)malloc(n * sizeof(int *));
		for(i=0;i<n;i++)
			soc[i]=(int *)malloc(n * sizeof(int));
		visited=(int *)malloc(n * sizeof(int));
		q=(int *)malloc(n * sizeof(int));
		N=n;
		makeunvisited(n);
		assign(n);
		while(fscanf(gp,"%d",&u)!= EOF && fscanf(gp,"%d",&v)!=EOF && fscanf(gp,"%d",&w)!=EOF)
		{
			soc[u][v]=w;
			soc[v][u]=w;
		}
		printf("DFS Traversal  : ");
		DFSTraversal(0,n);
		printf("\nBFS Traversal  : ");
		makeunvisited(n);
		BFSTraversal(0,n);
		for(i=0;i<n;i++)
		{
			int in=indegree(i,n);
			int max=0,pos=i,fof=0;
			findmax(i,n,&pos,&max);
			fof=frirndoffriend(i,n);
			printf("\nPerson %3d has %d friends and FOFs %d,oldest friend is %d (%d days) ",i,in,fof,pos,max);			
		}
		
	}
	fclose(fp);
	fclose(gp);	
}

