#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

static char *read_all(FILE *f) {
    size_t cap = 4096, len = 0;
    char *buf = malloc(cap);
    if (!buf) return NULL;
    size_t n;
    while ((n = fread(buf + len, 1, cap - len, f)) > 0) {
        len += n;
        if (len == cap) {
            cap *= 2;
            char *tmp = realloc(buf, cap);
            if (!tmp) { free(buf); return NULL; }
            buf = tmp;
        }
    }
    buf[len] = '\0';
    return buf;
}

int main(int argc, char *argv[]) {
    // Open input file
    FILE *f = stdin;
    if (argc > 1) {
        f = fopen(argv[1], "r");
        if (!f) { perror(argv[1]); return 1; }
    }

    // Load all data
    char *text = read_all(f);
    if (f != stdin) fclose(f);
    if (!text) { fprintf(stderr, "Erreur de lecture\n"); return 1; }

    // Build regex
    regex_t re;
    if (regcomp(&re, "[[:alnum:]_-]+", REG_EXTENDED) != 0) {
        fprintf(stderr, "Erreur regex\n");
        free(text);
        return 1;
    }

    // Match words
    regmatch_t m;
    char *p = text;
    while (regexec(&re, p, 1, &m, 0) == 0) {
        fwrite(p + m.rm_so, 1, m.rm_eo - m.rm_so, stdout);
        putchar('\n');
        p += m.rm_eo;
    }

    // Free data
    regfree(&re);
    free(text);
}