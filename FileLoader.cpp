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
    int totResources = file->getResources().size();
    int i = 0;

#ifdef UNIT_TEST
    //niente
#else
    wprintw(logWin, "\nCurrently loading: %s\n", file->getSourceName().c_str());
    wrefresh(logWin);
#endif
    const list<string>& resources = file->getResources();

    for (const auto& res : resources) {
#ifdef UNIT_TEST
        //niente
#else
        wprintw(logWin, "...loading %s\n", res.c_str());
        wrefresh(logWin);
#endif
        int progress = ((i * 100) / totResources);
        notify(progress);

#ifdef UNIT_TEST
        //niente
#else
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
#endif
        i++;
    }
    int progress = 100;
    notify(progress);
#ifdef UNIT_TEST
    //niente
#else
    wprintw(logWin, "\n COMPLETED!\n\n");
    wrefresh(logWin);
#endif

}

void FileLoader::loadAll() {
    int i = 0;
    for (auto currFile : filesToLoad) {
#ifdef UNIT_TEST
        //niente
#else
        wprintw(logWin, "\nUploading source file named: %s\n", currFile->getSourceName().c_str());
        wprintw(logWin, "Loading [%d/%ld]\n", ++i, filesToLoad.size());
        wrefresh(logWin);
#endif
        loadResources(currFile);
        sleep(3);
    }
    getch();
}

void FileLoader::addFilesToLoad(SourceFile* sourceFile) {
    filesToLoad.push_back(sourceFile);
}

void FileLoader::removeFilesToLoad(SourceFile* sourceFile) {
    filesToLoad.remove(sourceFile);
}