//
// Created by Virginia Paolini on 23/04/25.
//

#ifndef LAB_PROGRESSBAR_SOURCEFILE_H
#define LAB_PROGRESSBAR_SOURCEFILE_H
#include <string>
#include <list>
#include <iostream>
#include "global_functions.h"
using namespace std;

class SourceFile {
public:
    explicit SourceFile(const string &name) : sourceName(name) {}

    const void getInfo() const {
        wprintw(logWin, "This SOURCE FILE contains the following files...\n");
        for (const auto& i : resources) {
            wprintw(logWin, "%s\n", i.c_str());
        }
        wrefresh(logWin);
    }

    void addResource(const list<string>& res) {
        for( const auto &i: res)
            resources.push_back(i);
    }

    void removeResource(const string& res) {
            resources.remove(res);
    }

    const list<string> &getResources() const {
        return resources;
    }

    const string &getSourceName() const {
        return sourceName;
    }

private:
    string sourceName;
    list<string> resources;
};


#endif //LAB_PROGRESSBAR_SOURCEFILE_H
