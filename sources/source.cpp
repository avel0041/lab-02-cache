#include <intrin.h>

#include <chrono>
#include <ctime>
#include <header.hpp>
#include <iostream>
#include <map>
#include <random>

//#define MULT(x) x x
#define MULT(x) x x x x x x x x x x

int main() {
  srand(time(0));
  std::map<unsigned int, double> straight;
  // straight[49152] = 0;//49152, 262144, 524288, 1048576, 2097152, 4194304
  // straight[262144] = 0;
  // straight[524288] = 0;
  // straight[1048576] = 0;
  // straight[2097152] = 0;
  // straight[4194304] = 0;
  for (unsigned int i = 49152; i < 4194304; i += 100000) {
    straight[i] = 0;
  }
  for (auto& it : straight) {
    int* arr = new int[it.first];
    for (auto i = 0; i < it.first; i += 16) arr[i] = i + 16;

    arr[it.first - 16] = 0;
    // double all_time = 0;
    int i = 0;


    for (int j = 0; j < 100; j++) {
      MULT(MULT(MULT(MULT(i = arr[i];))))
    }

    auto start = std::chrono::high_resolution_clock::now();
    // auto ticks_start = __rdtsc();

    for (int j = 0; j < 10000; j++) {
      MULT(MULT(MULT(MULT(i = arr[i];))))
    }
    // auto ticks_end = __rdtsc();
    // const double cycles = (ticks_end - ticks_start) * 16. / (1000 *
    // it.first); std::cout << cycles << " - ";
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sec = 
        !!i * std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    double final_avg = sec.count();
    /// 1000;  //(10000. * 10000);
    // t(доступа к 1 элементу) = t(доступа ко всем элементам)/
    //(1000(кол-во итераций)*(кол-во элем.)/16(т.к. обращаемся к каждом 16-му)
    it.second = final_avg;
    std::cout << it.first / 1024 * 4 << " KB - " << it.second << std::endl;
  }
  straight.clear();
  std::cout << "That was results for straight method" << std::endl;
  // for (auto & it : straight) {
  //  std::cout << it.first/1024*4 << " KB - " << it.second << std::endl;
  //}

  std::map<unsigned int, double> reverse;
  reverse[49152] = 0;  // 49152, 262144, 524288, 1048576, 2097152, 4194304
  // reverse[262144] = 0;
  // reverse[524288] = 0;
  // reverse[1048576] = 0;
  // reverse[2097152] = 0;
  // reverse[4194304] = 0;
  for (unsigned int i = 0; i < 4194304; i += 100000){
    reverse[i] = 0;
  }
  for (auto& it : reverse) {
    int k = 0;
    int* arr = new int[it.first];
    for (unsigned int i = it.first; i > 0; i -= 16) {
      arr[i] = rand() % 10000;
    }
    for (unsigned int i = it.first; i > 0; i -= 16) {
      k = arr[i];
    }
    double all_time = 0;
    for (int j = 0; j < 1000; j++) {
      auto start = std::chrono::high_resolution_clock::now();
      for (unsigned int i = it.first; i > 0; i -= 16) {
        k = arr[i];
      }
      auto end = std::chrono::high_resolution_clock::now();
      std::chrono::duration<double> sec =
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
      double reading_1_elem_avg =
          sec.count() / it.first;  //среднее значение чтения 1 элемента
      all_time = reading_1_elem_avg +
                 all_time;  //сумма всех средних значений за 100 экспериментов
    }
    double final_avg = all_time / 1000;
    //std::cout << k << std::endl;
    it.second = final_avg;
  }
  std::cout << "Results for reverse method:" << std::endl;
  for (auto& it : reverse) {
    std::cout << it.first / 1024 * 4 << " KB - " << it.second << std::endl;
  }


    std::map <unsigned int, double> random;
    random[49152] = 0;//49152, 262144, 524288, 1048576, 2097152, 4194304
    random[262144] = 0;
    random[524288] = 0;
    random[1048576] = 0;
    random[2097152] = 0;
    random[4194304] = 0;
    for (auto & it : random) {
      int k = 0;
      int* arr = new int[it.first];
      for (unsigned int i = 0; i < it.first; i += 16) {
        arr[i] = rand() % 10000;
      }
      for (unsigned int i = 0; i < it.first; i += 16) {
        k = arr[i];
      }
      double all_time = 0;
      for (int j = 0; j < 1000; j++) {
        auto start = std::chrono::high_resolution_clock::now();
        for (unsigned int i = 1; i < it.first; i += 16) {
          k = arr[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sec =
            std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        unsigned int a = it.first;
        auto b = (double) a;
        double reading_1_elem_avg =
            sec.count() / b;  //среднее значение чтения 1 элемента
        all_time = reading_1_elem_avg +
                   all_time;  //сумма всех средних значений за 100 экспериментов
      }
      double final_avg = all_time / 1000;
      //std::cout << k << std::endl;
      it.second = final_avg;
    }
    std::cout << "Results for random method:" << std::endl;
    for (auto & it : random) {
      std::cout << it.first/1024*4 << " KB - " << it.second << std::endl;
    }
  return 0;
}