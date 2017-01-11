#ifndef MACROS
#define MACROS

// OOP helper methods
#define call(item, method) item->method(item)
#define apply(item, method, args...) item->method(item, args)
#define add_method(target, name) target->name = &name

// MIN and MAX
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

typedef enum {
  false=0,
  true,
} bool;

bool char_byte_compare(char *a, char *b, int length);
#endif
