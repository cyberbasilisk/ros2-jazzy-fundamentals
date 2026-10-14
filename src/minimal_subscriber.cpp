#include "rclcpp/rclcpp.hpp" // ROS-2 client
#include "std_msgs/msg/string.hpp" // String object (data type)

using std::placeholders::_1; // placeholder for callback


class MinimalSubscriber : public rclcpp::Node {
    public :
        
        MinimalSubscriber() : Node("minimal_subscriber") {
            subscriber_ = create_subscription<std_msgs::msg::String>("/cpp_example_topic", 10, std::bind(&MinimalSubscriber::topicCallback, this, _1));
        }

        void topicCallback(const std_msgs::msg::String &msg) const {
            RCLCPP_INFO_STREAM(get_logger(), "I heard: " << msg.data.c_str());
        }
    
    private :
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
};

int main(int argc, char *argv[]){

    rclcpp::init(argc, argv);

    auto minimal_subscriber = std::make_shared<MinimalSubscriber>();
    rclcpp::spin(minimal_subscriber);

    rclcpp::shutdown();

    return 0;
}