// text
#include <iostream>


class HelloWorld {
    public:
        HelloWorld(){}
        void say(){
            std::cout << "Hello Kepke!!" << std::endl;
        }
};

extern "C" void sayHello() {
    HelloWorld hw;
    hw.say();
}