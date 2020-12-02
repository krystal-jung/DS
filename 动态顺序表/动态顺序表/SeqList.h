typedef int	SLDataTye;
typedef struct SeqList{
	SLDataTye* arr;
	size_t size;
	size_t capicity;

}SeqList;
void init(SeqList* sl);
void pushBack(SeqList* sl, SLDataTye val);
void checkCapicity(SeqList* sl);