#!/usr/bin/env python3

"""
Description:
    This ROS 2 node publishes "Hello ROS" messages on a topic every half second.
    The goal of this node is to demonstrates basic ROS concepts.

Publishing Topics:
    /example_topic - std_msgs/String

Subscription Topics:
    None
"""

import rclpy # ROS 2 client Python library
from rclpy.node import Node

from std_msgs.msg import String

class MinimalPublisher(Node):

	def __init__(self):

		# Initialize node
		super().__init__('minimal_publisher')

		self.queue_count = 10
		self.publisher_1 = self.create_publisher(String, '/py_example_topic', self.queue_count)

		timer_period = 0.5
		self.timer = self.create_timer(timer_period, self.timer_callback)

		self.i = 0

	def timer_callback(self):
		msg = String()

		msg.data = f"Hello Ros {self.i}"
		self.publisher_1.publish(msg)

		self.get_logger().info(f"Publishing: {msg.data}")
		self.i += 1


def main(args=None):

	rclpy.init(args=args)

	minimal_publisher = MinimalPublisher()

	rclpy.spin(minimal_publisher)
	minimal_publisher.destroy_node()

	rclpy.shutdown()


if __name__ == '__main__':
	main()
