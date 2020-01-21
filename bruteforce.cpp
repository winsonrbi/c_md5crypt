#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "hashlibpp.h"
#include "hl_exception.h"
#include "hl_hashwrapper.h"
#include "hl_md5.cpp"
#include "hl_md5wrapper.cpp"

#include <cstdlib>

using namespace std;

void md5crypt(string plaintext_password){
  try{
    hashwrapper *h = new md5wrapper();
    string target_hash = "wPwz7GC6xLt9eQZ9eJkaq";
    string salt = "hfT7jp2q";
    const char *base64_crypt = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    h->test();  
    string alternate = plaintext_password + salt + plaintext_password;
    string alternate_sum = h->getHashFromString(alternate);
    cout << alternate_sum << endl; 
    string intermediate_0 = plaintext_password + "$1$" + salt;

    string intermediate_0_hash = h->getHashFromString(intermediate_0);
    
    //update digest
    int pwlen = plaintext_password.length();
    int i = pwlen;
    for(i; i>0; i -=16){
      if(i > 16){
        intermediate_0 = intermediate_0 + alternate_sum;
      }
      else{
        intermediate_0 = intermediate_0 + alternate_sum.substr(0,i-1);
      }
    }
    //dummy char
    char dummy[8] = "DUMMY"; 
    memset(dummy,0,sizeof dummy);
    for (i = pwlen; i; i >>=1){
      if(i % 2 == 1){
        intermediate_0 = intermediate_0 + dummy[0];
      }
      else{
        intermediate_0 = intermediate_0 + plaintext_password.at(0);
      }
    }
    intermediate_0_hash = h->getHashFromString(intermediate_0);
    cout << intermediate_0_hash << endl;
    cout << alternate << endl;
        
  }
  catch(int e){
    fprintf(stderr, "Problem exception number %d", e); 
    abort();
  }
}

int main(){
  md5crypt("zhgnnd"); 
  return 0;
}
