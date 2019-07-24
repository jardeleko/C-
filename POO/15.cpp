#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Group{

private:
	string _class;
	double a, b, c, d;

public: 
	Group(double a, double b, double c, double d, string _class){
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->_class = _class;
	}

	double get_a(){
		return this->a;
	}
	
	double get_b(){
		return this->a;
	}
	
	double get_c(){
		return this->a;
	}
	
	double get_d(){
		return this->a;
	}	
	
	string get_class(){
		return this->_class;
	}
};
	
	//return the distance between two points 
double get_distance_euc(Group att, Group att2){
	double sum;
	sum = pow((att.get_a() - att2.get_a()), 2) +
		  pow((att.get_b() - att2.get_b()), 2) +	
		  pow((att.get_c() - att2.get_c()), 2) +
		  pow((att.get_d() - att2.get_d()), 2);

	return sqrt(sum);
}
string ckecking_group(vector<Group>& attemps, Group new_att, int K){
	if(K % 2 == 0)	{
		K--;
		if (K <= 0)	{
			K = 1;
		}
	}

	int size_att = attemps.size();
	set <pair <double, int> > distance_att;	 

	for (int i = 0; i < size_att; ++i){
		double get_dist = get_distance_euc(attemps[i], new_att);
		distance_att.insert(make_pair(get_dist, i));
	}

	set<pair <double, int> >:: iterator it;
	
	vector<int> count_attemps(3);

	int countK = 0;

	for (it = distance_att.begin(); it !=distance_att.end(); it++)	{
		string _class = attemps[it->second].get_class();

		if(_class == "Iris-setosa") 
			count_attemps[0]++;
		else if(_class == "Iris-versicolor") 
			count_attemps[1]++;
		else 			 
			count_attemps[2]++;

		if(countK > K) break;
		countK++;
	}
	string out_date;	
	if(count_attemps[0] >= count_attemps[1] && count_attemps[0]	>= count_attemps[2])
		out_date = "Iris-setosa";
	else if(count_attemps[1] >= count_attemps[0] && count_attemps[1] >= count_attemps[2])
		out_date = "Iris-versicolor";
	else 
		out_date = "Iris-virginica";

	return out_date;
}


int main(void){

	vector<Group> attemps;
	int K = 3;
	int size_exe = 6;

	for (int i = 0; i < size_exe; ++i){
		string _class;
		double a, b, c, d;

		cin >> a >> b >> c >> d >> _class;
		attemps.push_back(Group(a,b,c,d, _class));

	}
	int hit = 0;
	int size_hits = 150 - size_exe;
	printf("\n");

	for (int i = 0; i < size_hits; ++i)	{
		string _class;
		double a, b, c, d;

		cin >> a >> b >> c >> d >> _class;

		Group group(a, b, c, d, _class);	
	
		string checked;
		
		checked = ckecking_group(attemps, group, K);
	
		cout << "Expected Class: " << _class << "\n";
		cout << "Return: " << checked << endl;

		if(_class == checked) 
			hit++;
	}
	printf("\n");
	printf("\n");

	cout << "Hits this treaning: "<< hit << endl;
	cout << "the large tests: " << size_hits << endl;
	printf("\n");
	printf("\n");

	return 0;

}