#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>

#ifdef DEBUG_LEVEL

# if DEBUG_LEVEL == 1
#define DEBUG_PRINT(fmt, ...) do {                                      \
    printf("DEBUG: func=%s, line=%d\n", __func__, __LINE__);            \
} while (0)

#elif DEBUG_LEVEL == 2

#define DEBUG_PRINT(fmt, ...) do {                                      \
    printf("DEBUG: func=%s, line=%d, ", __func__, __LINE__);            \
    printf(fmt, ##__VA_ARGS__);                                         \
    printf("\n");                                                      \
} while (0)

#elif DEBUG_LEVEL == 3

#define DEBUG_PRINT(fmt, ...) do {                                      \
    printf("DEBUG: func=%s, line=%d, ", __func__, __LINE__);            \
    printf(fmt, ##__VA_ARGS__);                                         \
    printf("\n");                                                      \
                                                                         \
    void *buffer[100];                                                  \
    int nptrs = backtrace(buffer, 100);                                  \
    char **symbols = backtrace_symbols(buffer, nptrs);                   \
                                                                         \
    if (symbols != NULL) {                                               \
        printf("Backtrace:\n");                                         \
        for (int i = 0; i < nptrs; i++) {                                \
            printf("  %s\n", symbols[i]);                               \
        }                                                                \
        free(symbols);                                                   \
    }                                                                    \
} while (0)

#endif

#endif



void test() {
    int x = 42;
    DEBUG_PRINT("x=%d", x);
}

int main() {
    test();
    return 0;
}