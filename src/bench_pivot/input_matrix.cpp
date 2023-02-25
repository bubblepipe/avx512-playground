#include <vector>
const int input_mat_row = 49;
const int input_mat_col = 22;
const int input_mat_pivot_row = 8;
const int input_mat_pivot_col = 5;
const int input_mat_arr [49] [22] = 
  {{32, -31, 0, -32, 0, 0, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0},
  {2, 29, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 2, -1, 0, 0, 0, 0, 1},
  {1, 31, 0, 0, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {1, 31, 0, 0, 0, 0, 0, -1, 1, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, -1, 1, -32, 0, 0, 0, 0, -1, 0, 0, 0, -1, 1, 0, 0, 0, 0, -1},
  {1, 31, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 1, -32, 0, 0, 0, 0, 0, 0, 0, 0, -2, 1, 0, 0, 0, 0, -1},
  {1, 31, 0, 0, 0, -1, 32, 0, 0, 0, 0, 0, 0, 0, 0, 2, -1, 0, 0, 0, 0, 1},
  {1, 31, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {32, -31, 0, 0, 0, 0, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1},
  {32, -31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, -32, 0, 0, -1, 0, 0, 0, 0, 1},
  {1, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {2, 29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1},
  {1, 31, 0, 0, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 1, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 1, -32, 0, 0, 0, 0, 0, 0, 0, 0, -2, 1, 0, 0, 0, 0, -1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
  {1, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0},
  {1, 31, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0},
  {32, -31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1},
  {1, 30, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {1, 31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0},
  {1, 31, 0, 0, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 1, -32, 0, 0, 0, 0, 0, 0, 0, 0, -2, 0, 0, 0, 0, 0, -1}};

const int expected_out_mat_arr [49] [22] = 
  {{32,-31,0,-32,0,0,32,0,0,0,0,2,0,0,0,0,-1,0,0,0,0,1,},
  {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,-1,0,0,0,0,0,0,},
  {2,29,0,0,0,0,32,0,0,0,0,0,0,0,0,2,-1,0,0,0,0,1,},
  {1,31,0,0,0,0,0,-1,0,0,0,-1,0,0,0,1,0,0,0,0,0,0,},
  {1,31,0,0,0,0,0,-1,1,0,0,-1,0,0,0,1,0,0,0,0,0,0,},
  {1,31,0,0,-1,-1,0,0,0,0,0,-1,0,0,0,1,0,0,0,0,0,0,},
  {1,0,0,0,0,1,-32,0,0,0,0,0,0,0,0,-2,1,0,0,0,0,-1,},
  {1,31,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
  {1,31,0,0,0,-1,32,0,0,0,0,0,0,0,0,2,-1,0,0,0,0,1,},
  {1,31,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
  {1,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
  {1,0,-1,0,0,0,0,0,0,0,0,1,0,0,0,-1,0,0,0,0,0,0,},
  {1,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,},
  {1,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
  {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,-1,0,0,0,0,0,0,},
  {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,},
  {1,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,},
  {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,},
  {1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,},
  {1,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
  {32,-31,0,0,0,0,32,0,0,0,0,2,0,0,0,0,-1,0,0,0,0,1,},
  {32,-31,0,0,0,0,0,0,0,0,0,2,0,-32,0,0,-1,0,0,0,0,1,},
  {1,30,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,},
  {2,29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,1,},
  {1,31,0,0,0,0,0,-1,0,0,0,-1,0,0,0,0,0,-1,-1,0,0,0,},
  {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,},
  {1,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0,1,0,0,0,0,0,},
  {1,31,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,},
  {1,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,},
  {1,31,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,},
  {1,0,0,0,0,0,0,0,0,0,0,1,-1,0,0,0,0,0,0,0,0,0,},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,},
  {1,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,},
  {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,},
  {32,-31,0,0,0,0,0,0,0,0,0,2,0,0,0,0,-1,0,0,0,0,1,},
  {1,30,0,0,0,0,0,0,0,0,0,-1,0,0,0,1,0,0,0,0,0,0,},
  {1,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
  {1,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,},
  {1,31,0,0,0,0,0,-1,0,0,0,-1,0,0,0,0,0,-1,0,0,0,0,},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,},
  {1,31,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,}};
