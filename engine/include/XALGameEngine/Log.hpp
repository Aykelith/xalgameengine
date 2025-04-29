#ifndef XALGE_LOG_HPP
#define XALGE_LOG_HPP

#include "Global.hpp"

#ifndef XALGE_IS_PRODUCTION
#include <iostream>
#include <vector>
#include <string>
#define XAL_LOG_INFO(msg) \
    std::cout << "[I]" << msg << '\n'

#define XAL_LOG_DEBUG(msg) \
    std::cout << "[D][" << __FILE__ << ":" << __LINE__ << "]: " << msg << '\n'

#define XAL_LOG_VERBOSE(msg) \
    std::cout << "[B][" << __FUNCTION__ << "]: " << msg << '\n'

#define XAL_LOG_VERBOSE_DEBUG(msg) \
    std::cout << "[VB][" << __FILE__ << ":" << __LINE__ << "][" << __FUNCTION__ << "]: " << msg << '\n'

#define XAL_LOG_PRINT_STRING_VECTOR(vec) \
    for (const auto& el : vec) std::cout << "\t" << el << "\n";

#define XAL_LOG_PLAIN(msg) \
    std::cout << msg << '\n'

#define XAL_LOG_PLAIN_ERROR(msg) \
    std::cout << msg << '\n'

#define XAL_DEBUG_START_BLOCK() if (true)

#else
#define XAL_LOG_INFO(msg)

#define XAL_LOG_DEBUG(msg)

#define XAL_LOG_VERBOSE(msg)

#define XAL_LOG_VERBOSE_DEBUG(msg)

#define XAL_LOG_PRINT_STRING_VECTOR(vec)

#define XAL_LOG_PLAIN(msg)

#define XAL_LOG_PLAIN_ERROR(msg)

#define XAL_DEBUG_START_BLOCK() if (false)

#endif

#endif // XALGE_LOG_HPP