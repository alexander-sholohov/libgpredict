swig.exe -php -c++ -outdir ./out_php -I..  satpredict.i 
move satpredict_wrap.cpp  .\out_cpp 
move out_php\php_satpredict.h  .\out_cpp  
