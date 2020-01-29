#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <errno.h>
typedef struct vector
{	
	int *data;
	size_t size,capacity;
}vector;
vector initvector(size_t capacity);
void copy(vector *dest , vector *src);
void fill(vector* t , int v);
void printvector(vector* t);
void reserve(vector *t);
void pushfront(vector*t,int v);
void pushback(vector *t,int v);
int front(vector*t);
int back(vector*t);
void freevector(vector *t);
size_t size(vector*);
size_t capacity(vector*);