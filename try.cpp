#include <iostream>
#include <vector>
#include <chrono>
#include <random>
using namespace std;
using namespace chrono;

int main() {
    int size = 1000; // 🧠 Change to 3 to print matrix, or 1500+ to stress more

    vector<vector<int>> A(size, vector<int>(size));
    vector<vector<int>> B(size, vector<int>(size));
    vector<vector<long long>> C(size, vector<long long>(size, 0));

    // Random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);

    // Initialize matrices
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            A[i][j] = dis(gen);
            B[i][j] = dis(gen);
        }

    auto start = high_resolution_clock::now();

    // Matrix multiplication
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            for (int k = 0; k < size; k++)
                C[i][j] += (long long)A[i][k] * B[k][j];

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "✅ Matrix multiplication completed.\n";
    cout << "⏱️ Time taken: " << duration.count() << " ms\n";

    // Optional: print small matrix
    if (size <= 5) {
        cout << "Resultant Matrix C:\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                cout << C[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
