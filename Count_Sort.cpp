#include <iostream>
#include <vector>

using namespace std;

void Count_Sort(int a[], int n)
{
    int max = a[0];
   for(int i = 1; i < n; i++)
       if(a[i] > max)
         max = a[i];
        
   int ar[max+1];
   for(int i = 0; i <= max; i++)
        ar[i] = 0;
   for(int i = 0; i <= max; i++)
       ar[a[i]]++;
   for(int i = 1; i <= max; i++)
        ar[i] = ar[i] + ar[i-1];
    
     

    int arr[n];
    for(int i = n-1; i >= 0; i--)
        arr[--ar[a[i]]] = a[i];
     
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int n;
    cout << "Enter the number of Inputs :\n";
    cin >> n;
     
     int a[n];
    cout << "ENTER THE NUMBERS :\n";
    for(int i = 0; i < n; i++)
      cin >> a[i];
    Count_Sort(a, n);
    
}