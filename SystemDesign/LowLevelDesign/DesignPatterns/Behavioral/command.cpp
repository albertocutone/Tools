// Command is behavioral design pattern that converts requests or simple operations into objects.


#include <iostream>
#include <cstring>


class Command {
    public:
    virtual ~Command();
    virtual void Execute() const = 0;
};

class SimpleCommand : public Command {
  private:
    std::string payload_;
  public:
    explicit SimpleCommand(std::string payload): payload_(payload){}
    void Execute() const override {
        std::cout << "SimpleCommand: See, I can do simple things like printing (" << this->payload_ << ")\n";
    }
};

class Receiver {
  public:
    void DoSomething(const std::string &a){
        std::cout << "Receiver: Working on (" << a << ".)\n";
    }
    void DoSomethingElse(const std::string &b) {
        std::cout << "Receiver: Also working on (" << b << ".)\n";
    }
};

class ComplexCommand: public Command {
  private:
    Receiver *receiver_;
    std::string a_;
    std::string b_;
  public:
    ComplexCommand(Receiver* receiver, std::string a, std::string b) :
        receiver_(receiver), a_(a), b_(b){}

    //Command delegates to receiver's methods
    void Execute() const override {
        std::cout << "ComplexCommand: Complex stuff should be done by a receiver object.\n";
        this->receiver_->DoSomething(this->a_);
        this->receiver_->DoSomethingElse(this->b_);
    }
};

//Sender, is associated with one or more commands. It send requests to commands.
class Invoker {
  private:
    Command *on_start_;
    Command *on_finish_;

  public:
    ~Invoker() {
        delete on_start_;
        delete on_finish_;
    }

    void SetOnStart(Command *command) {
        this->on_start_ = command;
    }
    void SetOnFinish(Command *command) {
        this->on_finish_ = command;
    }

    void DoSomethingImportant(){
        std::cout << "Invoker: Does anybody want something done before I begin?\n";
        if (this->on_start_) {
            this->on_start_->Execute();
        }
        std::cout << "Invoker: ...doing something really important...\n";
        std::cout << "Invoker: Does anybody want something done after I finish?\n";
        if (this->on_finish_) {
            this->on_finish_->Execute();
        }
    }
};

int main() {
    Invoker *invoker = new Invoker;
    invoker->SetOnStart(new SimpleCommand("Say Hi!"));
    Receiver *receiver = new Receiver;
    invoker -> SetOnFinish(new ComplexCommand(receiver, "Send email","Save report"));

    delete invoker;
    delete receiver;

    return 0;
}
