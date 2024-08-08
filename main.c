#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tree.h"

//Função para processar as consultas
void processQueries(TrieNode* root, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Não foi possível abrir o arquivo %s\n", filename);
        return;
    }

    char query[100];
    int maxDistance;
    while (fscanf(file, "%s %d", query, &maxDistance) != EOF) {
        char results[20][100];
        char originalResults[20][100];
        char currentWord[100] = "";
        int resultCount = 0;

        searchTrie(root, query, maxDistance, currentWord, 0, results, originalResults, &resultCount);

        printf("%s:", query);
        for (int i = 0; i < resultCount; i++) {
            printf("%s%s", originalResults[i], (i == resultCount - 1) ? "\n" : ", ");
        }
    }
    fclose(file);
}

int main() {
    //Para lidar com caracteres especiais
    setlocale(LC_ALL, "");

    //Cria um nodo novo
    TrieNode* root = getNode();

    //Construir a TRIE a partir do arquivo de palavras
    buildTrieFromFile(root, stdin);

    // Processar as consultas
    processQueries(root, "consultas.txt");

    return 0;
}
