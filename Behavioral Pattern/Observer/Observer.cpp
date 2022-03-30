/* Observer
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */

/* 设计模式之观察者模式
 *
 * 观察者模型：隶属于behavioural Model。
 * 对象间一对多的关系，一个对象发生状态变化，通知其他所有对象。在抽象类里有一个列表存放着所有的观察者们。
 * 
 * 场景：如拍卖的时候，拍卖师观察最高竞价，然后通知给其他竞价这竞价。
 * 
 */

#include <iostream>
#include <vector>


class Subject; /* 管理观察者们的类 */


/* 观察者对象的接口 */
class Observer {
public:
    virtual ~Observer() {}

    virtual int getState() = 0;
    virtual void update(Subject* subject) = 0;
    //...
};

/* 具体的观察者 */
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(int s) : observer_state(s) {}

    ~ConcreteObserver() {}

    int getState() {
        return this->observer_state;
    }

    void update(Subject *subject); /* 实现在后面 */

private:
    int observer_state;
};


/*  管理观察者们的对象  */
class Subject {
public:
    virtual ~Subject() {}

    void attach(Observer* ob) {
        observers.push_back(ob);
    }

    void detach(const int index) {
        observers.erase(observers.begin() + index);
    } 

    void notify() {
        for (int i = 0; i < observers.size(); ++i) {
            observers[i]->update(this);
        }
    }

    virtual int getState() = 0;
    virtual void setState(const int state) = 0;

private:
    std::vector<Observer*> observers;
};


/* 具体的subject */
class ConcreteSubject : public Subject {
public:
    virtual ~ConcreteSubject() {}

    int getState() {
        return subject_state;
    }

    void setState(const int state) {
        this->subject_state = state;
    }

private:
    int subject_state;
    //...
};


void ConcreteObserver::update(Subject* subject) {
    observer_state = subject->getState();
    std::cout << "observer state updated." << std::endl;
}


/* for test */
int main() {
    ConcreteObserver observer1(1);
    ConcreteObserver observer2(2);

    std::cout << "observer1 state is " << observer1.getState() << std::endl;
    std::cout << "observer2 state is " << observer2.getState() << std::endl;

    Subject *subject = new ConcreteSubject();
    subject->attach(&observer1);
    subject->attach(&observer2);

    subject->setState(observer1.getState());
    subject->notify();

    std::cout << "observer1 state is " << observer1.getState() << std::endl;
    std::cout << "observer2 state is " << observer2.getState() << std::endl;

    delete subject;

    return 0;
}