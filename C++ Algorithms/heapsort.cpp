#include<stdio.h>
int main()
{
    int a[10], t, n, j,i;
    printf("Enter the number of element: ");
    scanf("%d", &n);
    printf("\nEnter the elements:\n\n");
    for (i = 0;i<n;i++){
        scanf("%d", &a[i]);
    }
    //min heap for(i=0;i<n;i++)
    {
        for (j = 0;j<n-i-1;j++)
        {
            if (a[i] > a[2 * i + 1])
            {
                t = a[i];
                a[i] = a[2 * i + 1];
                a[2 * i + 1] = t;
            }
            else if (a[i] > a[2 * i + 2])
            {
                t = a[i];
                a[i] = a[2 * i + 2];
                a[2 * i + 2] = t;
            }
            else
            {
                continue;
            }
        }
    }

    return 0;
}
