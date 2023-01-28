/*
prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/



//Runs in O(V + E) time using BFS 

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses); //graph (2D vector) to hold all prereqs of every course
        vector<int> depth(numCourses, 0); //vector to hold how many courses the current class is a prereq to

        for(auto m: prerequisites) { //iterate through all the courses
            graph[m[1]].push_back(m[0]); //add the prereq of the current course to the graph
            depth[m[0]]++; //increase the count of how many courses the current course is a prereq to
        }

        queue<int> q; //queue to hold courses to take 
        for(int i = 0; i < numCourses; i++) { //adds all courses that are pre reqs to nothing
            if(depth[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; //number of courses you need to take to finish all the required courses (including pre reqs)
        while(!q.empty()) { //repeat until all necessary courses are completed
            int course_num = q.front(); //current course becomes the one at the front of the queue
            q.pop(); //remove current course from queue
            count++; //increment number of courses need to take to finish all required courses (including pre reqs)
            for(int i = 0; i < graph[course_num].size(); i++) { 
                --depth[graph[course_num][i]]; //decrement how many courses left it is a pre req to
                if(depth[graph[course_num][i]] == 0) { //if no longer a pre req, mark it as completed
                    q.push(graph[course_num][i]);
                }
            }
        }
        return count == numCourses; //possible to complete all required classes if same as number of courses you have to take
    }
};