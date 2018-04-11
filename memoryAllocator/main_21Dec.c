#include <stdio.h>
#include <malloc.h>
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

  //char *a = (char *)malloc(35); 
  char *a = (char *)mymalloc(35); 
  printf("Address of pointer a = [%p]\n",a);

  //char *b = (char *)malloc(35); 
  char *b = (char *)mymalloc(35); 
  printf("Address of pointer b = [%p]\n",b);

  myfree(a);
  myfree(b);

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
    block = request_space(NULL, size);
    if (!block) 
    {
      return NULL;
    }
    global_base = block;
  } 
  else 
  {
    struct block_meta *last = global_base;
    block = find_free_block(&last, size);
    if (!block) 
    { // Failed to find free block.
      block = request_space(last, size);
      if (!block) 
      {
        return NULL;
      }
    } 
    else 
    { // Found free block
      // TODO: consider splitting block here.
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
    return malloc(size);
  }

  struct block_meta* block_ptr = get_block_ptr(ptr);
  if (block_ptr->size >= size) {
    // We have enough space. Could free some once we implement split.
    return ptr;
  }

  // Need to really realloc. Malloc new space and free old space.
  // Then copy old data to new space.
  void *new_ptr;
  new_ptr = malloc(size);
  if (!new_ptr) {
    return NULL; // TODO: set errno on failure.
  }
  memcpy(new_ptr, ptr, block_ptr->size);
  free(ptr);
  return new_ptr;
}

void *mycalloc(size_t nelem, size_t elsize) {
  size_t size = nelem * elsize; // TODO: check for overflow.
  void *ptr = malloc(size);
  memset(ptr, 0, size);
  return ptr;
}

/*void myfree(void *ptr)
{
  free(ptr);
}*/

void myfree(void *ptr)
{
  if (!ptr) 
  {
    return;
  }

  // TODO: consider merging blocks once splitting blocks is implemented.
  struct block_meta* block_ptr = get_block_ptr(ptr);
  assert(block_ptr->free == 0);
  block_ptr->free = 1;
  #ifdef DEBUG
    assert(block_ptr->magic == 0x77777777 || block_ptr->magic == 0x12345678);
    block_ptr->magic = 0x55555555;
  #endif
}

struct block_meta *find_free_block(struct block_meta **last, size_t size)
{
  struct block_meta *current = global_base;
  while (current && !(current->free && current->size >= size)) {
    *last = current;
    current = current->next;
  }
  return current;
}

//struct block_meta *request_space(struct block_meta* last, size_t passed_size)
struct block_meta *request_space(struct block_meta* last, size_t size)
{
  struct block_meta *block;
  //size_t size;
  block = sbrk(0);
  //size=change_to_2_power_n(passed_size);
  void *request = sbrk(size + META_SIZE);
  assert((void*)block == request); // Not thread safe.
  if (request == (void*) -1)
  {
    return NULL; // sbrk failed.
  }

  if (last)
  { // NULL on first request.
    last->next = block;
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
