#include <iostream>
#include <vector>
#include <algorithm>
#include <benchmark/benchmark.h>

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

    // print_matrix(mat);

    // step 0-3: row operations on remaining rows.
    for (int i = 0; i < row; i += 1) {
        if (i != piv_row) {
            auto xxx = mat[i][piv_col];
            for (int j = 0; j < col; j += 1) {
                mat[i][j] = mat[i][j] - xxx * mat[piv_row][j];
            }
        }
    }

    // print_matrix(mat);

}

static void bench(benchmark::State &state) {
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
        simplex_iterate(m);
    }

    
}


BENCHMARK(bench);
BENCHMARK_MAIN();