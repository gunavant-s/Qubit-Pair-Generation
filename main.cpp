#include <iostream>
#include <iomanip>
#include <bitset>

void printBinary(int num, int bits) {
    std::bitset<16> b(num); //only 16 bits kind of hardcoded
    std::cout << b.to_string().substr(16-bits) << " (" << num << ")";
}

int main() {
    int N, t;  // N-qubit system
    
    // Input validation for N
    do {
        std::cout << "Enter number of qubits (N > 0): ";
        std::cin >> N;
        if (N <= 0) {
            std::cout << "N must be positive!\n";
        }
    } while (N <= 0);
    
    // Input validation for t
    do {
        std::cout << "Enter target qubit (0 to " << N-1 << "): ";
        std::cin >> t;
        if (t < 0 || t >= N) {
            std::cout << "Target qubit must be between 0 and " << N-1 << "!\n";
        }
    } while (t < 0 || t >= N);
    
    int pairs = 1 << (N-1);  // number of pairs to process
    
    std::cout << "\nN = " << N << " qubits, target = " << t << "\n";
    std::cout << "Number of pairs: " << pairs << "\n\n";
    
    for(int idx = 0; idx < pairs; idx++) {
        int mask = 1 << t;
        int base = (idx & ~((1 << t) - 1)) << 1 | (idx & ((1 << t) - 1));
        int i0 = base;
        int i1 = base | mask;
        
        std::cout << "Pair " << std::setw(2) << idx << ": ";
        printBinary(i0, N);
        std::cout << " and ";
        printBinary(i1, N);
        std::cout << "\n";
    }
    
    return 0;
}
