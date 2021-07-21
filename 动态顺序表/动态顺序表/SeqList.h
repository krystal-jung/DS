typedef int	SLDataTye;
typedef struct SeqList{
	SLDataTye* arr;   //ָ��̬���ٵ�����
	size_t size;      //��Ч���ݸ���
	size_t capicity;  //�����ռ��С
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