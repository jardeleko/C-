#include <iostream>
#include <math.h>
#include <vector>
#include <set>
#include <map>
//my first code the of machine learning with a warnings haueha
using namespace std;

class Group{

private:
	string _class;
	double a, b, c, d;

public:
	Group(double a, double b, double c, double d, string group){
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->_class = _class;
	}

	string get_opt_result(){
		return this->_class;
	}
	
	double get_a(){
		return this->a;
	}
	double get_b(){
		return this->b;
	}
	double get_c(){
		return this->c;
	}
	double get_d(){
		return this->d;
	}
};
 
double get_distance(Group pt_1, Group pt_2){
	double sum;
	sum = (pow((pt_1.get_a() - pt_2.get_a()), 2) + 
		pow((pt_1.get_b() - pt_2.get_b()), 2) +
		pow((pt_1.get_c() - pt_2.get_c()), 2) +
		pow((pt_1.get_d() - pt_2.get_d()), 2)	
		);
	return sqrt(sum);
}

string checked_group(vector<Group>& samples, Group new_sample, int K){
	if(K % 2 == 0){
	 	K--;
		if(K <= 0)
			K = 1;
	}
	int size = samples.size(); //samples my individes 

	set<pair <double, int> > distance_clusters;
	
	for (int i = 0; i < size; ++i){
		double distance = get_distance(samples[i], new_sample);
		distance_clusters.insert(make_pair(distance, i));
	}			

	set<pair <double, int> >::iterator it;
	
	vector<int> count_clusters(3);
	int countK = 0;

	for (it = distance_clusters.begin(); it != distance_clusters.end(); it++){
		string groups = samples[it->second].get_opt_result();

		if(groups == "Iris-setosa") 
			count_clusters[0]++;
		else if(groups == "Iris-versicolor") 
			count_clusters[1]++;
		else 
			count_clusters[2]++;
		if(countK > K) break;
		
		countK++;
	}

	string output_request;

	if(count_clusters[0] >= count_clusters[1] && count_clusters[0] >= count_clusters[2])
		output_request = "Iris-setosa";
	else if(count_clusters[1] >= count_clusters[0] && count_clusters[1] >= count_clusters[2])
		output_request = "Iris-versicolor";
	else 
		output_request = "Iris-virginica";
	
	return output_request;
}

int main(void){

	vector<Group> samples;
	int K = 3;
	int size_request = 105;

	for (int i = 0; i < size_request; i++){
		string option;
		double a, b, c, d;
		cin >> a >> b >> c >> d >> option;
		
		samples.push_back(Group(a, b, c, d, option));
	}	
	
	int tests = 0;
	int size_tests = 150 - size_request;

	for (int i = 0; i < size_tests; ++i){
		string opt;
		double a, b, c, d;

		cin >> a >> b >> c >> d >> opt;

		Group sample(a, b, c, d, opt);

		string result_attemp = checked_group(samples, sample, K);

		cout << "expected: " << opt << "\n";
		cout << "return: " << result_attemp << endl ;
		

		if(opt == result_attemp) tests++;
	}
	printf("\n");
	cout << "hits: " << tests << "\nCount finally the attemps " << size_tests << "\n";
	printf("\n");

	return 0;
}