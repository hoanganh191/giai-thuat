#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

float giaTriHauTo(string bieuThuc){
    stack<float> numberStack;
    for(char x : bieuThuc){
        if (isdigit(x))
        {
            numberStack.push(x-'0');
        } 
        
        else if (numberStack.size() > 1)
        {
            float y = numberStack.top();
            numberStack.pop();
            float z = numberStack.top();
            numberStack.pop();
            float w;
            switch (x)
            {
            case '+':
                w = z + y;
                break;
            case '-':
                w = z - y;
                break;
            case '*':
                w = z*y;
                break;
            case '/':
                if (y == 0)
                {
                    cout << "Bieu thuc loi";
                    return 0;
                }
                w = z/y;
                break;
            default:
                cout << "Bieu thuc nhap bi loi";
                return 0;
                break;
            }

            numberStack.push(w);
        } else {
            cout << "Bieu thuc sai";
            return 0;
        }

        
    }

    return numberStack.empty() ? 0 : numberStack.top();
}

int main(){
    string bieuThuc = "573-/215+*+";
    cout << "Giá trị biểu thức hậu tố: " << giaTriHauTo(bieuThuc) << endl;
    return 0;
}

