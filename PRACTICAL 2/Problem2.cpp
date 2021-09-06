#include<omp.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter size of array: " << endl;
	cin>>n;
	int arr[n],b,crr[n],i;
	for(i=0;i<n;i++){
		arr[i] = i;
	}
	cout<<"Enter scalar: " << endl;
	cin>>b;
	#pragma omp parallel for shared(arr,b,crr) num_threads(n/4)
	for(i=0;i<n;i++){
		crr[i] = arr[i] + b;
		cout << endl << " Thread " << omp_get_thread_num() << " work on " << i ;
	}
    for(i=0; i<n; i++) {
		cout << endl << arr[i] << " + " << b << " = " << crr[i] ;
    }
	return 0;
}
