// Copyright 2020 scorpy2013

#include "JsonArray.hpp"

#include <iostream>
void Start() {
  auto logger_trace = boost::log::add_file_log(
      boost::log::keywords::file_name =
          "/home/alexscorpy/Documents/АЯ/lab-06-multithreads-wp-lab/logs/"
          "LoggerFileTrace%N.log",
      boost::log::keywords::rotation_size = 10 * 1024 * 1024,
      boost::log::keywords::format =
          "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");
  auto logger_info = boost::log::add_file_log(
      boost::log::keywords::file_name =
          "/home/alexscorpy/Documents/АЯ/lab-06-multithreads-wp-lab/logs/"
          "LoggerFileInfo.log",
      boost::log::keywords::format =
          "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");
  auto logger_console = boost::log::add_console_log(
      std::cout, boost::log::keywords::format =
                     "[%TimeStamp%][%Severity%][%ThreadID%]: %Message%");
  logger_trace->set_filter(boost::log::trivial::severity >=
                           boost::log::trivial::trace);
  logger_info->set_filter(boost::log::trivial::severity ==
                          boost::log::trivial::info);
  logger_console->set_filter(boost::log::trivial::severity ==
                             boost::log::trivial::info);
}
void JsonArray::Logging(std::time_t timestamp, const std::string& hash,
                        const std::string& data) {
  std::scoped_lock<std::mutex> lock(mut);
  std::stringstream str;
  str << std::hex << std::uppercase << std::stoi(data);
  json JsonObject;
  JsonObject["timestamp"] = timestamp;
  JsonObject["hash"] = hash;
  JsonObject["data"] = str.str();
  JsonObject.push_back(JsonObject);
}
std::ostream& operator<<(std::ostream& out, const JsonArray& Json) {
  std::scoped_lock<std::mutex> lock(Json.mut);
  out << Json.JsonFile.dump(4);
  return out;
}
