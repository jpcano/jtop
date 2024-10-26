#ifndef FORMAT_H
#define FORMAT_H

#include <string>
#include <vector>
namespace Format {
std::string ElapsedTime(long times);
std::vector<std::string> split(const std::string& serialized_str,
                               const std::string& delimiter);
};  // namespace Format

#endif