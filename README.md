# libbcrypt
A c++ wrapper around bcrypt password hashing

## How to build this
This is a CMake based project:

```bash
git clone https://github.com/trusch/libbcrypt
cd libbcrypt
mkdir build
cd build
cmake ..
make
sudo make install
sudo ldconfig
```

## How to use this

Here an example how to use this wrapper class (you can find a slightly edited example in src/ subdirectory)

```cpp
#include "bcrypt/BCrypt.hpp"
#include <iostream>

int main(){
	std::string password = "test";
	std::string hash = BCrypt::generateHash(password);

	std::cout << BCrypt::validatePassword(password,hash) << std::endl;
	std::cout << BCrypt::validatePassword("test1",hash) << std::endl;

	return 0;
}
```

build this with something like this:

```bash
g++ --std=c++11 -lbcrypt main.cpp
```
