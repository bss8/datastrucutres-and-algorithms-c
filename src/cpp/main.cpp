#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

const int SIZE = 2049;
queue<int> myQueue;

// Adjacency matrix
int **adjacencyMatrix;

// Add a directional one-way edge to the graph
void addEdge(int start, int e)
{
    adjacencyMatrix[start][e] = 1;
}

/**
* Breadth First Search implementation. 
* Will print the path up to and including the search item if found. 
* Will print all nodes in the path they're traversed otherwise. 
* @param G - a graph, with the second dimension required
* @param start - what is the starting point 
* @param x - the value we are searching for
* @return true if search item is found
*/
bool BFS(int start, int x)
{
    int i = start;
    int visited[SIZE] = {0};

    printf("%d ", i);
    visited[i] = 1;
    myQueue.push(i);

    while (!myQueue.empty())
    {
        i = myQueue.front();
        myQueue.pop();
        for (int j = 1; j < SIZE; j++)
        {
            if (i == x)
            {
                printf(" search item found ");
                return true;
            }
            if (adjacencyMatrix[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                myQueue.push(j);
            }
        }
    }
    return false;
}

/**
* Depth First Search implementation. 
* Will print the path up to but NOT including the search item if found. 
* Will print all nodes in the path they're traversed otherwise. 
* @param G - a graph, with the second dimension required
* @param start - what is the starting point 
* @param x - the value we are searching for
* @return true if search item is found
*/
bool DFS(int start, int x)
{
    // static so it's accessible for every call
    static int visited[SIZE] = {0};

    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;

        for (int i = 1; i < SIZE; i++)
        {
            if (i == x)
            {
                // do not print at this time because
                // recursion will print it multiple times
                return true; // stop when we find it
            }

            if (adjacencyMatrix[start][i] == 1 && visited[i] == 0)
                DFS(i, x);
        }
    }
    return false;
}

void printAdjacencyMatrix()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << adjacencyMatrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

/**
 * Helper function to determine if we've previously generated the value already
 */
bool wasGenerated(vector<int> generated, int val)
{
    for (int i = 0; i < generated.size(); i++)
    {
        if (generated.at(i) == val)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    adjacencyMatrix = new int *[SIZE];

    // First we populate the matrix with all zero values
    for (int row = 0; row < SIZE; row++)
    {
        adjacencyMatrix[row] = new int[SIZE];
        for (int column = 0; column < SIZE; column++)
        {
            adjacencyMatrix[row][column] = 0;
        }
    }

    int val = 0;
    vector<int> generated;
    queue<int> collatzValues;
    collatzValues.push(1);
    // next we generate the Collatz values using the formulas
    // and add the edges to our matrix accordingly
    for (int i = 0; i < 30; i++)
    {
        val = collatzValues.front();
        collatzValues.pop();
        if (val % 2 == 0 && (val - 1) % 3 == 0)
        {

            // calculate
            int edge_a = val * 2;
            int edge_b = (val * 2 - 1) / 3;

            // debug
            cout << val << " : " << edge_a << ", " << edge_b << endl;

            // add to our q
            collatzValues.push(edge_a);
            generated.insert(generated.begin(), edge_a);

            if (!wasGenerated(generated, edge_b))
            {
                collatzValues.push(edge_b);
                generated.insert(generated.begin(), edge_b);
            }

            // add edges to matrix
            addEdge(val, edge_a);
            addEdge(val, edge_b);
        }
        else
        {

            int edge = val * 2;
            cout << val << ": " << edge << endl;
            collatzValues.push(edge);
            generated.insert(generated.begin(), edge);
            addEdge(val, edge);
        }
    }

    // comment out to see adjacency matrix
    // disabling as it takes up a lot of space to print
    //printAdjacencyMatrix();

    printf("DFS: ");
    bool isFound = DFS(1, 16);
    if (isFound)
    {
        printf(" search item found ");
    }

    printf("\n");

    printf("BFS: ");
    BFS(1, 106);

    return EXIT_SUCCESS;
}