%module satpredict

%{
#include "../../src/SatCalc.h"
#include "../../src/PassItem.h"
#include "../../src/SatPosition.h"
#include "../../src/TQth.h"
#include "../../src/TSat.h"
#include "../../src/TTime.h"
%}

#ifdef SWIGPHP
%include "php_ex.i"
#endif

#ifdef SWIGPYTHON
%include "python_ex.i"
#endif

#ifdef SWIGCSHARP
%include "csharp_ex.i"
#endif

#ifdef SWIGJAVA
%include "java_ex.i"
#endif

%include "../../src/SatCalc.h"
%include "../../src/PassItem.h"
%include "../../src/SatPosition.h"
%include "../../src/TQth.h"
%include "../../src/TSat.h"
%include "../../src/TTime.h"


