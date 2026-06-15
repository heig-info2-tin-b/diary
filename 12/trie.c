#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

typedef struct node {
    int count;
    struct node *children[26];
} Node;

void add_word_to_trie(Node *root, const char *word) {
    Node *cur = root;
    for (const char *p = word; *p; p++) {
        unsigned char c = (unsigned char)*p;
        if (!isalpha(c)) continue; // skip non a-z characters
        int idx = tolower(c) - 'a';
        if (!cur->children[idx]) {
            cur->children[idx] = calloc(1, sizeof(Node));
            if (!cur->children[idx]) abort();
        }
        cur = cur->children[idx];
    }
    cur->count++;
}

// Recursive walk: fills two parallel arrays (word, occurrences).
static void collect_words(Node *node, char *buf, int depth,
                          char ***words, int **counts,
                          int *n, int *cap) {
    if (!node) return;

    if (node->count > 0) {
        buf[depth] = '\0';
        if (*n == *cap) {
            *cap = (*cap == 0) ? 64 : *cap * 2;
            *words  = realloc(*words,  *cap * sizeof(char*));
            *counts = realloc(*counts, *cap * sizeof(int));
            if (!*words || !*counts) {
                fprintf(stderr, "Allocation error\n");
                exit(1);
            }
        }
        (*words)[*n]  = strdup(buf);
        (*counts)[*n] = node->count;
        (*n)++;
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            buf[depth] = 'a' + i;
            collect_words(node->children[i], buf, depth + 1,
                          words, counts, n, cap);
        }
    }
}

// Comparator: decreasing occurrences, then alphabetical order.
struct pair { const char *word; int count; };

static int cmp_pair(const void *a, const void *b) {
    const struct pair *pa = a, *pb = b;
    if (pb->count != pa->count) return pb->count - pa->count;
    return strcmp(pa->word, pb->word);
}

void print_words_by_occurrences(Node *root) {
    char buf[1024];
    char **words = NULL;
    int  *counts = NULL;
    int n = 0, cap = 0;

    collect_words(root, buf, 0, &words, &counts, &n, &cap);

    struct pair *pairs = malloc(n * sizeof(struct pair));
    if (!pairs) { fprintf(stderr, "Allocation error\n"); exit(1); }
    for (int i = 0; i < n; i++) {
        pairs[i].word  = words[i];
        pairs[i].count = counts[i];
    }
    qsort(pairs, n, sizeof(struct pair), cmp_pair);

    for (int i = 0; i < n; i++) {
        printf("%6d  %s\n", pairs[i].count, pairs[i].word);
    }

    for (int i = 0; i < n; i++) free(words[i]);
    free(words);
    free(counts);
    free(pairs);
}

// Frees the trie (avoids leaks).
static void free_trie(Node *node) {
    if (!node) return;
    for (int i = 0; i < 26; i++) free_trie(node->children[i]);
    free(node);
}

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
    FILE *f = stdin;
    if (argc > 1) {
        f = fopen(argv[1], "r");
        if (!f) { perror(argv[1]); return 1; }
    }

    char *text = read_all(f);
    if (f != stdin) fclose(f);
    if (!text) { fprintf(stderr, "Read error\n"); return 1; }

    regex_t re;
    if (regcomp(&re, "[[:alnum:]_-]+", REG_EXTENDED) != 0) {
        fprintf(stderr, "Regex error\n");
        free(text);
        return 1;
    }

    Node root = {0};

    regmatch_t m;
    char *p = text;
    while (regexec(&re, p, 1, &m, 0) == 0) {
        size_t wlen = m.rm_eo - m.rm_so;
        char *word = malloc(wlen + 1);
        memcpy(word, p + m.rm_so, wlen);
        word[wlen] = '\0';

        add_word_to_trie(&root, word);

        free(word);
        p += m.rm_eo;
    }

    print_words_by_occurrences(&root);

    // Free children; root lives on the stack.
    for (int i = 0; i < 26; i++) free_trie(root.children[i]);

    regfree(&re);
    free(text);
}