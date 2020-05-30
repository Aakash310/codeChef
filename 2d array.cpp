#include<bits/stdc++.h>
using namespace std;



int main(){
	int n;
	cin>>n;
	
	int arr[n][n];
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin>>arr[i][j];
		}
	}
	
	int m = 0;
	int k = 0;
	int count = 0 ;
	int stop = 0;
	bool need1 = true;
	bool need2 = true;
	bool truth = true;
	while(need1 && need2){
		stop = 0;
		if(truth == true){
	      for(int i = k ; i < k+1 && k <= n-2; i++){
	       	for(int j = 0 ; j < n ; j++){
			  if(arr[i][j] > arr[i+1][j]){
			  	count++;
			  	stop++;
				int temp = arr[i][j];
				arr[i][j] = arr[i+1][j];
				arr[i+1][j] = temp;
		    	}
		   }
    	}
    	if(stop == 0){
		  need1 = false;
		}
    	k++;
    	k=k%(n-1);
    	truth = false;
		}else{
			for(int i = 0 ; i < n; i++){
		        for(int j = m ; j < m+1 && m <= n-2; j++ ){
			       if(arr[i][j] > arr[i][j+1]){
			       	    count++;
			       	    stop++;
				        int temp = arr[i][j];
				        arr[i][j] = arr[i][j+1];
				        arr[i][j+1] = temp;
			       }
		       }
        	}
        	if(stop == 0){
		       need2 = false;
		   }  
        	m++;
        	m=m%(n-1);
	        truth = true;
		}
	}
	cout<<count<<endl;
	//row_exch(arr);
	//col_exch(arr);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cout<<arr[i][j]<<' ';
		}
		cout<<endl;
	}
	
	
	return 0;
}
