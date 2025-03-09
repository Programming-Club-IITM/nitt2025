#include <iostream>
using namespace std;

/* Implement the Stack Interface */
template <typename T>
class Stack {
    private:
        T arr[1000];
        int stack_size;
        int curr_position;
    
    public:
        Stack() {
            // Initialize the stack
            stack_size = 1000;
            curr_position = -1;
        }

        T top_element() {
            // Return the top element of the stack
            if (curr_position >= 0) {
                return arr[curr_position];
            }
            throw runtime_error("Stack is empty");
        }

        void push_element(T element) {
            // Add an element to the stack
            if (curr_position + 1 < stack_size) {
                arr[++curr_position] = element;
            } else {
                throw runtime_error("Stack overflow");
            }
        }

        void pop_element() {
            // Remove the top element of the stack
            if (curr_position >= 0) {
                curr_position--;
            } else {
                throw runtime_error("Stack underflow");
            }
        }

        int current_size() {
            // Return the number of elements in the stack
            return curr_position + 1;
        }

        bool is_empty() {
            // Check if the stack is empty
            return curr_position == -1;
        }
};
/* DO NOT CHANGE ANY CODE BELOW THIS LINE */

// Function to return precedence of operators
int precedence(char c) {
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// Function to return associativity of operators
char associativity(char c) {
	if (c == '^')
		return 'R';
	return 'L'; // Default to left-associative
}

// The main function to convert infix expression
// to postfix expression
string infixToPostfix(string s) {
	Stack<char> ele_stack;
	string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		// If the scanned character is
		// an operand, add it to the output string.
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;

		else if (c == '(')
			ele_stack.push_element('(');

		else if (c == ')') {
			while (ele_stack.top_element() != '(') {
				result += ele_stack.top_element();
				ele_stack.pop_element();
			}
			ele_stack.pop_element(); // Pop '('
		}

		// If an operator is scanned
		else {
			while (!ele_stack.is_empty() && precedence(s[i]) < precedence(ele_stack.top_element()) ||
				!ele_stack.is_empty() && precedence(s[i]) == precedence(ele_stack.top_element()) &&
				associativity(s[i]) == 'L') {
				result += ele_stack.top_element();
				ele_stack.pop_element();
			}
			ele_stack.push_element(c);
		}
	}

	// Pop all the remaining elements from the stack
	while (!ele_stack.is_empty()) {
		result += ele_stack.top_element();
		ele_stack.pop_element();
	}
    return result;
}

// Function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
    /*
    ( -> 1
    { -> 2
    [ -> 3    
    */

    // Declare a stack to hold the previous brackets.
    Stack<int> encoding_stack;
    for (int i = 0; i < expr.size(); i++) {
        if (encoding_stack.is_empty()) {
             
            // If the stack is empty 
            // just push the encoding of current bracket
            if(expr[i] == '(') encoding_stack.push_element(1);
            else if(expr[i] == '{') encoding_stack.push_element(2);
            else if(expr[i] == '[') encoding_stack.push_element(3);
            else return false;
        }
        else if ((encoding_stack.top_element() == 1 && expr[i] == ')')
                 || (encoding_stack.top_element() == 2 && expr[i] == '}')
                 || (encoding_stack.top_element() == 3 && expr[i] == ']')) {
             
            // If we found any complete pair of bracket
            // then pop
            encoding_stack.pop_element();
        }
        else {
            if(expr[i] == '(') encoding_stack.push_element(1);
            else if(expr[i] == '{') encoding_stack.push_element(2);
            else if(expr[i] == '[') encoding_stack.push_element(3);
            else return false;
        }
    }
    if (encoding_stack.is_empty()) {
         
        // If stack is empty return true
        return true;
    }
    return false;
}
 
// Driver code
int main() {
	string infix;
    cin >> infix;

	// Function call
	string postfix = infixToPostfix(infix);
    cout << "Postfix is " << postfix << endl;

    string expr;
    cin >> expr;
    // Function call
    if (areBracketsBalanced(expr)){
        cout << "The string " << expr << " is Balanced" << endl;
    }
    else{
        cout << "The string " << expr << " is Not Balanced" << endl;
    }

	return 0;
}
