#include <stdio.h>
#include <string.h>

void help(FILE *fp) {
    fprintf(fp, "HELP\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        help(stdout);
        return 0;
    }
};