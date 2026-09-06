#include <vector>
using std::vector;
/*
 * Find all is it possible to finish all course.
 * So every course has its own prerequisites course
 * We only cant finish all course if there is a cycle or deadlock
 * So we can just dfs and detect whether got cycle or not
 * */

class Solution
{
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adjList(numCourses, std::vector<int>());

        for (const auto &prerequisite : prerequisites)
        {
            adjList[prerequisite[0]].push_back(prerequisite[1]);
        }

        for (int i{}; i < numCourses; i++)
        {
            vector<bool> visited(numCourses, false);
            if (!dfs(adjList, visited, i))
            {
                return false;
            }
        }

        return true;
    }

    bool dfs(vector<vector<int>> &adjList, vector<bool> &visited, int currCourse)
    {

        visited[currCourse] = true;

        for (const auto nextCourse : adjList[currCourse])
        {
            if (visited[nextCourse])
            {
                return false;
            }

            if (!dfs(adjList, visited, nextCourse))
            {
                return false;
            }
        }

        // Prune it means we can take current course
        visited[currCourse] = false; // Backtrack to handle diamond case
        adjList[currCourse].clear();

        return true;
    }
};
