#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include <map>
#include <tuple>
#include <filesystem>
#include <chrono>
#include <functional>
#include <thread>
#include <iostream>

#if defined(_WIN64)
#if defined(COOL_LIB_EXPORTS)
  #define EXPORT __declspec(dllexport)
#else
  #define EXPORT __declspec(dllimport)
#endif
#elif defined(__linux__) || defined(__APPLE__)
#define EXPORT __attribute__((visibility("default")))
#else
#define EXPORT
#endif

namespace cool_library {
  int EXPORT whatsup(int n);
}