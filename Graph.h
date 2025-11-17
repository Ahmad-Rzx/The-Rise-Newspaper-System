#include<iostream>
#include<string>
#include<cstring>
#pragma once
using namespace std;
struct Graph{
    int** distances; 
    int numLocations; 
    string* locations; 
};
Graph* createGraph(int numLocations);
void saveGraph(string filename, Graph*& graph);
void loadGraph(string filename, Graph*& graph);
void printGraph(Graph* graph);
void freeGraph(Graph*& graph);
