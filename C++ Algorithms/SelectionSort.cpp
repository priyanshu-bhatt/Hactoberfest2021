#include <iostream>
using namespace std;

int main()
{
    int a[5] = {30, 17, 20, 3, 48};
    int i, key, j , temp;
    for (i = 0; i < 5; i++)      //outer loop for swapping of first element and iterative element
    {
        for (j = i+1; j < 5; j++)  // inner loop to check elements and swap
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

    }
for(i=0;i<5;i++){
    cout << a[i] << " ";
}
    
}