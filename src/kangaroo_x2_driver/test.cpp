#include <Arduino/Arduino.h>
#include "rclcpp/rclcpp.hpp"

class TestClass : public rclcpp::Node{
    public:
        TestClass() : Node("Test"){}
    
};

int main(int argc, char * argv[])
{
    std::string port = "/tmp/ttyV0"; 
    unsigned long baud = 38400;
    unsigned long timeout = 1000;
    // unsigned long enc_count_per_rev = 1200;
    // // time_ = std::chrono::system_clock::now();

    serial::Serial serial_port(port, baud, serial::Timeout::simpleTimeout(timeout));
    SerialStream stream(serial_port);

    // KangarooSerial K(stream);
    // KangarooChannel K1(K, '1');

    // K1.start();

    // byte b = 0xffffff80;
    // std::string s;
    // TestClass t = new TestClass();
    rclcpp::init(argc,argv);
    rclcpp::Rate(1000);
    // rclcpp::spin(std::make_shared<TestClass>());
    std::cout<<"start...."<<std::endl;
    while(rclcpp::ok()){
        int i = stream.read();
        // if(i==-128)
            // i = 128;
        // if(i<0) continue;
        if(i!=-1){
            i &= 0xFF;
            std::cout << "i is " << std::hex << i << std::endl;
        // rclcpp::sleep_for((std::chrono::nanoseconds)10000);
        }
    }
    rclcpp::shutdown();
    return 0;
}