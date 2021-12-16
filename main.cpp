#include <QCoreApplication>
#include <QDebug>

#include <vector>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
    int longest = 0;
    stack<pair<char, int>> data;

    for (int i=0; i<s.length(); i++){
        if (!data.empty()){
            if( data.top().first == '(' && s[i] == ')' ){
                data.pop();
                continue;
            }
            if((i-data.top().second-1)>longest)
                longest = i-data.top().second-1;
        } else{
            if(i>longest) longest=i;
        }
        data.push({s[i],i});
    }

    if(!data.empty()){
        if(s.length()-data.top().second-1 > longest ){
            longest = s.length()-data.top().second-1;
        }
    }else{
        longest = s.length();
    }

    return longest;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    qDebug() << longestValidParentheses("(()(())()");
    qDebug() << longestValidParentheses(")()())");
    qDebug() << longestValidParentheses("");

    return a.exec();
}

