// Copyright 2020 scorpy2013

#ifndef INCLUDE_JSON_ARRAY_HPP_
#define INCLUDE_JSON_ARRAY_HPP_
#include <boost/log/expressions.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup.hpp>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <mutex>
#include <nlohmann/json.hpp>
#include <sstream>
#include <string>

using json = nlohmann::json;

class JsonArray {
 public:
  void Logging(std::time_t timestamp, const std::string &hash,
               const std::string &data);

  friend std::ostream &operator<<(std::ostream &out, const JsonArray &Json);

 private:
  mutable std::mutex mut;
  json JsonFile;
};
void Start();
#endif  // INCLUDE_JSON_ARRAY_HPP_
