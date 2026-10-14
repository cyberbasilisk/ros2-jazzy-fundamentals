#include "rclcpp/rclcpp.hpp" // ROS-2 client
#include "std_msgs/msg/string.hpp" // String object (data type)

using namespace std::chrono_literals; // Handles time

class MinimalPublisher : public rclcpp::Node {
    public :
        
        MinimalPublisher() : Node("minimal_publisher"), count_(0) {
            publisher_ = create_publisher<std_msgs::msg::String>("/cpp_example_topic", 10);

            timer_ = create_wall_timer(500ms, std::bind(&MinimalPublisher::timerCallback, this));

            RCLCPP_INFO(get_logger(), "Publishing at 2Hz");
        }

        void timerCallback() {
            auto message = std_msgs::msg::String();
            message.data = "Hello ROS " + std::to_string(count_++);
            
            publisher_->publish(message);
        }

    private :

        size_t count_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc,char *argv[]) {

    rclcpp::init(argc, argv);

    auto minimal_publisher = std::make_shared<MinimalPublisher>();
    rclcpp::spin(minimal_publisher);

    rclcpp::shutdown();

    return 0;
}