#include "unionFind.hpp"

// Construtor da classe Union-Find
UnionFind::UnionFind(int quant) {
    tamanho = quant;
    subconjuntos = new Subconjunto[quant];
    for (int i = 0; i < quant; i++) {
        Make(i); // Inicializa cada elemento como seu próprio conjunto.
    }
}

// Destrutor da classe Union-Find
UnionFind::~UnionFind() {
    delete[] subconjuntos;
}

// Função para criar um novo subconjunto com o elemento x.
void UnionFind::Make(int x) {
    if (x >= 0 && x < tamanho) {
        subconjuntos[x].representante = x;
        subconjuntos[x].rank = 0; // Inicializa o rank como 0.
    }
}

// Função para encontrar o representante do subconjunto que contém o elemento x.
int UnionFind::Find(int x) {
    if (x < 0 || x >= tamanho) {
        return -1; // Valor inválido, retorne -1 para indicar erro.
    }

    if (subconjuntos[x].representante != x) {
        subconjuntos[x].representante = Find(subconjuntos[x].representante);
    }
    return subconjuntos[x].representante;
}

// Função para unir dois subconjuntos, identificados pelos elementos x e y.
void UnionFind::Union(int x, int y) {
    int representanteX = Find(x);
    int representanteY = Find(y);

    if (representanteX == representanteY) {
        return; // Os elementos x e y já pertencem ao mesmo conjunto.
    }

    // Realize a união com base no rank para manter a árvore mais baixa.
    if (subconjuntos[representanteX].rank < subconjuntos[representanteY].rank) {
        subconjuntos[representanteX].representante = representanteY;
    } else if (subconjuntos[representanteX].rank > subconjuntos[representanteY].rank) {
        subconjuntos[representanteY].representante = representanteX;
    } else {
        subconjuntos[representanteY].representante = representanteX;
        subconjuntos[representanteX].rank++;
    }
}
