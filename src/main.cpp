#include "bcrypt/BCrypt.hpp"
#include <iostream>

int main(){
	BCrypt bcrypt;
	std::string right_password = "right_password";
	std::string wrong_password = "wrong_password";

	std::cout << "generate hash... " << std::flush;
	std::string hash = bcrypt.generateHash(right_password);
	std::cout << "done." << std::endl;

	std::cout << "checking right password: " << std::flush
			  << bcrypt.validatePassword(right_password,hash) << std::endl;

	std::cout << "checking wrong password: " << std::flush
			  << bcrypt.validatePassword(wrong_password,hash) << std::endl;

	return 0;
}
