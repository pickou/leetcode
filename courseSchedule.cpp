// leetcode 207
/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.

Note:

    The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
    You may assume that there are no duplicate edges in the input prerequisites.

 Hints:

    This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
    Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
    Topological sort could also be done via BFS.
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> visited(numCourses, true);
        queue<int> courseQ;
        vector<int> indegree(numCourses, 0);
        int N = 0;
        for(auto it: prerequisites) {
            indegree[it.first]++; // indegree
            visited[it.first] = false; // missing edge for visited
            visited[it.second] = false;
        }

        for(int i=0; i<numCourses; i++) {// in queue
            if(indegree[i]==0&&!visited[i]) {
                courseQ.push(i);
                visited[i] = true;
                for(auto it: prerequisites) { // indegree --
                    if(it.second==i) {
                        indegree[it.first]--;
                    }
                }
            }
        }
        
        while(!courseQ.empty()) { // topsort
            N = courseQ.size();
            for(int i=0; i<N; i++) {
                int course = courseQ.front(); // out queue
                courseQ.pop();
                
                for(int j=0; j<numCourses; j++) { // in queue
                    if(!visited[j]&&indegree[j]==0) {
                        courseQ.push(j);
                        visited[j] = true;
                        for(auto it: prerequisites) { // indegree --
                            if(it.second==j) {
                                indegree[it.first]--;
                            }
                        }
                    }
                }
            }  
        }
        for(auto it: indegree) {
            if(it) return false;  
        }
        return true;
    }
};
