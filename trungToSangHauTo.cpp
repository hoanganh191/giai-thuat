#include <iostream>
#include <stack>
#include <cctype>
#include <string>

using namespace std;

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

string infixToPostfix(string infix){
    stack<char> opStack;
    string postfix = "";
    for(char ch : infix){
        if (isalnum(ch))
        {
            postfix += ch;
        } else if(ch == '('){
            opStack.push(ch);
        } else if(ch == ')'){
            while (!opStack.empty() && opStack.top() != '(')
            {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop();
        } else {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(ch) )
            {
                postfix += opStack.top();
                opStack.pop();
            }

            opStack.push(ch);
            
        }
        
    }

    while (!opStack.empty())
    {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
    
}

int main(){
    string infix;
    cout << "Nhap bieu thuc trung to : ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Bieu thuc co dang la : " << postfix << endl;
}

