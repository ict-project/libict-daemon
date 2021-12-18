//! @file
//! @brief Base64 get module - Source file.
//! @author Mariusz Ornowski (mariusz.ornowski@ict-project.pl)
//! @version 1.0
//! @date 2012-2021
//! @copyright ICT-Project Mariusz Ornowski (ict-project.pl)
/* **************************************************************
Copyright (c) 2012-2021, ICT-Project Mariusz Ornowski (ict-project.pl)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
3. Neither the name of the ICT-Project Mariusz Ornowski nor the names
of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**************************************************************/
//============================================
#include "get.hpp"
#include "robot.hpp"
//============================================
namespace ict { namespace base64 {
//===========================================
void encode(const std::string & input,std::string & output,bool url,bool padding){
  robot r(false,url,padding);
  for (const char & c : input) {
    if (r(c).isReady()) r.getNext(output);
  }
  r.getLast(output);
}
std::string encode(const std::string & input,bool url,bool padding){
  std::string output;
  encode(input,output,url,padding);
  return(output);
}
void decode(const std::string & input,std::string & output){
  robot r(true);
  for (const char & c : input) {
    if (r(c).isReady()) r.getNext(output);
  }
  r.getLast(output);
}
std::string decode(const std::string & input){
  std::string output;
  decode(input,output);
  return(output);
}
//===========================================
} }
//===========================================
#ifdef ENABLE_TESTING
#include "test.hpp"
REGISTER_TEST(base64,tc1){
  std::string input(ict::test::test_string[3]);
  std::string output("RG_Fm8SHIGLFgmF6ZcWEc3R3LCDFvHLEhSBtw7NqIHDEmWsgbHXFum55Y2ggZmlnLg==");
  std::string out;
  std::cout<<" Test funcji ict::base64::encode(input,url=true,padding=true)"<<std::endl;
  out=ict::base64::encode(input,true,true);
  if (out!=output){
    std::cout<<" Błąd!!!"<<std::endl;
    std::cout<<" input="<<input<<std::endl;
    std::cout<<" output(oczekiwany)="<<output<<std::endl;
    std::cout<<" output(otrzymany)="<<out<<std::endl;
    return(-1);
  }
  return(0);
}
REGISTER_TEST(base64,tc2){
  std::string input(ict::test::test_string[3]);
  std::string output("RG/Fm8SHIGLFgmF6ZcWEc3R3LCDFvHLEhSBtw7NqIHDEmWsgbHXFum55Y2ggZmlnLg==");
  std::string out;
  std::cout<<" Test funcji ict::base64::encode(input,url=false,padding=true)"<<std::endl;
  out=ict::base64::encode(input,false,true);
  if (out!=output){
    std::cout<<" Błąd!!!"<<std::endl;
    std::cout<<" input="<<input<<std::endl;
    std::cout<<" output(oczekiwany)="<<output<<std::endl;
    std::cout<<" output(otrzymany)="<<out<<std::endl;
    return(-1);
  }
  return(0);
}
REGISTER_TEST(base64,tc3){
  std::string input(ict::test::test_string[3]);
  std::string output("RG_Fm8SHIGLFgmF6ZcWEc3R3LCDFvHLEhSBtw7NqIHDEmWsgbHXFum55Y2ggZmlnLg");
  std::string out;
  std::cout<<" Test funcji ict::base64::encode(input,url=true,padding=false)"<<std::endl;
  out=ict::base64::encode(input,true,false);
  if (out!=output){
    std::cout<<" Błąd!!!"<<std::endl;
    std::cout<<" input="<<input<<std::endl;
    std::cout<<" output(oczekiwany)="<<output<<std::endl;
    std::cout<<" output(otrzymany)="<<out<<std::endl;
    return(-1);
  }
  return(0);
}
REGISTER_TEST(base64,tc4){
  std::string input(ict::test::test_string[3]);
  std::string output("RG/Fm8SHIGLFgmF6ZcWEc3R3LCDFvHLEhSBtw7NqIHDEmWsgbHXFum55Y2ggZmlnLg");
  std::string out;
  std::cout<<" Test funcji ict::base64::encode(input,url=false,padding=false)"<<std::endl;
  out=ict::base64::encode(input,false,false);
  if (out!=output){
    std::cout<<" Błąd!!!"<<std::endl;
    std::cout<<" input="<<input<<std::endl;
    std::cout<<" output(oczekiwany)="<<output<<std::endl;
    std::cout<<" output(otrzymany)="<<out<<std::endl;
    return(-1);
  }
  return(0);
}
REGISTER_TEST(base64,tc5){
  std::string input("RG_Fm8SHIGLFgmF6ZcWEc3R3LCDFvHLEhSBtw7NqIHDEmWsgbHXFum55Y2ggZmlnLg==");
  std::string output(ict::test::test_string[3]);
  std::string out;
  std::cout<<" Test funcji ict::base64::decode()"<<std::endl;
  out=ict::base64::decode(input);
  if (out!=output){
    std::cout<<" Błąd!!!"<<std::endl;
    std::cout<<" input="<<input<<std::endl;
    std::cout<<" output(oczekiwany)="<<output<<std::endl;
    std::cout<<" output(otrzymany)="<<out<<std::endl;
    return(-1);
  }
  return(0);
}
REGISTER_TEST(base64,tc6){
  std::string input("RG/Fm8SHIGLFgmF6ZcWEc3R3LCDFvHLEhSBtw7NqIHDEmWsgbHXFum55Y2ggZmlnLg==");
  std::string output(ict::test::test_string[3]);
  std::string out;
  std::cout<<" Test funcji ict::base64::decode()"<<std::endl;
  out=ict::base64::decode(input);
  if (out!=output){
    std::cout<<" Błąd!!!"<<std::endl;
    std::cout<<" input="<<input<<std::endl;
    std::cout<<" output(oczekiwany)="<<output<<std::endl;
    std::cout<<" output(otrzymany)="<<out<<std::endl;
    return(-1);
  }
  return(0);
}
REGISTER_TEST(base64,tc7){
  std::string input("RG_Fm8SHIGLFgmF6ZcWEc3R3LCDFvHLEhSBtw7NqIHDEmWsgbHXFum55Y2ggZmlnLg");
  std::string output(ict::test::test_string[3]);
  std::string out;
  std::cout<<" Test funcji ict::base64::decode()"<<std::endl;
  out=ict::base64::decode(input);
  if (out!=output){
    std::cout<<" Błąd!!!"<<std::endl;
    std::cout<<" input="<<input<<std::endl;
    std::cout<<" output(oczekiwany)="<<output<<std::endl;
    std::cout<<" output(otrzymany)="<<out<<std::endl;
    return(-1);
  }
  return(0);
}
REGISTER_TEST(base64,tc8){
  std::string input("RG/Fm8SHIGLFgmF6ZcWEc3R3LCDFvHLEhSBtw7NqIHDEmWsgbHXFum55Y2ggZmlnLg");
  std::string output(ict::test::test_string[3]);
  std::string out;
  std::cout<<" Test funcji ict::base64::decode()"<<std::endl;
  out=ict::base64::decode(input);
  if (out!=output){
    std::cout<<" Błąd!!!"<<std::endl;
    std::cout<<" input="<<input<<std::endl;
    std::cout<<" output(oczekiwany)="<<output<<std::endl;
    std::cout<<" output(otrzymany)="<<out<<std::endl;
    return(-1);
  }
  return(0);
}
REGISTER_TEST(base64,tc9){
  std::cout<<" Test funcji ict::base64::encode(input,url=true,padding=true) oraz ict::base64::decode()"<<std::endl;
  for (const auto & s : ict::test::test_string){
    std::string input(s);
    std::string enc(ict::base64::encode(input,true,true));
    std::string dec(ict::base64::decode(enc));
    if (input!=dec){
      std::cout<<" Błąd!!!"<<std::endl;
      std::cout<<" input="<<input<<std::endl;
      std::cout<<" encode()="<<enc<<std::endl;
      std::cout<<" decode()="<<dec<<std::endl;
      return(-1);
    }
  }
  return(0);
}
REGISTER_TEST(base64,tc10){
  std::cout<<" Test funcji ict::base64::encode(input,url=false,padding=true) oraz ict::base64::decode()"<<std::endl;
  for (const auto & s : ict::test::test_string){
    std::string input(s);
    std::string enc(ict::base64::encode(input,false,true));
    std::string dec(ict::base64::decode(enc));
    if (input!=dec){
      std::cout<<" Błąd!!!"<<std::endl;
      std::cout<<" input="<<input<<std::endl;
      std::cout<<" encode()="<<enc<<std::endl;
      std::cout<<" decode()="<<dec<<std::endl;
      return(-1);
    }
  }
  return(0);
}
REGISTER_TEST(base64,tc11){
  std::cout<<" Test funcji ict::base64::encode(input,url=true,padding=false) oraz ict::base64::decode()"<<std::endl;
  for (const auto & s : ict::test::test_string){
    std::string input(s);
    std::string enc(ict::base64::encode(input,true,false));
    std::string dec(ict::base64::decode(enc));
    if (input!=dec){
      std::cout<<" Błąd!!!"<<std::endl;
      std::cout<<" input="<<input<<std::endl;
      std::cout<<" encode()="<<enc<<std::endl;
      std::cout<<" decode()="<<dec<<std::endl;
      return(-1);
    }
  }
  return(0);
}
REGISTER_TEST(base64,tc12){
  std::cout<<" Test funcji ict::base64::encode(input,url=false,padding=false) oraz ict::base64::decode()"<<std::endl;
  for (const auto & s : ict::test::test_string){
    std::string input(s);
    std::string enc(ict::base64::encode(input,false,false));
    std::string dec(ict::base64::decode(enc));
    if (input!=dec){
      std::cout<<" Błąd!!!"<<std::endl;
      std::cout<<" input="<<input<<std::endl;
      std::cout<<" encode()="<<enc<<std::endl;
      std::cout<<" decode()="<<dec<<std::endl;
      return(-1);
    }
  }
  return(0);
}
#endif
//===========================================