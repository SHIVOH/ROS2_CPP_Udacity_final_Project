#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/srv/add_four_ints.hpp"                                        // CHANGE

#include <memory>

void add(const std::shared_ptr<tutorial_interfaces::srv::AddFourInts::Request> request,     // CHANGE
          std::shared_ptr<tutorial_interfaces::srv::AddFourInts::Response>       response)  // CHANGE
{
  response->sum = request->a + request->b + request->c + request->d;                                      // CHANGE
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld" " c: %ld"" d: %ld",  // CHANGE
                request->a, request->b, request->c, request->d);                                         // CHANGE
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("add_four_ints_server");   // CHANGE

  rclcpp::Service<tutorial_interfaces::srv::AddFourInts>::SharedPtr service =               // CHANGE
    node->create_service<tutorial_interfaces::srv::AddFourInts>("add_four_ints",  &add);   // CHANGE

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add four ints.");                     // CHANGE

  rclcpp::spin(node);
  rclcpp::shutdown();
}
