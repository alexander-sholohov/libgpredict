

%typemap(out) char* {
  if( !result) { return SWIG_Py_Void(); }
  $result = PyString_FromString((const char *)result);
  free(result);
}

