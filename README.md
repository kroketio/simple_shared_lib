## cool_lib

Usage:

```cpp
#include "cool_lib/cool_lib.h"
[...]
int result = cool_library::whatsup(42);
```

## Installation

```bash
# configure the project
cmake -Bbuild .

# build the project
make -Cbuild -j4

# install the project (into /usr/local/)
sudo make -Cbuild install
```

Output of the install command:

```
-- Up-to-date: /usr/local/include/cool_lib/cool_lib.h
-- Up-to-date: /usr/local/lib/libcool_lib.so.0.0.1
-- Up-to-date: /usr/local/lib/libcool_lib.so.0
-- Up-to-date: /usr/local/lib/libcool_lib.so
-- Installing: /usr/local/lib/cmake/cool_lib/cool_libTargets.cmake
-- Installing: /usr/local/lib/cmake/cool_lib/cool_libTargets-debug.cmake
-- Installing: /usr/local/lib/cmake/cool_lib/cool_libConfig.cmake
-- Installing: /usr/local/lib/cmake/cool_lib/cool_libConfigVersion.cmake
```

At this point there is a `.so` (the library) for linking, and a header file `cool_lib/cool_lib.h` for inclusion.


## Test app

There is also at test app that gets compiled:

```text
[dsc@fastbox shared_lib (master ✗)]$ ./build/bin/cool_test
whatsup() called :)
factorial(42) = 0
```

it links against our library:

```text
[dsc@fastbox shared_lib (master ✗)]$ ldd /build/bin/cool_test
	libcool_lib.so.0
```