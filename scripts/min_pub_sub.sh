#!/bin/bash

cleanup() {
    echo 'Restarting ROS-2 daemon...'
    ros2 daemon stop
    sleep 1
    ros2 daemon start
    echo 'Terminating all ROS-2 related processes...'
    kill 0
    exit
}

trap 'cleanup' SIGINT

# Run Publisher And Subscriber Nodes
ros2 run ros2_fundamentals minimal_publisher.py &
sleep 2
ros2 run ros2_fundamentals minimal_subscriber.py