#include<omp.h>
#include<bits/stdc++.h>
#include<time.h>
using namespace std;

int main()
{
    long n=1000;
    long arr[n],brr[n],crr[n];
    for(long i=0;i<n;i++)
    {
        brr[i]=i;
        crr[i]=i;
    }
    clock_t start = clock();
    clock_t stop;
    #pragma omp parallel for schedule(static,100)
    for(long  i=0;i<n;i++)
    {
        arr[i]=brr[i]+crr[i];
        cout << endl << " Thread " << omp_get_thread_num() << " work on " << i;
    }

    #pragma omp barrier
    {
        stop = clock();
    }


    for(long i=0;i<n;i++)
    {
        cout << endl << brr[i] << " + " << crr[i] << " = " << arr[i] ;
    }

    cout << endl << "Execution time " << double(stop - start)/CLOCKS_PER_SEC << " seconds " << endl;
}
