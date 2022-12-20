#include <array>
#include <chrono>
#include <cstdlib>
#include <experimental/simd>
#include <iostream>
#include <random>

using std::experimental::native_simd;
using Vec3D_v = std::array<native_simd<float>, 3>;
native_simd<float> scalar_product(const Vec3D_v& a, const Vec3D_v& b) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
using Vec3D = std::array<float, 3>;
float scalar_product(const std::array<float, 3>& a, const std::array<float, 3>& b) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

int main(){
  constexpr std::size_t VECREG_SIZE = native_simd<float>::size();
  std::array<Vec3D, VECREG_SIZE * 1000> arr;
  std::array<Vec3D_v, VECREG_SIZE * 1000> arr_v;
  std::random_device rd;
  std::mt19937 generator(rd());
  std::uniform_real_distribution<float> distribution(0.f, 1.f);
  for( std::size_t i = 0; i < arr.size(); ++i ){
    arr[i] = {distribution(generator), distribution(generator), distribution(generator)};
    arr_v[i] = {distribution(generator), distribution(generator), distribution(generator)};
  }
  float result = 0.f;
  auto start = std::chrono::high_resolution_clock::now();
  for( std::size_t i = 1; i < arr.size(); ++i ){
    result += scalar_product(arr_v[i-1], arr_v[i])[0];
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = end - start;
  std::cout << "VC: " << elapsed.count() << '\n' << std::endl;

  result = 0;
  start = std::chrono::high_resolution_clock::now();
  for( std::size_t i = 1; i < arr.size(); ++i ){
    result += scalar_product(arr[i-1], arr[i]);
  }
  end = std::chrono::high_resolution_clock::now();
  elapsed = end - start;
  std::cout << "notVC: " << elapsed.count() << '\n';
  return EXIT_SUCCESS;
}