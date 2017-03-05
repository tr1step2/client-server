#pragma once

#include <string>
#include <set>
#include <mutex>

#include "StoreManager.hpp"

namespace fxtm
{

class DataManager
{
public:
    DataManager();
    void updateData(std::uint16_t value, double & avg);

private:
    std::set<std::uint16_t> mDataStorage;
    size_t mCachedTotal = 0;
    size_t mCachedCount = 0;

    std::mutex mLockCache;
    std::mutex mLockStorage;

    StoreManager mStoreManager;
};

} // ns fxtm
