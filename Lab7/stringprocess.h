#ifndef STRING_PROCESSOR_H
#define STRING_PROCESSOR_H

#include <iostream>
#include <stack>
#include <string>
using namespace std;


class StringProcessor {
public:
    static string processString(const string &input) {
        stack<char> st;

        for (char ch : input) {
            if (ch == '+') {
                if (!st.empty()) {
                    st.pop();  // Remove the last valid character
                }
            } else {
                st.push(ch);
            }
        }

        // Construct the final processed string
        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};

#endif // STRING_PROCESSOR_H
