#include <algorithm>
#include <fstream>
#include <iterator>
#include <vector>

#include "StoreManager.hpp"
#include "Logger.hpp"

fxtm::StoreManager::StoreManager(const std::multiset<uint16_t> & storage, std::mutex & storageMutex,
                                 size_t interval)
    : mStorage(storage)
    , mStorageMutex(storageMutex)
    , mSyncSecondsInterval(interval)
{
    startThread();
}

fxtm::StoreManager::~StoreManager()
{
    mRunFlag.store(false);
    mSyncThread->join();
}

void fxtm::StoreManager::storeData()
{
    mNextSyncTimePoint = std::chrono::system_clock::now() + std::chrono::seconds(mSyncSecondsInterval);

    std::vector<std::uint16_t> storageCopy;

    //critical section to copy storage
    {
        std::lock_guard<std::mutex> lock(mStorageMutex);

        storageCopy.reserve(storageCopy.size());
        std::copy(mStorage.cbegin(), mStorage.cend(), std::back_inserter(storageCopy));
    }

    storeDataToFile(storageCopy);
}

void fxtm::StoreManager::startThread()
{
    mRunFlag.store(true);
    mSyncThread.reset(new std::thread([this]()
    {
        while(true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            if (!mRunFlag)
                return;

            std::chrono::system_clock::time_point currentTimePoint = std::chrono::system_clock::now();

            if (currentTimePoint >= mNextSyncTimePoint)
                storeData();
        }
    }));
}

void fxtm::StoreManager::storeDataToFile(std::vector<std::uint16_t> & storageCopy)
{
    std::ofstream ofs("storage");
    if (!ofs)
    {
        Logger::log("Can't open file.");
        return;
    }

    std::ostream_iterator<std::uint16_t> outIterator(ofs, " ");
    std::copy(storageCopy.begin(), storageCopy.end(), outIterator);
}
