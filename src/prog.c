#include<kv.h>


/* 
  fn kv_put 
  params: 
    - db: a pointer to the db 
    - key: a pointer to the key value 
    - value: a pointer to the value itself
    returns: the index of the key, otherwise an 
    error, returns -1
*/

// NOT a cryptographically sound hash
size_t hash(char *val, int capacity) {
  size_t hash = 0x13371337deadbeef;

  while(*val) {
    
    hash ^= *val;
    hash = hash << 8;
    hash += *val;

    val++;
  }
  return hash % capacity;
}

int kv_put(kv_t *db, char *key, char *value){
  if (!db || !key || !value) return -1;
}

typedef struct {
    char *key;
    char *value;
} kv_entry_t;



kv_t *kv_init(size_t capacity) {
  if (capacity == 0) return NULL;

  kv_t *table = malloc(sizeof(kv_t));
  if (table == NULL) {
   return NULL;
 }
    
 table->capacity = capacity;
 table->count = 0;

 table->entries = calloc(sizeof(kv_entry_t), capacity);
 if(table->entries == NULL) {
   return NULL;
 }
 return table; 

 }
