//! @file
//! @brief Base64 robot module - Header file.
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
#ifndef _ICT_BASE64_ROBOT_HEADER
#define _ICT_BASE64_ROBOT_HEADER
//============================================
#include <string>
//============================================
namespace ict { namespace base64 {
//===========================================
enum robot_type_t {
    robot_decoder,//!< Dekoder.
    robot_encoder_padding,//!< Enkoder ze znakami uzupełnienia.
    robot_encoder_padding_url,//!< Enkoder ze znakami uzupełnienia i z możliwością wstawienia do URL.
    robot_encoder_url,//!< Enkoder bez znaków uzupełnienia i z możliwością wstawienia do URL.
    robot_encoder//!< Enkoder bez znaków uzupełnienia.
};
class robot{
private:
    robot_type_t type;
    bool url;
    bool padding;
    uint8_t phase=0;
    uint8_t bytes[4];
public:
    //! 
    //! @brief Konstruktor.
    //! 
    //! @param t Typ robota.
    //! 
    robot(robot_type_t t):type(t){
        clear();
    }
    //! 
    //! @brief Konstruktor.
    //! 
    //! @param t Typ robota.
    //! 
    robot(bool decoder,bool u=false,bool p=true){
        if (decoder){
            type=robot_decoder;
        } else if (u&&p){
            type=robot_encoder_padding_url;
        } else if (u&&!p){
            type=robot_encoder_url;
        } else if (!u&&!p){
            type=robot_encoder;
        } else if (!u&&p){
            type=robot_encoder_padding;
        }
        clear();
    }
    //! 
    //! @brief Dodaje nowy znak (dekoder) lub bajt (enkoder) do robota.
    //! 
    //! @param input Znak do załadowania
    //! 
    robot & operator ()(const char & input);
    //! 
    //! @brief Zwraca wyjście w kolejnym kroku.
    //! 
    //! @param output Wyjście, do którego dodawane są kolejne znaki (enkoder) lub bajty (dekoder). 
    //! 
    void getNext(std::string & output) const;
    //! 
    //! @brief Zwraca wyjście w ostatnim kroku.
    //! 
    //! @param output Wyjście, do którego dodawane są kolejne znaki (enkoder) lub bajty (dekoder). 
    //! 
    void getLast(std::string & output) const;
    //! 
    //! @brief Zwraca status.
    //! 
    //! @return true Gotowy do odczytu
    //! @return false Jeszcze nie gotowy do odczytu.
    //! 
    bool isReady() const;
    //! 
    //! @brief Zeruje obiekt
    //! 
    void clear();
};
//===========================================
} }
//============================================
#endif