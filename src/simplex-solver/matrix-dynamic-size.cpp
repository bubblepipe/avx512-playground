#include <benchmark/benchmark.h>
#include <matrix-dynamic-size.h>
// #include <"src/matrix-dynamic-size.h">

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
        simplex_iterate(m);

    }
}

static void bench_6_8(benchmark::State &state) {
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
        simplex_iterate(m);
        simplex_iterate(m);
    }
}

// int main(){
//     auto m = generate_random_matrix(4,4);
//     print_matrix(m);
//     simplex_iterate(m); print_matrix(m);
//     simplex_iterate(m); print_matrix(m);
//     simplex_iterate(m); print_matrix(m);
//     simplex_iterate(m); print_matrix(m);

// }

static void bench_8_13(benchmark::State &state) {
    int row = 8;
    int col = 13;

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


void bench_x(benchmark::State &state) {

    int variable_count = 32;
    int constraints_count = variable_count;
    auto mat_ref= generate_random_matrix(variable_count, constraints_count);
    int row = mat_ref.size();
    int col = mat_ref[0].size();
    
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

BENCHMARK(bench_x);
// BENCHMARK(bench_x);
BENCHMARK_MAIN();