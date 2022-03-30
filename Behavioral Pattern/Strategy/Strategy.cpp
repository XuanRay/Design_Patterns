/* Strategy
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */

/* 设计模式之策略模型
 *
 * 策略模型：隶属于behavioural Model : 一个类的行为或算法可以在运行时改变。
 * 创建表示各种策略的对象和一个行为随着策略对象改变而改变的context对象。
 * 
 * 场景：如一个系统需要在多个算法中选择一种。
 * 
 */

#include <iostream>


/** Strategy
 *  
 *  对所有的算法声明一个通用的接口
 */
class Strategy {
public:
    virtual ~Strategy() {}

    virtual void AlgorithmInterface() = 0;
    //...
};


/** ConcreteStrategyA
 *   
 *  具体算法类
 */
class ConcreteStrategyA : public Strategy {
public:
    virtual ~ConcreteStrategyA() {}

    void AlgorithmInterface() {
        std::cout << "Using Algorithm a" << std::endl;
    }
    //...
};



/** ConcreteStrategyB
 *   
 *  具体算法类
 */
class ConcreteStrategyB : public Strategy {
public:
    virtual ~ConcreteStrategyB() {}

    void AlgorithmInterface() {
        std::cout << "Using Algorithm b" << std::endl;
    }
    //...
};


/** Context
 * 
 *  contains a reference to a Strategy object.
 */
class Context {
private:
    Strategy* strategy;

public:
    ~Context() {
       delete strategy; 
    }

    Context(Strategy* s) : strategy(s) {}

    void ContextInterface() {
        this->strategy->AlgorithmInterface();
    }
    //...
};


/* for test */
int main() {
    Context context(new ConcreteStrategyA());
    context.ContextInterface();

    Context context1(new ConcreteStrategyB());
    context1.ContextInterface();

    return 0;
}