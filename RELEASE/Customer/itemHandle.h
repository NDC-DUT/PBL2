#pragma once
#include <string>
#include <vector>
// #include "../DATASTRUCTURE/AVLTree/AVLTree.h"
#include "../ITEM/ITEMMANAGE.h"
#include <iostream>
using namespace std;

unsigned nCategory = CATEGORY.size();
int hightlight = 1;
void printCategory()
{
    cout << "┌─────────────────────────────┐" << endl;
    for (auto &c : CATEGORY)
        cout << c.first << endl;
    cout << "└─────────────────────────────┘";
}
// VECTOR<AVLTree<ITEM>> cateTree(5);

// struct findITEMArgs;

// VECTOR<VECTOR<PAIR<pthread_t, findITEMArgs>>> iPtd // pthread_t cho tìm kiếm ITEM song song
//     {
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(2), // 0
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(2), // 1
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(2), // 2
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(1), // 3
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(5), // 4
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(5), // 5
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(4), // 6
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(6), // 7
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(7), // 8
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(4), // 9
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(6), // 10
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(4), // 11
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(1), // 12
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(6), // 13
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(7), // 14
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(4), // 15
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(6), // 16
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(1), // 17
//         VECTOR<PAIR<pthread_t, findITEMArgs>>(1), // 18
//                                                             //
//     };
// VECTOR<PAIR<short unsigned, short unsigned>> iSup //
//     {

//         //
//     };
// VECTOR<VECTOR<ITEM>> ans;
// short unsigned curVec;
// pthread_mutex_t mutex;

// struct findITEMArgs
// {
//     int x;
//     int y;
//     std::string _name;
//     findITEMArgs(int x = 0, int y = 0, std::string _name = "NULL")
//         : x{x}, y{y}, _name{_name}
//     {
//     }
// };

// void *findITEM(void *argv)
// {
//     findITEMArgs *tmp = static_cast<findITEMArgs *>(argv);

//     for (int &&i{0}; i < ITEM_CONTAINER[tmp->x][tmp->y].size(); ++i)
//     {
//         if (SKIPSEARCH((tmp->_name).c_str(), (tmp->_name).length(), ITEM_CONTAINER[tmp->x][tmp->y][i].getiName().c_str(), ITEM_CONTAINER[tmp->x][tmp->y][i].getiName().length()))
//         {
//             pthread_mutex_lock(&mutex);
//             ans[curVec].push_back(ITEM_CONTAINER[tmp->x][tmp->y][i]);
//             if (ans[curVec].size() == 100)
//                 ++curVec;
//             pthread_mutex_unlock(&mutex);
//         }
//     }
//     return nullptr;
// }

// void fillFindVector(const std::string &ITEMName)
// {
//     pthread_mutex_init(&mutex, nullptr);
//     ans.clear();
//     curVec = 0;

//     pthread_create(&iPtd[0][0], nullptr, &findITEM, static_cast<void *>(&iArgs));

//     pthread_join(iPtd[0][0], nullptr);
//     pthread_mutex_destroy(&mutex);
// }