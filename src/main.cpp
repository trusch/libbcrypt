#include "bcrypt/BCrypt.hpp"
#include <iostream>

int main(){
	BCrypt bcrypt;
	std::string password = "test";
	std::string hash = bcrypt.generateHash(password);
	std::cout<<bcrypt.validatePassword(password,hash)<<std::endl;
	std::cout<<bcrypt.validatePassword("test1",hash)<<std::endl;
	return 0;
}
