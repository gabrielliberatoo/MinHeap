#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include "unionFind.hpp"

class minHeap {
public:
    // Construtor da classe Min Heap.
    minHeap(int tamanho);

    // Destrutor da classe Min Heap.
    ~minHeap();

    // Função para inserir um novo nó na Min Heap.
    void inserir(int ver1, int ver2, int custo);

    // Função para reorganizar a Min Heap após uma inserção.
    void heapfy(int indice);

    // Função para obter um nó da Min Heap com base em um índice.
    Aresta getCell(int indice) const {
        return heap[indice];
    }

private:
    Aresta* heap;        // Array para armazenar os nós da Min Heap.
    int heapSize;        // Tamanho atual da Min Heap.
    int arraySize;       // Tamanho total do array.
    
    // Funções auxiliares para calcular índices dos filhos e pai de um nó.
    int getEsqFilho(int indice);
    int getDirFilho(int indice);
    int getParent(int indice);

    // Função para trocar dois nós na Min Heap durante a reorganização.
    void trocar(int i, int j);

    // Funções para verificar a existência dos filhos esquerdo e direito de um nó.
    bool existeDir(int indice);
    bool existeEsq(int indice);
};

#endif
