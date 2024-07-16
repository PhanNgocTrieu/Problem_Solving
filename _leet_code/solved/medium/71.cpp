/*
    https://leetcode.com/problems/simplify-path/description/
*/
string simplifyPath(string path) {
    stack<string> cs;
    cs.push("/");
    string tmp = "";
    for (char c : path) {
        // debug(c);
        if (c == '/') {
            if (cs.top()[0] == '/' && tmp == "") {
                // debug("not including");
            }
            else if (tmp == ".") {
                // debug("...");
            }
            else if (tmp == "..") {
                if (cs.size() > 1) cs.pop();
                if (cs.size() > 1) cs.pop();
            } 
            else if (tmp != "/") {
                cs.push(tmp);
                cs.push(string(1, '/'));
            }
            tmp = "";
        }
        else {
            tmp += c;
        }
        // debug(tmp);
    }

    if (!tmp.empty() && tmp != "/" && tmp != ".") {
        if (tmp == "..") {
            if (cs.size() > 1) cs.pop();
            if (cs.size() > 1) cs.pop();
        }
        else {
            cs.push(tmp);
        }
    }

    vector<string> _result;
    while (!cs.empty()) {
        auto _v = cs.top();
        _result.push_back(_v);
        cs.pop();
    }
    reverse(_result.begin(), _result.end());
    // debugv(_result);
    
    string ans = "";
    for (auto r : _result) {
        ans += r;
    }
    // debug(ans);
    // debug(ans.substr(0, ans.length() - 1));

    return ans[ans.length() - 1] == '/' && ans.size() > 1 ? ans.substr(0, ans.length() - 1) : ans;
}
