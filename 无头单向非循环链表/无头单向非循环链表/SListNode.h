typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;


SListNode* creatListNode(SLTDataType val);
void SListPrint(SListNode* plist);
void SListPushBack(SListNode** pphead, SLTDataType val);
void SListPopBack(SListNode** pphead);
void SListPushFront(SListNode** pphead, SLTDataType val);
void SListPopFront(SListNode** pphead);

void SListEraseAfter(SListNode* pos);
void SListInsertAfter(SListNode* pos, SLTDataType val);
SListNode* SListFind(SListNode* phead, SLTDataType val);
int listSize(SListNode** pphead);
void listDestory(SListNode** pphead);