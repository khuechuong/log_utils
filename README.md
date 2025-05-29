# log_utils
`log_utils` is a lightweight, header-only ROS 2 utility package that provides simplified logging functions:
- `log_utils::info()`
- `log_utils::warn()`
- `log_utils::error()`
- `log_utils::debug()`

These functions wrap the standard `RCLCPP_*` macros and support formatted output using variadic arguments, making logging more concise and consistent across packages.

Instead of 
```RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready.");```
you can do this:
```log_utils::info("Ready.");```
