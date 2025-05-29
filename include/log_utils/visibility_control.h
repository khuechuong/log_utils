#ifndef LOG_UTILS__VISIBILITY_CONTROL_H_
#define LOG_UTILS__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define LOG_UTILS_EXPORT __attribute__ ((dllexport))
    #define LOG_UTILS_IMPORT __attribute__ ((dllimport))
  #else
    #define LOG_UTILS_EXPORT __declspec(dllexport)
    #define LOG_UTILS_IMPORT __declspec(dllimport)
  #endif
  #ifdef LOG_UTILS_BUILDING_LIBRARY
    #define LOG_UTILS_PUBLIC LOG_UTILS_EXPORT
  #else
    #define LOG_UTILS_PUBLIC LOG_UTILS_IMPORT
  #endif
  #define LOG_UTILS_PUBLIC_TYPE LOG_UTILS_PUBLIC
  #define LOG_UTILS_LOCAL
#else
  #define LOG_UTILS_EXPORT __attribute__ ((visibility("default")))
  #define LOG_UTILS_IMPORT
  #if __GNUC__ >= 4
    #define LOG_UTILS_PUBLIC __attribute__ ((visibility("default")))
    #define LOG_UTILS_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define LOG_UTILS_PUBLIC
    #define LOG_UTILS_LOCAL
  #endif
  #define LOG_UTILS_PUBLIC_TYPE
#endif

#endif  // LOG_UTILS__VISIBILITY_CONTROL_H_
