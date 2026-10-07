#include <iostream>
#include <pthread.h>
#include <fstream>
using namespace std;

void* hitungFaktorial(void* arg) {
    int n = *(int*)arg;
    int hasil = 1;
    
    for (int i = 1; i <= n; i++) {
        hasil *= i;
    }
    cout << "\nThread 1 : Faktorial = " << n << "! = " << hasil << endl;
    
    return nullptr;
}

void* fibonacci(void* arg) {
    int n = *(int*)arg;
    int a = 0;
    int b = 1;
    int c;

    cout << "\nThread 2 : Fibonacci = \n";

    for (int i = 0; i < n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;

    return nullptr;
}

void* pembacaFile(void* arg) {
    cout << "\nThread 3 : Membaca file ... \n";

    ifstream file("data.txt");
    string isiFile;

    while (getline(file, isiFile)) {
        cout << isiFile << endl;
    }

    return nullptr;
}

int main () {
    pthread_t thread1, thread2, thread3;

    int faktorial;
    int jumlahFibonacci;

    cout << "Masukkan angka Faktorial: ";
    cin >> faktorial;

    cout << "Masukkan jumlah Fibonacci: ";
    cin >> jumlahFibonacci;

    pthread_create(
        &thread1,
        nullptr,
        hitungFaktorial,
        &faktorial
    );

   pthread_create(
        &thread2,
        nullptr,
        fibonacci,
        &jumlahFibonacci
    );

   pthread_create(
        &thread3,
        nullptr,
        pembacaFile,
        nullptr
    );

    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);
    pthread_join(thread3, nullptr);

    cout << "\nSemua Thread sudah selesai" << endl;

    return 0;
}