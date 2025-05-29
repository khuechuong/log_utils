#pragma once

#include "rclcpp/rclcpp.hpp"
#include <string>

namespace log_utils {

template<typename... Args>
void info(const std::string & format, Args&&... args)
{
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), format.c_str(), std::forward<Args>(args)...);
}

template<typename... Args>
void warn(const std::string & format, Args&&... args)
{
    RCLCPP_WARN(rclcpp::get_logger("rclcpp"), format.c_str(), std::forward<Args>(args)...);
}

template<typename... Args>
void error(const std::string & format, Args&&... args)
{
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), format.c_str(), std::forward<Args>(args)...);
}

template<typename... Args>
void debug(const std::string & format, Args&&... args)
{
    RCLCPP_DEBUG(rclcpp::get_logger("rclcpp"), format.c_str(), std::forward<Args>(args)...);
}

}

