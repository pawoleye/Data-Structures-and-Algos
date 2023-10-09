void mySort (int d[], unsigned int n){
		int i;
		int j;
		int key;
		for (j=1; j<n;j++){
		  key = d[j];
		  i=j-1;
		  while(i>=0 && d[i] > key){
			d[i+1]=d[i];
			i = i -1;
		}
		d[i+1] = key;
		}
}
