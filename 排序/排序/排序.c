//插入排序
void InsertSort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] >= data)
		{
			arr[end+1] = arr[end];
			--end;

		}
		arr[end + 1] = data;
	}
}

//希尔排序
void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 2;
		for (int i = gap; i < n; i++)
		{
			int end = i - gap;
			int data = arr[i];
			while (end >= 0 && data < arr[end])
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = data;
		}
	}
}


void Swap(int* arr, int pos1,int pos2)
{
	int tmp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = tmp;

}


void SelectSort(int* arr, int n)
{
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int minIdx = start;
		for (int i = start + 1; i <= end; ++i)
		{
			if (arr[i] < arr[minIdx])
			{
				minIdx = i;
			}
		}
		Swap(arr, start, minIdx);
		++start;
	}
}

void selectSort(int* arr, int n)
{
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int minIdx = start;
		int maxIdx = start;
		for (int j = start + 1; j <= end; ++j)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
			if (arr[j] > arr[maxIdx])
			{
				maxIdx = j;
			}
		}
		Swap(arr, start, minIdx);
		Swap(arr, end, maxIdx);
		++start;
		--end;
	}
}


void BubbleSort(int* arr, int n)
{
	int end = n;
	while (end > 1)
	{
		int flag = 0;
		for (int i = 1; i < end; i++)
		{
			if (arr[i - 1]>arr[i])
			{
				Swap(arr, i - 1, i);
				flag = 1;
			}
		}
		if (!flag)
		{
			break;
		}
		--end;
	}
}
//获取基准值
int getMid(int* arr, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])
		{
			return mid;
		}
		else if (arr[begin] > arr[end])
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
	else
	{
		if (arr[mid] < arr[end])
		{
			return mid;
		}
		else if (arr[begin] < arr[end])
		{
			return end;
		}
		else
		{
			return begin;
		}
	}
}
//返回划分后基准值所在位置
int partion(int* arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);
	int key = arr[begin];
	int start = begin;
	while (begin < end)
	{
		while (begin<end&&arr[end] >= key)
		{
			--end;
		}
		while (begin < end&&arr[begin] <= key)
		{
			++begin;
		}
		Swap(arr, begin, end);
	}
	Swap(arr, start, begin);

	return begin;

}


void quicksort(int* arr, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int div = partion(arr, begin, end);
	//左右两部分进行快排
	//begin,div-1     div+1,end
	quicksort(arr, begin, div - 1);
	quicksort(arr, div + 1, end);
}



int partion2(int*arr, int begin, int end)
{
	int mid = getMid(arr, begin, end);
	Swap(arr, begin, mid);
	int key = arr[begin];
	while (begin < end)
	{
		while (begin < end&&arr[end] >= key)
		{
			--end;
		}
		arr[begin] = arr[end];
		while (begin < end&&arr[begin] <= key)
		{
			++begin;
		}
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
	
}


int partion3(int* arr, int begin, int end)
{
	int prev = begin;
	int cur = begin + 1;
	int key = arr[begin];
	while (cur <= end)
	{
		if (arr[cur] < key&&++prev!=cur)
		{
			Swap(arr, prev, cur);

		}
		++cur;
	}
	Swap(arr, begin, prev);
	return prev;
}


void merge(int* arr, int begin, int mid, int end, int* tmp)
{
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int idx = begin;
	while (begin1 <= end1 && begin2 < end2)
	{
		if (arr[begin1] <= arr[begin2])
		{
			tmp[idx++] = arr[begin1++];
		}
		else
		{
			tmp[idx++] = arr[begin2++];
		}
		if (begin1 <= end1)
		{
			memcpy(tmp + idx, arr + begin1, sizeof(int)*(end1 - begin1 + 1));

		}

		if (begin2 <= end2)
		{
			memcpy(tmp + idx, arr + begin2, sizeof(int)*(end2 - begin2 + 1));

		}
		memcpy(arr + begin, tmp + begin, sizeof(int)*(end - begin + 1));
	}
}


void _mergesort(int* arr, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = begin + (end - begin) / 2;
	_mergesort(arr,begin,mid,tmp);
	_mergesort(arr,mid+1,end,tmp);

	merge(arr, begin, mid, end, tmp);
}

void mergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_mergesort(arr, 0, n-1, tmp);
	free(tmp);
}


