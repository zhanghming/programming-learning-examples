#include "file_util.h"
#include <string.h>
#include <iostream>

namespace file_util {

std::string JoinPath(const std::string& path1, const std::string& path2) {
    if (path1.empty() || path2.empty()) return path1 + path2;
    std::string path1_temp = (*(path1.end() - 1) != '/' ? path1 : path1.substr(0, path1.size() - 1));
    std::string path2_temp = (*path2.begin() == '/' ? path2 : path2.substr(1, path1.size() - 1));
    return path1_temp + path2_temp;
}

bool PathExists(const std::string &path) {
  struct stat info;
  return stat(path.c_str(), &info) == 0;
}

bool DirectoryExists(const std::string &directory_path) {
  struct stat info;
  return stat(directory_path.c_str(), &info) == 0 && (info.st_mode & S_IFDIR);
}

std::vector<std::string> ListSubPaths(const std::string &directory_path,
                                                                               const bool remove_extension) {
  std::vector<std::string> result;
  DIR *directory = opendir(directory_path.c_str());
  if (directory == nullptr) {
    std::cout << "Cannot open directory " << directory_path;
    return result;
  }

  struct dirent *entry;
  while ((entry = readdir(directory)) != nullptr) {
    // Skip "." and "..".
    if (strcmp(entry->d_name, ".") != 0 &&
        strcmp(entry->d_name, "..") != 0) {
      std::string name(entry->d_name);
      std::string file_name;

      if (remove_extension) {
        size_t end = name.find_last_of(".");

        if (end != std::string::npos) {
          const auto len = (end != std::string::npos) ? end - 0 : end;
          file_name = name.substr(0, len);
        }
      } else {
        file_name = name;
      }

      result.emplace_back(file_name);
    }
  }
  closedir(directory);
  return result;
}

}  // namespace file_util