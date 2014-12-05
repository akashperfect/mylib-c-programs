#include <iostream>
#include <sstream>
#include <list>
#include <stack>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>

const int LEFT_ASSOC  = 0;
const int RIGHT_ASSOC = 1;

using namespace std;

map< string, pair< int,int > > OpMap;
list< string > out;

// Test if token is an operator
bool isOperator(string token)
{
    return token == "+" || token == "-" ||
           token == "*" || token == "/";
}

// Test associativity of operator token
bool isAssociative( string token, int type)
{
    // Get type
    pair<int,int> p = OpMap.find( token )->second;

    if (p.second == type)
    {
        return true;
    }

    return false;
}



// Compare precedence of operators.
int cmpPrecedence( string token1, string token2)
{
    pair<int,int> p1 = OpMap.find( token1 )->second;
    pair<int,int> p2 = OpMap.find( token2 )->second;

    return p1.first - p2.first;
}


// Convert infix expression format into reverse Polish notation
void infixToRPN( vector<string> inputTokens, int size, vector<string>& strArray )
{
    list<string> out;
    stack<string> st;

    // For each token
    for ( int i = 0; i < size; i++ )
    {
        std::string token = inputTokens[ i ];
        // If token is an operator
        if (isOperator(token))
        {
            // While stack not empty AND stack top element
            // is an operator
            while ( !st.empty() && isOperator(st.top() ) )
            {
                if ( ( isAssociative( token, LEFT_ASSOC )       &&
                        cmpPrecedence( token, st.top() ) <= 0 ) ||
                    ( isAssociative( token, RIGHT_ASSOC )       &&
                        cmpPrecedence( token, st.top() ) < 0) )
                {
                    string str = (string) st.top();
                    st.pop();
                    out.push_back( str );
                    continue;
                }
                break;
            }

            // Push the new operator on the stack
            st.push(token);
        }
        // If token is a left bracket '('
        else if ( token == "(" )
        {
            // Push token to top of the stack
            st.push(token);
        }
        // If towken is a right bracket ')'
        else if ( token == ")" )
        {
            while ( !st.empty() && st.top() != "(" )
            {
                // Add to end of list
                out.push_back( st.top() );
                st.pop();
            }
            st.pop();
        }
        // If token is a number
        else
        {
            out.push_back( token );
        }
    }
    while ( !st.empty() )
    {
        out.push_back( st.top() );
        st.pop();
    }

    list<string>::iterator it = out.begin();

    for ( ; it != out.end(); ++it )
    {
        strArray.push_back( *it );
    }
}


double RPNtoDouble( vector<string> tokens )
{
    stack<string> st;

    // For each token
    for ( int i = 0; i < (int)tokens.size(); ++i )
    {
        string token = tokens[ i ];

        // If the token is a value push it onto the stack
        if ( !isOperator(token) )
        {
            st.push(token);
        }
        else
        {
            // Token is an operator: pop top two entries
            string val2 = st.top();
            st.pop();
            double d2 = strtod( val2.c_str(), NULL );

            string val1 = st.top();
            st.pop();
            double d1 = strtod( val1.c_str(), NULL );

            //Get the result
            double result = token == "+" ? d1 + d2 :
                            token == "-" ? d1 - d2 :
                            token == "*" ? d1 * d2 :
                                           d1 / d2;

            // Push result onto stack
            std::ostringstream s;
            s << result;
            st.push( s.str() );
        }
    }

    string val = st.top();
    return strtod( val.c_str(), NULL );
}


int main()
{
    OpMap[ "+" ] = pair<int,int>( 0, LEFT_ASSOC );
    OpMap[ "-" ] = pair<int,int>( 0, LEFT_ASSOC );
    OpMap[ "*" ] = pair<int,int>( 5, LEFT_ASSOC );
    OpMap[ "/" ] = pair<int,int>( 5, LEFT_ASSOC );
    char *s,*s1;int i,j=0;
    s = (char*)malloc(1000*sizeof(char));
    s1 = (char*)malloc(1000*sizeof(char));
    scanf("%s",s);
    s1[j++] = ' ';
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/')
        s1[j++] = s[i];
        else
        {s1[j++] = ' ';
        s1[j++] = s[i];
        s1[j++] = ' ';}
    }
    s1[j++] = ' ';
    //printf("%s\n",s1);
    istringstream iss( s1 );

    vector<string> tokens;
    vector<string> rpn;

    copy( istream_iterator<string>(iss),
          istream_iterator<string>(),
          back_inserter<vector<string> >(tokens) );

    infixToRPN( tokens, tokens.size(), rpn );


    double d = RPNtoDouble( rpn );
    int d1 = d;
    printf("%d\n",d1);

    return 0;
}
