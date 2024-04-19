#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>   // header file for dynamic memory 

using namespace std::chrono_literals;

class PublisherNode : public rclcpp::Node   // Creates a class that will contain the node. 
{
public:
    PublisherNode() : Node("Publisher_node") // Creates a constructor that has a node named "Publisher_node"
    {
        publisher_ = this->create_publisher<std_msgs::msg::Int32>("random_numbers", 10);    // underscore represents objects within method NODE.
        timer_ = this->create_wall_timer(1s, std::bind(&PublisherNode::publishRandomNumber, this)); // This createsw a timer that will run the "publishRandomNumber" function every 1s. bind = binds the node to function.
    }
private:
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;  // CREATES publisher OBJECT
    rclcpp::TimerBase::SharedPtr timer_;    // Declare timer object. 

    void publishRandomNumber()
    {
        auto msg = std::make_shared<std_msgs::msg::Int32>();
        msg->data = rand() % 100; // generate random number from 0-99
        RCLCPP_INFO(get_logger(), "Publishing random number: %d", msg->data);   // prints the number to console.
        publisher_->publish(*msg);  // publish random number.
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);   // init = initializes the ROS 2 library 
    auto node = std::make_shared<PublisherNode>();  // instance of the PublisherNode class. 
    rclcpp::spin(node); // handles all the callbacks. Even though we do not have a callback, ROS 2 still requires for normal operation of the nodes. 
    rclcpp::shutdown();
    return 0;
}
