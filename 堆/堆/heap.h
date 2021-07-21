typedef int HDataType;
typedef struct heap
{
	HDataType* data;
	int size;
	int capacity;
}heap;
void Swap(int* a, int* b);
void checkCapcity(heap* hp);
void shiftDown(int* arr, int n, int cur);
void shiftUp(int* arr, int n, int cur);
void heapInit(heap* hp);
void heapCreate(heap* hp, int* arr, int n);
void heapDestory(heap* hp);
void heapPush(heap* hp, HDataType val);
void heapPop(heap* hp);
HDataType heapTop(heap* hp);
int heapEmpty(heap* hp);
void heapSort(heap* hp);
void HeapPrint(heap* hp);
