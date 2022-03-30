/* Singleton
 * Author: Rayss
 * Blog: https://www.cnblogs.com/rayss
 * 2022 
 */

/**
 * 现代较少用的模式：Builder, Mediator, Memento, Iterator, Chain of Responsibility, 
 *                Command, Visitor, Interpreter
 */


#include <iostream> 

/** 构建型模式之单例模式(Singleton)
    1. 在一个程序中，确保一个类只有唯一的一个实例；
    2. 提供访问这个实例的全局接入点。

    使用场景：
    1. 比如在某个服务器程序中，该Server的配置信息存放在一个文件中，这些配置信息
    由一个单例对象统一读取，其他对象再通过该单例对象获取这些配置信息，简化管理；
    2. 数据库连接池；
    3. 多线程线程池；
    4. OS的文件系统。

    单例模式一般用在有共享资源的情况下，但是需要小心。比如多线程场景下，两个线程同时创建这个实例（可以考虑加互斥锁）。
*/

class Singleton {
public:
    static Singleton* get_instance() { // interface
        if (!instance) {
            return new Singleton();
        }
        return instance;
    }
    
    static void restart() {
        if (instance) {
            delete instance;
        }
    }

    void test() {
        std::cout << "This is a Singleton." << std::endl;
    }


private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton *instance;
    //...
};

// initialize
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton::get_instance()->test();
    Singleton::restart();

    return 0;
}
