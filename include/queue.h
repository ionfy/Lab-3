#pragma once

#pragma once

template <class T>
class TQueue {
private:
    size_t s;
    size_t f;
    size_t memSize;
    T* pMem;

    size_t next(size_t n) {
        return (n + 1) % memSize;
    }
public:
    TQueue(size_t n = 1): s(0), f(n-1), memSize(n), pMem(new T[memSize]) {}
    ~TQueue() { delete[] pMem; }
    TQueue(const TQueue& c) {
        memSize = c.memSize;
        s = c.s;
        f = c.f;
        pMem = new T[memSize];
        for (size_t i = s; i != next(f); i = next(i))
            pMem[i] = c.pMem[i];
    }

    TQueue& operator=(const TQueue& c) {
        if (this == &c) return *this;
        s = c.s;
        f = c.f;
        if (memSize != c.memSize) {
            T* tmp = new T[c.memSize];
            memSize = c.memSize;
            delete[] pMem;
            pMem = tmp;
        }
        for (size_t i = s; i != next(f); i = next(i))
            pMem[i] = c.pMem[i];
        return *this;
    }

    bool empty() {
        return s == next(f);
    }

    bool full() {
        return s == next(next(f));
    }

    void push(T elem) {
        if (full()) throw -1;
        f = next(f);
        pMem[f] = elem;
    }

    T last() {
        if (empty()) throw -1;
        return pMem[f];
    }

    T first() {
        if (empty()) throw -1;
        return pMem[s];
    }

    void pop() {
        if (empty()) throw -1;
        s = next(s);
    }
};