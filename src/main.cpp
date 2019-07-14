#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"

int main() {
	// 書き込みサンプル
	{
		std::vector<std::string> vec = { "hoge", "fuga", "piyo" };

		YAML::Node param;
		param["param1"] = vec[0];
		param["param2"] = vec[1];
		param["param3"] = vec[2];

		YAML::Emitter out;
		out << param;

		std::ofstream ofs("param.yaml");
		ofs << out.c_str();
		ofs.close();
	}

	// 読み込みサンプル
	{
		YAML::Node param = YAML::LoadFile("param.yaml");
		std::cout << "param1: " << param["param1"] << std::endl;
		std::cout << "param2: " << param["param2"] << std::endl;
		std::cout << "param3: " << param["param3"] << std::endl;
	}

	return 0;
}