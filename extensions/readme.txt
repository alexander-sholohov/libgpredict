
This SWIG wrapper around gpredict library.
Supported languages: python, php. It is easy to add other languages SWIG supports.


How to compile gpredict python module

git clone https://github.com/alexander-sholohov/libgpredict
cd libgpredict
mkdir build
cd build
cmake ..
make
cd ../extensions/python 
mkdir build
cd build
cmake ..
make

Done. Please find _satpredict.so at the current directory. 
For demo sample refer to ./extensions/python/demo/readme.txt 



SWIG:
http://swig.org

Git repository:
https://github.com/alexander-sholohov/libgpredict

Alexander Sholohov  <ra9yer@yahoo.com>
