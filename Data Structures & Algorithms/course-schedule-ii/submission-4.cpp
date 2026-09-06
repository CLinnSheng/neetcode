#include <deque>
#include <vector>
using std::vector;
/*
 * Imagine there is a node from prerequite course to the next course.
 * From this we can tell that nodes with no inDegree means we can take the course, tehres no need to take any mroe
 * prerequisite course
 * We can use a queue to store all the course we can take and then find all its next course and check whetehr can we
 * take or not
 * */
class Solution
{
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto &prerequisite : prerequisites)
        {
            adjList[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        }

        std::deque<int> queue;
        // Push all the course can be taken into the queue and then take it
        for (int i{}; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                queue.push_back(i);
            }
        }

        vector<int> ans;

        while (!queue.empty())
        {
            // Take the current course
            auto currCourse = queue.front();
            queue.pop_front();

            // Find all the course depends on this and decrement the inDegree
            for (const auto nxtCourse : adjList[currCourse])
            {
                inDegree[nxtCourse]--;

                // If the next course can be taken, push into the queue
                if (inDegree[nxtCourse] == 0)
                {
                    queue.push_back(nxtCourse);
                }
            }

            ans.push_back(currCourse);
        }

        return ans.size() == numCourses ? ans : vector<int>();
    }
};
