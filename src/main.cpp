#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"

// key-value�`���̏������݃T���v��
void mapSample() {
	// �������݃T���v��
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

	// �ǂݍ��݃T���v��
	{
		YAML::Node param = YAML::LoadFile("param1.yaml");
		std::cout << "param1: " << param["param1"] << std::endl;
		std::cout << "param2: " << param["param2"] << std::endl;
	}
}

// �z����g�p�����
void arraySample() {
	// �������݃T���v��
	{
		std::vector<std::string> vec1 = { "hoge", "fuga", "piyo" };
		std::vector<std::string> vec2 = { "hogehoge", "fugafuga", "piyopiyo" };

		YAML::Emitter out;
		out << YAML::BeginMap;
		out << YAML::Key << "key";
		out << YAML::Value;
		out << YAML::BeginSeq;	// �z��J�n
		out << YAML::Flow << vec1;
		out << YAML::Flow << vec2;
		out << YAML::EndSeq;	// �z��I��
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