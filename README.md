# Arvore Trie 

Trabalho desenvolvido para a disciplina CI1057 ministrada pelo professor Dr. Andrey Pimentel. O objetivo principal desse exercício era implementar a estrutura de dados Trie, cujo objetivo é guardar e realizar operações com palavras.

# Algumas particularidades

A árvore Trie é uma estrutura que utiliza muita memória, já que sempre separa todos os espaços para todas as letras do alfabeto em cada nodo, utilizando esse espaço ou não. Apesar disso, é uma das estruturas mais completas para implementar uma funcionalidade como um corretor ortográfico, pela facilidade de calcular as distâncias entre diversas palavras e, consequentemente, sugerir a palavra esperada durante a digitação.

# Bugs e dificuldades

Mexer com ponteiros nas árvores é sempre algo muito complicado e passível de erros, e como esperado, foi nossa maior dificuldade durante o processo de desenvolvimento. O erro maior que encontramos foi que, durante o percurso do arquivo de entrada, as palavras consultadas acabavam interferindo no dicionário por mal uso das variáveis. Apesar disso, superamos as dificuldades!

# Modo de uso

Para utilizar o programa, basta escrever

make
./dicionario < _arquivo_de_entrada.txt_ > _arquivo_de_saida.txt_

Nossa sugestão de uso:

make
./dicionario < consultas.txt > saida.txt

# Autores

Trabalho de autoria de: André Gustavo Silveira e Henrico
