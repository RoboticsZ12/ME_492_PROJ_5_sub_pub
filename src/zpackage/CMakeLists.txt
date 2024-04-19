cmake_minimum_required(VERSION 3.5)
project(zpackage)

# Find packages needed for project. 
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Add executable files within the src folder.
add_executable(publisher_node src/publisher.cpp)
ament_target_dependencies(publisher_node rclcpp std_msgs) # ament_target_dependencies() is basically target_link_libraries.
add_executable(subscriber_node src/subscriber.cpp)
ament_target_dependencies(subscriber_node rclcpp std_msgs)

# Install executables to binary files. 
install(TARGETS
  publisher_node
  subscriber_node
  DESTINATION lib/${PROJECT_NAME})

# Install package.xml
install(FILES
  package.xml
  DESTINATION share/${PROJECT_NAME})

ament_package()


#------------------------------#
# HOW TO CREATE RUN THE FILES. #
#------------------------------#
  # cd ~/ros2_ws/
  # colcon build --symlink-install
  
  # Run the publisher and subscriber nodes in separate terminals using the following commands:
  
######## publisher_node and subscriber_node = names

  # source install/setup.bash
  # ros2 run zpackage publisher_node
  
  # source install/setup.bash
  # ros2 run zpackage subscriber_node
  
  
  