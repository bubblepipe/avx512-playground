#include <vector>
template <typename T>
class matrix {

  public:
    std::vector<T> m;
    unsigned int row;
    unsigned int col;

    matrix(unsigned int r, unsigned int c) {
        row = r;
        col = c;
        m.resize(r * c);
    }

  public:
    T get(unsigned int x, unsigned int y) {
        return m[col * x + y];
    }
    void set(unsigned int x, unsigned int y, T val) {
        m[col * x + y] = val;
    }
};
