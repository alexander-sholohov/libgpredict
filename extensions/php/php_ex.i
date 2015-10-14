
%typemap(out) char* {
    if(!result) {
      ZVAL_NULL(return_value);
    } else {
      ZVAL_STRING(return_value, (char *)result, 1);
    }
    free(result);
}


