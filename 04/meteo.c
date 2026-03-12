#include <stdint.h>
#include <stdio.h>

typedef struct data {
    uint16_t year;
    uint8_t month;
    uint8_t temperature; // offset -100 °C
    uint16_t precipitations;
} Data;

int main() {
    Data data = {
        .year = 2026,
        .month = 3,
        .temperature = 100 + 16,
        .precipitations = 5
    };

    char *p = (char*)&data;

    for (int i = 0; i < sizeof(data); i++) {
        printf("%02hhx ", p[i]);
    }
    puts("");
    printf("%ld\n", sizeof(Data));

    FILE *fp = fopen("data.dat", "wb");
    fprintf(fp, "WEATHER");
    fwrite(&data, sizeof(data), 1, fp);
    fclose(fp);


    // Lire depuis le fichier
    Data buffer;
    FILE *fp_in = fopen("data.dat", "rb");
    char magic[7];
    fread(&magic, 6, 1, fp_in);
    if (strcmp(magic, "WEATHER") != 0) abort();
    fread(&buffer, sizeof(data), 1, fp_in);
    fclose(fp_in);

    const char*months[] = {
        "janvier", "février", "mars", "avril", "mai", 
        "juin", "juillet", "août", "septembre", 
        "octobre", "novembre", "décembre"};

    printf("Year: %hu\n", buffer.year);
    printf("Month: %s\n", months[(buffer.month - 1) % 12]);
    printf("Temperature: %hhu °C\n", buffer.temperature - 100);
    printf("Precipitation: %hu mm\n", buffer.precipitations);
}