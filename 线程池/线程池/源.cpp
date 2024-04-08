#include<iostream>
#include<thread>//线程
#include<condition_variable>//wait()&notify
#include<mutex>//互斥锁
#include<string>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

class ThreadPool {
public:
	//构造
	// num  指要有多少个线程
	ThreadPool(int num) :stop(false) {
		for (int i = 0; i < num; i++) {
			threads.emplace_back([this] {//不能用pushback因为不能去拷贝而是直接在vector里构造新的
				while (1) {
					unique_lock<mutex>lock(mtx);
					condition.wait(lock, [this] {
						return !tasks.empty() || stop;
						});//teaks不为空或者不需要stop时 线程会wait
					if (stop && tasks.empty())return;//停止线程
					function<void()>task(move(tasks.front()));//move让tasks能作为右值 并将有值的所有移动到左值（右值会清空） 这里值将tesk变成tasks里的第一个任务
					tasks.pop();//拿到任务pop掉
					lock.unlock();//拿到任务取消锁
					task();//做任务
				}
				});//lambda
		}
	}
	//析构
	~ThreadPool() {
		{
			unique_lock<mutex>lock(mtx);
			stop = true;
		}//加锁确保所有线程的stop被正确修改
		condition.notify_all();
		for (auto& temp : threads) {
			temp.join();
		}
		system("pause");

	}
	template<class T,class ...Args>
	void enqueue(T&& t,Args&&... args) {//&&表示右值引用 如果是参数则是万能引用 随意调用左右值
		function<void()>task = bind(forward<T>(t), forward<Args>(args)...);//不用考虑参数 使用bind绑定参数 forward用来完美转发参数 不用考虑左右值
		{
			unique_lock<mutex>lock(mtx);
			tasks.emplace(move(task));
		}
		condition.notify_one();
	}
private:
	vector<thread>threads;
	queue < function<void()>>tasks;//即队列里的元素是没有返回值的函数
	mutex mtx;//锁
	condition_variable condition;
	bool stop;//什么时候终止
};

int main() {
	ThreadPool pool(4);//构造4线程的线程池
	for (int i = 0; i < 10; i++) {//加10个任务
		pool.enqueue([i] {//打印是乱的 因为任务本身没有锁
			cout << "task: " << i <<" start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "task: " << i << " is done" << endl;
			});
	}
	return 0;
}