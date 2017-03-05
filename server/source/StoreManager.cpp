#include "StoreManager.hpp"

fxtm::StoreManager::StoreManager(const std::set<uint16_t> & storage, std::mutex & storageMutex)
    : mStorage(storage)
    , mStorageMutex(storageMutex)
{

}

fxtm::StoreManager::~StoreManager()
{

}

void fxtm::StoreManager::storeData()
{

}
