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

  myfree(a);
  myfree(e);

  a = (char *)mymalloc(20);
  printf("Address of pointer a = [%p]\n",a);

  print_meta_blk();
  print_free_blk();

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
    
    struct block_free* freed_block;
    freed_block = malloc(sizeof(struct block_free));
    if(!freed_block)
      return;
    memset(freed_block,0,sizeof(struct block_free));
    freed_block->block = splitted_block;
    splitted_block->free_ptr = freed_block;
    if(!global_free_base)
    {
      global_free_base = freed_block;
      global_free_end = freed_block;
    }
    else
    {
      ((struct block_free*)global_free_end)->next = freed_block;
      freed_block->prev = (struct block_free*)global_free_end;
      global_free_end = (void *)freed_block;
    }

    #ifdef DEBUG
      current->magic = 0x66666666;
      splitted_block->magic = 0x66666666;
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
    block = find_free_block_from_list(size);
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
      free(block->free_ptr);
      block->free = 0;
      block->free_ptr = NULL;

      #ifdef DEBUG
        block->magic = 0x77777777;
      #endif
    }
  }
  return(block+1);
  block->free_ptr = NULL;
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

int merge_free_block(struct block_meta* block_ptr)
{

  if(!block_ptr)
    return -1;
  
  struct block_meta** _prev = &(block_ptr->prev);
  struct block_meta** _next = &(block_ptr->next);
  struct block_free** _free_ptr = &(block_ptr->free_ptr);
 
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
  if(*_next && (*_next)->free == 1)
  {
    //Merging and freeing in free list
    {
      if((struct block_free*)((*_next)->free_ptr)->prev)
        ((struct block_free*)((*_next)->free_ptr))->prev->next = (struct block_free*)((*_next)->free_ptr)->next;
      else if((*_next)->free_ptr == global_free_base)
        global_free_base = (void*)((*_next)->free_ptr)->next;

      if((struct block_free*)((*_next)->free_ptr)->next)
        ((struct block_free*)((*_next)->free_ptr))->next->prev = (struct block_free*)((*_next)->free_ptr)->prev;
      else if((*_next)->free_ptr == global_free_end)
        global_free_end = (void*)((*_next)->free_ptr)->prev;

      free((*_next)->free_ptr);
    }

    //A->block_ptr B->_next  C->_next->next
    //A->B->C   A<-B<-C
    block_ptr->size += ((*_next)->size + META_SIZE);
    *_next = (*_next)->next;
    //A->block_ptr B-> C->_next
    //A->C   A<-B<-C
    if(*_next)
    {
      (*_next)->prev = block_ptr;
      if((*_next)->free_ptr)
        (*_next)->free_ptr->prev = *_free_ptr;
    }
    //A->C   A<-C
  }

  if(*_prev && (*_prev)->free == 1)
  {
    //Merging and freeing in free list
    {
      if((*_free_ptr)->prev)
        (*_free_ptr)->prev->next = (*_free_ptr)->next;
      else if((*_free_ptr) == global_free_base)
        global_free_base = (void*)(*_free_ptr)->next;

      if((*_free_ptr)->next)
        (*_free_ptr)->next->prev = (*_free_ptr)->prev;
      else if((*_free_ptr) == global_free_end)
        global_free_end = (void*)(*_free_ptr)->prev;

      free(*_free_ptr);
    }

    //A->_prev B->block_ptr C->_next
    //A->B->C   A<-B<-C
    (*_prev)->size += (block_ptr->size + META_SIZE);
    (*_prev)->next = *_next;
    //A->_prev B-> C->_next
    //A->C   A<-B<-C
    if(*_next)
    {
      (*_next)->prev = *_prev;
      (*_prev)->free_ptr->next = (*_next)->free_ptr;
      if((*_next)->free_ptr)
        (*_next)->free_ptr->prev = (*_prev)->free_ptr; 
    }
    //A->C   A<-C
  }
  return 0;
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

  struct block_free* freed_block;
  freed_block = malloc(sizeof(struct block_free));
  if(!freed_block)
    return;
  memset(freed_block,0,sizeof(struct block_free));
  freed_block->block = block_ptr;
  block_ptr->free_ptr = freed_block;
  if(!global_free_base)
  {
    global_free_base = freed_block;
    global_free_end = freed_block;
  }
  else
  {
    ((struct block_free*)global_free_end)->next = freed_block;
    freed_block->prev = (struct block_free*)global_free_end;
    global_free_end = (void *)freed_block; 
  }
    
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

struct block_meta *find_free_block_from_list(size_t size)
{
  struct block_free *current = global_free_base;
  while (current && !(current->block->size >= size)) 
  {
    current = current->next;
  }

  if(current)
  {
    if(current==global_free_base)
      global_free_base=NULL;
    if(current==global_free_end)
      global_free_end=NULL;

    if(current->prev)
    {
      current->prev->next = current->next;
      if(global_free_end==NULL)
        global_free_end=current->prev;
    }

    if(current->next)
    {
      current->next->prev = current->prev;
      if(global_free_base == NULL)
        global_free_base = current->next;
    }
    
    if(global_free_base==NULL)
      global_free_base=global_free_end;
    if(global_free_end==NULL)
      global_free_end=global_free_base;

    return current->block;
  }

  return NULL;
}


void print_meta_blk()
{
  struct block_meta *current = global_base;
  printf("Meta List\n");
  while (current) 
  {
    printf("Addresss:%p,size:%lu,next:%p,prev:%p,free:%d,free_ptr:%p\n",current,current->size,current->next,current->prev,current->free,current->free_ptr);
    current = current->next;
  }
}

void print_free_blk()
{
  struct block_free *current = global_free_base;
  printf("Free List\n");
  while (current)
  {
    printf("Addresss:%p,next:%p,prev:%p,block:%p\n",current,current->next,current->prev,current->block);
    current = current->next;
  }
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
