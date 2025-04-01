#include "m_string.h"

void* m_memchr(const void* str, int c, m_size_t n){
    if (str == M_NULL) return M_NULL;
    
    const char* src = (const char*)str;
    const char ch = (const char)c;

    while(n-->0){
        if (*src == ch){
            return (void*)src;
        }
        ++src;
    }
    return M_NULL;
}

int m_memcmp(const void *lhs, const void *rhs, m_size_t n){
    const unsigned char* src1 = (const unsigned char*)lhs;
    const unsigned char* src2 = (const unsigned char*)rhs;

    while(n --> 0 ){
        if (*src1 == *src2){
            ++src1;
            ++src2;
        }
        else if (*src1 < *src2){
            return -1;
        }
        else{
            return 1;
        }
    }
    return 0;
}

void *m_memcpy(void *dest, const void *src, m_size_t n){
    unsigned char *pd = dest;
    const unsigned char *ps = src;
    
    for(int i = 0; i < n; ++i){
        pd[i] = ps[i];
    }
    
    return dest;
}

void* m_memset(void* dest, int ch, m_size_t n){
    unsigned char* p = dest;
    unsigned char uc = (unsigned char)ch;
    
    for (m_size_t i = 0; i < n; i++) {
        p[i] = uc;
    }
    
    return dest;
}

char* m_strncat(char *dest, const char *src, m_size_t n){
    if (n == 0) return dest;

    char* p = dest;
    for(int i = 0; *p != '\0'; ++i)
        ++p;

    for(int i = 0; i < n; ++i){
        *p = src[i];
        ++p;
    }
    *p = '\0';

    return dest;
}

char* m_strchr(const char *str, int c){
    unsigned char uc = (unsigned char)c;
    unsigned char ch = *str;
    if (ch == c) return (char*)str;

    for(int i = 0; ch != '\0'; ++i){
        if (ch == uc) return ((char*)str + i - 1);
        ch = *(str + i);
    }
    return M_NULL;
}

int m_strncmp(const char *lhs, const char *rhs, m_size_t n){ //TODO: проверить по стандарту
    while(n --> 0){
        if (*lhs != *rhs)
            return *(unsigned char*)lhs - *(unsigned char*)rhs;
        ++lhs;
        ++rhs;
    }
    return 0;
}

char* m_strncpy(char* dest, const char* src, m_size_t n){
    for(int i = 0; i < n || src[i] != '\0'; ++i){
        dest[i] = src[i];
    }
    return dest;
}

m_size_t m_strcspn(const char* dest, const char* src){
    unsigned char table[128] = {0};
    const unsigned char* s = (const unsigned char*)src;

    while (*s){
        if (*s < 128)
            table[*s] = 1;
        ++s;
    }

    const unsigned char* d = (const unsigned char*)dest;
    while(*d){
        if(*d < 128 && table[*d]){
            break;
        }
        ++d;
    }

    return (m_size_t)(d - (const unsigned char*)dest);
}

m_size_t strlen(const char* str){
    if (!str) return 0;

    m_size_t sz = 0;
    while(*str != '\0'){
        ++sz;
        ++str;
    }
    return sz;
}

char* m_strpbrk(const char* dest, const char* breakest){

    unsigned char table[128] = {0};
    const unsigned char* s = (const unsigned char*)breakest;

    while (*s){
        if (*s < 128)
            table[*s] = 1;
        ++s;
    }

    const unsigned char* d = (const unsigned char*)dest;
    while(*d){
        if (*d < 128 && table[*d])
            return (char* )d;
        ++d;
    }
    return M_NULL;
}

char* m_strrchr(const char* str, int c){
    unsigned char uc = (unsigned char)c;
    unsigned char ch = *str;
    if (ch == c) return (char*)str;

    for(int i = strlen(str); i > 0; --i){
        if (ch == uc) return ((char*)str + i - 1);
        ch = *(str + i);
    }
    return M_NULL;
}

char* m_strstr(const char* str, const char* substr){
    if (!*substr) return (char *)str;
    
    for (m_size_t i = 0; str[i]; i++) {
        m_size_t j = 0;
        while (substr[j] && str[i + j] == substr[j]) {
            j++;
        }
        if (!substr[j]) {
            return (char *)&str[i];
        }
    }
    
    return M_NULL; 
} 

char* m_strtok(char* str, const char* delim) {
    static char* buf = M_NULL;
    char* start, *next_tok;

    if (str != M_NULL){
        start = str;
    }
    else{
        if (buf == M_NULL) return M_NULL;
        start = buf;
    }

    while(*start && m_strpbrk(start,delim) == start)
        ++start;

    if (start == M_NULL) return M_NULL;

    next_tok = m_strpbrk(start,delim);
    
    if (next_tok != M_NULL){
        *next_tok = '\0';
        buf = next_tok + 1;
    }
    else {
        buf = M_NULL;
    }

    return start;
}