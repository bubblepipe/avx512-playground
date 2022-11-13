#include <iostream>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>
#include <stdlib.h>

void print_matrix(std::vector<std::vector<float>> mat ){
    int row = mat.size();
    int col = mat[0].size();

    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void simplex_iterate(std::vector<std::vector<float>> & mat) {

    int row = mat.size();
    int col = mat[0].size();

    // Step 0-1: Picking the Pivot Elem
    auto x = mat[row - 1];
    auto piv_col_it = std::min_element(std::begin(mat[row - 1]), std::end(mat[row - 1]));
    int piv_col = std::distance(std::begin(mat[row - 1]), piv_col_it);

    std::vector<float> ratios(row - 1);
    for (int i = 0; i < row - 1; i += 1) {
        ratios[i] = mat[i][col - 1] / mat[i][piv_col];
    }
    auto piv_row_it = std::min_element(std::begin(ratios), std::end(ratios));
    int piv_row = std::distance(std::begin(ratios), piv_row_it);

    auto piv_elem = mat[piv_row][piv_col];
    // std::cout << piv_elem << std::endl << std::endl;

    // step 0-2: div piv row by piv item:
    for (int i = 0; i < col; i += 1) {
        mat[piv_row][i] = mat[piv_row][i] / piv_elem;
    }

    // step 0-3: row operations on remaining rows.
    for (int i = 0; i < row; i += 1) {
        if (i != piv_row) {
            auto xxx = mat[i][piv_col];
            for (int j = 0; j < col; j += 1) {
                mat[i][j] = mat[i][j] - xxx * mat[piv_row][j];
            }
        }
    }

    #ifndef BENCH
        print_matrix(mat);
    #endif 
}

static void bench_4_7(benchmark::State &state) {
    int row = 4;
    int col = 7;
    
    float mat_ref[4][7] =
    {
        {1 , 2 , 1 , 0 , 0 , 0 , 16},
        {1 , 1 , 0 , 1 , 0 , 0 ,  9},
        {3 , 2 , 0 , 0 , 1 , 0 , 24},
        {-40,-30,0 , 0 , 0 , 1 ,  0},
    };
    
    for (auto _ : state) {
        std::vector<std::vector<float>> m;
        m.resize(row, std::vector<float>(col, 0));
    
        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                m[i][j] = mat_ref[i][j];
            }
        }

        simplex_iterate(m);
        print_matrix(m);
        simplex_iterate(m);
        print_matrix(m);
        exit(0);

    }
}

static void bench_2(benchmark::State &state) {
    int row = 6;
    int col = 8;
    
    // maximize 12 x + 8 y 
    // subject to:
    // x + y < 80
    // 2 x + 3 y < 60
    // x + 3 y < 44
    // 2 x + 5 y < 55
    // 7 x + 3 y < 60
    float mat_ref[6][8] =
    {
        //   x1  x2  x3  x4  x5  x6  x7  
        {1 , 2 , 1 , 0 , 0 , 0 , 0 , 80},
        {2 , 3 , 0 , 1 , 0 , 0 , 0 , 60},
        {1 , 3 , 0 , 0 , 1 , 0 , 0 , 44},
        {2 , 5 , 0 , 0 , 0 , 1 , 0 , 55},
        {7 , 3 , 0 , 0 , 0 , 0 , 1 , 60},
        {-40,-30,0 , 0 , 0 , 0 , 0 , 0},
    };
    
    for (auto _ : state) {
        std::vector<std::vector<float>> m;
        m.resize(row, std::vector<float>(col, 0));
    
        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                m[i][j] = mat_ref[i][j];
            }
        }

        simplex_iterate(m);
        simplex_iterate(m);
    }
}

std::vector<std::vector<float>> generate_random_matrix(int variable_count, int constraints_count) {
    int row = constraints_count + 1;
    int col = variable_count + constraints_count + 2;
    std::vector<std::vector<float>> m;
    m.resize(row, std::vector<float>(col, 0));
    
    srand(114514);

    // fill random number
    for (int i = 0; i < constraints_count; i += 1){
        for (int j = 0; j < variable_count; j += 1){
            m[i][j] = rand() % 100;
        }
    }

    // fill 1 
    for (int i = 0; i < row; i += 1){
        m[i][i + variable_count] = 1;
    }

    // fill rhs
    for (int i = 0; i < row; i += 1){
        m[i][col - 1] = rand() % 100;
    }

    // fill bottom row
    for (int i = 0; i < variable_count; i += 1){
        m[row-1][i] = -1 * (rand() % 100);
    }

    return m;
}

// int main(){
//     auto m = generate_random_matrix(4,4);
//     print_matrix(m);
//     simplex_iterate(m); print_matrix(m);
//     simplex_iterate(m); print_matrix(m);
//     simplex_iterate(m); print_matrix(m);
//     simplex_iterate(m); print_matrix(m);

// }

void bench_4(benchmark::State &state) {

    int variable_count = 32;
    int constraints_count = 32;
    auto mat_ref= generate_random_matrix(variable_count, constraints_count);
    int row = mat_ref.size();
    int col = mat_ref[0].size();
    
    exit(0);
    for (auto _ : state) {
        std::vector<std::vector<float>> m;
        m.resize(row, std::vector<float>(col, 0));
    
        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                m[i][j] = mat_ref[i][j];
            }
        }

        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        // exit(0);
    }
}


static void bench_3(benchmark::State &state) {
    int row = 8;
    int col = 13;
        // maximize x1 + 2x2 + 3x3 + 4x4 
    // subject to 
    // 2 x1 + 3 x2 + 4 x3 + 5 x4 < 1000
    // 7 x1 + 2 x4 < 8000
    // 3 x1 + 1 x4 < 800
    // 11 x2 + 12x3 < 7777

    float mat_ref[8][13] =
    {
        //x1 x2  x3  x4  s1  s2  s3  s4  s5  s6  s7  P   rhs
        {2 , 3 , 4 , 5 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 8000},
        {7 , 2 , 3 , 4 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 6000},
        {3 , 1 , 2 , 2 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 0 , 4400},
        {11, 12, 13, 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 0 , 78600},
        {13, 14, 15, 16, 0 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 81000},
        {21, 22, 23, 24, 0 , 0 , 0 , 0 , 0 , 1 , 0 , 0 , 19190},
        {81, 9 , 3 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0 , 114514},
        {-40,-30,-10,-8, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 , 0},
    };
    
    for (auto _ : state) {
        std::vector<std::vector<float>> m;
        m.resize(row, std::vector<float>(col, 0));
    
        for (int i = 0; i < row; i += 1) {
            for (int j = 0; j < col; j += 1) {
                m[i][j] = mat_ref[i][j];
            }
        }

        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        simplex_iterate(m); // print_matrix(m);
        // exit(0);
    }
}


BENCHMARK(bench_4);
BENCHMARK_MAIN();