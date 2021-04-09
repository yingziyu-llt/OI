#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <cmath>

using namespace std;

char s[1000];
int  g_pos;  // ?????????¡À?

             /* ???????? */
double Translation(int & pos)
{
    double integer = 0.0;    // ????????
    double remainder = 0.0;  // ????????

    while (s[pos] >= '0' && s[pos] <= '9')
    {
        integer *= 10;
        integer += (s[pos] - '0');
        pos++;
    }

    if (s[pos] == '.')
    {
        pos++;
        int c = 1;
        while (s[pos] >= '0' && s[pos] <= '9')
        {
            double t = s[pos] - '0';
            t *= pow(0.1, c);
            c++;
            remainder += t;
            pos++;
        }
    }

    return integer + remainder;
}

/* ????????????? */
int GetLevel(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '(':
        return 0;
    case '#':
        return -1;
    };
}

/* ???????????????? */
double Operate(double a1, char op, double a2)
{
    switch (op)
    {
    case '+':
        return a1 + a2;
    case '-':
        return a1 - a2;
    case '*':
        return a1 * a2;
    case '/':
        return a1 / a2;
    };
}

/* ??????????????????? */
double Compute()
{
    stack<char> optr;    // ???????
    stack<double> opnd;  // ???????

    optr.push('#');
    int len = strlen(s);
    bool is_minus = true;  // ?§Ø?'-'???????????

    for (g_pos = 0; g_pos < len;)
    {
        //1. ????  
        if (s[g_pos] == '-' && is_minus)  // ?????
        {
            opnd.push(0);
            optr.push('-');
            g_pos++;
        }
        //2. ???????? ) 
        else if (s[g_pos] == ')')
        {
            is_minus = false;
            g_pos++;

            while (optr.top() != '(')
            {
                double a2 = opnd.top();
                opnd.pop();
                double a1 = opnd.top();
                opnd.pop();
                char op = optr.top();
                optr.pop();

                double result = Operate(a1, op, a2);
                opnd.push(result);
            }

            optr.pop();  // ???'('  
        }
        //3. ????  
        else if (s[g_pos] >= '0' && s[g_pos] <= '9')
        {
            is_minus = false;
            opnd.push(Translation(g_pos));
        }
        //4. ( ??????  
        else if (s[g_pos] == '(')
        {
            is_minus = true;
            optr.push(s[g_pos]);
            g_pos++;
        }
        //5. + - * / ????  
        else
        {
            while (GetLevel(s[g_pos]) <= GetLevel(optr.top()))
            {
                double a2 = opnd.top();
                opnd.pop();
                double a1 = opnd.top();
                opnd.pop();
                char op = optr.top();
                optr.pop();

                double result = Operate(a1, op, a2);
                opnd.push(result);
            }

            optr.push(s[g_pos]);
            g_pos++;
        }
    }

    while (optr.top() != '#')
    {
        double a2 = opnd.top();
        opnd.pop();
        double a1 = opnd.top();
        opnd.pop();
        char op = optr.top();
        optr.pop();

        double result = Operate(a1, op, a2);
        opnd.push(result);
    }

    return opnd.top();
}

int main()
{
    while (cin >> s)
        cout << "??????" << Compute() << endl << endl;

    return 0;
}


