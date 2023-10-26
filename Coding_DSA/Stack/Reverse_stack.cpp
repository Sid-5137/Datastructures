#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> st;
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    for(int i=0;i<4;i++){
        int n = st.top();
        cout<<n<<endl;
        st.pop();
    }
}