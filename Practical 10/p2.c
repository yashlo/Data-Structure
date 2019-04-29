#include<stdio.h>
void main()
{
    int Graph[10][10],v,i,j;

    printf("Enter Total Number of Vertex : ");
    scanf("%d",&v);

   printf("Enter Edges : \n");
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            printf("vertex [%d] to [%d] : ",i,j);
            scanf("%d",&Graph[i][j]);
        }
    }



    printf("\n\n Vertex\t INDEG\t OUTDEG\t\n");
    for(i=1;i<=v;i++)
    {
        int indeg=0,outdeg=0;
        for(j=1;j<=v;j++)
        {
            if(Graph[j][i] == 1)
            {
                indeg++;
            }
        }
        for(j=1;j<=v;j++)
        {
            if(Graph[i][j] == 1)
            {
                outdeg++;
            }
        }
        printf("%d\t%d\t%d\t\n",i,indeg,outdeg);
    }

}
