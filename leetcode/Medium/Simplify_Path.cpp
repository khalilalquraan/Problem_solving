class Solution {
public:
    string simplifyPath(string path)
    {
        vector<string> dName;
        string tmp = "";
        path += '/';
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/' && tmp != ".." && tmp != "" && tmp != ".") {
                dName.push_back(tmp);
                tmp = "";
            }
            else if (path[i] == '/' && tmp == ".") {
                tmp = "";
            }
            else if (path[i] == '/' && tmp == "..") {
                if (dName.size() > 0)
                    dName.pop_back();
                tmp = "";
            }
            else if (path[i] != '/')
                tmp += path[i];
        }
        string ans = "";
        for (auto i : dName)
            ans += "/" + i;
        return (ans == "" ? "/" : ans);
    }
};