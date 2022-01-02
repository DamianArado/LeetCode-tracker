class Solution {
 public:
  std::string defangIPaddr(std::string address) {
    return std::regex_replace(address, std::regex("\\.") , "[.]");
  }
};