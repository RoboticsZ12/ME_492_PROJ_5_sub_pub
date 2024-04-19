#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

#include <memory>

class SubscriberNode : public rclcpp::Node  // THIS CREATES A NODE
{
public:
  SubscriberNode() : Node("subscriber_node")  // THIS CONSTRUCCTOR CREATES THE NODE NAMES "subscriber_node"
  {
    subscription_ = this->create_subscription<std_msgs::msg::Int32>("random_numbers", 10, std::bind(&SubscriberNode::topicCallback, this, std::placeholders::_1));
    // creates a queue of 10, topicCallback refers where to go if a message is recieved from the topic. 
    //placeholders_1 = creates a function object that binds the topicCallback function to the subscription so it can be called. 
  }

private:
  void topicCallback(const std_msgs::msg::Int32::SharedPtr msg) // this represents the callback function for received messages.
  {
    RCLCPP_INFO(this->get_logger(), "Received random number: %d", msg->data); 
    // LOGS the random numbers.
    // RCLPP_INFO is a type of message. There is also WARNING, and ERROR.
  }

  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;  // This represents the subscription.
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv); // "init" basically initilizes the ROS 2 libraries. 
  auto node = std::make_shared<SubscriberNode>();   // Is basically describing an instance for the class "SubscriberNode" and putting it in "node" variable.
  rclcpp::spin(node); // Handles incoming messages on all its OWN subscriptions. When message received, "callback function" is called to handle it. 
  rclcpp::shutdown(); // Turn off the ROS 2 library.
  return 0;
}
