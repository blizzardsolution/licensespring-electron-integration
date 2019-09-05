#pragma once

#ifdef LS_DLL_EXPORTS
#define LICENSESPRING_EXP __declspec(dllexport)
#elif LS_STATIC
#define LICENSESPRING_EXP
#else
#define LICENSESPRING_EXP __declspec(dllimport)
#endif

#ifdef __linux__
#define LICENSESPRING_EXP
#endif // __linux__

#ifdef __APPLE__
#define LICENSESPRING_EXP
#endif // __APPLE__


