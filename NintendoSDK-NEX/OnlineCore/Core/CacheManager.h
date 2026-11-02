#pragma once

namespace nn::nex {
class String;
class BasicCache;

class CacheManager {
public:
    CacheManager();
    ~CacheManager();

    BasicCache* GetCache(const String&);
};

}  // namespace nn::nex
