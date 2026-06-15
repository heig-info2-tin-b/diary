#include <stdio.h>

int main() {
    FILE *fp;
    
    fp = fopen("filename", "r");
    fclose(fp);
    fprintf(fp, "Prout %d", 42);
    fscanf(fp, "%d %d %c", &a, &b, &c);
    int c = fgetchar(fp);
    
    char buffer[1024];
    fgets(buffer, sizeof(buffer)-1, fp);

    fread(buffer, sizeof(Data), 10, fp);
    fwrite(buffer, sizof(Data), 10, fp);
    fseek(fp, 0, SEEK_END);
    size_t cursor_position = ftell(fp);
    rewind(fp);
}