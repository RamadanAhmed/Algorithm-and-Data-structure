#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

using std::vector;
using std::cin;
using std::cout;

using pair_long_int = std::pair<long long, int>;
class JobQueue {
private:
	int num_workers_;
	vector<int> jobs_;
	vector<int> assigned_workers_;
	vector<long long> start_times_;

	void WriteResponse() const {
		for (int i = 0; i < jobs_.size(); ++i) { 
			cout << assigned_workers_[i] << " " << start_times_[i] << "\n"; 
		}
	}
	void CheckResponse(const std::string & filename) const {
		std::ifstream AnsFile(filename);
		for (int i = 0; i < jobs_.size(); ++i) {
			int worker;
			long long start_time;
			AnsFile >> worker >> start_time;
			assert(worker == assigned_workers_[i]);
			assert(start_time == start_times_[i]);
		}
	}

	void ReadDataConsole() {
		int m;
		cin >> num_workers_ >> m;
		jobs_.resize(m);
		for (int i = 0; i < m; ++i) 
			cin >> jobs_[i];
	}
	
	void ReadDataFile(const std::string &file_name) {
		std::ifstream infile(file_name);
		int m;
		infile >> num_workers_ >> m;
		jobs_.resize(m);
		for (int i = 0; i < m; ++i)
			infile >> jobs_[i];
	}

	void OldAssignJobs() {
		assigned_workers_.resize(jobs_.size());
		start_times_.resize(jobs_.size());
		vector<long long> next_free_time(num_workers_, 0);
		for (int i = 0; i < jobs_.size(); ++i) {
			int duration = jobs_[i];
			int next_worker = 0;
			for (int j = 0; j < num_workers_; ++j) {
				if (next_free_time[j] < next_free_time[next_worker]) 
					next_worker = j;
			}
			assigned_workers_[i] = next_worker;
			start_times_[i] = next_free_time[next_worker];
			next_free_time[next_worker] += duration;
		}
	}

	void PriorityQueueAssignJob() {
		auto compareDist = [](pair_long_int left, pair_long_int right) {
			return left.first == right.first ? left.second > right.second : left.first > right.first;
		};
		assigned_workers_.resize(jobs_.size());
		start_times_.resize(jobs_.size());
		std::priority_queue < pair_long_int, std::vector<pair_long_int>, decltype (compareDist) > next_free_worker(compareDist);
		for (int i = 0; i < num_workers_; ++i) {
			next_free_worker.push({ 0,i });
		}
		for (int i = 0; i < jobs_.size(); ++i) {
			int duration = jobs_[i];
			pair_long_int next_worker = next_free_worker.top();
			assigned_workers_[i] = next_worker.second;
			start_times_[i] = next_worker.first;
			next_free_worker.pop();
			next_free_worker.push({ next_worker.first + duration, next_worker.second });
		}
	}

	void AssignJobs() {
		//OldAssignJobs();
		PriorityQueueAssignJob();
	}

public:
	void Solve() {
		ReadDataConsole();
		AssignJobs();
		WriteResponse();
	}
	void TestSolution() {
		// Test 02
		ReadDataFile("../tests/02");
		AssignJobs();
		CheckResponse("../tests/02.a");
		std::cout << "Passed Test 02" << '\n';
		// Test 08
		ReadDataFile("../tests/08");
		AssignJobs();
		CheckResponse("../tests/08.a");
		std::cout << "Passed Test 08" << '\n';
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	JobQueue job_queue;
	job_queue.Solve();
	//job_queue.TestSolution();
	return 0;
}
