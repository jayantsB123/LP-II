#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

int main() {
    int n = 5; // Number of jobs
    vector<Job> jobs = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30},
        {5, 1, 60}
    };

    // Sort jobs by profit (in descending order)
    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.profit > b.profit;
    });

    vector<int> scheduled;
    int time = 0;

    for (const auto& job : jobs) {
        if (time <= job.deadline) {
            scheduled.push_back(job.id);
            time++;
        }
    }

    // Output scheduled jobs
    cout << "Jobs are scheduled as: ";
    for (int i = 0; i < scheduled.size(); ++i) {
        cout << scheduled[i];
        if (i != scheduled.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;

    return 0;
}
