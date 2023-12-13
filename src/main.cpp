#include "unionFind.hpp"
#include "minHeap.hpp"
#include <iostream>

//valor máximo para o custo das arestas
const int MAX_COST = 1e9;

int main() {
    int quantVert;    // Número de vértices no grafo
    int quantAres;    // Número de arestas no grafo

    std::cin >> quantVert >> quantAres; // Leitura do número de vértices e arestas a partir da entrada padrão

    minHeap arestas(quantAres); // Cria uma Min Heap para armazenar as arestas do grafo

    for (int i = 0; i < quantAres; i++) {
        int u, v, c;
        std::cin >> u >> v >> c; // Leitura das informações de cada aresta (vértices e custo)
        arestas.inserir(u, v, c); // Inserção da aresta na Min Heap
    }

    UnionFind operacao(quantVert); // Cria uma estrutura Union-Find para realizar as operações 

    int custo = 0; // Inicializando o custo como 0.
    int cont = 0;  // Inicializando o contador de arestas como 0.

    while (cont < quantVert - 1) {
        int menorCusto = MAX_COST;
        int menorIndice = -1;

        for (int i = 0; i < quantAres; i++) {
            Aresta aux = arestas.getCell(i);
            int ver1 = aux.u;
            int ver2 = aux.v;

            // Verifique se adicionar a aresta a arvore geradora não forma ciclos
            if (operacao.Find(ver1) != operacao.Find(ver2) && aux.custo < menorCusto) {
                menorCusto = aux.custo;
                menorIndice = i;
            }
        }

        if (menorIndice != -1) {
            Aresta aux = arestas.getCell(menorIndice);
            int ver1 = aux.u;
            int ver2 = aux.v;
            operacao.Union(ver1, ver2); // Une os conjuntos contendo o vertice1 e vertice2
            custo += aux.custo; // Adiciona o custo da aresta à soma total da arvore geradora
            cont++;
        }
    }

    std::cout << custo << std::endl; // Imprima o custo total da arvore geradora

    return 0;
}
