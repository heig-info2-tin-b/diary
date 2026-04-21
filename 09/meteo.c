
/**
flux de données --(stdin)--> programme --> csv

temperature, 1byte, 0.25°C/LSB
humidité, 1byte, 0..100LSB -> 0..100%

cat data.bin | ./program data.csv
*/
#include <stdio.h>
#include <stdlib.h>

int insert_record(FILE* data_input, char *output_filename) {
    if (data_input == NULL) return 1; // discutable pour des raisons de perfs.
    int temp_raw = fgetc(data_input);
    int humidity = fgetc(data_input);

    #if 0
    struct data {
        char temperature;
        char humidity;
    } data;
    if (fread(&data, sizeof(char), 2, data_input) != 2) return 6;
    #endif
    
    if (temp_raw == -1 || humidity == -1) return 3;
    
    char buffer[17] = {0};
    get_timestamp(buffer);
    
    FILE *data_out = fopen(output_filename, "a");
    if (data_out == NULL) return 2;
    fprintf("\"%s\"; \"%.2f°C\"; \"%d%%\"", buffer, temp_raw / 4., humidity);
    fclose(data_out);
}