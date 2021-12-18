# `ict::base64::robot` class

Provides single character processing for Base64 encoding/decoding.

## Interface

```c
//! 
//! @brief Adds a char character to the robot.
//! 
//! @param input Character to add.
//! 
robot & operator ()(const char & input);
//! 
//! @brief Returns the output in subsequent steps.
//! 
//! @param output Output where encoded/decoded chars are added.
//! 
void getNext(std::string & output) const;
//! 
//! @brief Returns the output in the last step.
//! 
//! @param output Output where encoded/decoded chars are added.
//! 
void getLast(std::string & output) const;
//! 
//! @brief Informs if robot is ready to generate the output (getNext() only).
//! 
bool isReady() const;
//! 
//! @brief Clears object.
//! 
void clear();
```

## Usage

Encoder:
```c
#inlude "robot.hpp"

std::string input;
std::string output;
ict::base64::robot r(robot_encoder_padding);
for (const char & c : input){//Read char by char
    if (r(c).isReady()){//When robot is ready (has enough data)
        r.getNext(output);//Write output.
    }
}
r.getLast(output);//Write output (last step).
```

Decoder:
```c
#inlude "robot.hpp"

std::string input;
std::string output;
ict::base64::robot r(robot_decoder);
for (const char & c : input){//Read char by char
    if (r(c).isReady()){//When robot is ready (has enough data)
        r.getNext(output);//Write output.
    }
}
r.getLast(output);//Write output (last step).
```

In the robot's constructor following choice must be made:
* `robot_decoder` - for decoder;
* `robot_encoder_padding`- for encoder with padding;
* `robot_encoder_padding_url`- for encoder with padding and compatible with URL;
* `robot_encoder_url` - for encoder without padding and compatible with URL;
* `robot_encoder` - for encoder without padding.
