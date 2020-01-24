#include "vector.h"

	
vector initvector(size_t capacity)
{	/*if(capacity<10)
		capacity=10;*/
	vector new;
	new.data=(int*)malloc(sizeof(int)*capacity);
	new.capacity=capacity;
	new.size=0;
	return new;

}

void copy(vector *dest , vector *src)
{
	if(dest->capacity<src->size)
	{
		fprintf(stderr, "%s\n", "capacity<size");
		return;
	}
	size_t i;
	for ( i = 0; i < src->size; ++i)
		dest->data[i]=src->data[i];
	
}

void fill(vector* t , int v){
	size_t i;
	for ( i = 0; i < t->capacity; ++i)
		t->data[i]=v;

	t->size=t->capacity-1;
}

void printvector(vector t)
{
	size_t i;
	for (i = 0; i < t.size; ++i)
		printf("%d\n",t.data[i]);
}

void reserve(vector *t)
{
	vector*tmp;
	tmp->data=(int*)malloc(sizeof(int)*t->capacity);
	tmp->capacity=t->capacity;
	tmp->size=t->capacity;
	copy(tmp,t);
	free(t->data);
	t->data=(int*)malloc(sizeof (int)*t->capacity*2);
	t->capacity*=2;
	printf("entre dans reserve %d\n",t->capacity);
	copy(t,tmp);
}

void pushback(vector *t,int v)
{	if(t->size>=t->capacity)
		reserve(t);
	t->data[t->size]=v;
	t->size++;	
}

void freevector(vector *t)
{
	free(t->data);

}

int main(int argc, char const *argv[])
{

	return 0;
} 
