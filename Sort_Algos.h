void Merge(int a[], int l, int m, int h)
{
    int a_n = m - l + 1;
    int b_n = h - m;

     int arr_a[a_n];
     int arr_b[a_n];
    for(int i = 0; i < a_n; i++)
          arr_a[i] = a[l+i];
    for(int i = 0; i < b_n; i++)
          arr_b[i] = a[m+i+1];

    int a_i = 0, b_i = 0, arr_i = l;
    while(a_i < a_n && b_i < b_n)
    {
        if(arr_a[a_i] < arr_b[b_i])
          a[arr_i++] = arr_a[a_i++];
        else
          a[arr_i++] = arr_b[b_i++];
    }  

    while(a_i < a_n)
    a[arr_i++] = arr_a[a_i++];

    while(b_i < b_n)
    a[arr_i++] = arr_b[b_i++];
}

void Merge_Sort(int a[], int l, int h)
{
    if(l < h)
    {
       int mid = (l + h)/2;
       Merge_Sort(a, l , mid);
       Merge_Sort(a, mid+1, h);
       Merge(a, l, mid, h);
    }
}
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