#include <thread>

#include "DataManager.hpp"

fxtm::DataManager::DataManager(size_t syncInterval)
    : mStoreManager(mDataStorage, mLockStorage, syncInterval)
{

}

void fxtm::DataManager::updateData(std::uint16_t value, double & avg)
{
    std::lock_guard<std::mutex> lock(mLockCache);

    mCachedCount += 1;
    mCachedTotal += value * value;

    avg = (double)mCachedTotal / mCachedCount;

    std::thread t([this, value]()
    {
        std::lock_guard<std::mutex> lock(mLockStorage);
        mDataStorage.insert(value);
    });

    t.detach();
}
