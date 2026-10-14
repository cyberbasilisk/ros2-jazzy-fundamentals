#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class MinimalSubscriber(Node):

    def __init__(self):
        
        super().__init__('minimal_subscriber')

        self.queue = 10
        self.subscriber_1 = self.create_subscription(String, '/py_example_topic', self.listener_callback, self.queue)

    def listener_callback(self, msg):

        self.get_logger().info(f'Listening for: {msg.data}')


def main(args=None):

    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()
    rclpy.spin(minimal_subscriber)

    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

    

