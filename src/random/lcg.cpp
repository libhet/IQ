#include "lcg.h"


int lcg::get() {
        return _get(_A, _X, _B, _M);
}

void lcg::set_seed(int X) {
        _X = X;
}

int lcg::_get(const int A, int Xn, const int B, const int M) {
        auto X = _X;
        _X = (A * Xn + B) % M;
        return X;
}
