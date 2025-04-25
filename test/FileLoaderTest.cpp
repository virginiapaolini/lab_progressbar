//
// Created by Virginia Paolini on 23/04/25.
//
#include <gtest/gtest.h>
#include "../FileLoader.h"
#include "../Observer.h"
#include "../SourceFile.h"

class TestObserver : public Observer {
public:
    explicit TestObserver(FileLoader* s) : subject(s) {}
    void update(int progress) override {
        updates.push_back(progress);
    }
    ~TestObserver() override = default;
    void attach() override {
     subject->subscribe(this);
    }
    void detach() override {
        subject->unsubscribe(this);
    }
    vector<int> updates;
    FileLoader* subject;
};

class FileLoaderTestFixture : public ::testing::Test {
protected:
    FileLoader* loader;
    TestObserver* observer;
    SourceFile* file1;
    SourceFile* file2;

    void SetUp() override {
        loader = new FileLoader();
        observer = new TestObserver(loader);
        file1 = new SourceFile("File 1");
        file2 = new SourceFile("File 2");

        loader->subscribe(observer);

        file1->addResource({"ris1", "ris2", "ris3"});
        file2->addResource({"res1", "res2"});
    }

    void TearDown() override {
        delete loader;
        delete observer;
        delete file1;
        delete file2;
    }
};



TEST_F(FileLoaderTestFixture, NotifyCallObs) {
    loader->notify(55);
    ASSERT_EQ(observer->updates.size(), 1);
    EXPECT_EQ(observer->updates[0], 55);
}

TEST_F(FileLoaderTestFixture, UnsubscribeRemovesObserver) {
    loader->unsubscribe(observer);
    EXPECT_TRUE(observer->updates.empty());
}

TEST_F(FileLoaderTestFixture, AddAndRemoveFilesToLoad) {
    EXPECT_EQ(loader->getSize(), 0);
    loader->addFilesToLoad(file1);
    EXPECT_EQ(loader->getSize(), 1);
    loader->removeFilesToLoad(file1);
    EXPECT_EQ(loader->getSize(), 0);
}

TEST_F(FileLoaderTestFixture, LoadAllWithoutFilesDoesNothing) {
    loader->loadAll();
    EXPECT_TRUE(observer->updates.empty());
}


TEST_F(FileLoaderTestFixture, LoadResourcesSendsProgressUpdates) {
    loader->addFilesToLoad(file1);
    loader->loadAll();
    EXPECT_EQ(observer->updates[0], 0);
    EXPECT_EQ(observer->updates[1], 33);
    EXPECT_EQ(observer->updates[2], 66);
    ASSERT_EQ(observer->updates.size(), 3);
}


