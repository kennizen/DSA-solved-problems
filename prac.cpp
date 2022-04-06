#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int merge(int ar[], int tmp[], int s, int m, int e)
{
    int count = 0;

    int i = s;
    int j = m + 1;
    int k = s;

    while (i <= m && j <= e)
    {
        if (ar[i] < ar[j])
        {
            tmp[k++] = ar[i++];
        }
        else
        {
            tmp[k++] = ar[j++];
            count += (m + 1) - i;
        }
    }

    while (i <= m)
    {
        tmp[k++] = ar[i++];
    }

    while (j <= e)
    {
        tmp[k++] = ar[j++];
    }

    for (i = s; i <= e; i++)
    {
        ar[i] = tmp[i];
    }

    return count;
}
int mergeSort(int ar[], int tmp[], int s, int e)
{
    if (s >= e)
    {
        return 0;
    }

    int m, count = 0;
    m = (s + e) / 2;

    count += mergeSort(ar, tmp, s, m);
    count += mergeSort(ar, tmp, m + 1, e);

    count += merge(ar, tmp, s, m, e);

    return count;
}

int main()
{
    int ar[] = {3,2,1};
    int temp[3];

    cout << mergeSort(ar, temp, 0, 2) << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
    return 0;
}
