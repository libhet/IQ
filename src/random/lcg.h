#ifndef LCG_H
#define LCG_H

/// Линейный конгруэнтный генератор
/// Генерирует число между 0 (включительно) и M (исключительно)
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

// Лучше всего конвертировать произведенную ГПСЧ величину в дробь между 0
// и 1, а затем умножить ее на желаемый диапазон, как в следующей формуле: резуль-
// тат = min + (число  M) u (max – min).

#endif // LCG_H