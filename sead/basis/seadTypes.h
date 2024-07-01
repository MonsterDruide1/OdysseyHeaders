#ifndef SEAD_TYPES_H_
#define SEAD_TYPES_H_

#ifdef cafe
#include <types.h>
#else
#include <cstddef>
#include <cstdint>
#include <cstdio>

using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using s8 = std::int8_t;
using s16 = std::int16_t;
using s32 = std::int32_t;
using s64 = std::int64_t;

using f32 = float;
using f64 = double;

using char16 = char16_t;
using size_t = std::size_t;
#endif

#define DEREF_NULL *(volatile int*)0;
#define WARN_UNIMPL printf("Function not implemented: %s (%s:%d)\n", __PRETTY_FUNCTION__, __FILE__, __LINE__)
#define CRASH {WARN_UNIMPL;DEREF_NULL}


#endif  // SEAD_NEW_H_
