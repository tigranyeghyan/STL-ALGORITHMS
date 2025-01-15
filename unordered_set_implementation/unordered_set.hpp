#ifndef UNORDERED_SET_H
#define UNORDERED_SET_H

#include <vector>
#include <list>
#include <functional>

template <typename T>
class unordered_set {
private:
    static constexpr size_t INITIAL_BUCKET_COUNT = 8;
    static constexpr double LOAD_FACTOR_THRESHOLD = 0.75;
    std::vector<std::list<T>> buckets;
    size_t elementCount;
    std::hash<T> hasher;
    size_t getIndex(const T& key) const;
    void rehash();

public:
    unordered_set();
    bool insert(const T& value);
    bool contains(const T& value) const;
    bool erase(const T& value);
    size_t size() const;
    bool empty() const;
    void clear();
};

#include "unordered_set.cpp"

#endif
