#include <iostream>
#include <vector>
#include <algorithm>
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

    // // step 0-2: div piv row by piv item:
    // for (int i = 0; i < col; i += 1) {
    //     mat[piv_row][i] = mat[piv_row][i] / piv_elem;
    // }

    // // step 0-3: row operations on remaining rows.
    // for (int i = 0; i < row; i += 1) {
    //     if (i != piv_row) {
    //         auto xxx = mat[i][piv_col];
    //         for (int j = 0; j < col; j += 1) {
    //             mat[i][j] = mat[i][j] - xxx * mat[piv_row][j];
    //         }
    //     }
    // }

    #ifndef BENCH
        print_matrix(mat);
    #endif 
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
