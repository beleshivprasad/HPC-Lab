#include<omp.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cout<<" Enter size of array:" << endl;
	cin>>n;
	int arr[n],b,crr[n],i;
	for(i=0;i<n;i++){
		arr[i] = i;
	}
	cout<<"Enter scalar: " << endl;
	cin>>b;
	omp_set_num_threads(n/3);
	#pragma omp parallel for shared(i)
	for(i=0;i<n;i++){
		crr[i] = arr[i] + b;
		cout << endl;
		cout << " Thread " << omp_get_thread_num() << " work on  " << i ;
	}
    for(i=0; i<n; i++){
        cout << endl;
		cout << arr[i] << " + " << b << " = " << crr[i]  ;
    }
	return 0;
}
