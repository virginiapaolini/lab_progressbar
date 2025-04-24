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

void FileLoader::loadResources(SourceFile* file) {
    int totResources = file->getResources().size() - 1;
    int i = 0;

    wprintw(logWin, "Currently loading: %s\n", file->getSourceName().c_str());
    wrefresh(logWin);

    for (const auto &res : file->getResources()) {
        wprintw(logWin, "...loading %s\n", res.c_str());
        wrefresh(logWin);

        int progress = ((i * 100) / totResources);
        notify(progress);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        ++i;
    }
}

void FileLoader::loadAll() {
    int i = 0;
    for (const auto &currFile : filesToLoad) {
        wprintw(logWin, "\nUploading source file named: %s\n", currFile->getSourceName().c_str());
        wprintw(logWin, "Loading [%d/%ld]\n", ++i, filesToLoad.size());
        wrefresh(logWin);

        loadResources(currFile);
    }
}

void FileLoader::addFilesToLoad(SourceFile* sourceFile) {
    filesToLoad.push_back(sourceFile);
}

void FileLoader::removeFilesToLoad(SourceFile* sourceFile) {
    filesToLoad.remove(sourceFile);
}
