#ifndef __WIN_BCRYPT__H
#define __WIN_BCRYPT__H

#include <iostream>

#include "crypt_blowfish.h"
#include "./bcrypt.h"

// For NULL byte add 1.
#define BCRYPT_HASHSIZE 61

// Looked at here for example on how this can be done on windows.
// https://github.com/kelektiv/node.bcrypt.js/blob/master/src/bcrypt.cc
#ifdef _WIN32
#define snprintf _snprintf
#endif

class BCrypt {
public:
	static std::string generateHash(const std::string & password, int workload = 12) {
		char salt[BCRYPT_HASHSIZE];
		char hash[BCRYPT_HASHSIZE];
		int ret;
		ret = bcrypt_gensalt(workload, salt);
		if (ret != 0)throw std::runtime_error{ "bcrypt: can not generate salt" };
		ret = bcrypt_hashpw(password.c_str(), salt, hash);
		if (ret != 0)throw std::runtime_error{ "bcrypt: can not generate hash" };
		return std::string{ hash };
	}

	static bool validatePassword(const std::string & password, const std::string & hash) {
		return (bcrypt_checkpw(password.c_str(), hash.c_str()) == 0);
	}
};

#endif