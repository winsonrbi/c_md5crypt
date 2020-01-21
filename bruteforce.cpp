#include <string>
#include <stdio.h>
#include <iostream>
#include <hashlibpp.h>
using namespace std;

void md5crypt(string plaintext_password){
  try{
    hashwrapper *
    string target_hash = "wPwz7GC6xLt9eQZ9eJkaq";
    string salt = "hfT7jp2q";
    const char *base64_crypt = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
      
    string alternate = plaintext_password + salt + plaintext_password;
    cout << alternate << endl;
    
  }
  catch(int e){
    fprintf(stderr, "Problem exception number %d", e); 
  }
  
}

int main(){
  md5crypt("zhgnnd"); 
  return 0;
}
