#include <iostream>
#include <vector>
#include <algorithm>

struct Job {
    int id;
    int time;
};

bool compareJobs(Job j1, Job j2) {
    return j1.time > j2.time; // Sort in descending order of processing time
}

void scheduleJobs(std::vector<Job>& jobs) {
    std::sort(jobs.begin(), jobs.end(), compareJobs); // Sort jobs based on processing time

    int machine1 = 0, machine2 = 0;
    std::vector<int> schedule1, schedule2;

    for (int i = 0; i < jobs.size(); ++i) {
        if (machine1 <= machine2) {
            schedule1.push_back(jobs[i].id);
            machine1 += jobs[i].time;
        } else {
            schedule2.push_back(jobs[i].id);
            machine2 += jobs[i].time;
        }
    }

    std::cout << "Jobs scheduled on Machine 1: ";
    for (int job : schedule1) {
        std::cout << "J" << job << " ";
    }
    std::cout << "\nJobs scheduled on Machine 2: ";
    for (int job : schedule2) {
        std::cout << "J" << job << " ";
    }
    std::cout << std::endl;

    std::cout << "Total time taken " << std::max(machine1, machine2) << std::endl;

}

int main() {
    int n;
    std::cout << "Enter the number of jobs: ";
    std::cin >> n;

    std::vector<Job> jobs(n);
    std::cout << "Enter processing times of " << n << " jobs:\n";
    for (int i = 0; i < n; ++i) {
        jobs[i].id = i + 1;
        std::cin >> jobs[i].time;
    }

    scheduleJobs(jobs);

    return 0;
}
