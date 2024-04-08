bool customCompare(const std::string& str1, const std::string& str2) {
    // 比较前两位字母的字母序
    if (str1.substr(0, 2) != str2.substr(0, 2)) {
        return str1.substr(0, 2) < str2.substr(0, 2);
    }

    // 若前两位字母相同，比较后4位数字
    return str1.substr(2) < str2.substr(2);
}//飞机排序