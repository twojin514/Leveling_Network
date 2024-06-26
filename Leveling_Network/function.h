#pragma once
#include <vector>
#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <locale>
#include <cctype>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <cctype>
#include <locale>
#include <iomanip>

struct Line
{
	int32_t  line_number;
	std::string id_to;
	std::string id_from;
	double elevation_difference;
	double standard_deviation;
};

struct Benchmark
{
	int32_t benchmark_number;
	std::string id;
	double elevation;
	double standard_deviation;
};

void ReadInputLineFile(std::string FileName, std::vector<Line>& lines_data);
void ReadInputBMFile(std::string FileName, std::vector<Benchmark>& benchmarks_data);
bool CompareStrings(const std::string& a, const std::string& b);
void SortInputData(std::vector<Line>& lines_data, std::vector<Benchmark>& benchmarks_data, int32_t& point_number, std::vector<std::string>& point_names);
void PrintLevelingProgram(std::ofstream& outfile, std::vector<Line>& lines_data, std::vector<Benchmark>& benchmarks_data, std::vector<std::vector<std::int32_t>>& a_matrix, std::vector<std::vector<std::string>>& x_matrix, std::vector<std::vector<double>>& l_matrix, std::vector<std::vector<double>>& w_matrix, std::vector<std::vector<double>>& atwa_matrix, std::vector<std::vector<double>>& atwl_matrix);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void SetXMatrix(std::vector<Line>& lines_data, std::vector<Benchmark>& benchmarks_data, int32_t& n_measurement_point, std::vector<std::string>& point_names, std::vector<std::vector<std::string>>& a_matrix);
void SetAMatrix(std::vector<Line>& lines_data, std::vector<Benchmark>& benchmarks_data, int32_t& m_observation_point, int32_t& n_measurement_point, std::vector<std::vector<std::string>>& x_matrix, std::vector<std::vector<std::int32_t>>& a_matrix);
void SetLMatrix(std::vector<Line>& lines_data, std::vector<Benchmark>& benchmarks_data, int32_t& m_observation_point, std::vector<std::vector<double>>& l_matrix);
void SetWMatrix(std::vector<Line>& lines_data, std::vector<Benchmark>& benchmarks_data, int32_t& m_observation_point, std::vector<std::vector<double>>& w_matrix);
void SetATWAMatrix(std::vector<Line>& lines_data, std::vector<Benchmark>& benchmarks_data, int32_t& n_measurement_point, std::vector<std::vector<int32_t>>& a_matrix,std::vector<std::vector<double>>& w_matrix, std::vector<std::vector<double>>& atwa_matrix);
void SetATWLMatrix(std::vector<Line>& lines_data, std::vector<Benchmark>& benchmarks_data, int32_t& n_measurement_point, std::vector<std::vector<int32_t>>& a_matrix, std::vector<std::vector<double>>& w_matrix, std::vector<std::vector<double>>& l_matrix, std::vector<std::vector<double>>& atwl_matrix);
void VectoMatrix(std::vector<std::vector<double>>& matrix, cv::Mat& mat);
void VectoMatrix(std::vector<std::vector<int32_t>>& matrix, cv::Mat& mat);