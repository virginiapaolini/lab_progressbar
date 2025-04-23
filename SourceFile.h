//
// Created by Virginia Paolini on 23/04/25.
//

#ifndef LAB_PROGRESSBAR_SOURCEFILE_H
#define LAB_PROGRESSBAR_SOURCEFILE_H
#include <string>
#include <list>
#include <iostream>
using namespace std;

class SourceFile {
public:
    explicit SourceFile(const string &name) : sourceName(name) {}

    const void getInfo() const {
        cout << "This SOURCE FILE contains the following files..." << endl;
        for(auto const &i : resources)
            cout << i << endl;
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
