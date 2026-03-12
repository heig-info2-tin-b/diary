# Semaine 04/16

- [ ] Les fichiers binaires

## fread, fwrite

Lire et d'écrire dans un fichier des données brutes binaires

```c
int data[] = {1, 3, 56, 89, -4};

FILE *fp = fopen("data.bin", "wb");
fwrite(data, sizeof(data[0]), 5, fp);
```