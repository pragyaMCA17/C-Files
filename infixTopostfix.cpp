#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>


using namespace std;

//char stack
stack<char> optr;

//to give weights to operators
int Precedence(char op)
{
    switch(op)
    {
    case '/' :
        return 4;
    case '*' :
        return 3;
    case '+' :
        return 2;
    case '-' :
        return 1;
    }

}

//to check the precedence
inline bool hasPrecedence(char op1,char op2)
{
    if(Precedence(op1)>Precedence(op2))
       return true;
    else {return false;}
}


//check for all opening brackets { [ (
inline bool isOpening(char opr)
{
    if(opr=='('||opr=='{'||opr=='[')
        return true;
    else {return false;}
}


//check for all closing brackets }])
inline bool isClosing(char opr)
{
    if(opr==')'||opr=='}'||opr==']')
        return true;
    else {return false;}
}


//to covert from infix to postfix notation using stack
void infixTOpostfix(string expr)
{
    string resExp="";

    for(int i=0;i<expr.size();i++)
    {
        if(isdigit(expr[i]))
           {resExp+=expr[i];}

        else if(isOpening(expr[i]))
            {optr.push(expr[i]);}

        else if(isClosing(expr[i]))
        {
            while(!optr.empty() && !isOpening(optr.top()))
            {
                resExp+=optr.top();
                optr.pop();
            }
            optr.pop();
        }
        else
        {
            while(!optr.empty() && !isOpening(optr.top()) && hasPrecedence(optr.top(),expr[i]))
               {

                resExp+=optr.top();
                optr.pop();
               }
            optr.push(expr[i]);
        }

    }
    while(!optr.empty())
    {
        resExp+=optr.top();
        optr.pop();
    }

    cout<<endl<<endl<<"Postfix String Notation: "<<resExp;
}

int main()
{
    string exprsn;
    cout<<"Enter the string :";
    getline(cin,exprsn);

    infixTOpostfix(exprsn);

    return 0;

}
