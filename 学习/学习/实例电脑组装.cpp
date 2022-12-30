#include<iostream>
using namespace std;
#include<string>
//抽象cpu
class CPU{
public:
	virtual void cal() = 0;
};
class GPU {
public:
	virtual void display() = 0;
};
class RAM {
public:
	virtual void store() = 0;
};
class Computer {
public:
	//初始化函数
	Computer(CPU* cpu, GPU* gpu, RAM* ram) {
		this->cpu = cpu;
		this->gpu = gpu;
		this->ram = ram;
	}
	//工作函数
	void work() {
		cpu->cal();
		gpu->display();
		ram->store();
	}
	~Computer() {
		if (cpu != NULL) {
			delete cpu;
			cpu = NULL;
		}
		if (gpu != NULL) {
			delete gpu;
			gpu = NULL;
		}
		if (ram != NULL) {
			delete ram;
			ram = NULL;
		}
	}
private:
	CPU* cpu;
	GPU* gpu;
	RAM* ram;
};
//厂商
//intel
class IntelCPU : public CPU {
	void cal() {
		cout << "Intel的cpu开始工作" << endl;
	}
};
class IntelGPU : public GPU {
	void display() {
		cout << "Intel的gpu开始工作" << endl;
	}
};
class IntelRAM : public RAM {
	void store() {
		cout << "Intel的ram开始工作" << endl;
	}
};
//lenovo
class LenovoCPU : public CPU {
	void cal() {
		cout << "Lenovo的cpu开始工作" << endl;
	}
};
class LenovoGPU : public GPU {
	void display() {
		cout << "Lenovo的gpu开始工作" << endl;
	}
};
class LenovoRAM : public RAM {
	void store() {
		cout << "Lenovo的ram开始工作" << endl;
	}
};
void test01() {
	//第一台电脑
	CPU* intelcpu = new IntelCPU;
	GPU* intelgpu = new IntelGPU;
	RAM* intelram = new IntelRAM;
	Computer* PC1 = new Computer(intelcpu, intelgpu, intelram);
	PC1->work();
	delete PC1;
	Computer* PC2 = new Computer(new LenovoCPU, new LenovoGPU, new LenovoRAM);
	PC2->work();
	delete PC2;
	Computer* PC3 = new Computer(new LenovoCPU, new IntelGPU, new LenovoRAM);
	PC3->work();
	delete PC3;
}
int main() {
	test01();
	return 0;
}