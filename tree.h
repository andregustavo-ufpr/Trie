#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>

typedef struct TrieNode {
    struct TrieNode* children[52];
    int isEndOfWord;
    char* originalWord;
} TrieNode;

// Funções da TRIE
TrieNode* getNode(); //Função para criar um novo nó da TRIE

//Função para calcular o índice do caractere na TRIE, retorna -1 para caractere inválido
int getCharIndex(char c);

//Função para inserir uma palavra na TRIE
void insert(TrieNode* root, const char* str);

//Função para construir a TRIE a partir de um arquivo
void buildTrieFromFile(TrieNode* root, FILE* file);

//Função para calcular a distância de edição entre duas strings
int editDistance(const char *str1, const char *str2);

//Função recursiva para buscar na TRIE
void searchTrieRecursive(TrieNode* node, const char* query, int maxDistance, char* currentWord, int length, char results[][100], char originalResults[][100], int* resultCount);

//Função para buscar palavras na TRIE
void searchTrie(TrieNode* root, const char* query, int maxDistance, char* currentWord, int length, char results[][100], char originalResults[][100], int* resultCount);

void freeTrie(TrieNode* node);

#endif
