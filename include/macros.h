
#ifndef MACROS
#define MACROS

// OOP helper methods
#define call(item, method) item->method(item)
#define apply(item, method, args...) item->method(item, args)

#endif
