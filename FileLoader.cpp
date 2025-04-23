//
// Created by Virginia Paolini on 23/04/25.
//

#include "FileLoader.h"

void FileLoader::subscribe(Observer* o) {
    observers.push_back(o);
}

void FileLoader::unsubscribe(Observer* o) {
    observers.remove(o);
}

void FileLoader::notify(int progress) {
    for(auto obs : observers)
        obs->update(progress);
}

void FileLoader::loadResources() {
    int totResources = fileToLoad->getResources().size()-1;
    int i = 0;
    cout << "Currently loading " << fileToLoad->getSourceName() << endl;
    for (const auto &it : fileToLoad->getResources()){
        cout << "...loading " << it << endl;
        // this_thread::sleep_for(chrono::milliseconds(500));
        int progress = ((i*100)/totResources);
        notify(progress);
        i++;
    }
}

void FileLoader::loadAll() {
    int i = 0;
    for(const auto currFile : filesToLoad) {
        cout << "Uploading source file named " << currFile->getSourceName() << endl;
        cout << "Loading " << ++i << "/"<< filesToLoad.size()-1 << endl;
        loadResources()
    }
}

void FileLoader::addFilesToLoad(SourceFile* sourceFile) {
    filesToLoad.push_back(sourceFile);
}

void FileLoader::removeFilesToLoad(SourceFile* sourceFile) {
    filesToLoad.remove(sourceFile);
}
