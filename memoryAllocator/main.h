
#ifdef DEBUG
#define __DEBUGMAGIC int magic; // For debugging only.
#else
#define __DEBUGMAGIC
#endif

#define MYSTRING "Hello World\n"
#define MAX_2_POW_N 1073741824

struct block_meta {
  size_t size;
  struct block_meta *next;
  struct block_meta *prev;
  struct block_free *free_ptr;		//Used in case of merging
  int free;
  __DEBUGMAGIC
};

struct block_free {
  struct block_free *next;
  struct block_free *prev;
  struct block_meta *block;
};

#define META_SIZE sizeof(struct block_meta)

/*Global Variable Declarations*/
void *global_base = NULL;
void *global_free_base = NULL;
void *global_end = NULL;
void *global_free_end = NULL;

/*Functions Declaration*/

void myprint();
void print_meta_blk();
void print_free_blk();
void *mymalloc(size_t size);
void myfree(void *ptr);
struct block_meta *find_free_block(size_t size);
struct block_meta *find_free_block_from_list(size_t size);
struct block_meta *request_space(size_t size);
struct block_meta *get_block_ptr(void *ptr);
void *myrealloc(void *ptr, size_t size);
void *mycalloc(size_t nelem, size_t elsize);
