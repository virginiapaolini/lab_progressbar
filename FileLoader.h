//
// Created by Virginia Paolini on 23/04/25.
//

#ifndef LAB_PROGRESSBAR_FILELOADER_H
#define LAB_PROGRESSBAR_FILELOADER_H
#include "Subject.h"
#include "SourceFile.h"
#include <chrono>
#include <thread>
#include "global_functions.h"

class FileLoader : public Subject {
public:
    explicit FileLoader() = default;

    ~FileLoader() = default;

    void subscribe(Observer* o) override;

    void unsubscribe(Observer* o) override;

    void notify(int progress) override;

    void loadResources(SourceFile* file);

    void loadAll();

    void addFilesToLoad(SourceFile* s);

    void removeFilesToLoad(SourceFile* s);

    const int getSize() {
        return filesToLoad.size();
    }

protected:
    list<Observer*> observers;
    list <SourceFile*> filesToLoad;
};


#endif //LAB_PROGRESSBAR_FILELOADER_H
