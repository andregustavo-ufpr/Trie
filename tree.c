#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

#define min(a, b) ((a) < (b) ? (a) : (b))

//Função para criar um novo nó da TRIE
TrieNode* getNode() {
    TrieNode* node = (TrieNode *)malloc(sizeof(TrieNode));

    if (node) {
        // Define todas as folhas como null
        for (int i = 0; i < 52; i++)
            node->children[i] = NULL;
        node->isEndOfWord = 0;
        node->originalWord = NULL;
    }
    
    return node;
}

//Função para calcular o índice do caractere na TRIE, retorna -1 para caractere inválido
int getCharIndex(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 26;
    else
        return -1;
}

//Função para inserir uma palavra na TRIE
void insert(TrieNode* root, const char* str) {
    TrieNode* node = root;
    char* aux = strdup(str);

    while (*str) {
        int index = getCharIndex(*str);

        if (index == -1) {
            str++;
            continue;
        }
        if (!node->children[index])
            node->children[index] = getNode();
        node = node->children[index];
        str++;
    }

    node->isEndOfWord = 1;

    //Armazena a palavra original
    node->originalWord = strdup(aux);
}

//Função para construir a TRIE a partir de um arquivo
void buildTrieFromFile(TrieNode* root, FILE* file) {
    char str[100];
    while (fscanf(file, "%s", str) != EOF)
        insert(root, str);
}

//Função para calcular a distância de edição entre duas strings
int editDistance(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    return dp[len1][len2];
}

//Função recursiva para buscar na TRIE
void searchTrieRecursive(TrieNode* node, const char* query, int maxDistance, char* currentWord, int length, char results[][100], char originalResults[][100], int* resultCount) {
    if (*resultCount >= 20)
        return;

    if (node->isEndOfWord) {
        currentWord[length] = '\0';
        //Limita a distância em 3
        if (editDistance(query, currentWord) <= maxDistance && maxDistance <= 3) {
            strcpy(results[*resultCount], currentWord);
            strcpy(originalResults[*resultCount], node->originalWord); //Armazena a palavra original
            (*resultCount)++;
        }
    }

    for (int i = 0; i < 52; i++) {
        if (node->children[i]) {
            currentWord[length] = (i < 26) ? 'a' + i : 'A' + (i - 26);
            searchTrieRecursive(node->children[i], query, maxDistance, currentWord, length + 1, results, originalResults, resultCount);
        }
    }
}

//Função para buscar palavras na TRIE
void searchTrie(TrieNode* root, const char* query, int maxDistance, char* currentWord, int length, char results[][100], char originalResults[][100], int* resultCount) {
    searchTrieRecursive(root, query, maxDistance, currentWord, length, results, originalResults, resultCount);
}
