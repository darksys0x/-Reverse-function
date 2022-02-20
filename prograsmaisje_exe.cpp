#include<stdio.h>
#include<Windows.h>
#include <stdint.h>

#include <string>


uint8_t* EncryptTheString(uint8_t* str, DWORD size) {
	uint8_t* resultEncrypted = (uint8_t*)malloc(100);
	for (DWORD i = 0; ; i++) {
		if (i >= size)
			break;
		BYTE v13 = str[i];
		
		BYTE v3 = v13 ^ 4;
		BYTE v12 = v3 + size;
		
		resultEncrypted[i] = v12;
		


	}
	resultEncrypted[size] = '\0';
	return resultEncrypted;
}


std::string EncryptTheString(std::string str) {
	std::string encrypted;
	for (DWORD i = 0; ; i++) {
		if (i >= str.length())
			break;
		BYTE c = str[i] ^ 4;
		encrypted += c + str.length();
	}
	return encrypted;
}

int main() {
	char name[] = "hamad";
	uint8_t* d =  EncryptTheString((uint8_t*)name, strlen(name));
	printf("the encrypt name = %s", d);
	
	return 0;
}


  std::string theUser;
  std::cout << "user: ";
  std::getline(std::cin, theUser);

  std::string encryptedUser;
  for (int i = 0; i < theUser.length(); i++) {
    encryptedUser += (theUser[i] ^ 4) + theUser.length();
  }

  std::string theSerial;
  std::cout << "serial: ";
  std::getline(std::cin, theSerial);

  if (encryptedUser == theSerial)
    std::cout <<"good you are a master hacking, but make a keygen :/");
  else
    std::cout <<"you are not a master hacking";
  system("pause");



