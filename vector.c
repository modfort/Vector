#include "vector.h"

	
vector initvector(size_t capacity)
{	if(capacity<1)
		capacity=2;
	
	vector new;
	new.data = (int*) malloc(sizeof(int) * capacity);
	assert(new.data);
	new.capacity = capacity;
	new.size = 0;
	return new;
}

void copy(vector *dest , vector *src)
{
	if(dest->capacity<=src->size)
	{
		fprintf(stderr, "%s\n", "capacity<size");
		exit(1);
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

void printvector(vector *t)
{
	size_t i;
	for (i = 0; i < t->size; ++i)
		printf("%ld : %d\n",i,t->data[i]);
}

void reserve(vector *t)
{
	vector  tmp;
	tmp.data = (int*) malloc( sizeof(int) * t->capacity );
	if(tmp.data==NULL)
	{
		fprintf(stderr, "erreur d'allocation\n" );
		exit(0);
	}
	assert(tmp.data);
	tmp.capacity = t->capacity;
	tmp.size = t->capacity;
	copy(&tmp,t);
	free(t->data);
	t->data = (int*)malloc(sizeof (int)*t->capacity*2);
	assert(t->data);
	t->capacity *= 2;
	copy(t,&tmp);
}

void pushback(vector *t,int v)
{	
	if(t->size >= t->capacity-1)
		reserve(t);
	
	t->data[t->size] = v ;
	t->size++;	
}

void pushfront(vector*t,int v)
{	
	if( t->size >= t->capacity - 1 )
		reserve(t);
	size_t i;
	for ( i = t->size ; i >0 ; --i )
		t->data[i] = t->data[i-1];
	t->data[0] = v;
	t->size++;
	
}

int front(vector*t){
	return t->data[0];
} 

int back(vector*t)
{
	return t->data[t->size-1];
}

size_t size(vector*t)
{
	return t->size;
}

size_t capacity(vector*t)
{
	return t->capacity;
}

void freevector(vector *t)
{
	free(t->data);
}

