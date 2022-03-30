/* State
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */

/* 设计模式之状态模式
 *
 * 状态模型：隶属于Behavioral Pattern。
 * 类的行为是根据它的状态改变的。
 * 
 * 场景：1.行为随状态改变而改变的场景；
 * 
 * note：状态一般不超过5个。
 * 
 */

#include <iostream>


/* 状态的抽象类 */
class State {
public:
    virtual ~State() {}

    virtual void handle() = 0;
    //...
};


/* 具体状态类 */
class ConcreteStateA : public State {
public:
    virtual ~ConcreteStateA() {}

    void handle() {
        std::cout << "State A handled." << std::endl;
    }
    //...
};

/* 具体状态类 */
class ConcreteStateB : public State {
public:
    virtual ~ConcreteStateB() {}

    void handle() {
        std::cout << "State B handled." << std::endl;
    }
    //...
};


/* Context 定义客户感兴趣的接口 */
class Context {
public:
    Context() : s(NULL) {}
    
    ~Context() {
        if (s)
            delete s;
    }

    void setState(State* s) {
        if (this->s) {
            delete this->s;
        }
        this->s = s;
    }

    void request() {
        if (this->s)
            s->handle();
        else 
            std::cout << "state is null." << std::endl;
    }
    //...

private:
    State *s;
};

/* for test */
int main() {
    Context* context = new Context();
    context->request();

    context->setState(new ConcreteStateA());
    context->request();
    context->setState(new ConcreteStateB());
    context->request();

    delete context;
    return 0;
}