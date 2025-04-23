//
// Created by Virginia Paolini on 23/04/25.
//
#include <gtest/gtest.h>
#include "../FileLoader.h"
#include "Observer.h"

class NotifiesCounter : public Observer {
public:
    explicit NotifiesCounter(FileLoader *file) : subject(file) {
            attach();
    }
    ~NotifiesCounter() override {
        detach();
    }

    void attach() override {
        subject->subscribe(this);
    }
    void detach() override {
        subject->unsubscribe(this);
    }

    void update(int progress) override {
        numUpdates.push_back(progress);
    }

protected:
    vector<int> numUpdates;
    FileLoader* subject;
};

class FileLoaderTest : public ::testing::Test {
protected:
    void setUp()  {
        // tipo costruttore
        SourceFile* source1 = new SourceFile({"text.txt", "audio.mp3"});
        SourceFile* source2 = new SourceFile({"movie.mkv"});
        SourceFile* source3 = new SourceFile({"app.apk"});
        FileLoaderTest* loader1 = new FileLoaderTest;
        NotifiesCounter* notifiesCounter = new NotifiesCounter(loader1);
    }

    void tearDown() {
        // tipo distruttore
        delete loader;
        delete source;
    }
    SourceFile* source1;
    SourceFile* source2;
    SourceFile* source3;
    FileLoaderTest* loader1;
    NotifiesCounter* notifiesCounter;

};

TEST_F(FileLoaderTest, CorrectResourceLoading){
    loader1->addFilesToLoad(source1);
    loader1->addFilesToLoad(source2);
    loader1->addFilesToLoad(source3);
    loader1->loadAll();

ASSERT_EQ(notifiesCounter->numUpdates.size(), 4);

// Controlla che la prog sia corretta (0, 25, 50, 100)
vector<int> expectedProgress = {0, 25, 50, 100};
EXPECT_EQ(notifiesCounter->numUpdates, expectedProgress);

}

TEST_F(FileLoaderTest, CorrectFilesLoading){
loader1->addFilesToLoad(source1);
loader1->addFilesToLoad(source2);
loader1->addFilesToLoad(source3);
ASSERT_EQ(loader1->filesToLoad.size(), 3);

loader1->removeFilesToLoad(source1);
loader1->removeFilesToLoad(source2);
loader1->removeFilesToLoad(source3);

ASSERT_TRUE(loader1->filesToLoad.empty());
}

