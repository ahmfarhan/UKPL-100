#include <iostream>
#include <string>

enum State {
  STATE_LOGIN,
  STATE_MENU,
  STATE_BLOCKED
};

class StateMachine {
public:
  StateMachine() {
    currentState = STATE_LOGIN;
    loginAttempts = 0;
  }

  void setInput(const std::string& username, const std::string& password) {
    this->username = username;
    this->password = password;
  }

  void transition() {
    
    switch (currentState) {
      case STATE_LOGIN:
        if (username == "admin" && password == "password") {
          loginAttempts = 0;
          currentState = STATE_MENU;
        } else {
          loginAttempts++;
          std::cout << "Your Username or Password is invalid. Try again!" << std::endl;
          std::cout << "Login attempts : "<< (loginAttempts) << std::endl;
          if (loginAttempts >= 2) {
            currentState = STATE_BLOCKED;
          }
        }
        break;

      case STATE_MENU:
        std::cout << "Do something in the system menu" << std::endl;
        currentState = STATE_LOGIN;
        break;

      case STATE_BLOCKED:
        std::cout << "Your account has been blocked!" << std::endl;
        break;

      default:
        std::cout << "Invalid state" << std::endl;
        break;
    }
  }

  State getCurrentState() const {
    return currentState;
  }

private:
  State currentState;
  std::string username;
  std::string password;
  int loginAttempts;
};

int main() {
  StateMachine sm;

  while (true) {
    std::string username;
    std::string password;
    //system("cls");
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    sm.setInput(username, password);
    sm.transition();

    if (sm.getCurrentState() == STATE_BLOCKED) {
      std::cout << "You have reached maximum of login attempts" << std::endl;
      std::cout << "Please contact the system administrator" << std::endl;
      break;
    } else if (sm.getCurrentState() == STATE_MENU) {
      std::cout << "Welcome to the system!" << std::endl;
      break;
    }
  }

  return 0;
}
