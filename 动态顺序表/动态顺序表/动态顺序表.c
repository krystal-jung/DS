#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SeqList.h"

void init(SeqList* sl){
	sl->arr = NULL;
	sl->capicity = sl->size = 0;
}

void pushBack(SeqList* sl, SLDataTye val){
	checkCapicity(sl);
	sl->arr[sl->size] = val;
	sl->size++;

}

void checkCapicity(SeqList* sl){
	if (sl == NULL){
		return;
	}
	if (sl->capicity == sl->size){
		int newCapicity = sl->capicity == 0 ? 1 : 2 * sl->capicity;
		SLDataTye* tmp = (SLDataTye*)malloc(sizeof(SLDataTye)*newCapicity);
		memcpy(tmp, sl->arr, sizeof(SLDataTye)*sl->size);
		free(sl->arr);

		//sl->arr = (SLDataTye*)realloc(sl->arr, sizeof(SLDataTye)*newCapicity);
		
		sl->arr = tmp;
		sl->capicity = newCapicity;
		
	}
}
int main()
{
	SeqList sl;
	init(&sl);
	system("pause");
	return 0;
}