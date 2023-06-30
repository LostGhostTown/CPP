#include"orderManage.h"

OrderFile::OrderFile(){
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string time;
	string id;
	string stuid;
	string state;

	this->size = 0;

	while (ifs >> date && ifs >> time && ifs >> id && ifs >> stuid && ifs >> state) {
		//测试
		//cout << date << endl << time << endl << id << endl << stuid << endl << state << endl;
		string key;
		string value;
		map<string, string>m;

		int pos = date.find(":");//找到“：”的位置
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - 1);
			m.insert(make_pair(key, value));
		}

		pos = time.find(":");//找到“：”的位置
		if (pos != -1) {
			key = time.substr(0, pos);
			value = time.substr(pos + 1, time.size() - 1);
			m.insert(make_pair(key, value));
		}

		pos = id.find(":");//找到“：”的位置
		if (pos != -1) {
			key = id.substr(0, pos);
			value = id.substr(pos + 1, id.size() - 1);
			m.insert(make_pair(key, value));
		}

		pos = stuid.find(":");//找到“：”的位置
		if (pos != -1) {
			key = stuid.substr(0, pos);
			value = stuid.substr(pos + 1, stuid.size() - 1);
			m.insert(make_pair(key, value));
		}

		pos = state.find(":");//找到“：”的位置
		if (pos != -1) {
			key = state.substr(0, pos);
			value = state.substr(pos + 1, state.size() - 1);
			m.insert(make_pair(key, value));
		}
		this->orderData.insert(make_pair(this->size, m));
		this->size++;
	}
	ifs.close();
	//测试
	for (map<int, map<string, string>>::iterator it = orderData.begin(); it != orderData.end(); it++) {
		cout << "条数=" << it->first << endl << "value =" << endl;
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != it->second.end(); mit++) {
			cout << "key=" << mit->first << endl << "value = " << mit->second << endl;
		}
	}
}
void OrderFile::update(){
	if (this->size == 0)return;
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->size; i++) {
		ofs << "date:" << this->orderData[i]["date"] << " ";
		ofs << "time:" << this->orderData[i]["time"] << " ";
		ofs << "id:" << this->orderData[i]["id"] << " ";
		ofs << "stuid:" << this->orderData[i]["stuid"] << " ";
		ofs << "state:" << this->orderData[i]["state"] << " ";
	}
}
bool OrderFile::check(string date, string time, string id,string stuid) {
	if (this->size == 0)return true;
	for (int i = 0; i < this->size; i++) {
		if (this->orderData[i]["id"] == id && this->orderData[i]["date"] == date && this->orderData[i]["time"] == time) { if(this->orderData[i]["state"] != "0"|| this->orderData[i]["state"] != "-1")return false; }
		if (this->orderData[i]["stuid"] == stuid) { if (this->orderData[i]["state"] != "0" || this->orderData[i]["state"] != "-1")return false; }
	}
	return true;
}