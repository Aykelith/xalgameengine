#ifndef XALGE_LOG_HPP
#define XALGE_LOG_HPP

#ifndef XALGE_IS_PRODUCTION
#include <iostream>
#define INFO(msg) \
    std::cout << "[I]" << msg << '\n'

#define DEBUG(msg) \
    std::cout << "[D][" << __FILE__ << ":" << __LINE__ << "]: " << msg << '\n'

#define VERBOSE(msg) \
    std::cout << "[B][" << __FUNCTION__ << "]: " << msg << '\n'

#define VERBOSE_DEBUG(msg) \
    std::cout << "[VB][" << __FILE__ << ":" << __LINE__ << "][" << __FUNCTION__ << "]: " << msg << '\n'
#else
#define DEBUG()
#endif

#endif // XALGE_LOG_HPP