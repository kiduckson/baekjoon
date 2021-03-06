void swap(int *a,int *b)
{
  int tmp;
  tmp=*a;
  *a=*b;
  *b=tmp;
}
int max(int a,int b,int c)
{
  int max=0,q;
  if(tree[a]>max) {
    max=tree[a];
    q=a;
  }
  if(tree[b]>max) {
    max=tree[b];
    q=b;
  }
  if(tree[c]>max) {
    max=tree[c];
    q=c;
  }
  return q;
}
void create_heap()
{
  end=N/2;
  for(i=end;i>=1;i--) {
    nnow=i;
    while((qq=max(nnow,nnow*2,nnow*2+1))!=nnow) {
      swap(&tree[nnow],&tree[qq]);
      nnow=qq;
    }
  }
}

void hsort(int a[], int n)
{
	int i, tmp;
	for (i=n/2-1;i>=0;i--)
		makeTreeHeap(i,n);
	for (i=n-1;i>=1;i--){
		tmp=a[i];a[i]=a[0];a[0]=tmp;
		makeTreeHeap(1,i-1);
	}
}
