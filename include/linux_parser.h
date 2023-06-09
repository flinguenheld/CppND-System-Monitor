#ifndef LINUX_PARSER_H
#define LINUX_PARSER_H

#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using std::string;
using std::vector;

namespace LinuxParser {

    // Paths
    const string kProcDirectory{"/proc/"};
    const string kCmdlineFilename{"cmdline"};
    const string kCpuinfoFilename{"cpuinfo"};
    const string kStatusFilename{"status"};
    const string kStatFilename{"stat"};
    const string kUptimeFilename{"uptime"};
    const string kMeminfoFilename{"meminfo"};
    const string kVersionFilename{"version"};
    const string kOSPath{"/etc/os-release"};
    const string kPasswordPath{"/etc/passwd"};

    /*
     * Open the file with the <path>, find the first line starting with <grep> and cut it with the <delimiter>.
     * Then return all <desired fields>.
     * Set the <default_val> strings if grep failed or desired_field(s) failed.
     * Add ^ on the grep argument to search lines which start by <grep>.
     * Set an empty <delimiter> to take the entire line.
    */
    vector<string> parse(const string &path, string grep, vector<int> desired_fields,
                         string delimiter=" ", string default_val="");
    string parse(const string &path, string grep, int desired_field, string delimiter=" ", string default_val="");

    /* Overload for single line files. */
    vector<string> parse(const string &path, vector<int> desired_fields,
                         string delimiter=" ", string default_val="");
    string parse(const string &path, int desired_field, string delimiter=" ", string default_val="");

    /* Cut the given <line> with the <delimiter> and return all <desired_fields>. */
    vector<string> cut_line(string line, vector<int> desired_fields, string delimiter=" ", string default_val="");
    string cut_line(string line, int desired_field, string delimiter=" ", string default_val="");

};  // namespace LinuxParser

#endif
