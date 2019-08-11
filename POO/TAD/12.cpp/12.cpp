#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>


using namespace std;

class Point {
private:
	int id_point, id_cluster;
	vector<double> values;
	int total_values;
	string name;
public: 
	Point(int id_point, vector<double>& values, string name = ""){
		this->id_point = id_point;
		this->total_values = values.size();

		for (int i = 0; i < total_values; ++i)	
			this->values.push_back(values[i]);
		this->name = name;
		id_cluster = -1;	
	}	
	int get_id(){
		return this->id_point;
	}
	void set_cluster(int id_cluster){
		this->id_cluster = id_cluster;
	}
	int get_cluster(){
		return this->id_cluster;
	}
	double get_value(int index){
		return this->values[index];
	} 
	int get_total_values(){
		return this->total_values;
	}
	void set_value(double value){
		values.push_back(value);
	}
	string get_name(){
		return this->name;
	}
};

class Cluster {
private:
	int id_cluster;
	vector<double> central_values;
	vector<Point> points;
public:
	Cluster(int id_cluster, Point point){
		this->id_cluster = id_cluster;
		int total_values = point.get_total_values();

		for (int i = 0; i < total_values; ++i)
			central_values.push_back(point.get_value(i));

		points.push_back(point);
	}
	void set_point(Point point){
		points.push_back(point);
	}
	bool remove_point(int id_point){
		int total_points = points.size();
		for (int i = 0; i < total_points; ++i)		{
			if(points[i].get_id() == id_point){
				points.erase(points.begin() + i);
				return true;
			}
		}
		return false;
	}
	double get_central_value(int index){
		return this->central_values[index];
	}
	void set_central_value(int index, double value){
		central_values[index] = value;
	}
	Point get_point(int index){
		return this->points[index];
	}
	int get_total_points(){
		return this->points.size();
	}
	int get_id(){
		return this->id_cluster;
	}

};

class Kmeans{
private:
	int K; //max size cluster
	int total_values, total_points, max_iterations;
	vector<Cluster> clusters;
	int get_id_nearst_center(Point point){
		double sum = 0.0, min_dist;
		int id_cluster_center = 0;

		for (int i = 0; i < total_values; ++i)
			sum += pow(clusters[0].get_central_value(i) - point.get_value(i), 2.0);

		min_dist = sqrt(sum);
		for (int i = 1; i < K; ++i){
			double dist;
			sum = 0.0;
			for (int j = 0; j < K; ++j){
				sum += pow(clusters[i].get_central_value(j) - point.get_value(j), 2.0);
			}
			dist = sqrt(sum);
			if(dist < min_dist){
				min_dist = dist;
				id_cluster_center = i;
			}
		}
		return id_cluster_center;
	}
public: 
	Kmeans(int K, int total_points, int total_values, int max_iterations){
		this->K = K;
		this->total_points = total_points;
		this->total_values = total_values;
		this->max_iterations = max_iterations;
	}
	void run(vector<Point>& points){
		if(K > total_points) return;

		vector<int> prohibited_indexes;
		for (int i = 0; i < K; ++i)		{
			while(true){
				int index_point = rand() % total_points;
				if(find(prohibited_indexes.begin(), prohibited_indexes.end(),
					index_point) == prohibited_indexes.end()){
					prohibited_indexes.push_back(index_point);
					points[index_point].set_cluster(i);
					Cluster cluster(i, points[index_point]);
					clusters.push_back(cluster);
					break;
				}
			}

		}
		int iter = 1;
		while(true){
			bool done = true;
			for (int i = 0; i < total_points; ++i)			{
				int id_old_cluster = points[i].get_cluster();
				int id_nearest_center = get_id_nearst_center(points[i]);
				if(id_old_cluster != id_nearest_center){
					if(id_old_cluster != -1)
						clusters[id_old_cluster].remove_point(points[i].get_id());
					points[i].set_cluster(id_nearest_center);
					clusters[id_nearest_center].set_point(points[i]);
					done = false;
				}
			}

			for (int i = 0; i < K; ++i)	{
				for(int j = 0; j < total_values; ++j)	{
					int total_points_cluster = clusters[i].get_total_points();
					double sum = 0.0;
					if(total_points_cluster > 0){
						for (int p = 0; p < total_points_cluster; ++p)
							sum += clusters[i].get_point(p).get_value(j);
						clusters[i].set_central_value(j, sum / total_points_cluster);
						
					}
				}
			}
			if(done == true || iter >= max_iterations){
				cout << "Break iterator " << iter << "\n\n";
				break;
			}
			iter ++;
		}
		//show all elements 
		for (int i = 0; i < K; ++i){
			int total_points_cluster = clusters[i].get_total_points();
			cout << "Cluster " << clusters[i].get_id() + 1 << endl;
			for (int j = 0; j < total_points_cluster; ++j)		{
				cout << "Point " << clusters[i].get_point(j).get_id() + 1 << " : ";
				for (int p = 0; p < total_values; ++p)	
					cout << clusters[i].get_point(j).get_value(p) << " ";

				string point_name = clusters[i].get_point(j).get_name();

				if(point_name != "") cout << "- " << point_name;

				cout << endl;
			}
			cout << "Cluster values: ";
			for (int j = 0; j < total_values; ++j)	
				cout << clusters[i].get_central_value(j) << " ";
			cout << "\n\n";
			
		}
	}
};

int main(void){
	srand (time(NULL));
	int total_points, total_values, K, max_iterations, has_name;
	cin >> total_points >> total_values >> K >> max_iterations >> has_name;
	vector<Point> points;
	string point_name;
	for (int i = 0; i < total_points; ++i)	 {
	 	vector<double> values;
	 	for (int j = 0; j < total_values; ++j)	 	{
	 		double value;
	 		cin >> value;
	 		values.push_back(value);
	 	}
	 	if(has_name){
	 		cin >> point_name;
	 		Point p(i, values, point_name);
	 		points.push_back(p);
	 	}
	 	else {
	 		Point p(i, values);
	 		points.push_back(p);	
	 	}
	 } 
	 Kmeans kmeans(K, total_points, total_values, max_iterations);
	 kmeans.run(points);

	return 0;
}