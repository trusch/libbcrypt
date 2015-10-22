#ifndef __BCRYPT__
#define __BCRYPT__

#include "bcrypt.h"
#include <string>
#include <stdexcept>

class BCrypt {
protected:
    int _workFactor;
public:
    BCrypt(int workFactor = 12) : _workFactor{workFactor} {}

    std::string generateHash(const std::string & password){
        char salt[BCRYPT_HASHSIZE];
        char hash[BCRYPT_HASHSIZE];
        int ret;
        ret = bcrypt_gensalt(12, salt);
        if(ret != 0)throw std::runtime_error{"bcrypt: can not generate salt"};
        ret = bcrypt_hashpw(password.c_str(), salt, hash);
        if(ret != 0)throw std::runtime_error{"bcrypt: can not generate hash"};
        return std::string{hash};
    }

    bool validatePassword(const std::string & password, const std::string & hash){
        return (bcrypt_checkpw(password.c_str(), hash.c_str()) == 0);
    }
};

#endif // __BCRYPT__
