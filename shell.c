#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int shell(int *A, int lenth)
{
    int d=lenth;
    d=d/2;
    while (d>0)
    {
        for (int i=0; i<lenth-d; i++)
        {
            int j=i;
            while(j>=0 && A[j]>A[j+d])
            {
                int sklad=A[j];
                A[j]=A[j+d];
                A[j+d]=sklad;
                j--;
            }
        }
        d=d/2;
    }
    for (int i =0; i<lenth-1; i ++)
         return A[i];
}

main(int argc, char * argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    int n;
    fscanf(f, "%d", &n);
    int *q = malloc(n*sizeof(int));
    for(int i = 0; i < n; i++)
	{
		fscanf(f, "%d", &q[i]);
	}

    clock_t begin=clock();

    shell(*q, n-1);

    clock_t end=clock();

    printf("Time:%lf",(double)(end-begin)/CLOCKS_PER_SEC);

    printf("\n");
    for(int i = 0;i<n;i++)
    {
        printf("%d\n",q[i]);
    }
    fclose(f);
    free(q);
    return 0;
}


