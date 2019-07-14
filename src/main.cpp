#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"

// key-value形式の書き込みサンプル
void mapSample() {
	// 書き込みサンプル
	{
		YAML::Emitter out;
		//out << param;
		out << YAML::BeginMap;
		out << YAML::Key << "param1";
		out << YAML::Value << "hoge";
		out << YAML::Key << "param2";
		out << YAML::Value << "fuga";
		out << YAML::EndMap;

		std::ofstream ofs("param1.yaml");
		ofs << out.c_str();
		ofs.close();
	}

	// 読み込みサンプル
	{
		YAML::Node param = YAML::LoadFile("param1.yaml");
		std::cout << "param1: " << param["param1"] << std::endl;
		std::cout << "param2: " << param["param2"] << std::endl;
	}
}

// 配列を使用する例
void arraySample() {
	// 書き込みサンプル
	{
		std::vector<std::string> vec1 = { "hoge", "fuga", "piyo" };
		std::vector<std::string> vec2 = { "hogehoge", "fugafuga", "piyopiyo" };

		YAML::Emitter out;
		out << YAML::BeginMap;
		out << YAML::Key << "key";
		out << YAML::Value;
		out << YAML::BeginSeq;	// 配列開始
		out << YAML::Flow << vec1;
		out << YAML::Flow << vec2;
		out << YAML::EndSeq;	// 配列終了
		out << YAML::EndMap;

		std::ofstream ofs("param2.yaml");
		ofs << out.c_str();
		ofs.close();
	}
}

int main() {
	mapSample();

	arraySample();

	return 0;
}