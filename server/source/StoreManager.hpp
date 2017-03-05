#pragma once

#include <atomic>
#include <mutex>
#include <thread>
#include <set>
#include <vector>

namespace fxtm
{

class StoreManager
{
public:
    StoreManager(const std::multiset<uint16_t> & storage, std::mutex & storageMutex,
                 size_t mSyncSecondsInterval);
    ~StoreManager();

private:
    void storeData();
    void startThread();
    void storeDataToFile(std::vector<uint16_t> & storageCopy);
private:
    std::mutex & mStorageMutex;
    const std::multiset<std::uint16_t> & mStorage;

    std::atomic<bool> mRunFlag;
    std::unique_ptr<std::thread> mSyncThread;
    std::chrono::system_clock::time_point mNextSyncTimePoint;
    size_t mSyncSecondsInterval;
};

} // ns fxtm
