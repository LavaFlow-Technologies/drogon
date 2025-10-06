#pragma once

#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef DROGON_EXPORTS
    // Building Drogon as a DLL
    #ifdef __GNUC__
      #define DROGON_EXPORT __attribute__((dllexport))
    #else
      #define DROGON_EXPORT __declspec(dllexport)
    #endif
  #else
    // Using Drogon as a DLL
    #ifdef __GNUC__
      #define DROGON_EXPORT __attribute__((dllimport))
    #else
      #define DROGON_EXPORT __declspec(dllimport)
    #endif
  #endif
  #define DROGON_LOCAL
#else
  // Non-Windows platforms
  #if __GNUC__ >= 4
    #define DROGON_EXPORT __attribute__((visibility("default")))
    #define DROGON_LOCAL  __attribute__((visibility("hidden")))
  #else
    #define DROGON_EXPORT
    #define DROGON_LOCAL
  #endif
#endif
