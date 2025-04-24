//
// Created by Virginia Paolini on 23/04/25.
//
#include <gtest/gtest.h>
#include "../FileLoader.h"
#include "../ProgressBar.h"

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

    vector<int> numUpdates;
    FileLoader* subject;
};

class FileLoaderTest : public ::testing::Test {
protected:
    void setUp()  {
        // tipo costruttore
        SourceFile* source1 = new SourceFile("file1");
        source1->addResource({"text.txt", "audio.mp3"});

        SourceFile* source2 = new SourceFile("file2");
        source2->addResource({"movie.mkv"});

        SourceFile* source3 = new SourceFile("file3");
        source3->addResource({"movie.mkv"});

        FileLoader* loader1 = new FileLoader;
        NotifiesCounter* notifiesCounter = new NotifiesCounter(loader1);
        ProgressBar* bar = new ProgressBar(loader1);
    }

    void tearDown() {
        // tipo distruttore
        delete loader1;
        delete source1;
        delete source2;
        delete source3;
        delete notifiesCounter;
    }

    SourceFile* source1;
    SourceFile* source2;
    SourceFile* source3;
    FileLoader* loader1;
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

ASSERT_EQ(loader1->getSize(), 3);

loader1->removeFilesToLoad(source1);
loader1->removeFilesToLoad(source2);
loader1->removeFilesToLoad(source3);

ASSERT_EQ(loader1->getSize(), 0);
}

