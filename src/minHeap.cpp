#include "minHeap.hpp"

// Construtor da classe Min Heap
minHeap::minHeap(int tamanho) {
    heap = new Aresta[tamanho];
    heapSize = 0;
    arraySize = tamanho;
}

// Destrutor da classe Min Heap
minHeap::~minHeap() {
    delete[] heap;
}

// Função para obter o índice do filho esquerdo de um nó
int minHeap::getEsqFilho(int indice) {
    return 2 * indice + 1;
}

// Função para obter o índice do filho direito de um nó
int minHeap::getDirFilho(int indice) {
    return 2 * indice + 2;
}

// Função para obter o índice do pai de um nó
int minHeap::getParent(int indice) {
    return (indice - 1) / 2;
}

// Função para trocar dois elementos na Min Heap
void minHeap::trocar(int i, int j) {
    Aresta aux = heap[i];
    heap[i] = heap[j];
    heap[j] = aux;
}

// Função para verificar se o filho direito de um nó existe
bool minHeap::existeDir(int indice) {
    return getDirFilho(indice) < heapSize;
}

// Função para verificar se o filho esquerdo de um nó existe
bool minHeap::existeEsq(int indice) {
    return getEsqFilho(indice) < heapSize;
}

// Função para inserir um novo elemento na Min Heap
void minHeap::inserir(int ver1, int ver2, int custo) {
    Aresta elemento;
    elemento.u = ver1;
    elemento.v = ver2;
    elemento.custo = custo;

    if (heapSize == arraySize) {
        return; // A Min Heap está cheia, não é possível inserir mais elementos.
    } else {
        heapSize++;
        heap[heapSize - 1] = elemento;
        heapfy(heapSize - 1); // Reorganiza a Min Heap após a inserção.
    }
}

// Função para reorganizar a Min Heap após a inserção de um novo elemento
void minHeap::heapfy(int indice) {
    if (indice != 0) {
        int parente = getParent(indice);
        if (heap[parente].custo > heap[indice].custo) {
            trocar(parente, indice);
            heapfy(parente); // Reorganiza recursivamente até que a min Heap esteja certa.
        }
    }
}
