#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

template<typename T>
inline T gcd(T a, T b) {
    if (b == 0) {
        return a;
    }
    return abs(gcd(b, a % b));
}

#endif // MY_FUNCTIONS_H
