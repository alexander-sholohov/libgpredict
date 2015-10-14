#pragma once


// prevent strange strdup Win32 behaviour

#ifdef _MSC_VER
#define mystrdup(X) _strdup(X)
#else
#define mystrdup(X) strdup(X)
#endif

