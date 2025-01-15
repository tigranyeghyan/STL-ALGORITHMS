#include "unordered_set.hpp"

template <typename T>
unordered_set<T>::unordered_set() : buckets(INITIAL_BUCKET_COUNT), elementCount(0) 
{

}

template <typename T>
size_t unordered_set<T>::getIndex(const T& key) const 
{
    return hasher(key) % buckets.size();
}

template <typename T>
void unordered_set<T>::rehash() 
{
    size_t newBucketCount = buckets.size() * 2;
    std::vector<std::list<T>> newBuckets(newBucketCount);
    for (auto& bucket : buckets)
    {
        for (const auto& elem : bucket) 
        {
            size_t newIndex = hasher(elem) % newBucketCount;
            newBuckets[newIndex].push_back(elem);
        }
    }

    buckets = std::move(newBuckets);
}

template <typename T>
bool unordered_set<T>::insert(const T& value) {
    size_t bucketIndex = getIndex(value);

    for (const auto& elem : buckets[bucketIndex]) {
        if (elem == value) {
            return false;
        }
    }

    buckets[bucketIndex].push_back(value);
    ++elementCount;
    if (static_cast<double>(elementCount) / buckets.size() > LOAD_FACTOR_THRESHOLD) 
    {
        rehash();
    }
    return true;
}

template <typename T>
bool unordered_set<T>::contains(const T& value) const 
{
    size_t bucketIndex = getIndex(value);
    for (const auto& elem : buckets[bucketIndex]) 
    {
        if (elem == value) 
        {
            return true;
        }
    }
    return false;
}

template <typename T>
bool unordered_set<T>::erase(const T& value) 
{
    size_t bucketIndex = getIndex(value);
    auto& bucket = buckets[bucketIndex];

    for (auto it = bucket.begin(); it != bucket.end(); ++it) 
    {
        if (*it == value) 
        {
            bucket.erase(it);
            --elementCount;
            return true;
        }
    }

    return false;
}

template <typename T>
size_t unordered_set<T>::size() const 
{
    return elementCount;
}

template <typename T>
bool unordered_set<T>::empty() const 
{
    return elementCount == 0;
}

template <typename T>
void unordered_set<T>::clear() 
{
    for (auto& bucket : buckets) 
    {
        bucket.clear();
    }
    elementCount = 0;
}
