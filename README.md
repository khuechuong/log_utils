# log_utils
`log_utils` is a lightweight, header-only ROS 2 utility package that provides simplified logging functions:
- `log_utils::info()`
- `log_utils::warn()`
- `log_utils::error()`
- `log_utils::debug()`

These functions wrap the standard `RCLCPP_*` macros and support formatted output using variadic arguments, making logging more concise and consistent across packages.

## ✨ Features

```cpp
#include "log_utils/log_utils.hpp"

log_utils::info("Sum: %d", 42);
log_utils::warn("Battery low: %.2f%%", 7.5);
log_utils::error("Failed to connect to %s", "sensor_node");
log_utils::debug("x: %.2f, y: %.2f", 1.23, 4.56);
```

## 🔧 Installation
```
cd ~/<you folder>/src
git clone https://github.com/khuechuong/log_utils.git
cd ..
colcon build --packages-select log_utils
source install/setup.bash
```

## 📥 How to Use in Another ROS 2 Package

To use `log_utils` in your own ROS 2 C++ package:

---

### 1. Update `package.xml`

Add the dependency:

```xml
<depend>log_utils</depend>
```

### 2. Update CMakeLists.txt

At the top, add:

```
find_package(log_utils REQUIRED)
```

Then link it to your target:

```
add_executable(my_node src/my_node.cpp)
ament_target_dependencies(my_node rclcpp log_utils)
```
### 3. Use It in Your Code

```cpp
#include "log_utils/log_utils.hpp"

log_utils::info("Launching node: %s", "my_node");
```
