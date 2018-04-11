#include <stdio.h>
//#include <malloc.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

#include "main.h"

void main1()
{
  printf(MYSTRING);
  myprint();
}

void myprint()
{
  printf("myprint func");
}

void main()
{
  printf("Method main() is called.\n");

  char *a = (char *)mymalloc(35); 
  printf("Address of pointer a = [%p]\n",a);

  char *b = (char *)mymalloc(35); 
  printf("Address of pointer b = [%p]\n",b);

  char *c = (char *)mymalloc(35); 
  printf("Address of pointer c = [%p]\n",c);

  b = myrealloc(b,70);

  char *d = (char *)mymalloc(35); 
  printf("Address of pointer d = [%p]\n",d);

  char *e = (char *)mymalloc(35); 
  printf("Address of pointer e = [%p]\n",e); 

  myfree(b);
  myfree(d);
  myfree(c);
 
  char *f = (char *)mymalloc(60); 
  printf("Address of pointer f = [%p]\n",f);

  printf("Method main() ends.\n");  
}

/*void * mymalloc(size_t size)
{
  void * ptr = NULL;
  void * top = NULL;

  top = (void *)sbrk(0);
  printf("Address of current top of the heap [%p]\n",top);

  ptr = (void *)sbrk(size);
  if (ptr == (void*) -1) {
    return NULL; // sbrk failed.
  }

  return ptr;
}*/

size_t align_size(size_t size)
{
  return ((size / 8 + 1) * 8);
}

void split_block(struct block_meta* current, size_t size)
{
  struct block_meta* splitted_block;
  if(current && current->size >= size + META_SIZE + 8) /*will split the block only if left over block is greater than 
                                                         size of structure of meta data plus 8. So that block should be of atleast 8 bytes*/
  {
    splitted_block = (void *)current + size + META_SIZE;
    splitted_block->size = current->size - size - META_SIZE;
    current->size = size;
    splitted_block->next = current->next;
    splitted_block->prev = current;
    current->next = splitted_block;
    splitted_block->free = 1;
    if(splitted_block->next)
      (splitted_block->next)->prev = splitted_block;
    #ifdef DEBUG
      block->magic = 0x66666666;
    #endif
  }
}

void *mymalloc(size_t size) 
{
  struct block_meta *block;
  // TODO: align size?    //DONE
  size = align_size(size);

  if (size <= 0) 
  {
    return NULL;
  }

  if (!global_base) 
  { // First call.
    block = request_space(size);
    if (!block) 
    {
      return NULL;
    }
    global_base = block;
    global_end = block;
    block->prev = NULL;
  } 
  else 
  {
    block = find_free_block(size);
    if (!block) 
    { // Failed to find free block.
      block = request_space(size);
      if (!block) 
      {
        return NULL;
      }
      block->prev = global_end;
      global_end = block;
    } 
    else 
    { // Found free block

      // TODO: consider splitting block here.    //DONE refer split_block(block, size)
      split_block(block, size);

      block->free = 0;

      #ifdef DEBUG
        block->magic = 0x77777777;
      #endif
    }
  }
  return(block+1);
}

void *myrealloc(void *ptr, size_t size) {
  if (!ptr) {
    // NULL ptr. realloc should act like malloc.
    return mymalloc(size);
  }
  else if(size == 0)		//Size passed is 0 so calling my free to free the pointer
  {
    myfree(ptr);
    return (void *) -1;
  }

  struct block_meta* block_ptr = get_block_ptr(ptr);
  if (block_ptr->size >= size) {
    // We have enough space. Could free some once we implement split.
    return ptr;
  }

  // Need to really realloc. Malloc new space and free old space.
  // Then copy old data to new space.
  void *new_ptr;
  new_ptr = mymalloc(size);
  if (!new_ptr) {
    return NULL; // TODO: set errno on failure.
  }
  memcpy(new_ptr, ptr, block_ptr->size);
  myfree(ptr);
  return new_ptr;
}

void *mycalloc(size_t nelem, size_t elsize) {
  size_t size = nelem * elsize; // TODO: check for overflow.
  void *ptr = mymalloc(size);
  memset(ptr, 0, size);
  return ptr;
}

/*void myfree(void *ptr)
{
  free(ptr);
}*/

struct block_meta* merge_free_block(struct block_meta* block_ptr)
{
  struct block_meta** __prev = &(block_ptr->prev);
  struct block_meta** __next = &(block_ptr->next);
 
  /*
  * In scenario of block getting merged:
  * A would be the block that will keep meta data and update meta data according to the block merged
  * B would be the block that will disappear after getting merged in A and it would be next to A
  * C would be the block next to the B
  *
  * Steps taken to be merged :
  * Step 1: size(A) += size(B)
  * Step 2: next(A) = C
  * Step 3: prev(C) = A
  */ 
  if(*__next && (*__next)->free == 1)
  {
    //A->block_ptr B->__next  C->__next->next
    //A->B->C	A<-B<-C
    block_ptr->size += ((*__next)->size + META_SIZE);
    *__next = (*__next)->next;
    //A->block_ptr B-> C->__next
    //A->C   A<-B<-C
    if(*__next)
    (*__next)->prev = block_ptr;
    //A->C   A<-C
  }

  if(*__prev && (*__prev)->free == 1)
  {
    //A->__prev B->block_ptr C->__next
    //A->B->C   A<-B<-C
    (*__prev)->size += (block_ptr->size + META_SIZE);
    (*__prev)->next = *__next;
    //A->__prev B-> C->__next
    //A->C   A<-B<-C
    if(*__next)
      (*__next)->prev = *__prev;
    //A->C   A<-C
  }
}

void myfree(void *ptr)
{
  if (!ptr) 
  {
    return;
  }

  // TODO: consider merging blocks once splitting blocks is implemented. DONE Refer merge_free_block (struct block_meta* block_ptr)
  struct block_meta* block_ptr = get_block_ptr(ptr);
  assert(block_ptr->free == 0);
  block_ptr->free = 1;
  #ifdef DEBUG
    assert(block_ptr->magic == 0x77777777 || block_ptr->magic == 0x12345678);
    block_ptr->magic = 0x55555555;
  #endif
  merge_free_block(block_ptr);
}

struct block_meta *find_free_block(size_t size)
{
  struct block_meta *current = global_base;
  while (current && !(current->free && current->size >= size)) 
  {
    current = current->next;
  }
  return current;
}

struct block_meta *request_space(size_t size)
{
  struct block_meta *block;
  block = sbrk(0);
  void *request = sbrk(size + META_SIZE);
  assert((void*)block == request); // Not thread safe.
  if (request == (void*) -1)
  {
    return NULL; // sbrk failed.
  }

  if (global_end)
  { // NULL on first request.
    ((struct block_meta*)global_end)->next = block;
  }
  block->size = size;
  block->next = NULL;
  block->free = 0;
  #ifdef DEBUG
    block->magic = 0x12345678;
  #endif
  return block;
}

struct block_meta *get_block_ptr(void *ptr) {
  return (struct block_meta*)ptr - 1;
}

size_t change_to_2_power_n(size_t value)
{
  size_t ret = MAX_2_POW_N  >> 1; /* Right shift 1 bit means divide by 2 */

  while(ret > 0)
  {
    if (value > ret)
      return (ret << 1); /* Left shift one bit means multiply by 2 */

    ret = ret >> 1; /* Right shift 1 bit means divide by 2 */
  }

  return value;
}
