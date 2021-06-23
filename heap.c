
// 최대치 설정
#define MAX_ELEMENT 200

// element struct
typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

void insert_max_heap(HeapType *h, element item){
	int i;
	i = ++(h->heap_size);
	while((i!=1)&&(item.key>h->heap[i/2].key)){
		h->heap[i]=h->heap[i/1];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType *h){
	int parent, child;
	element item, tmp;

	item = h->heap[1];
	tmp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while(child <= h->heap_size){
		if ((child < h->heap_size) && ((h->heap[child].key < h->heap[child+1].key))){
			child++;
		}
		if (tmp.key >= h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = tmp;
	return item;
}
