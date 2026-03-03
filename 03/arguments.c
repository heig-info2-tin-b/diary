#include <stdio.h>
#include <stdbool.h>

typedef struct options {
    int verbose; // -v1, -v2, -v3
    int count; // -c10
    bool happy; // -h
    char *filename; // filename.txt
} Options;

#if 0
bool parse_options(int argc, char *argv[], Options *options) {
    options->verbose = 0;
    return false;
}
#endif 

Options parse_options(int argc, char *argv[]) {
    Options options = {0, 0, false, NULL};

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            switch (argv[i][1]) {
                case 'v':
                    options.verbose = argv[i][2] - '0'; // Convert char to int
                    break;
                case 'c':
                    options.count = atoi(&argv[i][2]); // Convert string to int
                    break;
                case 'h':
                    options.happy = true;
                    break;
            }
        } else {
            options.filename = argv[i];
        }
    }

    return options;
}


int main(int argc, char *argv[]) {
    Options options = parse_options(argc, argv);

    if (options.happy) {
        printf("I'm happy!\n");
    }
}