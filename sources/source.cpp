// Copyright 2018 Your Name <your_email>
#include <intrin.h>
#include <chrono>
#include <ctime>
#include <iostream>
#include <map>
#include <random>

#define MULT(x) x x x x x x x x x x

using namespace std;
using namespace chrono;
void straightMethod() {
  map<long, double> straight;
  for (long i = 49152; i < 4194304; i += 160000) {
    straight[i] = 0;
  }
  for (auto& it : straight) {
    int* arr = new int[it.first];
    for (auto i = 0; i < it.first; i += 16) arr[i] = i + 16;
    arr[it.first - 16] = 0;
    int i = 0;

    for (int j = 0; j < 100000000; j++) {
      MULT(i = arr[i];)
    }
    auto start = high_resolution_clock::now();
    for (int j = 0; j < 100000000; j++) {
      MULT(i = arr[i];)
    }
    auto end = high_resolution_clock::now();
    duration<double> sec = !!i * duration_cast<nanoseconds>(end - start);
    double final_avg = sec.count();
    it.second = final_avg;
    cout << it.first / 1024 * 4 << " KB - " << it.second << endl;
  }
  straight.clear();
  cout << "That was results for straight method" << endl;
}
void reverseMethod() {
  map<long, double> straight;
  for (long i = 49152; i < 4194304; i += 160000) {
    straight[i] = 0;
  }
  for (auto& it : straight) {
    int* arr = new int[it.first];
    for (auto i = it.first; i > 0; i -= 16) arr[i] = i - 16;
    arr[0] = it.first - 16;
    int i = 0;

    for (int j = 0; j < 1000000; j++) {
      MULT(i = arr[i];)
    }
    auto start = high_resolution_clock::now();
    for (int j = 0; j < 100000000; j++) {
      MULT(i = arr[i];)
    }
    auto end = high_resolution_clock::now();
    duration<double> sec = !!i * duration_cast<nanoseconds>(end - start);
    double final_avg = sec.count();
    it.second = final_avg;
    cout << it.first / 1024 * 4 << " KB - " << it.second << endl;
  }
  straight.clear();
  cout << "That was results for reverse method" << endl;
}
void randomMethod() {
  map<long, double> straight;
  for (long i = 49152; i < 4194304; i += 160000) {
    straight[i] = 0;
  }

  for (auto& it : straight) {
    int* arr = new int[it.first];
    for (auto i = 0; i < it.first; i += 16) arr[i] = i + 16;
    arr[it.first - 16] = 0;
    for (auto i = 0; i < 100000000; i += 16) {
      int random_number1 = (rand() % (it.first / 16)) * 16;
      int random_number2 = (rand() % (it.first / 16)) * 16;
      if (random_number2 != random_number1)
        swap(arr[random_number1], arr[random_number2]);
    }
    int i = 0;
    for (int j = 0; j < 1000000; j++) {
      MULT(i = arr[i];)
    }
    auto start = high_resolution_clock::now();
    for (int j = 0; j < 100000000; j++) {
      MULT(i = arr[i];)
    }
    auto end = high_resolution_clock::now();
    duration<double> sec = !!i * duration_cast<nanoseconds>(end - start);
    double final_avg = sec.count();
    it.second = final_avg;
    cout << it.first / 1024 * 4 << " KB - " << it.second << endl;
  }
  straight.clear();
  cout << "That was results for random method" << endl;
}

int main() {
  srand(time(nullptr));
  straightMethod();
  reverseMethod();
  randomMethod();
  return 0;
}