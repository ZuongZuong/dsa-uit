#include <fstream>
#include <iostream>
#include "json.hpp"
using json = nlohmann::json;

std::string linear_search(json dictionary, std::string target)
{
    for (const auto &[key, value] : dictionary.items())
    {
        if (key == target)
        {
            return value["meaning"];
        }
    }
    return "";
}

std::string binary_search(const json &dictionary, const std::string &target)
{
    std::vector<std::string> keys;
    for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
        keys.push_back(it.key());

    int left = 0;
    int right = static_cast<int>(keys.size()) - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        const std::string &k = keys[mid];
        if (k == target)
        {
            const auto &entry = dictionary.at(k);
            if (entry.is_object() && entry.contains("meaning"))
                return entry["meaning"].get<std::string>();
            return "";
        }
        if (k < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return "";
}

int main()
{
    std::ifstream json_file("dictionary.json");
    json dictionary = json::parse(json_file);

    std::string result = linear_search(dictionary, "nam");
    if (!result.empty())
    {
        std::cout << "Found: " << result << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }

    std::string result2 = binary_search(dictionary, "nam");
    if (!result2.empty())
    {
        std::cout << "Found: " << result2 << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}