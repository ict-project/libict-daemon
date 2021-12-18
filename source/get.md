# `ict::base64::get` interface

Provides simple encoder/decoder functions:
* `void ict::base64::encode(const std::string & input,std::string & output,bool url=false,bool padding=true);`
* `std::string ict::base64::encode(const std::string & input,bool url=false,bool padding=true);`
* `void ict::base64::decode(const std::string & input,std::string & output);`
* `std::string ict::base64::decode(const std::string & input);`
