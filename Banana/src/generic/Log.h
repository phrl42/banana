#pragma once

#define LOG(x) std::cout << "\033[38;05;34;1m" << "[MESSAGE]: "<< x << "\033[m" << std::endl
#define LOG_DEBUG(x)

#ifdef BUILD_DEBUG
#undef LOG_DEBUG
#define LOG_DEBUG(x) std::cout << "\033[38;05;45;1m" << "[DEBUG]: " << x << "\033[m" << std::endl
#endif


#define ASSERT(c, x) if(c){ std::cout << "\033[38;05;9;1m" << "[ASSERT]: " << x << "\033[m" << std::endl; std::exit(EXIT_FAILURE); }
