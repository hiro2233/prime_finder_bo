# Prime number finder

A prime number finder libraries utility sets and snippets written in Python, C/C++, Javascript, JAVA and Pascal.

Target platform supported: Arduino, Browsers and GNU/Linux distributions, Windows isn't yet tested.

There are two versions sources:

	- prime_number_sucre
	- prime_number_santacruz

The first (prime_number_sucre) is based on this document:
https://drive.google.com/file/d/1p2nQXw7cAWlFlbc3VRl1N0aKxTDZrCju/view
This one is written on Python on that document and source code is located on src/python/prime_number_sucre.py python file on this repository, source code was formatted with python coding style, some final output display description was modified and the 5th value on the group number values array was set to 10000000, originally setted to 100000.

The second is another algorithm soution (prime_number_santacruz) and is upto 8 (on some targets) times more fast than the first solution.

NOTE: On Arduino versions the 5th number on the group is set to 100000, and set to 10000000 on the other targets.

### On Arduino

Open the sketch ino source on Arduino IDE found at "src/arduino/prime_number*" folder, then build and flash it as normally way.

### On Browsers (Javascript)

Open the index.html on your browser found at  "src/browser/prime_number*" folder, then it will run directly, wait until it finish.

### On GNU/Linux (Java)

Open the terminal (for each version) and execute:

For Sucre:
```bash
$ javac src/java/prime_number_sucre.java
$ java -classpath src/java prime_number_sucre
```

For Santa Cruz:
```bash
$ javac src/java/prime_number_santacruz.java
$ java -classpath src/java prime_number_santacruz
```

### On GNU/Linux (C/C++)

Open the a terminal (for each version) and execute:

For Sucre:
```bash
$ cd src/native/prime_number_sucre/
$ make
$ ./build/Release/prime_number_sucre
```

For Santa Cruz:
```bash
$ cd native/prime_number_santacruz/
$ make
$ ./build/Release/prime_number_santacruz
```
### On GNU/Linux (Pascal)

Open the a terminal (for each version) and execute:

For Sucre:

```bash
$ fpc -O3 src/pascal/prime_number_sucre/prime_number_sucre.pas
$ ./src/pascal/prime_number_sucre/prime_number_sucre
```

For Santa Cruz:

```bash
$ fpc -O3 src/pascal/prime_number_santacruz/prime_number_santacruz.pas
$ ./src/pascal/prime_number_santacruz/prime_number_santacruz
```

### On GNU/Linux (Python)

Open the a terminal (for each version) and execute:

For Sucre:

```bash
$ python src/python/prime_number_sucre.py
```

For Santa Cruz:

```bash
$ python src/python/prime_number_santacruz.py
```

----------------
# Benchmarking output comparison:

Tested PC on CPU:

```bash
$ lscpu

Architecture:          x86_64
CPU op-mode(s):        32-bit, 64-bit
Byte Order:            Little Endian
CPU(s):                8
On-line CPU(s) list:   0-7
Thread(s) per core:    2
Core(s) per socket:    4
Socket(s):             1
NUMA node(s):          1
Vendor ID:             AuthenticAMD
CPU family:            21
Model:                 2
Model name:            AMD FX(tm)-8350 Eight-Core Processor
Stepping:              0
CPU MHz:               3600.000
CPU max MHz:           3600.0000
CPU min MHz:           1400.0000
BogoMIPS:              7223.10
Virtualization:        AMD-V
L1d cache:             16K
L1i cache:             64K
L2 cache:              2048K
L3 cache:              8192K
NUMA node0 CPU(s):     0-7

```

Tested Arduino target on Arduino UNO Board (atmega328p).

### Prime number finder SUCRE version benchmark:

| Platform | Language | Time in Seconds |
| ---- | ---- | ---- |
| Arduino  | C/C++   | 300 |
| GNU/Linux (Firefox) | Javascript | 28.901 |
| GNU/Linux |  Java | 103.657 |
| GNU/Linux |  C/C++ | 80.489 |
| GNU/Linux |  Pascal | 256.06 |
| GNU/Linux |  Python | 638.523 |

### Prime number finder Santa Cruz version benchmark:

| Platform | Language | Time in Seconds |
| ---- | ---- | ---- |
| Arduino  | C/C++   | 115 |
| GNU/Linux (Firefox) | Javascript | 12.458 |
| GNU/Linux |  Java | 11.698 |
| GNU/Linux |  C/C++ | 11.869 |
| GNU/Linux |  Pascal | 11.93 |
| GNU/Linux |  Python | 196.261 |
