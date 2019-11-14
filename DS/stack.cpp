#include<bits/stdc++.h>
#define SIZE 100

using namespace std;

int main() {
    int val, c, i;
    int stack[SIZE];
    int top = 0;
    int exit = 1;

    do {
        cin>>c;
        switch (c) {
            case 1:
                if (top == SIZE)
                    cout << "\nStack Full!";
                else {
                    cin>>val;
                    stack[top++] = val;
                }
                break;
            case 2:
                if (top == 0)
                    cout << "\nStack Empty!";
                else {
                    --top;
                }
                break;
            case 3:
                cout<<"------------"<<endl;
                for (i = (top - 1); i >= 0; i--)
                {
                  cout << stack[i] << endl;
                }
                cout << "--------------"<<endl;
                break;
            default:
                exit = 0;
                break;
        }
    } while (exit);
    return 0;
}
