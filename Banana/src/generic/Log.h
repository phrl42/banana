#pragma once

#define LOG(x) std::cout << "[MESSAGE]: "<< x << std::endl
#define LOG_DEBUG(x)

#ifdef BUILD_DEBUG
#undef LOG_DEBUG
#define LOG_DEBUG(x) std::cout << "[DEBUG]: " << x << std::endl
#endif


#define ASSERT(x) if(x){ std::cout << "[ASSERT]: " << x << std::endl; std::exit(EXIT_FAILURE); }
