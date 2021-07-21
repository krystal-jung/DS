#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SeqList.h"
void init(SeqList* sl){
	sl->arr = NULL;
	sl->capicity = sl->size = 0;
}
void destroySeqList(SeqList* sl){
	if (sl){
		if (sl->arr){
			free(sl->arr);
			sl->arr = NULL;
			sl->capicity = sl->size = 0;
		}
	}
}

void erase(SeqList* sl, int pos){
	if (sl == NULL||sl->size==0){
		return;
	}
	if (pos >= 0 && pos <= sl->size){
		int end = sl->size;
		int start = pos+1;
		while (start < end){
			sl->arr[start-1] = sl->arr[start];
			++start;
		}
		--sl->size;
	}
}

void printSeqList(SeqList* sl){
	for (int i = 0; i < sl->size; ++i){
		printf("%d ", sl->arr[i]);
	}
	printf("\n");
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
		sl->arr = tmp;
		sl->capicity = newCapicity;
	}
}

void popFront(SeqList* sl){
	if (sl == NULL){
		return;
	}
	for (int start = 1; start < sl->size; ++start){
		sl->arr[start - 1] = sl->arr[start];
	}
	--sl->size;
}

void pushFront(SeqList* sl, SLDataTye val){
	if (sl == NULL){
		return;
	}
	checkCapicity(sl);
	for (int end = sl->size; end > 0; --end){
		sl->arr[end] = sl->arr[end-1];
	}
	sl->arr[0] = val;
	sl->size++;
}

void popBack(SeqList* sl){
	if (sl == NULL){
		return;
	}
	if (sl->size > 0){
		sl->size--;
	}
}

void pushBack(SeqList* sl, SLDataTye val){
	checkCapicity(sl);
	sl->arr[sl->size] = val;
	sl->size++;
}

void insert(SeqList* sl, int pos, SLDataTye val){
	if (sl == NULL){
		return;
	}
	if (pos >= 0 && pos <= sl->size){
		checkCapicity(sl);
		int start = pos;
		int end = sl->size;
		while (start < end){
			sl->arr[end] = sl->arr[end - 1];
			--end;
		}
		sl->arr[pos] = val;
		sl->size++;
	}
}

int findIdx(SeqList* sl, SLDataTye val){
	for (int i = 0; i < sl->size; i++){
		if (val == sl->arr[i]){
			return i;
		}
	}
	return -1;
}