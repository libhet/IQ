/// Линейный конгруэнтный генератор
#ifndef LCG_H
#define LCG_H

class lcg {
public:
        lcg(const int A, const int B, const int M) 
            : _A(A), _B(B), _M(M) {        }

    int get();

    void set_seed(int X);

private:
    /// Х_(n+1) = ( A x X_n + B) mod M
    int _get(const int A, int Xn, const int B, const int M);

private:
    int _A, _B, _M;
    int _X; ///< seed
};

#endif // LCG_H