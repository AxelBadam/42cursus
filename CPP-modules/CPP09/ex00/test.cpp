#include <iostream>
#include <map>
#include <string>

int main() {
    // Creating a multimap with date strings as keys and some numeric values
    std::multimap<std::string, int> dateMultimap;
    dateMultimap.insert(std::make_pair("2021-01-01", 10));
    dateMultimap.insert(std::make_pair("2021-01-05", 20));
    dateMultimap.insert(std::make_pair("2021-01-05", 25)); // Note: Duplicate date
    dateMultimap.insert(std::make_pair("2021-01-10", 30));

    // Specified date to search for
    std::string searchDate = "2021-01-04";

    // Using lower_bound to find the first date not before the search date
    auto it = dateMultimap.lower_bound(searchDate);

    if (it != dateMultimap.end()) {
        // Found an entry
        std::cout << "Found date: " << it->first << " with value: " << it->second << std::endl;
    } else {
        // No entry found that meets or exceeds the search date
        std::cout << "No date found on or after " << searchDate << std::endl;
    }

    return 0;
}
