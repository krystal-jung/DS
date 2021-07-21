void shiftDown(int* arr,int n ,int cur){
	int child = 2 * cur + 1;
	while (child < n){
		if (child + 1 < n&&arr[child + 1] < arr[child]){
			++child;
		}
		if (arr[child] < arr[cur]){
			int tmp = arr[child];
			arr[child] = arr[cur];
			arr[cur] = tmp;
			cur = child;
			child = 2 * cur + 1;
		}
		else{
			break;
		}
	}

}