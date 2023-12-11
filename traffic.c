#include <stdio.h>
#include <stdlib.h>

#define EMPTY ' '
#define TRAFFIC_PATH '.'
#define CAR '>'
#define PLAYER 'P'
#define GOAL 'G'

void drawMap(char** map, int rows, int cols) {
    // Print top border
    for (int i = 0; i < cols + 2; i++) {
        printf("* ");
    }
    printf("\n");

    // Print map content
    for (int i = 0; i < rows; i++) {
        printf("* ");
        for (int j = 0; j < cols; j++) {
            char symbol;
            switch (map[i][j]) {
                case '0':
                    symbol = EMPTY;
                    break;
                case '1':
                    symbol = TRAFFIC_PATH;
                    break;
                case '2':
                    symbol = CAR;
                    break;
                case '3':
                    symbol = PLAYER;
                    break;
                case '4':
                    symbol = GOAL;
                    break;
                default:
                    symbol = '?';
                    break;
            }
            printf("%c ", symbol);
        }
        printf("*\n");
    }

    // Print bottom border
    for (int i = 0; i < cols + 2; i++) {
        printf("* ");
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./traffic <map_file_name>\n");
        return 0;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    char line[1000];
    if (fgets(line, sizeof(line), file) == NULL) {
        printf("Invalid map size in the file.\n");
        fclose(file);
        return 0;
    }

    int rows, cols;
    if (sscanf(line, "%d %d", &rows, &cols) != 2) {
        printf("Invalid map size in the file.\n");
        fclose(file);
        return 0;
    }

    char** map = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        map[i] = (char*)malloc(cols * sizeof(char));
        if (fgets(line, sizeof(line), file) == NULL) {
            printf("Invalid map data in the file.\n");
            fclose(file);
            return 0;
        }
        for (int j = 0; j < cols; j++) {
            if (line[j] == '\n') {
                printf("Invalid map data in the file.\n");
                fclose(file);
                return 0;
            }
            map[i][j] = line[j];
        }
    }

    fclose(file);

    drawMap(map, rows, cols);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}