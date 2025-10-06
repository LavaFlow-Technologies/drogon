#pragma once

#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef TRANTOR_EXPORTS
    // Building TRANTOR as a DLL
    #ifdef __GNUC__
      #define TRANTOR_EXPORT __attribute__((dllexport))
    #else
      #define TRANTOR_EXPORT __declspec(dllexport)
    #endif
  #else
    // Using TRANTOR as a DLL
    #ifdef __GNUC__
      #define TRANTOR_EXPORT __attribute__((dllimport))
    #else
      #define TRANTOR_EXPORT __declspec(dllimport)
    #endif
  #endif
  #define TRANTOR_LOCAL
#else
  // Non-Windows platforms
  #if __GNUC__ >= 4
    #define TRANTOR_EXPORT __attribute__((visibility("default")))
    #define TRANTOR_LOCAL  __attribute__((visibility("hidden")))
  #else
    #define TRANTOR_EXPORT
    #define TRANTOR_LOCAL
  #endif
#endif
