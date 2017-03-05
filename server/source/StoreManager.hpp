#pragma once

#include <atomic>
#include <mutex>
#include <thread>
#include <set>

namespace fxtm
{

class StoreManager
{
public:
    StoreManager(const std::set<uint16_t> & storage, std::mutex & storageMutex);
    ~StoreManager();

private:
    void storeData();

private:
    std::mutex & mStorageMutex;
    const std::set<std::uint16_t> & mStorage;

    std::atomic<bool> mRunFlag;
    std::thread mSyncThread;
};

} // ns fxtm
