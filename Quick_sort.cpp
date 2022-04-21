#include <iostream>

using namespace std;

void swap( int *i, int *j)
{
    int t = *j;
    *j = *i;
    *i = t;
}
int partition(int a[], int l, int h)
{
    int p = a[h];
    int k = l-1;

    for(int i = l; i < h; i++)
        if(a[i] < p)
        {
            k++;
            swap(&a[i], &a[k]);
        }
    swap(&a[k+1], &a[h]);
    return k+1;
}
void Quick_Sort(int a[], int l, int h)
{
    if( l < h)
    {
        int pi = partition(a, l, h);
        Quick_Sort(a, l, pi-1);
        Quick_Sort(a, pi+1, h);
    }
}
int main()
{
    int n;
    cout << "ENTER THE NUMBER OF INPUTS :\n";
    cin >> n;

    int a[n];
    cout << "Enter the numbers :\n";
    for(int i = 0; i < n; i++)
       cin >> a[i];
    
    Quick_Sort(a, 0, n-1);

    cout << "Sorted Array :\n";
    for(int i = 0; i<n; i++)
    cout << a[i] << " "; 
    
}