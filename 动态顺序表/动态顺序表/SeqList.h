typedef int	SLDataTye;
typedef struct SeqList{
	SLDataTye* arr;   //指向动态开辟的数组
	size_t size;      //有效数据个数
	size_t capicity;  //容量空间大小
}SeqList;


void init(SeqList* sl);
void destroySeqList(SeqList* sl);
void erase(SeqList* sl ,int pos);
void printSeqList(SeqList* sl);
void checkCapicity(SeqList* sl);
void pushBack(SeqList* sl, SLDataTye val);
void popBack(SeqList* sl);
void pushFront(SeqList* sl, SLDataTye val);
void popFront(SeqList* sl);
void insert(SeqList* sl, int pos, SLDataTye val);
int findIdx(SeqList* sl, SLDataTye val);