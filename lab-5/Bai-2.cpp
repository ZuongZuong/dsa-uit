#include <iostream>
#include <stack>
using namespace std;

bool IsOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int PostFix(string postfix)
{
    stack<int> st;

    for (int i = 0;i < postfix.length();i++)
    {
        char x = postfix[i];

        if (!IsOperator(x))
        {
            st.push(x - '0');
        }
        else
        {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            switch (x)
            {
            case '+':
                st.push(a + b);
                break;

            case '-':
                st.push(a - b);
                break;

            case '*':
                st.push(a * b);
                break;

            case '/':
                st.push(a / b);
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    string s = "34+52-*";

    cout << PostFix(s);

    return 0;
}