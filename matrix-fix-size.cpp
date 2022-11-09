#include <iostream>
#include <vector>
#include <algorithm>

# define row 4
# define col 7
void print_matrix(float arr[row][col] ){
    
    for (int i = 0; i < row; i += 1) {
        for (int j = 0; j < col; j += 1) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


int main()
{
    float arr[row][col] =
    {
        {1 , 2 , 1 , 0 , 0 , 0 , 16},
        {1 , 1 , 0 , 1 , 0 , 0 ,  9},
        {3 , 2 , 0 , 0 , 1 , 0 , 24},
        {-40,-30,0 , 0 , 0 , 1 ,  0},
    };

    // Step 0-1: Picking the Pivot Elem
    auto piv_col_it = std::min_element(std::begin(arr[row-1]), std::end(arr[row-1]));
    int piv_col = std::distance(std::begin(arr[row-1]), piv_col_it);

    std::vector<float> ratios(row - 1);
    for (int i = 0; i < row-1; i += 1) {
        ratios[i] = arr[i][col-1] / arr[i][piv_col];
    }
    auto piv_row_it = std::min_element(std::begin(ratios), std::end(ratios));
    int piv_row = std::distance(std::begin(ratios), piv_row_it);

    auto piv_elem = arr[piv_row][piv_col];
    std::cout << piv_elem << std::endl << std::endl;


    // step 0-2: div piv row by piv item:
    for (int i = 0; i < col; i += 1) {
        arr[piv_row][i] = arr[piv_row][i] / piv_elem;
    }

    print_matrix(arr);

    // step 0-3: row operations on remaining rows. 
    for (int i = 0; i < row; i += 1) {
        if (i != piv_row){
            auto xxx = arr[i][piv_col];
            for (int j = 0; j < col; j += 1) {
                arr[i][j] = arr[i][j] - xxx * arr[piv_row][j];
            }
        }
    }
    
    print_matrix(arr);

    // step 1-1: pick piv elem
    piv_col_it = std::min_element(std::begin(arr[row-1]), std::end(arr[row-1]));
    piv_col = std::distance(std::begin(arr[row-1]), piv_col_it);

    for (int i = 0; i < row-1; i += 1) {
        ratios[i] = arr[i][col-1] / arr[i][piv_col];
    }
    piv_row_it = std::min_element(std::begin(ratios), std::end(ratios));
    piv_row = std::distance(std::begin(ratios), piv_row_it);


    piv_elem = arr[piv_row][piv_col];
    std::cout << piv_elem << std::endl << std::endl;


    // step 1-2: div piv row by piv item:
    for (int i = 0; i < col; i += 1) {
        arr[piv_row][i] = arr[piv_row][i] / piv_elem;
    }

    print_matrix(arr);

    // step 1-3: row operations on remaining rows. 
    for (int i = 0; i < row; i += 1) {
        if (i != piv_row){
            auto xxx = arr[i][piv_col];
            for (int j = 0; j < col; j += 1) {
                arr[i][j] = arr[i][j] - xxx * arr[piv_row][j];
            }
        }
    }
    
    print_matrix(arr);

    exit(0);
    

}