#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>
#include <iomanip> 

#include "QuickFind.hpp"
#include "QuickUnion.hpp"
#include "UnionFindOptimized.hpp"

template <typename UF>
void measurePerformance(const std::string& filename, const std::string& algorithmName) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return;
    }

    int n;
    file >> n;

    std::vector<std::pair<int, int>> operations;
    int p, q;
    while (file >> p >> q) {
        operations.push_back({p, q});
    }
    file.close();

    UF uf(n);

    auto start = std::chrono::high_resolution_clock::now();

    for (const auto& op : operations) {
        uf.union_sets(op.first, op.second);
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> tempo = end - start;

    std::cout << std::left << std::setw(15) << algorithmName 
              << " | " << std::setw(15) << filename 
              << " | Tempo: " << tempo.count() << " ms" << std::endl;
}

int main() {
    // Casos de teste extraidos em: https://algs4.cs.princeton.edu/15uf/
    std::vector<std::string> files = {
        "samples/tinyUF.txt", 
        "samples/mediumUF.txt", 
        "samples/largeUF.txt"
    };

    std::cout << "Iniciando bateria de testes...\n\n";

    for (const auto& file : files) {
        measurePerformance<QuickFind>(file, "Quick-Find");
        measurePerformance<QuickUnion>(file, "Quick-Union");
        measurePerformance<UnionFindOptimized>(file, "Union-Find Otimizada");
        
        std::cout << "\n";
    }

    std::cout << "Testes finalizados!" << std::endl;

    return 0;
}