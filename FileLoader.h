//
// Created by Virginia Paolini on 23/04/25.
//

#ifndef LAB_PROGRESSBAR_FILELOADER_H
#define LAB_PROGRESSBAR_FILELOADER_H
#include "Subject.h"
#include "SourceFile.h"
#include <chrono>
#include <thread>

class FileLoader : public Subject {
public:
    explicit FileLoader() = default;

    ~FileLoader() = default;

    void subscribe(Observer* o) override;

    void unsubscribe(Observer* o) override;

    void notify(int progress) override;

    void loadResources();

    void addFilesToLoad();

private:
    list<Observer*> observers;
    list <SourceFile*> filesToLoad;
};


#endif //LAB_PROGRESSBAR_FILELOADER_H
