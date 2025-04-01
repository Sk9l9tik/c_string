//defenitions
typedef unsigned long m_size_t;

#define M_NULL ((void*)0)

//functions

/**
* Finds the first occurrence of `c` in initial `n` bytes
*/
void* m_memchr(const void* str, int c, m_size_t n);

/**
* To compare first `n` bytes str1 and str2
* @warning if `lhs` or `rhs` is null it`s UB 
*/
int m_memcmp(const void* lhs, const void* rhs, m_size_t n);

/**
* Copy first `n` symbols from `src` to `dst`
*/
void* m_memcpy(void* dest, const void* src, m_size_t n);

void* m_memset(void* dest, int ch, m_size_t n);

char* m_strncat(char* dest, const char* src, m_size_t n);

char* m_strchr(const char* str, int c);

int m_strncmp(const char* lhs, const char* rhs, m_size_t n);

char* strncpy(char* dest, const char* src, m_size_t n);

char* m_strncpy(char* dest, const char* src, m_size_t n);

m_size_t m_strcspn(const char* dest, const char* src);

char* m_strerror(int errnum); //TODO: write impl

m_size_t strlen(const char* str);

char* m_strpbrk(const char* dest, const char* breakest);

char* m_strrchr(const char* str, int c);

char* m_strstr(const char* str, const char* substr); //TODO: write impl

char* m_strtok(char* str, const char* delim);