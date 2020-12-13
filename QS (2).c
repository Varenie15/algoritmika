#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

void quicksort(int *array, int first, int last)
{
    if (first < last)
    {
        int l = first;
        int r = last;
        int mid = array[(l+r)/2];
        do
        {
            while (array[l] < mid) l++;
            while (array[r] > mid) r--;
            if (l<=r)
            {
                int c=array[l];
                array[l]=array[r];
                array[r]=c;
                l++;
                r--;
            }
        } while (l<=r);
        quicksort(array, first, r);
        quicksort(array,l, last);
    }

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

    quicksort(q, 0, n-1);

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

